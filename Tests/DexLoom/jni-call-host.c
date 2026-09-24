/* Phase 3 final gate: Call variants and static field access return the
 * API19 result. A zero without a pending exception is a real result only
 * when the callee ran or the static slot was read. */
#include "dx_vm.h"
#include "dx_jni.h"
#include "dx_log.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int g_failures = 0;
static int g_calls = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static DxResult native_byte(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm;
    g_calls++;
    frame->result = DX_INT_VALUE(arg_count > 1 ? args[1].i + 3 : -1);
    frame->has_result = true;
    return DX_OK;
}

static DxResult native_static_int(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)args; (void)arg_count;
    g_calls++;
    frame->result = DX_INT_VALUE(41);
    frame->has_result = true;
    return DX_OK;
}

static DxResult native_void(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)frame; (void)args; (void)arg_count;
    g_calls++;
    return DX_OK;
}

static DxResult native_parent(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)args; (void)arg_count;
    g_calls++;
    frame->result = DX_INT_VALUE(1);
    frame->has_result = true;
    return DX_OK;
}

static DxResult native_child(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)args; (void)arg_count;
    g_calls++;
    frame->result = DX_INT_VALUE(2);
    frame->has_result = true;
    return DX_OK;
}

int main(void) {
    DxVM *vm;
    JNIEnv *env;
    DxClass cls, parent, child;
    DxMethod byte_method, static_method, void_method, parent_method, child_method;
    DxMethod *vtable[1];
    DxObject receiver;
    DxValue slots[2];
    const char *names[2];
    const char *types[2];
    jfieldID count_id;
    jvalue arg;
    int calls_before;
    alarm(20);
    dx_log_set_level(DX_LOG_ERROR);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_jni_init(vm) != DX_OK) return 1;
    env = dx_jni_get_env(vm);
    memset(&cls, 0, sizeof(cls));
    memset(&parent, 0, sizeof(parent));
    memset(&child, 0, sizeof(child));
    memset(&byte_method, 0, sizeof(byte_method));
    memset(&static_method, 0, sizeof(static_method));
    memset(&void_method, 0, sizeof(void_method));
    memset(&parent_method, 0, sizeof(parent_method));
    memset(&child_method, 0, sizeof(child_method));
    memset(&receiver, 0, sizeof(receiver));
    memset(slots, 0, sizeof(slots));
    cls.descriptor = "LGate;";
    cls.status = DX_CLASS_INITIALIZED;
    names[0] = "COUNT";
    names[1] = "LABEL";
    types[0] = "I";
    types[1] = "Ljava/lang/String;";
    cls.static_field_count = 2;
    cls.static_field_names = names;
    cls.static_field_types = types;
    slots[0] = DX_INT_VALUE(7);
    cls.static_fields = slots;
    byte_method.name = "next";
    byte_method.shorty = "BI";
    byte_method.declaring_class = &cls;
    byte_method.vtable_idx = -1;
    byte_method.is_native = true;
    byte_method.native_fn = native_byte;
    byte_method.access_flags = DX_ACC_PUBLIC;
    static_method = byte_method;
    static_method.name = "value";
    static_method.shorty = "I";
    static_method.access_flags = DX_ACC_PUBLIC | DX_ACC_STATIC;
    static_method.native_fn = native_static_int;
    void_method = static_method;
    void_method.name = "run";
    void_method.shorty = "V";
    void_method.native_fn = native_void;
    parent.descriptor = "LParent;";
    parent.status = DX_CLASS_INITIALIZED;
    child.descriptor = "LChild;";
    child.super_class = &parent;
    child.status = DX_CLASS_INITIALIZED;
    parent_method.name = "m";
    parent_method.shorty = "I";
    parent_method.declaring_class = &parent;
    parent_method.vtable_idx = 0;
    parent_method.is_native = true;
    parent_method.native_fn = native_parent;
    parent_method.access_flags = DX_ACC_PUBLIC;
    child_method = parent_method;
    child_method.declaring_class = &child;
    child_method.native_fn = native_child;
    vtable[0] = &child_method;
    child.vtable = vtable;
    child.vtable_size = 1;
    receiver.klass = &child;
    arg.i = 4;
    calls_before = g_calls;
    expect((*env)->CallByteMethodA(env, dx_jni_wrap_object(&receiver), (jmethodID)&byte_method, &arg) == 7,
           "CallByteMethodA returns the callee result");
    expect(g_calls == calls_before + 1, "CallByteMethodA invokes the method");
    expect((*env)->ExceptionCheck(env) == JNI_FALSE, "a real byte result leaves no exception");
    calls_before = g_calls;
    expect((*env)->CallStaticIntMethod(env, dx_jni_wrap_class(&cls), (jmethodID)&static_method) == 41,
           "CallStaticIntMethod returns the static callee result");
    expect(g_calls == calls_before + 1, "CallStaticIntMethod invokes the method");
    calls_before = g_calls;
    (*env)->CallStaticVoidMethod(env, dx_jni_wrap_class(&cls), (jmethodID)&void_method);
    expect(g_calls == calls_before + 1 && (*env)->ExceptionCheck(env) == JNI_FALSE,
           "CallStaticVoidMethod invokes and does not invent an exception");
    expect((*env)->CallIntMethod(env, dx_jni_wrap_object(&receiver), (jmethodID)&parent_method) == 2,
           "CallIntMethod uses virtual dispatch");
    expect((*env)->CallNonvirtualIntMethod(env, dx_jni_wrap_object(&receiver),
                                            dx_jni_wrap_class(&parent), (jmethodID)&parent_method) == 1,
           "CallNonvirtualIntMethod keeps the resolved method");
    calls_before = g_calls;
    (*env)->ThrowNew(env, dx_jni_wrap_class(dx_vm_find_class(vm, "Ljava/lang/Exception;")), "pending");
    expect((*env)->CallByteMethodA(env, dx_jni_wrap_object(&receiver), (jmethodID)&byte_method, &arg) == 0,
           "a pending exception makes Call return zero");
    expect(g_calls == calls_before, "a pending exception does not invoke");
    (*env)->ExceptionClear(env);
    calls_before = g_calls;
    expect((*env)->CallIntMethodA(env, dx_jni_wrap_object(&receiver), NULL, NULL) == 0, "null method returns zero");
    expect((*env)->ExceptionCheck(env) == JNI_TRUE, "null method is not a successful zero");
    expect(g_calls == calls_before, "null method does not invoke");
    (*env)->ExceptionClear(env);
    count_id = (*env)->GetStaticFieldID(env, dx_jni_wrap_class(&cls), "COUNT", "I");
    expect((*env)->GetStaticIntField(env, dx_jni_wrap_class(&cls), count_id) == 7,
           "GetStaticIntField reads the static slot");
    expect((*env)->ExceptionCheck(env) == JNI_FALSE, "a stored zero-width read of a real slot is success");
    (*env)->SetStaticIntField(env, dx_jni_wrap_class(&cls), count_id, 0);
    expect((*env)->GetStaticIntField(env, dx_jni_wrap_class(&cls), count_id) == 0 &&
           (*env)->ExceptionCheck(env) == JNI_FALSE,
           "a stored zero is distinct from a missing field");
    expect((*env)->GetStaticIntField(env, dx_jni_wrap_class(&cls), NULL) == 0, "missing static field returns zero");
    expect((*env)->ExceptionCheck(env) == JNI_TRUE, "missing static field is not a successful zero");
    return g_failures ? 1 : 0;
}
