#ifndef AGR_BIONIC_MMAP_H
#define AGR_BIONIC_MMAP_H

#include <stdint.h>
#include "../Process/agr_guest_vma.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    AGR_PROT_NONE = 0, AGR_PROT_READ = 1, AGR_PROT_WRITE = 2, AGR_PROT_EXEC = 4,
    AGR_MAP_SHARED = 1, AGR_MAP_PRIVATE = 2, AGR_MAP_FIXED = 0x10,
    AGR_MAP_ANONYMOUS = 0x20, AGR_MAP_NORESERVE = 0x4000,
};

typedef int32_t (*agr_bionic_guest_write_fn)(void *opaque, uint32_t address,
                                              const void *data, uint32_t size);
typedef int32_t (*agr_bionic_file_view_fn)(void *opaque, int32_t guest_fd,
                                           const uint8_t **bytes, uint32_t *size);
typedef int32_t (*agr_bionic_guest_protect_fn)(void *opaque, uint32_t address,
                                               uint32_t size, uint32_t protection);

typedef struct agr_bionic_mmap_context {
    agr_guest_vma_space *vma;
    void *opaque;
    agr_bionic_guest_write_fn write_guest;
    agr_bionic_file_view_fn file_view;
    agr_bionic_guest_protect_fn protect_guest;
} agr_bionic_mmap_context;

/* API 19 ARM ABI: mmap byte offset, __mmap2 offset in 4096-byte units. */
int32_t agr_bionic_mmap(agr_bionic_mmap_context *context, uint32_t address,
                        uint32_t length, uint32_t protection, uint32_t flags,
                        int32_t guest_fd, uint64_t byte_offset,
                        uint32_t *mapped_address, int32_t *guest_errno);
int32_t agr_bionic_mmap2(agr_bionic_mmap_context *context, uint32_t address,
                         uint32_t length, uint32_t protection, uint32_t flags,
                         int32_t guest_fd, uint32_t page_offset,
                         uint32_t *mapped_address, int32_t *guest_errno);
int32_t agr_bionic_mprotect(agr_bionic_mmap_context *context, uint32_t address,
                            uint32_t length, uint32_t protection,
                            int32_t *guest_errno);
int32_t agr_bionic_munmap(agr_bionic_mmap_context *context, uint32_t address,
                          uint32_t length, int32_t *guest_errno);

#ifdef __cplusplus
}
#endif
#endif
