/* Phase 3A: Dalvik indirect references and JNI thread state. No game APK. */
#include "dx_vm.h"
#include "dx_jni.h"
#include "dx_log.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static int g_failures = 0;

static unsigned jni_to_visible(jobject ref) {
    return (unsigned)(uintptr_t)ref;
}

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

typedef struct {
    JavaVM *vm;
    jobject foreign_local;
    int wrong_thread_rejected;
} ThreadProbe;

static void *other_thread(void *arg) {
    ThreadProbe *probe = (ThreadProbe *)arg;
    JNIEnv *env = NULL;
    jobject local;
    if ((*probe->vm)->GetEnv(probe->vm, (void **)&env, JNI_VERSION_1_6) != JNI_EDETACHED)
        return (void *)1;
    if ((*probe->vm)->AttachCurrentThread(probe->vm, (void **)&env, NULL) != JNI_OK || !env)
        return (void *)2;
    if ((*probe->vm)->GetEnv(probe->vm, (void **)&env, JNI_VERSION_1_6) != JNI_OK)
        return (void *)3;
    local = (*env)->NewLocalRef(env, probe->foreign_local);
    probe->wrong_thread_rejected = (local == NULL);
    if ((*probe->vm)->DetachCurrentThread(probe->vm) != JNI_OK) return (void *)4;
    if ((*probe->vm)->GetEnv(probe->vm, (void **)&env, JNI_VERSION_1_6) != JNI_EDETACHED)
        return (void *)5;
    return NULL;
}

int main(void) {
    DxVM *vm;
    DxClass *object_class;
    DxObject *object;
    JNIEnv *env;
    JavaVM *java_vm;
    jobject local;
    jobject global;
    jobject kept;
    jobject weak;
    jobject stale;
    pthread_t thread;
    ThreadProbe probe;
    int i;
    alarm(20);
    dx_log_set_level(DX_LOG_ERROR);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_jni_init(vm) != DX_OK) return 1;
    env = dx_jni_get_env(vm);
    object_class = dx_vm_find_class(vm, "Ljava/lang/Object;");
    object = object_class ? dx_vm_alloc_object(vm, object_class) : NULL;
    local = dx_jni_wrap_object(object);
    expect(env && local, "attached env and local ref");
    expect((*env)->PushLocalFrame(env, 16) == 0, "push local frame");
    kept = (*env)->NewLocalRef(env, local);
    expect(kept && (*env)->IsSameObject(env, local, kept), "local ref survives inside frame");
    stale = kept;
    kept = (*env)->PopLocalFrame(env, kept);
    expect(kept && (*env)->IsSameObject(env, local, kept), "pop preserves requested result");
    expect(!(*env)->IsSameObject(env, local, stale), "local ref invalid after frame pop");
    global = (*env)->NewGlobalRef(env, local);
    expect(global && (jni_to_visible(global) & 3) == 2, "global ref is not the raw object");
    (*env)->DeleteLocalRef(env, local);
    expect((*env)->IsSameObject(env, global, global), "global ref roots object after local delete");
    expect((*env)->GetObjectRefType(env, global) == JNIGlobalRefType, "global ref type");
    (*env)->DeleteGlobalRef(env, global);
    expect((*env)->GetObjectRefType(env, global) != JNIGlobalRefType, "deleted global ref is rejected");
    object = dx_vm_alloc_object(vm, object_class);
    local = dx_jni_wrap_object(object);
    weak = (*env)->NewWeakGlobalRef(env, local);
    expect(weak && (*env)->GetObjectRefType(env, weak) == JNIWeakGlobalRefType, "weak global ref");
    (*env)->DeleteLocalRef(env, local);
    expect(dx_vm_gc(vm) == DX_OK, "gc with weak ref");
    expect((*env)->NewLocalRef(env, weak) == NULL, "weak ref clears when it is not a strong root");
    object = dx_vm_alloc_object(vm, object_class);
    local = dx_jni_wrap_object(object);
    stale = (*env)->NewLocalRef(env, local);
    (*env)->DeleteLocalRef(env, stale);
    expect((*env)->NewLocalRef(env, stale) == NULL, "stale local handle rejected");
    for (i = 0; i < 200; i++) {
        jobject created = (*env)->NewGlobalRef(env, local);
        if (!created) g_failures++;
        (*env)->DeleteGlobalRef(env, created);
    }
    expect(g_failures == 0, "repeated allocate/delete stress");
    (*env)->GetJavaVM(env, &java_vm);
    probe.vm = java_vm;
    probe.foreign_local = local;
    probe.wrong_thread_rejected = 0;
    expect(pthread_create(&thread, NULL, other_thread, &probe) == 0, "start second thread");
    pthread_join(thread, NULL);
    expect(probe.wrong_thread_rejected, "wrong-thread local ref rejected");
    expect((*java_vm)->GetEnv(java_vm, (void **)&env, JNI_VERSION_1_6) == JNI_OK, "main thread stays attached");
    return g_failures ? 1 : 0;
}
