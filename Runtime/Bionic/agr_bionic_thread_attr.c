/* Source port of Android 4.4.4_r2 bionic/libc/bionic/pthread_attr.cpp
 * and pthread_create.cpp's ARM32 stack/TLS placement. Kernel mmap/mprotect
 * remains the guest VMA adapter boundary; this file owns Bionic policy. */
#include "agr_bionic_thread_attr.h"
#include "agr_bionic_errno.h"

#include <string.h>

#define API19_PAGE_SIZE 4096u
#define API19_SIGSTKSZ 8192u
#define API19_STACK_MIN (2u * API19_PAGE_SIZE)
#define API19_DEFAULT_STACK_SIZE ((1024u * 1024u) - API19_SIGSTKSZ)
#define API19_TLS_BYTES (140u * 4u)
#define API19_DETACHED_FLAG 1u
#define API19_USER_STACK_FLAG 2u

_Static_assert(sizeof(agr_bionic_thread_attr) == 24,
               "API19 ARM32 pthread_attr_t must remain 24 bytes");

int32_t agr_bionic_thread_attr_init(agr_bionic_thread_attr *attr) {
  if (!attr) return AGR_ANDROID_EINVAL;
  *attr = (agr_bionic_thread_attr){0, 0, API19_DEFAULT_STACK_SIZE,
                                  API19_PAGE_SIZE, 0, 0};
  return 0;
}
int32_t agr_bionic_thread_attr_destroy(agr_bionic_thread_attr *attr) {
  if (!attr) return AGR_ANDROID_EINVAL;
  memset(attr, 0x42, sizeof(*attr));
  return 0;
}
int32_t agr_bionic_thread_attr_setdetachstate(agr_bionic_thread_attr *attr,
                                              int32_t state) {
  if (!attr || (state != 0 && state != 1)) return AGR_ANDROID_EINVAL;
  attr->flags = (attr->flags & ~API19_DETACHED_FLAG) | (uint32_t)state;
  return 0;
}
int32_t agr_bionic_thread_attr_setstacksize(agr_bionic_thread_attr *attr,
                                            uint32_t size) {
  if (!attr || size < API19_STACK_MIN) return AGR_ANDROID_EINVAL;
  attr->stack_size = size;
  return 0;
}
int32_t agr_bionic_thread_attr_setstack(agr_bionic_thread_attr *attr,
                                        uint32_t base, uint32_t size) {
  if (!attr || (base & (API19_PAGE_SIZE - 1u)) ||
      (size & (API19_PAGE_SIZE - 1u)) || size < API19_STACK_MIN)
    return AGR_ANDROID_EINVAL;
  attr->stack_base = base;
  attr->stack_size = size;
  return 0;
}
int32_t agr_bionic_thread_attr_setguardsize(agr_bionic_thread_attr *attr,
                                            uint32_t size) {
  if (!attr) return AGR_ANDROID_EINVAL;
  attr->guard_size = size;
  return 0;
}
int32_t agr_bionic_thread_compute_stack_layout(const agr_bionic_thread_attr *attr,
                                               uint32_t allocated_base,
                                               agr_bionic_thread_stack_layout *out) {
  if (!attr || !out || attr->stack_size > UINT32_MAX - 4095u ||
      attr->guard_size > UINT32_MAX - 4095u)
    return AGR_ANDROID_EINVAL;
  uint32_t size = (attr->stack_size + 4095u) & ~4095u;
  uint32_t guard = (attr->guard_size + 4095u) & ~4095u;
  uint32_t base = attr->stack_base ? attr->stack_base : allocated_base;
  if (!base || (base & 4095u) || size < API19_STACK_MIN ||
      base > UINT32_MAX - size || guard >= size - API19_TLS_BYTES)
    return AGR_ANDROID_EINVAL;
  uint32_t tls = base + size - API19_TLS_BYTES;
  *out = (agr_bionic_thread_stack_layout){base, size, guard, tls, tls,
      attr->stack_base != 0 ? 1u : 0u};
  return 0;
}
