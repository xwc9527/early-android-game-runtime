#ifndef AGR_GUEST_VMA_H
#define AGR_GUEST_VMA_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    AGR_GUEST_VMA_FIXED = 1u << 0,
    AGR_GUEST_VMA_NOREPLACE = 1u << 1,
};

typedef struct agr_guest_vma_region {
    uint32_t start;
    uint64_t end;
    uint32_t protection;
} agr_guest_vma_region;

typedef struct agr_guest_vma_space {
    agr_guest_vma_region *regions;
    size_t count;
    size_t capacity;
    uint32_t page_size;
    uint32_t lower_bound;
    uint64_t upper_bound;
} agr_guest_vma_space;

int agr_guest_vma_init(agr_guest_vma_space *space, uint32_t page_size,
                       uint32_t lower_bound, uint64_t upper_bound);
void agr_guest_vma_destroy(agr_guest_vma_space *space);

/* Returns a positive errno value. Guest addresses remain 32-bit. */
int agr_guest_vma_map(agr_guest_vma_space *space, uint32_t address,
                      uint64_t length, uint32_t protection, uint32_t flags,
                      uint32_t *mapped_address);
int agr_guest_vma_unmap(agr_guest_vma_space *space, uint32_t address,
                        uint64_t length);
int agr_guest_vma_protect(agr_guest_vma_space *space, uint32_t address,
                          uint64_t length, uint32_t protection);

const agr_guest_vma_region *agr_guest_vma_find(const agr_guest_vma_space *space,
                                                uint32_t address);
int agr_guest_vma_validate(const agr_guest_vma_space *space);

#ifdef __cplusplus
}
#endif
#endif
