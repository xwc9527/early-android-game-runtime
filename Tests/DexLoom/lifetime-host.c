/* Phase 3D: JNI, static, class, and native-frame roots, plus weak clearing. */
#include "dx_vm.h"
#include "dx_jni.h"
#include "dx_log.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int g_failures = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static int on_heap(DxVM *vm, DxObject *obj) {
    uint32_t i;
    for (i = 0; i < vm->heap_count; i++) if (vm->heap[i] == obj) return 1;
    return 0;
}

static DxObject *g_native_seen;

static DxResult native_gc(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)frame;
    (void)arg_count;
    if (dx_vm_gc(vm) != DX_OK) return DX_ERR_INTERNAL;
    g_native_seen = args[0].obj;
    return DX_OK;
}

int main(void) {
    DxVM *vm;
    JNIEnv *env;
    DxClass *object_class;
    DxClass holder;
    DxObject *object;
    DxObject *cache_array;
    DxObject *cache_entry;
    DxObject *mirror;
    DxValue static_slot;
    jobject local;
    jobject global;
    jobject weak;
    DxMethod native_method;
    DxValue arg;
    int i;
    alarm(20);
    dx_log_set_level(DX_LOG_ERROR);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_jni_init(vm) != DX_OK) return 1;
    env = dx_jni_get_env(vm);
    object_class = dx_vm_find_class(vm, "Ljava/lang/Object;");
    object = dx_vm_alloc_object(vm, object_class);
    memset(&holder, 0, sizeof(holder));
    holder.descriptor = "LHolder;";
    holder.status = DX_CLASS_INITIALIZED;
    holder.static_field_count = 1;
    static_slot = DX_OBJ_VALUE(object);
    holder.static_fields = &static_slot;
    vm->classes[vm->class_count++] = &holder;
    expect(dx_vm_gc(vm) == DX_OK && on_heap(vm, object), "a static field keeps the object");
    holder.static_fields[0] = DX_NULL_VALUE;
    expect(dx_vm_gc(vm) == DX_OK && !on_heap(vm, object), "dropping the static root lets GC free the object");
    cache_array = dx_vm_alloc_array(vm, 1);
    cache_entry = dx_vm_alloc_object(vm, object_class);
    if (!cache_array || !cache_entry || !cache_array->array_elements) return 1;
    cache_array->array_elements[0] = DX_OBJ_VALUE(cache_entry);
    holder.static_fields[0] = DX_OBJ_VALUE(cache_array);
    expect(dx_vm_gc_minor(vm) == DX_OK && on_heap(vm, cache_array) && on_heap(vm, cache_entry),
           "minor GC retains an object through a static array root");
    expect(dx_vm_gc(vm) == DX_OK && on_heap(vm, cache_array) && on_heap(vm, cache_entry),
           "major GC retains an object through a static array root");
    dx_vm_gc_step(vm);
    for (i = 0; i < 1000 && vm->gc_phase != DX_GC_IDLE; i++) dx_vm_gc_step(vm);
    expect(vm->gc_phase == DX_GC_IDLE && on_heap(vm, cache_array) && on_heap(vm, cache_entry),
           "incremental GC retains an object through a static array root");
    holder.static_fields[0] = DX_NULL_VALUE;
    expect(dx_vm_gc(vm) == DX_OK && !on_heap(vm, cache_array) && !on_heap(vm, cache_entry),
           "dropping the static array root releases its elements");
    mirror = dx_vm_class_mirror(vm, object_class);
    expect(dx_vm_gc(vm) == DX_OK && on_heap(vm, mirror), "the class mirror global ref keeps the Class object");
    object = dx_vm_alloc_object(vm, object_class);
    memset(&native_method, 0, sizeof(native_method));
    native_method.name = "hold";
    native_method.shorty = "VL";
    native_method.declaring_class = object_class;
    native_method.is_native = true;
    native_method.native_fn = native_gc;
    arg = DX_OBJ_VALUE(object);
    expect(dx_vm_execute_method(vm, &native_method, &arg, 1, NULL) == DX_OK &&
           g_native_seen == object && on_heap(vm, object),
           "a native frame register keeps the argument");
    object = dx_vm_alloc_object(vm, object_class);
    local = dx_jni_wrap_object(object);
    global = (*env)->NewGlobalRef(env, local);
    (*env)->DeleteLocalRef(env, local);
    (*env)->DeleteGlobalRef(env, global);
    expect(dx_vm_gc(vm) == DX_OK && !on_heap(vm, object), "a deleted JNI root does not keep the object");
    object = dx_vm_alloc_object(vm, object_class);
    local = dx_jni_wrap_object(object);
    expect((*env)->PushLocalFrame(env, 8) == 0, "push a frame for the lifetime test");
    global = (*env)->NewLocalRef(env, local);
    (*env)->DeleteLocalRef(env, local);
    (*env)->PopLocalFrame(env, NULL);
    expect(dx_vm_gc(vm) == DX_OK && !on_heap(vm, object), "popping a local frame releases its roots");
    object = dx_vm_alloc_object(vm, object_class);
    local = dx_jni_wrap_object(object);
    weak = (*env)->NewWeakGlobalRef(env, local);
    (*env)->DeleteLocalRef(env, local);
    expect(dx_vm_gc(vm) == DX_OK && (*env)->NewLocalRef(env, weak) == NULL, "weak clearing drops the referent");
    object = dx_vm_alloc_object(vm, object_class);
    local = dx_jni_wrap_object(object);
    global = (*env)->NewGlobalRef(env, local);
    {
        int stress_ok = 1;
        for (i = 0; i < 30; i++) {
            if (dx_vm_gc(vm) != DX_OK || dx_vm_gc_minor(vm) != DX_OK) stress_ok = 0;
        }
        expect(stress_ok && (*env)->IsSameObject(env, global, global), "repeated GC keeps a live global root");
    }
    (*env)->DeleteGlobalRef(env, global);
    return g_failures ? 1 : 0;
}
