#ifndef AGR_BIONIC_THREAD_LIFECYCLE_H
#define AGR_BIONIC_THREAD_LIFECYCLE_H

#include <stdint.h>

#include "../HostServices/agr_host_services.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Host-native adaptation of android-4.4.4_r2 pthread_create.cpp,
 * pthread_join.cpp, pthread_detach.cpp and pthread_internal.h. The AOSP
 * lifecycle rules stay here; HostServices supplies only raw Darwin threads.
 * guest_binding is an opaque per-thread owner used by GuestRuntime to bind an
 * independent ARM CPU/TLS/stack state before guest code executes. */
typedef struct agr_bionic_thread_lifecycle agr_bionic_thread_lifecycle;
typedef int32_t (*agr_bionic_thread_execute)(void *opaque,
                                             uint32_t guest_thread,
                                             uint32_t start_routine,
                                             uint32_t argument,
                                             uint32_t *return_value);

enum {
  AGR_BIONIC_THREAD_JOINABLE = 0,
  AGR_BIONIC_THREAD_DETACHED = 1,
};

agr_bionic_thread_lifecycle *agr_bionic_thread_lifecycle_create(
    const agr_host_services *, void *opaque, agr_bionic_thread_execute);
void agr_bionic_thread_lifecycle_destroy(agr_bionic_thread_lifecycle *);

int32_t agr_bionic_thread_lifecycle_create_thread(
    agr_bionic_thread_lifecycle *, uint32_t guest_thread,
    uint32_t start_routine, uint32_t argument, uint32_t detached,
    uint32_t *pthread_handle);
int32_t agr_bionic_thread_lifecycle_join(agr_bionic_thread_lifecycle *,
                                         uint32_t pthread_handle,
                                         uint32_t *return_value);
int32_t agr_bionic_thread_lifecycle_detach(agr_bionic_thread_lifecycle *,
                                           uint32_t pthread_handle);
/* GuestRuntime calls this after creating the complete GuestThreadContext on a
 * Darwin worker. Host TLS then contains that context, never this source-port's
 * private record. */
int32_t agr_bionic_thread_lifecycle_bind_current(
    agr_bionic_thread_lifecycle *, uint32_t guest_thread, void *guest_context);
int32_t agr_bionic_thread_lifecycle_register_current(
    agr_bionic_thread_lifecycle *, uint32_t guest_thread,
    uint32_t pthread_handle, void *guest_context);
uint32_t agr_bionic_thread_lifecycle_self(agr_bionic_thread_lifecycle *);
int32_t agr_bionic_thread_lifecycle_equal(uint32_t one, uint32_t two);
uint32_t agr_bionic_thread_lifecycle_live_count(agr_bionic_thread_lifecycle *);

#ifdef __cplusplus
}
#endif
#endif
