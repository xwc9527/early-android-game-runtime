# AGR Architecture

## Mission

AGR executes original Android APK, DEX, resources, and ARMv7 binaries inside an iOS process by providing the Android 4.4.4/API19 behavior visible to games. It does not boot Android, system_server, or a complete userspace.

## Execution Placement

**GUEST-ARM** owns original native libraries, game ARM code, native callbacks, and GCC/libgcc/libgnustl EHABI and C++ exception propagation.

**HOST-NATIVE AOSP** owns portable source ports such as the formal KitKat linker/Bionic components, androidfw, portable framework behavior, and the host-side DEX interpreter/object model.

**HOST-HLE** owns true kernel, device, service, and presentation boundaries, including the SurfaceFlinger/AudioFlinger/device endpoints that iOS must replace.

## Process and State Model

AGR models one Android application process. There is no zygote, fork/exec, system_server, full Binder OS, or Android multiprocess model.

`ProcessRuntime` owns guest address space, VMA and heap, loaded DSO state, fd namespace, thread registry, shared DEX VM state, resources, process diagnostics, and shared service registries.

Every guest thread, including the main guest thread, has a `GuestThreadContext` containing its Darwin identity, guest pthread identity, ARM CPU/registers, guest stack, Bionic TLS and errno, lifecycle, current PC, recent calls, reentrancy depth, exit state, and TLS destructor state.

One guest pthread maps to one Darwin pthread. The Runtime must not restore a cooperative scheduler or serialize the entire process with one global lock.

## Service Affinity

- `CurrentThreadDirect`: portable and thread-safe services execute on the calling Darwin worker.
- `EGLContextOwner`: operations execute on the thread owning the EGL context.
- `AndroidLooperOwner`: queue/Looper behavior executes at its Android owner.
- `IOSMainThread`: UIKit-only endpoints execute on the iOS main thread.

UIKit must not execute arbitrary guest code. Cross-affinity synchronous waits occur without AGR internal shared-state locks. Host-to-guest callbacks follow the registered thread context and reentrancy policy.

## Guest ABI

The guest ABI is little-endian ARM32/armeabi-v7a with API19-visible layout and 4 KiB Android page semantics. Guest pointers, sizes, fds, pthread objects, structs, handles, and errno remain 32-bit Android values. Darwin pointers and layouts never cross the boundary.

## Ownership Boundaries

The formal AOSP-derived linker is the sole owner of ELF mappings, dependencies, symbols, relocations, constructors, finalizers, and libdl lifetime.

DEX runs host-side. JNI is the explicit bridge between host DEX objects and guest ARM native code; guest C++ exception machinery remains guest code.

Graphics follows `guest EGL/GLES -> AGR bridge -> ANGLE -> Metal`.

Input follows `UIKit raw event -> Android InputQueue semantics -> Android Looper -> guest handler`. UIKit supplies events and surfaces but does not implement Android policy.

## Source Migration Policy

1. Port exact API19 AOSP/Bionic source when portable.
2. Preserve upstream algorithms and observable state while replacing only the OS boundary.
3. Use HLE only at real kernel, service, device, or platform boundaries.
4. Use a self-written replacement only when direct source reuse is unsuitable and record the justification in `DECISIONS.md`.

Python is restricted to build, audit, test, CI, and device observation. Production Runtime remains native C/C++, Rust for the existing ARM interpreter, and necessary iOS host code.

## Technical Debt Policy

Architecture debt must be resolved. Implementation debt remains outside the active target unless it blocks a closed public Android contract, stability, or a locked architecture. A missing call observed in a real game does not by itself open that debt. Framework work follows `REFERENCE_MIGRATION_RULES.md`.
