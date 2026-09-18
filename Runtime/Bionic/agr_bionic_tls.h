#ifndef AGR_BIONIC_TLS_H
#define AGR_BIONIC_TLS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AGR_BIONIC_TLS_FIRST_USER_SLOT 7u
#define AGR_BIONIC_TLS_SLOTS 140u
#define AGR_BIONIC_TLS_ERRNO_SLOT 2u

typedef struct agr_bionic_tls agr_bionic_tls;
typedef int32_t (*agr_bionic_tls_read)(void *, uint32_t, uint32_t *);
typedef int32_t (*agr_bionic_tls_write)(void *, uint32_t, uint32_t);
typedef int32_t (*agr_bionic_tls_invoke)(void *, uint32_t thread_id,
                                         uint32_t destructor, uint32_t value);

agr_bionic_tls *agr_bionic_tls_create(void *opaque, agr_bionic_tls_read read,
                                      agr_bionic_tls_write write,
                                      agr_bionic_tls_invoke invoke);
void agr_bionic_tls_destroy(agr_bionic_tls *);
int32_t agr_bionic_tls_register_thread(agr_bionic_tls *, uint32_t thread_id,
                                       uint32_t tls_base,
                                       uint32_t guest_thread_descriptor);
int32_t agr_bionic_tls_cleanup_thread(agr_bionic_tls *, uint32_t thread_id);
int32_t agr_bionic_tls_unregister_thread(agr_bionic_tls *, uint32_t thread_id);
int32_t agr_bionic_tls_key_create(agr_bionic_tls *, uint32_t destructor,
                                  uint32_t *key);
int32_t agr_bionic_tls_key_delete(agr_bionic_tls *, uint32_t key);
int32_t agr_bionic_tls_setspecific(agr_bionic_tls *, uint32_t thread_id,
                                   uint32_t key, uint32_t value);
int32_t agr_bionic_tls_getspecific(agr_bionic_tls *, uint32_t thread_id,
                                   uint32_t key, uint32_t *value);
uint32_t agr_bionic_tls_errno_address(agr_bionic_tls *, uint32_t thread_id);

#ifdef __cplusplus
}
#endif
#endif
