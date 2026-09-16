#include <stdint.h>

int32_t android_atomic_inc(volatile int32_t *p) { return __atomic_fetch_add(p, 1, __ATOMIC_RELEASE); }
int32_t android_atomic_dec(volatile int32_t *p) { return __atomic_fetch_sub(p, 1, __ATOMIC_RELEASE); }
int32_t android_atomic_add(int32_t v, volatile int32_t *p) { return __atomic_fetch_add(p, v, __ATOMIC_RELEASE); }
int32_t android_atomic_and(int32_t v, volatile int32_t *p) { return __atomic_fetch_and(p, v, __ATOMIC_RELEASE); }
int32_t android_atomic_or(int32_t v, volatile int32_t *p) { return __atomic_fetch_or(p, v, __ATOMIC_RELEASE); }
int32_t android_atomic_acquire_load(volatile const int32_t *p) { return __atomic_load_n(p, __ATOMIC_ACQUIRE); }
int32_t android_atomic_release_load(volatile const int32_t *p) { return __atomic_load_n(p, __ATOMIC_RELAXED); }
void android_atomic_acquire_store(int32_t v, volatile int32_t *p) { __atomic_store_n(p, v, __ATOMIC_RELAXED); }
void android_atomic_release_store(int32_t v, volatile int32_t *p) { __atomic_store_n(p, v, __ATOMIC_RELEASE); }
int android_atomic_acquire_cas(int32_t old, int32_t value, volatile int32_t *p) {
    return __atomic_compare_exchange_n(p, &old, value, 0, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED) ? 0 : 1;
}
int android_atomic_release_cas(int32_t old, int32_t value, volatile int32_t *p) {
    return __atomic_compare_exchange_n(p, &old, value, 0, __ATOMIC_RELEASE, __ATOMIC_RELAXED) ? 0 : 1;
}
