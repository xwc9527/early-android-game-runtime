# Android 4.4.4 Bionic native source baseline

These unmodified source files are from `platform/bionic` tag
`android-4.4.4_r2`, peeled commit
`081db840befec895fb86e709ae95832ade2d065c` at
https://android.googlesource.com/platform/bionic/.

The original source paths are preserved under this directory. They are a
source baseline for the host-native API19 pthread/TLS/errno port, not yet a
compiled Runtime component. In particular, `libc/bionic/pthread.c` owns the
KitKat mutex, condition-variable, once, and futex-wrapper control flow;
`pthread_create.cpp`, `pthread_join.cpp`, and `pthread_detach.cpp` own thread
lifecycle; `pthread_key.cpp` owns key allocation, deletion, and destructor
iteration. `libc/include/pthread.h` and the private headers define the ARM32
ABI and TLS slots. Linux syscall/clone/kernel TLS boundaries must be replaced
by the AGR host primitives when ported. The host's 64-bit `pthread_t` and
Darwin `errno` must never be exposed to the guest.

Importing these files alone does not make pthread production ready. The old
synthetic thread dispatcher remains active until the source port, real host
thread binding, API19 differential, stress, and both iOS builds pass.

## Allocator provenance and API19 configuration

The allocator files under `libc/bionic`, `libc/upstream-dlmalloc`, and
`libc/include/malloc.h` are from the same pinned tag and peeled commit. The
production port is generated from the unmodified
`libc/upstream-dlmalloc/malloc.c` (dlmalloc 2.8.6) and retains the KitKat
wrapper configuration from `libc/bionic/dlmalloc.h`:

- `HAVE_GETPAGESIZE=1`, `MALLOC_INSPECT_ALL=1`, `MSPACES=0`;
- `REALLOC_ZERO_BYTES_FREES=1`, `USE_DL_PREFIX=1`, `USE_LOCKS=1`;
- `LOCK_AT_FORK=1`, recursive and spin locks disabled;
- `DEFAULT_MMAP_THRESHOLD=64 KiB`, `PROCEED_ON_ERROR=0`;
- wrapper `MMAP` and `DIRECT_MMAP` both use named anonymous mappings;
- the ARM32 default `MALLOC_ALIGNMENT` is 8 bytes.

AGR changes only representation and OS boundaries: persistent allocator
pointers and sizes are explicit 32-bit guest values, chunk/bin/top/dv/segment
state remains in guest memory, the lock is host-native, and
`MMAP`/`MORECORE`/`MUNMAP`, errno, and fatal reporting are adapters to the
formal guest VMA and per-thread Bionic TLS. `Runtime/Bionic/
agr_api19_dlmalloc_source.inc` is the mechanically adapted compilation form;
this unmodified vendor copy remains the source provenance and review oracle.

Pinned SHA-256 values:

- `libc/bionic/dlmalloc.c`: `02328DFE84D69BC51E272E28C2D9A58F507C012D88764C3F8D220972F275D69B`
- `libc/bionic/dlmalloc.h`: `E74CB3C01102EA98BF8E737715F3EFAAC54CC61BEFD72E1C228B0480095C1668`
- `libc/upstream-dlmalloc/malloc.c`: `C36002B8DB5F899487DFA471E544C5D9C3263CE2488C4DF606AB5C1FB2E4AEB1`
