# AGR Module Status

Status controls modification permission. `stable` and `CLOSED` mean the current contract is protected. A real game that reaches a missing API does not reopen a module and does not authorize an Android implementation or HLE.

| Module | Status | Owner | Closure commit / evidence | Regression gate | Reopen condition |
|---|---|---|---|---|---|
| Formal linker/libdl | stable | HOST-NATIVE AOSP | `6ec6673` lineage | API19 linker/libdl contracts and differential | direct mapping, symbol, relocation, or lifecycle regression |
| pthread/TLS/futex | stable | HOST-NATIVE AOSP | `bionic-thread-migration` closure lineage | Bionic pthread/futex contracts | proven guest-thread semantic failure |
| EHABI/C++ exceptions | stable | GUEST-ARM | `503f88a` / `eb024d4` / `da20772` lineage | EHABI Phase 1/2A/2B differential | guest GCC exception regression |
| API19 allocator | stable | HOST-NATIVE AOSP | `dd83c742` baseline lineage | allocator contract/stress and API19 differential | heap semantic regression on the primary path |
| APK bootstrap | stable | HOST-NATIVE AOSP | `1111664` | PVS bootstrap gate | manifest, DEX startup, loadLibrary, or binding regression |
| NativeActivity/Window | stable | HOST-NATIVE AOSP | `09d6953e` | PVS1 target gate | proven lifecycle or window regression |
| Looper/InputQueue | stable | HOST-NATIVE AOSP | `09d6953e` | PVS1 input contract | proven queue, ownership, or consumption regression |
| Simulator regression harness | stable | test harness | `09d6953e` | bounded smoke and evidence gate | proven harness contract defect affecting active evidence |
| DEX Runtime Activity lifecycle | stable | HOST-DEX | `a5c5958` | Activity/Window source, contract, and real-APK gate | proven regression inside the closed Activity contract |
| Framework ViewRoot attach | stable | HOST-DEX | `a6256ba4` (post-merge `35598935478`) | focused ViewRoot attach contract and real-APK gate | proven attach-order, parent, traversal-schedule, or session-ownership regression |
| Framework first traversal / root Surface | stable | HOST-DEX | `3e3db84a` (post-merge `35662355600`) | focused first-traversal contract, protected regressions, iphoneos build, closure `35634763769` | proven measure, relayout, layout, or persistent root-Surface regression |
| Dalvik Boot ClassPath / ClassLoader | CLOSED | DALVIK_VM | `ccccca77` / tree `5392048daa` | classpath `36019018497`; governance `36019009849`; protected `36019009689` | boot loses to an application class, suffix lookup returns, or eight DEX files is again a load limit |
| Dalvik JNI references, exceptions, native binding, GC roots | CLOSED through Phase 3D | DALVIK_VM | 3A/3B `a2e07eb` / tree `d9544ad8`; 3C `d8fdb0c` / tree `e56edae4`; 3D `fcf78ce` / tree `4f63f6d6` | JNI, classpath, governance, and protected regression on those commits | proven regression of the closed indirect-ref, exception, native-binding, or GC-root contract |
| Phase 3 final gate | CLOSED | DALVIK_VM | `851a025a` / tree `9ece3c2b`; JNI `36039287996` | Tests/DexLoom/jni-call-host.c plus classpath, governance, and protected regression on that commit | Reopen if a JNI Call variant or static field getter returns a default without invoking or reading the slot and without a pending exception |
| Framework | not started | none until a Migration Book names an API19 source owner | — | — | a Cluster Source Manifest exists after API19 Source Closure. A public call missing from a real game is not a reopen |
| Audio/OpenSL ES | not started | none | — | — | the migration sequence reaches an excluded AudioFlinger or device boundary |
| Product UI/library | not started | product | — | — | a product phase is explicitly opened |

`DalvikJNI` in `ci/governance/modules.json` is the machine-registry projection of the existing DALVIK_VM JNI CLOSED surface. It gives stable protection to `Runtime/DexLoom/VM/dx_jni.c` and `Runtime/DexLoom/Include/dx_jni.h`. The CLOSED rows above stay CLOSED. This entry is not a new closure. `ci/governance/reopens.json` reopens `DalvikJNI` for target `Dalvik.JNINativeBinding API19 Repair`. The module status stays `stable`. The reopen does not change `dx_jni.c` or `dx_jni.h` and does not mark that owner `SOURCE_CLOSED`.

`pthread` stays `stable` in `ci/governance/modules.json`. `ci/governance/reopens.json` reopens it for the same target. The ThreadState self-suspend path reaches untimed `pthread_cond_wait`, normal `pthread_mutex_lock` / `pthread_mutex_unlock`, and `pthread_cond_broadcast`. Those operations now follow the pinned `pthread.c` contract: the wait ignores mutex unlock and relock results, a normal lock and unlock run a full barrier, and broadcast's pulse runs that barrier before wake. Absolute condition timed-wait is not on this path and is still absent. `Runtime/Bionic/agr_futex_host.cpp` remains the wait and wake primitive. The ThreadState prerequisite relationship for this exact crossing is `PREREQUISITE_CLOSED`. That closure does not mark `Bionic.PthreadCondition` `PRODUCTION_CLOSED`. Its crossing status and `owner_source_status` stay `SOURCE_CLOSED`.

`NativeCoreRuntime` is an experimental machine owner for `Runtime/NativeCore/agr_runtime.c` only. It is not a semantic owner, a closure, or a reopen. On Apple, `agr_dispatch_system("clock_gettime")` routes Android clock ids 0 and 1 to `Runtime/Bionic/agr_bionic_clock.c`. That port maps them to the existing `AGR_HOST_CLOCK_REALTIME` and `AGR_HOST_CLOCK_MONOTONIC` primitives and stores a failure through the existing Bionic errno path. Other clock ids, and every clock id on non-Apple builds, still use the pre-reference synthetic `16666667` ns counter. `gettimeofday` is unchanged. This is not `PRODUCTION_CLOSED`.

Stable modules may be read during Discovery. A production change carried into closure still needs an evidence-backed reopen in `ci/governance/reopens.json`. Historical Frozen Bubble, traversal, physical-first-frame, and DEX-parser reopen records are in `ci/governance/history/reopens-pre-reference.json` and are not reopen authority.

Framework implementation follows `REFERENCE_MIGRATION_RULES.md`.
