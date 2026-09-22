/* Independent java.lang.Thread execution-context contract.
   start() returns while run() is still on another host thread. */
#include "dx_vm.h"
#include "dx_dex.h"
#include "dx_log.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

static int g_failures = 0;

enum {
    F_ACQUIRED = 0,
    F_AFTER,
    F_BEFORE,
    F_BURNED,
    F_CALLER_RELEASE,
    F_GATE,
    F_HELD,
    F_LOCK_OBJ,
    F_RECURSE,
    F_RELEASE,
    F_RUN_ENTERED,
    F_RUN_EXITED,
    F_SLEPT,
    F_COUNT
};

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static void reset_markers(DxClass *markers) {
    if (!markers || !markers->static_fields) return;
    for (uint32_t i = 0; i < markers->static_field_count && i < F_COUNT; i++) {
        if (i == F_LOCK_OBJ) continue;
        markers->static_fields[i] = DX_INT_VALUE(0);
    }
}

static int32_t marker(DxClass *markers, int field) {
    if (!markers || !markers->static_fields || (uint32_t)field >= markers->static_field_count)
        return -1;
    return markers->static_fields[field].i;
}

static DxMethod *static_method(DxClass *cls, const char *name) {
    if (!cls) return NULL;
    for (uint32_t i = 0; i < cls->direct_method_count; i++) {
        if (cls->direct_methods[i].name && strcmp(cls->direct_methods[i].name, name) == 0)
            return &cls->direct_methods[i];
    }
    return NULL;
}

static DxResult call_static(DxVM *vm, DxMethod *method, DxObject *arg) {
    DxValue value = arg ? DX_OBJ_VALUE(arg) : DX_NULL_VALUE;
    return dx_vm_execute_method(vm, method, arg ? &value : NULL, arg ? 1 : 0, NULL);
}

static int wait_marker(DxClass *markers, int field, int32_t expected) {
    for (int i = 0; i < 2000; i++) {
        if (marker(markers, field) == expected) return 1;
        usleep(1000);
    }
    return 0;
}

static uint64_t now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000ull + (uint64_t)ts.tv_nsec / 1000000ull;
}

typedef struct ObserveArgs {
    DxVM *vm;
    DxClass *markers;
    int saw_caller;
    int saw_worker;
    DxExecSnapshot caller;
    DxExecSnapshot worker;
} ObserveArgs;

static void *observe_async(void *arg) {
    ObserveArgs *obs = (ObserveArgs *)arg;
    for (int i = 0; i < 2000; i++) {
        if (marker(obs->markers, F_RUN_ENTERED) == 1 && marker(obs->markers, F_AFTER) == 1) {
            uint32_t count = dx_vm_exec_snapshot_count(obs->vm);
            for (uint32_t n = 0; n < count; n++) {
                DxExecSnapshot snap;
                if (dx_vm_copy_exec_snapshot(obs->vm, n, &snap) != 0) continue;
                if (snap.stack_depth > 0 && strcmp(snap.method, "probeAsync") == 0) {
                    obs->caller = snap;
                    obs->saw_caller = 1;
                }
                if (snap.stack_depth > 0 && strcmp(snap.method, "run") == 0) {
                    obs->worker = snap;
                    obs->saw_worker = 1;
                }
            }
            __sync_synchronize();
            obs->markers->static_fields[F_CALLER_RELEASE] = DX_INT_VALUE(1);
            return NULL;
        }
        usleep(1000);
    }
    return NULL;
}

static DxExecutionContext *root_exec(DxVM *vm) {
    return vm ? vm->root_exec : NULL;
}

int main(int argc, char **argv) {
    alarm(30);
    dx_log_set_level(DX_LOG_WARN);
    const char *path = argc > 1 ? argv[1] : "/tmp/thread-start.dex";
    FILE *file = fopen(path, "rb");
    if (!file) { perror(path); return 1; }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    uint8_t *bytes = malloc((size_t)size);
    if (!bytes || fread(bytes, 1, (size_t)size, file) != (size_t)size) return 1;
    fclose(file);

    DxDexFile *dex = NULL;
    if (dx_dex_parse(bytes, (uint32_t)size, &dex) != DX_OK) return 1;
    DxVM *vm = dx_vm_create(NULL);
    if (!vm || dx_register_java_lang(vm) != DX_OK || dx_vm_load_dex(vm, dex) != DX_OK) return 1;

    const char *names[] = {
        "Lsynth/Markers;", "Lsynth/Worker;", "Lsynth/Boom;", "Lsynth/Burner;",
        "Lsynth/Sleeper;", "Lsynth/Locker;", "Lsynth/Waiter;", "Lsynth/Probe;"
    };
    DxClass *loaded[8] = {0};
    for (int i = 0; i < 8; i++) {
        if (dx_vm_load_class(vm, names[i], &loaded[i]) != DX_OK || !loaded[i]) {
            fprintf(stderr, "load failed %s\n", names[i]);
            return 1;
        }
    }
    DxClass *markers = loaded[0];
    DxClass *worker_cls = loaded[1];
    DxClass *boom_cls = loaded[2];
    DxClass *burner_cls = loaded[3];
    DxClass *sleeper_cls = loaded[4];
    DxClass *locker_cls = loaded[5];
    DxClass *waiter_cls = loaded[6];
    DxClass *probe = loaded[7];
    DxClass *object = dx_vm_find_class(vm, "Ljava/lang/Object;");
    DxClass *thread = dx_vm_find_class(vm, "Ljava/lang/Thread;");
    DxMethod *join = dx_vm_find_method(thread, "join", "V");
    if (!object || !thread || !join || markers->static_field_count < F_COUNT) return 1;
    DxObject *lock = dx_vm_alloc_object(vm, object);
    if (!lock) return 1;
    markers->static_fields[F_LOCK_OBJ] = DX_OBJ_VALUE(lock);

    DxExecutionContext *caller = root_exec(vm);
    printf("caller_exec=%u caller_host=%lu\n", caller ? caller->id : 0,
           caller && caller->has_host_thread ? (unsigned long)(uintptr_t)caller->host_thread : 0);

    reset_markers(markers);
    DxObject *worker = dx_vm_alloc_object(vm, worker_cls);
    ObserveArgs obs;
    memset(&obs, 0, sizeof(obs));
    obs.vm = vm;
    obs.markers = markers;
    pthread_t observer;
    if (pthread_create(&observer, NULL, observe_async, &obs) != 0) return 1;
    DxResult async_rc = call_static(vm, static_method(probe, "probeAsync"), worker);
    pthread_join(observer, NULL);
    expect(async_rc == DX_OK, "probeAsync returns");
    expect(marker(markers, F_BEFORE) == 1, "beforeStart = 1");
    expect(marker(markers, F_AFTER) == 1, "afterStart = 1 while worker may still be running");
    expect(marker(markers, F_RUN_ENTERED) == 1, "runEntered = 1");
    expect(marker(markers, F_RUN_EXITED) == 0, "afterStart observed before run exited");
    expect(obs.saw_caller && obs.saw_worker, "caller and worker frames were live together");
    expect(obs.caller.id != obs.worker.id, "caller execution context != worker execution context");
    expect(obs.caller.host_thread != obs.worker.host_thread, "caller host thread != worker host thread");
    expect(obs.caller.stack_depth >= 1 && obs.worker.stack_depth >= 1, "both stacks are independent");
    printf("async caller_exec=%u caller_host=%lu caller_frame=%s depth=%u\n",
           obs.caller.id, obs.caller.host_thread, obs.caller.method, obs.caller.stack_depth);
    printf("async worker_exec=%u worker_host=%lu worker_frame=%s depth=%u\n",
           obs.worker.id, obs.worker.host_thread, obs.worker.method, obs.worker.stack_depth);
    markers->static_fields[F_GATE] = DX_INT_VALUE(1);
    expect(call_static(vm, join, worker) == DX_OK, "join running worker");
    expect(wait_marker(markers, F_RUN_EXITED, 1), "runExited after join");

    reset_markers(markers);
    DxObject *boom = dx_vm_alloc_object(vm, boom_cls);
    DxObject *caller_exc_before = caller ? caller->pending_exception : NULL;
    expect(call_static(vm, dx_vm_find_method(thread, "start", "V"), boom) == DX_OK, "start Boom");
    expect(call_static(vm, join, boom) == DX_OK, "join Boom");
    int boom_exception = 0;
    uint32_t snaps = dx_vm_exec_snapshot_count(vm);
    for (uint32_t i = 0; i < snaps; i++) {
        DxExecSnapshot snap;
        if (dx_vm_copy_exec_snapshot(vm, i, &snap) != 0) continue;
        if (snap.has_exception && snap.id != (caller ? caller->id : 0)) boom_exception = 1;
    }
    expect(caller && caller->pending_exception == caller_exc_before, "caller pending_exception unchanged");
    expect(boom_exception, "worker exception stays on the worker context");

    reset_markers(markers);
    DxObject *burner = dx_vm_alloc_object(vm, burner_cls);
    uint64_t caller_before = caller ? caller->insn_count : 0;
    uint64_t start_ms = now_ms();
    expect(call_static(vm, dx_vm_find_method(thread, "start", "V"), burner) == DX_OK, "start Burner");
    uint64_t caller_after = caller ? caller->insn_count : 0;
    expect(now_ms() - start_ms < 80, "Burner start returns without waiting for the loop");
    expect(call_static(vm, join, burner) == DX_OK, "join Burner");
    uint64_t worker_insns = 0;
    snaps = dx_vm_exec_snapshot_count(vm);
    for (uint32_t i = 0; i < snaps; i++) {
        DxExecSnapshot snap;
        if (dx_vm_copy_exec_snapshot(vm, i, &snap) != 0) continue;
        if (snap.insn_count > worker_insns && snap.id != (caller ? caller->id : 0))
            worker_insns = snap.insn_count;
    }
    printf("budget caller_delta=%llu worker_insns=%llu caller_limit=%llu\n",
           (unsigned long long)(caller_after - caller_before),
           (unsigned long long)worker_insns,
           (unsigned long long)(caller ? caller->insn_limit : 0));
    expect(caller_after - caller_before < 500000ull, "caller budget is not consumed by the worker");
    expect(worker_insns > 500000ull, "worker instruction count exceeds the caller budget");
    expect(marker(markers, F_BURNED) == 150000, "burned = 150000");

    reset_markers(markers);
    DxObject *sleeper = dx_vm_alloc_object(vm, sleeper_cls);
    start_ms = now_ms();
    expect(call_static(vm, dx_vm_find_method(thread, "start", "V"), sleeper) == DX_OK, "start Sleeper");
    uint64_t start_elapsed = now_ms() - start_ms;
    expect(start_elapsed < 80, "Thread.sleep does not block the caller");
    expect(marker(markers, F_SLEPT) == 0, "sleep has not finished when start returns");
    expect(call_static(vm, join, sleeper) == DX_OK, "join Sleeper");
    expect(marker(markers, F_SLEPT) == 1, "slept = 1");
    expect(now_ms() - start_ms >= 100, "sleep lasted on the worker");

    reset_markers(markers);
    DxObject *locker = dx_vm_alloc_object(vm, locker_cls);
    DxObject *waiter = dx_vm_alloc_object(vm, waiter_cls);
    expect(call_static(vm, dx_vm_find_method(thread, "start", "V"), locker) == DX_OK, "start Locker");
    expect(wait_marker(markers, F_HELD, 1), "locker holds the monitor");
    expect(call_static(vm, dx_vm_find_method(thread, "start", "V"), waiter) == DX_OK, "start Waiter");
    usleep(50000);
    expect(marker(markers, F_ACQUIRED) == 0, "waiter blocks while locker owns the monitor");
    markers->static_fields[F_RELEASE] = DX_INT_VALUE(1);
    expect(wait_marker(markers, F_ACQUIRED, 1), "waiter acquires after monitor-exit");
    expect(call_static(vm, join, locker) == DX_OK, "join Locker");
    expect(call_static(vm, join, waiter) == DX_OK, "join Waiter");

    reset_markers(markers);
    expect(call_static(vm, static_method(probe, "probeRecurse"), NULL) == DX_OK, "same-context monitor reentry");
    expect(marker(markers, F_RECURSE) == 1, "recurseOk = 1");

    reset_markers(markers);
    DxObject *twice = dx_vm_alloc_object(vm, worker_cls);
    DxResult twice_rc = call_static(vm, static_method(probe, "probeTwice"), twice);
    const char *twice_exc = caller && caller->pending_exception && caller->pending_exception->klass
        ? caller->pending_exception->klass->descriptor : "";
    expect(twice_rc == DX_ERR_EXCEPTION, "second Thread.start throws");
    expect(strcmp(twice_exc, "Ljava/lang/IllegalThreadStateException;") == 0, twice_exc);
    if (caller) caller->pending_exception = NULL;
    markers->static_fields[F_GATE] = DX_INT_VALUE(1);
    expect(call_static(vm, join, twice) == DX_OK, "join the single worker from the rejected second start");

    dx_vm_destroy(vm);
    dx_dex_free(dex);
    free(bytes);
    if (g_failures) {
        printf("thread start contract: FAIL (%d)\n", g_failures);
        return 1;
    }
    printf("thread start contract: PASS\n");
    return 0;
}
