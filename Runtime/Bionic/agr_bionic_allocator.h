#ifndef AGR_BIONIC_ALLOCATOR_H
#define AGR_BIONIC_ALLOCATOR_H

#include <stdint.h>
#include "agr_bionic_mmap.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct agr_bionic_allocator agr_bionic_allocator;
typedef void (*agr_allocator_errno_fn)(void *opaque, int32_t value);

enum {
    AGR_ALLOCATOR_FATAL_NONE = 0,
    AGR_ALLOCATOR_FATAL_USAGE = 1,
    AGR_ALLOCATOR_FATAL_CORRUPTION = 2,
};

typedef struct agr_allocator_mallinfo {
    uint32_t arena, ordblks, smblks, hblks, hblkhd;
    uint32_t usmblks, fsmblks, uordblks, fordblks, keepcost;
} agr_allocator_mallinfo;

agr_bionic_allocator *agr_bionic_allocator_create(
    agr_bionic_mmap_context *mmap_context, uint8_t *guest_memory_base,
    uint32_t heap_base, uint32_t heap_limit, void *errno_opaque,
    agr_allocator_errno_fn set_errno);
void agr_bionic_allocator_destroy(agr_bionic_allocator *allocator);

uint32_t agr_bionic_allocator_malloc(agr_bionic_allocator *allocator, uint32_t size);
uint32_t agr_bionic_allocator_calloc(agr_bionic_allocator *allocator,
                                     uint32_t count, uint32_t size);
uint32_t agr_bionic_allocator_realloc(agr_bionic_allocator *allocator,
                                      uint32_t address, uint32_t size);
void agr_bionic_allocator_free(agr_bionic_allocator *allocator, uint32_t address);
uint32_t agr_bionic_allocator_memalign(agr_bionic_allocator *allocator,
                                       uint32_t alignment, uint32_t size);
uint32_t agr_bionic_allocator_valloc(agr_bionic_allocator *allocator,
                                     uint32_t size);
uint32_t agr_bionic_allocator_pvalloc(agr_bionic_allocator *allocator,
                                      uint32_t size);
int32_t agr_bionic_allocator_posix_memalign(agr_bionic_allocator *allocator,
                                            uint32_t *address,
                                            uint32_t alignment, uint32_t size);
uint32_t agr_bionic_allocator_usable_size(agr_bionic_allocator *allocator,
                                          uint32_t address);
int32_t agr_bionic_allocator_mallinfo(agr_bionic_allocator *allocator,
                                      agr_allocator_mallinfo *out);
int32_t agr_bionic_allocator_mallopt(agr_bionic_allocator *allocator,
                                     int32_t parameter, int32_t value);
uint32_t agr_bionic_allocator_fatal(const agr_bionic_allocator *allocator);
void agr_bionic_allocator_clear_fatal(agr_bionic_allocator *allocator);

#ifdef __cplusplus
}
#endif
#endif
