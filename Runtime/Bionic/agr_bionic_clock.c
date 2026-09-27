#include "agr_bionic_clock.h"

#include "agr_bionic_errno.h"
#include "agr_bionic_errno_host.h"

int32_t agr_bionic_clock_gettime(const agr_host_services *services,
                                 int32_t android_clock_id,
                                 uint32_t guest_timespec,
                                 uint32_t *tv_sec,
                                 uint32_t *tv_nsec,
                                 int32_t *android_errno) {
    agr_host_clock host_clock;
    uint64_t nanoseconds = 0;
    uint64_t seconds;
    int32_t host_error;
    if (android_clock_id != 0 && android_clock_id != 1) return 1;
    if (!android_errno) return -1;
    if (!guest_timespec || !tv_sec || !tv_nsec) {
        *android_errno = AGR_ANDROID_EFAULT;
        return -1;
    }
    if (!services || !services->clock_ns) {
        *android_errno = AGR_ANDROID_ENOSYS;
        return -1;
    }
    host_clock = android_clock_id == 0 ? AGR_HOST_CLOCK_REALTIME : AGR_HOST_CLOCK_MONOTONIC;
    host_error = services->clock_ns(services->context, host_clock, &nanoseconds);
    if (host_error != 0) {
        *android_errno = agr_bionic_errno_from_host(host_error);
        return -1;
    }
    seconds = nanoseconds / 1000000000ull;
    if (seconds > 0xffffffffull) {
        *android_errno = AGR_ANDROID_EIO;
        return -1;
    }
    *tv_sec = (uint32_t)seconds;
    *tv_nsec = (uint32_t)(nanoseconds % 1000000000ull);
    return 0;
}
