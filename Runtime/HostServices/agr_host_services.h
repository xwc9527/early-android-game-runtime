#ifndef AGR_HOST_SERVICES_H
#define AGR_HOST_SERVICES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Host-only primitives. Android-visible policy belongs above this interface. */
typedef enum agr_host_clock {
    AGR_HOST_CLOCK_MONOTONIC = 1,
    AGR_HOST_CLOCK_REALTIME = 2,
} agr_host_clock;

typedef enum agr_host_vm_protection {
    AGR_HOST_VM_NONE  = 0,
    AGR_HOST_VM_READ  = 1,
    AGR_HOST_VM_WRITE = 2,
    AGR_HOST_VM_EXEC  = 4,
} agr_host_vm_protection;

typedef struct agr_host_services {
    void *context;
    uint32_t page_size;
    int32_t (*clock_ns)(void *context, agr_host_clock clock, uint64_t *value);
    int32_t (*vm_reserve)(void *context, uint64_t size, void **base);
    int32_t (*vm_protect)(void *context, void *base, uint64_t size,
                          uint32_t protection);
    int32_t (*vm_release)(void *context, void *base, uint64_t size);
    int32_t (*file_open)(void *context, const char *path, int flags, int mode);
    int64_t (*file_read)(void *context, int fd, void *data, uint64_t size);
    int64_t (*file_write)(void *context, int fd, const void *data, uint64_t size);
    int64_t (*file_seek)(void *context, int fd, int64_t offset, int whence);
    int32_t (*file_dup)(void *context, int fd);
    int32_t (*file_close)(void *context, int fd);
    /* AOSP consumer: Bionic pthread_create/join/detach and per-thread TLS
     * anchor. These are raw Darwin operations; guest lifecycle policy stays
     * in the Bionic source port. */
    int32_t (*thread_create)(void *context, void *(*entry)(void *), void *arg,
                             void **handle);
    int32_t (*thread_join)(void *context, void *handle, void **return_value);
    int32_t (*thread_detach)(void *context, void *handle);
    void (*thread_bind_guest)(void *context, void *guest_thread);
    void *(*thread_guest_binding)(void *context);
} agr_host_services;

/* Installs Darwin primitives only. It does not implement Bionic semantics. */
int32_t agr_host_services_init_darwin(agr_host_services *services);
/* The single host TLS slot used by Apple production to map the current
 * Darwin pthread to its GuestThreadContext. */
void agr_host_services_bind_current_guest(void *guest_thread);
void *agr_host_services_current_guest(void);

#ifdef __cplusplus
}
#endif
#endif
