/* Test-only guest library. JNI_OnLoad calls the image libdvm RegisterNatives.
   Pending-exception strings come from the throwable that was actually pending.
   This file does not name an expected exception class. */
#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "report.h"

static char g_pending_store[9][160];
static int g_pending_slot;

static const char *keep_pending(const char *text) {
    char *slot;
    if (g_pending_slot >= 9) return text;
    slot = g_pending_store[g_pending_slot++];
    snprintf(slot, 160, "%s", text);
    return slot;
}

static jint JNICALL fn_eleven(JNIEnv *env, jclass clazz) {
    (void)env;
    (void)clazz;
    return 11;
}

static jint JNICALL fn_twentytwo(JNIEnv *env, jclass clazz) {
    (void)env;
    (void)clazz;
    return 22;
}

static jint JNICALL fn_plus(JNIEnv *env, jclass clazz, jint value) {
    (void)env;
    (void)clazz;
    return value + 1;
}

static jint JNICALL fn_marker(JNIEnv *env, jclass clazz) {
    (void)env;
    (void)clazz;
    return 99;
}

static jint JNICALL fn_fast(JNIEnv *env, jclass clazz) {
    (void)env;
    (void)clazz;
    return 33;
}

static void read_pending(JNIEnv *env, char *out, size_t out_len) {
    jthrowable thrown;
    jclass thrown_class;
    jclass class_class;
    jmethodID get_name;
    jstring name;
    const char *utf;
    out[0] = '\0';
    thrown = (*env)->ExceptionOccurred(env);
    if (!thrown) return;
    (*env)->ExceptionClear(env);
    thrown_class = (*env)->GetObjectClass(env, thrown);
    class_class = thrown_class ? (*env)->GetObjectClass(env, thrown_class) : NULL;
    get_name = class_class
        ? (*env)->GetMethodID(env, class_class, "getName", "()Ljava/lang/String;")
        : NULL;
    if (!get_name) {
        snprintf(out, out_len, "unreadable");
        (*env)->ExceptionClear(env);
        return;
    }
    name = (jstring)(*env)->CallObjectMethod(env, thrown_class, get_name);
    if ((*env)->ExceptionCheck(env) || !name) {
        snprintf(out, out_len, "unreadable");
        (*env)->ExceptionClear(env);
        return;
    }
    utf = (*env)->GetStringUTFChars(env, name, NULL);
    if (!utf) {
        snprintf(out, out_len, "unreadable");
        return;
    }
    snprintf(out, out_len, "%s", utf);
    (*env)->ReleaseStringUTFChars(env, name, utf);
}

static jmethodID need_method(JNIEnv *env, jclass clazz, const char *name,
                             const char *signature, int is_static) {
    jmethodID id;
    if (is_static) id = (*env)->GetStaticMethodID(env, clazz, name, signature);
    else id = (*env)->GetMethodID(env, clazz, name, signature);
    if (!id) {
        fprintf(stderr, "missing Probe.%s%s\n", name, signature);
        (*env)->ExceptionClear(env);
    }
    return id;
}

static void observe(JNIEnv *env, jclass clazz, JniBindCase *out, const char *name,
                    const char *method_name, const char *signature, void *fn,
                    jmethodID call_id, jvalue *call_arg) {
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

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    jclass clazz;
    jmethodID value_id;
    jmethodID value_int_id;
    jmethodID fast_id;
    jmethodID plain_id;
    JniBindCase cases[9];
    jvalue arg;
    FILE *json;
    (void)reserved;
    if ((*vm)->GetEnv(vm, (void **)&env, JNI_VERSION_1_6) != JNI_OK || !env) {
        fprintf(stderr, "GetEnv failed\n");
        return JNI_ERR;
    }
    clazz = (*env)->FindClass(env, "Probe");
    if (!clazz) {
        fprintf(stderr, "FindClass Probe failed\n");
        (*env)->ExceptionClear(env);
        return JNI_ERR;
    }
    value_id = need_method(env, clazz, "value", "()I", 1);
    value_int_id = need_method(env, clazz, "value", "(I)I", 1);
    fast_id = need_method(env, clazz, "fast", "()I", 1);
    plain_id = need_method(env, clazz, "plain", "()I", 1);
    if (!value_id || !value_int_id || !fast_id || !plain_id ||
        !need_method(env, clazz, "synced", "()I", 1) ||
        !need_method(env, clazz, "inst", "()I", 0)) {
        return JNI_ERR;
    }

    /* method->fastJni is stored by dvmRegisterJNIMethod and has no reader in
       this pinned tree. dvmCallJNIMethod still passes JNIEnv and jclass.
       fast_* records the '!' registration gates, not an omitted-JNIEnv ABI. */
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

    json = fopen("/data/local/tmp/jnibind-clean.json", "w");
    if (!json) {
        fprintf(stderr, "fopen jnibind-clean.json failed\n");
        return JNI_ERR;
    }
    jni_bind_print_json(json, cases, 9);
    fclose(json);
    jni_bind_print_json(stdout, cases, 9);
    fflush(stdout);
    return JNI_VERSION_1_6;
}
