/* API 19 behavior derived from bionic/libc/bionic/mmap.cpp and ARM mman.h. */
#include "agr_bionic_mmap.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

static int32_t fail(int error, int32_t *guest_errno) {
    if (guest_errno) *guest_errno = error;
    return -1;
}

static int valid_protection(uint32_t protection) {
    return !(protection & ~(AGR_PROT_READ | AGR_PROT_WRITE | AGR_PROT_EXEC));
}

static int write_zero(agr_bionic_mmap_context *context, uint32_t address,
                      uint32_t length) {
    static const uint8_t zero[4096] = {0};
    while (length) {
        uint32_t amount = length > sizeof(zero) ? (uint32_t)sizeof(zero) : length;
        if (context->write_guest(context->opaque, address, zero, amount)) return EFAULT;
        address += amount;
        length -= amount;
    }
    return 0;
}

int32_t agr_bionic_mmap(agr_bionic_mmap_context *context, uint32_t address,
                        uint32_t length, uint32_t protection, uint32_t flags,
                        int32_t guest_fd, uint64_t byte_offset,
                        uint32_t *mapped_address, int32_t *guest_errno) {
    if (!context || !context->vma || !context->write_guest || !mapped_address ||
        !length || !valid_protection(protection) || (byte_offset & 4095u)) {
        return fail(EINVAL, guest_errno);
    }
    uint32_t known = AGR_MAP_SHARED | AGR_MAP_PRIVATE | AGR_MAP_FIXED |
                     AGR_MAP_ANONYMOUS | AGR_MAP_NORESERVE;
    if ((flags & ~known) || ((flags & AGR_MAP_SHARED) != 0) ==
                            ((flags & AGR_MAP_PRIVATE) != 0) ||
        ((flags & AGR_MAP_FIXED) && (address & 4095u))) {
        return fail(EINVAL, guest_errno);
    }
    uint32_t vma_flags = (flags & AGR_MAP_FIXED) ? AGR_GUEST_VMA_FIXED : 0;
    int error = agr_guest_vma_map(context->vma, address, length, protection,
                                  vma_flags, mapped_address);
    if (error) return fail(error, guest_errno);

    if (flags & AGR_MAP_ANONYMOUS) {
        error = write_zero(context, *mapped_address, length);
    } else {
        const uint8_t *bytes = NULL;
        uint32_t size = 0;
        if (guest_fd < 0 || !context->file_view ||
            context->file_view(context->opaque, guest_fd, &bytes, &size) ||
            byte_offset > size || length > (uint64_t)size - byte_offset) {
            error = EBADF;
        } else if (context->write_guest(context->opaque, *mapped_address,
                                        bytes + (uint32_t)byte_offset, length)) {
            error = EFAULT;
        }
    }
    if (error) {
        agr_guest_vma_unmap(context->vma, *mapped_address, length);
        return fail(error, guest_errno);
    }
    if (guest_errno) *guest_errno = 0;
    return 0;
}

int32_t agr_bionic_mmap2(agr_bionic_mmap_context *context, uint32_t address,
                         uint32_t length, uint32_t protection, uint32_t flags,
                         int32_t guest_fd, uint32_t page_offset,
                         uint32_t *mapped_address, int32_t *guest_errno) {
    return agr_bionic_mmap(context, address, length, protection, flags, guest_fd,
                           (uint64_t)page_offset << 12, mapped_address, guest_errno);
}

int32_t agr_bionic_mprotect(agr_bionic_mmap_context *context, uint32_t address,
                            uint32_t length, uint32_t protection,
                            int32_t *guest_errno) {
    if (!context || !context->vma || !length || !valid_protection(protection) ||
        (address & 4095u)) return fail(EINVAL, guest_errno);
    int error = agr_guest_vma_protect(context->vma, address, length, protection);
    if (error) return fail(error, guest_errno);
    if (guest_errno) *guest_errno = 0;
    return 0;
}

int32_t agr_bionic_munmap(agr_bionic_mmap_context *context, uint32_t address,
                          uint32_t length, int32_t *guest_errno) {
    if (!context || !context->vma || !length || (address & 4095u))
        return fail(EINVAL, guest_errno);
    int error = agr_guest_vma_unmap(context->vma, address, length);
    if (error) return fail(error, guest_errno);
    if (guest_errno) *guest_errno = 0;
    return 0;
}
