#include "dx_vm.h"
#include "dx_dex.h"
#include "dx_memory.h"
#include "game_dex_runner.h"
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
    DxClass *native_activity = reg_class(vm, "Landroid/app/NativeActivity;", context);
    add_method(native_activity, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(native_activity, "onCreate", "VL", DX_ACC_PUBLIC, noop, 0);
    add_method(context, "getAssets", "L", DX_ACC_PUBLIC, context_get_assets, 0);

    DxClass *asset_manager = reg_class(vm, "Landroid/content/res/AssetManager;", obj);
    add_method(asset_manager, "open", "LL", DX_ACC_PUBLIC, asset_open, 0);
    DxClass *input = reg_class(vm, "Ljava/io/InputStream;", obj);
    one_field(input, "_assetPath", "Ljava/lang/String;");
    add_method(input, "close", "V", DX_ACC_PUBLIC, noop, 0);

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
    DxMethod *load_image;
};

agr_dex_game *agr_dex_game_create(const char *dex_path) {
    agr_dex_game *game = calloc(1,sizeof(*game));
    if (!game) return NULL;
    uint32_t size=0; DxClass *cls=NULL;
    if (!read_file(dex_path,&game->bytes,&size) ||
        dx_dex_parse(game->bytes,size,&game->dex)!=DX_OK ||
        !(game->vm=dx_vm_create(NULL)) ||
        dx_vm_load_dex(game->vm,game->dex)!=DX_OK ||
        dx_register_java_lang(game->vm)!=DX_OK ||
        register_game_framework(game->vm)!=DX_OK ||
        dx_vm_load_class(game->vm,"Lcom/onetwofivegames/kungfoobarracuda/KungFooBarracudaNativeActivity;",&cls)!=DX_OK || !cls)
        goto fail;
    game->activity=dx_vm_alloc_object(game->vm,cls);
    if (!game->activity) goto fail;
    g_activity=game->activity;
    DxMethod *init=dx_vm_find_method(cls,"<init>","V");
    DxValue init_args[1]={DX_OBJ_VALUE(game->activity)};
    if (!init || dx_vm_execute_method(game->vm,init,init_args,1,NULL)!=DX_OK) goto fail;
    DxMethod *on_create=dx_vm_find_method(cls,"onCreate","VL");
    DxValue create_args[2]={DX_OBJ_VALUE(game->activity),DX_NULL_VALUE};
    if (!on_create || dx_vm_execute_method(game->vm,on_create,create_args,2,NULL)!=DX_OK) goto fail;
    game->load_image=dx_vm_find_method(cls,"loadImage","IL");
    if (!game->load_image) goto fail;
    return game;
fail:
    agr_dex_game_destroy(game); return NULL;
}

void agr_dex_game_destroy(agr_dex_game *game) {
    if (!game) return;
    if (g_activity==game->activity) g_activity=NULL;
    if (game->vm) dx_vm_destroy(game->vm);
    if (game->dex) dx_dex_free(game->dex);
    free(game->bytes); free(game);
}

int agr_dex_game_load_image(agr_dex_game *game, const char *path, int32_t *texture) {
    if (!game || !path) return -1;
    DxObject *name=dx_vm_create_string(game->vm,path);
    if (!name) return -1;
    DxValue args[2]={DX_OBJ_VALUE(game->activity),DX_OBJ_VALUE(name)};
    DxValue result=DX_INT_VALUE(0);
    DxResult rc=dx_vm_execute_method(game->vm,game->load_image,args,2,&result);
    if (rc!=DX_OK || result.tag!=DX_VAL_INT) return -1;
    if (texture) *texture=result.i;
    return 0;
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
