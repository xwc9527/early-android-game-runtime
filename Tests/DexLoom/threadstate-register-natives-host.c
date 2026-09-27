/* Production path for Dalvik ThreadStatus around RegisterNatives.
 * DxJavaThreadState is observed only to show it stays independent. */
#include "dx_vm.h"
#include "dx_jni.h"
#include "dx_log.h"
#include "dx_thread_state.h"

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int32_t g_body_status = -100;
static int g_body_calls;
static DxExecutionContext *g_suspend_exec;

void dx_thread_register_natives_body_observer(DxExecutionContext *exec) {
    g_body_calls += 1;
    g_body_status = dx_thread_status(exec);
}

static int fail(const char *message) {
    fprintf(stderr, "THREADSTATE_PORT fail %s\n", message);
    return 1;
}

static void prepare_method(DxMethod *method, DxClass *cls) {
    memset(method, 0, sizeof(*method));
    method->name = "value";
    method->shorty = "I";
    method->declaring_class = cls;
    method->access_flags = DX_ACC_PUBLIC | DX_ACC_STATIC | DX_ACC_NATIVE;
    method->is_native = true;
    method->vtable_idx = -1;
}

static void *wake_when_suspended(void *unused) {
    int spins = 0;
    (void)unused;
    while (dx_thread_status(g_suspend_exec) != DX_DALVIK_THREAD_SUSPENDED && spins < 2000) {
        usleep(1000);
        spins += 1;
    }
    if (dx_thread_status(g_suspend_exec) == DX_DALVIK_THREAD_SUSPENDED)
        dx_thread_resume_suspend(g_suspend_exec);
    return NULL;
}

static void *other_context(void *vm_ptr) {
    DxVM *vm = vm_ptr;
    DxExecutionContext *exec = dx_exec_create_attached(vm);
    if (!exec) return (void *)2;
    dx_thread_change_status(exec, DX_DALVIK_THREAD_WAIT);
    if (dx_thread_status(exec) != DX_DALVIK_THREAD_WAIT) return (void *)3;
    if ((int)exec->state == DX_DALVIK_THREAD_WAIT) return (void *)4;
    return exec;
}

int main(void) {
    DxVM *vm;
    JNIEnv *env;
    DxExecutionContext *root;
    DxExecutionContext *other;
    DxClass cls;
    DxMethod method;
    jclass clazz;
    JNINativeMethod native_method;
    pthread_t waker;
    pthread_t worker;
    void *joined = NULL;
    int32_t before;
    uint32_t waits_before;
    alarm(8);
    dx_log_set_level(DX_LOG_ERROR);
    vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_jni_init(vm) != DX_OK) return fail("init");
    env = dx_jni_get_env(vm);
    root = vm->root_exec;
    if (!env || !root) return fail("env");
    if (dx_thread_status(root) != DX_DALVIK_THREAD_NATIVE) return fail("entry native");
    if ((int)root->state == DX_DALVIK_THREAD_NATIVE) return fail("java state collided");
    if ((int)DX_JAVA_THREAD_RUNNING == (int)DX_DALVIK_THREAD_RUNNING) return fail("enum values match");
    root->state = DX_JAVA_THREAD_TERMINATED;
    if (dx_thread_status(root) != DX_DALVIK_THREAD_NATIVE) return fail("java state wrote dalvik status");

    if (dx_thread_change_status(root, DX_DALVIK_THREAD_NATIVE) != DX_DALVIK_THREAD_NATIVE)
        return fail("same status return");
    if (dx_thread_change_status(root, DX_DALVIK_THREAD_SUSPENDED) != DX_DALVIK_THREAD_NATIVE)
        return fail("suspended request");
    if (dx_thread_status(root) != DX_DALVIK_THREAD_NATIVE) return fail("suspended stored");

    dx_thread_add_suspend_counts(root, 1, 1);
    if (dx_thread_change_status(root, DX_DALVIK_THREAD_WAIT) != DX_DALVIK_THREAD_NATIVE)
        return fail("wait transition");
    if (dx_thread_status(root) != DX_DALVIK_THREAD_WAIT) return fail("wait stored");
    dx_thread_add_suspend_counts(root, -1, -1);
    dx_thread_change_status(root, DX_DALVIK_THREAD_NATIVE);

    before = dx_thread_status(root);
    g_body_calls = 0;
    g_body_status = -100;
    if ((*env)->RegisterNatives(env, NULL, NULL, 0) != -1) return fail("null class return");
    if (before != DX_DALVIK_THREAD_NATIVE) return fail("pre-failure status");
    if (g_body_calls != 1 || g_body_status != DX_DALVIK_THREAD_RUNNING) return fail("failure body");
    if (dx_thread_status(root) != DX_DALVIK_THREAD_NATIVE) return fail("failure restore");

    memset(&cls, 0, sizeof(cls));
    cls.descriptor = "LProbe;";
    cls.status = DX_CLASS_INITIALIZED;
    prepare_method(&method, &cls);
    cls.direct_methods = &method;
    cls.direct_method_count = 1;
    clazz = dx_jni_wrap_class(&cls);
    if (!clazz) return fail("class");
    native_method.name = "value";
    native_method.signature = "()I";
    native_method.fnPtr = (void *)1;
    g_body_calls = 0;
    if ((*env)->RegisterNatives(env, clazz, &native_method, 1) != 0) return fail("bind");
    if (g_body_status != DX_DALVIK_THREAD_RUNNING) return fail("success body");
    if (dx_thread_status(root) != DX_DALVIK_THREAD_NATIVE) return fail("success restore");
    if (method.native_fn == NULL) return fail("fn");

    dx_thread_add_suspend_counts(root, 1, 1);
    g_suspend_exec = root;
    waits_before = dx_thread_bionic_wait_entries();
    if (pthread_create(&waker, NULL, wake_when_suspended, NULL) != 0) return fail("waker");
    g_body_calls = 0;
    g_body_status = -100;
    if ((*env)->RegisterNatives(env, clazz, &native_method, 1) != 0) return fail("suspend bind");
    pthread_join(waker, NULL);
    if (dx_thread_bionic_wait_entries() <= waits_before) return fail("bionic wait");
    if (dx_thread_bionic_broadcast_entries() == 0) return fail("bionic broadcast");
    if (dx_thread_suspend_cond_word() != 0xfffffffeu) return fail("cond pulse");
    if (g_body_status != DX_DALVIK_THREAD_RUNNING) return fail("resumed body");
    if (dx_thread_status(root) != DX_DALVIK_THREAD_NATIVE) return fail("suspend restore");

    if (pthread_create(&worker, NULL, other_context, vm) != 0) return fail("worker");
    pthread_join(worker, &joined);
    other = joined;
    if (other == (void *)1 || other == (void *)2 || other == (void *)3 || other == (void *)4)
        return fail("other context");
    if (dx_thread_status(root) != DX_DALVIK_THREAD_NATIVE) return fail("root shared");
    if (dx_thread_status(other) != DX_DALVIK_THREAD_WAIT) return fail("other status");

    printf("THREADSTATE_PORT ok=1 waits=%u broadcasts=%u cond=%u body=%d java=%d dalvik=%d\n",
           dx_thread_bionic_wait_entries(), dx_thread_bionic_broadcast_entries(),
           dx_thread_suspend_cond_word(), g_body_status, (int)root->state,
           dx_thread_status(root));
    return 0;
}
