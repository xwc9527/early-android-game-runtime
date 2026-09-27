#ifndef DX_THREAD_STATE_H
#define DX_THREAD_STATE_H

#include "dx_vm.h"
#include <stdint.h>

/* Dalvik ThreadStatus from platform/dalvik vm/Thread.h. These values are not
 * DxJavaThreadState. */
enum {
    DX_DALVIK_THREAD_UNDEFINED = -1,
    DX_DALVIK_THREAD_ZOMBIE = 0,
    DX_DALVIK_THREAD_RUNNING = 1,
    DX_DALVIK_THREAD_TIMED_WAIT = 2,
    DX_DALVIK_THREAD_MONITOR = 3,
    DX_DALVIK_THREAD_WAIT = 4,
    DX_DALVIK_THREAD_INITIALIZING = 5,
    DX_DALVIK_THREAD_STARTING = 6,
    DX_DALVIK_THREAD_NATIVE = 7,
    DX_DALVIK_THREAD_VMWAIT = 8,
    DX_DALVIK_THREAD_SUSPENDED = 9
};

/* Prepare the D010 host words and call pthread_mutex_init(NULL) /
 * pthread_cond_init(NULL) through the closed Bionic port. */
int dx_thread_suspend_storage_init(void);

/* dvmChangeStatus. A NULL self uses the current HOST-DEX execution context. */
int32_t dx_thread_change_status(DxExecutionContext *self, int32_t new_status);
int32_t dx_thread_status(const DxExecutionContext *self);

/* Suspend-count stores used by the self-suspend path. The lock is the closed
 * Bionic mutex, not a host pthread mutex. */
void dx_thread_add_suspend_counts(DxExecutionContext *self, int32_t suspend_delta,
                                  int32_t dbg_delta);
/* dvmResumeThread's effect on this condition: decrement under the lock and
 * pthread_cond_broadcast when the count reaches zero. */
void dx_thread_resume_suspend(DxExecutionContext *target);

uint32_t dx_thread_bionic_wait_entries(void);
uint32_t dx_thread_bionic_broadcast_entries(void);
uint32_t dx_thread_suspend_cond_word(void);

#endif
