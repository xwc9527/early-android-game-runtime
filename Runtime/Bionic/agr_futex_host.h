#ifndef AGR_FUTEX_HOST_H
#define AGR_FUTEX_HOST_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct agr_futex_host agr_futex_host;

/* Raw process-shared ARM32 word read. The callback must serialize with all
 * guest writes; it does not return a Darwin pointer or Darwin errno. */
typedef int32_t (*agr_futex_read_word)(void *opaque, uint32_t address,
                                      uint32_t *value);

agr_futex_host *agr_futex_host_create(void *opaque, agr_futex_read_word read);
void agr_futex_host_destroy(agr_futex_host *host);

/* Linux futex syscall result convention used by KitKat Bionic:
 * nonnegative on success, negative Android errno on failure. A timeout is a
 * relative number of nanoseconds; UINT64_MAX means no timeout. */
int32_t agr_futex_host_wait(agr_futex_host *host, uint32_t address,
                            uint32_t expected, uint64_t relative_timeout_ns);
int32_t agr_futex_host_wake(agr_futex_host *host, uint32_t address,
                            uint32_t maximum);

#ifdef __cplusplus
}
#endif

#endif
