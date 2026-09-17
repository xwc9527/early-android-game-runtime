# Android 4.4.4 linker source port

Upstream baseline: AOSP tag `android-4.4.4_r2`, platform/bionic commit
`081db840befec895fb86e709ae95832ade2d065c`.

Production source ownership:

- `bionic/linker/linker_phdr.cpp`
  - `phdr_table_get_load_size`
  - `ElfReader::ReserveAddressSpace`
  - `ElfReader::LoadSegments`
  - `_phdr_table_set_load_prot`
  - `phdr_table_protect_segments`
  - `_phdr_table_set_gnu_relro_prot` / `phdr_table_protect_gnu_relro`
- `bionic/libc/bionic/mmap.cpp`
  - byte-offset alignment check
  - `mmap` to `__mmap2` 4096-byte-unit conversion

The port retains these functions' control flow and address/page formulas. It
owns ELF load-span calculation, load bias, reservation, `PT_LOAD` file mapping,
writable partial-page zero fill, anonymous BSS pages, segment protection
restoration, and GNU RELRO. The AGR `agr_aosp_linker_unload` wrapper releases
the load extent; this wrapper is not copied from `linker_phdr.cpp`.

AGR modifications are limited to the platform boundary:

- native pointers representing mapped Android addresses are `uint32_t` guest
  addresses;
- direct `mmap`, `mprotect`, and `munmap` syscalls call the Bionic adapter;
- the adapter calls `agr_guest_vma` and guest-memory write callbacks;
- Android errno is returned explicitly because host errno is not guest TLS;
- ELF bytes are exposed through a guest-fd file view rather than a Darwin fd;
- AOSP logging macros are replaced by the caller's structured error result.
- `validate_headers` adds bounds/congruence checks on the in-memory ELF view;
  it is AGR glue, not an AOSP function.
- `phdr_table_protect_gnu_relro` in the port folds the original helper into
  one function; its page-rounding and `PROT_READ` policy are retained.
- the AOSP wrapper's `madvise(MADV_MERGEABLE)` hint is omitted because the
  guest VMA is backed by interpreter memory, not Linux KSM pages. It is not
  an Android-visible segment mapping decision.

`agr_guest_vma` does not select segment addresses or protections. It only
performs the raw map/protect/unmap operations requested by the ported AOSP
policy. The former independently rewritten `agr_aosp_linker.c` is deleted and
is not compiled by any production or test target.
