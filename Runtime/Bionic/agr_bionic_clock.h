#ifndef AGR_BIONIC_CLOCK_H
#define AGR_BIONIC_CLOCK_H

#include <stdint.h>

#include "../HostServices/agr_host_services.h"

#ifdef __cplusplus
extern "C" {
#endif

/* API19 clock_gettime for the authorized CLOCK_REALTIME (0) and
 * CLOCK_MONOTONIC (1) requests only. The Linux clock id stays here.
 * HostServices receives only AGR_HOST_CLOCK_REALTIME or
 * AGR_HOST_CLOCK_MONOTONIC. A return of 1 means the id is outside this
 * port: HostServices is not called and errno is unchanged. */
int32_t agr_bionic_clock_gettime(const agr_host_services *services,
                                 int32_t android_clock_id,
                                 uint32_t guest_timespec,
                                 uint32_t *tv_sec,
                                 uint32_t *tv_nsec,
                                 int32_t *android_errno);

#ifdef __cplusplus
}
#endif
#endif
