#include "../Include/dx_vm.h"
#include "../Include/dx_log.h"
#include "../Include/dx_memory.h"
#include "../agr_forensic.h"

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <errno.h>

#define TAG "Thread"

__thread DxExecutionContext *dx_tls_exec;

static void set_state(DxExecutionContext *exec, DxJavaThreadState state) {
    __atomic_store_n((int *)&exec->state, (int)state, __ATOMIC_RELEASE);
}

static DxJavaThreadState get_state(DxExecutionContext *exec) {
    return (DxJavaThreadState)__atomic_load_n((int *)&exec->state, __ATOMIC_ACQUIRE);
}

extern void agr_forensic_publish(const agr_forensic_sample *) __attribute__((weak));

static uint32_t forensic_thread_state(DxExecutionContext *exec) {
    DxJavaThreadState state = exec ? get_state(exec) : DX_JAVA_THREAD_NEW;
    if (state == DX_JAVA_THREAD_STARTING) return 1;
    if (state == DX_JAVA_THREAD_RUNNING && exec && exec->at_safepoint) return 3;
    if (state == DX_JAVA_THREAD_RUNNING) return 2;
    if (state == DX_JAVA_THREAD_TERMINATED) return 4;
    return 0;
}

static void monitor_owner_snapshot(DxExecutionContext *exec, int *owner, uint32_t *recursion);

static void forensic_thread(uint32_t phase, DxExecutionContext *exec) {
    agr_forensic_sample sample;
    if (!agr_forensic_publish || !exec) return;
    memset(&sample, 0, sizeof(sample));
    sample.phase = phase;
    sample.critical = 1;
    sample.has_exec = 1;
    sample.exec_id = exec->id;
    sample.thread_state = forensic_thread_state(exec);
    sample.host_thread = exec->has_host_thread ? (uint64_t)(uintptr_t)exec->host_thread : (uint64_t)pthread_self();
    agr_forensic_publish(&sample);
}

static void forensic_exec_snapshot(DxExecutionContext *exec, const char *when) {
    agr_forensic_sample sample;
    const char *cls = "";
    const char *method = "";
    const char *pending = "";
    const char *thread_cls = "";
    uint32_t pc = 0;
    int monitor_owner = 0;
    uint32_t recursion = 0;
    DxValue field;
    if (!agr_forensic_publish || !exec) return;
    if (exec->current_frame && exec->current_frame->method) {
        pc = exec->current_frame->pc;
        if (exec->current_frame->method->name)
            method = exec->current_frame->method->name;
        if (exec->current_frame->method->declaring_class &&
            exec->current_frame->method->declaring_class->descriptor)
            cls = exec->current_frame->method->declaring_class->descriptor;
    }
    if (exec->pending_exception && exec->pending_exception->klass &&
        exec->pending_exception->klass->descriptor)
        pending = exec->pending_exception->klass->descriptor;
    monitor_owner_snapshot(exec, &monitor_owner, &recursion);
    memset(&sample, 0, sizeof(sample));
    sample.phase = AGR_PHYS_PHASE_GUEST_EXEC_SNAPSHOT;
    sample.has_exec = 1;
    sample.exec_id = exec->id;
    sample.thread_state = forensic_thread_state(exec);
    sample.host_thread = exec->has_host_thread ? (uint64_t)(uintptr_t)exec->host_thread : (uint64_t)pthread_self();
    snprintf(sample.class_name, sizeof(sample.class_name), "%s", cls);
    snprintf(sample.method_name, sizeof(sample.method_name), "%s", method);
    snprintf(sample.detail, sizeof(sample.detail),
             "when=%s pc=%u pending=%s wait_vm=%d safepoint=%d monitor_owner=%d recursion=%u",
             when ? when : "-", pc, pending[0] ? pending : "-",
             exec->waiting_for_vm_lock ? 1 : 0, exec->at_safepoint ? 1 : 0,
             monitor_owner, recursion);
    agr_forensic_publish(&sample);
    if (!exec->java_thread || !exec->java_thread->klass || !exec->java_thread->klass->descriptor)
        return;
    thread_cls = exec->java_thread->klass->descriptor;
    if (!strstr(thread_cls, "GameThread")) return;
    memset(&field, 0, sizeof(field));
    if (dx_vm_get_field(exec->java_thread, "mRun", &field) == DX_OK) {
        memset(&sample, 0, sizeof(sample));
        sample.phase = AGR_PHYS_PHASE_DIAGNOSTIC_FIELD_WITNESS;
        sample.has_exec = 1;
        sample.exec_id = exec->id;
        sample.host_thread = exec->has_host_thread ? (uint64_t)(uintptr_t)exec->host_thread : (uint64_t)pthread_self();
        snprintf(sample.class_name, sizeof(sample.class_name), "%s", thread_cls);
        snprintf(sample.method_name, sizeof(sample.method_name), "mRun");
        snprintf(sample.detail, sizeof(sample.detail), "when=%s mRun=%d",
                 when ? when : "-", field.tag == DX_VAL_INT ? field.i : -1);
        agr_forensic_publish(&sample);
    }
    memset(&field, 0, sizeof(field));
    if (dx_vm_get_field(exec->java_thread, "mImagesReady", &field) == DX_OK) {
        memset(&sample, 0, sizeof(sample));
        sample.phase = AGR_PHYS_PHASE_DIAGNOSTIC_FIELD_WITNESS;
        sample.has_exec = 1;
        sample.exec_id = exec->id;
        sample.host_thread = exec->has_host_thread ? (uint64_t)(uintptr_t)exec->host_thread : (uint64_t)pthread_self();
        snprintf(sample.class_name, sizeof(sample.class_name), "%s", thread_cls);
        snprintf(sample.method_name, sizeof(sample.method_name), "mImagesReady");
        snprintf(sample.detail, sizeof(sample.detail), "when=%s mImagesReady=%d",
                 when ? when : "-", field.tag == DX_VAL_INT ? field.i : -1);
        agr_forensic_publish(&sample);
    }
}

void dx_vm_forensic_exec_snapshot(DxVM *vm, const char *when) {
    if (!vm) return;
    forensic_exec_snapshot(dx_vm_current_exec(vm), when);
}

static const char *thread_state_name(DxJavaThreadState state) {
    switch (state) {
    case DX_JAVA_THREAD_NEW: return "NEW";
    case DX_JAVA_THREAD_STARTING: return "STARTING";
    case DX_JAVA_THREAD_RUNNING: return "RUNNING";
    case DX_JAVA_THREAD_TERMINATED: return "TERMINATED";
    }
    return "?";
}

static unsigned long host_id(pthread_t thread) {
    return (unsigned long)(uintptr_t)thread;
}

DxExecutionContext *dx_vm_current_exec(DxVM *vm) {
    if (!vm) return NULL;
    if (dx_tls_exec && dx_tls_exec->vm == vm) return dx_tls_exec;
    if (!vm->root_exec) return NULL;
    dx_tls_exec = vm->root_exec;
    if (!vm->root_exec->has_host_thread) {
        vm->root_exec->host_thread = pthread_self();
        vm->root_exec->has_host_thread = 1;
    }
    return dx_tls_exec;
}

void dx_vm_shared_lock(DxVM *vm) {
    if (!vm || !vm->shared_ready) return;
    DxExecutionContext *exec = dx_tls_exec;
    int tracked = exec && exec->vm == vm;
    if (tracked && __atomic_load_n(&exec->vm_lock_depth, __ATOMIC_ACQUIRE) > 0) {
        pthread_mutex_lock(&vm->shared_mu);
        __atomic_add_fetch(&exec->vm_lock_depth, 1, __ATOMIC_ACQ_REL);
        return;
    }
    if (tracked)
        __atomic_store_n(&exec->waiting_for_vm_lock, 1, __ATOMIC_RELEASE);
    pthread_mutex_lock(&vm->shared_mu);
    if (tracked) {
        __atomic_store_n(&exec->waiting_for_vm_lock, 0, __ATOMIC_RELEASE);
        __atomic_add_fetch(&exec->vm_lock_depth, 1, __ATOMIC_ACQ_REL);
    }
}

void dx_vm_shared_lock_current(void) {
    if (dx_tls_exec && dx_tls_exec->vm) dx_vm_shared_lock(dx_tls_exec->vm);
}

void dx_vm_shared_unlock_current(void) {
    if (dx_tls_exec && dx_tls_exec->vm) dx_vm_shared_unlock(dx_tls_exec->vm);
}

void dx_vm_shared_unlock(DxVM *vm) {
    if (!vm || !vm->shared_ready) return;
    DxExecutionContext *exec = dx_tls_exec;
    if (exec && exec->vm == vm && __atomic_load_n(&exec->vm_lock_depth, __ATOMIC_ACQUIRE) > 0)
        __atomic_sub_fetch(&exec->vm_lock_depth, 1, __ATOMIC_ACQ_REL);
    pthread_mutex_unlock(&vm->shared_mu);
}

static DxExecutionContext *exec_create(DxVM *vm, DxObject *java_thread, uint64_t insn_limit) {
    if (!vm || vm->exec_count >= DX_MAX_EXEC_CONTEXTS) return NULL;
    DxExecutionContext *exec = (DxExecutionContext *)dx_malloc(sizeof(DxExecutionContext));
    if (!exec) return NULL;
    memset(exec, 0, sizeof(*exec));
    exec->id = vm->next_exec_id++;
    exec->vm = vm;
    exec->java_thread = java_thread;
    exec->state = DX_JAVA_THREAD_NEW;
    exec->insn_limit = insn_limit;
    pthread_mutex_init(&exec->life_mu, NULL);
    pthread_cond_init(&exec->done_cv, NULL);
    vm->execs[vm->exec_count++] = exec;
    return exec;
}

void dx_exec_vm_init(DxVM *vm) {
    if (!vm || vm->shared_ready) return;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&vm->shared_mu, &attr);
    pthread_mutexattr_destroy(&attr);
    pthread_mutex_init(&vm->safepoint_mu, NULL);
    pthread_cond_init(&vm->safepoint_cv, NULL);
    vm->shared_ready = 1;
    vm->root_exec = exec_create(vm, NULL, 0);
    if (vm->root_exec) {
        set_state(vm->root_exec, DX_JAVA_THREAD_RUNNING);
        vm->root_exec->host_thread = pthread_self();
        vm->root_exec->has_host_thread = 1;
        dx_tls_exec = vm->root_exec;
    }
}

static int exec_is_blocked_for_gc(DxExecutionContext *exec) {
    if (!exec) return 1;
    if (__atomic_load_n(&exec->waiting_for_vm_lock, __ATOMIC_ACQUIRE)) return 1;
    /* A context that holds the shared lock is still mutating VM state.
       It must not be treated as stopped, or GC waits on a lock that
       context still owns. */
    if (__atomic_load_n(&exec->vm_lock_depth, __ATOMIC_ACQUIRE) > 0) return 0;
    if (__atomic_load_n(&exec->in_vm, __ATOMIC_ACQUIRE) == 0) return 1;
    if (__atomic_load_n(&exec->at_safepoint, __ATOMIC_ACQUIRE)) return 1;
    return 0;
}

static void safepoint_begin(DxVM *vm) {
    DxExecutionContext *self = dx_vm_current_exec(vm);
    __atomic_store_n(&vm->safepoint_requested, 1, __ATOMIC_RELEASE);
    pthread_mutex_lock(&vm->safepoint_mu);
    for (;;) {
        int pending = 0;
        for (uint32_t i = 0; i < vm->exec_count; i++) {
            DxExecutionContext *exec = vm->execs[i];
            if (!exec || exec == self) continue;
            if (exec_is_blocked_for_gc(exec)) continue;
            pending = 1;
            break;
        }
        if (!pending) break;
        pthread_cond_wait(&vm->safepoint_cv, &vm->safepoint_mu);
    }
    pthread_mutex_unlock(&vm->safepoint_mu);
}

static void safepoint_end(DxVM *vm) {
    pthread_mutex_lock(&vm->safepoint_mu);
    __atomic_store_n(&vm->safepoint_requested, 0, __ATOMIC_RELEASE);
    pthread_cond_broadcast(&vm->safepoint_cv);
    pthread_mutex_unlock(&vm->safepoint_mu);
}

void dx_exec_gc_begin(DxVM *vm) {
    if (!vm) return;
    vm->safepoint_depth++;
    if (vm->safepoint_depth == 1) safepoint_begin(vm);
}

void dx_exec_gc_end(DxVM *vm) {
    if (!vm || vm->safepoint_depth <= 0) return;
    vm->safepoint_depth--;
    if (vm->safepoint_depth == 0) safepoint_end(vm);
}

static void safepoint_wait(DxExecutionContext *exec) {
    if (!exec || !exec->vm) return;
    pthread_mutex_lock(&exec->vm->safepoint_mu);
    __atomic_store_n(&exec->at_safepoint, 1, __ATOMIC_RELEASE);
    pthread_cond_broadcast(&exec->vm->safepoint_cv);
    while (__atomic_load_n(&exec->vm->safepoint_requested, __ATOMIC_ACQUIRE) &&
           !exec->stop_requested) {
        pthread_cond_wait(&exec->vm->safepoint_cv, &exec->vm->safepoint_mu);
    }
    __atomic_store_n(&exec->at_safepoint, 0, __ATOMIC_RELEASE);
    pthread_mutex_unlock(&exec->vm->safepoint_mu);
}

DxResult dx_vm_exec_poll(DxVM *vm) {
    DxExecutionContext *exec = dx_vm_current_exec(vm);
    if (!exec) return DX_OK;
    if (exec->stop_requested) return DX_ERR_CANCELLED;
    /* Do not wait at a safepoint while this context owns the shared lock. */
    if (__atomic_load_n(&exec->vm_lock_depth, __ATOMIC_ACQUIRE) > 0) return DX_OK;
    if (vm && __atomic_load_n(&vm->safepoint_requested, __ATOMIC_ACQUIRE))
        safepoint_wait(exec);
    if (exec->stop_requested) return DX_ERR_CANCELLED;
    return DX_OK;
}

void dx_exec_enter(DxExecutionContext *exec) {
    if (exec) __atomic_add_fetch(&exec->in_vm, 1, __ATOMIC_ACQ_REL);
}

void dx_exec_leave(DxExecutionContext *exec) {
    if (exec) __atomic_sub_fetch(&exec->in_vm, 1, __ATOMIC_ACQ_REL);
}

static DxExecutionContext *exec_for_thread(DxVM *vm, DxObject *thread) {
    if (!vm || !thread) return NULL;
    dx_vm_shared_lock(vm);
    DxExecutionContext *found = NULL;
    for (uint32_t i = 0; i < vm->exec_count; i++) {
        if (vm->execs[i] && vm->execs[i]->java_thread == thread) {
            found = vm->execs[i];
            break;
        }
    }
    dx_vm_shared_unlock(vm);
    return found;
}

static void throw_on(DxVM *vm, const char *descriptor, const char *message) {
    DxExecutionContext *exec = dx_vm_current_exec(vm);
    if (!exec || exec->pending_exception) return;
    exec->pending_exception = dx_vm_create_exception(vm, descriptor, message);
}

static void thread_log(const char *event, DxExecutionContext *caller, DxExecutionContext *worker,
                       const char *method) {
    fprintf(stderr,
            "JTHREAD event=%s caller_exec=%u caller_host=%lu worker_exec=%u worker_host=%lu java=%p state=%s method=%s\n",
            event ? event : "?",
            caller ? caller->id : 0,
            caller && caller->has_host_thread ? host_id(caller->host_thread) : 0,
            worker ? worker->id : 0,
            worker && worker->has_host_thread ? host_id(worker->host_thread) : 0,
            worker && worker->java_thread ? (void *)worker->java_thread :
                (caller && caller->java_thread ? (void *)caller->java_thread : NULL),
            worker ? thread_state_name(get_state(worker)) :
                (caller ? thread_state_name(get_state(caller)) : "?"),
            method ? method : "-");
}

static void *java_worker_main(void *arg) {
    DxExecutionContext *exec = (DxExecutionContext *)arg;
    dx_tls_exec = exec;
    exec->host_thread = pthread_self();
    exec->has_host_thread = 1;
    set_state(exec, DX_JAVA_THREAD_RUNNING);
    forensic_thread(AGR_PHYS_PHASE_THREAD_RUN_ENTER, exec);
    forensic_exec_snapshot(exec, "THREAD_RUN_ENTER");
    if (exec->java_thread && exec->java_thread->klass && exec->java_thread->klass->descriptor &&
        strstr(exec->java_thread->klass->descriptor, "GameThread"))
        dx_vm_set_draw_witness(exec->vm, 256);
    DxObject *self = exec->java_thread;
    const char *method_name = "run";
    DxMethod *run = NULL;
    if (self && self->klass)
        run = dx_vm_find_method(self->klass, "run", "V");
    thread_log("run_enter", NULL, exec,
               run && run->declaring_class && run->declaring_class->descriptor
                   ? run->declaring_class->descriptor : method_name);
    DxResult rc = DX_ERR_METHOD_NOT_FOUND;
    if (run) {
        DxValue args[1];
        args[0] = DX_OBJ_VALUE(self);
        rc = dx_vm_execute_method(exec->vm, run, args, 1, NULL);
    } else if (self && self->klass) {
        DX_WARN(TAG, "Thread worker found no run() on %s", self->klass->descriptor);
    }
    const char *exc_name = NULL;
    if (rc == DX_ERR_EXCEPTION && exec->pending_exception && exec->pending_exception->klass)
        exc_name = exec->pending_exception->klass->descriptor;
    pthread_mutex_lock(&exec->life_mu);
    set_state(exec, DX_JAVA_THREAD_TERMINATED);
    pthread_cond_broadcast(&exec->done_cv);
    pthread_mutex_unlock(&exec->life_mu);
    forensic_thread(AGR_PHYS_PHASE_THREAD_RUN_EXIT, exec);
    fprintf(stderr,
            "JTHREAD event=%s caller_exec=0 caller_host=0 worker_exec=%u worker_host=%lu java=%p state=%s method=%s rc=%d exception=%s insns=%llu error=%s\n",
            rc == DX_OK ? "run_exit" : "run_exit_error",
            exec->id,
            exec->has_host_thread ? host_id(exec->host_thread) : 0,
            exec->java_thread ? (void *)exec->java_thread : NULL,
            thread_state_name(get_state(exec)),
            method_name,
            (int)rc,
            exc_name ? exc_name : "-",
            (unsigned long long)exec->insn_count,
            exec->error_msg[0] ? exec->error_msg : "-");
    return NULL;
}

static void wake_exec(DxExecutionContext *exec) {
    if (!exec) return;
    exec->stop_requested = 1;
    pthread_mutex_lock(&exec->life_mu);
    pthread_cond_broadcast(&exec->done_cv);
    pthread_mutex_unlock(&exec->life_mu);
    if (exec->vm) {
        pthread_mutex_lock(&exec->vm->safepoint_mu);
        pthread_cond_broadcast(&exec->vm->safepoint_cv);
        pthread_mutex_unlock(&exec->vm->safepoint_mu);
    }
}

DxResult native_thread_start(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)frame;
    (void)arg_count;
    DxObject *self = args && arg_count > 0 ? args[0].obj : NULL;
    if (!self || !self->klass) {
        throw_on(vm, "Ljava/lang/NullPointerException;", "Thread.start");
        return DX_ERR_EXCEPTION;
    }
    DxResult monitor = dx_vm_monitor_enter(vm, self);
    if (monitor != DX_OK) return monitor;

    dx_vm_shared_lock(vm);
    DxExecutionContext *existing = exec_for_thread(vm, self);
    if (existing) {
        dx_vm_shared_unlock(vm);
        dx_vm_monitor_exit(vm, self);
        throw_on(vm, "Ljava/lang/IllegalThreadStateException;", "Thread already started");
        return DX_ERR_EXCEPTION;
    }
    DxExecutionContext *exec = exec_create(vm, self, 0);
    if (!exec) {
        dx_vm_shared_unlock(vm);
        dx_vm_monitor_exit(vm, self);
        throw_on(vm, "Ljava/lang/OutOfMemoryError;", "Thread execution context");
        return DX_ERR_EXCEPTION;
    }
    set_state(exec, DX_JAVA_THREAD_STARTING);
    dx_vm_shared_unlock(vm);

    int created = pthread_create(&exec->host_thread, NULL, java_worker_main, exec);
    if (created != 0) {
        set_state(exec, DX_JAVA_THREAD_TERMINATED);
        exec->has_host_thread = 0;
        thread_log("start_failed", dx_vm_current_exec(vm), exec, "start");
        dx_vm_monitor_exit(vm, self);
        throw_on(vm, "Ljava/lang/OutOfMemoryError;", "pthread_create failed");
        return DX_ERR_EXCEPTION;
    }
    exec->has_host_thread = 1;
    exec->joinable = 1;
    thread_log("start", dx_vm_current_exec(vm), exec, "start");
    forensic_thread(AGR_PHYS_PHASE_THREAD_START, exec);
    forensic_thread(AGR_PHYS_PHASE_EXEC_PUBLISHED, exec);
    dx_vm_monitor_exit(vm, self);
    return DX_OK;
}

DxResult native_thread_isalive(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)arg_count;
    DxObject *self = args ? args[0].obj : NULL;
    DxExecutionContext *exec = exec_for_thread(vm, self);
    int alive = 0;
    if (exec) {
        DxJavaThreadState state = get_state(exec);
        alive = state == DX_JAVA_THREAD_STARTING || state == DX_JAVA_THREAD_RUNNING;
    }
    frame->result = DX_INT_VALUE(alive ? 1 : 0);
    frame->has_result = true;
    return DX_OK;
}

DxResult native_thread_current(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)args;
    (void)arg_count;
    DxExecutionContext *exec = dx_vm_current_exec(vm);
    if (exec && !exec->java_thread) {
        DxClass *thread_cls = dx_vm_find_class(vm, "Ljava/lang/Thread;");
        if (thread_cls) {
            dx_vm_shared_lock(vm);
            if (!exec->java_thread) {
                exec->java_thread = dx_vm_alloc_object(vm, thread_cls);
                if (get_state(exec) == DX_JAVA_THREAD_NEW)
                    set_state(exec, DX_JAVA_THREAD_RUNNING);
            }
            dx_vm_shared_unlock(vm);
        }
    }
    frame->result = exec && exec->java_thread ? DX_OBJ_VALUE(exec->java_thread) : DX_NULL_VALUE;
    frame->has_result = true;
    return DX_OK;
}

DxResult native_thread_join(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)frame;
    DxObject *self = args && arg_count > 0 ? args[0].obj : NULL;
    DxExecutionContext *target = exec_for_thread(vm, self);
    DxExecutionContext *caller = dx_vm_current_exec(vm);
    if (!target || get_state(target) == DX_JAVA_THREAD_TERMINATED || get_state(target) == DX_JAVA_THREAD_NEW) {
        if (target && target->joinable) {
            pthread_join(target->host_thread, NULL);
            target->joinable = 0;
        }
        return DX_OK;
    }
    if (target == caller) {
        throw_on(vm, "Ljava/lang/IllegalThreadStateException;", "join on the current thread");
        return DX_ERR_EXCEPTION;
    }
    pthread_mutex_lock(&target->life_mu);
    while (get_state(target) == DX_JAVA_THREAD_STARTING || get_state(target) == DX_JAVA_THREAD_RUNNING) {
        if (caller) __atomic_store_n(&caller->at_safepoint, 1, __ATOMIC_RELEASE);
        pthread_cond_wait(&target->done_cv, &target->life_mu);
        if (caller) __atomic_store_n(&caller->at_safepoint, 0, __ATOMIC_RELEASE);
        if (caller && caller->stop_requested) break;
    }
    pthread_mutex_unlock(&target->life_mu);
    if (target->joinable && get_state(target) == DX_JAVA_THREAD_TERMINATED) {
        pthread_join(target->host_thread, NULL);
        target->joinable = 0;
    }
    return DX_OK;
}

static void sleep_ms(DxExecutionContext *exec, int64_t millis) {
    if (millis < 0) millis = 0;
    while (millis > 0 && exec && !exec->stop_requested) {
        if (exec->vm && __atomic_load_n(&exec->vm->safepoint_requested, __ATOMIC_ACQUIRE))
            safepoint_wait(exec);
        uint32_t slice = millis > 10 ? 10 : (uint32_t)millis;
        struct timespec ts;
        ts.tv_sec = slice / 1000;
        ts.tv_nsec = (long)(slice % 1000) * 1000000L;
        if (exec) __atomic_store_n(&exec->at_safepoint, 1, __ATOMIC_RELEASE);
        nanosleep(&ts, NULL);
        if (exec) __atomic_store_n(&exec->at_safepoint, 0, __ATOMIC_RELEASE);
        millis -= slice;
    }
}

DxResult native_thread_sleep(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count) {
    (void)frame;
    if (!args || arg_count < 1) return DX_OK;
    int64_t millis = 0;
    if (args[0].tag == DX_VAL_LONG) millis = args[0].l;
    else if (args[0].tag == DX_VAL_INT) millis = args[0].i;
    if (millis < 0) {
        throw_on(vm, "Ljava/lang/IllegalArgumentException;", "timeout < 0");
        return DX_ERR_EXCEPTION;
    }
    sleep_ms(dx_vm_current_exec(vm), millis);
    return DX_OK;
}

typedef struct DxMonitor {
    pthread_mutex_t mu;
    pthread_cond_t cv;
    DxExecutionContext *owner;
    uint32_t recursion;
} DxMonitor;

static void monitor_owner_snapshot(DxExecutionContext *exec, int *owner, uint32_t *recursion) {
    DxMonitor *monitor;
    if (owner) *owner = 0;
    if (recursion) *recursion = 0;
    if (!exec || !exec->java_thread || !exec->java_thread->monitor) return;
    monitor = (DxMonitor *)exec->java_thread->monitor;
    if (owner) *owner = monitor->owner == exec;
    if (recursion) *recursion = monitor->recursion;
}

static DxMonitor *monitor_of(DxVM *vm, DxObject *obj) {
    if (!obj) return NULL;
    dx_vm_shared_lock(vm);
    if (!obj->monitor) {
        DxMonitor *monitor = (DxMonitor *)dx_malloc(sizeof(DxMonitor));
        if (monitor) {
            memset(monitor, 0, sizeof(*monitor));
            pthread_mutex_init(&monitor->mu, NULL);
            pthread_cond_init(&monitor->cv, NULL);
            obj->monitor = monitor;
        }
    }
    DxMonitor *monitor = (DxMonitor *)obj->monitor;
    dx_vm_shared_unlock(vm);
    return monitor;
}

DxResult dx_vm_monitor_enter(DxVM *vm, DxObject *obj) {
    if (!obj) {
        throw_on(vm, "Ljava/lang/NullPointerException;", "monitor-enter");
        return DX_ERR_EXCEPTION;
    }
    DxMonitor *monitor = monitor_of(vm, obj);
    DxExecutionContext *self = dx_vm_current_exec(vm);
    if (!monitor || !self) return DX_ERR_OUT_OF_MEMORY;
    pthread_mutex_lock(&monitor->mu);
    while (monitor->owner && monitor->owner != self && !self->stop_requested) {
        __atomic_store_n(&self->at_safepoint, 1, __ATOMIC_RELEASE);
        pthread_cond_wait(&monitor->cv, &monitor->mu);
        __atomic_store_n(&self->at_safepoint, 0, __ATOMIC_RELEASE);
    }
    if (self->stop_requested) {
        pthread_mutex_unlock(&monitor->mu);
        return DX_ERR_CANCELLED;
    }
    monitor->owner = self;
    monitor->recursion++;
    pthread_mutex_unlock(&monitor->mu);
    return DX_OK;
}

DxResult dx_vm_monitor_exit(DxVM *vm, DxObject *obj) {
    if (!obj) {
        throw_on(vm, "Ljava/lang/NullPointerException;", "monitor-exit");
        return DX_ERR_EXCEPTION;
    }
    DxMonitor *monitor = monitor_of(vm, obj);
    DxExecutionContext *self = dx_vm_current_exec(vm);
    if (!monitor || !self) return DX_ERR_OUT_OF_MEMORY;
    pthread_mutex_lock(&monitor->mu);
    if (monitor->owner != self || monitor->recursion == 0) {
        pthread_mutex_unlock(&monitor->mu);
        throw_on(vm, "Ljava/lang/IllegalMonitorStateException;", "monitor-exit");
        return DX_ERR_EXCEPTION;
    }
    monitor->recursion--;
    if (monitor->recursion == 0) {
        monitor->owner = NULL;
        pthread_cond_broadcast(&monitor->cv);
    }
    pthread_mutex_unlock(&monitor->mu);
    return DX_OK;
}

static void free_monitors(DxVM *vm) {
    for (uint32_t i = 0; i < vm->heap_count; i++) {
        DxObject *obj = vm->heap[i];
        if (!obj || !obj->monitor) continue;
        DxMonitor *monitor = (DxMonitor *)obj->monitor;
        pthread_cond_destroy(&monitor->cv);
        pthread_mutex_destroy(&monitor->mu);
        dx_free(monitor);
        obj->monitor = NULL;
    }
}

void dx_exec_vm_shutdown(DxVM *vm) {
    if (!vm) return;
    for (uint32_t i = 0; i < vm->exec_count; i++) {
        DxExecutionContext *exec = vm->execs[i];
        if (!exec || exec == vm->root_exec) continue;
        wake_exec(exec);
    }
    for (uint32_t i = 0; i < vm->exec_count; i++) {
        DxExecutionContext *exec = vm->execs[i];
        if (!exec || exec == vm->root_exec || !exec->joinable) continue;
        pthread_join(exec->host_thread, NULL);
        exec->joinable = 0;
        set_state(exec, DX_JAVA_THREAD_TERMINATED);
    }
    free_monitors(vm);
    /* Free published contexts under the registry lock so a diagnostic
       snapshot cannot observe a pointer after it is released. */
    dx_vm_shared_lock(vm);
    for (uint32_t i = 0; i < vm->exec_count; i++) {
        DxExecutionContext *exec = vm->execs[i];
        if (!exec || exec == vm->root_exec) continue;
        for (uint32_t f = 0; f < exec->frame_pool_count; f++)
            dx_free(exec->frame_pool[f]);
        exec->frame_pool_count = 0;
        pthread_mutex_destroy(&exec->life_mu);
        pthread_cond_destroy(&exec->done_cv);
        if (dx_tls_exec == exec) dx_tls_exec = vm->root_exec;
        dx_free(exec);
        vm->execs[i] = NULL;
    }
    if (vm->root_exec) {
        vm->execs[0] = vm->root_exec;
        vm->exec_count = 1;
    } else {
        vm->exec_count = 0;
    }
    dx_vm_shared_unlock(vm);
}

void dx_exec_vm_fini(DxVM *vm) {
    if (!vm || !vm->shared_ready) return;
    dx_vm_shared_lock(vm);
    if (vm->root_exec) {
        for (uint32_t f = 0; f < vm->root_exec->frame_pool_count; f++)
            dx_free(vm->root_exec->frame_pool[f]);
        vm->root_exec->frame_pool_count = 0;
        pthread_mutex_destroy(&vm->root_exec->life_mu);
        pthread_cond_destroy(&vm->root_exec->done_cv);
        if (dx_tls_exec == vm->root_exec) dx_tls_exec = NULL;
        dx_free(vm->root_exec);
        vm->root_exec = NULL;
        if (vm->exec_count > 0) vm->execs[0] = NULL;
        vm->exec_count = 0;
    }
    dx_vm_shared_unlock(vm);
    pthread_mutex_destroy(&vm->shared_mu);
    pthread_mutex_destroy(&vm->safepoint_mu);
    pthread_cond_destroy(&vm->safepoint_cv);
    vm->shared_ready = 0;
}

uint32_t dx_vm_exec_snapshot_count(DxVM *vm) {
    return vm ? vm->exec_count : 0;
}

int dx_vm_copy_exec_snapshot(DxVM *vm, uint32_t index, DxExecSnapshot *out) {
    if (!vm || !out || index >= vm->exec_count || !vm->execs[index]) return -1;
    DxExecutionContext *exec = vm->execs[index];
    memset(out, 0, sizeof(*out));
    out->id = exec->id;
    out->stack_depth = exec->stack_depth;
    out->insn_count = exec->insn_count;
    out->insn_limit = exec->insn_limit;
    out->alive = get_state(exec) == DX_JAVA_THREAD_STARTING || get_state(exec) == DX_JAVA_THREAD_RUNNING;
    out->state = (int32_t)get_state(exec);
    out->has_exception = exec->pending_exception != NULL;
    out->host_thread = exec->has_host_thread ? host_id(exec->host_thread) : 0;
    if (exec->current_frame && exec->current_frame->method && exec->current_frame->method->name) {
        snprintf(out->method, sizeof(out->method), "%s", exec->current_frame->method->name);
    }
    return 0;
}
