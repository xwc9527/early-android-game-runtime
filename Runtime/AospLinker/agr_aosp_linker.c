/*
 * Segment policy is a C adaptation of Android 4.4.4 bionic linker_phdr.cpp:
 * phdr_table_get_load_size, ReserveAddressSpace, LoadSegments,
 * phdr_table_protect_segments, and phdr_table_protect_gnu_relro.
 */
#include "agr_aosp_linker.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

#define PAGE_START(x) ((uint32_t)(x) & ~4095u)
#define PAGE_END(x) (((uint32_t)(x) + 4095u) & ~4095u)
#define PAGE_OFFSET(x) ((uint32_t)(x) & 4095u)
#define PT_GNU_RELRO 0x6474e552u
#define PF_X 1u
#define PF_W 2u
#define PF_R 4u

typedef struct source_view {
    const uint8_t *bytes;
    uint32_t size;
    agr_bionic_mmap_context *host;
} source_view;

static int32_t source_file(void *opaque, int32_t fd, const uint8_t **bytes,
                           uint32_t *size) {
    source_view *source = (source_view *)opaque;
    if (!source || fd != 1 || !bytes || !size) return EBADF;
    *bytes = source->bytes;
    *size = source->size;
    return 0;
}

static int32_t source_write(void *opaque, uint32_t address, const void *bytes,
                            uint32_t size) {
    source_view *source = (source_view *)opaque;
    return source->host->write_guest(source->host->opaque, address, bytes, size);
}

static uint32_t pflags_to_prot(uint32_t flags) {
    uint32_t result = AGR_PROT_NONE;
    if (flags & PF_R) result |= AGR_PROT_READ;
    if (flags & PF_W) result |= AGR_PROT_WRITE;
    if (flags & PF_X) result |= AGR_PROT_EXEC;
    return result;
}

static int headers(const void *bytes, uint32_t size, const Elf32_Ehdr **ehdr,
                   const Elf32_Phdr **phdr, int32_t *guest_errno) {
    if (!bytes || size < sizeof(Elf32_Ehdr)) goto invalid;
    const Elf32_Ehdr *eh = (const Elf32_Ehdr *)bytes;
    if (memcmp(eh->e_ident, ELFMAG, SELFMAG) || eh->e_ident[EI_CLASS] != ELFCLASS32 ||
        eh->e_machine != EM_ARM || eh->e_phentsize != sizeof(Elf32_Phdr) ||
        !eh->e_phnum || eh->e_phnum > 65536u / sizeof(Elf32_Phdr) ||
        eh->e_phoff > size ||
        (uint64_t)eh->e_phnum * sizeof(Elf32_Phdr) > size - eh->e_phoff) goto invalid;
    *ehdr = eh;
    *phdr = (const Elf32_Phdr *)((const uint8_t *)bytes + eh->e_phoff);
    return 0;
invalid:
    if (guest_errno) *guest_errno = ENOEXEC;
    return -1;
}

static int zero_range(agr_bionic_mmap_context *context, uint32_t address,
                      uint32_t size) {
    static const uint8_t zero[4096] = {0};
    while (size) {
        uint32_t amount = size > sizeof(zero) ? (uint32_t)sizeof(zero) : size;
        if (context->write_guest(context->opaque, address, zero, amount)) return -1;
        address += amount;
        size -= amount;
    }
    return 0;
}

int32_t agr_aosp_linker_map(agr_bionic_mmap_context *context,
                            const void *elf_bytes, uint32_t elf_size,
                            uint32_t preferred_bias,
                            agr_aosp_linker_image *image,
                            int32_t *guest_errno) {
    const Elf32_Ehdr *eh = NULL;
    const Elf32_Phdr *ph = NULL;
    if (!context || !image || headers(elf_bytes, elf_size, &eh, &ph, guest_errno)) return -1;
    uint32_t min = UINT32_MAX, max = 0;
    for (uint32_t i = 0; i < eh->e_phnum; ++i) if (ph[i].p_type == PT_LOAD) {
        uint64_t vend = (uint64_t)ph[i].p_vaddr + ph[i].p_memsz;
        uint64_t fend = (uint64_t)ph[i].p_offset + ph[i].p_filesz;
        if (ph[i].p_filesz > ph[i].p_memsz || vend > UINT32_MAX || fend > elf_size ||
            PAGE_OFFSET(ph[i].p_vaddr) != PAGE_OFFSET(ph[i].p_offset)) {
            if (guest_errno) *guest_errno = ENOEXEC;
            return -1;
        }
        if (ph[i].p_vaddr < min) min = ph[i].p_vaddr;
        if ((uint32_t)vend > max) max = (uint32_t)vend;
    }
    if (min == UINT32_MAX || PAGE_END(max) <= PAGE_START(min)) {
        if (guest_errno) *guest_errno = ENOEXEC;
        return -1;
    }
    min = PAGE_START(min);
    max = PAGE_END(max);
    uint32_t load_size = max - min;
    uint32_t hint = preferred_bias <= UINT32_MAX - min ? preferred_bias + min : 0;

    source_view source = {(const uint8_t *)elf_bytes, elf_size, context};
    agr_bionic_mmap_context local = *context;
    void *saved_opaque = local.opaque;
    agr_bionic_file_view_fn saved_file_view = local.file_view;
    local.file_view = source_file;
    local.opaque = &source;
    local.write_guest = source_write;
    uint32_t load_start = 0;
    if (agr_bionic_mmap2(&local, hint, load_size, AGR_PROT_NONE,
                         AGR_MAP_PRIVATE | AGR_MAP_ANONYMOUS, -1, 0,
                         &load_start, guest_errno)) return -1;
    uint32_t bias = load_start - min;

    /* file_view needs source; writes still belong to the original host context. */
    for (uint32_t i = 0; i < eh->e_phnum; ++i) if (ph[i].p_type == PT_LOAD) {
        uint32_t seg_start = bias + ph[i].p_vaddr;
        uint32_t seg_end = seg_start + ph[i].p_memsz;
        uint32_t seg_page_start = PAGE_START(seg_start);
        uint32_t seg_page_end = PAGE_END(seg_end);
        uint32_t seg_file_end = seg_start + ph[i].p_filesz;
        uint32_t file_page_start = PAGE_START(ph[i].p_offset);
        uint32_t file_length = ph[i].p_offset + ph[i].p_filesz - file_page_start;
        uint32_t mapped = 0;
        uint32_t protection = pflags_to_prot(ph[i].p_flags) | AGR_PROT_WRITE;
        if (file_length && agr_bionic_mmap2(&local, seg_page_start, file_length,
                                            protection,
                                            AGR_MAP_FIXED | AGR_MAP_PRIVATE, 1,
                                            file_page_start >> 12, &mapped,
                                            guest_errno)) goto fail;
        if ((ph[i].p_flags & PF_W) && PAGE_OFFSET(seg_file_end)) {
            uint32_t count = 4096u - PAGE_OFFSET(seg_file_end);
            if (zero_range(context, seg_file_end, count)) { if (guest_errno) *guest_errno = EFAULT; goto fail; }
        }
        seg_file_end = PAGE_END(seg_file_end);
        if (seg_page_end > seg_file_end &&
            agr_bionic_mmap2(context, seg_file_end, seg_page_end - seg_file_end,
                             protection, AGR_MAP_FIXED | AGR_MAP_PRIVATE |
                             AGR_MAP_ANONYMOUS, -1, 0, &mapped, guest_errno)) goto fail;
    }
    local.opaque = saved_opaque;
    local.file_view = saved_file_view;
    *image = (agr_aosp_linker_image){load_start, load_size, bias, min, max, 0, 0};
    return 0;
fail:
    agr_bionic_munmap(context, load_start, load_size, NULL);
    return -1;
}

int32_t agr_aosp_linker_finalize(agr_bionic_mmap_context *context,
                                 const void *elf_bytes, uint32_t elf_size,
                                 agr_aosp_linker_image *image,
                                 int32_t *guest_errno) {
    const Elf32_Ehdr *eh = NULL;
    const Elf32_Phdr *ph = NULL;
    if (!context || !image || headers(elf_bytes, elf_size, &eh, &ph, guest_errno)) return -1;
    for (uint32_t i = 0; i < eh->e_phnum; ++i) if (ph[i].p_type == PT_LOAD) {
        uint32_t start = PAGE_START(ph[i].p_vaddr) + image->load_bias;
        uint32_t end = PAGE_END(ph[i].p_vaddr + ph[i].p_memsz) + image->load_bias;
        if (agr_bionic_mprotect(context, start, end - start,
                                pflags_to_prot(ph[i].p_flags), guest_errno)) return -1;
    }
    for (uint32_t i = 0; i < eh->e_phnum; ++i) if (ph[i].p_type == PT_GNU_RELRO) {
        uint32_t start = PAGE_START(ph[i].p_vaddr) + image->load_bias;
        uint32_t end = PAGE_END(ph[i].p_vaddr + ph[i].p_memsz) + image->load_bias;
        if (agr_bionic_mprotect(context, start, end - start, AGR_PROT_READ,
                                guest_errno)) return -1;
        image->relro_start = start;
        image->relro_size = end - start;
    }
    return 0;
}

int32_t agr_aosp_linker_unload(agr_bionic_mmap_context *context,
                               agr_aosp_linker_image *image,
                               int32_t *guest_errno) {
    if (!context || !image || !image->load_size) {
        if (guest_errno) *guest_errno = EINVAL;
        return -1;
    }
    if (agr_bionic_munmap(context, image->load_start, image->load_size, guest_errno)) return -1;
    memset(image, 0, sizeof(*image));
    return 0;
}
