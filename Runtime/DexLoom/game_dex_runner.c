#include "dx_vm.h"
#include "dx_dex.h"
#include "dx_memory.h"
#include "dx_apk.h"
#include "dx_manifest.h"
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
static int32_t g_next_sound = 1;
static char g_package_name[256];

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
    DxClass *native_activity = reg_class(vm, "Landroid/app/NativeActivity;", context);
    add_method(native_activity, "<init>", "V", DX_ACC_PUBLIC | DX_ACC_CONSTRUCTOR, noop, 1);
    add_method(native_activity, "onCreate", "VL", DX_ACC_PUBLIC, noop, 0);
    add_method(context, "getAssets", "L", DX_ACC_PUBLIC, context_get_assets, 0);
    add_method(context, "getResources", "L", DX_ACC_PUBLIC, context_get_resources, 0);
    add_method(context, "getPackageName", "L", DX_ACC_PUBLIC, context_get_package_name, 0);

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
    agr_dex_native_callback native_callback;
    void *native_callback_user;
    struct { uint32_t handle; DxObject *object; } *objects;
    uint32_t object_count, object_capacity;
};

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
    if (!package->activity_descriptor || !package->native_library ||
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
    if (!package->library_count) goto fail;
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
    free(package->libraries); free(package->activity_descriptor); free(package->native_library);
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
        register_game_framework(game->vm)!=DX_OK ||
        dx_vm_load_class(game->vm,activity_descriptor,&cls)!=DX_OK || !cls)
        goto fail;
    game->activity_class=cls;
    game->activity=dx_vm_alloc_object(game->vm,cls);
    if (!game->activity) goto fail;
    g_activity=game->activity;
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
    DxClass *cls=game->activity_class;
    DxMethod *init=dx_vm_find_method(cls,"<init>","V");
    DxValue init_args[1]={DX_OBJ_VALUE(game->activity)};
    if (!init || dx_vm_execute_method(game->vm,init,init_args,1,NULL)!=DX_OK) return -1;
    DxMethod *on_create=dx_vm_find_method(cls,"onCreate","VL");
    DxValue create_args[2]={DX_OBJ_VALUE(game->activity),DX_NULL_VALUE};
    return !on_create || dx_vm_execute_method(game->vm,on_create,create_args,2,NULL)!=DX_OK ? -1 : 0;
}

void agr_dex_game_destroy(agr_dex_game *game) {
    if (!game) return;
    if (g_activity==game->activity) g_activity=NULL;
    if (game->vm) dx_vm_destroy(game->vm);
    if (game->dex) dx_dex_free(game->dex);
    free(game->objects); free(game->bytes); free(game);
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
        "com.onetwofivegames.kungfoobarracuda");
    free(bytes);
    if (game && agr_dex_game_start_activity(game)) { agr_dex_game_destroy(game);game=NULL; }
    return game;
}

agr_dex_game *agr_dex_game_create_from_apk(const agr_apk_package *package) {
    return package?create_game(package->dex_bytes,package->dex_size,
        package->activity_descriptor,package->manifest->package_name):NULL;
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
