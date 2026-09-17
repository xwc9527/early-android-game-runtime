/*
 * Copyright (C) 2013 The Android Open Source Project
 * Licensed under the Apache License, Version 2.0.
 *
 * Source port: android-4.4.4_r2 bionic/libc/bionic/mmap.cpp.
 * The public mmap wrapper below preserves the original 4 KiB offset check and
 * __mmap2 conversion. agr_bionic_mmap2 is the replaced Linux syscall boundary:
 * it delegates raw address-space operations to AGR's guest VMA substrate.
 */
#include "agr_bionic_mmap.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

static int32_t fail(int error, int32_t* guest_errno) {
  if (guest_errno != NULL) *guest_errno = error;
  return -1;
}

static int valid_protection(uint32_t protection) {
  return !(protection & ~(AGR_PROT_READ | AGR_PROT_WRITE | AGR_PROT_EXEC));
}

static int write_zero(agr_bionic_mmap_context* context, uint32_t address, uint32_t length) {
  static const uint8_t zero[4096] = {0};
  while (length != 0) {
    uint32_t amount = length > sizeof(zero) ? sizeof(zero) : length;
    if (context->write_guest(context->opaque, address, zero, amount) != 0) return EFAULT;
    address += amount;
    length -= amount;
  }
  return 0;
}

/* AOSP mmap.cpp wrapper, with errno returned explicitly across the host ABI. */
extern "C" int32_t agr_bionic_mmap(agr_bionic_mmap_context* context,
                                    uint32_t address, uint32_t size,
                                    uint32_t protection, uint32_t flags,
                                    int32_t guest_fd, uint64_t offset,
                                    uint32_t* mapped_address,
                                    int32_t* guest_errno) {
  if (offset & 4095) {
    return fail(EINVAL, guest_errno);
  }
  if ((offset >> 12) > UINT32_MAX) return fail(EOVERFLOW, guest_errno);
  return agr_bionic_mmap2(context, address, size, protection, flags, guest_fd,
                          static_cast<uint32_t>(offset >> 12), mapped_address,
                          guest_errno);
}

/* AGR PORT: replacement for API19 ARM __mmap2 kernel entry only. */
extern "C" int32_t agr_bionic_mmap2(agr_bionic_mmap_context* context,
                                     uint32_t address, uint32_t length,
                                     uint32_t protection, uint32_t flags,
                                     int32_t guest_fd, uint32_t page_offset,
                                     uint32_t* mapped_address,
                                     int32_t* guest_errno) {
  if (context == NULL || context->vma == NULL || context->write_guest == NULL ||
      mapped_address == NULL || length == 0 || !valid_protection(protection)) {
    return fail(EINVAL, guest_errno);
  }
  const uint32_t known = AGR_MAP_SHARED | AGR_MAP_PRIVATE | AGR_MAP_FIXED |
                         AGR_MAP_ANONYMOUS | AGR_MAP_NORESERVE;
  if ((flags & ~known) != 0 || ((flags & AGR_MAP_SHARED) != 0) ==
      ((flags & AGR_MAP_PRIVATE) != 0) ||
      ((flags & AGR_MAP_FIXED) != 0 && (address & 4095) != 0) {
    return fail(EINVAL, guest_errno);
  }
  uint32_t vma_flags = (flags & AGR_MAP_FIXED) ? AGR_GUEST_VMA_FIXED : 0;
  int error = agr_guest_vma_map(context->vma, address, length, protection,
                                vma_flags, mapped_address);
  if (error != 0) return fail(error, guest_errno);

  if ((flags & AGR_MAP_ANONYMOUS) != 0) {
    error = write_zero(context, *mapped_address, length);
  } else {
    const uint8_t* bytes = NULL;
    uint32_t file_size = 0;
    uint64_t byte_offset = static_cast<uint64_t>(page_offset) << 12;
    if (guest_fd < 0 || context->file_view == NULL ||
        context->file_view(context->opaque, guest_fd, &bytes, &file_size) != 0 ||
        byte_offset > file_size || length > static_cast<uint64_t>(file_size) - byte_offset) {
      error = EBADF;
    } else if (context->write_guest(context->opaque, *mapped_address,
                                    bytes + static_cast<uint32_t>(byte_offset),
                                    length) != 0) {
      error = EFAULT;
    }
  }
  if (error != 0) {
    agr_guest_vma_unmap(context->vma, *mapped_address, length);
    return fail(error, guest_errno);
  }
  if (guest_errno != NULL) *guest_errno = 0;
  return 0;
}

extern "C" int32_t agr_bionic_mprotect(agr_bionic_mmap_context* context,
                                        uint32_t address, uint32_t length,
                                        uint32_t protection,
                                        int32_t* guest_errno) {
  if (context == NULL || context->vma == NULL || length == 0 ||
      !valid_protection(protection) || (address & 4095) != 0) return fail(EINVAL, guest_errno);
  int error = agr_guest_vma_protect(context->vma, address, length, protection);
  if (error != 0) return fail(error, guest_errno);
  if (guest_errno != NULL) *guest_errno = 0;
  return 0;
}

extern "C" int32_t agr_bionic_munmap(agr_bionic_mmap_context* context,
                                      uint32_t address, uint32_t length,
                                      int32_t* guest_errno) {
  if (context == NULL || context->vma == NULL || length == 0 || (address & 4095) != 0)
    return fail(EINVAL, guest_errno);
  int error = agr_guest_vma_unmap(context->vma, address, length);
  if (error != 0) return fail(error, guest_errno);
  if (guest_errno != NULL) *guest_errno = 0;
  return 0;
}
