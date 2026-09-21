#include "dx_vm.h"
#include "dx_dex.h"
#include "dx_memory.h"
#include "dx_apk.h"
#include "dx_manifest.h"
#include "game_dex_runner.h"
#include "AndroidMini/framework_viewroot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLES2/gl2.h>

typedef int32_t (*AgrDexUploadFn)(void *user, const char *asset_path);
static AgrDexUploadFn g_upload;
static void *g_upload_user;

void agr_dex_set_upload_callback(AgrDexUploadFn callback, void *user) {
    g_upload = callback;
    g_upload_user = user;
}

static DxObject *g_activity;
static char g_opened_asset[512];
static char g_uploaded_asset[512];
static int32_t g_next_texture = 1;
static int32_t g_bound_texture = 0;
static int32_t g_log_calls = 0;
static int32_t g_next_sound = 1;
static char g_package_name[256];

static DxResult context_get_application_context(DxVM *vm, DxFrame *frame,
                                                DxValue *args, uint32_t count) {
    (void)args; (void)count;
    frame->result = vm->application_instance ? DX_OBJ_VALUE(vm->application_instance)
                                             : DX_NULL_VALUE;
    frame->has_result = true;
    return DX_OK;
}

static DxResult activity_get_application(DxVM *vm, DxFrame *frame,
                                         DxValue *args, uint32_t count) {
    return context_get_application_context(vm, frame, args, count);
}

static DxResult object_field_result(DxFrame *frame, DxValue *args, uint32_t count,
                                    const char *field) {
    DxValue value = DX_NULL_VALUE;
    if (!frame || count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj)
        return DX_ERR_NULL_PTR;
    if (dx_vm_get_field(args[0].obj, field, &value) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    frame->result = value;
    frame->has_result = true;
    return DX_OK;
}

static DxResult activity_get_window(DxVM *vm, DxFrame *frame,
                                    DxValue *args, uint32_t count) {
    (void)vm;
    return object_field_result(frame, args, count, "_window");
}

static DxResult activity_get_window_manager(DxVM *vm, DxFrame *frame,
                                            DxValue *args, uint32_t count) {
    (void)vm;
    return object_field_result(frame, args, count, "_windowManager");
}

static DxResult window_get_decor_view(DxVM *vm, DxFrame *frame,
                                      DxValue *args, uint32_t count) {
    (void)vm;
    return object_field_result(frame, args, count, "_decor");
}

static DxResult window_get_attributes(DxVM *vm, DxFrame *frame,
                                      DxValue *args, uint32_t count) {
    (void)vm;
    return object_field_result(frame, args, count, "_attributes");
}

static DxResult view_set_visibility(DxVM *vm, DxFrame *frame,
                                    DxValue *args, uint32_t count) {
    (void)vm; (void)frame;
    if (count < 2 || args[0].tag != DX_VAL_OBJ || !args[0].obj ||
        args[1].tag != DX_VAL_INT) return DX_ERR_INVALID_FORMAT;
    return dx_vm_set_field(args[0].obj, "_visibility", args[1]);
}

static DxResult window_manager_add_view(DxVM *vm, DxFrame *frame,
                                        DxValue *args, uint32_t count);

static DxResult activity_on_post_resume(DxVM *vm, DxFrame *frame,
                                        DxValue *args, uint32_t count) {
    (void)vm; (void)frame; (void)args; (void)count;
    /* API19 Activity.onPostResume makes the Window active when one exists.
       This launch environment has not attached a Window or ActionBar, so the
       guarded branches have no guest-visible work. */
    return DX_OK;
}

static void add_method(DxClass *cls, const char *name, const char *shorty,
                       uint32_t flags, DxNativeMethodFn fn, int direct) {
    DxMethod **methods = direct ? &cls->direct_methods : &cls->virtual_methods;
    uint32_t *count = direct ? &cls->direct_method_count : &cls->virtual_method_count;
    DxMethod *grown = dx_realloc(*methods, sizeof(DxMethod) * (*count + 1));
    if (!grown) return;
    *methods = grown;
    DxMethod *method = &grown[(*count)++];
    memset(method, 0, sizeof(*method));
    method->name = name;
    method->shorty = shorty;
    method->declaring_class = cls;
    method->access_flags = flags;
    method->native_fn = fn;
    method->is_native = true;
    /* Framework HLE methods are resolved by descriptor/name/shorty.  They do
       not occupy application vtable slots unless we explicitly build the
       inherited framework vtable.  A synthetic local index here caused
       Context.getAssets() to dispatch to slot zero of the Activity vtable. */
    method->vtable_idx = -1;
}

static DxClass *reg_class(DxVM *vm, const char *descriptor, DxClass *super) {
    DxClass *existing = dx_vm_find_class(vm, descriptor);
    if (existing) return existing;
    DxClass *cls = dx_malloc(sizeof(*cls));
    if (!cls) return NULL;
    cls->descriptor = descriptor;
    cls->super_class = super ? super : vm->class_object;
    cls->status = DX_CLASS_INITIALIZED;
    cls->is_framework = true;
    vm->classes[vm->class_count++] = cls;
    dx_vm_class_hash_insert(vm, cls);
    return cls;
}

static void one_field(DxClass *cls, const char *name, const char *type) {
    cls->instance_field_count = 1;
    cls->field_defs = dx_malloc(sizeof(*cls->field_defs));
    cls->field_defs[0].name = name;
    cls->field_defs[0].type = type;
    cls->field_defs[0].flags = DX_ACC_PUBLIC;
    cls->field_defs[0].slot_index = 0;
}

static void own_fields(DxClass *cls, uint32_t count,
                       const char *const *names, const char *const *types) {
    uint32_t inherited = cls->super_class ? cls->super_class->instance_field_count : 0;
    cls->instance_field_count = inherited + count;
    if (!count) return;
    cls->field_defs = dx_malloc((size_t)count * sizeof(*cls->field_defs));
    for (uint32_t i = 0; i < count; i++) {
        cls->field_defs[i].name = names[i];
        cls->field_defs[i].type = types[i];
        cls->field_defs[i].flags = DX_ACC_PUBLIC;
        cls->field_defs[i].slot_index = inherited + i;
    }
}

static DxResult noop(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)frame; (void)args; (void)count;
    return DX_OK;
}

static DxResult context_get_assets(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)args; (void)count;
    DxClass *cls = dx_vm_find_class(vm, "Landroid/content/res/AssetManager;");
    frame->result = DX_OBJ_VALUE(dx_vm_alloc_object(vm, cls));
    frame->has_result = true;
    return DX_OK;
}

static DxResult context_get_resources(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)args; (void)count;
    DxClass *cls = dx_vm_find_class(vm, "Landroid/content/res/Resources;");
    frame->result = DX_OBJ_VALUE(dx_vm_alloc_object(vm, cls)); frame->has_result = true; return DX_OK;
}

static DxResult context_get_package_name(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)args; (void)count;
    frame->result = DX_OBJ_VALUE(dx_vm_create_string(vm,g_package_name));
    frame->has_result = true; return DX_OK;
}

static DxResult resources_get_identifier(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)args; (void)count;
    frame->result = DX_INT_VALUE(g_next_sound++); frame->has_result = true; return DX_OK;
}

static DxResult soundpool_load(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)args; (void)count;
    frame->result = DX_INT_VALUE(g_next_sound++); frame->has_result = true; return DX_OK;
}

static DxResult soundpool_play(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)args; (void)count;
    frame->result = DX_INT_VALUE(g_next_sound++); frame->has_result = true; return DX_OK;
}

static DxResult asset_open(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    if (count < 2 || args[1].tag != DX_VAL_OBJ || !args[1].obj) return DX_ERR_NULL_PTR;
    const char *path = dx_vm_get_string_value(args[1].obj);
    snprintf(g_opened_asset, sizeof(g_opened_asset), "%s", path ? path : "");
    DxClass *cls = dx_vm_find_class(vm, "Ljava/io/InputStream;");
    DxObject *stream = dx_vm_alloc_object(vm, cls);
    dx_vm_set_field(stream, "_assetPath", DX_OBJ_VALUE(dx_vm_create_string(vm, g_opened_asset)));
    frame->result = DX_OBJ_VALUE(stream);
    frame->has_result = true;
    return DX_OK;
}

static DxResult bitmap_decode(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    if (count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_NULL_PTR;
    DxValue path = DX_NULL_VALUE;
    dx_vm_get_field(args[0].obj, "_assetPath", &path);
    DxClass *cls = dx_vm_find_class(vm, "Landroid/graphics/Bitmap;");
    DxObject *bitmap = dx_vm_alloc_object(vm, cls);
    dx_vm_set_field(bitmap, "_assetPath", path);
    frame->result = DX_OBJ_VALUE(bitmap);
    frame->has_result = true;
    return DX_OK;
}

static DxResult gles_gen_textures(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)frame;
    if (count < 3 || args[1].tag != DX_VAL_OBJ || !args[1].obj || !args[1].obj->is_array)
        return DX_ERR_INVALID_FORMAT;
    int32_t amount = args[0].i;
    int32_t offset = args[2].i;
    GLuint *textures = calloc((size_t)amount, sizeof(*textures));
    if (!textures) return DX_ERR_OUT_OF_MEMORY;
    glGenTextures(amount, textures);
    for (int32_t i = 0; i < amount && (uint32_t)(offset + i) < args[1].obj->array_length; i++)
        args[1].obj->array_elements[offset + i] = DX_INT_VALUE((int32_t)textures[i]);
    free(textures);
    return DX_OK;
}

static DxResult gles_bind_texture(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)frame;
    if (count >= 2) { g_bound_texture = args[1].i; glBindTexture((GLenum)args[0].i, (GLuint)args[1].i); }
    return DX_OK;
}

static DxResult gles_tex_parameter(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)frame;
    if (count >= 3) glTexParameteri((GLenum)args[0].i, (GLenum)args[1].i, args[2].i);
    return DX_OK;
}

static DxResult gles_delete_textures(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)frame;
    if (count < 3 || args[1].tag != DX_VAL_OBJ || !args[1].obj || !args[1].obj->is_array) return DX_ERR_INVALID_FORMAT;
    int32_t amount = args[0].i, offset = args[2].i;
    GLuint *textures = calloc((size_t)amount, sizeof(*textures)); if (!textures) return DX_ERR_OUT_OF_MEMORY;
    for (int32_t i = 0; i < amount && (uint32_t)(offset + i) < args[1].obj->array_length; i++) textures[i] = (GLuint)args[1].obj->array_elements[offset + i].i;
    glDeleteTextures(amount, textures); free(textures); return DX_OK;
}

static DxResult glutils_tex_image(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)frame;
    if (count < 3 || args[2].tag != DX_VAL_OBJ || !args[2].obj) return DX_ERR_NULL_PTR;
    DxValue path = DX_NULL_VALUE;
    dx_vm_get_field(args[2].obj, "_assetPath", &path);
    const char *text = path.tag == DX_VAL_OBJ && path.obj ? dx_vm_get_string_value(path.obj) : "";
    snprintf(g_uploaded_asset, sizeof(g_uploaded_asset), "%s", text ? text : "");
    if (!g_upload || g_upload(g_upload_user, g_uploaded_asset) != 0) return DX_ERR_IO;
    return DX_OK;
}

static DxResult log_call(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    (void)vm; (void)args; (void)count;
    g_log_calls++;
    frame->result = DX_INT_VALUE(0);
    frame->has_result = true;
    return DX_OK;
}

static DxResult register_game_framework(DxVM *vm) {
    DxClass *obj = vm->class_object;
    DxClass *context = reg_class(vm, "Landroid/content/Context;", obj);
    DxClass *context_wrapper = reg_class(vm, "Landroid/content/ContextWrapper;", context);
    DxClass *application = reg_class(vm, "Landroid/app/Application;", context_wrapper);
    DxClass *activity = reg_class(vm, "Landroid/app/Activity;", context_wrapper);
    DxClass *native_activity = reg_class(vm, "Landroid/app/NativeActivity;", activity);
    const char *wrapper_names[] = { "_baseContext" };
    const char *wrapper_types[] = { "Landroid/content/Context;" };
    own_fields(context_wrapper, 1, wrapper_names, wrapper_types);
    own_fields(application, 0, NULL, NULL);
    const char *activity_names[] = { "_application", "_intent", "_window", "_windowManager", "_decor",
        "_startedActivity", "_finished", "_visibleFromClient", "_visibleFromServer", "_windowAdded" };
    const char *activity_types[] = { "Landroid/app/Application;", "Landroid/content/Intent;",
        "Landroid/view/Window;", "Landroid/view/WindowManager;", "Landroid/view/View;",
        "Z", "Z", "Z", "Z", "Z" };
    own_fields(activity, 10, activity_names, activity_types);
    own_fields(native_activity, 0, NULL, NULL);
    add_method(context, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(context_wrapper, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(application, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(application, "onCreate", "V", DX_ACC_PUBLIC, noop, 0);
    add_method(activity, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(activity, "onCreate", "VL", DX_ACC_PROTECTED, noop, 0);
    add_method(activity, "onStart", "V", DX_ACC_PROTECTED, noop, 0);
    add_method(activity, "onResume", "V", DX_ACC_PROTECTED, noop, 0);
    add_method(activity, "onPostResume", "V", DX_ACC_PROTECTED, activity_on_post_resume, 0);
    add_method(activity, "getApplication", "L", DX_ACC_PUBLIC, activity_get_application, 0);
    add_method(activity, "getWindow", "L", DX_ACC_PUBLIC, activity_get_window, 0);
    add_method(activity, "getWindowManager", "L", DX_ACC_PUBLIC, activity_get_window_manager, 0);
    add_method(native_activity, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(native_activity, "onCreate", "VL", DX_ACC_PUBLIC, noop, 0);
    add_method(context, "getAssets", "L", DX_ACC_PUBLIC, context_get_assets, 0);
    add_method(context, "getResources", "L", DX_ACC_PUBLIC, context_get_resources, 0);
    add_method(context, "getPackageName", "L", DX_ACC_PUBLIC, context_get_package_name, 0);
    add_method(context, "getApplicationContext", "L", DX_ACC_PUBLIC,
               context_get_application_context, 0);

    DxClass *view = reg_class(vm, "Landroid/view/View;", obj);
    const char *view_names[] = { "_visibility", "_layoutParams", "_parent", "_attachInfo",
                                 "_attachedToWindow", "_measuredWidth", "_measuredHeight",
                                 "_left", "_top", "_right", "_bottom" };
    const char *view_types[] = { "I", "Landroid/view/WindowManager$LayoutParams;",
                                 "Landroid/view/ViewRootImpl;", "Landroid/view/View$AttachInfo;",
                                 "Z", "I", "I", "I", "I", "I", "I" };
    own_fields(view, 11, view_names, view_types);
    add_method(view, "setVisibility", "VI", DX_ACC_PUBLIC, view_set_visibility, 0);
    DxClass *layout_params = reg_class(vm, "Landroid/view/WindowManager$LayoutParams;", obj);
    const char *layout_names[] = { "_type", "_softInputMode", "_width", "_height" };
    const char *layout_types[] = { "I", "I", "I", "I" };
    own_fields(layout_params, 4, layout_names, layout_types);
    DxClass *window = reg_class(vm, "Landroid/view/Window;", obj);
    const char *window_names[] = { "_decor", "_attributes" };
    const char *window_types[] = { "Landroid/view/View;", "Landroid/view/WindowManager$LayoutParams;" };
    own_fields(window, 2, window_names, window_types);
    add_method(window, "getDecorView", "L", DX_ACC_PUBLIC, window_get_decor_view, 0);
    add_method(window, "getAttributes", "L", DX_ACC_PUBLIC, window_get_attributes, 0);
    DxClass *window_manager = reg_class(vm, "Landroid/view/WindowManager;", obj);
    const char *manager_names[] = { "_lastView", "_lastLayoutParams", "_viewRoot" };
    const char *manager_types[] = { "Landroid/view/View;", "Landroid/view/WindowManager$LayoutParams;",
                                    "Landroid/view/ViewRootImpl;" };
    own_fields(window_manager, 3, manager_names, manager_types);
    add_method(window_manager, "addView", "VLL", DX_ACC_PUBLIC, window_manager_add_view, 0);
    DxClass *viewroot = reg_class(vm, "Landroid/view/ViewRootImpl;", obj);
    const char *root_names[] = { "_view", "_layoutParams", "_session", "_attachInfo", "_added",
                                 "_layoutRequested", "_traversalPending", "_surface",
                                 "_frameLeft", "_frameTop", "_frameRight", "_frameBottom" };
    const char *root_types[] = { "Landroid/view/View;", "Landroid/view/WindowManager$LayoutParams;",
                                 "Landroid/view/IWindowSession;", "Landroid/view/View$AttachInfo;",
                                 "Z", "Z", "Z", "Landroid/view/Surface;", "I", "I", "I", "I" };
    own_fields(viewroot, 12, root_names, root_types);
    DxClass *attach_info = reg_class(vm, "Landroid/view/View$AttachInfo;", obj);
    const char *attach_names[] = { "_rootView", "_surface", "_windowVisibility" };
    const char *attach_types[] = { "Landroid/view/View;", "Landroid/view/Surface;", "I" };
    own_fields(attach_info, 3, attach_names, attach_types);
    DxClass *session = reg_class(vm, "Landroid/view/IWindowSession;", obj);
    const char *session_names[] = { "_attachedWindow", "_inputChannelOwned", "_contentInsetLeft",
                                    "_contentInsetTop", "_contentInsetRight", "_contentInsetBottom",
                                    "_requestedWidth", "_requestedHeight", "_viewVisibility",
                                    "_frameLeft", "_frameTop", "_frameRight", "_frameBottom", "_surface" };
    const char *session_types[] = { "Landroid/view/Window;", "Z", "I", "I", "I", "I",
                                    "I", "I", "I", "I", "I", "I", "I", "Landroid/view/Surface;" };
    own_fields(session, 14, session_names, session_types);
    DxClass *surface = reg_class(vm, "Landroid/view/Surface;", obj);
    const char *surface_names[] = { "_ownerWindow", "_valid", "_generation", "_width", "_height" };
    const char *surface_types[] = { "Landroid/view/Window;", "Z", "I", "I", "I" };
    own_fields(surface, 5, surface_names, surface_types);

    DxClass *asset_manager = reg_class(vm, "Landroid/content/res/AssetManager;", obj);
    add_method(asset_manager, "open", "LL", DX_ACC_PUBLIC, asset_open, 0);
    DxClass *input = reg_class(vm, "Ljava/io/InputStream;", obj);
    one_field(input, "_assetPath", "Ljava/lang/String;");
    add_method(input, "close", "V", DX_ACC_PUBLIC, noop, 0);
    DxClass *resources = reg_class(vm, "Landroid/content/res/Resources;", obj);
    add_method(resources, "getIdentifier", "ILLL", DX_ACC_PUBLIC, resources_get_identifier, 0);

    DxClass *options = reg_class(vm, "Landroid/graphics/BitmapFactory$Options;", obj);
    one_field(options, "inScaled", "Z");
    add_method(options, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    DxClass *bitmap = reg_class(vm, "Landroid/graphics/Bitmap;", obj);
    one_field(bitmap, "_assetPath", "Ljava/lang/String;");
    add_method(bitmap, "recycle", "V", DX_ACC_PUBLIC, noop, 0);
    DxClass *factory = reg_class(vm, "Landroid/graphics/BitmapFactory;", obj);
    add_method(factory, "decodeStream", "LLLL", DX_ACC_PUBLIC | DX_ACC_STATIC, bitmap_decode, 1);

    DxClass *gles = reg_class(vm, "Landroid/opengl/GLES20;", obj);
    add_method(gles, "glGenTextures", "VI[II", DX_ACC_PUBLIC | DX_ACC_STATIC, gles_gen_textures, 1);
    add_method(gles, "glBindTexture", "VII", DX_ACC_PUBLIC | DX_ACC_STATIC, gles_bind_texture, 1);
    add_method(gles, "glTexParameteri", "VIII", DX_ACC_PUBLIC | DX_ACC_STATIC, gles_tex_parameter, 1);
    add_method(gles, "glDeleteTextures", "VI[II", DX_ACC_PUBLIC | DX_ACC_STATIC, gles_delete_textures, 1);
    DxClass *glutils = reg_class(vm, "Landroid/opengl/GLUtils;", obj);
    add_method(glutils, "texImage2D", "VIILI", DX_ACC_PUBLIC | DX_ACC_STATIC, glutils_tex_image, 1);

    DxClass *log = reg_class(vm, "Landroid/util/Log;", obj);
    add_method(log, "i", "ILL", DX_ACC_PUBLIC | DX_ACC_STATIC, log_call, 1);
    add_method(log, "e", "ILL", DX_ACC_PUBLIC | DX_ACC_STATIC, log_call, 1);
    DxClass *sound_pool = reg_class(vm, "Landroid/media/SoundPool;", obj);
    add_method(sound_pool, "<init>", "VIII", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(sound_pool, "load", "ILII", DX_ACC_PUBLIC, soundpool_load, 0);
    add_method(sound_pool, "play", "IIFFIIF", DX_ACC_PUBLIC, soundpool_play, 0);
    return DX_OK;
}

static int read_file(const char *path, uint8_t **data, uint32_t *size) {
    FILE *file = fopen(path, "rb");
    if (!file) return 0;
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    *data = malloc((size_t)length);
    if (!*data || fread(*data, 1, (size_t)length, file) != (size_t)length) { fclose(file); return 0; }
    fclose(file); *size = (uint32_t)length; return 1;
}

struct agr_dex_game {
    uint8_t *bytes;
    DxDexFile *dex;
    DxVM *vm;
    DxObject *activity;
    DxClass *activity_class;
    DxObject *application;
    DxClass *application_class;
    DxObject *application_context;
    DxObject *activity_context;
    DxObject *intent;
    DxObject *window;
    DxObject *decor;
    DxObject *window_manager;
    DxObject *window_attributes;
    agr_activity_launch_stage launch_stage;
    char launch_error[256];
    agr_dex_native_callback native_callback;
    void *native_callback_user;
    struct { uint32_t handle; DxObject *object; } *objects;
    uint32_t object_count, object_capacity;
    int post_resume_completed;
    int window_attached;
    int window_added;
    int window_visible;
    int idle_handler_scheduled;
    int viewroot_handoff;
    agr_viewroot_attach_state viewroot;
    uint32_t framework_event_count;
    char framework_events[AGR_DEX_FRAMEWORK_TRACE_CAPACITY][96];
};

static void framework_event(agr_dex_game *game, const char *event) {
    if (!game || !game->vm || !game->vm->telemetry.telemetry_enabled || !event) return;
    uint32_t slot = game->framework_event_count % AGR_DEX_FRAMEWORK_TRACE_CAPACITY;
    snprintf(game->framework_events[slot], sizeof(game->framework_events[slot]), "%s", event);
    game->framework_event_count++;
}

static void viewroot_event(void *user, const char *event) {
    framework_event((agr_dex_game *)user, event);
}

static DxResult window_manager_add_view(DxVM *vm, DxFrame *frame,
                                        DxValue *args, uint32_t count) {
    (void)frame;
    agr_dex_game *game = vm ? (agr_dex_game *)vm->framework_user : NULL;
    if (!game || count < 3 || args[0].tag != DX_VAL_OBJ ||
        args[0].obj != game->window_manager ||
        args[1].tag != DX_VAL_OBJ || !args[1].obj ||
        args[2].tag != DX_VAL_OBJ || !args[2].obj)
        return DX_ERR_INVALID_FORMAT;
    DxResult result = agr_viewroot_add_view(vm, &game->viewroot, args[0].obj,
                                            args[1].obj, args[2].obj,
                                            game->window, viewroot_event, game);
    if (result != DX_OK) return result;
    if (dx_vm_set_field(args[0].obj, "_lastView", args[1]) != DX_OK ||
        dx_vm_set_field(args[0].obj, "_lastLayoutParams", args[2]) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    return DX_OK;
}

typedef struct {
    char *name;
    uint8_t *bytes;
    uint32_t size;
} agr_apk_library;

struct agr_apk_package {
    DxApkFile *apk;
    DxManifest *manifest;
    uint8_t *dex_bytes;
    uint32_t dex_size;
    char *activity_descriptor;
    char *application_descriptor;
    char *native_library;
    agr_apk_library *libraries;
    uint32_t library_count;
};

static char *copy_text(const char *text) {
    if (!text) return NULL;
    size_t size=strlen(text)+1;
    char *copy=malloc(size);
    if (copy) memcpy(copy,text,size);
    return copy;
}

static const char *component_metadata(const DxComponent *component, const char *name) {
    if (!component || !name) return NULL;
    for (uint32_t i=0;i<component->meta_data_count;i++)
        if (component->meta_data[i].name && !strcmp(component->meta_data[i].name,name))
            return component->meta_data[i].value;
    return NULL;
}

static char *class_descriptor(const char *name) {
    if (!name) return NULL;
    size_t length=strlen(name);
    char *descriptor=malloc(length+3);
    if (!descriptor) return NULL;
    descriptor[0]='L';
    for (size_t i=0;i<length;i++) descriptor[i+1]=name[i]=='.'?'/':name[i];
    descriptor[length+1]=';'; descriptor[length+2]=0;
    return descriptor;
}

agr_apk_package *agr_apk_package_open(const char *apk_path) {
    agr_apk_package *package=calloc(1,sizeof(*package));
    const DxZipEntry *entry=NULL;
    uint8_t *manifest_bytes=NULL; uint32_t manifest_size=0;
    if (!package || !apk_path || dx_apk_open_file(apk_path,&package->apk)!=DX_OK ||
        dx_apk_find_entry(package->apk,"AndroidManifest.xml",&entry)!=DX_OK ||
        dx_apk_extract_entry(package->apk,entry,&manifest_bytes,&manifest_size)!=DX_OK ||
        dx_manifest_parse(manifest_bytes,manifest_size,&package->manifest)!=DX_OK ||
        !package->manifest->package_name || !package->manifest->main_activity) goto fail;
    dx_free(manifest_bytes); manifest_bytes=NULL;
    package->activity_descriptor=class_descriptor(package->manifest->main_activity);
    package->application_descriptor=package->manifest->application_name
        ? class_descriptor(package->manifest->application_name)
        : copy_text("Landroid/app/Application;");
    const DxComponent *activity=dx_manifest_find_activity(package->manifest,
                                                           package->manifest->main_activity);
    const char *lib=component_metadata(activity,"android.app.lib_name");
    if (!lib) lib="main"; /* NativeActivity.java API19 default. */
    size_t lib_length=strlen(lib);
    if (lib_length>6 && !strncmp(lib,"lib",3) && !strcmp(lib+lib_length-3,".so"))
        package->native_library=copy_text(lib);
    else {
        package->native_library=malloc(lib_length+7);
        if (package->native_library) snprintf(package->native_library,lib_length+7,"lib%s.so",lib);
    }
    if (!package->activity_descriptor || !package->application_descriptor ||
        dx_apk_find_entry(package->apk,"classes.dex",&entry)!=DX_OK ||
        dx_apk_extract_entry(package->apk,entry,&package->dex_bytes,&package->dex_size)!=DX_OK)
        goto fail;

    const char *abi_prefix="lib/armeabi-v7a/";
    size_t prefix_length=strlen(abi_prefix);
    bool found_v7=false;
    for (uint32_t i=0;i<package->apk->entry_count;i++)
        if (!strncmp(package->apk->entries[i].filename,abi_prefix,prefix_length)) { found_v7=true; break; }
    if (!found_v7) { abi_prefix="lib/armeabi/"; prefix_length=strlen(abi_prefix); }
    for (uint32_t i=0;i<package->apk->entry_count;i++) {
        const DxZipEntry *candidate=&package->apk->entries[i];
        const char *filename=candidate->filename;
        size_t length=filename?strlen(filename):0;
        if (!filename || strncmp(filename,abi_prefix,prefix_length) || length<3 ||
            strcmp(filename+length-3,".so")) continue;
        agr_apk_library *grown=realloc(package->libraries,
            sizeof(*grown)*(package->library_count+1));
        if (!grown) goto fail;
        package->libraries=grown;
        agr_apk_library *library=&package->libraries[package->library_count];
        memset(library,0,sizeof(*library));
        library->name=copy_text(filename+prefix_length);
        if (!library->name || dx_apk_extract_entry(package->apk,candidate,&library->bytes,
                                                    &library->size)!=DX_OK) goto fail;
        package->library_count++;
    }
    return package;
fail:
    dx_free(manifest_bytes);
    agr_apk_package_close(package);
    return NULL;
}

void agr_apk_package_close(agr_apk_package *package) {
    if (!package) return;
    for (uint32_t i=0;i<package->library_count;i++) {
        free(package->libraries[i].name); dx_free(package->libraries[i].bytes);
    }
    free(package->libraries); free(package->activity_descriptor); free(package->application_descriptor);
    free(package->native_library);
    dx_free(package->dex_bytes); dx_manifest_free(package->manifest);
    if (package->apk) dx_apk_close(package->apk);
    free(package);
}
const char *agr_apk_package_name(const agr_apk_package *p){return p&&p->manifest?p->manifest->package_name:NULL;}
const char *agr_apk_launch_activity(const agr_apk_package *p){return p?p->activity_descriptor:NULL;}
const char *agr_apk_native_library(const agr_apk_package *p){return p?p->native_library:NULL;}
int32_t agr_apk_min_sdk(const agr_apk_package *p){return p&&p->manifest?p->manifest->min_sdk:0;}
int32_t agr_apk_target_sdk(const agr_apk_package *p){return p&&p->manifest?p->manifest->target_sdk:0;}
const void *agr_apk_dex_bytes(const agr_apk_package *p,uint32_t *size){if(size)*size=p?p->dex_size:0;return p?p->dex_bytes:NULL;}
uint32_t agr_apk_native_library_count(const agr_apk_package *p){return p?p->library_count:0;}
const char *agr_apk_native_library_name(const agr_apk_package *p,uint32_t i){return p&&i<p->library_count?p->libraries[i].name:NULL;}
const void *agr_apk_native_library_bytes(const agr_apk_package *p,uint32_t i,uint32_t *size){if(size)*size=p&&i<p->library_count?p->libraries[i].size:0;return p&&i<p->library_count?p->libraries[i].bytes:NULL;}

static agr_dex_game *create_game(const uint8_t *bytes, uint32_t size,
                                 const char *activity_descriptor,
                                 const char *application_descriptor,
                                 const char *package_name) {
    agr_dex_game *game = calloc(1,sizeof(*game));
    if (!game) return NULL;
    DxClass *cls=NULL;
    game->bytes=malloc(size);
    if (game->bytes) memcpy(game->bytes,bytes,size);
    snprintf(g_package_name,sizeof(g_package_name),"%s",package_name?package_name:"");
    if (!game->bytes || !activity_descriptor ||
        dx_dex_parse(game->bytes,size,&game->dex)!=DX_OK ||
        !(game->vm=dx_vm_create(NULL)) ||
        dx_vm_load_dex(game->vm,game->dex)!=DX_OK ||
        dx_register_java_lang(game->vm)!=DX_OK ||
        register_game_framework(game->vm)!=DX_OK)
        goto fail;
    game->vm->framework_user=game;
    if (dx_vm_load_class(game->vm,activity_descriptor,&cls)!=DX_OK || !cls) {
        snprintf(game->launch_error,sizeof(game->launch_error),
                 "activity class resolution failed: %s",activity_descriptor);
        return game;
    }
    game->launch_stage=AGR_ACTIVITY_LAUNCH_CLASS_RESOLVED;
    game->activity_class=cls;
    game->activity=dx_vm_alloc_object(game->vm,cls);
    if (!game->activity) goto fail;
    /* performLaunchActivity retains the new Activity in process launch state
     * while LoadedApk creates/initializes the Application. */
    game->vm->activity_instance=game->activity;
    g_activity=game->activity;
    game->launch_stage=AGR_ACTIVITY_LAUNCH_ACTIVITY_INSTANTIATED;
    const char *app_desc=application_descriptor&&application_descriptor[0]
        ? application_descriptor : "Landroid/app/Application;";
    if (dx_vm_load_class(game->vm,app_desc,&game->application_class)!=DX_OK ||
        !game->application_class) {
        snprintf(game->launch_error,sizeof(game->launch_error),"application class not found: %s",app_desc);
        return game;
    }
    /* ActivityThread owns the launched Activity independently of whether a
     * framework constructor happens to install the same root.  NativeActivity
     * in this host-side API19 environment has a no-op constructor, so make the
     * process root explicit before any allocation can trigger collection. */
    return game;
fail:
    agr_dex_game_destroy(game); return NULL;
}

static char *method_signature(const agr_dex_game *game, const DxMethod *method) {
    if (!game || !method || method->dex_method_idx >= game->dex->method_count) return NULL;
    uint32_t count=dx_dex_get_method_param_count(game->dex,method->dex_method_idx);
    const char *ret=dx_dex_get_method_return_type(game->dex,method->dex_method_idx);
    size_t length=3+(ret?strlen(ret):0);
    for(uint32_t i=0;i<count;i++) {
        const char *type=dx_dex_get_method_param_type(game->dex,method->dex_method_idx,i);
        length+=type?strlen(type):0;
    }
    char *signature=malloc(length);
    if(!signature)return NULL;
    char *out=signature;*out++='(';
    for(uint32_t i=0;i<count;i++) {
        const char *type=dx_dex_get_method_param_type(game->dex,method->dex_method_idx,i);
        if(type){size_t n=strlen(type);memcpy(out,type,n);out+=n;}
    }
    *out++=')';if(ret){size_t n=strlen(ret);memcpy(out,ret,n);out+=n;}*out=0;
    return signature;
}

static uint32_t object_handle(agr_dex_game *game, DxObject *object) {
    if(!game||!object)return 0;
    for(uint32_t i=0;i<game->object_count;i++)if(game->objects[i].object==object)return game->objects[i].handle;
    if(game->object_count==game->object_capacity) {
        uint32_t next=game->object_capacity?game->object_capacity*2:16;
        void *grown=realloc(game->objects,(size_t)next*sizeof(*game->objects));
        if(!grown)return 0;game->objects=grown;game->object_capacity=next;
    }
    uint32_t handle=0x67000000u+game->object_count*4u;
    game->objects[game->object_count++]=(typeof(*game->objects)){handle,object};
    return handle;
}

static DxResult dex_unbound_native(DxVM *vm, DxFrame *frame, DxMethod *method,
                                   DxValue *args, uint32_t count, void *user) {
    (void)vm;
    agr_dex_game *game=(agr_dex_game *)user;
    if(!game||!game->native_callback)return DX_ERR_METHOD_NOT_FOUND;
    char *signature=method_signature(game,method);
    if(!signature)return DX_ERR_METHOD_NOT_FOUND;
    agr_dex_argument *native_args=count?calloc(count,sizeof(*native_args)):NULL;
    if(count&&!native_args){free(signature);return DX_ERR_OUT_OF_MEMORY;}
    for(uint32_t i=0;i<count;i++) {
        if(args[i].tag==DX_VAL_INT){native_args[i].kind=AGR_DEX_ARG_INT;native_args[i].value.i=args[i].i;}
        else if(args[i].tag==DX_VAL_FLOAT){native_args[i].kind=AGR_DEX_ARG_FLOAT;native_args[i].value.f=args[i].f;}
        else if(args[i].tag==DX_VAL_OBJ&&!args[i].obj){native_args[i].kind=AGR_DEX_ARG_NULL;}
        else if(args[i].tag==DX_VAL_OBJ&&args[i].obj) {
            const char *text=dx_vm_get_string_value(args[i].obj);
            if(text){native_args[i].kind=AGR_DEX_ARG_STRING;native_args[i].value.string=text;}
            else {native_args[i].kind=AGR_DEX_ARG_OBJECT;native_args[i].value.object=object_handle(game,args[i].obj);}
        } else {free(native_args);free(signature);return DX_ERR_INTERNAL;}
    }
    agr_dex_argument result={0};
    int32_t rc=game->native_callback(game->native_callback_user,
        method->declaring_class?method->declaring_class->descriptor:NULL,method->name,signature,
        (method->access_flags&DX_ACC_STATIC)!=0,native_args,count,&result);
    if(!rc&&result.kind==AGR_DEX_ARG_INT){frame->result=DX_INT_VALUE(result.value.i);frame->has_result=true;}
    else if(!rc&&result.kind==AGR_DEX_ARG_FLOAT){frame->result.tag=DX_VAL_FLOAT;frame->result.f=result.value.f;frame->has_result=true;}
    free(native_args);free(signature);
    return rc?DX_ERR_INTERNAL:DX_OK;
}

void agr_dex_game_set_native_callback(agr_dex_game *game,
                                      agr_dex_native_callback callback, void *user) {
    if(!game)return;
    game->native_callback=callback;game->native_callback_user=user;
    game->vm->unbound_native_fn=callback?dex_unbound_native:NULL;
    game->vm->unbound_native_user=game;
}
void agr_dex_game_set_load_library_callback(agr_dex_game *game,
                                            int32_t (*callback)(void *, const char *),
                                            void *user) {
    if(!game)return;game->vm->load_library_fn=callback;game->vm->load_library_user=user;
}

int agr_dex_game_start_activity(agr_dex_game *game) {
    if (!game || !game->activity_class || !game->activity) return -1;
    DxVM *vm=game->vm;
    DxClass *context_class=dx_vm_find_class(vm,"Landroid/content/Context;");
    DxClass *intent_class=dx_vm_find_class(vm,"Landroid/content/Intent;");
    if (!intent_class) intent_class=reg_class(vm,"Landroid/content/Intent;",vm->class_object);
    game->application_context=dx_vm_alloc_object(vm,context_class);
    game->activity_context=dx_vm_alloc_object(vm,context_class);
    game->intent=dx_vm_alloc_object(vm,intent_class);
    game->application=dx_vm_alloc_object(vm,game->application_class);
    game->window=dx_vm_alloc_object(vm,dx_vm_find_class(vm,"Landroid/view/Window;"));
    game->decor=dx_vm_alloc_object(vm,dx_vm_find_class(vm,"Landroid/view/View;"));
    game->window_manager=dx_vm_alloc_object(vm,dx_vm_find_class(vm,"Landroid/view/WindowManager;"));
    game->window_attributes=dx_vm_alloc_object(vm,
        dx_vm_find_class(vm,"Landroid/view/WindowManager$LayoutParams;"));
    if (!game->application_context || !game->activity_context || !game->intent ||
        !game->application || !game->window || !game->decor || !game->window_manager ||
        !game->window_attributes) {
        snprintf(game->launch_error,sizeof(game->launch_error),"launch object allocation failed");
        return -1;
    }
    vm->application_context=game->application_context;
    vm->activity_context=game->activity_context;
    vm->launch_intent=game->intent;
    vm->application_instance=game->application;
    game->launch_stage=AGR_ACTIVITY_LAUNCH_APPLICATION_CREATED;
    framework_event(game,"launch.application.instantiate");

    DxMethod *app_init=dx_vm_find_method(game->application_class,"<init>","V");
    DxValue app_args[1]={DX_OBJ_VALUE(game->application)};
    if (!app_init || dx_vm_execute_method(vm,app_init,app_args,1,NULL)!=DX_OK) {
        snprintf(game->launch_error,sizeof(game->launch_error),"Application constructor failed");
        return -1;
    }
    dx_vm_set_field(game->application,"_baseContext",DX_OBJ_VALUE(game->application_context));
    game->launch_stage=AGR_ACTIVITY_LAUNCH_CONTEXT_ATTACHED;
    framework_event(game,"launch.application.context_attached");
    DxMethod *app_create=dx_vm_find_method(game->application_class,"onCreate","V");
    if (app_create && dx_vm_execute_method(vm,app_create,app_args,1,NULL)!=DX_OK) {
        snprintf(game->launch_error,sizeof(game->launch_error),"Application.onCreate failed: %s",vm->error_msg);
        return -1;
    }

    DxClass *cls=game->activity_class;
    DxMethod *init=dx_vm_find_method(cls,"<init>","V");
    DxValue init_args[1]={DX_OBJ_VALUE(game->activity)};
    if (!init || dx_vm_execute_method(vm,init,init_args,1,NULL)!=DX_OK) {
        snprintf(game->launch_error,sizeof(game->launch_error),"Activity constructor failed: %s",vm->error_msg);
        return -1;
    }
    dx_vm_set_field(game->activity,"_baseContext",DX_OBJ_VALUE(game->activity_context));
    dx_vm_set_field(game->activity,"_application",DX_OBJ_VALUE(game->application));
    dx_vm_set_field(game->activity,"_intent",DX_OBJ_VALUE(game->intent));
    dx_vm_set_field(game->window,"_decor",DX_OBJ_VALUE(game->decor));
    dx_vm_set_field(game->window,"_attributes",DX_OBJ_VALUE(game->window_attributes));
    dx_vm_set_field(game->activity,"_window",DX_OBJ_VALUE(game->window));
    dx_vm_set_field(game->activity,"_windowManager",DX_OBJ_VALUE(game->window_manager));
    dx_vm_set_field(game->activity,"_decor",DX_OBJ_VALUE(game->decor));
    dx_vm_set_field(game->activity,"_startedActivity",DX_INT_VALUE(0));
    dx_vm_set_field(game->activity,"_finished",DX_INT_VALUE(0));
    dx_vm_set_field(game->activity,"_visibleFromClient",DX_INT_VALUE(1));
    dx_vm_set_field(game->activity,"_visibleFromServer",DX_INT_VALUE(0));
    dx_vm_set_field(game->activity,"_windowAdded",DX_INT_VALUE(0));
    dx_vm_set_field(game->window_attributes,"_type",DX_INT_VALUE(1));
    dx_vm_set_field(game->window_attributes,"_softInputMode",DX_INT_VALUE(0));
    dx_vm_set_field(game->window_attributes,"_width",DX_INT_VALUE(-1));
    dx_vm_set_field(game->window_attributes,"_height",DX_INT_VALUE(-1));
    dx_vm_set_field(game->decor,"_visibility",DX_INT_VALUE(4));
    game->window_attached=1;
    game->launch_stage=AGR_ACTIVITY_LAUNCH_ACTIVITY_ATTACHED;
    framework_event(game,"launch.activity.attached");
    framework_event(game,"activity.attach.window");
    DxMethod *on_create=dx_vm_find_method(cls,"onCreate","VL");
    DxValue create_args[2]={DX_OBJ_VALUE(game->activity),DX_NULL_VALUE};
    if (!on_create) {
        snprintf(game->launch_error,sizeof(game->launch_error),"Activity.onCreate unresolved");
        return -1;
    }
    game->launch_stage=AGR_ACTIVITY_LAUNCH_ON_CREATE_ENTERED;
    framework_event(game,"lifecycle.onCreate.enter");
    if (dx_vm_execute_method(vm,on_create,create_args,2,NULL)!=DX_OK) {
        snprintf(game->launch_error,sizeof(game->launch_error),"Activity.onCreate failed: %s",vm->error_msg);
        return -1;
    }
    game->launch_stage=AGR_ACTIVITY_LAUNCH_ON_CREATE_RETURNED;
    framework_event(game,"lifecycle.onCreate.return");
    DxMethod *on_start=dx_vm_find_method(cls,"onStart","V");
    if (on_start && dx_vm_execute_method(vm,on_start,init_args,1,NULL)!=DX_OK) return -1;
    game->launch_stage=AGR_ACTIVITY_LAUNCH_STARTED;
    framework_event(game,"lifecycle.onStart.return");
    DxMethod *on_resume=dx_vm_find_method(cls,"onResume","V");
    if (on_resume && dx_vm_execute_method(vm,on_resume,init_args,1,NULL)!=DX_OK) return -1;
    framework_event(game,"lifecycle.onResume.return");
    DxMethod *on_post_resume=dx_vm_find_method(cls,"onPostResume","V");
    if (!on_post_resume || dx_vm_execute_method(vm,on_post_resume,init_args,1,NULL)!=DX_OK) {
        snprintf(game->launch_error,sizeof(game->launch_error),"Activity.onPostResume failed: %s",vm->error_msg);
        return -1;
    }
    game->post_resume_completed=1;
    framework_event(game,"lifecycle.onPostResume.return");
    framework_event(game,"coordinator.performResume.return");

    /* API19 ActivityThread.handleResumeActivity owns this continuous semantic
       cluster after performResumeActivity returns: obtain the Activity window
       and decor, keep decor invisible while WindowManager attaches it, then
       publish Activity visibility and schedule the idle-report boundary.  The
       next owner is ViewRoot/Surface; this phase records that handoff without
       claiming to implement the downstream subsystem. */
    DxClass *activity_base=dx_vm_find_class(vm,"Landroid/app/Activity;");
    DxClass *window_class=dx_vm_find_class(vm,"Landroid/view/Window;");
    DxClass *view_class=dx_vm_find_class(vm,"Landroid/view/View;");
    DxClass *manager_class=dx_vm_find_class(vm,"Landroid/view/WindowManager;");
    DxMethod *get_window=dx_vm_find_method(activity_base,"getWindow","L");
    DxMethod *get_decor=dx_vm_find_method(window_class,"getDecorView","L");
    DxMethod *set_visibility=dx_vm_find_method(view_class,"setVisibility","VI");
    DxMethod *get_manager=dx_vm_find_method(activity_base,"getWindowManager","L");
    DxMethod *get_attributes=dx_vm_find_method(window_class,"getAttributes","L");
    DxMethod *add_view=dx_vm_find_method(manager_class,"addView","VLL");
    DxValue value=DX_NULL_VALUE;
    if (!get_window || dx_vm_execute_method(vm,get_window,init_args,1,&value)!=DX_OK ||
        value.tag!=DX_VAL_OBJ || value.obj!=game->window) goto window_cluster_failed;
    framework_event(game,"window.obtain");
    DxValue window_args[1]={value};
    if (!get_decor || dx_vm_execute_method(vm,get_decor,window_args,1,&value)!=DX_OK ||
        value.tag!=DX_VAL_OBJ || value.obj!=game->decor) goto window_cluster_failed;
    framework_event(game,"window.decor.obtain");
    DxValue visibility_args[2]={DX_OBJ_VALUE(game->decor),DX_INT_VALUE(4)};
    if (!set_visibility || dx_vm_execute_method(vm,set_visibility,visibility_args,2,NULL)!=DX_OK)
        goto window_cluster_failed;
    framework_event(game,"window.decor.invisible");
    if (!get_manager || dx_vm_execute_method(vm,get_manager,init_args,1,&value)!=DX_OK ||
        value.tag!=DX_VAL_OBJ || value.obj!=game->window_manager) goto window_cluster_failed;
    if (!get_attributes || dx_vm_execute_method(vm,get_attributes,window_args,1,&value)!=DX_OK ||
        value.tag!=DX_VAL_OBJ || value.obj!=game->window_attributes) goto window_cluster_failed;
    DxValue add_args[3]={DX_OBJ_VALUE(game->window_manager),DX_OBJ_VALUE(game->decor),
                         DX_OBJ_VALUE(game->window_attributes)};
    if (!add_view || dx_vm_execute_method(vm,add_view,add_args,3,NULL)!=DX_OK)
        goto window_cluster_failed;
    dx_vm_set_field(game->activity,"_windowAdded",DX_INT_VALUE(1));
    game->window_added=1;
    framework_event(game,"window_manager.add_view");
    visibility_args[1]=DX_INT_VALUE(0);
    if (dx_vm_execute_method(vm,set_visibility,visibility_args,2,NULL)!=DX_OK)
        goto window_cluster_failed;
    dx_vm_set_field(game->activity,"_visibleFromServer",DX_INT_VALUE(1));
    game->window_visible=1;
    framework_event(game,"activity.make_visible");
    game->idle_handler_scheduled=1;
    framework_event(game,"looper.idle_handler.scheduled");
    if (!game->viewroot.attach_complete || !game->viewroot.pending_first_traversal ||
        game->viewroot.decor != game->decor ||
        game->viewroot.layout_params != game->window_attributes ||
        game->viewroot.attached_window != game->window)
        goto window_cluster_failed;
    game->viewroot_handoff=1;
    framework_event(game,"handoff.viewroot_traversal");
    game->launch_stage=AGR_ACTIVITY_LAUNCH_RESUMED;
    return 0;

window_cluster_failed:
    snprintf(game->launch_error,sizeof(game->launch_error),
             "ActivityThread window visibility cluster failed: %s",vm->error_msg);
    return -1;
}

void agr_dex_game_enable_diagnostics(agr_dex_game *game, int enabled) {
    if (!game || !game->vm) return;
    dx_vm_set_telemetry_enabled(game->vm, enabled != 0);
}

int agr_dex_game_runtime_snapshot(const agr_dex_game *game, agr_dex_runtime_snapshot *snapshot) {
    if (!game || !game->vm || !snapshot) return -1;
    const DxVM *vm=game->vm;
    memset(snapshot,0,sizeof(*snapshot));
    snapshot->methods_invoked=vm->telemetry.total_methods_invoked;
    snapshot->instructions_executed=vm->insn_total;
    snapshot->stack_depth=vm->stack_depth;
    snapshot->vm_running=vm->running ? 1 : 0;
    snapshot->pending_exception=vm->pending_exception ? 1 : 0;
    snapshot->post_resume_completed=game->post_resume_completed;
    snapshot->window_attached=game->window_attached;
    snapshot->window_added=game->window_added;
    snapshot->window_visible=game->window_visible;
    snapshot->idle_handler_scheduled=game->idle_handler_scheduled;
    snapshot->viewroot_handoff=game->viewroot_handoff;
    snapshot->viewroot_created=game->viewroot.root!=NULL;
    snapshot->viewroot_root_assigned=game->viewroot.decor==game->decor &&
        game->viewroot.layout_params==game->window_attributes;
    snapshot->traversal_scheduled=game->viewroot.pending_first_traversal;
    snapshot->window_session_attached=game->viewroot.attached_window==game->window;
    DxValue parent=DX_NULL_VALUE;
    snapshot->view_parent_assigned=game->decor && game->viewroot.root &&
        dx_vm_get_field(game->decor,"_parent",&parent)==DX_OK &&
        parent.tag==DX_VAL_OBJ && parent.obj==game->viewroot.root;
    snapshot->viewroot_attach_completed=game->viewroot.attach_complete;
    snapshot->hierarchy_attached=game->viewroot.hierarchy_attached;
    snapshot->traversal_phase=(int)game->viewroot.traversal_phase;
    snapshot->traversal_count=game->viewroot.traversal_count;
    snapshot->measured_width=game->viewroot.measured_width;
    snapshot->measured_height=game->viewroot.measured_height;
    snapshot->frame_left=game->viewroot.frame_left;
    snapshot->frame_top=game->viewroot.frame_top;
    snapshot->frame_right=game->viewroot.frame_right;
    snapshot->frame_bottom=game->viewroot.frame_bottom;
    snapshot->layout_complete=game->viewroot.layout_complete;
    snapshot->surface_valid=agr_viewroot_surface_valid(&game->viewroot);
    snapshot->surface_generation=game->viewroot.backing.generation;
    snprintf(snapshot->last_method,sizeof(snapshot->last_method),"%s",vm->diagnostic_last_method);
    snprintf(snapshot->error,sizeof(snapshot->error),"%s",vm->error_msg);
    uint32_t method_count=vm->diagnostic_method_event_count;
    uint64_t method_start=vm->diagnostic_method_sequence > method_count
        ? vm->diagnostic_method_sequence - method_count : 0;
    snapshot->method_event_count=method_count;
    for (uint32_t i=0;i<method_count;i++) {
        const DxDiagnosticMethodEvent *source=
            &vm->diagnostic_method_events[(method_start+i)%DX_DIAGNOSTIC_METHOD_EVENTS];
        snapshot->method_events[i].sequence=source->sequence;
        snapshot->method_events[i].depth=source->depth;
        snapshot->method_events[i].is_native=source->is_native ? 1 : 0;
        snprintf(snapshot->method_events[i].method,sizeof(snapshot->method_events[i].method),
                 "%s",source->method);
    }
    uint32_t framework_count=game->framework_event_count < AGR_DEX_FRAMEWORK_TRACE_CAPACITY
        ? game->framework_event_count : AGR_DEX_FRAMEWORK_TRACE_CAPACITY;
    uint32_t framework_start=game->framework_event_count > framework_count
        ? game->framework_event_count-framework_count : 0;
    snapshot->framework_event_count=framework_count;
    for (uint32_t i=0;i<framework_count;i++)
        snprintf(snapshot->framework_events[i],sizeof(snapshot->framework_events[i]),"%s",
                 game->framework_events[(framework_start+i)%AGR_DEX_FRAMEWORK_TRACE_CAPACITY]);
    if (vm->pending_exception && vm->pending_exception->klass &&
        vm->pending_exception->klass->descriptor)
        snprintf(snapshot->exception_class,sizeof(snapshot->exception_class),"%s",
                 vm->pending_exception->klass->descriptor);
    return 0;
}

static int field_is_object(DxObject *owner, const char *name, DxObject *expected) {
    DxValue value=DX_NULL_VALUE;
    return owner && dx_vm_get_field(owner,name,&value)==DX_OK &&
           value.tag==DX_VAL_OBJ && value.obj==expected;
}

int agr_dex_game_viewroot_contract(agr_dex_game *game) {
    if (!game || !game->vm || !game->viewroot.attach_complete ||
        !game->viewroot.layout_requested || game->viewroot.pending_first_traversal!=1 ||
        !game->viewroot.input_channel_owned || !game->viewroot.app_visible ||
        game->viewroot.decor!=game->decor ||
        game->viewroot.layout_params!=game->window_attributes ||
        game->viewroot.attached_window!=game->window)
        return 0;
    if (!field_is_object(game->window_manager,"_lastView",game->decor) ||
        !field_is_object(game->window_manager,"_lastLayoutParams",game->window_attributes) ||
        !field_is_object(game->window_manager,"_viewRoot",game->viewroot.root) ||
        !field_is_object(game->viewroot.root,"_view",game->decor) ||
        !field_is_object(game->viewroot.root,"_layoutParams",game->window_attributes) ||
        !field_is_object(game->viewroot.root,"_session",game->viewroot.session) ||
        !field_is_object(game->viewroot.root,"_attachInfo",game->viewroot.attach_info) ||
        !field_is_object(game->viewroot.attach_info,"_rootView",game->decor) ||
        !field_is_object(game->decor,"_parent",game->viewroot.root) ||
        !field_is_object(game->viewroot.session,"_attachedWindow",game->window))
        return 0;
    return 1;
}

int agr_dex_game_post_resume_completed(const agr_dex_game *game) {
    return game ? game->post_resume_completed : 0;
}

agr_dex_game *agr_dex_game_create_for_launch(const void *dex_bytes, uint32_t dex_size,
                                              const char *activity_descriptor,
                                              const char *application_descriptor,
                                              const char *package_name) {
    return create_game((const uint8_t *)dex_bytes,dex_size,activity_descriptor,
                       application_descriptor,package_name);
}

agr_activity_launch_stage agr_dex_game_launch_stage(const agr_dex_game *game) {
    return game ? game->launch_stage : AGR_ACTIVITY_LAUNCH_NONE;
}
const char *agr_dex_game_launch_error(const agr_dex_game *game) {
    return game ? game->launch_error : "game unavailable";
}

void agr_dex_game_destroy(agr_dex_game *game) {
    if (!game) return;
    if (g_activity==game->activity) g_activity=NULL;
    agr_viewroot_release(&game->viewroot);
    if (game->vm) dx_vm_destroy(game->vm);
    if (game->dex) dx_dex_free(game->dex);
    free(game->objects); free(game->bytes); free(game);
}

int agr_dex_game_do_traversal(agr_dex_game *game, uint32_t width, uint32_t height) {
    if (!game || !game->vm) return -1;
    agr_viewroot_display display = { width, height };
    DxResult result = agr_viewroot_do_traversal(game->vm, &game->viewroot,
                                                display, viewroot_event, game);
    if (result != DX_OK) {
        snprintf(game->launch_error, sizeof(game->launch_error),
                 "first ViewRoot traversal failed: %d", (int)result);
        return -1;
    }
    return 0;
}

int agr_dex_game_set_surface_allocator(agr_dex_game *game,
                                       void *(*allocate)(void *, size_t),
                                       void (*release)(void *, void *), void *user) {
    if (!game || !!allocate != !!release || game->viewroot.backing.pixels) return -1;
    game->viewroot.pixel_alloc = allocate;
    game->viewroot.pixel_free = release;
    game->viewroot.pixel_user = user;
    return 0;
}

int agr_dex_game_activity_gc_contract(agr_dex_game *game) {
    if (!game || !game->vm || !game->activity ||
        game->vm->activity_instance != game->activity) return -1;
    if (dx_vm_gc_collect(game->vm) != DX_OK ||
        game->vm->activity_instance != game->activity) return -1;
    for (uint32_t i=0; i<game->vm->heap_count; i++)
        if (game->vm->heap[i] == game->activity) return 0;
    return -1;
}
int agr_dex_game_application_gc_contract(agr_dex_game *game) {
    if (!game || !game->vm || !game->application ||
        game->vm->application_instance != game->application) return -1;
    if (dx_vm_gc_collect(game->vm) != DX_OK ||
        game->vm->application_instance != game->application) return -1;
    for (uint32_t i=0; i<game->vm->heap_count; i++)
        if (game->vm->heap[i] == game->application) return 0;
    return -1;
}
int agr_dex_game_static_int(agr_dex_game *game, const char *class_descriptor,
                            const char *field_name, int32_t *value) {
    if (!game || !class_descriptor || !field_name || !value) return -1;
    DxClass *cls=dx_vm_find_class(game->vm,class_descriptor);
    if (!cls || !cls->dex_file || !cls->static_fields ||
        cls->dex_class_def_idx>=cls->dex_file->class_count) return -1;
    DxDexClassData *data=cls->dex_file->class_data[cls->dex_class_def_idx];
    if (!data) return -1;
    for (uint32_t i=0;i<data->static_fields_count;i++) {
        const char *name=dx_dex_get_field_name(cls->dex_file,data->static_fields[i].field_idx);
        if (name && !strcmp(name,field_name) && cls->static_fields[i].tag==DX_VAL_INT) {
            *value=cls->static_fields[i].i; return 0;
        }
    }
    return -1;
}
const char *agr_dex_game_activity_descriptor(const agr_dex_game *game) {
    return game&&game->activity_class?game->activity_class->descriptor:NULL;
}

static DxMethod *find_exact_method(agr_dex_game *game, DxClass *cls,
                                   const char *name, const char *signature) {
    for(DxClass *at=cls;at;at=at->super_class) {
        for(uint32_t group=0;group<2;group++) {
            DxMethod *methods=group?at->virtual_methods:at->direct_methods;
            uint32_t count=group?at->virtual_method_count:at->direct_method_count;
            for(uint32_t i=0;i<count;i++) if(methods[i].name&&!strcmp(methods[i].name,name)) {
                char *candidate=method_signature(game,&methods[i]);
                int match=candidate&&!strcmp(candidate,signature);free(candidate);
                if(match)return &methods[i];
            }
        }
    }
    return NULL;
}
int agr_dex_game_resolve_class(agr_dex_game *game, const char *descriptor) {
    DxClass *cls=NULL;
    return game&&descriptor&&dx_vm_load_class(game->vm,descriptor,&cls)==DX_OK&&cls?0:-1;
}
int agr_dex_game_resolve_method(agr_dex_game *game, const char *class_descriptor,
                                const char *name, const char *signature, int is_static) {
    DxClass *cls=NULL;
    if(!game||!class_descriptor||!name||!signature||
       dx_vm_load_class(game->vm,class_descriptor,&cls)!=DX_OK||!cls)return -1;
    DxMethod *method=find_exact_method(game,cls,name,signature);
    return method&&(is_static<0||(((method->access_flags&DX_ACC_STATIC)!=0)==!!is_static))?0:-1;
}

int agr_dex_game_invoke_int(agr_dex_game *game, const char *name, const char *signature,
                            const agr_dex_argument *arguments, uint32_t argument_count,
                            int32_t *value) {
    if (!game || !name || !signature || argument_count+1>DX_MAX_REGISTERS) return -1;
    DxMethod *method=find_exact_method(game,game->activity_class,name,signature);
    if (!method || !method->shorty || method->shorty[0]!='I') return -1;
    DxValue args[DX_MAX_REGISTERS]={0}; args[0]=DX_OBJ_VALUE(game->activity);
    for (uint32_t i=0;i<argument_count;i++) {
        switch(arguments[i].kind) {
        case AGR_DEX_ARG_INT: args[i+1]=DX_INT_VALUE(arguments[i].value.i); break;
        case AGR_DEX_ARG_FLOAT: args[i+1].tag=DX_VAL_FLOAT;args[i+1].f=arguments[i].value.f;break;
        case AGR_DEX_ARG_STRING:
            args[i+1]=DX_OBJ_VALUE(dx_vm_create_string(game->vm,arguments[i].value.string));break;
        case AGR_DEX_ARG_NULL: args[i+1]=DX_NULL_VALUE;break;
        default:return -1;
        }
    }
    DxValue result=DX_INT_VALUE(0);
    DxResult rc=dx_vm_execute_method(game->vm,method,args,argument_count+1,&result);
    if (rc!=DX_OK || result.tag!=DX_VAL_INT) return -1;
    if (value) *value=result.i;
    return 0;
}

int agr_dex_game_load_image(agr_dex_game *game, const char *path, int32_t *texture) {
    agr_dex_argument arg={AGR_DEX_ARG_STRING,{.string=path}};
    return agr_dex_game_invoke_int(game,"loadImage","(Ljava/lang/String;)I",&arg,1,texture);
}

agr_dex_game *agr_dex_game_create(const char *dex_path) {
    uint8_t *bytes=NULL; uint32_t size=0;
    if (!read_file(dex_path,&bytes,&size)) return NULL;
    agr_dex_game *game=create_game(bytes,size,
        "Lcom/onetwofivegames/kungfoobarracuda/KungFooBarracudaNativeActivity;",
        "Landroid/app/Application;",
        "com.onetwofivegames.kungfoobarracuda");
    free(bytes);
    if (game && agr_dex_game_start_activity(game)) { agr_dex_game_destroy(game);game=NULL; }
    return game;
}

agr_dex_game *agr_dex_game_create_from_apk(const agr_apk_package *package) {
    return package?create_game(package->dex_bytes,package->dex_size,
        package->activity_descriptor,package->application_descriptor,
        package->manifest->package_name):NULL;
}

int agr_dex_game_play_sound(agr_dex_game *game, const char *path, float direction, int32_t *play_id) {
    agr_dex_argument args[2]={{AGR_DEX_ARG_STRING,{.string=path}},
                              {AGR_DEX_ARG_FLOAT,{.f=direction}}};
    return agr_dex_game_invoke_int(game,"playSound","(Ljava/lang/String;F)I",args,2,play_id);
}

int agr_dex_game_main(int argc, char **argv) {
    if (argc != 3) { fprintf(stderr, "usage: dex_game_runner classes.dex image\n"); return 2; }
    g_opened_asset[0] = 0; g_uploaded_asset[0] = 0; g_bound_texture = 0; g_log_calls = 0;
    uint8_t *data = NULL; uint32_t size = 0; DxDexFile *dex = NULL;
    if (!read_file(argv[1], &data, &size) || dx_dex_parse(data, size, &dex) != DX_OK) return 3;
    DxVM *vm = dx_vm_create(NULL);
    if (!vm || dx_vm_load_dex(vm, dex) != DX_OK || dx_register_java_lang(vm) != DX_OK ||
        register_game_framework(vm) != DX_OK) return 4;
    DxClass *cls = NULL;
    DxResult rc = dx_vm_load_class(vm,
        "Lcom/onetwofivegames/kungfoobarracuda/KungFooBarracudaNativeActivity;", &cls);
    if (rc != DX_OK || !cls) { printf("{\"stage\":\"load_class\",\"rc\":%d}\n", rc); return 5; }
    g_activity = dx_vm_alloc_object(vm, cls);
    DxMethod *init = dx_vm_find_method(cls, "<init>", "V");
    DxValue init_args[1] = { DX_OBJ_VALUE(g_activity) };
    rc = init ? dx_vm_execute_method(vm, init, init_args, 1, NULL) : DX_ERR_METHOD_NOT_FOUND;
    if (rc != DX_OK) { printf("{\"stage\":\"activity_init\",\"rc\":%d}\n", rc); return 6; }
    DxMethod *on_create = dx_vm_find_method(cls, "onCreate", "VL");
    DxValue create_args[2] = { DX_OBJ_VALUE(g_activity), DX_NULL_VALUE };
    rc = on_create ? dx_vm_execute_method(vm, on_create, create_args, 2, NULL) : DX_ERR_METHOD_NOT_FOUND;
    if (rc != DX_OK) { printf("{\"stage\":\"onCreate\",\"rc\":%d}\n", rc); return 7; }
    DxMethod *load = dx_vm_find_method(cls, "loadImage", "IL");
    DxObject *name = dx_vm_create_string(vm, argv[2]);
    DxValue call_args[2] = { DX_OBJ_VALUE(g_activity), DX_OBJ_VALUE(name) };
    DxValue result = DX_INT_VALUE(0);
    rc = load ? dx_vm_execute_method(vm, load, call_args, 2, &result) : DX_ERR_METHOD_NOT_FOUND;
    printf("{\"stage\":\"loadImage\",\"rc\":%d,\"result\":%d,\"opened_asset\":\"%s\","
           "\"uploaded_asset\":\"%s\",\"bound_texture\":%d,\"dex_instructions\":%llu,\"log_calls\":%d}\n",
           rc, result.tag == DX_VAL_INT ? result.i : -1, g_opened_asset, g_uploaded_asset,
           g_bound_texture, (unsigned long long)vm->insn_total, g_log_calls);
    return rc == DX_OK && g_uploaded_asset[0] ? 0 : 8;
}
