#ifndef AGR_BIONIC_THREAD_ATTR_H
#define AGR_BIONIC_THREAD_ATTR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ARM32/API19 pthread_attr_t, from pinned libc/include/pthread.h. No Darwin
 * pointer or size_t may enter this guest-visible 24-byte layout. */
typedef struct agr_bionic_thread_attr {
  uint32_t flags;
  uint32_t stack_base;
  uint32_t stack_size;
  uint32_t guard_size;
  int32_t sched_policy;
  int32_t sched_priority;
} agr_bionic_thread_attr;

typedef struct agr_bionic_thread_stack_layout {
  uint32_t base;
  uint32_t size;
  uint32_t guard_size;
  uint32_t tls_base;
  uint32_t initial_sp;
  uint32_t user_stack;
} agr_bionic_thread_stack_layout;

int32_t agr_bionic_thread_attr_init(agr_bionic_thread_attr *);
int32_t agr_bionic_thread_attr_destroy(agr_bionic_thread_attr *);
int32_t agr_bionic_thread_attr_setdetachstate(agr_bionic_thread_attr *, int32_t);
int32_t agr_bionic_thread_attr_setstacksize(agr_bionic_thread_attr *, uint32_t);
int32_t agr_bionic_thread_attr_setstack(agr_bionic_thread_attr *, uint32_t,
                                        uint32_t);
int32_t agr_bionic_thread_attr_setguardsize(agr_bionic_thread_attr *, uint32_t);
int32_t agr_bionic_thread_compute_stack_layout(const agr_bionic_thread_attr *,
                                               uint32_t allocated_base,
                                               agr_bionic_thread_stack_layout *);

#ifdef __cplusplus
}
#endif
#endif
