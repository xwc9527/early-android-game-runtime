# Android Guest Runtime Core

`agr_runtime.c` is the portable native implementation. It owns guest-address
allocation, ARM32 ELF loading/linking state, `DT_NEEDED`, dynamic symbols,
relocations, constructors, `libdl`, ARM exidx lookup, errno/TLS, pthread object
state and the implemented Bionic/C++ ABI calls.

It does not call Windows or Android kernel APIs. Guest memory access and import
resolution enter through the callback table in `agr_runtime.h`. The same API can
be connected directly to the Rust ARM interpreter and an iOS host.

`runtime_core/*.py` is a Windows PoC adapter and regression harness. It is not a
Runtime implementation target. It connects the C callback table to the current
interpreter, translates scheduler actions, and preserves the old JSON evidence
format while functionality is migrated out of `run_poc.py`.

The implementation follows the Android 4.4.4 Bionic linker behavior for the
ARM relocation set exercised by the corpus: `R_ARM_RELATIVE`, `R_ARM_ABS32`,
`R_ARM_REL32`, `R_ARM_GLOB_DAT`, and `R_ARM_JUMP_SLOT`. It deliberately maps
observable Bionic behavior onto host services instead of importing Bionic's
Linux syscalls or private TLS implementation.
