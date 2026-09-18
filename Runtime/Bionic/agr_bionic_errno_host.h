#ifndef AGR_BIONIC_ERRNO_HOST_H
#define AGR_BIONIC_ERRNO_HOST_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Translate a positive Darwin pthread/host error before returning it to an
 * ARM32 Bionic caller. Zero remains success. Unknown host codes must not leak
 * to guest; they map to Android EIO for explicit failure. */
int32_t agr_bionic_errno_from_host(int32_t host_error);

#ifdef __cplusplus
}
#endif
#endif
