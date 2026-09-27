/* Test-only host fixture. Method declarations mirror Probe.java.
   RegisterNatives is the production jni_RegisterNatives in dx_jni.c.
   Pending-exception text is the class of the object ExceptionOccurred
   returned. Class.getName is not used: native_class_getname reads the
   java.lang.Class object's own klass, which would mix another owner into
   this observation. */
#include "dx_vm.h"
#include "dx_jni.h"
#include "dx_log.h"
#include "report.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static char g_pending_store[9][160];
static int g_pending_slot;

static const char *keep_pending(const char *text) {
    char *slot;
    if (g_pending_slot >= 9) return text;
    slot = g_pending_store[g_pending_slot++];
    snprintf(slot, sizeof(g_pending_store[0]), "%s", text);
    return slot;
}

static DxResult fn_eleven(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)args; (void)arg_count;
    frame->result = DX_INT_VALUE(11);
    frame->has_result = true;
    return DX_OK;
}

static DxResult fn_twentytwo(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)args; (void)arg_count;
    frame->result = DX_INT_VALUE(22);
    frame->has_result = true;
    return DX_OK;
}

static DxResult fn_plus(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm;
    frame->result = DX_INT_VALUE(arg_count > 0 ? args[0].i + 1 : -1);
    frame->has_result = true;
    return DX_OK;
}

static DxResult fn_marker(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)args; (void)arg_count;
    frame->result = DX_INT_VALUE(99);
    frame->has_result = true;
    return DX_OK;
}

static DxResult fn_fast(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)vm; (void)args; (void)arg_count;
    frame->result = DX_INT_VALUE(33);
    frame->has_result = true;
    return DX_OK;
}

static void read_pending(JNIEnv *env, char *out, size_t out_len) {
    jthrowable thrown;
    DxObject *object;
    const char *descriptor;
    size_t length;
    size_t in_index;
    size_t out_index;
    out[0] = '\0';
    thrown = (*env)->ExceptionOccurred(env);
    if (!thrown) return;
    object = dx_jni_unwrap_object((jobject)thrown);
    descriptor = (object && object->klass) ? object->klass->descriptor : NULL;
    (*env)->ExceptionClear(env);
    if (!descriptor) {
        snprintf(out, out_len, "unreadable");
        return;
    }
    length = strlen(descriptor);
    if (length >= 2 && descriptor[0] == 'L' && descriptor[length - 1] == ';') {
        out_index = 0;
        for (in_index = 1; in_index + 1 < length && out_index + 1 < out_len; in_index++) {
            out[out_index++] = descriptor[in_index] == '/' ? '.' : descriptor[in_index];
        }
        out[out_index] = '\0';
        return;
    }
    snprintf(out, out_len, "%s", descriptor);
}

static void prepare_method(DxMethod *method, DxClass *cls, const char *name,
                           const char *shorty, uint32_t flags, int is_native) {
    memset(method, 0, sizeof(*method));
    method->name = name;
    method->shorty = shorty;
    method->declaring_class = cls;
    method->access_flags = flags;
    method->is_native = is_native ? true : false;
    method->vtable_idx = -1;
}

static void observe(JNIEnv *env, jclass clazz, JniBindCase *out, const char *name,
                    const char *method_name, const char *signature, void *fn,
                    jmethodID call_id, const jvalue *call_arg) {
    JNINativeMethod native_method;
    char pending[160];
    native_method.name = method_name;
    native_method.signature = signature;
    native_method.fnPtr = fn;
    (*env)->ExceptionClear(env);
    out->name = name;
    out->register_return = (int)(*env)->RegisterNatives(env, clazz, &native_method, 1);
    read_pending(env, pending, sizeof(pending));
    out->pending = pending[0] ? keep_pending(pending) : NULL;
    (*env)->ExceptionClear(env);
    out->has_call = call_id != NULL;
    out->call_result = 0;
    if (call_id) {
        if (call_arg)
            out->call_result = (*env)->CallStaticIntMethodA(env, clazz, call_id, call_arg);
        else
            out->call_result = (*env)->CallStaticIntMethod(env, clazz, call_id);
        (*env)->ExceptionClear(env);
    }
}

int main(void) {
    DxVM *vm;
    JNIEnv *env;
    DxClass cls;
    DxMethod direct[5];
    DxMethod inst;
    jclass clazz;
    jmethodID value_id;
    jmethodID value_int_id;
    jmethodID fast_id;
    jmethodID plain_id;
    JniBindCase cases[9];
    jvalue arg;
    static uint16_t plain_insns[2] = {0x7012, 0x000F};
    uint32_t native_flags = DX_ACC_PUBLIC | DX_ACC_STATIC | DX_ACC_NATIVE;
    alarm(30);
    dx_log_set_level(DX_LOG_ERROR);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_jni_init(vm) != DX_OK) return 1;
    env = dx_jni_get_env(vm);
    memset(&cls, 0, sizeof(cls));
    cls.descriptor = "LProbe;";
    cls.status = DX_CLASS_INITIALIZED;
    prepare_method(&direct[0], &cls, "value", "I", native_flags, 1);
    prepare_method(&direct[1], &cls, "value", "II", native_flags, 1);
    prepare_method(&direct[2], &cls, "fast", "I", native_flags, 1);
    prepare_method(&direct[3], &cls, "synced", "I",
                   native_flags | DX_ACC_SYNCHRONIZED, 1);
    prepare_method(&direct[4], &cls, "plain", "I", DX_ACC_PUBLIC | DX_ACC_STATIC, 0);
    direct[4].has_code = true;
    direct[4].code.registers_size = 1;
    direct[4].code.ins_size = 0;
    direct[4].code.outs_size = 0;
    direct[4].code.tries_size = 0;
    direct[4].code.insns_size = 2;
    direct[4].code.insns = plain_insns;
    prepare_method(&inst, &cls, "inst", "I", DX_ACC_PUBLIC | DX_ACC_NATIVE, 1);
    cls.direct_methods = direct;
    cls.direct_method_count = 5;
    cls.virtual_methods = &inst;
    cls.virtual_method_count = 1;
    clazz = dx_jni_wrap_class(&cls);
    value_id = (*env)->GetStaticMethodID(env, clazz, "value", "()I");
    value_int_id = (*env)->GetStaticMethodID(env, clazz, "value", "(I)I");
    fast_id = (*env)->GetStaticMethodID(env, clazz, "fast", "()I");
    plain_id = (*env)->GetStaticMethodID(env, clazz, "plain", "()I");
    if (!value_id || !value_int_id || !fast_id || !plain_id ||
        !(*env)->GetStaticMethodID(env, clazz, "synced", "()I") ||
        !(*env)->GetMethodID(env, clazz, "inst", "()I")) {
        fprintf(stderr, "Probe declaration did not resolve\n");
        return 1;
    }
    g_pending_slot = 0;
    observe(env, clazz, &cases[0], "repeat_a", "value", "()I", (void *)fn_eleven,
            value_id, NULL);
    observe(env, clazz, &cases[1], "repeat_b", "value", "()I", (void *)fn_twentytwo,
            value_id, NULL);
    observe(env, clazz, &cases[2], "missing_signature", "value", "(J)I",
            (void *)fn_marker, NULL, NULL);
    arg.i = 5;
    observe(env, clazz, &cases[3], "overload_int", "value", "(I)I", (void *)fn_plus,
            value_int_id, &arg);
    observe(env, clazz, &cases[4], "non_native", "plain", "()I", (void *)fn_marker,
            plain_id, NULL);
    observe(env, clazz, &cases[5], "null_fn", "value", "()I", NULL, value_id, NULL);
    observe(env, clazz, &cases[6], "fast_static", "fast", "!()I", (void *)fn_fast,
            fast_id, NULL);
    observe(env, clazz, &cases[7], "fast_nonstatic", "inst", "!()I", (void *)fn_marker,
            NULL, NULL);
    observe(env, clazz, &cases[8], "fast_synchronized", "synced", "!()I",
            (void *)fn_marker, NULL, NULL);
    jni_bind_print_json(stdout, cases, 9);
    return 0;
}
