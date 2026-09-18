#ifndef AGR_BIONIC_SYNC_H
#define AGR_BIONIC_SYNC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ARM32 addresses and values only. Atomics must serialize with interpreter
 * writes to the same guest address space and provide acquire/release order. */
typedef struct agr_bionic_sync {
  void *opaque;
  int32_t (*load)(void *, uint32_t, uint32_t *);
  int32_t (*store)(void *, uint32_t, uint32_t);
  int32_t (*cas)(void *, uint32_t, uint32_t, uint32_t, uint32_t *);
  int32_t (*exchange)(void *, uint32_t, uint32_t, uint32_t *);
  int32_t (*fetch_sub)(void *, uint32_t, uint32_t, uint32_t *);
  int32_t (*wait)(void *, uint32_t, uint32_t, uint64_t);
  int32_t (*wake)(void *, uint32_t, uint32_t);
  uint32_t (*current_tid)(void *);
  int32_t (*invoke_once)(void *, uint32_t);
} agr_bionic_sync;

int32_t agr_bionic_mutex_init(agr_bionic_sync *, uint32_t mutex, int32_t type);
int32_t agr_bionic_mutexattr_init(agr_bionic_sync *, uint32_t attr);
int32_t agr_bionic_mutexattr_destroy(agr_bionic_sync *, uint32_t attr);
int32_t agr_bionic_mutexattr_settype(agr_bionic_sync *, uint32_t attr, int32_t type);
int32_t agr_bionic_mutexattr_setpshared(agr_bionic_sync *, uint32_t attr, int32_t shared);
int32_t agr_bionic_mutex_destroy(agr_bionic_sync *, uint32_t mutex);
int32_t agr_bionic_mutex_lock(agr_bionic_sync *, uint32_t mutex);
int32_t agr_bionic_mutex_trylock(agr_bionic_sync *, uint32_t mutex);
int32_t agr_bionic_mutex_unlock(agr_bionic_sync *, uint32_t mutex);
int32_t agr_bionic_cond_init(agr_bionic_sync *, uint32_t cond, int32_t shared);
int32_t agr_bionic_condattr_init(agr_bionic_sync *, uint32_t attr);
int32_t agr_bionic_condattr_destroy(agr_bionic_sync *, uint32_t attr);
int32_t agr_bionic_condattr_setpshared(agr_bionic_sync *, uint32_t attr, int32_t shared);
int32_t agr_bionic_cond_destroy(agr_bionic_sync *, uint32_t cond);
int32_t agr_bionic_cond_signal(agr_bionic_sync *, uint32_t cond);
int32_t agr_bionic_cond_broadcast(agr_bionic_sync *, uint32_t cond);
int32_t agr_bionic_cond_wait_relative(agr_bionic_sync *, uint32_t cond,
                                       uint32_t mutex, uint64_t timeout_ns);
int32_t agr_bionic_once(agr_bionic_sync *, uint32_t control,
                          uint32_t init_function);

#ifdef __cplusplus
}
#endif
#endif
