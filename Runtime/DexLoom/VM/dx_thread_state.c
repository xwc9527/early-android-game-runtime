/* Dalvik.ThreadState production port for the RegisterNatives self-suspend path.
 * gDvm.threadSuspendCountLock and threadSuspendCountCond are D010 HOST-DEX
 * private words. Their pthread behavior is agr_bionic_mutex_lock / unlock,
 * agr_bionic_cond_wait_relative, and agr_bionic_cond_broadcast. Slot numbers
 * are callback identities for those two words. They are not guest VMA
 * addresses and not Darwin pointers. */
#include "../Include/dx_thread_state.h"
#include "../../Bionic/agr_bionic_sync.h"
#include "../../Bionic/agr_futex_host.h"

#include <stdatomic.h>
#include <stdint.h>
#include <string.h>

enum { kLockSlot = 4u, kCondSlot = 8u };

static _Atomic uint32_t g_words[2];
static agr_futex_host *g_futex;
static agr_bionic_sync g_sync;
static int g_storage_ready;
static _Atomic uint32_t g_wait_entries;
static _Atomic uint32_t g_broadcast_entries;

typedef struct DxDalvikThread {
    _Atomic(DxExecutionContext *) owner;
    _Atomic int32_t status;
    _Atomic int32_t suspend_count;
    int32_t dbg_suspend_count;
} DxDalvikThread;

static DxDalvikThread g_slots[DX_MAX_EXEC_CONTEXTS];

static _Atomic uint32_t *host_word(uint32_t address) {
    if (address == kLockSlot) return &g_words[0];
    if (address == kCondSlot) return &g_words[1];
    return NULL;
}

static int32_t host_load(void *opaque, uint32_t address, uint32_t *value) {
    _Atomic uint32_t *word = host_word(address);
    (void)opaque;
    if (!word || !value) return -1;
    *value = atomic_load_explicit(word, memory_order_seq_cst);
    return 0;
}
static int32_t host_store(void *opaque, uint32_t address, uint32_t value) {
    _Atomic uint32_t *word = host_word(address);
    (void)opaque;
    if (!word) return -1;
    atomic_store_explicit(word, value, memory_order_seq_cst);
    return 0;
}
static int32_t host_cas(void *opaque, uint32_t address, uint32_t expected,
                        uint32_t next, uint32_t *observed) {
    _Atomic uint32_t *word = host_word(address);
    (void)opaque;
    if (!word || !observed) return -1;
    *observed = expected;
    atomic_compare_exchange_strong_explicit(
        word, observed, next, memory_order_seq_cst, memory_order_seq_cst);
    return 0;
}
static int32_t host_exchange(void *opaque, uint32_t address, uint32_t next,
                             uint32_t *previous) {
    _Atomic uint32_t *word = host_word(address);
    (void)opaque;
    if (!word || !previous) return -1;
    *previous = atomic_exchange_explicit(word, next, memory_order_seq_cst);
    return 0;
}
static int32_t host_fetch_sub(void *opaque, uint32_t address, uint32_t amount,
                              uint32_t *previous) {
    _Atomic uint32_t *word = host_word(address);
    (void)opaque;
    if (!word || !previous) return -1;
    *previous = atomic_fetch_sub_explicit(word, amount, memory_order_seq_cst);
    return 0;
}
static int32_t host_wait(void *opaque, uint32_t address, uint32_t expected,
                         uint64_t timeout_ns) {
    (void)opaque;
    if (address == kCondSlot)
        atomic_fetch_add_explicit(&g_wait_entries, 1, memory_order_relaxed);
    return agr_futex_host_wait(g_futex, address, expected, timeout_ns);
}
static int32_t host_wake(void *opaque, uint32_t address, uint32_t count) {
    if (address == kCondSlot)
        atomic_fetch_add_explicit(&g_broadcast_entries, 1, memory_order_relaxed);
    (void)opaque;
    return agr_futex_host_wake(g_futex, address, count);
}
static uint32_t host_tid(void *opaque) {
    (void)opaque;
    return 1;
}

static DxDalvikThread *slot_for(DxExecutionContext *exec, int create) {
    uint32_t index;
    DxExecutionContext *expected;
    if (!exec) return NULL;
    for (index = 0; index < DX_MAX_EXEC_CONTEXTS; index++) {
        if (atomic_load_explicit(&g_slots[index].owner, memory_order_acquire) == exec)
            return &g_slots[index];
    }
    if (!create) return NULL;
    for (index = 0; index < DX_MAX_EXEC_CONTEXTS; index++) {
        expected = NULL;
        if (atomic_compare_exchange_strong_explicit(
                &g_slots[index].owner, &expected, exec,
                memory_order_acq_rel, memory_order_acquire)) {
            atomic_store_explicit(&g_slots[index].status, DX_DALVIK_THREAD_UNDEFINED,
                                  memory_order_relaxed);
            atomic_store_explicit(&g_slots[index].suspend_count, 0, memory_order_relaxed);
            g_slots[index].dbg_suspend_count = 0;
            return &g_slots[index];
        }
        if (expected == exec) return &g_slots[index];
    }
    return NULL;
}

int dx_thread_suspend_storage_init(void) {
    if (g_storage_ready) return 0;
    memset(g_slots, 0, sizeof(g_slots));
    atomic_store_explicit(&g_words[0], 0, memory_order_relaxed);
    atomic_store_explicit(&g_words[1], 0, memory_order_relaxed);
    g_futex = agr_futex_host_create(NULL, host_load);
    if (!g_futex) return -1;
    g_sync = (agr_bionic_sync){NULL, host_load, host_store, host_cas, host_exchange,
                               host_fetch_sub, host_wait, host_wake, host_tid, NULL};
    if (agr_bionic_mutex_init(&g_sync, kLockSlot, 0) != 0) return -1;
    if (agr_bionic_cond_init(&g_sync, kCondSlot, 0) != 0) return -1;
    g_storage_ready = 1;
    return 0;
}

static void full_suspend_check(DxDalvikThread *thread) {
    int32_t old_status;
    int need_suspend;
    if (!g_storage_ready || !thread) return;
    if (agr_bionic_mutex_lock(&g_sync, kLockSlot) != 0) return;
    need_suspend = atomic_load_explicit(&thread->suspend_count, memory_order_relaxed) != 0;
    if (need_suspend) {
        old_status = atomic_load_explicit(&thread->status, memory_order_relaxed);
        atomic_store_explicit(&thread->status, DX_DALVIK_THREAD_SUSPENDED, memory_order_relaxed);
        while (atomic_load_explicit(&thread->suspend_count, memory_order_relaxed) != 0) {
            agr_bionic_cond_wait_relative(&g_sync, kCondSlot, kLockSlot, UINT64_MAX);
        }
        atomic_store_explicit(&thread->status, old_status, memory_order_relaxed);
    }
    agr_bionic_mutex_unlock(&g_sync, kLockSlot);
}

int32_t dx_thread_change_status(DxExecutionContext *self, int32_t new_status) {
    DxDalvikThread *thread;
    int32_t old_status;
    if (!self) return DX_DALVIK_THREAD_UNDEFINED;
    if (!g_storage_ready && dx_thread_suspend_storage_init() != 0)
        return DX_DALVIK_THREAD_UNDEFINED;
    thread = slot_for(self, 1);
    if (!thread) return DX_DALVIK_THREAD_UNDEFINED;
    old_status = atomic_load_explicit(&thread->status, memory_order_acquire);
    if (old_status == new_status) return old_status;
    if (new_status == DX_DALVIK_THREAD_SUSPENDED) return old_status;
    if (new_status == DX_DALVIK_THREAD_RUNNING) {
        atomic_store_explicit(&thread->status, new_status, memory_order_seq_cst);
        if (atomic_load_explicit(&thread->suspend_count, memory_order_acquire) != 0)
            full_suspend_check(thread);
    } else {
        atomic_store_explicit(&thread->status, new_status, memory_order_release);
    }
    return old_status;
}

int32_t dx_thread_status(const DxExecutionContext *self) {
    DxDalvikThread *thread = slot_for((DxExecutionContext *)self, 0);
    if (!thread) return DX_DALVIK_THREAD_UNDEFINED;
    return atomic_load_explicit(&thread->status, memory_order_acquire);
}

void dx_thread_add_suspend_counts(DxExecutionContext *self, int32_t suspend_delta,
                                  int32_t dbg_delta) {
    DxDalvikThread *thread;
    if (!self || !g_storage_ready) return;
    thread = slot_for(self, 1);
    if (!thread || agr_bionic_mutex_lock(&g_sync, kLockSlot) != 0) return;
    atomic_fetch_add_explicit(&thread->suspend_count, suspend_delta, memory_order_relaxed);
    thread->dbg_suspend_count += dbg_delta;
    agr_bionic_mutex_unlock(&g_sync, kLockSlot);
}

void dx_thread_resume_suspend(DxExecutionContext *target) {
    DxDalvikThread *thread;
    int32_t count;
    if (!target || !g_storage_ready) return;
    thread = slot_for(target, 0);
    if (!thread || agr_bionic_mutex_lock(&g_sync, kLockSlot) != 0) return;
    count = atomic_load_explicit(&thread->suspend_count, memory_order_relaxed);
    if (count > 0) {
        atomic_store_explicit(&thread->suspend_count, count - 1, memory_order_relaxed);
        thread->dbg_suspend_count -= 1;
        count -= 1;
    }
    if (count == 0) agr_bionic_cond_broadcast(&g_sync, kCondSlot);
    agr_bionic_mutex_unlock(&g_sync, kLockSlot);
}

uint32_t dx_thread_bionic_wait_entries(void) {
    return atomic_load_explicit(&g_wait_entries, memory_order_acquire);
}
uint32_t dx_thread_bionic_broadcast_entries(void) {
    return atomic_load_explicit(&g_broadcast_entries, memory_order_acquire);
}
uint32_t dx_thread_suspend_cond_word(void) {
    return atomic_load_explicit(&g_words[1], memory_order_acquire);
}
