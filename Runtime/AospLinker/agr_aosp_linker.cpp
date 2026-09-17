/*
 * Copyright (C) 2012 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Source port: android-4.4.4_r2 bionic/linker/linker_phdr.cpp.
 * Ported policy functions: phdr_table_get_load_size, ReserveAddressSpace,
 * LoadSegments, _phdr_table_set_load_prot, phdr_table_protect_segments, and
 * phdr_table_protect_gnu_relro. Host-boundary edits are listed in SOURCE_PORT.md.
 */
#include "agr_aosp_linker.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

#define PAGE_SIZE 4096
#define PAGE_START(x) ((x) & ~4095U)
#define PAGE_END(x) PAGE_START((x) + (PAGE_SIZE-1))
#define PAGE_OFFSET(x) ((x) & (PAGE_SIZE-1))
#define PT_GNU_RELRO 0x6474e552U
#define PF_X 1U
#define PF_W 2U
#define PF_R 4U
#define PFLAGS_TO_PROT(x) (((x) & PF_R ? AGR_PROT_READ : 0) | ((x) & PF_W ? AGR_PROT_WRITE : 0) | ((x) & PF_X ? AGR_PROT_EXEC : 0))

struct SourceView {
  const uint8_t* bytes;
  uint32_t size;
  agr_bionic_mmap_context* host;
};

static int32_t source_file(void* opaque, int32_t fd, const uint8_t** bytes, uint32_t* size) {
  SourceView* source = static_cast<SourceView*>(opaque);
  if (source == NULL || fd != 1 || bytes == NULL || size == NULL) return EBADF;
  *bytes = source->bytes;
  *size = source->size;
  return 0;
}
static int32_t source_write(void* opaque, uint32_t address, const void* bytes, uint32_t size) {
  SourceView* source = static_cast<SourceView*>(opaque);
  return source->host->write_guest(source->host->opaque, address, bytes, size);
}
static int zero_guest(agr_bionic_mmap_context* context, uint32_t address, uint32_t size) {
  static const uint8_t zero[PAGE_SIZE] = {0};
  while (size != 0) {
    uint32_t amount = size > sizeof(zero) ? sizeof(zero) : size;
    if (context->write_guest(context->opaque, address, zero, amount) != 0) return -1;
    address += amount; size -= amount;
  }
  return 0;
}

/* AOSP linker_phdr.cpp::phdr_table_get_load_size, with names retained. */
static size_t phdr_table_get_load_size(const Elf32_Phdr* phdr_table,
                                       size_t phdr_count,
                                       Elf32_Addr* out_min_vaddr,
                                       Elf32_Addr* out_max_vaddr) {
  Elf32_Addr min_vaddr = 0xFFFFFFFFU;
  Elf32_Addr max_vaddr = 0x00000000U;

  bool found_pt_load = false;
  for (size_t i = 0; i < phdr_count; ++i) {
    const Elf32_Phdr* phdr = &phdr_table[i];
    if (phdr->p_type != PT_LOAD) {
      continue;
    }
    found_pt_load = true;
    if (phdr->p_vaddr < min_vaddr) {
      min_vaddr = phdr->p_vaddr;
    }
    if (phdr->p_vaddr + phdr->p_memsz > max_vaddr) {
      max_vaddr = phdr->p_vaddr + phdr->p_memsz;
    }
  }
  if (!found_pt_load) {
    min_vaddr = 0x00000000U;
  }

  min_vaddr = PAGE_START(min_vaddr);
  max_vaddr = PAGE_END(max_vaddr);

  if (out_min_vaddr != NULL) {
    *out_min_vaddr = min_vaddr;
  }
  if (out_max_vaddr != NULL) {
    *out_max_vaddr = max_vaddr;
  }
  return max_vaddr - min_vaddr;
}

static int validate_headers(const void* bytes, uint32_t size, const Elf32_Ehdr** ehdr,
                            const Elf32_Phdr** phdr, int32_t* guest_errno) {
  if (bytes == NULL || size < sizeof(Elf32_Ehdr)) goto invalid;
  *ehdr = static_cast<const Elf32_Ehdr*>(bytes);
  if (memcmp((*ehdr)->e_ident, ELFMAG, SELFMAG) != 0 || (*ehdr)->e_ident[EI_CLASS] != ELFCLASS32 ||
      (*ehdr)->e_machine != EM_ARM || (*ehdr)->e_phentsize != sizeof(Elf32_Phdr) ||
      (*ehdr)->e_phnum < 1 || (*ehdr)->e_phnum > 65536/sizeof(Elf32_Phdr) ||
      (*ehdr)->e_phoff > size || static_cast<uint64_t>((*ehdr)->e_phnum)*sizeof(Elf32_Phdr) > size-(*ehdr)->e_phoff) goto invalid;
  *phdr = reinterpret_cast<const Elf32_Phdr*>(static_cast<const uint8_t*>(bytes)+(*ehdr)->e_phoff);
  for (size_t i=0;i<(*ehdr)->e_phnum;++i) if ((*phdr)[i].p_type==PT_LOAD) {
    const Elf32_Phdr* p=&(*phdr)[i];
    if (p->p_filesz>p->p_memsz || static_cast<uint64_t>(p->p_offset)+p->p_filesz>size ||
        static_cast<uint64_t>(p->p_vaddr)+p->p_memsz>UINT32_MAX || PAGE_OFFSET(p->p_vaddr)!=PAGE_OFFSET(p->p_offset)) goto invalid;
  }
  return 0;
invalid: if (guest_errno != NULL) *guest_errno=ENOEXEC; return -1;
}

/* AOSP ElfReader::ReserveAddressSpace, with mmap replaced at the syscall boundary. */
static bool ReserveAddressSpace(agr_bionic_mmap_context* context, const Elf32_Phdr* table,
                                size_t count, uint32_t preferred_bias,
                                agr_aosp_linker_image* image, int32_t* guest_errno) {
  Elf32_Addr min_vaddr;
  Elf32_Addr max_vaddr;
  size_t load_size = phdr_table_get_load_size(table, count, &min_vaddr, &max_vaddr);
  if (load_size == 0 || load_size > UINT32_MAX) {
    if (guest_errno != NULL) *guest_errno = ENOEXEC;
    return false;
  }

  // AGR PORT: the original uint8_t* address is an explicit 32-bit guest address.
  uint32_t addr = preferred_bias <= UINT32_MAX - min_vaddr ?
                  preferred_bias + min_vaddr : 0;
  int mmap_flags = AGR_MAP_PRIVATE | AGR_MAP_ANONYMOUS;
  uint32_t start = 0;
  if (agr_bionic_mmap2(context, addr, static_cast<uint32_t>(load_size),
                       AGR_PROT_NONE, mmap_flags, -1, 0, &start, guest_errno) != 0) {
    return false;
  }

  image->load_start = start;
  image->load_size = static_cast<uint32_t>(load_size);
  image->load_bias = start - min_vaddr;
  image->min_vaddr = min_vaddr;
  image->max_vaddr = max_vaddr;
  return true;
}

/* AOSP ElfReader::LoadSegments. All address/layout decisions remain in this function. */
static bool LoadSegments(agr_bionic_mmap_context* context, const Elf32_Phdr* table,
                         size_t count, Elf32_Addr load_bias, int32_t* guest_errno) {
  for (size_t i = 0; i < count; ++i) {
    const Elf32_Phdr* phdr = &table[i];
    if (phdr->p_type != PT_LOAD) {
      continue;
    }

    // Segment addresses in guest memory.
    Elf32_Addr seg_start = phdr->p_vaddr + load_bias;
    Elf32_Addr seg_end = seg_start + phdr->p_memsz;
    Elf32_Addr seg_page_start = PAGE_START(seg_start);
    Elf32_Addr seg_page_end = PAGE_END(seg_end);
    Elf32_Addr seg_file_end = seg_start + phdr->p_filesz;

    // File offsets. This is the same page-aligned file window as AOSP.
    Elf32_Addr file_start = phdr->p_offset;
    Elf32_Addr file_end = file_start + phdr->p_filesz;
    Elf32_Addr file_page_start = PAGE_START(file_start);
    Elf32_Addr file_length = file_end - file_page_start;

    uint32_t mapped = 0;
    if (file_length != 0) {
      // AGR PORT: AOSP mmap(MAP_FIXED|MAP_PRIVATE, fd, file_page_start).
      if (agr_bionic_mmap2(context, seg_page_start, file_length,
                           PFLAGS_TO_PROT(phdr->p_flags),
                           AGR_MAP_FIXED | AGR_MAP_PRIVATE, 1,
                           file_page_start >> 12, &mapped, guest_errno) != 0) {
        return false;
      }
    }

    // AOSP zero-fills the unused tail of a writable file page.
    if ((phdr->p_flags & PF_W) != 0 && PAGE_OFFSET(seg_file_end) > 0) {
      if (zero_guest(context, seg_file_end,
                     PAGE_SIZE - PAGE_OFFSET(seg_file_end)) != 0) {
        if (guest_errno != NULL) *guest_errno = EFAULT;
        return false;
      }
    }

    seg_file_end = PAGE_END(seg_file_end);
    if (seg_page_end > seg_file_end) {
      // AGR PORT: AOSP anonymous MAP_FIXED BSS tail.
      if (agr_bionic_mmap2(context, seg_file_end,
                           seg_page_end - seg_file_end,
                           PFLAGS_TO_PROT(phdr->p_flags),
                           AGR_MAP_FIXED | AGR_MAP_ANONYMOUS | AGR_MAP_PRIVATE,
                           -1, 0, &mapped, guest_errno) != 0) {
        return false;
      }
    }
  }
  return true;
}

static int _phdr_table_set_load_prot(agr_bionic_mmap_context* context,const Elf32_Phdr* table,
                                     int count,Elf32_Addr bias,int extra,int32_t* guest_errno) {
  const Elf32_Phdr* phdr = table;
  const Elf32_Phdr* phdr_limit = phdr + count;
  for (; phdr < phdr_limit; phdr++) {
    if (phdr->p_type != PT_LOAD || (phdr->p_flags & PF_W) != 0) {
      continue;
    }
    Elf32_Addr seg_page_start = PAGE_START(phdr->p_vaddr) + bias;
    Elf32_Addr seg_page_end = PAGE_END(phdr->p_vaddr + phdr->p_memsz) + bias;
    // AGR PORT: AOSP mprotect on the guest VMA, retaining PFLAGS_TO_PROT.
    if (agr_bionic_mprotect(context, seg_page_start,
                            seg_page_end - seg_page_start,
                            PFLAGS_TO_PROT(phdr->p_flags) | extra,
                            guest_errno) != 0) {
      return -1;
    }
  }
  return 0;
}
static int phdr_table_protect_segments(agr_bionic_mmap_context* context,
                                        const Elf32_Phdr* table, int count,
                                        Elf32_Addr bias, int32_t* guest_errno) {
  return _phdr_table_set_load_prot(context, table, count, bias, 0, guest_errno);
}
static int phdr_table_protect_gnu_relro(agr_bionic_mmap_context* context,
                                         const Elf32_Phdr* table, int count,
                                         Elf32_Addr bias, agr_aosp_linker_image* image,
                                         int32_t* guest_errno) {
  const Elf32_Phdr* phdr = table;
  const Elf32_Phdr* phdr_limit = phdr + count;
  for (; phdr < phdr_limit; phdr++) {
    if (phdr->p_type != PT_GNU_RELRO) {
      continue;
    }
    // KitKat deliberately protects every page touched by PT_GNU_RELRO.
    Elf32_Addr seg_page_start = PAGE_START(phdr->p_vaddr) + bias;
    Elf32_Addr seg_page_end = PAGE_END(phdr->p_vaddr + phdr->p_memsz) + bias;
    if (agr_bionic_mprotect(context, seg_page_start,
                            seg_page_end - seg_page_start, AGR_PROT_READ,
                            guest_errno) != 0) {
      return -1;
    }
    image->relro_start = seg_page_start;
    image->relro_size = seg_page_end - seg_page_start;
  }
  return 0;
}

extern "C" int32_t agr_aosp_linker_map(agr_bionic_mmap_context* context,const void* bytes,uint32_t size,uint32_t preferred,agr_aosp_linker_image* image,int32_t* guest_errno){
  const Elf32_Ehdr*eh;const Elf32_Phdr*ph;if(context==NULL||image==NULL||validate_headers(bytes,size,&eh,&ph,guest_errno)!=0)return -1;
  memset(image,0,sizeof(*image));SourceView source={static_cast<const uint8_t*>(bytes),size,context};agr_bionic_mmap_context port=*context;port.opaque=&source;port.write_guest=source_write;port.file_view=source_file;
  if(!ReserveAddressSpace(&port,ph,eh->e_phnum,preferred,image,guest_errno))return -1;
  if(!LoadSegments(&port,ph,eh->e_phnum,image->load_bias,guest_errno)){agr_bionic_munmap(context,image->load_start,image->load_size,NULL);memset(image,0,sizeof(*image));return -1;}return 0;}
extern "C" int32_t agr_aosp_linker_finalize(agr_bionic_mmap_context*c,const void*b,uint32_t z,agr_aosp_linker_image*im,int32_t*e){const Elf32_Ehdr*eh;const Elf32_Phdr*ph;if(validate_headers(b,z,&eh,&ph,e)!=0)return -1;if(phdr_table_protect_segments(c,ph,eh->e_phnum,im->load_bias,e)!=0)return -1;return phdr_table_protect_gnu_relro(c,ph,eh->e_phnum,im->load_bias,im,e);}
extern "C" int32_t agr_aosp_linker_unload(agr_bionic_mmap_context*c,agr_aosp_linker_image*im,int32_t*e){if(c==NULL||im==NULL||im->load_size==0){if(e)*e=EINVAL;return -1;}if(agr_bionic_munmap(c,im->load_start,im->load_size,e)!=0)return -1;memset(im,0,sizeof(*im));return 0;}
