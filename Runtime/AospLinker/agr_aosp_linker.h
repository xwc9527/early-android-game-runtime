#ifndef AGR_AOSP_LINKER_H
#define AGR_AOSP_LINKER_H

#include <stdint.h>
#include "../Bionic/agr_bionic_mmap.h"
#include "../NativeCore/agr_elf32.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct agr_aosp_linker_image {
    uint32_t load_start;
    uint32_t load_size;
    uint32_t load_bias;
    uint32_t min_vaddr;
    uint32_t max_vaddr;
    uint32_t relro_start;
    uint32_t relro_size;
} agr_aosp_linker_image;

/* HOST-NATIVE AOSP placement, derived from KitKat linker/linker_phdr.cpp. */
int32_t agr_aosp_linker_map(agr_bionic_mmap_context *mmap_context,
                            const void *elf_bytes, uint32_t elf_size,
                            uint32_t preferred_load_bias,
                            agr_aosp_linker_image *image,
                            int32_t *guest_errno);
int32_t agr_aosp_linker_finalize(agr_bionic_mmap_context *mmap_context,
                                 const void *elf_bytes, uint32_t elf_size,
                                 agr_aosp_linker_image *image,
                                 int32_t *guest_errno);
int32_t agr_aosp_linker_unload(agr_bionic_mmap_context *mmap_context,
                               agr_aosp_linker_image *image,
                               int32_t *guest_errno);

#ifdef __cplusplus
}
#endif
#endif
