# Android 4.4.4 game runtime migration plan

## Boundary and decision rule

AGR hosts an Android 4.4.4/API 19 game process inside an iOS application. The
iOS shell owns UIKit, Metal, CoreAudio and the sandbox. Android-visible behavior
comes from Android 4.4.4 source whenever that behavior is independent of the
Linux kernel or Android system services.

Every component uses one of these decisions:

- **KEEP**: already uses the required upstream implementation or is a host-only
  component with no Android-visible policy.
- **REPLACE WITH AOSP**: the current implementation duplicates portable AOSP
  behavior and must be retired after differential tests pass.
- **ADAPT AOSP**: retain upstream algorithms and object models, replacing only
  kernel, Binder, SurfaceFlinger, AudioFlinger or platform-device boundaries.
- **HLE REQUIRED**: the observable contract is retained, but the original
  component cannot run without excluded Android services.
- **REMOVE**: sample-specific or synthetic behavior that is not part of the
  runtime architecture.

The pinned upstream baselines are Bionic commit
`081db840befec895fb86e709ae95832ade2d065c`, Dalvik commit
`36e356c96640775f0a3f167bd2426ea0f0093b8b`, and the Android 4.4.4_r2
framework trees. Research checkouts are inputs to the port; they are not linked
into a release until their source subset, license notice and adapter boundary
are recorded in the build.

## Hard architecture constraints

### Execution placement

Every migrated component has one declared execution location:

- **GUEST-ARM** preserves Android ARMv7 code, calling convention, registers,
  stack layout, ARM EHABI and guest pointers. It is used when the Android ARM
  ABI is part of the observable contract.
- **HOST-NATIVE AOSP** compiles ISA-independent AOSP algorithms for iOS arm64.
  Its public boundary uses explicit 32-bit guest ABI records; no host pointer,
  `long`, `size_t`, `va_list`, fd, pthread object or native C++ object crosses
  that boundary.
- **HOST-HLE** terminates an Android contract at an unavailable kernel,
  Binder, system service, SurfaceFlinger, AudioFlinger or device boundary.
  HLE is not permission to fabricate success.

| Component | Placement | Reason and non-negotiable boundary |
|---|---|---|
| iOS shell and HostServices | **HOST-HLE** | UIKit, Metal, CoreAudio, sandbox, raw Darwin VM/file/thread/wait primitives only; contains no Android policy |
| ARM interpreter | **HOST-NATIVE backend** | CPU implementation is host native; all executed game/NDK instructions remain **GUEST-ARM** |
| Guest VMA, fd namespace and path policy | **HOST-NATIVE AOSP adapter** | Maintains Android 32-bit addresses, flags, errno and paths over raw HostServices |
| Bionic ARM assembly and libm ARM entry points | **GUEST-ARM** | Register ABI, softfp/VFP entry behavior and 32-bit data layout are observable |
| Portable Bionic libc algorithms and stdio | **HOST-NATIVE AOSP** | Guest structs, varargs and pointers use marshal adapters; syscalls terminate in HostServices |
| Allocator | **GUEST-ARM preferred** | API19 dlmalloc operating on guest VMA prevents host allocator layout leaking into guest |
| pthread/TLS/errno | **HOST-NATIVE AOSP adapter** | Preserve Bionic object representation and algorithms; map guest threads to Darwin pthreads and replace futex/clone/TLS kernel edges |
| dynamic linker/libdl | **HOST-NATIVE AOSP adapter** | Retain API19 ARM ELF algorithms; relocation writes and symbol values are 32-bit guest values |
| C++ ABI, libgcc unwind and ARM EHABI | **GUEST-ARM** | Exceptions, exidx, personality routines, registers and stack unwinding remain in one ARM domain |
| DEX interpreter and Java object model | **HOST-NATIVE AOSP semantics** | Dalvik algorithms are adapted to the host DEX engine; Java objects never become guest pointers directly |
| JNI/JavaVM/native binding | **HOST-NATIVE AOSP adapter** | Dalvik indirect-reference algorithms and lifecycle; ARM calls cross one explicit JNI ABI bridge |
| androidfw, manifest and resources | **HOST-NATIVE AOSP** | Parser/resource algorithms are ISA independent; guest access uses opaque 32-bit handles |
| Bitmap/Skia codec | **HOST-NATIVE AOSP** | Pixel storage is host owned; Bitmap JNI exposes API19 lifetime, density, stride and errors |
| Context and basic Framework | **HOST-NATIVE AOSP + HOST-HLE** | Standalone Java/AOSP behavior is retained; service-backed calls stop at a declared HLE registry |
| NativeActivity/Looper/Input/Window | **HOST-NATIVE AOSP + HOST-HLE** | AOSP state machines and event objects remain; UIKit/Metal and wait sources are host endpoints |
| EGL/GLES wrappers | **GUEST-ARM exports + HOST-HLE backend** | Android entry ABI and guest memory remain 32-bit; rendering terminates in ANGLE/Metal |
| SoundPool/AudioTrack/OpenSL ES | **HOST-NATIVE AOSP + HOST-HLE** | Android object/state model remains; AudioFlinger/device output is replaced by CoreAudio |
| APK launcher | **HOST-NATIVE AOSP** | Package, manifest, ABI and SDK decisions derive from APK metadata |

### Locked guest ABI

The declared guest is Android API19 ARM 32-bit `armeabi-v7a`, with compatible
ARMv7 `armeabi` content accepted only when its actual instruction and ABI
requirements fit the same runtime. Guest-visible rules are fixed: 32-bit
pointers, `long` and `size_t`; little-endian ARM EABI alignment and structure
layout; Android enum and flag values; guest `va_list`; Android errno; and the
actual softfp/VFP calling convention required by each imported symbol. Android
x86, x86_64 and arm64 are outside the current scope.

Boundary structs use fixed-width fields and explicit copy-in/copy-out. Darwin
fds, pthread objects, pointers and arm64 layouts are never serialized into
guest memory. Each adapter gets ABI layout assertions or generated layout tests.

### Process and thread model

AGR represents one Android application process. It does not provide zygote,
`fork`, `exec`, multiple Android processes, system_server, Binder IPC or Android
System UI. A manifest component requesting a distinct process is rejected as
unsupported. Inside the process, real multithreading, TLS, futex-equivalent
wait/wake, thread-local errno, JNI attach/detach, Looper, C++ unwind and Java
GC/safepoints are required.

The formal mapping is one guest application thread to one Darwin pthread while
runnable. Guest identity, Bionic TLS, errno, JNI state, signal mask and stack
remain runtime-owned records. The old cooperative synthetic thread mechanism
is a bootstrap fixture and is removed after Bionic thread contracts pass.

### HostServices policy boundary and AOSP consumer ledger

HostServices exports raw host primitives only. Android flags, errno mapping,
path layout, pthread policy, lifecycle, JNI and resources belong above it.
Ported AOSP modules do not call Darwin directly unless a documented private
implementation detail cannot affect Android-observable behavior.

| Phase 1 primitive | Required AOSP consumer | Stop condition for Phase 1 work |
|---|---|---|
| VM reserve/protect/release and guest VMA | Bionic `mmap`, dlmalloc, linker PT_LOAD mapping, thread stacks | anonymous/private/fixed/protection contracts are sufficient to start the Bionic consumer port |
| Raw file operations and guest fd namespace | Bionic open/fcntl/unistd and BSD stdio | fd reuse/error/dup contracts pass; Android flag/path/errno policy is implemented with Bionic |
| Monotonic/realtime clock | Bionic time and pthread timeout code | raw clocks exist; clock-id semantics move to Bionic |
| Host thread and wait/wake | Bionic pthread/futex adapter and Dalvik safepoints | create/join/wait/wake support the first real Bionic contention test |
| Sandbox root/path primitive | Bionic filesystem adapter and Framework Context paths | host supplies canonical roots; Android directory layout is built above |

No Phase 1 primitive without a named consumer is added. Once these minimum
edges exist, work moves immediately into the corresponding AOSP component.

### Required guest VMA semantics

The VMA adapter covers anonymous and file-backed mappings, `MAP_PRIVATE`,
API19-relevant `MAP_SHARED`, `MAP_FIXED`, protection changes, executable
mappings, unmap split/coalesce, address reuse, failure/errno, linker segment
mapping, allocator page acquisition and guarded guest stacks. Guest pages are
4 KiB even when the Darwin host page is larger; the backing adapter coalesces
host operations without changing guest-visible boundaries. `brk`/`sbrk` is an
adapter over the reserved guest heap arena only for API19 callers that need it;
it is not an independent second heap.

The current VMA contract implements anonymous metadata, fixed/noreplace,
split/coalesce, protection and reuse. File backing, host-page projection,
`MAP_SHARED`, executable policy, stack guards and `brk` remain incomplete until
the Bionic/linker consumers and their tests are connected.

### pthread, futex, atomics and memory ordering

The baseline is `bionic/libc/bionic/pthread*.{c,cpp}`, `pthread_key.cpp`,
`semaphore.c`, `bionic_futex.h`, ARM atomic helpers and `sys/atomics.h`.
Bionic mutex/cond/once algorithms remain. Linux futex operations become runtime
wait/wake keyed by guest address and expected 32-bit value. ARM acquire/release
and full-barrier behavior is enforced around guest atomic state before host
waiting or waking. Contracts cover contention, recursive/error-check mutexes,
condition variables, once, join/detach, thread exit, TLS destructor iterations
and realtime/monotonic timed waits.

### Signal scope

Signals are **ADAPT AOSP + HOST-HLE**, not a Linux signal subsystem. Required
behavior includes per-thread masks used by Bionic/Dalvik, supported
`sigaction`/`signal`, a `sigaltstack` equivalent for stack-overflow/crash
handling, translation of guest memory/CPU faults into Android-style
SIGSEGV/SIGBUS state, and Bionic SIGABRT behavior. Darwin signals are not
delivered directly into guest handlers. Unsupported asynchronous signals
return the API19-defined error. Zygote SIGCHLD behavior is excluded. The source
evidence is Bionic `abort.cpp`, `pthread_create.cpp`, `pthread_sigmask.cpp` and
Dalvik `vm/Init.cpp`/`Thread.cpp`.

### API19 game native library compatibility surface

| Library/surface | Source baseline | Decision and placement |
|---|---|---|
| `libc.so`, `libm.so`, `libdl.so`, linker | `bionic/{libc,libm,libdl,linker}` | **ADAPT AOSP**, mixed **GUEST-ARM/HOST-NATIVE AOSP** as declared above |
| `liblog.so` | `system/core/liblog` | **ADAPT AOSP**, **HOST-HLE** transport to AGR structured Android log; binary/event contracts remain |
| `libandroid.so` | `frameworks/base/native/android` | **ADAPT AOSP**; Looper/input/config/assets remain, Binder/gui/service edges are **HOST-HLE** |
| `libjnigraphics.so` | `frameworks/base/native/graphics/jni` plus Skia | **ADAPT AOSP**, **HOST-NATIVE AOSP** Bitmap pixel/lock contracts |
| `libnativehelper` | `platform/libnativehelper` at the pinned tag | **ADAPT AOSP**, **HOST-NATIVE AOSP** utilities over formal JavaVM/JNIEnv |
| platform `libstdc++.so` | KitKat platform compatibility runtime | **GUEST-ARM** original ABI when imported; never substitute Darwin libc++ ABI |
| `libgcc` and ARM EHABI | API19 NDK/GCC ARM runtime | **GUEST-ARM** unwind, personality and compiler helpers |
| `libz.so` | `external/zlib` pinned KitKat tag | **HOST-NATIVE AOSP** behind guest ABI adapter, or **GUEST-ARM** when APK-bundled |
| APK-bundled `gnustl`/`stlport` | matching API19-era NDK runtime | **GUEST-ARM original**; linker resolves its EHABI dependencies |
| Binder/gui/system-only libraries | respective AOSP trees | no general binary surface; declared game-facing contracts terminate at **HOST-HLE** |

This surface is reviewed against API19/NDK exports before game runs. APK
DT_NEEDED data prioritizes work but does not define the implementation.

### Framework capability declaration

The Runtime maintains a machine-readable supported API/service table generated
from passed contracts. Each entry declares its API19 behavior for success,
`null`, exception, unsupported return or hard Runtime failure. Unknown services
are never synthesized. Fixed handles, synthetic resource IDs, fake SoundPool
success and always-0/1 branches are prohibited and removed with their formal
owning modules.

### APK launcher metadata requirements

The launcher enumerates `classes.dex`, `classes2.dex` and subsequent numbered
DEX entries. Multi-dex execution is a Phase 6 gate; before that gate, a
multi-dex APK is rejected explicitly rather than partially launched. Native
libraries are selected from `lib/armeabi-v7a` first and compatible
`lib/armeabi` second, based on declared capability. `minSdkVersion` and
`targetSdkVersion` are parsed and feed a documented API19 legacy-behavior
table. Package names, classes, libraries, addresses and callbacks never come
from host constants.

## Module migration decisions

| Environment module | Android 4.4.4 source of truth | Current AGR code | Decision | Host dependency replaced at the boundary | Completion criterion |
|---|---|---|---|---|---|
| iOS shell | `App/main.m` is host code, not AOSP | UIKit app, touch source, diagnostics | **KEEP**, then split sample harness from shell | UIKit window/lifecycle, app sandbox, Metal/CoreAudio handles | Shell starts an empty game process without package-specific names and exposes only host-service interfaces |
| ARMv7 execution | Android ARM EABI plus CPU architecture; touchHLE interpreter is the selected backend | `Runtime/ArmInterpreter` | **KEEP** | No Android policy in the CPU backend; memory faults and SVC/import exits go to the process runtime | A32/Thumb-2/VFP corpus and undefined-instruction reporting pass independently of games |
| Guest address space and VMA | Bionic `libc/bionic/mmap.cpp`, `libc/SYSCALLS.TXT`; Linux `mmap`, `mprotect`, `munmap` contracts | Flat interpreter mapping plus NativeCore heap | **ADAPT AOSP** | Darwin `mmap/mprotect/munmap`; AGR maintains Android 32-bit VMA, page and errno semantics | API 19 mapping/protection differential tests, overlap/split/coalesce tests and long allocation stress pass |
| Files, fd and stdio | Bionic `open.c`, `fcntl.c`, `lseek64.c`, BSD stdio under `libc/stdio` | Callback fragments and virtual pipes | **ADAPT AOSP** | Paths are translated into the iOS container; fd primitives use Darwin descriptors or virtual device endpoints | Identical API19 tests cover open flags, seek, append, EOF, errno, stdio buffering and sandbox path mapping |
| Clock and time | Bionic time wrappers, tzcode and generated syscall stubs | Synthetic 16.7 ms increment | **REPLACE WITH AOSP** | `mach_continuous_time`/`clock_gettime`, wall clock and timezone provider | Monotonic/realtime/CPU clock and timeout behavior match Android 4.4 reference output |
| Signals and fault delivery | Bionic `signal.c`, `abort.cpp`, `pthread_sigmask.cpp`, generated signal syscalls; Dalvik `vm/Init.cpp`, `Thread.cpp` | Host crash/failure capture only | **ADAPT AOSP + HLE REQUIRED** | Runtime-owned guest masks/actions and alt stacks; interpreter/VMA faults become guest SIGSEGV/SIGBUS state; Darwin signals stay host-private | Mask/action/abort/fault/stack-overflow contracts pass; unsupported asynchronous signals fail explicitly |
| Bionic libc string/stdlib/stdio | `bionic/libc/{bionic,stdio,stdlib,string,upstream-*}` | Function-name host dispatcher | **REPLACE WITH AOSP** for portable code; **ADAPT AOSP** for syscall wrappers | Calls into the host-service ABI rather than Linux syscalls; guest pointers remain 32-bit | Selected Bionic tests compile for the runtime, then differential and stress suites pass without per-symbol sample shims |
| libm | `bionic/libm`, including ARM ABI entry points | Small host-libm switch | **REPLACE WITH AOSP** | ARM routines execute as guest code; unavoidable host primitives use well-defined bit-level adapters | Bionic libm test vectors and FP exception/NaN/rounding cases match reference |
| allocator | `libc/bionic/dlmalloc.c`, `libc/upstream-dlmalloc` | AGR free-list allocator | **ADAPT AOSP**; retain current allocator only as bootstrap | dlmalloc obtains/relinquishes guest pages through VMA adapter rather than Linux `mmap`/`sbrk` | Bionic malloc tests, million-operation stress, alignment, fragmentation and OOM semantics pass |
| pthread, mutex, cond, once | `libc/bionic/pthread*.{c,cpp}`, `semaphore.c`; futex syscall boundary | Cooperative fixed tables | **ADAPT AOSP** | futex/clone/TLS setup map to an AGR scheduler backed by Darwin pthreads and condition primitives | Contention, timed waits, recursive/error-check mutexes, join/detach, TLS destructors and cancellation-declared behavior match API19 |
| TLS and errno | Bionic private TLS layout, `__errno.c`, `pthread_key.cpp` | Fixed key arrays per synthetic thread | **ADAPT AOSP** | Per-guest-thread TLS block is owned by AGR; host TLS only locates the current guest thread | Key reuse, destructor iterations, detach and errno isolation differential tests pass |
| linker and libdl | `bionic/linker/{linker.cpp,linker_phdr.cpp,dlfcn.cpp,rt.cpp}` and `libdl` | Custom ELF loader and partial `dl*` | **ADAPT AOSP**; current loader remains bootstrap/oracle only | File mapping, page protection, logging and process namespace enter through host services | DT_NEEDED traversal, API19 ARM relocations, symbol scope, init/fini order, dlopen refcounts and unload tests match reference |
| C++ ABI and ARM EHABI | NDK/GCC-era `libstdc++`, `libsupc++`, `libgcc` unwind ABI plus Bionic exidx lookup | Guards/atexit/exidx lookup only | **ADAPT AOSP/toolchain runtime** | Unwind reads guest registers and guest memory through the CPU adapter; host C++ exceptions never cross the boundary | Throw/catch/rethrow/destructor/unwind-across-DSO tests execute entirely in the ARMv7 domain |
| DEX parser/interpreter | Dalvik `libdex`, `vm/interp`, `vm/oo`, `vm/Exception.cpp` | DexLoom VM | **ADAPT AOSP semantics**; keep DexLoom execution engine only where differential tests prove parity | JIT, signals, ashmem and zygote are excluded; host allocator/thread/time adapters replace them | Opcode, class init, resolution, dispatch and exception differential corpus passes on Android 4.4 and AGR |
| GC and Java object model | Dalvik `vm/alloc`, `vm/oo`, root scanning in VM/thread/JNI code | DexLoom fixed heap and own collector | **ADAPT AOSP** data/lifecycle algorithms | Heap pages and safepoints use AGR memory/thread services; no zygote heap | Root, weak-reference, finalization, allocation pressure and native-reference stress match reference |
| JNI references and IDs | Dalvik `IndirectRefTable.*`, `ReferenceTable.*`, `Jni.cpp`, `Thread.*`, `Native.*` | Fixed handles, no-op refs, partial dynamic method IDs | **REPLACE WITH AOSP** reference-table algorithms; **ADAPT AOSP** JNI entry layer | Object payloads are Dex host objects while guest sees 32-bit serialised indirect refs; thread state comes from AGR | Local frames, stale-ref detection, global/weak roots, method/field IDs, arrays, strings, direct buffers and GC interaction pass JNI differential tests |
| JavaVM and native binding | Dalvik `Jni.cpp`, `Native.cpp`, thread attach/detach | Three simplified VM slots and two method special cases | **REPLACE WITH AOSP** semantics | ARM function calls use the interpreter bridge; host DEX frames use the host DEX runtime | JNI_OnLoad/RegisterNatives/name lookup, attach/detach/GetEnv and callbacks work without class or method special cases |
| APK/manifest/package metadata | `frameworks/base/libs/androidfw`, `PackageParser` behavior and manifest resource definitions | APK assets work; startup metadata is hard-coded | **KEEP** androidfw; **ADAPT AOSP** manifest/package parsing | APK bytes come from iOS files; package installation/system service is replaced by an in-process package record | Package/activity/native-library metadata is derived only from APK and configured compatibility profile |
| Context, Resources and basic services | `frameworks/base/core/java/android/{content,app}`, native androidfw | Small sample-specific native registrations | **ADAPT AOSP** where Java code is standalone; **HLE REQUIRED** for service-backed calls | Package record, sandbox filesystem, preferences and supported service registry replace Binder calls | Public declared service surface has contract tests; unknown services fail with Android-compatible behavior, not fabricated values |
| AssetManager and resource tables | `frameworks/base/libs/androidfw` | KitKat commonSources plus C adapter | **KEEP** native core; replace fixed guest handle layer | Guest/JNI object wrappers and lifecycle integrate with reference tables | Asset modes, configurations, resource selection, stream lifecycle and concurrent access tests pass |
| Bitmap and image decode | KitKat Skia plus `core/jni/android/graphics` | AOSP PNG subset; path-token Bitmap HLE | **KEEP** codec; **ADAPT AOSP** Bitmap/BitmapFactory JNI semantics | Pixel storage stays native; Java object/reference lifetime follows DEX/GC; GPU upload is separate | PNG plus declared codecs, density/stride/config/recycle/inBitmap behavior pass reference cases |
| NativeActivity and lifecycle | `frameworks/base/core/java/android/app/NativeActivity.java`, `frameworks/base/core/jni/android_app_NativeActivity.cpp`, `frameworks/native/libs/android` | Host calls fixed callbacks in fixed order | **ADAPT AOSP**; **REMOVE** fixed Kung Foo path | UIKit events feed an Android lifecycle state machine; surface/input handles are runtime objects | Lifecycle/order/save-state/window/input-queue tests pass under repeated foreground/background cycles |
| Looper and input | `system/core/libutils/Looper.cpp`, `frameworks/native/libs/android/{looper,input}.cpp`, input headers | Fixed queues and event structs | **ADAPT AOSP** | Darwin wait source plus runtime wake fd; UIKit events translate once into Android event objects | Poll timeout/callback/fd semantics, MotionEvent multi-touch/history and KeyEvent tests pass |
| Storage and preferences | Framework file APIs and `SharedPreferencesImpl` observable behavior | No general implementation | **ADAPT AOSP** Java behavior; **HLE REQUIRED** for filesystem boundary | iOS Application Support/Documents/cache directories mapped to Android app paths; atomic file writes use Darwin | Persistence, atomic commit/apply, restart and quota/error tests pass |
| EGL/GLES and ANativeWindow | API19 EGL/GLES headers/wrappers, `frameworks/native/opengl`, `ANativeWindow` contracts | ANGLE/Metal works; guest bridge is a call subset | **KEEP** ANGLE backend; **ADAPT AOSP** wrappers; **HLE REQUIRED** for window/surface producer | ANativeWindow buffer/surface maps to an ANGLE Metal surface; SurfaceFlinger is excluded | Exported declared EGL/GLES1/2 surface works from generated API coverage tests; proc-address and context-loss tests pass |
| GLES3 | API19 GLES3 public surface | No guest bridge | **ADAPT AOSP** only for the declared API19 range | Same ANGLE adapter | API19 GLES3 conformance subset passes before capability is advertised |
| SoundPool/AudioTrack | `frameworks/av/media/libmedia`, Java/JNI media classes | Synthetic IDs | **ADAPT AOSP** object/state model; **HLE REQUIRED** below AudioTrack because AudioFlinger/Binder are excluded | PCM queues, mixer timing and callbacks terminate in CoreAudio | Load/play/loop/rate/volume/pause/resume and callback ordering pass differential tests with actual audio output |
| OpenSL ES | `frameworks/wilhelm` | Missing | **ADAPT AOSP** engine/object interfaces; **HLE REQUIRED** for device output | Buffer queue/player output feeds the same CoreAudio mixer | NDK OpenSL object, buffer-queue, callback and lifecycle contracts pass |
| General APK launcher | Android manifest/activity/native-library startup semantics | Hard-coded Kung Foo filenames, class, package, load address and callback order | **REMOVE** sample path; build after dependent layers close | iOS document picker supplies APK only | Given an APK, launcher derives package, ABI, DEX, libraries and entry activity and starts it without source changes or package-specific branches |

## Implementation ownership, scope and dependencies

| Work package | Primary code scope | Depends on | Exit artifact |
|---|---|---|---|
| Host boundary | `Runtime/HostServices`, thin Objective-C iOS adapters | UIKit/Metal/CoreAudio/Darwin only | raw services with no Android constants or policy |
| Guest process substrate | `Runtime/Process` VMA, fd namespace, thread records, wait/wake, sandbox roots | Host boundary | 32-bit process contracts; no game or Bionic symbol dispatcher |
| Bionic syscall adapters | imported `ThirdParty/AOSP/bionic` subset plus `Runtime/BionicAdapters` | process substrate | API19 errno/flag/path/time/mmap/futex contracts |
| Bionic libc/libm/stdio/allocator | reviewed AOSP sources and guest ABI wrappers | syscall adapters, VMA, fd, clocks | selected upstream tests and differential corpus |
| Linker/libdl | reviewed AOSP linker/libdl sources plus guest-memory adapter | VMA, fd, libc, ARM interpreter | ARM ELF/relocation/scope/init/fini/dlopen parity suite |
| Thread/TLS/signals | AOSP Bionic pthread/TLS/signal algorithms plus Darwin wait/thread adapter | atomics, clocks, VMA stacks | real multithread, TLS destructor, fault and timeout suites |
| C++/EHABI | API19 NDK compiler runtimes in guest ARM domain | linker, VMA, thread state, interpreter | cross-DSO throw/catch/rethrow/destructor tests |
| Dalvik semantic core | reviewed Dalvik `vm/{oo,alloc,interp}` algorithms integrated into Dex runtime | allocator, threads, clocks | opcode/class/exception/GC differential suite |
| JNI/JavaVM | Dalvik `IndirectRefTable`, `ReferenceTable`, `Jni`, `Native`, `Thread` algorithms | Dalvik object/GC/thread core, ARM bridge | reference/native-binding/attach stress suite without fixed handles |
| Framework game surface | AOSP Java/native components plus declared HLE service registry | DEX/JNI, androidfw, process paths/loopers | generated capability table and API19 contracts |
| Graphics/audio | AOSP guest-visible wrappers/object models; ANGLE/Metal and CoreAudio endpoints | Framework lifecycle/window/input, threads | advertised API surface generated only from passing tests |
| Package launcher | androidfw/manifest/package records and ABI/DEX selector | all prior declared capabilities | package-derived single-process launch with explicit unsupported reports |

## Dependency-ordered execution

1. **Phase 1 — host shell and minimum game-process substrate.** Freeze the
   UIKit shell; add raw Darwin services and only the VMA, fd namespace, clocks,
   sandbox roots, thread and wait/wake primitives required by named Bionic
   consumers. Start the first Bionic mmap/fd/time/pthread consumer as soon as
   its primitive contract passes; do not build an independent mini-Linux.
2. **Phase 2 — native Android userspace.** Import a reviewed Bionic subset and
   linker source, replace their Linux syscall/futex boundary, then add the
   ARMv7 C++/EHABI runtime. Retire NativeCore symbol shims only after parity.
3. **Phase 3 — host DEX runtime with Dalvik semantics.** Bring in Dalvik indirect
   reference, JNI lifecycle, resolution, exception and GC algorithms. Remove
   fixed handles and method-name dispatch after differential tests.
4. **Phase 4 — game-visible Framework.** Build package metadata, Context,
   Resources, Bitmap, NativeActivity, Looper, input, storage and preferences on
   the closed lower layers.
5. **Phase 5 — graphics and audio.** Complete the declared EGL/GLES surface over
   ANGLE/Metal and audio object models over CoreAudio.
6. **Phase 6 — package-derived launcher.** Delete sample-specific startup and
   launch from manifest/package metadata.

## Test gates

Each module exits its phase only after four gates: API19/AOSP contracts,
identical-case Android 4.4 differential output, stress/lifecycle tests, and a
synthetic cross-module integration. Real games run after those gates and report
integration omissions; they do not define the implementation.

No module is complete merely because a visible frame exists. No unsupported
method returns a success placeholder. Capability advertisement is generated
from the tested public surface.
