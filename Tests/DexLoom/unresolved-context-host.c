/* Per-execution-context unresolved invoke telemetry.
   Each context publishes its own bounded trace. */
#include "dx_vm.h"
#include "dx_log.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int g_failures = 0;
static volatile int g_worker_entered = 0;
static volatile int g_worker_release = 0;
static volatile int g_worker_finished = 0;
static volatile int g_born_entered = 0;
static volatile int g_born_release = 0;
static volatile int g_born_finished = 0;
static volatile int g_reader_stop = 0;
static volatile int g_reader_passes = 0;
static volatile int g_reader_faults = 0;
static DxObject *g_overflow_worker = NULL;
static DxObject *g_born_worker = NULL;
static uint32_t g_seen_id[DX_MAX_EXEC_CONTEXTS];
static int g_seen_set[DX_MAX_EXEC_CONTEXTS];

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
    DxObject *self = (args && count > 0 && args[0].tag == DX_VAL_OBJ) ? args[0].obj : NULL;
    int i;
    (void)frame;
    if (self == g_born_worker) {
        __atomic_store_n(&g_born_entered, 1, __ATOMIC_RELEASE);
        while (__atomic_load_n(&g_born_release, __ATOMIC_ACQUIRE) == 0) {
        }
        for (i = 0; i < 4; i++) note(vm, (uint32_t)i, "bornOnly");
        __atomic_store_n(&g_born_finished, 1, __ATOMIC_RELEASE);
        return DX_OK;
    }
    if (self != g_overflow_worker) return DX_OK;
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

static const char *name_for_id(uint32_t exec_id) {
    if (exec_id == 0) return "rootOnly";
    if (exec_id == 1) return "workerOnly";
    if (exec_id == 2) return "bornOnly";
    return NULL;
}

/* One enumeration while another context may be published. A failed copy of
   an index below the snapshotted count is an unpublished slot. */
static int registry_pass(DxVM *vm) {
    uint32_t count = dx_vm_unresolved_context_count(vm);
    uint32_t i;
    if (count == 0 || count > DX_MAX_EXEC_CONTEXTS) return 0;
    for (i = 0; i < count; i++) {
        DxUnresolvedContextInfo info;
        const char *name;
        if (dx_vm_copy_unresolved_context(vm, i, &info) != 0) return 0;
        if (info.exec_id != i) return 0;
        if (g_seen_set[i] && g_seen_id[i] != info.exec_id) return 0;
        g_seen_id[i] = info.exec_id;
        g_seen_set[i] = 1;
        name = name_for_id(info.exec_id);
        if (!name) return 0;
        if (!events_are(vm, i, info.count, name)) return 0;
    }
    return 1;
}

static void *reader_main(void *arg) {
    DxVM *vm = (DxVM *)arg;
    while (__atomic_load_n(&g_reader_stop, __ATOMIC_ACQUIRE) == 0) {
        if (!registry_pass(vm))
            __atomic_fetch_add(&g_reader_faults, 1, __ATOMIC_RELAXED);
        __atomic_fetch_add(&g_reader_passes, 1, __ATOMIC_RELAXED);
    }
    if (!registry_pass(vm))
        __atomic_fetch_add(&g_reader_faults, 1, __ATOMIC_RELAXED);
    return NULL;
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
    DxUnresolvedContextInfo born;
    uint32_t root_index = 0;
    uint32_t worker_index = 0;
    uint32_t born_index = 0;
    pthread_t reader;
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
    g_overflow_worker = thread;
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

    expect(pthread_create(&reader, NULL, reader_main, vm) == 0, "diagnostic reader starts");
    for (i = 0; i < 2000 && __atomic_load_n(&g_reader_passes, __ATOMIC_ACQUIRE) == 0; i++)
        usleep(1000);
    expect(g_reader_passes > 0, "reader enumerated the published contexts");
    thread = dx_vm_alloc_object(vm, thread_cls);
    g_born_worker = thread;
    args[0] = DX_OBJ_VALUE(thread);
    expect(thread && dx_vm_execute_method(vm, start, args, 1, NULL) == DX_OK,
           "start a context while the reader enumerates");
    for (i = 0; i < 2000 && __atomic_load_n(&g_born_entered, __ATOMIC_ACQUIRE) == 0; i++)
        usleep(1000);
    expect(g_born_entered == 1, "new worker entered its own execution context");
    __atomic_store_n(&g_born_release, 1, __ATOMIC_RELEASE);
    for (i = 0; i < 2000 && __atomic_load_n(&g_born_finished, __ATOMIC_ACQUIRE) == 0; i++)
        usleep(1000);
    expect(g_born_finished == 1, "new worker published its own trace");
    expect(dx_vm_execute_method(vm, join, args, 1, NULL) == DX_OK, "join new worker");
    __atomic_store_n(&g_reader_stop, 1, __ATOMIC_RELEASE);
    expect(pthread_join(reader, NULL) == 0, "diagnostic reader finished");
    expect(g_reader_faults == 0, "registry enumeration saw only published contexts");
    expect(context_by_id(vm, 2, &born, &born_index), "the new context is enumerable after publication");
    expect(born.count == 4 && born.dropped == 0, "the new context keeps its own count");
    expect(events_are(vm, born_index, born.count, "bornOnly"),
           "the new context contains only its own unresolved events");
    expect(context_by_id(vm, 0, &root, &root_index) &&
           root.count == DX_UNRESOLVED_TRACE_CAP && root.dropped == 2 &&
           events_are(vm, root_index, root.count, "rootOnly"),
           "root trace stayed intact while another context was published");
    expect(context_by_id(vm, 1, &worker, &worker_index) &&
           worker.count == DX_UNRESOLVED_TRACE_CAP && worker.dropped == 2 &&
           events_are(vm, worker_index, worker.count, "workerOnly"),
           "the first worker trace stayed intact while another context was published");

    if (g_failures) {
        fprintf(stderr, "%d unresolved-context checks failed\n", g_failures);
        return 1;
    }
    printf("unresolved context contract: PASS\n");
    return 0;
}
