# ARM EHABI Phase 1 unwind source port

Behavioral source of truth is API19 / Android 4.4 era GCC ARM EHABI, not the
current AGR import shims.

Pinned references:

- ARM IHI 0038 Exception Handling ABI for the ARM Architecture
- GCC 4.8.5 `libgcc/config/arm/unwind-arm.c`
- GCC 4.8.5 `libgcc/config/arm/pr-support.c`
- GCC 4.8.5 `libgcc/unwind-arm-common.inc`
- KitKat Bionic `linker.cpp` `dl_unwind_find_exidx` via the already-ported
  `soinfo` / `PT_ARM_EXIDX` metadata in `agr_aosp_dynamic.cpp`

The Android 4.4 differential oracle (`Tests/Android44Unwind/probe.c`) is
compiled with NDK r10e `arm-linux-androideabi-gcc` 4.8 and `-static-libgcc`
so `_Unwind_Backtrace` is GCC `libgcc` ARM EHABI (`__gnu_Unwind_Backtrace`,
`__gnu_unwind_execute`). NDK r23+ Clang/LLVM libunwind is not a valid
reference.

Placement:

- EHABI registers, stack, return address, Thumb bit and unwind tables are
  **GUEST-ARM** contracts.
- The unwind engine is a **HOST-NATIVE** implementation of the upstream
  algorithm. It only reads 32-bit guest registers, guest memory, formal linker
  DSO metadata and guest stack bounds.
- Host C++ exceptions, Darwin unwind and host pointer layouts are not used.

Phase 1 implements guest stack unwinding only:

- `.ARM.exidx` binary search (`search_EIT_table`, `PC-2` as in GCC)
- `EXIDX_CANTUNWIND`
- compact personality 0/1/2 opcode decode
- core / SP / LR / PC restore
- VFP `VRS` pops restore `GuestUnwindContext.vfp_d[]` (including VFPX extra
  word). iWMMXt encodings are explicit `unsupported EHABI encoding` because
  this context has no iWMMXt register file; they must not silent-skip via SP
  adjustment alone
- ARM and Thumb return state
- explicit `unsupported EHABI encoding` for unknown personality indexes,
  custom personality routines, spare opcodes and iWMMXt

Phase 2 (not in this module yet): `__cxa_throw` / catch / rethrow /
personality catch selection / destructor cleanup / `libsupc++`.
