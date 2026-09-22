/* Per-execution-context unresolved invoke telemetry.
   Each context publishes its own bounded trace. */
#include "dx_vm.h"
#include "dx_log.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int g_failures = 0;
static volatile int g_worker_entered = 0;
static volatile int g_worker_release = 0;
static volatile int g_worker_finished = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static void note(DxVM *vm, uint32_t pc, const char *name) {
    dx_vm_note_unresolved_seen(vm, NULL, pc, 0x6e, 1000 + pc,
                               "Ltest/Marker;", name, "V", NULL, 0);
}

static DxResult worker_run(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t count) {
    int i;
    (void)frame;
    (void)args;
    (void)count;
    __atomic_store_n(&g_worker_entered, 1, __ATOMIC_RELEASE);
    while (__atomic_load_n(&g_worker_release, __ATOMIC_ACQUIRE) == 0) {
    }
    for (i = 0; i < 18; i++) note(vm, (uint32_t)i, "workerOnly");
    __atomic_store_n(&g_worker_finished, 1, __ATOMIC_RELEASE);
    return DX_OK;
}

static int context_by_id(DxVM *vm, uint32_t exec_id, DxUnresolvedContextInfo *out, uint32_t *index) {
    uint32_t n = dx_vm_unresolved_context_count(vm);
    uint32_t i;
    for (i = 0; i < n; i++) {
        if (dx_vm_copy_unresolved_context(vm, i, out) != 0) continue;
        if (out->exec_id == exec_id) {
            *index = i;
            return 1;
        }
    }
    return 0;
}

static int events_are(DxVM *vm, uint32_t index, uint32_t count, const char *name) {
    uint32_t i;
    for (i = 0; i < count; i++) {
        DxInvokeWitness event;
        if (dx_vm_copy_unresolved_event(vm, index, i, &event) != 0) return 0;
        if (strcmp(event.target_name, name) != 0) return 0;
        if (event.resolved != 0) return 0;
    }
    return 1;
}

int main(void) {
    DxVM *vm;
    DxClass *thread_cls;
    DxMethod *run;
    DxMethod *start;
    DxMethod *join;
    DxObject *thread;
    DxValue args[1];
    DxUnresolvedContextInfo root;
    DxUnresolvedContextInfo worker;
    uint32_t root_index = 0;
    uint32_t worker_index = 0;
    int i;

    alarm(20);
    dx_log_set_level(DX_LOG_WARN);
    vm = dx_vm_create(NULL);
    expect(vm && dx_register_java_lang(vm) == DX_OK, "create vm");
    if (!vm) return 1;
    dx_vm_set_telemetry_enabled(vm, true);
    thread_cls = dx_vm_find_class(vm, "Ljava/lang/Thread;");
    run = thread_cls ? dx_vm_find_method(thread_cls, "run", "V") : NULL;
    start = thread_cls ? dx_vm_find_method(thread_cls, "start", "V") : NULL;
    join = thread_cls ? dx_vm_find_method(thread_cls, "join", "V") : NULL;
    expect(run && start && join && run->is_native, "Thread start, run, and join exist");
    if (!run || !start || !join) return 1;
    run->native_fn = worker_run;

    thread = dx_vm_alloc_object(vm, thread_cls);
    args[0] = DX_OBJ_VALUE(thread);
    expect(thread && dx_vm_execute_method(vm, start, args, 1, NULL) == DX_OK, "start worker context");
    for (i = 0; i < 2000 && __atomic_load_n(&g_worker_entered, __ATOMIC_ACQUIRE) == 0; i++)
        usleep(1000);
    expect(g_worker_entered == 1, "worker entered its own execution context");
    __atomic_store_n(&g_worker_release, 1, __ATOMIC_RELEASE);
    for (i = 0; i < 18; i++) note(vm, (uint32_t)i, "rootOnly");
    for (i = 0; i < 2000 && __atomic_load_n(&g_worker_finished, __ATOMIC_ACQUIRE) == 0; i++)
        usleep(1000);
    expect(g_worker_finished == 1, "worker finished its trace");
    expect(dx_vm_execute_method(vm, join, args, 1, NULL) == DX_OK, "join worker");

    expect(context_by_id(vm, 0, &root, &root_index), "execution context 0 is readable");
    expect(context_by_id(vm, 1, &worker, &worker_index), "execution context 1 is readable");
    expect(root.count == DX_UNRESOLVED_TRACE_CAP && root.dropped == 2,
           "context 0 keeps its own count and dropped overflow");
    expect(worker.count == DX_UNRESOLVED_TRACE_CAP && worker.dropped == 2,
           "context 1 keeps its own count and dropped overflow");
    expect(events_are(vm, root_index, root.count, "rootOnly"),
           "context 0 contains only its own unresolved events");
    expect(events_are(vm, worker_index, worker.count, "workerOnly"),
           "context 1 contains only its own unresolved events");
    expect(root_index != worker_index, "the two contexts are distinct trace owners");

    if (g_failures) {
        fprintf(stderr, "%d unresolved-context checks failed\n", g_failures);
        return 1;
    }
    printf("unresolved context contract: PASS\n");
    return 0;
}
