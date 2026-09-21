# Android 4.4.4 to AGR Upstream Map

This is the human-readable index for `ci/governance/upstream-map.json`. It is an encounter-driven navigation index and semantic cache, not an oracle. Pinned Android 4.4.4/API19 source and necessary reference execution remain authoritative; an agent may bypass this map at any time.

Each machine entry records pinned source paths/hashes, AGR paths/hashes, dependencies, verification commit, and `VALID`, `STALE`, `UNVERIFIED`, or `INVALID` status. `ci/upstream-map.py` recomputes AGR hashes. A changed AGR path, baseline revision, dependency, or missing path invalidates cached authority. `STALE` means recheck source; it does not mean the cached statement is false. Normal cache maintenance needs no ADR.

| Subsystem | API19 source path | AGR path | Placement | Contract focus |
|---|---|---|---|---|
| NativeActivity lifecycle | `NativeActivity.java` -> `android_app_NativeActivity.cpp` | `App/main.m` -> `agr_guest_runtime.c` | HOST-HLE + GUEST-ARM callback | ordered lifecycle, window/input ownership |
| native_app_glue | NDK r10e `android_native_app_glue.c` | original guest DSO + pipe/Looper host boundary | GUEST-ARM | command ordering and pre/post state mutation |
| Looper/InputQueue | `frameworks/base/native/android/{looper,input}.cpp`, `system/core/libutils/Looper.cpp` | `agr_guest_runtime.c` | HOST-HLE | enqueue, wake, poll, get, finish, thread owner |
| EGL lifecycle | API19 `eglApi.cpp` | guest EGL imports -> ANGLE | HOST adapter | handle lifetime, current context, swap |
| JNI binding | Dalvik JNI + nativehelper | `agr_jni_methods.c`, `game_dex_runner.c` | cross-domain bridge | method/object lifetime, thread context |
| Assets/resources | androidfw `Asset.cpp`, `AssetManager.cpp`, `ResourceTypes.cpp` | `Runtime/AndroidFw` | HOST-NATIVE AOSP | APK assets and resource selection |
| pthread/TLS | API19 Bionic pthread sources | `Runtime/Bionic`, `GuestThreadContext` | HOST-NATIVE AOSP + Darwin boundary | thread, TLS, errno, futex-visible semantics |
| linker/libdl | API19 `bionic/linker` | `Runtime/AospLinker` | HOST-NATIVE AOSP | DSO ownership, lookup, relocation, lifecycle |
| EHABI | API19 Bionic exidx + NDK r10e libgcc | guest GCC runtime + `Runtime/Ehabi` backtrace support | GUEST-ARM / narrow HOST-HLE | exidx ownership and propagation |
| allocator | API19 Bionic dlmalloc | `Runtime/Bionic/agr_bionic_allocator.cpp`, `agr_api19_dlmalloc_source.inc` | HOST-NATIVE source port | guest chunk layout and malloc-family semantics |
| ViewRoot first traversal and root Surface | `ViewRootImpl.java`, `View.java`, `ViewGroup.java`, `IWindowSession.aidl`, `Surface.java` | `framework_viewroot.c`, `game_dex_runner.c` | HOST-DEX_HLE | attachment, measurement, relayout, frame, Surface lifetime and first-Surface reschedule |

Each new public path adds or updates one machine-readable entry. A problem report references the map entry, then supplies a compact `semantic-diff.json`; it does not duplicate the upstream map in prose.

Semantic comparison covers guest-observable behavior and required invariants: return/error behavior, callback and state ordering, ownership, thread affinity, blocking/wakeup, lifetime, and memory visibility. Host mechanisms may differ when these semantics remain equivalent.
