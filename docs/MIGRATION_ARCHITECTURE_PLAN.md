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

## Module migration decisions

| Environment module | Android 4.4.4 source of truth | Current AGR code | Decision | Host dependency replaced at the boundary | Completion criterion |
|---|---|---|---|---|---|
| iOS shell | `App/main.m` is host code, not AOSP | UIKit app, touch source, diagnostics | **KEEP**, then split sample harness from shell | UIKit window/lifecycle, app sandbox, Metal/CoreAudio handles | Shell starts an empty game process without package-specific names and exposes only host-service interfaces |
| ARMv7 execution | Android ARM EABI plus CPU architecture; touchHLE interpreter is the selected backend | `Runtime/ArmInterpreter` | **KEEP** | No Android policy in the CPU backend; memory faults and SVC/import exits go to the process runtime | A32/Thumb-2/VFP corpus and undefined-instruction reporting pass independently of games |
| Guest address space and VMA | Bionic `libc/bionic/mmap.cpp`, `libc/SYSCALLS.TXT`; Linux `mmap`, `mprotect`, `munmap` contracts | Flat interpreter mapping plus NativeCore heap | **ADAPT AOSP** | Darwin `mmap/mprotect/munmap`; AGR maintains Android 32-bit VMA, page and errno semantics | API 19 mapping/protection differential tests, overlap/split/coalesce tests and long allocation stress pass |
| Files, fd and stdio | Bionic `open.c`, `fcntl.c`, `lseek64.c`, BSD stdio under `libc/stdio` | Callback fragments and virtual pipes | **ADAPT AOSP** | Paths are translated into the iOS container; fd primitives use Darwin descriptors or virtual device endpoints | Identical API19 tests cover open flags, seek, append, EOF, errno, stdio buffering and sandbox path mapping |
| Clock and time | Bionic time wrappers, tzcode and generated syscall stubs | Synthetic 16.7 ms increment | **REPLACE WITH AOSP** | `mach_continuous_time`/`clock_gettime`, wall clock and timezone provider | Monotonic/realtime/CPU clock and timeout behavior match Android 4.4 reference output |
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

## Dependency-ordered execution

1. **Phase 1 — host shell and game-process substrate.** Freeze the UIKit shell;
   add an explicit Darwin host-service ABI; implement guest VMA, fd/path, clock,
   thread and TLS providers. Existing Runtime code is not redirected until the
   new contracts pass.
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
