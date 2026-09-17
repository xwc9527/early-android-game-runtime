#include "../../Runtime/AospLinker/agr_aosp_linker.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct harness { uint8_t *memory; uint32_t size; } harness;
static int32_t write_guest(void *opaque, uint32_t address, const void *data, uint32_t length) {
    harness *host = (harness *)opaque;
    if (address > host->size || length > host->size-address) return EFAULT;
    memcpy(host->memory+address, data, length);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) return 2;
    FILE *file = fopen(argv[1], "rb");
    if (!file || fseek(file, 0, SEEK_END)) return 3;
    long length = ftell(file);
    if (length <= 0 || length > UINT32_MAX || fseek(file, 0, SEEK_SET)) return 3;
    uint8_t *elf = (uint8_t *)malloc((size_t)length);
    if (!elf || fread(elf, 1, (size_t)length, file) != (size_t)length) return 3;
    fclose(file);

    harness host = {(uint8_t *)calloc(1, 0x10000000), 0x10000000};
    if (!host.memory) return 3;
    agr_guest_vma_space vma;
    if (agr_guest_vma_init(&vma, 4096, 0x10000, 0x100000000ull)) return 3;
    agr_bionic_mmap_context context = {&vma, &host, write_guest, NULL, NULL};
    agr_aosp_linker_image image = {0};
    int32_t guest_errno = 0;
    if (agr_aosp_linker_map(&context, elf, (uint32_t)length, 0x100000, &image, &guest_errno) ||
        agr_aosp_linker_finalize(&context, elf, (uint32_t)length, &image, &guest_errno)) {
        fprintf(stderr, "AGR ELF map/finalize failed: %d\n", guest_errno);
        return 4;
    }

    Elf32_Ehdr *header = (Elf32_Ehdr *)elf;
    Elf32_Phdr *segments = (Elf32_Phdr *)(elf+header->e_phoff);
    int bss_zero = 1;
    uint32_t load_count = 0;
    for (uint32_t i = 0; i < header->e_phnum; i++) {
        Elf32_Phdr *segment = &segments[i];
        if (segment->p_type == PT_LOAD) load_count++;
        if (segment->p_type != PT_LOAD || segment->p_memsz <= segment->p_filesz) continue;
        for (uint32_t j = segment->p_filesz; j < segment->p_memsz; j++) {
            if (host.memory[image.load_bias+segment->p_vaddr+j]) bss_zero = 0;
        }
    }
    int relro_ro = image.relro_size != 0 &&
        agr_guest_vma_find(&vma, image.relro_start) != NULL &&
        agr_guest_vma_find(&vma, image.relro_start)->protection == AGR_PROT_READ;
    uint32_t start = image.load_start, span = image.load_size;
    int *pages = (int *)malloc(sizeof(int)*(span/4096));
    if (!pages) return 5;
    for (uint32_t i = 0; i < span/4096; i++) {
        const agr_guest_vma_region *region = agr_guest_vma_find(&vma, start+i*4096);
        pages[i] = region ? (int)region->protection : -1;
    }
    int unloaded = agr_aosp_linker_unload(&context, &image, &guest_errno) == 0 && vma.count == 0;
    int unload_unmapped = unloaded && agr_guest_vma_find(&vma, start) == NULL;
    int reload_ok = unloaded && agr_aosp_linker_map(&context, elf, (uint32_t)length,
        0x100000, &image, &guest_errno) == 0;
    int reload_reused = reload_ok && image.load_start == start;
    uint32_t load_bias_page = reload_ok ? image.load_bias & 4095u : 0;
    if (reload_ok) agr_aosp_linker_unload(&context, &image, &guest_errno);

    uint32_t mapped = 0, replacement = 0;
    int offset_einval = agr_bionic_mmap(&context, 0, 4096, AGR_PROT_READ,
        AGR_MAP_PRIVATE, -1, 1, &mapped, &guest_errno) == -1 && guest_errno == EINVAL;
    int invalid_fd_ebadf = agr_bionic_mmap2(&context, 0, 4096, AGR_PROT_READ,
        AGR_MAP_PRIVATE, -1, 0, &mapped, &guest_errno) == -1 && guest_errno == EBADF;
    int first_ok = agr_bionic_mmap2(&context, 0, 4096,
        AGR_PROT_READ | AGR_PROT_WRITE, AGR_MAP_PRIVATE | AGR_MAP_ANONYMOUS,
        -1, 0, &mapped, &guest_errno) == 0;
    int fixed_replace = 0, failed_fixed_preserves = 0, protect_ok = 0, unmap_ok = 0, errno_preserved_success = 0;
    if (first_ok) {
        memset(host.memory+mapped, 0x5a, 4096);
        fixed_replace = agr_bionic_mmap2(&context, mapped, 4096,
            AGR_PROT_READ | AGR_PROT_WRITE,
            AGR_MAP_FIXED | AGR_MAP_PRIVATE | AGR_MAP_ANONYMOUS,
            -1, 0, &replacement, &guest_errno) == 0 &&
            replacement == mapped && host.memory[mapped] == 0;
        host.memory[mapped] = 0x5a;
        guest_errno = 0;
        failed_fixed_preserves = agr_bionic_mmap2(&context, mapped, 4096,
            AGR_PROT_READ, AGR_MAP_FIXED | AGR_MAP_PRIVATE, -1, 0,
            &replacement, &guest_errno) == -1 && guest_errno == EBADF &&
            host.memory[mapped] == 0x5a &&
            agr_guest_vma_find(&vma, mapped)->protection ==
                (AGR_PROT_READ | AGR_PROT_WRITE);
        guest_errno = 123;
        protect_ok = agr_bionic_mprotect(&context, mapped, 4096,
            AGR_PROT_READ, &guest_errno) == 0 &&
            agr_guest_vma_find(&vma, mapped)->protection == AGR_PROT_READ;
        errno_preserved_success = protect_ok && guest_errno == 123;
        unmap_ok = agr_bionic_munmap(&context, mapped, 4096, &guest_errno) == 0 &&
            agr_guest_vma_find(&vma, mapped) == NULL;
    }

    printf("{\"page_size\":4096,\"load_span\":%u,\"load_bias_page\":%u,\"pt_load_count\":%u,"
           "\"bss_zero\":%s,\"relro_ro\":%s,\"offset_einval\":%s,\"invalid_fd_ebadf\":%s,"
           "\"map_fixed_replace\":%s,\"failed_fixed_preserves\":%s,\"mprotect_ok\":%s,\"errno_preserved_success\":%s,\"munmap_ok\":%s,"
           "\"unload_unmapped\":%s,\"reload_ok\":%s,\"reload_reused\":%s,\"page_protection\":[",
           span, load_bias_page, load_count,
           bss_zero ? "true" : "false", relro_ro ? "true" : "false",
           offset_einval ? "true" : "false", invalid_fd_ebadf ? "true" : "false", fixed_replace ? "true" : "false", failed_fixed_preserves ? "true" : "false",
           protect_ok ? "true" : "false", errno_preserved_success ? "true" : "false", unmap_ok ? "true" : "false", unload_unmapped ? "true" : "false",
           reload_ok ? "true" : "false", reload_reused ? "true" : "false");
    for (uint32_t i=0;i<span/4096;i++) printf("%s%d", i ? "," : "", pages[i]);
    printf("],\"pt_load_layout\":[");int first=1;
    for (uint32_t i=0;i<header->e_phnum;i++){
        Elf32_Phdr *p=&segments[i];if(p->p_type!=PT_LOAD)continue;
        printf("%s[%u,%u,%u,%u,%u]",first?"":",",p->p_offset,p->p_vaddr,p->p_filesz,p->p_memsz,p->p_flags);
        first=0;
    }
    puts("]}");free(pages);
    agr_guest_vma_destroy(&vma);
    free(host.memory);
    free(elf);
    return 0;
}
