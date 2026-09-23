#include "dx_vm.h"
#include "dx_dex.h"
#include "dx_memory.h"
#include "dx_apk.h"
#include "dx_manifest.h"
#include "dx_resources.h"
#include "game_dex_runner.h"
#include "AndroidMini/framework_viewroot.h"
#include "agr_bitmap.h"
#include "agr_forensic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <pthread.h>
#include <GLES2/gl2.h>

extern void agr_forensic_publish(const agr_forensic_sample *) __attribute__((weak));
extern void agr_forensic_publish_passive(const agr_forensic_sample *) __attribute__((weak));

static void forensic_publish(const agr_forensic_sample *sample) {
    if (agr_forensic_publish) agr_forensic_publish(sample);
}

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
static DxResult activity_set_content_view(DxVM *vm, DxFrame *frame,
                                          DxValue *args, uint32_t count);
static DxResult activity_set_content_layout(DxVM *vm, DxFrame *frame,
                                            DxValue *args, uint32_t count);
static DxResult activity_find_view_by_id(DxVM *vm, DxFrame *frame,
                                         DxValue *args, uint32_t count);
static DxResult window_set_content_view(DxVM *vm, DxFrame *frame,
                                        DxValue *args, uint32_t count);
static DxResult window_set_content_layout(DxVM *vm, DxFrame *frame,
                                          DxValue *args, uint32_t count);
static DxResult surface_view_init(DxVM *vm, DxFrame *frame,
                                  DxValue *args, uint32_t count);
static DxResult surface_view_get_holder(DxVM *vm, DxFrame *frame,
                                        DxValue *args, uint32_t count);
static DxResult surface_holder_add_callback(DxVM *vm, DxFrame *frame,
                                            DxValue *args, uint32_t count);
static DxResult surface_holder_remove_callback(DxVM *vm, DxFrame *frame,
                                               DxValue *args, uint32_t count);
static DxResult surface_holder_get_surface(DxVM *vm, DxFrame *frame,
                                           DxValue *args, uint32_t count);
static DxResult surface_holder_get_surface_frame(DxVM *vm, DxFrame *frame,
                                                 DxValue *args, uint32_t count);
static DxResult surface_holder_lock_canvas(DxVM *vm, DxFrame *frame,
                                           DxValue *args, uint32_t count);
static DxResult surface_holder_unlock_canvas(DxVM *vm, DxFrame *frame,
                                             DxValue *args, uint32_t count);
static DxResult view_request_layout(DxVM *vm, DxFrame *frame,
                                    DxValue *args, uint32_t count);
static DxResult window_request_feature(DxVM *vm, DxFrame *frame,
                                       DxValue *args, uint32_t count);
static DxResult activity_request_window_feature(DxVM *vm, DxFrame *frame,
                                                DxValue *args, uint32_t count);
static DxResult activity_get_intent(DxVM *vm, DxFrame *frame,
                                    DxValue *args, uint32_t count);

/* API19 Window.DEFAULT_FEATURES. PhoneWindow.requestFeature is the body. */
#define AGR_FEATURE_OPTIONS_PANEL 0
#define AGR_FEATURE_NO_TITLE 1
#define AGR_FEATURE_CONTEXT_MENU 6
#define AGR_FEATURE_CUSTOM_TITLE 7
#define AGR_FEATURE_ACTION_BAR 8
#define AGR_FEATURE_ACTION_MODE_OVERLAY 10
#define AGR_DEFAULT_WINDOW_FEATURES \
    ((1 << AGR_FEATURE_OPTIONS_PANEL) | (1 << AGR_FEATURE_CONTEXT_MENU))

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

static DxResult bitmap_decode_byte_array(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);

/* Intrinsic pixel size of a PNG, GIF, or JPEG. A nine-patch PNG reports the
   content size, which is the IHDR size minus the one-pixel border. */
static int encoded_image_size(const uint8_t *data, uint32_t size, int *width, int *height) {
    if (!data || !width || !height) return 0;
    *width = 0;
    *height = 0;
    if (size >= 24 && data[0] == 0x89 && data[1] == 0x50 && data[2] == 0x4E &&
        data[3] == 0x47 && memcmp(data + 12, "IHDR", 4) == 0) {
        uint32_t image_width = ((uint32_t)data[16] << 24) | ((uint32_t)data[17] << 16) |
                               ((uint32_t)data[18] << 8) | data[19];
        uint32_t image_height = ((uint32_t)data[20] << 24) | ((uint32_t)data[21] << 16) |
                                ((uint32_t)data[22] << 8) | data[23];
        int nine_patch = 0;
        for (uint32_t i = 8; i + 12 < size; ) {
            uint32_t chunk = ((uint32_t)data[i] << 24) | ((uint32_t)data[i + 1] << 16) |
                             ((uint32_t)data[i + 2] << 8) | data[i + 3];
            if (i + 12u + chunk < i || i + 12u + chunk > size) break;
            if (memcmp(data + i + 4, "npTc", 4) == 0) nine_patch = 1;
            if (memcmp(data + i + 4, "IEND", 4) == 0) break;
            i += 12u + chunk;
        }
        if (nine_patch && image_width > 2 && image_height > 2) {
            image_width -= 2;
            image_height -= 2;
        }
        if (!image_width || !image_height || image_width > 32768 || image_height > 32768)
            return 0;
        *width = (int)image_width;
        *height = (int)image_height;
        return 1;
    }
    if (size >= 10 && data[0] == 'G' && data[1] == 'I' && data[2] == 'F' && data[3] == '8') {
        uint32_t image_width = (uint32_t)data[6] | ((uint32_t)data[7] << 8);
        uint32_t image_height = (uint32_t)data[8] | ((uint32_t)data[9] << 8);
        if (!image_width || !image_height || image_width > 32768 || image_height > 32768)
            return 0;
        *width = (int)image_width;
        *height = (int)image_height;
        return 1;
    }
    if (size >= 4 && data[0] == 0xFF && data[1] == 0xD8) {
        uint32_t i = 2;
        while (i + 8 < size) {
            if (data[i] != 0xFF) return 0;
            while (i < size && data[i] == 0xFF) i++;
            if (i >= size) return 0;
            uint8_t marker = data[i++];
            if (marker == 0xD9 || marker == 0xDA) return 0;
            if (marker == 0x01 || (marker >= 0xD0 && marker <= 0xD7)) continue;
            if (i + 1 >= size) return 0;
            uint32_t segment = ((uint32_t)data[i] << 8) | data[i + 1];
            if (segment < 2 || i + segment > size) return 0;
            if (marker >= 0xC0 && marker <= 0xCF && marker != 0xC4 &&
                marker != 0xC8 && marker != 0xCC) {
                if (segment < 7) return 0;
                uint32_t image_height = ((uint32_t)data[i + 3] << 8) | data[i + 4];
                uint32_t image_width = ((uint32_t)data[i + 5] << 8) | data[i + 6];
                if (!image_width || !image_height || image_width > 32768 || image_height > 32768)
                    return 0;
                *width = (int)image_width;
                *height = (int)image_height;
                return 1;
            }
            i += segment;
        }
    }
    return 0;
}

static int options_value_int(DxValue *args, uint32_t count, const char *name, int fallback) {
    DxValue value = DX_NULL_VALUE;
    if (count < 3 || args[2].tag != DX_VAL_OBJ || !args[2].obj ||
        dx_vm_get_field(args[2].obj, name, &value) != DX_OK || value.tag != DX_VAL_INT)
        return fallback;
    return value.i;
}

static int options_value_set(DxValue *args, uint32_t count, const char *name) {
    DxValue value = DX_NULL_VALUE;
    if (count < 3 || args[2].tag != DX_VAL_OBJ || !args[2].obj) return 0;
    if (dx_vm_get_field(args[2].obj, name, &value) != DX_OK) return 0;
    if (value.tag == DX_VAL_INT) return value.i != 0;
    return value.tag == DX_VAL_OBJ && value.obj != NULL;
}

static void options_witness_text(DxValue *args, uint32_t count, char *out, size_t capacity) {
    DxValue value = DX_NULL_VALUE;
    uint64_t options_identity = 0;
    int has_in_bitmap = 0;
    if (!out || capacity == 0) return;
    out[0] = '\0';
    if (count < 3 || args[2].tag != DX_VAL_OBJ || !args[2].obj) {
        snprintf(out, capacity, "options=null");
        return;
    }
    options_identity = args[2].obj->diagnostic_identity;
    if (dx_vm_get_field(args[2].obj, "inBitmap", &value) == DX_OK)
        has_in_bitmap = value.tag == DX_VAL_OBJ && value.obj != NULL;
    snprintf(out, capacity,
             "options=id%llu,bounds=%d,sample=%d,scaled=%d,density=%d,target=%d,screen=%d,inBitmap=%d",
             (unsigned long long)options_identity,
             options_value_int(args, count, "inJustDecodeBounds", 0),
             options_value_int(args, count, "inSampleSize", 1),
             options_value_int(args, count, "inScaled", 1),
             options_value_int(args, count, "inDensity", 0),
             options_value_int(args, count, "inTargetDensity", 0),
             options_value_int(args, count, "inScreenDensity", 0), has_in_bitmap);
}

static void publish_bitmap_witness(DxVM *vm, uint32_t phase, const char *class_name,
                                   const char *method, int32_t resource_id,
                                   DxObject *object, DxObject *related,
                                   const agr_bitmap *backing, int status,
                                   uint32_t flags, int width, int height,
                                   int value0, int value1, const char *path) {
    agr_forensic_sample sample;
    if (!agr_forensic_publish_passive) return;
    memset(&sample, 0, sizeof(sample));
    sample.phase = phase;
    sample.timing_sensitive = 1;
    sample.resource_id = resource_id;
    sample.object_identity = object ? object->diagnostic_identity : 0;
    sample.related_identity = related ? related->diagnostic_identity : 0;
    sample.backing_owner_identity = backing
        ? (object ? object->diagnostic_identity : (related ? related->diagnostic_identity : 0)) : 0;
    sample.backing_identity = backing ? (uint64_t)(uintptr_t)agr_bitmap_pixels(backing) : 0;
    sample.width = width;
    sample.height = height;
    sample.value0 = value0;
    sample.value1 = value1;
    sample.witness_flags = flags;
    sample.witness_status = (uint32_t)status;
    if (vm && dx_vm_current_exec(vm)) {
        DxExecutionContext *exec = dx_vm_current_exec(vm);
        sample.has_exec = 1;
        sample.exec_id = exec->id;
        sample.thread_state = 2;
        sample.host_thread = exec->has_host_thread
            ? (uint64_t)(uintptr_t)exec->host_thread : (uint64_t)pthread_self();
        if (exec->current_frame) {
            sample.guest_pc = exec->current_frame->pc;
            sample.has_guest_pc = 1;
        }
    } else {
        sample.host_thread = (uint64_t)pthread_self();
    }
    snprintf(sample.class_name, sizeof(sample.class_name), "%s",
             class_name ? class_name : "Landroid/graphics/BitmapFactory;");
    snprintf(sample.method_name, sizeof(sample.method_name), "%s", method ? method : "Bitmap");
    snprintf(sample.detail, sizeof(sample.detail), "%s", path ? path : "");
    agr_forensic_publish_passive(&sample);
}

static const DxResourceEntry *resource_file_entry(const DxResources *resources,
                                                  const DxApkFile *apk, uint32_t id) {
    if (!resources) return NULL;
    for (int hop = 0; hop < 4; hop++) {
        const DxResourceEntry *file = NULL;
        const DxResourceEntry *reference = NULL;
        for (uint32_t i = 0; i < resources->entry_count; i++) {
            const DxResourceEntry *entry = &resources->entries[i];
            if (entry->id != id) continue;
            if (entry->value_type == DX_RES_TYPE_STRING && entry->str_val && entry->str_val[0]) {
                const DxZipEntry *zip = NULL;
                if (apk && dx_apk_find_entry(apk, entry->str_val, &zip) == DX_OK) return entry;
                if (!file) file = entry;
            } else if (entry->value_type == DX_RES_TYPE_REF && entry->ref_id && !reference) {
                reference = entry;
            }
        }
        if (file || !reference) return file;
        id = reference->ref_id;
    }
    return NULL;
}

static DxResult bitmap_decode_failed(DxVM *vm, DxFrame *frame, int reuse_bitmap) {
    if (reuse_bitmap) {
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(vm, "Ljava/lang/IllegalArgumentException;",
            "Problem decoding into existing bitmap");
        return DX_ERR_EXCEPTION;
    }
    frame->result = DX_NULL_VALUE;
    frame->has_result = true;
    return DX_OK;
}

static DxResult bitmap_decode_resource(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);
static DxResult bitmap_decode_byte_array(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);
static DxResult bitmap_recycle(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);
static DxResult bitmap_create_scaled(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);
static DxResult canvas_draw_bitmap(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);
static DxResult canvas_save(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);
static DxResult canvas_clip_rect(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);
static DxResult canvas_restore(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count);
static void publish_region_op_replace(DxVM *vm, DxClass *obj);
static struct agr_content_surface *content_slot_for_canvas(agr_dex_game *game, DxObject *canvas);

static DxResult bitmap_get_dimension(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    const char *field = "_width";
    const char *method = "getWidth";
    DxValue value = DX_NULL_VALUE;
    DxObject *receiver = count && args[0].tag == DX_VAL_OBJ ? args[0].obj : NULL;
    if (frame->method && frame->method->name && !strcmp(frame->method->name, "getHeight")) {
        field = "_height";
        method = "getHeight";
    }
    if (!receiver) {
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_REFERENCE_WITNESS,
                               "Landroid/graphics/Bitmap;", method, -1, NULL, NULL,
                               NULL, DX_ERR_NULL_PTR, 0, 0, 0, 0, 0, "receiver=null");
        return DX_ERR_NULL_PTR;
    }
    if (dx_vm_get_field(receiver, field, &value) != DX_OK || value.tag != DX_VAL_INT) {
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_REFERENCE_WITNESS,
                               "Landroid/graphics/Bitmap;", method, -1, receiver, NULL,
                               NULL, DX_ERR_INVALID_FORMAT, 1u, 0, 0, 0, 0,
                               "field=missing_or_nonint");
        return DX_ERR_INVALID_FORMAT;
    }
    publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_REFERENCE_WITNESS,
                           "Landroid/graphics/Bitmap;", method, -1, receiver, NULL,
                           NULL, DX_OK, 1u, value.i, 0, 0, 0, field);
    frame->result = value;
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
    add_method(activity, "getIntent", "L", DX_ACC_PUBLIC, activity_get_intent, 0);
    add_method(activity, "requestWindowFeature", "ZI", DX_ACC_PUBLIC,
               activity_request_window_feature, 0);
    {
        DxClass *runtime_exception = dx_vm_find_class(vm, "Ljava/lang/RuntimeException;");
        DxClass *android_runtime = reg_class(vm, "Landroid/util/AndroidRuntimeException;",
                                             runtime_exception);
        own_fields(android_runtime, 0, NULL, NULL);
    }
    add_method(activity, "setContentView", "VL", DX_ACC_PUBLIC, activity_set_content_view, 0);
    add_method(activity, "setContentView", "VLL", DX_ACC_PUBLIC, activity_set_content_view, 0);
    add_method(activity, "setContentView", "VI", DX_ACC_PUBLIC, activity_set_content_layout, 0);
    add_method(activity, "findViewById", "LI", DX_ACC_PUBLIC, activity_find_view_by_id, 0);
    add_method(activity, "onContentChanged", "V", DX_ACC_PUBLIC, noop, 0);
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
                                 "_left", "_top", "_right", "_bottom", "_content",
                                 "_layoutWidth", "_layoutHeight", "_id", "_child", "_next" };
    const char *view_types[] = { "I", "Landroid/view/WindowManager$LayoutParams;",
                                 "Landroid/view/ViewRootImpl;", "Landroid/view/View$AttachInfo;",
                                 "Z", "I", "I", "I", "I", "I", "I", "Landroid/view/View;",
                                 "I", "I", "I", "Landroid/view/View;", "Landroid/view/View;" };
    own_fields(view, 17, view_names, view_types);
    add_method(view, "<init>", "VL", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(view, "<init>", "VLL", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    DxClass *view_group = reg_class(vm, "Landroid/view/ViewGroup;", view);
    own_fields(view_group, 0, NULL, NULL);
    add_method(view_group, "<init>", "VL", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(view_group, "<init>", "VLL", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    DxClass *frame_layout = reg_class(vm, "Landroid/widget/FrameLayout;", view_group);
    own_fields(frame_layout, 0, NULL, NULL);
    add_method(frame_layout, "<init>", "VL", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(frame_layout, "<init>", "VLL", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    DxClass *surface_view = reg_class(vm, "Landroid/view/SurfaceView;", view);
    const char *surface_view_names[] = { "_holder" };
    const char *surface_view_types[] = { "Landroid/view/SurfaceHolder;" };
    own_fields(surface_view, 1, surface_view_names, surface_view_types);
    add_method(surface_view, "<init>", "VL", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, surface_view_init, 1);
    add_method(surface_view, "<init>", "VLL", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, surface_view_init, 1);
    add_method(surface_view, "getHolder", "L", DX_ACC_PUBLIC, surface_view_get_holder, 0);
    DxClass *holder = reg_class(vm, "Landroid/view/SurfaceHolder;", obj);
    const char *holder_names[] = { "_surface" };
    const char *holder_types[] = { "Landroid/view/Surface;" };
    own_fields(holder, 1, holder_names, holder_types);
    add_method(holder, "addCallback", "VL", DX_ACC_PUBLIC, surface_holder_add_callback, 0);
    add_method(holder, "removeCallback", "VL", DX_ACC_PUBLIC, surface_holder_remove_callback, 0);
    add_method(holder, "getSurface", "L", DX_ACC_PUBLIC, surface_holder_get_surface, 0);
    add_method(holder, "getSurfaceFrame", "L", DX_ACC_PUBLIC, surface_holder_get_surface_frame, 0);
    add_method(holder, "lockCanvas", "L", DX_ACC_PUBLIC, surface_holder_lock_canvas, 0);
    add_method(holder, "lockCanvas", "LL", DX_ACC_PUBLIC, surface_holder_lock_canvas, 0);
    add_method(holder, "unlockCanvasAndPost", "VL", DX_ACC_PUBLIC, surface_holder_unlock_canvas, 0);
    DxClass *canvas = reg_class(vm, "Landroid/graphics/Canvas;", obj);
    const char *canvas_names[] = { "_width", "_height", "_rowBytes", "_generation", "_format", "_locked" };
    const char *canvas_types[] = { "I", "I", "I", "I", "I", "I" };
    own_fields(canvas, 6, canvas_names, canvas_types);
    add_method(canvas, "drawBitmap", "VLFFL", DX_ACC_PUBLIC, canvas_draw_bitmap, 0);
    add_method(canvas, "save", "II", DX_ACC_PUBLIC, canvas_save, 0);
    add_method(canvas, "clipRect", "ZFFFFL", DX_ACC_PUBLIC, canvas_clip_rect, 0);
    add_method(canvas, "restore", "V", DX_ACC_PUBLIC, canvas_restore, 0);
    publish_region_op_replace(vm, obj);
    DxClass *rect = reg_class(vm, "Landroid/graphics/Rect;", obj);
    const char *rect_names[] = { "left", "top", "right", "bottom" };
    const char *rect_types[] = { "I", "I", "I", "I" };
    own_fields(rect, 4, rect_names, rect_types);
    reg_class(vm, "Landroid/util/AttributeSet;", obj);
    add_method(view, "setVisibility", "VI", DX_ACC_PUBLIC, view_set_visibility, 0);
    add_method(view, "requestLayout", "V", DX_ACC_PUBLIC, view_request_layout, 0);
    DxClass *layout_params = reg_class(vm, "Landroid/view/WindowManager$LayoutParams;", obj);
    const char *layout_names[] = { "_type", "_softInputMode", "_width", "_height" };
    const char *layout_types[] = { "I", "I", "I", "I" };
    own_fields(layout_params, 4, layout_names, layout_types);
    DxClass *window = reg_class(vm, "Landroid/view/Window;", obj);
    const char *window_names[] = { "_decor", "_attributes", "_features", "_localFeatures",
                                   "_contentParent" };
    const char *window_types[] = { "Landroid/view/View;", "Landroid/view/WindowManager$LayoutParams;",
                                   "I", "I", "Landroid/view/View;" };
    own_fields(window, 5, window_names, window_types);
    add_method(window, "getDecorView", "L", DX_ACC_PUBLIC, window_get_decor_view, 0);
    add_method(window, "getAttributes", "L", DX_ACC_PUBLIC, window_get_attributes, 0);
    add_method(window, "requestFeature", "ZI", DX_ACC_PUBLIC, window_request_feature, 0);
    add_method(window, "setContentView", "VL", DX_ACC_PUBLIC, window_set_content_view, 0);
    add_method(window, "setContentView", "VLL", DX_ACC_PUBLIC, window_set_content_view, 0);
    add_method(window, "setContentView", "VI", DX_ACC_PUBLIC, window_set_content_layout, 0);
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
    const char *option_names[] = { "inScaled", "inJustDecodeBounds", "inBitmap", "outWidth", "outHeight" };
    const char *option_types[] = { "Z", "Z", "Landroid/graphics/Bitmap;", "I", "I" };
    own_fields(options, 5, option_names, option_types);
    add_method(options, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    DxClass *bitmap = reg_class(vm, "Landroid/graphics/Bitmap;", obj);
    const char *bitmap_names[] = { "_assetPath", "_width", "_height", "_recycled" };
    const char *bitmap_types[] = { "Ljava/lang/String;", "I", "I", "Z" };
    own_fields(bitmap, 4, bitmap_names, bitmap_types);
    add_method(bitmap, "recycle", "V", DX_ACC_PUBLIC, bitmap_recycle, 0);
    add_method(bitmap, "getWidth", "I", DX_ACC_PUBLIC, bitmap_get_dimension, 0);
    add_method(bitmap, "getHeight", "I", DX_ACC_PUBLIC, bitmap_get_dimension, 0);
    add_method(bitmap, "createScaledBitmap", "LLIIZ", DX_ACC_PUBLIC | DX_ACC_STATIC,
               bitmap_create_scaled, 1);
    DxClass *factory = reg_class(vm, "Landroid/graphics/BitmapFactory;", obj);
    add_method(factory, "decodeStream", "LLLL", DX_ACC_PUBLIC | DX_ACC_STATIC, bitmap_decode, 1);
    add_method(factory, "decodeResource", "LLIL", DX_ACC_PUBLIC | DX_ACC_STATIC, bitmap_decode_resource, 1);
    add_method(factory, "decodeByteArray", "L[BII", DX_ACC_PUBLIC | DX_ACC_STATIC, bitmap_decode_byte_array, 1);

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

/* API19 SurfaceView child surface. Distinct from the ViewRoot window Surface.
   PixelFormat.RGB_565 is 4, the SurfaceView default reported to surfaceChanged.
   The in-process backing is 4 bytes per pixel (host RGBA8888). Guest code in
   this contract does not read Canvas row bytes; draws address the backing
   through the Canvas object, not through the format integer. */
enum { AGR_CONTENT_SURFACE_CAP = 4, AGR_SURFACE_CALLBACK_CAP = 8,
       AGR_PIXEL_FORMAT_RGB_565 = 4, AGR_CONTENT_BYTES_PER_PIXEL = 4,
       AGR_GUEST_BITMAP_CAP = 128 };

/* API19 Canvas.save flags. CLIP_SAVE_FLAG copies the clip. Other bits are
   recorded and do not invent a Matrix or a layer. */
#define AGR_CANVAS_MATRIX_SAVE_FLAG 0x01
#define AGR_CANVAS_CLIP_SAVE_FLAG 0x02
#define AGR_CANVAS_SAVE_CAP 16
#define AGR_REGION_OP_REPLACE 5

struct agr_canvas_save {
    int32_t flags;
    int owns_clip;
    int clip_left, clip_top, clip_right, clip_bottom;
};

struct agr_content_surface {
    DxObject *view;
    DxObject *holder;
    DxObject *surface;
    DxObject *canvas;
    DxObject *callbacks[AGR_SURFACE_CALLBACK_CAP];
    uint32_t callback_count;
    int created;
    int valid;
    int width;
    int height;
    int format;
    int row_bytes;
    uint32_t generation;
    uint32_t created_count;
    uint32_t changed_count;
    void *pixels;
    /* Host exclusion for the content buffer. Not the Java monitor, and not
       the VM shared lock. Held only around the locked-flag update. */
    pthread_mutex_t mu;
    pthread_cond_t cv;
    int mutex_ready;
    int canvas_locked;
    uint32_t lock_owner_exec;
    uint32_t locked_generation;
    int clip_left, clip_top, clip_right, clip_bottom;
    /* API19 Canvas save stack for this lock. Index 0 is the first save above
       the base clip installed by lockCanvas. save_count is getSaveCount and
       starts at 1. The next lockCanvas replaces this stack. */
    struct agr_canvas_save save_stack[AGR_CANVAS_SAVE_CAP];
    int save_count;
    uint32_t lock_count;
    uint32_t unlock_count;
    uint32_t post_count;
    uint32_t last_post_generation;
    uint64_t hash_before_lock;
    int hash_before_set;
    uint64_t hash_after_post;
    uint32_t pixel_change_count;
    uint32_t draw_bitmap_count;
    uint64_t lock_owner_host;
    int64_t last_lock_fail_ms;
};

static agr_forensic_sample forensic_fill(uint32_t phase, int critical, DxExecutionContext *exec,
                                         const struct agr_content_surface *slot,
                                         uint32_t before, uint32_t after, int has_counters) {
    agr_forensic_sample sample;
    memset(&sample, 0, sizeof(sample));
    sample.phase = phase;
    sample.critical = critical;
    sample.host_thread = (uint64_t)pthread_self();
    if (exec) {
        sample.has_exec = 1;
        sample.exec_id = exec->id;
        if (exec->has_host_thread)
            sample.host_thread = (uint64_t)(uintptr_t)exec->host_thread;
        sample.thread_state = 2;
    }
    if (slot) {
        sample.canvas_locked = slot->canvas_locked;
        sample.lock_owner_exec = slot->lock_owner_exec;
        sample.lock_count = slot->lock_count;
        sample.unlock_count = slot->unlock_count;
        sample.post_count = slot->post_count;
        sample.draw_bitmap_count = slot->draw_bitmap_count;
        sample.pixel_change_count = slot->pixel_change_count;
        sample.surface_generation = slot->generation;
        sample.surface_identity = (uint64_t)(uintptr_t)slot->surface;
        sample.surface_valid = slot->valid;
        sample.created_count = slot->created_count;
        sample.changed_count = slot->changed_count;
    }
    sample.counter_before = before;
    sample.counter_after = after;
    sample.has_counters = has_counters;
    return sample;
}

static void forensic_surface(uint32_t phase, int critical, DxExecutionContext *exec,
                             const struct agr_content_surface *slot,
                             uint32_t before, uint32_t after, int has_counters) {
    agr_forensic_sample sample = forensic_fill(phase, critical, exec, slot, before, after, has_counters);
    forensic_publish(&sample);
}

struct agr_guest_bitmap {
    DxObject *guest;
    agr_bitmap *host;
    int recycled;
};

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
    DxObject *content_view;
    int32_t content_width;
    int32_t content_height;
    int content_child_count;
    int32_t content_first_child_id;
    struct agr_content_surface content_surfaces[AGR_CONTENT_SURFACE_CAP];
    uint32_t content_surface_count;
    struct agr_guest_bitmap bitmaps[AGR_GUEST_BITMAP_CAP];
    uint32_t bitmap_count;
    int first_bitmap_noted;
    uint64_t first_bitmap_guest;
    uint64_t first_bitmap_host;
    int first_bitmap_width;
    int first_bitmap_height;
    char first_bitmap_path[160];
    char first_bitmap_encoding[16];
    void *(*content_surface_alloc)(void *, size_t);
    void (*content_surface_free)(void *, void *);
    void *content_surface_alloc_user;
    char content_surface_exception[160];
    int draw_witness_locked_once;
    int exec_snapshot_post_once;
    struct {
        uint32_t id;
        uint8_t *xml;
        uint32_t size;
    } *layouts;
    uint32_t layout_count;
    const DxApkFile *resource_apk;
    DxResources *resources;
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
    uint32_t host_display_width;
    uint32_t host_display_height;
    int choreographer_in_frame;
    uint32_t framework_event_count;
    char framework_events[AGR_DEX_FRAMEWORK_TRACE_CAPACITY][96];
    uint32_t feature_event_count;
    char feature_events[AGR_FEATURE_EVENT_CAP][96];
    uint32_t intent_event_count;
    char intent_events[AGR_INTENT_EVENT_CAP][160];
    agr_canvas_trace canvas_trace[AGR_CANVAS_TRACE_CAP];
    uint32_t canvas_trace_count;
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

static void note_feature_event(agr_dex_game *game, const char *text) {
    if (!game || !text || game->feature_event_count >= AGR_FEATURE_EVENT_CAP) return;
    snprintf(game->feature_events[game->feature_event_count],
             sizeof(game->feature_events[0]), "%s", text);
    game->feature_event_count++;
}

static void note_intent_event(agr_dex_game *game, const char *text) {
    if (!game || !text || game->intent_event_count >= AGR_INTENT_EVENT_CAP) return;
    snprintf(game->intent_events[game->intent_event_count],
             sizeof(game->intent_events[0]), "%s", text);
    game->intent_event_count++;
}

/* API19 Activity.getIntent returns the Activity's current mIntent.
   AGR stores that reference in _intent. The getter does not allocate. */
static DxResult activity_get_intent(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = vm ? (agr_dex_game *)vm->framework_user : NULL;
    DxValue value = DX_NULL_VALUE;
    DxObject *activity;
    DxObject *intent = NULL;
    uint32_t pc = 0;
    uint32_t method_idx = 0;
    unsigned opcode = 0;
    char text[160];
    if (!frame || count < 1 || !args || args[0].tag != DX_VAL_OBJ || !args[0].obj)
        return DX_ERR_NULL_PTR;
    activity = args[0].obj;
    if (dx_vm_get_field(activity, "_intent", &value) == DX_OK && value.tag == DX_VAL_OBJ)
        intent = value.obj;
    frame->result = intent ? DX_OBJ_VALUE(intent) : DX_NULL_VALUE;
    frame->has_result = true;
    if (vm && vm->invoke_site_valid) {
        pc = vm->invoke_site_pc;
        opcode = vm->invoke_site_opcode;
        method_idx = vm->invoke_site_method_idx;
    }
    /* Witness only. The returned Intent is still the _intent field. */
    DxExecutionContext *exec = vm ? dx_vm_current_exec(vm) : NULL;
    uint32_t exec_id = exec ? exec->id : 0;
    snprintf(text, sizeof(text),
             "get a=%llu field=%llu ret=%llu launch=%llu e=%u p=%u o=%u m=%u",
             (unsigned long long)(uintptr_t)activity,
             (unsigned long long)(uintptr_t)intent,
             (unsigned long long)(uintptr_t)(frame->result.obj),
             (unsigned long long)(uintptr_t)(game ? game->intent : NULL),
             exec_id, pc, opcode, method_idx);
    note_intent_event(game, text);
    if (frame->caller && frame->caller->method && frame->caller->method->name &&
        frame->caller->method->declaring_class &&
        frame->caller->method->declaring_class->descriptor) {
        snprintf(text, sizeof(text), "who %s.%s",
                 frame->caller->method->declaring_class->descriptor,
                 frame->caller->method->name);
        note_intent_event(game, text);
    }
    return DX_OK;
}

/* Java int shifts mask the count to 5 bits. */
static int32_t feature_bit(int32_t feature_id) {
    return (int32_t)(1u << (uint32_t)(feature_id & 31));
}

static int32_t window_feature_bits(DxObject *window) {
    DxValue value = DX_NULL_VALUE;
    if (!window || dx_vm_get_field(window, "_features", &value) != DX_OK ||
        value.tag != DX_VAL_INT)
        return 0;
    return value.i;
}

static int window_has_content(DxObject *window) {
    DxValue value = DX_NULL_VALUE;
    return window && dx_vm_get_field(window, "_contentParent", &value) == DX_OK &&
           value.tag == DX_VAL_OBJ && value.obj != NULL;
}

static void store_window_features(DxObject *window, int32_t bits) {
    dx_vm_set_field(window, "_features", DX_INT_VALUE(bits));
    dx_vm_set_field(window, "_localFeatures", DX_INT_VALUE(bits));
}

static DxResult feature_throw(DxVM *vm, const char *message) {
    dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
        vm, "Landroid/util/AndroidRuntimeException;", message);
    return DX_ERR_EXCEPTION;
}

/* API19 PhoneWindow.requestFeature. mContainer is null on this window, so
   local features stay equal to features. No title view is generated. */
static DxResult window_request_feature(DxVM *vm, DxFrame *frame,
                                       DxValue *args, uint32_t count) {
    DxObject *window;
    int32_t feature_id;
    int32_t features;
    int32_t flag;
    if (!frame || !vm || count < 2 || args[0].tag != DX_VAL_OBJ || !args[0].obj) {
        if (vm) {
            dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
                vm, "Ljava/lang/NullPointerException;", "window");
            return DX_ERR_EXCEPTION;
        }
        return DX_ERR_NULL_PTR;
    }
    if (args[1].tag != DX_VAL_INT) return DX_ERR_INVALID_FORMAT;
    window = args[0].obj;
    feature_id = args[1].i;
    if (window_has_content(window))
        return feature_throw(vm, "requestFeature() must be called before adding content");
    features = window_feature_bits(window);
    if (features != AGR_DEFAULT_WINDOW_FEATURES && feature_id == AGR_FEATURE_CUSTOM_TITLE)
        return feature_throw(vm, "You cannot combine custom titles with other title features");
    if ((features & feature_bit(AGR_FEATURE_CUSTOM_TITLE)) != 0 &&
        feature_id != AGR_FEATURE_CUSTOM_TITLE &&
        feature_id != AGR_FEATURE_ACTION_MODE_OVERLAY)
        return feature_throw(vm, "You cannot combine custom titles with other title features");
    if ((features & feature_bit(AGR_FEATURE_NO_TITLE)) != 0 &&
        feature_id == AGR_FEATURE_ACTION_BAR) {
        frame->result = DX_INT_VALUE(0);
        frame->has_result = true;
        return DX_OK;
    }
    if ((features & feature_bit(AGR_FEATURE_ACTION_BAR)) != 0 &&
        feature_id == AGR_FEATURE_NO_TITLE) {
        features &= ~feature_bit(AGR_FEATURE_ACTION_BAR);
    }
    flag = feature_bit(feature_id);
    features |= flag;
    store_window_features(window, features);
    frame->result = DX_INT_VALUE((features & flag) != 0 ? 1 : 0);
    frame->has_result = true;
    return DX_OK;
}

/* API19 Activity.requestWindowFeature forwards to the Activity's own window. */
static DxResult activity_request_window_feature(DxVM *vm, DxFrame *frame,
                                                DxValue *args, uint32_t count) {
    agr_dex_game *game = vm ? (agr_dex_game *)vm->framework_user : NULL;
    DxValue window_value = DX_NULL_VALUE;
    DxObject *window = NULL;
    DxClass *window_class;
    DxMethod *method;
    DxValue forwarded[2];
    DxValue result = DX_NULL_VALUE;
    DxResult rc;
    int32_t before;
    int32_t after;
    int32_t feature_id = 0;
    int content_before;
    int exc;
    int ret;
    uint32_t pc = 0;
    uint32_t method_idx = 0;
    unsigned opcode = 0;
    char text[96];
    char caller[80];
    if (!frame || !vm || count < 2 || args[0].tag != DX_VAL_OBJ || !args[0].obj) {
        if (vm) {
            dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
                vm, "Ljava/lang/NullPointerException;", "activity");
            return DX_ERR_EXCEPTION;
        }
        return DX_ERR_NULL_PTR;
    }
    if (args[1].tag != DX_VAL_INT) return DX_ERR_INVALID_FORMAT;
    feature_id = args[1].i;
    if (dx_vm_get_field(args[0].obj, "_window", &window_value) != DX_OK ||
        window_value.tag != DX_VAL_OBJ || !window_value.obj) {
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/NullPointerException;", "window");
        return DX_ERR_EXCEPTION;
    }
    window = window_value.obj;
    before = window_feature_bits(window);
    content_before = window_has_content(window);
    if (vm->invoke_site_valid) {
        pc = vm->invoke_site_pc;
        opcode = vm->invoke_site_opcode;
        method_idx = vm->invoke_site_method_idx;
    }
    window_class = dx_vm_find_class(vm, "Landroid/view/Window;");
    method = window_class ? dx_vm_find_method(window_class, "requestFeature", "ZI") : NULL;
    if (!method) return DX_ERR_INVALID_FORMAT;
    forwarded[0] = DX_OBJ_VALUE(window);
    forwarded[1] = args[1];
    rc = dx_vm_execute_method(vm, method, forwarded, 2, &result);
    after = window_feature_bits(window);
    exc = rc == DX_ERR_EXCEPTION ? 1 : 0;
    ret = (!exc && result.tag == DX_VAL_INT) ? result.i : -1;
    snprintf(text, sizeof(text),
             "req a=%llu w=%llu id=%d b=%d f=%d r=%d e=%d c=%d p=%u o=%u m=%u",
             (unsigned long long)(uintptr_t)args[0].obj,
             (unsigned long long)(uintptr_t)window,
             feature_id, before, after, ret, exc, content_before,
             pc, (unsigned)opcode, method_idx);
    note_feature_event(game, text);
    caller[0] = 0;
    if (frame->caller && frame->caller->method && frame->caller->method->name &&
        frame->caller->method->declaring_class &&
        frame->caller->method->declaring_class->descriptor) {
        snprintf(caller, sizeof(caller), "%s.%s",
                 frame->caller->method->declaring_class->descriptor,
                 frame->caller->method->name);
        snprintf(text, sizeof(text), "who %s", caller);
        note_feature_event(game, text);
    }
    if (rc == DX_OK && result.tag == DX_VAL_INT) {
        frame->result = result;
        frame->has_result = true;
    }
    return rc;
}

/* PhoneWindow.setContentView(View, LayoutParams) installs one content child
   on the existing decor. It does not replace the ViewRoot decor. A window
   that is not yet added does not schedule; an attached window only posts
   scheduleTraversals. ActionBar is not created. */
static DxResult install_content_view(agr_dex_game *game, DxObject *view,
                                     int32_t width, int32_t height) {
    if (!game || !game->decor || !game->activity || !view || view == game->decor)
        return DX_ERR_INVALID_FORMAT;
    if (game->content_view && game->content_view != view)
        dx_vm_set_field(game->content_view, "_parent", DX_NULL_VALUE);
    if (dx_vm_set_field(game->decor, "_content", DX_OBJ_VALUE(view)) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    dx_vm_set_field(view, "_layoutWidth", DX_INT_VALUE(width));
    dx_vm_set_field(view, "_layoutHeight", DX_INT_VALUE(height));
    dx_vm_set_field(view, "_parent", DX_OBJ_VALUE(game->decor));
    game->content_view = view;
    game->content_width = width;
    game->content_height = height;
    game->content_child_count = 0;
    game->content_first_child_id = 0;
    {
        DxValue child = DX_NULL_VALUE;
        if (dx_vm_get_field(view, "_child", &child) == DX_OK && child.tag == DX_VAL_OBJ)
            for (DxObject *cursor = child.obj; cursor; ) {
                DxValue next = DX_NULL_VALUE;
                DxValue child_id = DX_NULL_VALUE;
                if (game->content_child_count == 0 &&
                    dx_vm_get_field(cursor, "_id", &child_id) == DX_OK &&
                    child_id.tag == DX_VAL_INT)
                    game->content_first_child_id = child_id.i;
                game->content_child_count++;
                if (dx_vm_get_field(cursor, "_next", &next) != DX_OK || next.tag != DX_VAL_OBJ)
                    break;
                cursor = next.obj;
            }
    }
    if (game->window) {
        DxValue activity_window = DX_NULL_VALUE;
        char text[96];
        dx_vm_set_field(game->window, "_contentParent", DX_OBJ_VALUE(view));
        if (game->activity)
            dx_vm_get_field(game->activity, "_window", &activity_window);
        snprintf(text, sizeof(text), "content aw=%llu w=%llu f=%d p=%llu",
                 (unsigned long long)(uintptr_t)(activity_window.tag == DX_VAL_OBJ
                                                 ? activity_window.obj : NULL),
                 (unsigned long long)(uintptr_t)game->window,
                 window_feature_bits(game->window),
                 (unsigned long long)(uintptr_t)view);
        note_feature_event(game, text);
    }
    framework_event(game, "window.set_content_view");
    if (game->viewroot.attach_complete &&
        agr_viewroot_request_layout(&game->viewroot, viewroot_event, game) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    DxMethod *changed = dx_vm_find_method(game->activity->klass, "onContentChanged", "V");
    if (changed) {
        DxValue args[1] = {DX_OBJ_VALUE(game->activity)};
        if (dx_vm_execute_method(game->vm, changed, args, 1, NULL) != DX_OK)
            return DX_ERR_INVALID_FORMAT;
    }
    return DX_OK;
}

static DxResult content_params(DxValue *args, uint32_t count, DxObject **view,
                               int32_t *width, int32_t *height) {
    if (count < 2 || args[1].tag != DX_VAL_OBJ || !args[1].obj) return DX_ERR_NULL_PTR;
    *view = args[1].obj;
    *width = -1;
    *height = -1;
    if (count >= 3 && args[2].tag == DX_VAL_OBJ && args[2].obj) {
        DxValue w = DX_NULL_VALUE, h = DX_NULL_VALUE;
        if (dx_vm_get_field(args[2].obj, "_width", &w) == DX_OK && w.tag == DX_VAL_INT) *width = w.i;
        if (dx_vm_get_field(args[2].obj, "_height", &h) == DX_OK && h.tag == DX_VAL_INT) *height = h.i;
    }
    return DX_OK;
}

static DxResult window_set_content_view(DxVM *vm, DxFrame *frame,
                                        DxValue *args, uint32_t count) {
    (void)frame;
    agr_dex_game *game = vm ? (agr_dex_game *)vm->framework_user : NULL;
    DxObject *view = NULL;
    int32_t width = -1, height = -1;
    if (content_params(args, count, &view, &width, &height) != DX_OK) return DX_ERR_NULL_PTR;
    if (!game || args[0].tag != DX_VAL_OBJ || args[0].obj != game->window)
        return DX_ERR_INVALID_FORMAT;
    return install_content_view(game, view, width, height);
}

static DxResult activity_set_content_view(DxVM *vm, DxFrame *frame,
                                          DxValue *args, uint32_t count) {
    (void)frame;
    agr_dex_game *game = vm ? (agr_dex_game *)vm->framework_user : NULL;
    if (!game || count < 2 || args[0].tag != DX_VAL_OBJ || args[0].obj != game->activity)
        return DX_ERR_INVALID_FORMAT;
    DxClass *window = dx_vm_find_class(vm, "Landroid/view/Window;");
    DxMethod *method = dx_vm_find_method(window, "setContentView", count >= 3 ? "VLL" : "VL");
    if (!method) return DX_ERR_INVALID_FORMAT;
    DxValue forwarded[3];
    forwarded[0] = DX_OBJ_VALUE(game->window);
    forwarded[1] = args[1];
    if (count >= 3) forwarded[2] = args[2];
    return dx_vm_execute_method(vm, method, forwarded, count >= 3 ? 3u : 2u, NULL);
}

static uint16_t axml_u16(const uint8_t *p) {
    return (uint16_t)(p[0] | (p[1] << 8));
}

static uint32_t axml_u32(const uint8_t *p) {
    return (uint32_t)(p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24));
}

static const char *axml_string(const DxAxmlParser *parser, uint32_t index) {
    if (!parser || index == 0xFFFFFFFFu || index >= parser->string_count) return NULL;
    return parser->strings[index];
}

static int view_class_descriptor(const char *name, char *out, size_t cap) {
    if (!name || !name[0] || !out || cap < 4) return 0;
    if (strchr(name, '.')) {
        size_t length = strlen(name);
        if (length + 3 > cap) return 0;
        out[0] = 'L';
        for (size_t i = 0; i < length; i++) out[i + 1] = name[i] == '.' ? '/' : name[i];
        out[length + 1] = ';';
        out[length + 2] = 0;
        return 1;
    }
    return snprintf(out, cap, "Landroid/widget/%s;", name) > 0;
}

static void link_child(DxObject *parent, DxObject *child) {
    DxValue first = DX_NULL_VALUE;
    if (!parent || !child) return;
    dx_vm_set_field(child, "_parent", DX_OBJ_VALUE(parent));
    if (dx_vm_get_field(parent, "_child", &first) != DX_OK ||
        first.tag != DX_VAL_OBJ || !first.obj) {
        dx_vm_set_field(parent, "_child", DX_OBJ_VALUE(child));
        return;
    }
    DxObject *cursor = first.obj;
    for (;;) {
        DxValue next = DX_NULL_VALUE;
        if (dx_vm_get_field(cursor, "_next", &next) != DX_OK ||
            next.tag != DX_VAL_OBJ || !next.obj) {
            dx_vm_set_field(cursor, "_next", DX_OBJ_VALUE(child));
            return;
        }
        cursor = next.obj;
    }
}

static DxObject *inflate_one_view(agr_dex_game *game, const char *name,
                                  int32_t id, int32_t width, int32_t height) {
    char descriptor[256];
    DxClass *cls = NULL;
    DxObject *view = NULL;
    DxMethod *init = NULL;
    if (!view_class_descriptor(name, descriptor, sizeof(descriptor))) return NULL;
    cls = dx_vm_find_class(game->vm, descriptor);
    if (!cls && dx_vm_load_class(game->vm, descriptor, &cls) != DX_OK) return NULL;
    if (!cls) return NULL;
    view = dx_vm_alloc_object(game->vm, cls);
    if (!view) return NULL;
    init = dx_vm_find_method(cls, "<init>", "VLL");
    if (!init) init = dx_vm_find_method(cls, "<init>", "VL");
    if (init) {
        DxValue args[3];
        uint32_t argc = 2;
        args[0] = DX_OBJ_VALUE(view);
        args[1] = DX_OBJ_VALUE(game->activity);
        args[2] = DX_NULL_VALUE;
        if (init->shorty && !strcmp(init->shorty, "VLL")) argc = 3;
        if (dx_vm_execute_method(game->vm, init, args, argc, NULL) != DX_OK) return NULL;
    }
    dx_vm_set_field(view, "_id", DX_INT_VALUE(id));
    dx_vm_set_field(view, "_layoutWidth", DX_INT_VALUE(width));
    dx_vm_set_field(view, "_layoutHeight", DX_INT_VALUE(height));
    return view;
}

/* PhoneWindow.setContentView(int) inflates into the content parent.
   layout_width/height -1 is MATCH_PARENT. An unknown class fails the
   inflation instead of installing a placeholder. */
static DxResult inflate_layout(agr_dex_game *game, const uint8_t *xml, uint32_t size,
                               DxObject **root_out, int32_t *width, int32_t *height) {
    DxAxmlParser *parser = NULL;
    DxObject *stack[16];
    int depth = 0;
    DxObject *root = NULL;
    uint32_t pos;
    if (!game || !xml || !root_out || dx_axml_parse(xml, size, &parser) != DX_OK) return DX_ERR_INVALID_FORMAT;
    pos = 8;
    while (pos + 8 <= size) {
        uint16_t chunk_type = axml_u16(xml + pos);
        uint16_t header_size = axml_u16(xml + pos + 2);
        uint32_t chunk_size = axml_u32(xml + pos + 4);
        if (chunk_size < 8 || pos + chunk_size > size || header_size < 8) {
            dx_axml_free(parser);
            return DX_ERR_INVALID_FORMAT;
        }
        if (chunk_type == 0x0102) {
            uint32_t ext = pos + header_size;
            uint32_t name_idx, attr_start;
            uint16_t attr_size, attr_count;
            int32_t id = 0, layout_width = -1, layout_height = -1;
            const char *name;
            DxObject *view;
            if (ext + 20 > pos + chunk_size) { dx_axml_free(parser); return DX_ERR_INVALID_FORMAT; }
            name_idx = axml_u32(xml + ext + 4);
            attr_start = axml_u16(xml + ext + 8);
            attr_size = axml_u16(xml + ext + 10);
            attr_count = axml_u16(xml + ext + 12);
            name = axml_string(parser, name_idx);
            for (uint16_t i = 0; i < attr_count; i++) {
                uint32_t at = ext + attr_start + (uint32_t)i * attr_size;
                const char *attr_name;
                uint8_t value_type;
                uint32_t value_data;
                if (attr_size < 20 || at + 20 > pos + chunk_size) continue;
                attr_name = axml_string(parser, axml_u32(xml + at + 4));
                value_type = xml[at + 15];
                value_data = axml_u32(xml + at + 16);
                if (attr_name && !strcmp(attr_name, "id") && value_type == 0x01)
                    id = (int32_t)value_data;
                else if (attr_name && !strcmp(attr_name, "layout_width") && value_type == 0x10)
                    layout_width = (int32_t)value_data;
                else if (attr_name && !strcmp(attr_name, "layout_height") && value_type == 0x10)
                    layout_height = (int32_t)value_data;
            }
            view = inflate_one_view(game, name, id, layout_width, layout_height);
            if (!view || depth >= 16) { dx_axml_free(parser); return DX_ERR_INVALID_FORMAT; }
            if (depth > 0) link_child(stack[depth - 1], view);
            else root = view;
            stack[depth++] = view;
        } else if (chunk_type == 0x0103) {
            if (depth > 0) depth--;
        }
        pos += chunk_size;
    }
    dx_axml_free(parser);
    if (!root) return DX_ERR_INVALID_FORMAT;
    *root_out = root;
    if (width) {
        DxValue value = DX_NULL_VALUE;
        *width = -1;
        if (dx_vm_get_field(root, "_layoutWidth", &value) == DX_OK && value.tag == DX_VAL_INT)
            *width = value.i;
    }
    if (height) {
        DxValue value = DX_NULL_VALUE;
        *height = -1;
        if (dx_vm_get_field(root, "_layoutHeight", &value) == DX_OK && value.tag == DX_VAL_INT)
            *height = value.i;
    }
    return DX_OK;
}

static const uint8_t *layout_xml(const agr_dex_game *game, uint32_t id, uint32_t *size) {
    if (size) *size = 0;
    if (!game) return NULL;
    for (uint32_t i = 0; i < game->layout_count; i++) {
        if (game->layouts[i].id == id) {
            if (size) *size = game->layouts[i].size;
            return game->layouts[i].xml;
        }
    }
    return NULL;
}

static DxResult window_set_content_layout(DxVM *vm, DxFrame *frame,
                                          DxValue *args, uint32_t count) {
    (void)frame;
    agr_dex_game *game = vm ? (agr_dex_game *)vm->framework_user : NULL;
    const uint8_t *xml;
    uint32_t xml_size = 0;
    DxObject *root = NULL;
    int32_t width = -1, height = -1;
    if (!game || count < 2 || args[0].tag != DX_VAL_OBJ || args[0].obj != game->window ||
        args[1].tag != DX_VAL_INT)
        return DX_ERR_INVALID_FORMAT;
    xml = layout_xml(game, (uint32_t)args[1].i, &xml_size);
    if (!xml || inflate_layout(game, xml, xml_size, &root, &width, &height) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    return install_content_view(game, root, width, height);
}

static DxResult activity_set_content_layout(DxVM *vm, DxFrame *frame,
                                            DxValue *args, uint32_t count) {
    (void)frame;
    agr_dex_game *game = vm ? (agr_dex_game *)vm->framework_user : NULL;
    DxClass *window;
    DxMethod *method;
    DxValue forwarded[2];
    if (!game || count < 2 || args[0].tag != DX_VAL_OBJ || args[0].obj != game->activity ||
        args[1].tag != DX_VAL_INT)
        return DX_ERR_INVALID_FORMAT;
    window = dx_vm_find_class(vm, "Landroid/view/Window;");
    method = dx_vm_find_method(window, "setContentView", "VI");
    if (!method) return DX_ERR_INVALID_FORMAT;
    forwarded[0] = DX_OBJ_VALUE(game->window);
    forwarded[1] = args[1];
    return dx_vm_execute_method(vm, method, forwarded, 2, NULL);
}

static DxObject *find_view_in_tree(DxObject *view, int32_t id);

static DxObject *find_view_and_siblings(DxObject *view, int32_t id) {
    while (view) {
        DxObject *found = find_view_in_tree(view, id);
        DxValue next = DX_NULL_VALUE;
        if (found) return found;
        if (dx_vm_get_field(view, "_next", &next) != DX_OK || next.tag != DX_VAL_OBJ) break;
        view = next.obj;
    }
    return NULL;
}

static DxObject *find_view_in_tree(DxObject *view, int32_t id) {
    DxValue value = DX_NULL_VALUE;
    if (!view) return NULL;
    if (dx_vm_get_field(view, "_id", &value) == DX_OK && value.tag == DX_VAL_INT && value.i == id)
        return view;
    if (dx_vm_get_field(view, "_child", &value) == DX_OK && value.tag == DX_VAL_OBJ)
        return find_view_and_siblings(value.obj, id);
    return NULL;
}

static DxResult activity_find_view_by_id(DxVM *vm, DxFrame *frame,
                                         DxValue *args, uint32_t count) {
    agr_dex_game *game = vm ? (agr_dex_game *)vm->framework_user : NULL;
    DxObject *found = NULL;
    if (!frame) return DX_ERR_INVALID_FORMAT;
    if (!game || count < 2 || args[0].tag != DX_VAL_OBJ || args[0].obj != game->activity ||
        args[1].tag != DX_VAL_INT)
        return DX_ERR_INVALID_FORMAT;
    found = find_view_in_tree(game->content_view, args[1].i);
    frame->result = found ? DX_OBJ_VALUE(found) : DX_NULL_VALUE;
    frame->has_result = true;
    return DX_OK;
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

static agr_dex_game *game_from_vm(DxVM *vm) {
    return vm ? (agr_dex_game *)vm->framework_user : NULL;
}

/* API19 BitmapFactory.decodeResource(Resources, int, Options) opens the raw
   resource and decodes it through KitKat SkImageDecoder (agr_bitmap). Failure
   returns null. Failure with Options.inBitmap set throws IllegalArgumentException.
   inJustDecodeBounds returns null after writing outWidth and outHeight without
   allocating pixels. Density scaling is not applied: Frozen Bubble sets
   Options.inScaled false before these calls. */
static struct agr_guest_bitmap *guest_bitmap_slot(agr_dex_game *game, DxObject *guest) {
    if (!game || !guest) return NULL;
    for (uint32_t i = 0; i < game->bitmap_count; i++)
        if (game->bitmaps[i].guest == guest) return &game->bitmaps[i];
    return NULL;
}

static struct agr_guest_bitmap *guest_bitmap_attach(agr_dex_game *game, DxObject *guest,
                                                    agr_bitmap *host) {
    struct agr_guest_bitmap *slot;
    if (!game || !guest || !host) return NULL;
    slot = guest_bitmap_slot(game, guest);
    if (slot) {
        if (slot->host && slot->host != host) agr_bitmap_destroy(slot->host);
        slot->host = host;
        slot->recycled = 0;
        return slot;
    }
    if (game->bitmap_count >= AGR_GUEST_BITMAP_CAP) {
        agr_bitmap_destroy(host);
        return NULL;
    }
    slot = &game->bitmaps[game->bitmap_count++];
    slot->guest = guest;
    slot->host = host;
    slot->recycled = 0;
    return slot;
}

static void release_guest_bitmaps(agr_dex_game *game) {
    if (!game) return;
    for (uint32_t i = 0; i < game->bitmap_count; i++) {
        if (game->bitmaps[i].host) agr_bitmap_destroy(game->bitmaps[i].host);
        game->bitmaps[i].host = NULL;
        game->bitmaps[i].guest = NULL;
        game->bitmaps[i].recycled = 1;
    }
    game->bitmap_count = 0;
}

static DxResult bitmap_decode_byte_array(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    DxObject *array;
    int32_t offset, length;
    uint8_t *bytes = NULL;
    agr_bitmap *host;
    DxClass *bitmap_class;
    DxObject *bitmap;
    int width, height;
    if (count < 3 || args[0].tag != DX_VAL_OBJ || !args[0].obj || !args[0].obj->is_array)
        return bitmap_decode_failed(vm, frame, 0);
    array = args[0].obj;
    offset = args[1].tag == DX_VAL_INT ? args[1].i : 0;
    length = args[2].tag == DX_VAL_INT ? args[2].i : 0;
    if (offset < 0 || length <= 0 ||
        (uint64_t)offset + (uint64_t)length > (uint64_t)array->array_length ||
        !array->array_elements)
        return bitmap_decode_failed(vm, frame, 0);
    bytes = (uint8_t *)malloc((size_t)length);
    if (!bytes) return DX_ERR_OUT_OF_MEMORY;
    for (int32_t i = 0; i < length; i++) {
        DxValue cell = array->array_elements[offset + i];
        bytes[i] = (uint8_t)(cell.tag == DX_VAL_INT ? cell.i : 0);
    }
    host = agr_bitmap_decode(bytes, (size_t)length);
    free(bytes);
    if (!host) return bitmap_decode_failed(vm, frame, 0);
    width = (int)agr_bitmap_width(host);
    height = (int)agr_bitmap_height(host);
    if (width <= 0 || height <= 0 || !agr_bitmap_pixels(host)) {
        agr_bitmap_destroy(host);
        return bitmap_decode_failed(vm, frame, 0);
    }
    bitmap_class = dx_vm_find_class(vm, "Landroid/graphics/Bitmap;");
    bitmap = bitmap_class ? dx_vm_alloc_object(vm, bitmap_class) : NULL;
    if (!bitmap) {
        agr_bitmap_destroy(host);
        return bitmap_decode_failed(vm, frame, 0);
    }
    if (!guest_bitmap_attach(game, bitmap, host))
        return bitmap_decode_failed(vm, frame, 0);
    dx_vm_set_field(bitmap, "_width", DX_INT_VALUE(width));
    dx_vm_set_field(bitmap, "_height", DX_INT_VALUE(height));
    dx_vm_set_field(bitmap, "_recycled", DX_INT_VALUE(0));
    frame->result = DX_OBJ_VALUE(bitmap);
    frame->has_result = true;
    return DX_OK;
}

static DxResult bitmap_recycle(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_guest_bitmap *slot;
    (void)frame;
    if (count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_NULL_PTR;
    slot = guest_bitmap_slot(game, args[0].obj);
    if (slot && slot->host) {
        agr_bitmap_destroy(slot->host);
        slot->host = NULL;
        slot->recycled = 1;
    }
    dx_vm_set_field(args[0].obj, "_recycled", DX_INT_VALUE(1));
    return DX_OK;
}

static void publish_bitmap_scale(DxVM *vm, uint32_t phase, const char *detail) {
    agr_forensic_sample sample = forensic_fill(phase, 0, vm ? dx_vm_current_exec(vm) : NULL,
                                               NULL, 0, 0, 0);
    snprintf(sample.class_name, sizeof(sample.class_name), "Landroid/graphics/Bitmap;");
    snprintf(sample.method_name, sizeof(sample.method_name), "createScaledBitmap");
    snprintf(sample.detail, sizeof(sample.detail), "%s", detail ? detail : "");
    forensic_publish(&sample);
}

/* API19 Bitmap.createScaledBitmap(Bitmap, int, int, boolean).
   Same requested dimensions return the source object. Any other positive
   size returns a new Bitmap whose pixels are the scaled source. A null
   source throws NullPointerException. Non-positive dimensions throw
   IllegalArgumentException. A recycled source throws IllegalStateException.
   This does not allocate a Matrix, Canvas, or Paint. */
static DxResult bitmap_create_scaled(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_guest_bitmap *slot;
    DxObject *source;
    DxClass *bitmap_class;
    DxObject *bitmap;
    agr_bitmap *scaled;
    DxValue path = DX_NULL_VALUE;
    int dst_w, dst_h, filter, src_w, src_h;
    if (count < 4 || args[0].tag != DX_VAL_OBJ || !args[0].obj) {
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_REFERENCE_WITNESS,
                               "Landroid/graphics/Bitmap;", "createScaledBitmap", -1,
                               NULL, NULL, NULL, DX_ERR_NULL_PTR, 0, 0, 0,
                               count > 1 && args[1].tag == DX_VAL_INT ? args[1].i : 0,
                               count > 2 && args[2].tag == DX_VAL_INT ? args[2].i : 0,
                               "scale_source=null");
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_FAIL, "fail=NPE;src=0");
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/NullPointerException;", "bitmap");
        return DX_ERR_EXCEPTION;
    }
    source = args[0].obj;
    dst_w = args[1].tag == DX_VAL_INT ? args[1].i : 0;
    dst_h = args[2].tag == DX_VAL_INT ? args[2].i : 0;
    filter = args[3].tag == DX_VAL_INT && args[3].i != 0;
    if (dst_w <= 0) {
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_FAIL, "fail=IAE_W;src=1");
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/IllegalArgumentException;", "width must be > 0");
        return DX_ERR_EXCEPTION;
    }
    if (dst_h <= 0) {
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_FAIL, "fail=IAE_H;src=1");
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/IllegalArgumentException;", "height must be > 0");
        return DX_ERR_EXCEPTION;
    }
    slot = guest_bitmap_slot(game, source);
    publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_REFERENCE_WITNESS,
                           "Landroid/graphics/Bitmap;", "createScaledBitmap", -1,
                           source, NULL, slot ? slot->host : NULL,
                           slot && slot->host && !slot->recycled ? DX_OK : DX_ERR_INVALID_FORMAT,
                           AGR_BITMAP_WITNESS_HAS_OBJECT |
                               (slot && slot->host ? AGR_BITMAP_WITNESS_HAS_BACKING : 0u) |
                               (slot && slot->host && agr_bitmap_pixels(slot->host)
                                    ? AGR_BITMAP_WITNESS_HAS_PIXELS : 0u) |
                               (slot && slot->recycled ? AGR_BITMAP_WITNESS_RECYCLED : 0u),
                           slot && slot->host ? (int)agr_bitmap_width(slot->host) : 0,
                           slot && slot->host ? (int)agr_bitmap_height(slot->host) : 0,
                           dst_w, dst_h, "scale_source");
    if (!slot || slot->recycled || !slot->host || !agr_bitmap_pixels(slot->host)) {
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_FAIL, "fail=RECYCLED;src=0");
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/IllegalStateException;",
            "Can't call getWidth() on a recycled bitmap");
        return DX_ERR_EXCEPTION;
    }
    src_w = (int)agr_bitmap_width(slot->host);
    src_h = (int)agr_bitmap_height(slot->host);
    {
        char detail[96];
        snprintf(detail, sizeof(detail), "src=%d,%d;dst=%d,%d;filter=%d;src_ok=1",
                 src_w, src_h, dst_w, dst_h, filter);
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_BEGIN, detail);
    }
    if (src_w == dst_w && src_h == dst_h) {
        char detail[96];
        snprintf(detail, sizeof(detail), "dst=%d,%d;same=1;src_ok=1", dst_w, dst_h);
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_END, detail);
        frame->result = DX_OBJ_VALUE(source);
        frame->has_result = true;
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_REFERENCE_WITNESS,
                               "Landroid/graphics/Bitmap;", "createScaledBitmap", -1,
                               source, source, slot->host, DX_OK,
                               AGR_BITMAP_WITNESS_HAS_OBJECT | AGR_BITMAP_WITNESS_HAS_BACKING |
                                   AGR_BITMAP_WITNESS_HAS_PIXELS,
                               src_w, src_h, dst_w, dst_h, "scale_return_same_object");
        return DX_OK;
    }
    scaled = agr_bitmap_scale(slot->host, dst_w, dst_h, filter);
    if (!scaled) {
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_FAIL, "fail=OOM;src_ok=1");
        return DX_ERR_OUT_OF_MEMORY;
    }
    bitmap_class = dx_vm_find_class(vm, "Landroid/graphics/Bitmap;");
    bitmap = bitmap_class ? dx_vm_alloc_object(vm, bitmap_class) : NULL;
    if (!bitmap || !guest_bitmap_attach(game, bitmap, scaled)) {
        if (!bitmap) agr_bitmap_destroy(scaled);
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_FAIL, "fail=ATTACH;src_ok=1");
        frame->result = DX_NULL_VALUE;
        frame->has_result = true;
        return DX_OK;
    }
    if (dx_vm_get_field(source, "_assetPath", &path) == DX_OK)
        dx_vm_set_field(bitmap, "_assetPath", path);
    dx_vm_set_field(bitmap, "_width", DX_INT_VALUE((int)agr_bitmap_width(scaled)));
    dx_vm_set_field(bitmap, "_height", DX_INT_VALUE((int)agr_bitmap_height(scaled)));
    dx_vm_set_field(bitmap, "_recycled", DX_INT_VALUE(0));
    {
        char detail[96];
        snprintf(detail, sizeof(detail), "dst=%d,%d;same=0;src_ok=1",
                 (int)agr_bitmap_width(scaled), (int)agr_bitmap_height(scaled));
        publish_bitmap_scale(vm, AGR_PHYS_PHASE_BITMAP_SCALE_END, detail);
    }
    frame->result = DX_OBJ_VALUE(bitmap);
    frame->has_result = true;
    publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_REFERENCE_WITNESS,
                           "Landroid/graphics/Bitmap;", "createScaledBitmap", -1,
                           bitmap, source, scaled, DX_OK,
                           AGR_BITMAP_WITNESS_HAS_OBJECT | AGR_BITMAP_WITNESS_HAS_BACKING |
                               AGR_BITMAP_WITNESS_HAS_PIXELS,
                           (int)agr_bitmap_width(scaled), (int)agr_bitmap_height(scaled),
                           dst_w, dst_h, "scale_return_new_object");
    return DX_OK;
}

static DxResult bitmap_decode_resource(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    const DxResourceEntry *entry;
    const DxZipEntry *zip = NULL;
    uint8_t *bytes = NULL;
    uint32_t size = 0;
    int width = 0, height = 0;
    int reuse_bitmap = options_value_set(args, count, "inBitmap");
    DxObject *options = count > 2 && args[2].tag == DX_VAL_OBJ ? args[2].obj : NULL;
    DxClass *bitmap_class;
    DxObject *bitmap;
    agr_bitmap *host = NULL;
    int32_t resource_id = count > 1 && args[1].tag == DX_VAL_INT ? args[1].i : -1;
    uint32_t option_flags = 0;
    char options_detail[160], decode_detail[256];
    options_witness_text(args, count, options_detail, sizeof(options_detail));
    snprintf(decode_detail, sizeof(decode_detail), "resource_path=unresolved;%s", options_detail);
    if (count > 2 && args[2].tag == DX_VAL_OBJ && args[2].obj)
        option_flags |= AGR_BITMAP_WITNESS_HAS_OPTIONS;
    if (options_value_set(args, count, "inJustDecodeBounds"))
        option_flags |= AGR_BITMAP_WITNESS_BOUNDS_ONLY;
    if (reuse_bitmap) option_flags |= AGR_BITMAP_WITNESS_IN_BITMAP;
    if (count < 3 || args[1].tag != DX_VAL_INT)
    {
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                               "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                               NULL, options, NULL, DX_ERR_INVALID_FORMAT, option_flags,
                               0, 0, 0, 0, decode_detail);
        return bitmap_decode_failed(vm, frame, reuse_bitmap);
    }
    entry = game ? resource_file_entry(game->resources, game->resource_apk,
                                       (uint32_t)args[1].i) : NULL;
    if (entry && entry->str_val)
        snprintf(decode_detail, sizeof(decode_detail), "resource_path=%s;%s",
                 entry->str_val, options_detail);
    if (!entry || !entry->str_val || !game || !game->resource_apk ||
        dx_apk_find_entry(game->resource_apk, entry->str_val, &zip) != DX_OK ||
        dx_apk_extract_entry(game->resource_apk, zip, &bytes, &size) != DX_OK) {
        dx_free(bytes);
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                               "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                               NULL, options, NULL, DX_ERR_NOT_FOUND, option_flags,
                               0, 0, 0, 0, decode_detail);
        return bitmap_decode_failed(vm, frame, reuse_bitmap);
    }
    if (options_value_set(args, count, "inJustDecodeBounds")) {
        if (!encoded_image_size(bytes, size, &width, &height)) {
            dx_free(bytes);
            publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                                   "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                                   NULL, options, NULL, DX_ERR_INVALID_FORMAT, option_flags,
                                   0, 0, (int)size, 0, decode_detail);
            return bitmap_decode_failed(vm, frame, reuse_bitmap);
        }
        dx_free(bytes);
        dx_vm_set_field(args[2].obj, "outWidth", DX_INT_VALUE(width));
        dx_vm_set_field(args[2].obj, "outHeight", DX_INT_VALUE(height));
        frame->result = DX_NULL_VALUE;
        frame->has_result = true;
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                               "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                               NULL, options, NULL, DX_OK, option_flags,
                               width, height, (int)size, 0, decode_detail);
        return DX_OK;
    }
    host = agr_bitmap_decode(bytes, size);
    dx_free(bytes);
    if (!host) {
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                               "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                               NULL, options, NULL, DX_ERR_INVALID_FORMAT, option_flags,
                               0, 0, (int)size, 0, decode_detail);
        return bitmap_decode_failed(vm, frame, reuse_bitmap);
    }
    width = (int)agr_bitmap_width(host);
    height = (int)agr_bitmap_height(host);
    if (width <= 0 || height <= 0 || !agr_bitmap_pixels(host)) {
        agr_bitmap_destroy(host);
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                               "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                               NULL, options, NULL, DX_ERR_INVALID_FORMAT, option_flags,
                               width, height, (int)size, 0, decode_detail);
        return bitmap_decode_failed(vm, frame, reuse_bitmap);
    }
    bitmap_class = dx_vm_find_class(vm, "Landroid/graphics/Bitmap;");
    bitmap = bitmap_class ? dx_vm_alloc_object(vm, bitmap_class) : NULL;
    if (!bitmap) {
        agr_bitmap_destroy(host);
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                               "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                               NULL, options, NULL, DX_ERR_OUT_OF_MEMORY, option_flags,
                               width, height, (int)size, 0, decode_detail);
        return bitmap_decode_failed(vm, frame, reuse_bitmap);
    }
    if (!guest_bitmap_attach(game, bitmap, host)) {
        publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                               "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                               bitmap, options, NULL, DX_ERR_OUT_OF_MEMORY,
                               option_flags | AGR_BITMAP_WITNESS_HAS_OBJECT,
                               width, height, (int)size, 0, decode_detail);
        return bitmap_decode_failed(vm, frame, reuse_bitmap);
    }
    dx_vm_set_field(bitmap, "_assetPath",
                    DX_OBJ_VALUE(dx_vm_create_string(vm, entry->str_val)));
    dx_vm_set_field(bitmap, "_width", DX_INT_VALUE(width));
    dx_vm_set_field(bitmap, "_height", DX_INT_VALUE(height));
    dx_vm_set_field(bitmap, "_recycled", DX_INT_VALUE(0));
    frame->result = DX_OBJ_VALUE(bitmap);
    frame->has_result = true;
    publish_bitmap_witness(vm, AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS,
                           "Landroid/graphics/BitmapFactory;", "decodeResource", resource_id,
                           bitmap, options, host, DX_OK,
                           option_flags | AGR_BITMAP_WITNESS_HAS_OBJECT |
                               AGR_BITMAP_WITNESS_HAS_BACKING | AGR_BITMAP_WITNESS_HAS_PIXELS,
                           width, height, (int)size, 0, decode_detail);
    return DX_OK;
}

static struct agr_content_surface *content_slot_for_canvas(agr_dex_game *game, DxObject *canvas) {
    if (!game || !canvas) return NULL;
    for (uint32_t i = 0; i < game->content_surface_count; i++)
        if (game->content_surfaces[i].canvas == canvas) return &game->content_surfaces[i];
    return NULL;
}

static uint64_t content_buffer_hash(const void *pixels, size_t bytes);

/* API19 SkFloatBits_toIntRound. Non-AA clipRect uses SkRect::round, which is
   this conversion on each edge. Halfway cases follow the Skia bit routine,
   not a separately invented rule. */
static int32_t canvas_round_coord(float x) {
    union { float f; int32_t i; } bits;
    int32_t packed;
    int exp, value, sign;
    bits.f = x;
    packed = bits.i;
    if ((packed << 1) == 0) return 0;
    exp = (int)(((uint32_t)packed << 1) >> 24) - (127 + 23);
    value = (packed & ~0xFF000000) | (1 << 23);
    sign = packed >> 31;
    if (exp >= 0) {
        if (exp > 7) value = 0x7FFFFFFF;
        else value <<= exp;
        return sign == -1 ? -value : value;
    }
    value = sign == -1 ? -value : value;
    exp = -exp;
    if (exp > 25) exp = 25;
    return (value + (1 << (exp - 1))) >> exp;
}

static void canvas_trace_begin(agr_dex_game *game, DxVM *vm, DxFrame *frame,
                               const char *kind, agr_canvas_trace *event) {
    const char *caller = "?";
    memset(event, 0, sizeof(*event));
    if (!game || !vm || !vm->telemetry.telemetry_enabled) return;
    if (game->canvas_trace_count >= AGR_CANVAS_TRACE_CAP) return;
    event->exec_id = dx_vm_current_exec(vm) ? dx_vm_current_exec(vm)->id : 0;
    if (vm->invoke_site_valid) {
        event->pc = vm->invoke_site_pc;
        event->opcode = vm->invoke_site_opcode;
        event->method_idx = vm->invoke_site_method_idx;
    }
    if (frame && frame->caller && frame->caller->method && frame->caller->method->name)
        caller = frame->caller->method->name;
    if (frame && frame->caller && frame->caller->method &&
        frame->caller->method->declaring_class &&
        frame->caller->method->declaring_class->descriptor) {
        snprintf(event->caller, sizeof(event->caller), "%s.%s",
                 frame->caller->method->declaring_class->descriptor, caller);
    } else {
        snprintf(event->caller, sizeof(event->caller), "%s", caller);
    }
    snprintf(event->kind, sizeof(event->kind), "%s", kind);
}

static void canvas_trace_commit(agr_dex_game *game, DxVM *vm, const agr_canvas_trace *event) {
    if (!game || !vm || !vm->telemetry.telemetry_enabled) return;
    if (game->canvas_trace_count >= AGR_CANVAS_TRACE_CAP) return;
    game->canvas_trace[game->canvas_trace_count++] = *event;
}

static struct agr_content_surface *canvas_live_slot(agr_dex_game *game, DxObject *canvas) {
    struct agr_content_surface *slot = content_slot_for_canvas(game, canvas);
    if (!slot || !slot->canvas_locked || !slot->pixels) return NULL;
    if (slot->locked_generation != slot->generation) return NULL;
    return slot;
}

static void canvas_copy_clip(const struct agr_content_surface *slot, int out[4]) {
    out[0] = slot->clip_left;
    out[1] = slot->clip_top;
    out[2] = slot->clip_right;
    out[3] = slot->clip_bottom;
}

static DxResult canvas_throw(DxVM *vm, const char *descriptor, const char *message) {
    dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(vm, descriptor, message);
    return DX_ERR_EXCEPTION;
}

/* API19 Canvas.save(int) returns getSaveCount() before the push. The base
   lock starts at 1. CLIP_SAVE_FLAG stores the clip; a save without that bit
   shares the clip with the previous level, so restore does not roll it back. */
static DxResult canvas_save(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    struct agr_canvas_save *saved;
    agr_canvas_trace event;
    int32_t flags;
    if (!frame || count < 2 || args[0].tag != DX_VAL_OBJ || !args[0].obj)
        return DX_ERR_NULL_PTR;
    flags = args[1].tag == DX_VAL_INT ? args[1].i : 0;
    canvas_trace_begin(game, vm, frame, "save", &event);
    event.save_flags = flags;
    slot = canvas_live_slot(game, args[0].obj);
    if (!slot || slot->save_count < 1) {
        frame->result = DX_INT_VALUE(0);
        frame->has_result = true;
        event.save_returned = 0;
        canvas_trace_commit(game, vm, &event);
        return DX_OK;
    }
    canvas_copy_clip(slot, event.clip_before);
    if (slot->save_count > AGR_CANVAS_SAVE_CAP) {
        canvas_trace_commit(game, vm, &event);
        return canvas_throw(vm, "Ljava/lang/IllegalStateException;", "Canvas save stack is full");
    }
    saved = &slot->save_stack[slot->save_count - 1];
    memset(saved, 0, sizeof(*saved));
    saved->flags = flags;
    saved->owns_clip = (flags & AGR_CANVAS_CLIP_SAVE_FLAG) != 0;
    saved->clip_left = slot->clip_left;
    saved->clip_top = slot->clip_top;
    saved->clip_right = slot->clip_right;
    saved->clip_bottom = slot->clip_bottom;
    event.save_returned = slot->save_count;
    slot->save_count++;
    event.save_count_after = slot->save_count;
    canvas_copy_clip(slot, event.clip_after);
    frame->result = DX_INT_VALUE(event.save_returned);
    frame->has_result = true;
    canvas_trace_commit(game, vm, &event);
    return DX_OK;
}

/* REPLACE sets the current clip to the rounded rectangle intersected with the
   device. The boolean is whether that resulting clip is non-empty. Other
   Region.Op values are not implemented. A null Op is a NullPointerException,
   matching op.nativeInt on API19. */
static DxResult canvas_clip_rect(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    agr_canvas_trace event;
    DxObject *op;
    DxValue native_int = DX_NULL_VALUE;
    float left, top, right, bottom;
    int rounded_l, rounded_t, rounded_r, rounded_b;
    int result = 0;
    if (!frame || count < 6 || args[0].tag != DX_VAL_OBJ || !args[0].obj)
        return DX_ERR_NULL_PTR;
    left = args[1].tag == DX_VAL_FLOAT ? args[1].f : (float)args[1].i;
    top = args[2].tag == DX_VAL_FLOAT ? args[2].f : (float)args[2].i;
    right = args[3].tag == DX_VAL_FLOAT ? args[3].f : (float)args[3].i;
    bottom = args[4].tag == DX_VAL_FLOAT ? args[4].f : (float)args[4].i;
    op = args[5].tag == DX_VAL_OBJ ? args[5].obj : NULL;
    canvas_trace_begin(game, vm, frame, "clipRect", &event);
    event.left = left;
    event.top = top;
    event.right = right;
    event.bottom = bottom;
    event.op_identity = (uint64_t)(uintptr_t)op;
    event.op_null = op ? 0 : 1;
    if (op && op->klass && op->klass->descriptor)
        snprintf(event.op_class, sizeof(event.op_class), "%s", op->klass->descriptor);
    if (!op) {
        canvas_trace_commit(game, vm, &event);
        return canvas_throw(vm, "Ljava/lang/NullPointerException;", "Region.Op is null");
    }
    if (dx_vm_get_field(op, "nativeInt", &native_int) == DX_OK && native_int.tag == DX_VAL_INT)
        event.op_native = native_int.i;
    else
        event.op_native = -1;
    slot = canvas_live_slot(game, args[0].obj);
    if (slot) canvas_copy_clip(slot, event.clip_before);
    if (event.op_native != AGR_REGION_OP_REPLACE) {
        canvas_trace_commit(game, vm, &event);
        return canvas_throw(vm, "Ljava/lang/UnsupportedOperationException;",
                            "Canvas.clipRect Region.Op other than REPLACE is not implemented");
    }
    if (!slot) {
        frame->result = DX_INT_VALUE(0);
        frame->has_result = true;
        canvas_trace_commit(game, vm, &event);
        return DX_OK;
    }
    rounded_l = canvas_round_coord(left);
    rounded_t = canvas_round_coord(top);
    rounded_r = canvas_round_coord(right);
    rounded_b = canvas_round_coord(bottom);
    if (rounded_l >= rounded_r || rounded_t >= rounded_b) {
        slot->clip_left = slot->clip_top = slot->clip_right = slot->clip_bottom = 0;
    } else {
        if (rounded_l < 0) rounded_l = 0;
        if (rounded_t < 0) rounded_t = 0;
        if (rounded_r > slot->width) rounded_r = slot->width;
        if (rounded_b > slot->height) rounded_b = slot->height;
        if (rounded_l >= rounded_r || rounded_t >= rounded_b) {
            slot->clip_left = slot->clip_top = slot->clip_right = slot->clip_bottom = 0;
        } else {
            slot->clip_left = rounded_l;
            slot->clip_top = rounded_t;
            slot->clip_right = rounded_r;
            slot->clip_bottom = rounded_b;
            result = 1;
        }
    }
    event.bool_result = result;
    event.save_count_after = slot->save_count;
    canvas_copy_clip(slot, event.clip_after);
    frame->result = DX_INT_VALUE(result);
    frame->has_result = true;
    canvas_trace_commit(game, vm, &event);
    return DX_OK;
}

static DxResult canvas_restore(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    struct agr_canvas_save *saved;
    agr_canvas_trace event;
    if (!frame || count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj)
        return DX_ERR_NULL_PTR;
    canvas_trace_begin(game, vm, frame, "restore", &event);
    slot = canvas_live_slot(game, args[0].obj);
    if (!slot) return DX_OK;
    canvas_copy_clip(slot, event.clip_before);
    event.save_count_after = slot->save_count;
    if (slot->save_count <= 1) {
        canvas_trace_commit(game, vm, &event);
        return canvas_throw(vm, "Ljava/lang/IllegalStateException;", "Underflow in restore");
    }
    slot->save_count--;
    saved = &slot->save_stack[slot->save_count - 1];
    event.save_flags = saved->flags;
    if (saved->owns_clip) {
        slot->clip_left = saved->clip_left;
        slot->clip_top = saved->clip_top;
        slot->clip_right = saved->clip_right;
        slot->clip_bottom = saved->clip_bottom;
    }
    event.save_count_after = slot->save_count;
    canvas_copy_clip(slot, event.clip_after);
    canvas_trace_commit(game, vm, &event);
    return DX_OK;
}

static void publish_region_op_replace(DxVM *vm, DxClass *obj) {
    DxClass *enum_cls = dx_vm_find_class(vm, "Ljava/lang/Enum;");
    DxClass *op_cls;
    DxObject *replace;
    const char *names[] = { "nativeInt", "name", "ordinal" };
    const char *types[] = { "I", "Ljava/lang/String;", "I" };
    uint32_t own = 3;
    reg_class(vm, "Landroid/graphics/Region;", obj);
    op_cls = reg_class(vm, "Landroid/graphics/Region$Op;", enum_cls ? enum_cls : obj);
    if (!op_cls) return;
    own_fields(op_cls, own, names, types);
    op_cls->access_flags = DX_ACC_PUBLIC | DX_ACC_FINAL | DX_ACC_ENUM;
    replace = dx_vm_alloc_object(vm, op_cls);
    if (!replace) return;
    dx_vm_set_field(replace, "nativeInt", DX_INT_VALUE(AGR_REGION_OP_REPLACE));
    dx_vm_set_field(replace, "ordinal", DX_INT_VALUE(AGR_REGION_OP_REPLACE));
    dx_vm_set_field(replace, "name", DX_OBJ_VALUE(dx_vm_create_string(vm, "REPLACE")));
    op_cls->field_defs = dx_realloc(op_cls->field_defs, sizeof(*op_cls->field_defs) * (own + 1));
    if (!op_cls->field_defs) return;
    memset(&op_cls->field_defs[own], 0, sizeof(op_cls->field_defs[own]));
    op_cls->field_defs[own].name = "REPLACE";
    op_cls->field_defs[own].type = "Landroid/graphics/Region$Op;";
    op_cls->field_defs[own].flags = DX_ACC_PUBLIC | DX_ACC_STATIC | DX_ACC_FINAL | DX_ACC_ENUM;
    op_cls->static_fields = dx_malloc(sizeof(DxValue));
    if (!op_cls->static_fields) return;
    op_cls->static_fields[0] = DX_OBJ_VALUE(replace);
    op_cls->static_field_count = 1;
}

static void content_blit_bounds(int src_w, int src_h, float left, float top,
                                int clip_l, int clip_t, int clip_r, int clip_b,
                                int dst_w, int dst_h,
                                int *x0, int *y0, int *x1, int *y1) {
    int dst_x0, dst_y0, draw_x, draw_y, draw_w, draw_h;
    *x0 = *y0 = *x1 = *y1 = 0;
    if (clip_l < 0) clip_l = 0;
    if (clip_t < 0) clip_t = 0;
    if (clip_r > dst_w) clip_r = dst_w;
    if (clip_b > dst_h) clip_b = dst_h;
    if (clip_r <= clip_l || clip_b <= clip_t || src_w <= 0 || src_h <= 0) return;
    dst_x0 = (int)floorf(left);
    dst_y0 = (int)floorf(top);
    draw_x = dst_x0;
    draw_y = dst_y0;
    draw_w = src_w;
    draw_h = src_h;
    if (draw_x < clip_l) {
        draw_w -= clip_l - draw_x;
        draw_x = clip_l;
    }
    if (draw_y < clip_t) {
        draw_h -= clip_t - draw_y;
        draw_y = clip_t;
    }
    if (draw_x + draw_w > clip_r) draw_w = clip_r - draw_x;
    if (draw_y + draw_h > clip_b) draw_h = clip_b - draw_y;
    if (draw_w <= 0 || draw_h <= 0) return;
    *x0 = draw_x;
    *y0 = draw_y;
    *x1 = draw_x + draw_w;
    *y1 = draw_y + draw_h;
}

/* API19 Canvas.drawBitmap(Bitmap, float, float, Paint). Frozen Bubble passes a
   null Paint. Destination is the locked SurfaceView content Surface backing
   (host RGBA8888 / SkPMColor layout). The clip is the current Canvas clip. */
static DxResult canvas_draw_bitmap(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    struct agr_guest_bitmap *bitmap_slot;
    DxObject *canvas;
    DxObject *bitmap;
    float left, top;
    int wrote;
    uint64_t before, after;
    size_t bytes;
    (void)frame;
    if (count < 4 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_NULL_PTR;
    canvas = args[0].obj;
    bitmap = args[1].tag == DX_VAL_OBJ ? args[1].obj : NULL;
    left = args[2].tag == DX_VAL_FLOAT ? args[2].f :
           args[2].tag == DX_VAL_INT ? (float)args[2].i : 0.f;
    top = args[3].tag == DX_VAL_FLOAT ? args[3].f :
          args[3].tag == DX_VAL_INT ? (float)args[3].i : 0.f;
    /* args[4] Paint may be null. Null Paint uses default SRC_OVER. */
    slot = content_slot_for_canvas(game, canvas);
    if (!slot || !slot->canvas_locked || !slot->pixels ||
        slot->locked_generation != slot->generation) {
        return DX_OK;
    }
    if (!bitmap) return DX_OK;
    bitmap_slot = guest_bitmap_slot(game, bitmap);
    if (!bitmap_slot || bitmap_slot->recycled || !bitmap_slot->host ||
        !agr_bitmap_pixels(bitmap_slot->host)) {
        return DX_OK;
    }
    bytes = (size_t)slot->width * (size_t)slot->height * (size_t)AGR_CONTENT_BYTES_PER_PIXEL;
    before = content_buffer_hash(slot->pixels, bytes);
    forensic_surface(AGR_PHYS_PHASE_DRAW_BITMAP_BEGIN, 0, dx_vm_current_exec(vm), slot,
                     slot->draw_bitmap_count, slot->draw_bitmap_count, 1);
    if (!game->first_bitmap_noted) {
        DxValue path = DX_NULL_VALUE;
        const char *text = NULL;
        const char *dot = NULL;
        game->first_bitmap_noted = 1;
        game->first_bitmap_guest = (uint64_t)(uintptr_t)bitmap;
        game->first_bitmap_host = (uint64_t)(uintptr_t)bitmap_slot->host;
        game->first_bitmap_width = (int)agr_bitmap_width(bitmap_slot->host);
        game->first_bitmap_height = (int)agr_bitmap_height(bitmap_slot->host);
        if (dx_vm_get_field(bitmap, "_assetPath", &path) == DX_OK && path.tag == DX_VAL_OBJ)
            text = dx_vm_get_string_value(path.obj);
        snprintf(game->first_bitmap_path, sizeof(game->first_bitmap_path), "%s", text ? text : "");
        dot = text ? strrchr(text, '.') : NULL;
        snprintf(game->first_bitmap_encoding, sizeof(game->first_bitmap_encoding), "%s",
                 dot ? dot + 1 : "");
    }
    wrote = agr_bitmap_draw(bitmap_slot->host,
                            slot->pixels,
                            slot->width,
                            slot->height,
                            (size_t)slot->row_bytes,
                            left,
                            top,
                            slot->clip_left,
                            slot->clip_top,
                            slot->clip_right,
                            slot->clip_bottom);
    if (vm->telemetry.telemetry_enabled && slot->save_count > 1) {
        agr_canvas_trace event;
        canvas_trace_begin(game, vm, frame, "drawBitmap", &event);
        event.left = left;
        event.top = top;
        event.save_count_after = slot->save_count;
        canvas_copy_clip(slot, event.clip_before);
        canvas_copy_clip(slot, event.clip_after);
        event.wrote = wrote < 0 ? 0 : wrote;
        event.has_write = 1;
        content_blit_bounds((int)agr_bitmap_width(bitmap_slot->host),
                            (int)agr_bitmap_height(bitmap_slot->host),
                            left, top,
                            slot->clip_left, slot->clip_top,
                            slot->clip_right, slot->clip_bottom,
                            slot->width, slot->height,
                            &event.write_left, &event.write_top,
                            &event.write_right, &event.write_bottom);
        canvas_trace_commit(game, vm, &event);
    }
    if (wrote < 0) return DX_OK;
    after = content_buffer_hash(slot->pixels, bytes);
    slot->draw_bitmap_count++;
    if (after != before) {
        if (wrote > 0) slot->pixel_change_count += (uint32_t)wrote;
        else slot->pixel_change_count++;
    }
    framework_event(game, "canvas.draw_bitmap");
    forensic_surface(AGR_PHYS_PHASE_DRAW_BITMAP_END, 1, dx_vm_current_exec(vm), slot,
                     slot->draw_bitmap_count - 1, slot->draw_bitmap_count, 1);
    if (after != before)
        forensic_surface(AGR_PHYS_PHASE_PIXEL_MUTATION, 0, dx_vm_current_exec(vm), slot,
                         0, slot->pixel_change_count, 1);
    return DX_OK;
}

static int view_int(DxObject *object, const char *name, int fallback) {
    DxValue value = DX_NULL_VALUE;
    return object && dx_vm_get_field(object, name, &value) == DX_OK &&
        value.tag == DX_VAL_INT ? value.i : fallback;
}

static int class_is_surface_view(DxClass *cls) {
    for (; cls; cls = cls->super_class)
        if (cls->descriptor && !strcmp(cls->descriptor, "Landroid/view/SurfaceView;"))
            return 1;
    return 0;
}

static struct agr_content_surface *content_slot_for_view(agr_dex_game *game, DxObject *view) {
    if (!game || !view) return NULL;
    for (uint32_t i = 0; i < game->content_surface_count; i++)
        if (game->content_surfaces[i].view == view) return &game->content_surfaces[i];
    return NULL;
}

static struct agr_content_surface *content_slot_for_holder(agr_dex_game *game, DxObject *holder) {
    if (!game || !holder) return NULL;
    for (uint32_t i = 0; i < game->content_surface_count; i++)
        if (game->content_surfaces[i].holder == holder) return &game->content_surfaces[i];
    return NULL;
}

static struct agr_content_surface *content_slot_new(agr_dex_game *game, DxObject *view) {
    struct agr_content_surface *slot = content_slot_for_view(game, view);
    if (slot || !game || !view || game->content_surface_count >= AGR_CONTENT_SURFACE_CAP)
        return slot;
    slot = &game->content_surfaces[game->content_surface_count++];
    memset(slot, 0, sizeof(*slot));
    slot->view = view;
    pthread_mutex_init(&slot->mu, NULL);
    pthread_cond_init(&slot->cv, NULL);
    slot->mutex_ready = 1;
    return slot;
}

/* API19 SurfaceView.updateWindow does not catch callback exceptions.
   A thrown callback stays pending on this execution context. The copy below
   is durable evidence. It is not guest success and it does not clear the
   exception. */
typedef enum {
    AGR_SURFACE_CALLBACK_OK = 0,
    AGR_SURFACE_CALLBACK_MISSING = 1,
    AGR_SURFACE_CALLBACK_THROW = 2,
    AGR_SURFACE_CALLBACK_EXEC_ERROR = 3
} agr_surface_callback_result;

static void content_surface_record_exception(agr_dex_game *game, DxVM *vm) {
    DxExecutionContext *exec;
    if (!game || !vm) return;
    exec = dx_vm_current_exec(vm);
    if (!exec || !exec->pending_exception || !exec->pending_exception->klass ||
        !exec->pending_exception->klass->descriptor) return;
    snprintf(game->content_surface_exception, sizeof(game->content_surface_exception),
             "%s", exec->pending_exception->klass->descriptor);
}

static const char *callback_result_token(agr_surface_callback_result result) {
    switch (result) {
    case AGR_SURFACE_CALLBACK_OK: return "CALLBACK_OK";
    case AGR_SURFACE_CALLBACK_MISSING: return "CALLBACK_MISSING";
    case AGR_SURFACE_CALLBACK_THROW: return "CALLBACK_THROW";
    case AGR_SURFACE_CALLBACK_EXEC_ERROR: return "CALLBACK_EXEC_ERROR";
    }
    return "CALLBACK_EXEC_ERROR";
}

static uint32_t callback_result_phase(agr_surface_callback_result result) {
    switch (result) {
    case AGR_SURFACE_CALLBACK_OK: return AGR_PHYS_PHASE_SURFACE_CALLBACK_OK;
    case AGR_SURFACE_CALLBACK_THROW: return AGR_PHYS_PHASE_SURFACE_CALLBACK_THROW;
    case AGR_SURFACE_CALLBACK_MISSING:
    case AGR_SURFACE_CALLBACK_EXEC_ERROR:
        return AGR_PHYS_PHASE_SURFACE_CALLBACK_EXEC_ERROR;
    }
    return AGR_PHYS_PHASE_SURFACE_CALLBACK_EXEC_ERROR;
}

static void arm_method_witness(DxVM *vm, uint32_t budget) {
    if (!vm || !vm->telemetry.telemetry_enabled) return;
    dx_vm_set_draw_witness(vm, budget);
}

static void publish_surface_callback(uint32_t phase, DxVM *vm, struct agr_content_surface *slot,
                                     DxObject *target, const char *name,
                                     const char *token, const char *exception_class,
                                     const char *when, int width, int height) {
    agr_forensic_sample sample = forensic_fill(phase, 0, vm ? dx_vm_current_exec(vm) : NULL,
                                               slot, 0, 0, 0);
    const char *cls = target && target->klass && target->klass->descriptor
        ? target->klass->descriptor : "";
    snprintf(sample.class_name, sizeof(sample.class_name), "%s", cls);
    snprintf(sample.method_name, sizeof(sample.method_name), "%s", name ? name : "");
    snprintf(sample.detail, sizeof(sample.detail), "%s;%s;%s;%d;%d",
             token ? token : "", exception_class ? exception_class : "",
             when ? when : "", width, height);
    forensic_publish(&sample);
}

static agr_surface_callback_result invoke_surface_callback(DxVM *vm, DxObject *callback,
                                                           const char *name, const char *shorty,
                                                           DxValue *args, uint32_t argc) {
    DxMethod *method;
    DxResult result;
    DxExecutionContext *exec;
    if (!vm || !callback || !callback->klass) return AGR_SURFACE_CALLBACK_MISSING;
    method = dx_vm_find_method(callback->klass, name, shorty);
    if (!method) return AGR_SURFACE_CALLBACK_MISSING;
    result = dx_vm_execute_method(vm, method, args, argc, NULL);
    exec = dx_vm_current_exec(vm);
    if (exec && exec->pending_exception) {
        content_surface_record_exception(game_from_vm(vm), vm);
        return AGR_SURFACE_CALLBACK_THROW;
    }
    if (result != DX_OK) return AGR_SURFACE_CALLBACK_EXEC_ERROR;
    return AGR_SURFACE_CALLBACK_OK;
}

static void note_callback_result(DxVM *vm, struct agr_content_surface *slot, DxObject *target,
                                 const char *name, agr_surface_callback_result result,
                                 const char *when, int width, int height) {
    const char *exception_class = "";
    DxExecutionContext *exec = vm ? dx_vm_current_exec(vm) : NULL;
    if (result == AGR_SURFACE_CALLBACK_THROW && exec && exec->pending_exception &&
        exec->pending_exception->klass && exec->pending_exception->klass->descriptor)
        exception_class = exec->pending_exception->klass->descriptor;
    publish_surface_callback(callback_result_phase(result), vm, slot, target, name,
                             callback_result_token(result), exception_class, when, width, height);
}

static void *content_pixels_alloc(agr_dex_game *game, size_t bytes) {
    if (game && game->content_surface_alloc) return game->content_surface_alloc(
        game->content_surface_alloc_user, bytes);
    return calloc(1, bytes);
}

static void content_pixels_free(agr_dex_game *game, void *pixels) {
    if (!pixels) return;
    if (game && game->content_surface_free)
        game->content_surface_free(game->content_surface_alloc_user, pixels);
    else free(pixels);
}

static void release_content_surfaces(agr_dex_game *game) {
    if (!game) return;
    for (uint32_t i = 0; i < game->content_surface_count; i++) {
        struct agr_content_surface *slot = &game->content_surfaces[i];
        if (slot->mutex_ready) {
            pthread_mutex_lock(&slot->mu);
            slot->canvas_locked = 0;
            pthread_cond_broadcast(&slot->cv);
            pthread_mutex_unlock(&slot->mu);
        }
        content_pixels_free(game, slot->pixels);
        slot->pixels = NULL;
        if (slot->mutex_ready) {
            pthread_cond_destroy(&slot->cv);
            pthread_mutex_destroy(&slot->mu);
            slot->mutex_ready = 0;
        }
    }
}

/* Layout size follows View.getDefaultSize for MATCH_PARENT and WRAP_CONTENT.
   updateWindow creates the child surface only after a positive frame and only
   while the window and the view are VISIBLE. surfaceCreated runs once;
   surfaceChanged follows on that creation and on a later size change. */
static void content_surface_lock(struct agr_content_surface *slot) {
    if (slot && slot->mutex_ready) pthread_mutex_lock(&slot->mu);
}

static void content_surface_unlock(struct agr_content_surface *slot) {
    if (slot && slot->mutex_ready) pthread_mutex_unlock(&slot->mu);
}

static void update_surface_view(DxVM *vm, agr_dex_game *game, DxObject *view,
                                int window_visible) {
    struct agr_content_surface *slot;
    DxObject *callbacks[AGR_SURFACE_CALLBACK_CAP];
    DxObject *holder = NULL;
    int width, height, visible, same, format;
    uint32_t count = 0;
    if (!class_is_surface_view(view->klass)) return;
    slot = content_slot_for_view(game, view);
    if (!slot) return;
    width = view_int(view, "_measuredWidth", 0);
    height = view_int(view, "_measuredHeight", 0);
    visible = window_visible && view_int(view, "_visibility", 0) == 0;
    if (!visible || width <= 0 || height <= 0) return;
    content_surface_lock(slot);
    /* A locked Canvas owns the backing. Replacement waits until unlock. */
    if (slot->canvas_locked) {
        content_surface_unlock(slot);
        return;
    }
    same = slot->created && slot->valid && slot->width == width && slot->height == height &&
        slot->format == AGR_PIXEL_FORMAT_RGB_565;
    if (same) {
        content_surface_unlock(slot);
        return;
    }
    if (!slot->created) {
        size_t bytes;
        void *pixels;
        content_surface_unlock(slot);
        if ((size_t)width > SIZE_MAX / (size_t)AGR_CONTENT_BYTES_PER_PIXEL / (size_t)height) {
            framework_event(game, "surface_view.allocation_failed");
            return;
        }
        bytes = (size_t)width * (size_t)height * (size_t)AGR_CONTENT_BYTES_PER_PIXEL;
        pixels = content_pixels_alloc(game, bytes);
        if (!pixels) {
            framework_event(game, "surface_view.allocation_failed");
            return;
        }
        memset(pixels, 0, bytes);
        content_surface_lock(slot);
        if (slot->canvas_locked || slot->created) {
            content_surface_unlock(slot);
            content_pixels_free(game, pixels);
            return;
        }
        slot->pixels = pixels;
        slot->hash_before_set = 0;
        slot->hash_before_lock = 0;
        slot->hash_after_post = 0;
        slot->generation++;
        slot->width = width;
        slot->height = height;
        slot->row_bytes = width * AGR_CONTENT_BYTES_PER_PIXEL;
        slot->format = AGR_PIXEL_FORMAT_RGB_565;
        slot->valid = 1;
        slot->created = 1;
        dx_vm_set_field(slot->surface, "_valid", DX_INT_VALUE(1));
        dx_vm_set_field(slot->surface, "_generation", DX_INT_VALUE((int32_t)slot->generation));
        dx_vm_set_field(slot->surface, "_width", DX_INT_VALUE(width));
        dx_vm_set_field(slot->surface, "_height", DX_INT_VALUE(height));
        count = slot->callback_count;
        if (count > AGR_SURFACE_CALLBACK_CAP) count = AGR_SURFACE_CALLBACK_CAP;
        memcpy(callbacks, slot->callbacks, sizeof(DxObject *) * count);
        holder = slot->holder;
        format = slot->format;
        content_surface_unlock(slot);
        framework_event(game, "surface_view.child_surface_created");
        for (uint32_t i = 0; i < count; i++) {
            DxValue args[5];
            agr_surface_callback_result created;
            agr_surface_callback_result changed;
            args[0] = DX_OBJ_VALUE(callbacks[i]);
            args[1] = DX_OBJ_VALUE(holder);
            publish_surface_callback(AGR_PHYS_PHASE_SURFACE_CALLBACK_BEGIN, vm, slot, callbacks[i],
                                     "surfaceCreated", "CALLBACK_BEGIN", "", "create", width, height);
            arm_method_witness(vm, 96);
            created = invoke_surface_callback(vm, callbacks[i], "surfaceCreated", "VL", args, 2);
            arm_method_witness(vm, 0);
            if (created == AGR_SURFACE_CALLBACK_OK) {
                content_surface_lock(slot);
                slot->created_count++;
                content_surface_unlock(slot);
            }
            note_callback_result(vm, slot, callbacks[i], "surfaceCreated", created, "create", width, height);
            if (created == AGR_SURFACE_CALLBACK_THROW) break;
            args[2] = DX_INT_VALUE(format);
            args[3] = DX_INT_VALUE(width);
            args[4] = DX_INT_VALUE(height);
            publish_surface_callback(AGR_PHYS_PHASE_SURFACE_CALLBACK_BEGIN, vm, slot, callbacks[i],
                                     "surfaceChanged", "CALLBACK_BEGIN", "", "create", width, height);
            arm_method_witness(vm, 96);
            changed = invoke_surface_callback(vm, callbacks[i], "surfaceChanged", "VLIII", args, 5);
            arm_method_witness(vm, 0);
            if (changed == AGR_SURFACE_CALLBACK_OK) {
                content_surface_lock(slot);
                slot->changed_count++;
                content_surface_unlock(slot);
            }
            note_callback_result(vm, slot, callbacks[i], "surfaceChanged", changed, "create", width, height);
            if (changed == AGR_SURFACE_CALLBACK_THROW) break;
        }
        content_surface_lock(slot);
        if (slot->created_count) framework_event(game, "surface_holder.surface_created");
        if (slot->changed_count) framework_event(game, "surface_holder.surface_changed");
        {
            agr_forensic_sample created;
            agr_forensic_sample changed;
            int note_created = slot->created_count != 0;
            int note_changed = slot->changed_count != 0;
            created = forensic_fill(AGR_PHYS_PHASE_SURFACE_CREATED, 1, dx_vm_current_exec(vm), slot, 0, slot->created_count, 1);
            changed = forensic_fill(AGR_PHYS_PHASE_SURFACE_CHANGED, 1, dx_vm_current_exec(vm), slot, 0, slot->changed_count, 1);
            content_surface_unlock(slot);
            if (note_created) forensic_publish(&created);
            if (note_changed) forensic_publish(&changed);
        }
        return;
    }
    slot->width = width;
    slot->height = height;
    slot->row_bytes = width * AGR_CONTENT_BYTES_PER_PIXEL;
    dx_vm_set_field(slot->surface, "_width", DX_INT_VALUE(width));
    dx_vm_set_field(slot->surface, "_height", DX_INT_VALUE(height));
    count = slot->callback_count;
    if (count > AGR_SURFACE_CALLBACK_CAP) count = AGR_SURFACE_CALLBACK_CAP;
    memcpy(callbacks, slot->callbacks, sizeof(DxObject *) * count);
    holder = slot->holder;
    format = slot->format;
    content_surface_unlock(slot);
    {
        uint32_t before;
        content_surface_lock(slot);
        before = slot->changed_count;
        content_surface_unlock(slot);
        for (uint32_t i = 0; i < count; i++) {
            DxValue args[5];
            agr_surface_callback_result changed;
            args[0] = DX_OBJ_VALUE(callbacks[i]);
            args[1] = DX_OBJ_VALUE(holder);
            args[2] = DX_INT_VALUE(format);
            args[3] = DX_INT_VALUE(width);
            args[4] = DX_INT_VALUE(height);
            publish_surface_callback(AGR_PHYS_PHASE_SURFACE_CALLBACK_BEGIN, vm, slot, callbacks[i],
                                     "surfaceChanged", "CALLBACK_BEGIN", "", "resize", width, height);
            arm_method_witness(vm, 96);
            changed = invoke_surface_callback(vm, callbacks[i], "surfaceChanged", "VLIII", args, 5);
            arm_method_witness(vm, 0);
            if (changed == AGR_SURFACE_CALLBACK_OK) {
                content_surface_lock(slot);
                slot->changed_count++;
                content_surface_unlock(slot);
            }
            note_callback_result(vm, slot, callbacks[i], "surfaceChanged", changed, "resize", width, height);
            if (changed == AGR_SURFACE_CALLBACK_THROW) break;
        }
        content_surface_lock(slot);
        if (slot->changed_count != before) {
            agr_forensic_sample changed = forensic_fill(AGR_PHYS_PHASE_SURFACE_CHANGED, 1,
                                                        dx_vm_current_exec(vm), slot, before, slot->changed_count, 1);
            framework_event(game, "surface_holder.surface_changed");
            content_surface_unlock(slot);
            forensic_publish(&changed);
        } else {
            content_surface_unlock(slot);
        }
    }
}

static int layout_dimension(int spec, int parent) {
    if (spec == -1 || spec == -2) return parent > 0 ? parent : 0;
    return spec > 0 ? spec : 0;
}

static void layout_content_tree(DxVM *vm, agr_dex_game *game, DxObject *view,
                                int parent_w, int parent_h, int window_visible) {
    int width, height;
    DxValue child = DX_NULL_VALUE;
    if (!view) return;
    width = layout_dimension(view_int(view, "_layoutWidth", -1), parent_w);
    height = layout_dimension(view_int(view, "_layoutHeight", -1), parent_h);
    dx_vm_set_field(view, "_measuredWidth", DX_INT_VALUE(width));
    dx_vm_set_field(view, "_measuredHeight", DX_INT_VALUE(height));
    dx_vm_set_field(view, "_left", DX_INT_VALUE(0));
    dx_vm_set_field(view, "_top", DX_INT_VALUE(0));
    dx_vm_set_field(view, "_right", DX_INT_VALUE(width));
    dx_vm_set_field(view, "_bottom", DX_INT_VALUE(height));
    update_surface_view(vm, game, view, window_visible);
    if (dx_vm_get_field(view, "_child", &child) == DX_OK && child.tag == DX_VAL_OBJ)
        for (DxObject *cursor = child.obj; cursor; ) {
            DxValue next = DX_NULL_VALUE;
            layout_content_tree(vm, game, cursor, width, height, window_visible);
            if (dx_vm_get_field(cursor, "_next", &next) != DX_OK || next.tag != DX_VAL_OBJ) break;
            cursor = next.obj;
        }
}

static struct agr_content_surface *first_content_surface(const agr_dex_game *game, DxObject *view) {
    struct agr_content_surface *slot;
    DxValue child = DX_NULL_VALUE;
    if (!game || !view) return NULL;
    for (uint32_t i = 0; i < game->content_surface_count; i++)
        if (game->content_surfaces[i].view == view) return (struct agr_content_surface *)&game->content_surfaces[i];
    if (dx_vm_get_field(view, "_child", &child) != DX_OK || child.tag != DX_VAL_OBJ) return NULL;
    for (DxObject *cursor = child.obj; cursor; ) {
        DxValue next = DX_NULL_VALUE;
        slot = first_content_surface(game, cursor);
        if (slot) return slot;
        if (dx_vm_get_field(cursor, "_next", &next) != DX_OK || next.tag != DX_VAL_OBJ) break;
        cursor = next.obj;
    }
    return NULL;
}

static void content_surface_pre_draw(DxVM *vm, agr_viewroot_attach_state *state, void *user) {
    agr_dex_game *game = user;
    int window_visible;
    if (!vm || !game || !state) return;
    window_visible = view_int(state->decor, "_visibility", 0) == 0;
    layout_content_tree(vm, game, game->content_view, state->measured_width,
                        state->measured_height, window_visible);
}

static DxResult surface_view_init(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    DxClass *holder_cls, *surface_cls;
    DxObject *holder, *surface;
    struct agr_content_surface *slot;
    (void)frame;
    if (count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_INVALID_FORMAT;
    if (!game) return DX_OK;
    slot = content_slot_new(game, args[0].obj);
    if (!slot) return DX_ERR_OUT_OF_MEMORY;
    if (slot->holder) return DX_OK;
    holder_cls = dx_vm_find_class(vm, "Landroid/view/SurfaceHolder;");
    surface_cls = dx_vm_find_class(vm, "Landroid/view/Surface;");
    holder = holder_cls ? dx_vm_alloc_object(vm, holder_cls) : NULL;
    surface = surface_cls ? dx_vm_alloc_object(vm, surface_cls) : NULL;
    if (!holder || !surface) return DX_ERR_OUT_OF_MEMORY;
    dx_vm_set_field(surface, "_valid", DX_INT_VALUE(0));
    dx_vm_set_field(surface, "_generation", DX_INT_VALUE(0));
    dx_vm_set_field(surface, "_width", DX_INT_VALUE(0));
    dx_vm_set_field(surface, "_height", DX_INT_VALUE(0));
    dx_vm_set_field(holder, "_surface", DX_OBJ_VALUE(surface));
    dx_vm_set_field(args[0].obj, "_holder", DX_OBJ_VALUE(holder));
    slot->holder = holder;
    slot->surface = surface;
    return DX_OK;
}

static DxResult surface_view_get_holder(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    DxValue holder = DX_NULL_VALUE;
    (void)vm;
    if (!frame || count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_INVALID_FORMAT;
    dx_vm_get_field(args[0].obj, "_holder", &holder);
    frame->result = holder.tag == DX_VAL_OBJ ? holder : DX_NULL_VALUE;
    frame->has_result = true;
    return DX_OK;
}

static DxResult surface_holder_add_callback(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    (void)frame;
    if (count < 2 || args[0].tag != DX_VAL_OBJ || !args[0].obj ||
        args[1].tag != DX_VAL_OBJ || !args[1].obj) return DX_ERR_INVALID_FORMAT;
    slot = content_slot_for_holder(game, args[0].obj);
    if (!slot) return DX_ERR_INVALID_FORMAT;
    for (uint32_t i = 0; i < slot->callback_count; i++)
        if (slot->callbacks[i] == args[1].obj) return DX_OK;
    if (slot->callback_count >= AGR_SURFACE_CALLBACK_CAP) return DX_ERR_OUT_OF_MEMORY;
    slot->callbacks[slot->callback_count++] = args[1].obj;
    framework_event(game, "surface_holder.callback_added");
    return DX_OK;
}

static DxResult surface_holder_remove_callback(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    (void)frame;
    if (count < 2 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_INVALID_FORMAT;
    slot = content_slot_for_holder(game, args[0].obj);
    if (!slot || args[1].tag != DX_VAL_OBJ) return DX_OK;
    for (uint32_t i = 0; i < slot->callback_count; i++) {
        if (slot->callbacks[i] != args[1].obj) continue;
        slot->callbacks[i] = slot->callbacks[slot->callback_count - 1];
        slot->callbacks[slot->callback_count - 1] = NULL;
        slot->callback_count--;
        framework_event(game, "surface_holder.callback_removed");
        return DX_OK;
    }
    return DX_OK;
}

static DxResult surface_holder_get_surface(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    (void)vm;
    if (!frame || count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_INVALID_FORMAT;
    slot = content_slot_for_holder(game, args[0].obj);
    frame->result = slot && slot->surface ? DX_OBJ_VALUE(slot->surface) : DX_NULL_VALUE;
    frame->has_result = true;
    return DX_OK;
}

static DxResult surface_holder_get_surface_frame(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    DxClass *rect_cls;
    DxObject *rect;
    int width = 0, height = 0;
    if (!frame || count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_INVALID_FORMAT;
    slot = content_slot_for_holder(game, args[0].obj);
    if (slot && slot->created) { width = slot->width; height = slot->height; }
    rect_cls = dx_vm_find_class(vm, "Landroid/graphics/Rect;");
    rect = rect_cls ? dx_vm_alloc_object(vm, rect_cls) : NULL;
    if (!rect) return DX_ERR_OUT_OF_MEMORY;
    dx_vm_set_field(rect, "left", DX_INT_VALUE(0));
    dx_vm_set_field(rect, "top", DX_INT_VALUE(0));
    dx_vm_set_field(rect, "right", DX_INT_VALUE(width));
    dx_vm_set_field(rect, "bottom", DX_INT_VALUE(height));
    frame->result = DX_OBJ_VALUE(rect);
    frame->has_result = true;
    return DX_OK;
}

/* Lock order: the host surface mutex is not held across guest bytecode, a
   Java monitor, or the VM shared lock. Callers may hold a Java monitor and
   then call lockCanvas. Allocation takes the VM lock only while the surface
   mutex is released. UI replacement waits on the canvas_locked flag. */
static int64_t content_now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (int64_t)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

static void content_safepoint_sleep(DxExecutionContext *exec, int64_t millis) {
    while (millis > 0 && exec && !exec->stop_requested) {
        uint32_t slice = millis > 10 ? 10 : (uint32_t)millis;
        struct timespec ts;
        ts.tv_sec = slice / 1000;
        ts.tv_nsec = (long)(slice % 1000) * 1000000L;
        __atomic_store_n(&exec->at_safepoint, 1, __ATOMIC_RELEASE);
        nanosleep(&ts, NULL);
        __atomic_store_n(&exec->at_safepoint, 0, __ATOMIC_RELEASE);
        millis -= slice;
    }
}

static uint64_t content_buffer_hash(const void *pixels, size_t bytes) {
    const uint8_t *cursor = pixels;
    uint64_t hash = 14695981039346656037ull;
    if (!cursor) return 0;
    for (size_t i = 0; i < bytes; i++) {
        hash ^= cursor[i];
        hash *= 1099511628211ull;
    }
    return hash;
}

static void content_bind_canvas(struct agr_content_surface *slot, DxObject *canvas) {
    dx_vm_set_field(canvas, "_width", DX_INT_VALUE(slot->width));
    dx_vm_set_field(canvas, "_height", DX_INT_VALUE(slot->height));
    dx_vm_set_field(canvas, "_rowBytes", DX_INT_VALUE(slot->row_bytes));
    dx_vm_set_field(canvas, "_generation", DX_INT_VALUE((int32_t)slot->generation));
    dx_vm_set_field(canvas, "_format", DX_INT_VALUE(slot->format));
    dx_vm_set_field(canvas, "_locked", DX_INT_VALUE(1));
}

static int content_clip_from_rect(DxObject *rect, int width, int height,
                                  int *left, int *top, int *right, int *bottom) {
    int values[4];
    const char *names[] = { "left", "top", "right", "bottom" };
    *left = 0;
    *top = 0;
    *right = width;
    *bottom = height;
    if (!rect) return 1;
    for (int i = 0; i < 4; i++) {
        DxValue value = DX_NULL_VALUE;
        if (dx_vm_get_field(rect, names[i], &value) != DX_OK || value.tag != DX_VAL_INT)
            return 0;
        values[i] = value.i;
    }
    if (values[2] < values[0] || values[3] < values[1]) return 0;
    if (values[0] > *left) *left = values[0];
    if (values[1] > *top) *top = values[1];
    if (values[2] < *right) *right = values[2];
    if (values[3] < *bottom) *bottom = values[3];
    if (*left < 0) *left = 0;
    if (*top < 0) *top = 0;
    if (*right > width) *right = width;
    if (*bottom > height) *bottom = height;
    return *right >= *left && *bottom >= *top;
}

static void content_lock_failure_throttle(struct agr_content_surface *slot,
                                          DxExecutionContext *exec) {
    int64_t now = content_now_ms();
    int64_t wait = 0;
    if (slot->last_lock_fail_ms != 0) {
        int64_t next = slot->last_lock_fail_ms + 100;
        if (next > now) wait = next - now;
    }
    slot->last_lock_fail_ms = now + wait;
    content_surface_unlock(slot);
    if (wait > 0) content_safepoint_sleep(exec, wait);
}

static DxResult surface_holder_lock_canvas(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    DxExecutionContext *exec = dx_vm_current_exec(vm);
    DxObject *rect = NULL;
    DxObject *canvas = NULL;
    int left, top, right, bottom;
    if (!frame) return DX_ERR_INVALID_FORMAT;
    frame->result = DX_NULL_VALUE;
    frame->has_result = true;
    if (count < 1 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_NULL_PTR;
    if (count >= 2 && args[1].tag == DX_VAL_OBJ) rect = args[1].obj;
    slot = content_slot_for_holder(game, args[0].obj);
    if (!slot || !exec) return DX_OK;
    forensic_surface(AGR_PHYS_PHASE_CANVAS_LOCK_BEGIN, 0, exec, slot, slot->lock_count, slot->lock_count, 1);
    content_surface_lock(slot);
    while (slot->canvas_locked && slot->lock_owner_exec != exec->id && !exec->stop_requested) {
        struct timespec ts;
        __atomic_store_n(&exec->at_safepoint, 1, __ATOMIC_RELEASE);
        clock_gettime(CLOCK_REALTIME, &ts);
        ts.tv_nsec += 10000000L;
        if (ts.tv_nsec >= 1000000000L) {
            ts.tv_sec += 1;
            ts.tv_nsec -= 1000000000L;
        }
        pthread_cond_timedwait(&slot->cv, &slot->mu, &ts);
        __atomic_store_n(&exec->at_safepoint, 0, __ATOMIC_RELEASE);
    }
    if (exec->stop_requested) {
        content_surface_unlock(slot);
        return DX_OK;
    }
    if (slot->canvas_locked && slot->lock_owner_exec == exec->id) {
        /* SurfaceView swallows Surface's already-locked exception and returns null. */
        content_lock_failure_throttle(slot, exec);
        forensic_surface(AGR_PHYS_PHASE_CANVAS_LOCK_FAILED, 1, exec, slot, 0, 0, 0);
        return DX_OK;
    }
    if (!slot->valid || !slot->pixels || !slot->created || slot->width <= 0 || slot->height <= 0) {
        content_lock_failure_throttle(slot, exec);
        forensic_surface(AGR_PHYS_PHASE_CANVAS_LOCK_FAILED, 1, exec, slot, 0, 0, 0);
        return DX_OK;
    }
    if (!content_clip_from_rect(rect, slot->width, slot->height, &left, &top, &right, &bottom)) {
        content_lock_failure_throttle(slot, exec);
        forensic_surface(AGR_PHYS_PHASE_CANVAS_LOCK_FAILED, 1, exec, slot, 0, 0, 0);
        return DX_OK;
    }
    if (!slot->canvas) {
        DxClass *canvas_cls;
        content_surface_unlock(slot);
        canvas_cls = dx_vm_find_class(vm, "Landroid/graphics/Canvas;");
        canvas = canvas_cls ? dx_vm_alloc_object(vm, canvas_cls) : NULL;
        content_surface_lock(slot);
        if (!canvas) {
            content_surface_unlock(slot);
            forensic_surface(AGR_PHYS_PHASE_CANVAS_LOCK_FAILED, 1, exec, slot, 0, 0, 0);
            return DX_ERR_OUT_OF_MEMORY;
        }
        if (!slot->canvas) slot->canvas = canvas;
    }
    if (slot->canvas_locked || !slot->valid || !slot->pixels) {
        content_lock_failure_throttle(slot, exec);
        forensic_surface(AGR_PHYS_PHASE_CANVAS_LOCK_FAILED, 1, exec, slot, 0, 0, 0);
        return DX_OK;
    }
    slot->clip_left = left;
    slot->clip_top = top;
    slot->clip_right = right;
    slot->clip_bottom = bottom;
    memset(slot->save_stack, 0, sizeof(slot->save_stack));
    slot->save_count = 1;
    slot->canvas_locked = 1;
    slot->lock_owner_exec = exec->id;
    slot->lock_owner_host = exec->has_host_thread ? (uint64_t)(uintptr_t)exec->host_thread : 0;
    slot->locked_generation = slot->generation;
    slot->lock_count++;
    /* Keep the first lock of this buffer. A later lock would replace the
       pre-draw hash with the already posted pixels and hide a real mutation. */
    if (!slot->hash_before_set) {
        slot->hash_before_lock = content_buffer_hash(slot->pixels,
            (size_t)slot->width * (size_t)slot->height * (size_t)AGR_CONTENT_BYTES_PER_PIXEL);
        slot->hash_before_set = 1;
    }
    content_bind_canvas(slot, slot->canvas);
    frame->result = DX_OBJ_VALUE(slot->canvas);
    {
        agr_forensic_sample locked = forensic_fill(AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED, 1, exec, slot,
                                                   slot->lock_count - 1, slot->lock_count, 1);
        content_surface_unlock(slot);
        forensic_publish(&locked);
    }
    if (game && !game->draw_witness_locked_once) {
        arm_method_witness(vm, 64);
        game->draw_witness_locked_once = 1;
        dx_vm_forensic_exec_snapshot(vm, "lock_canvas");
    }
    framework_event(game, "surface_holder.canvas_locked");
    return DX_OK;
}

static DxResult surface_holder_unlock_canvas(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    struct agr_content_surface *slot;
    DxObject *canvas;
    (void)frame;
    if (count < 2 || args[0].tag != DX_VAL_OBJ || !args[0].obj) return DX_ERR_NULL_PTR;
    canvas = args[1].tag == DX_VAL_OBJ ? args[1].obj : NULL;
    slot = content_slot_for_holder(game, args[0].obj);
    forensic_surface(AGR_PHYS_PHASE_CANVAS_POST_BEGIN, 1, dx_vm_current_exec(vm), slot, 0, 0, 0);
    if (game && !game->exec_snapshot_post_once) {
        game->exec_snapshot_post_once = 1;
        dx_vm_forensic_exec_snapshot(vm, "post_begin");
    }
    if (!slot) {
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/IllegalArgumentException;", "canvas object must be the locked instance");
        return DX_ERR_EXCEPTION;
    }
    content_surface_lock(slot);
    if (!canvas || canvas != slot->canvas) {
        content_surface_unlock(slot);
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/IllegalArgumentException;",
            "canvas object must be the same instance that was previously returned by lockCanvas");
        return DX_ERR_EXCEPTION;
    }
    if (!slot->canvas_locked) {
        content_surface_unlock(slot);
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/IllegalStateException;", "Surface was not locked");
        return DX_ERR_EXCEPTION;
    }
    if (slot->locked_generation != slot->generation || !slot->pixels) {
        slot->canvas_locked = 0;
        memset(slot->save_stack, 0, sizeof(slot->save_stack));
        slot->save_count = 1;
        dx_vm_set_field(canvas, "_locked", DX_INT_VALUE(0));
        pthread_cond_broadcast(&slot->cv);
        content_surface_unlock(slot);
        dx_vm_current_exec(vm)->pending_exception = dx_vm_create_exception(
            vm, "Ljava/lang/IllegalStateException;", "Surface generation changed while locked");
        return DX_ERR_EXCEPTION;
    }
    slot->hash_after_post = content_buffer_hash(slot->pixels,
        (size_t)slot->width * (size_t)slot->height * (size_t)AGR_CONTENT_BYTES_PER_PIXEL);
    slot->post_count++;
    slot->unlock_count++;
    slot->last_post_generation = slot->generation;
    slot->canvas_locked = 0;
    memset(slot->save_stack, 0, sizeof(slot->save_stack));
    slot->save_count = 1;
    slot->clip_left = 0;
    slot->clip_top = 0;
    slot->clip_right = slot->width;
    slot->clip_bottom = slot->height;
    dx_vm_set_field(canvas, "_locked", DX_INT_VALUE(0));
    pthread_cond_broadcast(&slot->cv);
    {
        agr_forensic_sample posted = forensic_fill(AGR_PHYS_PHASE_CANVAS_POST_END, 1, dx_vm_current_exec(vm), slot,
                                                   slot->post_count - 1, slot->post_count, 1);
        content_surface_unlock(slot);
        forensic_publish(&posted);
    }
    if (slot->post_count == 1) dx_vm_forensic_exec_snapshot(vm, "post_end");
    arm_method_witness(vm, 0);
    framework_event(game, "surface_holder.canvas_posted");
    return DX_OK;
}

static DxResult view_request_layout(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    agr_dex_game *game = game_from_vm(vm);
    (void)frame; (void)args; (void)count;
    if (game && game->viewroot.attach_complete)
        agr_viewroot_request_layout(&game->viewroot, viewroot_event, game);
    return DX_OK;
}

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
    game->viewroot.pre_draw = content_surface_pre_draw;
    game->viewroot.pre_draw_user = game;
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
        snprintf(game->launch_error,sizeof(game->launch_error),"Application.onCreate failed: %s",dx_vm_current_exec(vm)->error_msg);
        return -1;
    }

    DxClass *cls=game->activity_class;
    DxMethod *init=dx_vm_find_method(cls,"<init>","V");
    DxValue init_args[1]={DX_OBJ_VALUE(game->activity)};
    if (!init || dx_vm_execute_method(vm,init,init_args,1,NULL)!=DX_OK) {
        snprintf(game->launch_error,sizeof(game->launch_error),"Activity constructor failed: %s",dx_vm_current_exec(vm)->error_msg);
        return -1;
    }
    dx_vm_set_field(game->activity,"_baseContext",DX_OBJ_VALUE(game->activity_context));
    dx_vm_set_field(game->activity,"_application",DX_OBJ_VALUE(game->application));
    dx_vm_set_field(game->activity,"_intent",DX_OBJ_VALUE(game->intent));
    dx_vm_set_field(game->window,"_decor",DX_OBJ_VALUE(game->decor));
    dx_vm_set_field(game->window,"_attributes",DX_OBJ_VALUE(game->window_attributes));
    store_window_features(game->window, AGR_DEFAULT_WINDOW_FEATURES);
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
        snprintf(game->launch_error,sizeof(game->launch_error),"Activity.onCreate failed: %s",dx_vm_current_exec(vm)->error_msg);
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
        snprintf(game->launch_error,sizeof(game->launch_error),"Activity.onPostResume failed: %s",dx_vm_current_exec(vm)->error_msg);
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
             "ActivityThread window visibility cluster failed: %s",dx_vm_current_exec(vm)->error_msg);
    return -1;
}

void agr_dex_game_enable_diagnostics(agr_dex_game *game, int enabled) {
    if (!game || !game->vm) return;
    dx_vm_set_telemetry_enabled(game->vm, enabled != 0);
}

struct DxVM *agr_dex_game_vm(const agr_dex_game *game) {
    return game ? game->vm : NULL;
}

void *agr_dex_game_content_holder(const agr_dex_game *game) {
    if (!game || game->content_surface_count == 0) return NULL;
    return game->content_surfaces[0].holder;
}

int agr_dex_game_content_clip(const agr_dex_game *game, int *left, int *top,
                              int *right, int *bottom, int *save_count) {
    const struct agr_content_surface *slot;
    if (!game || game->content_surface_count == 0) return -1;
    slot = &game->content_surfaces[0];
    if (left) *left = slot->clip_left;
    if (top) *top = slot->clip_top;
    if (right) *right = slot->clip_right;
    if (bottom) *bottom = slot->clip_bottom;
    if (save_count) *save_count = slot->save_count;
    return 0;
}

int agr_dex_game_content_pixel(const agr_dex_game *game, int x, int y, uint32_t *pixel) {
    const struct agr_content_surface *slot;
    const uint8_t *bytes;
    size_t offset;
    if (!game || !pixel || game->content_surface_count == 0) return -1;
    slot = &game->content_surfaces[0];
    if (!slot->pixels || x < 0 || y < 0 || x >= slot->width || y >= slot->height) return -1;
    bytes = slot->pixels;
    offset = (size_t)y * (size_t)slot->row_bytes + (size_t)x * 4u;
    memcpy(pixel, bytes + offset, 4);
    return 0;
}

uint32_t agr_dex_game_canvas_trace_count(const agr_dex_game *game) {
    return game ? game->canvas_trace_count : 0;
}

int agr_dex_game_copy_canvas_trace(const agr_dex_game *game, uint32_t index,
                                   agr_canvas_trace *out) {
    if (!game || !out || index >= game->canvas_trace_count) return -1;
    *out = game->canvas_trace[index];
    return 0;
}

int agr_dex_game_diagnostic_content_lock_busy(const agr_dex_game *game) {
    uint32_t i;
    if (!game) return 0;
    for (i = 0; i < game->content_surface_count && i < AGR_CONTENT_SURFACE_CAP; i++) {
        struct agr_content_surface *slot =
            (struct agr_content_surface *)&game->content_surfaces[i];
        int rc;
        if (!slot->mutex_ready) continue;
        rc = pthread_mutex_trylock(&slot->mu);
        if (rc == 0) {
            pthread_mutex_unlock(&slot->mu);
            continue;
        }
        if (rc == EBUSY) return 1;
    }
    return 0;
}

int agr_dex_game_runtime_snapshot(const agr_dex_game *game, agr_dex_runtime_snapshot *snapshot) {
    if (!game || !game->vm || !snapshot) return -1;
    DxVM *vm=game->vm;
    memset(snapshot,0,sizeof(*snapshot));
    snapshot->methods_invoked=vm->telemetry.total_methods_invoked;
    snapshot->instructions_executed=vm->insn_total;
    snapshot->stack_depth=dx_vm_current_exec(vm)->stack_depth;
    snapshot->vm_running=vm->running ? 1 : 0;
    snapshot->pending_exception=dx_vm_current_exec(vm)->pending_exception ? 1 : 0;
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
    snapshot->draw_count=game->viewroot.draw_count;
    snapshot->content_view_installed=game->content_view!=NULL;
    snapshot->content_layout_width=game->content_view ? game->content_width : 0;
    snapshot->content_layout_height=game->content_view ? game->content_height : 0;
    snapshot->content_child_count=game->content_view ? game->content_child_count : 0;
    snapshot->content_first_child_id=game->content_view ? game->content_first_child_id : 0;
    {
        struct agr_content_surface *slot = first_content_surface(game, game->content_view);
        snapshot->root_surface_identity=(uint64_t)(uintptr_t)game->viewroot.surface;
        if (slot) {
            content_surface_lock(slot);
            snapshot->content_surface_valid=slot->valid;
            snapshot->content_surface_generation=slot->generation;
            snapshot->content_surface_width=slot->width;
            snapshot->content_surface_height=slot->height;
            snapshot->content_surface_format=slot->format;
            snapshot->content_surface_callback_count=slot->callback_count;
            snapshot->content_surface_created_count=slot->created_count;
            snapshot->content_surface_changed_count=slot->changed_count;
            snapshot->content_surface_identity=(uint64_t)(uintptr_t)slot->surface;
            snapshot->content_surface_owner_id=view_int(slot->view, "_id", 0);
            snapshot->canvas_lock_count=slot->lock_count;
            snapshot->canvas_unlock_count=slot->unlock_count;
            snapshot->canvas_post_count=slot->post_count;
            snapshot->canvas_locked=slot->canvas_locked;
            snapshot->canvas_lock_owner_exec=slot->lock_owner_exec;
            snapshot->canvas_locked_generation=slot->locked_generation;
            snapshot->canvas_last_post_generation=slot->last_post_generation;
            snapshot->canvas_row_bytes=slot->row_bytes;
            snapshot->canvas_buffer_hash_before=slot->hash_before_lock;
            snapshot->canvas_buffer_hash_after=slot->hash_after_post;
            snapshot->canvas_pixel_change_count=slot->pixel_change_count;
            snapshot->canvas_draw_bitmap_count=slot->draw_bitmap_count;
            snapshot->canvas_identity=(uint64_t)(uintptr_t)slot->canvas;
            snapshot->canvas_lock_owner_host=slot->lock_owner_host;
            content_surface_unlock(slot);
        }
        snapshot->bitmap_guest_identity=game->first_bitmap_guest;
        snapshot->bitmap_host_identity=game->first_bitmap_host;
        snapshot->bitmap_width=game->first_bitmap_width;
        snapshot->bitmap_height=game->first_bitmap_height;
        snprintf(snapshot->bitmap_path, sizeof(snapshot->bitmap_path), "%s", game->first_bitmap_path);
        snprintf(snapshot->bitmap_encoding, sizeof(snapshot->bitmap_encoding), "%s",
                 game->first_bitmap_encoding);
        snprintf(snapshot->content_surface_exception, sizeof(snapshot->content_surface_exception),
                 "%s", game->content_surface_exception);
    }
    snprintf(snapshot->last_method,sizeof(snapshot->last_method),"%s",dx_vm_current_exec(vm)->diagnostic_last_method);
    snprintf(snapshot->error,sizeof(snapshot->error),"%s",dx_vm_current_exec(vm)->error_msg);
    uint32_t method_count=dx_vm_current_exec(vm)->diagnostic_method_event_count;
    uint64_t method_start=dx_vm_current_exec(vm)->diagnostic_method_sequence > method_count
        ? dx_vm_current_exec(vm)->diagnostic_method_sequence - method_count : 0;
    snapshot->method_event_count=method_count;
    for (uint32_t i=0;i<method_count;i++) {
        const DxDiagnosticMethodEvent *source=
            &dx_vm_current_exec(vm)->diagnostic_method_events[(method_start+i)%DX_DIAGNOSTIC_METHOD_EVENTS];
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
    snapshot->feature_event_count = game->feature_event_count < AGR_FEATURE_EVENT_CAP
        ? game->feature_event_count : AGR_FEATURE_EVENT_CAP;
    for (uint32_t i = 0; i < snapshot->feature_event_count; i++)
        snprintf(snapshot->feature_events[i], sizeof(snapshot->feature_events[i]), "%s",
                 game->feature_events[i]);
    snapshot->intent_event_count = game->intent_event_count < AGR_INTENT_EVENT_CAP
        ? game->intent_event_count : AGR_INTENT_EVENT_CAP;
    for (uint32_t i = 0; i < snapshot->intent_event_count; i++)
        snprintf(snapshot->intent_events[i], sizeof(snapshot->intent_events[i]), "%s",
                 game->intent_events[i]);
    if (dx_vm_current_exec(vm)->pending_exception && dx_vm_current_exec(vm)->pending_exception->klass &&
        dx_vm_current_exec(vm)->pending_exception->klass->descriptor)
        snprintf(snapshot->exception_class,sizeof(snapshot->exception_class),"%s",
                 dx_vm_current_exec(vm)->pending_exception->klass->descriptor);
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
    for (uint32_t i = 0; i < game->layout_count; i++) free(game->layouts[i].xml);
    free(game->layouts);
    dx_resources_free(game->resources);
    /* Join workers before freeing a buffer a Canvas lock may still name.
       stop_requested unblocks a waiter on the next 10ms surface-cond slice. */
    agr_viewroot_release(&game->viewroot);
    if (game->vm) dx_vm_destroy(game->vm);
    game->vm = NULL;
    release_guest_bitmaps(game);
    release_content_surfaces(game);
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

int agr_dex_game_set_host_display(agr_dex_game *game, uint32_t width, uint32_t height) {
    if (!game || !width || !height || width > INT32_MAX || height > INT32_MAX) return -1;
    game->host_display_width = width;
    game->host_display_height = height;
    return 0;
}

int agr_dex_game_set_content_view(agr_dex_game *game) {
    if (!game || !game->vm || !game->activity) return -1;
    DxClass *view_class = dx_vm_find_class(game->vm, "Landroid/view/View;");
    DxObject *view = view_class ? dx_vm_alloc_object(game->vm, view_class) : NULL;
    DxClass *activity = dx_vm_find_class(game->vm, "Landroid/app/Activity;");
    DxMethod *method = activity ? dx_vm_find_method(activity, "setContentView", "VL") : NULL;
    if (!view || !method) return -1;
    DxValue args[2] = {DX_OBJ_VALUE(game->activity), DX_OBJ_VALUE(view)};
    return dx_vm_execute_method(game->vm, method, args, 2, NULL) == DX_OK ? 0 : -1;
}

int agr_dex_game_provide_layout(agr_dex_game *game, uint32_t layout_id,
                                const void *xml, uint32_t size) {
    uint8_t *copy;
    if (!game || !xml || !size || !layout_id) return -1;
    copy = malloc(size);
    if (!copy) return -1;
    memcpy(copy, xml, size);
    for (uint32_t i = 0; i < game->layout_count; i++) {
        if (game->layouts[i].id == layout_id) {
            free(game->layouts[i].xml);
            game->layouts[i].xml = copy;
            game->layouts[i].size = size;
            return 0;
        }
    }
    void *grown = realloc(game->layouts, sizeof(*game->layouts) * (game->layout_count + 1));
    if (!grown) { free(copy); return -1; }
    game->layouts = grown;
    game->layouts[game->layout_count].id = layout_id;
    game->layouts[game->layout_count].xml = copy;
    game->layouts[game->layout_count].size = size;
    game->layout_count++;
    return 0;
}

int agr_dex_game_set_content_layout(agr_dex_game *game, uint32_t layout_id) {
    DxClass *activity;
    DxMethod *method;
    DxValue args[2];
    if (!game || !game->vm || !game->activity || !layout_id) return -1;
    activity = dx_vm_find_class(game->vm, "Landroid/app/Activity;");
    method = activity ? dx_vm_find_method(activity, "setContentView", "VI") : NULL;
    if (!method) return -1;
    args[0] = DX_OBJ_VALUE(game->activity);
    args[1] = DX_INT_VALUE((int32_t)layout_id);
    return dx_vm_execute_method(game->vm, method, args, 2, NULL) == DX_OK ? 0 : -1;
}

static void load_apk_layouts(agr_dex_game *game, const agr_apk_package *package) {
    const DxZipEntry *entry = NULL;
    uint8_t *table = NULL;
    uint32_t table_size = 0;
    DxResources *resources = NULL;
    if (!game || !package || !package->apk) return;
    if (dx_apk_find_entry(package->apk, "resources.arsc", &entry) != DX_OK ||
        dx_apk_extract_entry(package->apk, entry, &table, &table_size) != DX_OK)
        return;
    if (dx_resources_parse(table, table_size, &resources) != DX_OK) {
        dx_free(table);
        return;
    }
    dx_free(table);
    for (uint32_t i = 0; resources && i < resources->layout_entry_count; i++) {
        const char *filename = resources->layout_entries[i].filename;
        const DxZipEntry *xml_entry = NULL;
        uint8_t *xml = NULL;
        uint32_t xml_size = 0;
        if (!filename || dx_apk_find_entry(package->apk, filename, &xml_entry) != DX_OK ||
            dx_apk_extract_entry(package->apk, xml_entry, &xml, &xml_size) != DX_OK)
            continue;
        agr_dex_game_provide_layout(game, resources->layout_entries[i].id, xml, xml_size);
        dx_free(xml);
    }
    game->resource_apk = package->apk;
    game->resources = resources;
}

int agr_dex_game_choreographer_frame(agr_dex_game *game) {
    if (!game || !game->vm || game->choreographer_in_frame) return -1;
    int scheduled = game->viewroot.pending_first_traversal &&
        game->viewroot.traversal_phase == AGR_TRAVERSAL_SCHEDULED;
    if (scheduled && (!game->host_display_width || !game->host_display_height)) return -1;
    game->choreographer_in_frame = 1;
    agr_viewroot_display display = { game->host_display_width, game->host_display_height };
    DxResult result = agr_viewroot_choreographer_frame(game->vm, &game->viewroot,
                                                       display, viewroot_event, game);
    game->choreographer_in_frame = 0;
    if (result != DX_OK) {
        snprintf(game->launch_error, sizeof(game->launch_error),
                 "host traversal frame failed: %d", (int)result);
        return -1;
    }
    return scheduled ? 0 : 1;
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

int agr_dex_game_set_content_surface_allocator(agr_dex_game *game,
                                              void *(*allocate)(void *, size_t),
                                              void (*release)(void *, void *), void *user) {
    if (!game || !!allocate != !!release) return -1;
    for (uint32_t i = 0; i < game->content_surface_count; i++)
        if (game->content_surfaces[i].pixels) return -1;
    game->content_surface_alloc = allocate;
    game->content_surface_free = release;
    game->content_surface_alloc_user = user;
    return 0;
}

int agr_dex_game_set_relayout_gate(agr_dex_game *game,
                                   int (*gate)(void *, uint32_t, uint32_t, int),
                                   void *user) {
    if (!game) return -1;
    game->viewroot.relayout_gate = gate;
    game->viewroot.relayout_user = user;
    return 0;
}

int agr_dex_game_root_surface(agr_dex_game *game, void **pixels,
                              uint32_t *width, uint32_t *height,
                              uint32_t *stride, uint32_t *generation) {
    if (!game || !pixels || !width || !height || !stride || !generation ||
        !agr_viewroot_surface_valid(&game->viewroot)) return -1;
    *pixels = game->viewroot.backing.pixels;
    *width = game->viewroot.backing.width;
    *height = game->viewroot.backing.height;
    *stride = game->viewroot.backing.stride;
    *generation = game->viewroot.backing.generation;
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
    agr_dex_game *game = package ? create_game(package->dex_bytes, package->dex_size,
        package->activity_descriptor, package->application_descriptor,
        package->manifest->package_name) : NULL;
    if (game && game->vm) load_apk_layouts(game, package);
    return game;
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
