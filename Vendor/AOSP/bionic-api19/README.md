# Android 4.4.4 Bionic pthread source baseline

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
