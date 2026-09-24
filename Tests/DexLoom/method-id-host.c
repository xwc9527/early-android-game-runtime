/* Phase 3B/3C: method and field identity, class init, pending exception. */
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

static DxResult native_probe(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)frame; (void)args; (void)arg_count;
    return DX_OK;
}

int main(void) {
    DxVM *vm;
    JNIEnv *env;
    DxClass *object_class;
    DxClass *random_class;
    DxClass *math_class;
    DxObject *object;
    jclass object_ref;
    jclass random_ref;
    jclass math_ref;
    jmethodID equals_obj;
    jmethodID equals_bad;
    jmethodID next_int;
    jmethodID next_int_arg;
    jmethodID sin_id;
    jfieldID seed;
    jfieldID seed_wrong;
    DxFieldId *seed_id;
    DxClass parent;
    DxClass child;
    jobject thrown;
    jthrowable pending;
    JNINativeMethod native_method;
    alarm(20);
    dx_log_set_level(DX_LOG_ERROR);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_jni_init(vm) != DX_OK) return 1;
    env = dx_jni_get_env(vm);
    object_class = dx_vm_find_class(vm, "Ljava/lang/Object;");
    random_class = dx_vm_find_class(vm, "Ljava/util/Random;");
    math_class = dx_vm_find_class(vm, "Ljava/lang/Math;");
    object = dx_vm_alloc_object(vm, object_class);
    object_ref = dx_jni_wrap_class(object_class);
    (void)object;
    random_ref = dx_jni_wrap_class(random_class);
    math_ref = dx_jni_wrap_class(math_class);
    expect(object_ref && (object_ref == dx_jni_wrap_class(object_class) ||
           (*env)->IsSameObject(env, (jobject)object_ref, (jobject)dx_jni_wrap_class(object_class))),
           "class ref is an indirect reference to one mirror");
    equals_obj = (*env)->GetMethodID(env, object_ref, "equals", "(Ljava/lang/Object;)Z");
    equals_bad = (*env)->GetMethodID(env, object_ref, "equals", "()V");
    expect(equals_obj && ((DxMethod *)equals_obj)->shorty &&
           strcmp(((DxMethod *)equals_obj)->shorty, "ZL") == 0, "equals resolves by signature");
    expect(equals_bad == NULL, "equals rejects a different signature");
    next_int = (*env)->GetMethodID(env, random_ref, "nextInt", "()I");
    next_int_arg = (*env)->GetMethodID(env, random_ref, "nextInt", "(I)I");
    expect(next_int && next_int_arg && next_int != next_int_arg, "overload keeps two method identities");
    sin_id = (*env)->GetStaticMethodID(env, math_ref, "sin", "(D)D");
    expect(sin_id && ((DxMethod *)sin_id)->access_flags & DX_ACC_STATIC, "static method id uses the signature");
    expect((*env)->GetStaticMethodID(env, math_ref, "sin", "()V") == NULL, "static method rejects the wrong signature");
    seed = (*env)->GetFieldID(env, random_ref, "seed", "J");
    seed_wrong = (*env)->GetFieldID(env, random_ref, "seed", "I");
    seed_id = (DxFieldId *)seed;
    expect(seed_id && seed_id->declaring == random_class && seed_id->index == 1, "field id is a resolved slot");
    expect(seed_wrong == NULL, "field id rejects the wrong type");
    memset(&parent, 0, sizeof(parent));
    memset(&child, 0, sizeof(child));
    parent.descriptor = "LParent;";
    parent.status = DX_CLASS_LOADED;
    child.descriptor = "LChild;";
    child.super_class = &parent;
    child.status = DX_CLASS_LOADED;
    expect(dx_vm_init_class(vm, &child) == DX_OK, "class init succeeds");
    expect(parent.status == DX_CLASS_INITIALIZED && child.status == DX_CLASS_INITIALIZED,
           "super is initialized before the child");
    child.status = DX_CLASS_INITIALIZING;
    expect(dx_vm_init_class(vm, &child) == DX_OK, "recursive init on the same thread returns");
    child.status = DX_CLASS_ERROR;
    expect(dx_vm_init_class(vm, &child) == DX_ERR_CLASS_NOT_FOUND, "failed class stays failed");
    thrown = dx_jni_wrap_object(dx_vm_create_exception(vm, "Ljava/lang/Exception;", "boom"));
    expect((*env)->Throw(env, (jthrowable)thrown) == 0, "throw sets the pending exception");
    expect((*env)->ExceptionCheck(env) == JNI_TRUE, "exception check sees the pending exception");
    pending = (*env)->ExceptionOccurred(env);
    expect(pending && (*env)->IsSameObject(env, (jobject)pending, thrown), "exception occurred returns the same object");
    (*env)->ExceptionClear(env);
    expect((*env)->ExceptionCheck(env) == JNI_FALSE, "exception clear removes the pending exception");
    native_method.name = "nextInt";
    native_method.signature = "()I";
    native_method.fnPtr = (void *)native_probe;
    expect((*env)->RegisterNatives(env, random_ref, &native_method, 1) == 0, "register natives binds the signature");
    expect(((DxMethod *)next_int)->native_fn == native_probe, "registered native is the resolved method");
    native_method.signature = "(J)I";
    expect((*env)->RegisterNatives(env, random_ref, &native_method, 1) != 0, "register natives rejects a missing signature");
    return g_failures ? 1 : 0;
}
