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
| Runtime traversal dispatch and root draw consumer | `ViewRootImpl.scheduleTraversals/doTraversal/performDraw`, `Choreographer.doFrame/doCallbacks` | `framework_viewroot.c`, `game_dex_runner.c`, `App/main.m` | HOST-DEX_HLE + UIKit vsync | one host frame consumes one posted traversal; the first Surface frame does not draw |
| Window setContentView | `Activity.setContentView(int/View)`, `PhoneWindow.setContentView` | `game_dex_runner.c` | HOST-DEX_HLE | inflate a layout or install one content child; an attached window only schedules |
| SurfaceView child Surface | `SurfaceView.updateWindow`, `SurfaceHolder.Callback` | `game_dex_runner.c`, `framework_viewroot.c` | HOST-DEX_HLE | a visible positive frame creates a distinct child Surface and delivers surfaceCreated then surfaceChanged once |
| SurfaceHolder lockCanvas | `SurfaceView.internalLockCanvas`, `Surface.lockCanvas`, `SurfaceHolder.lockCanvas` | `game_dex_runner.c` `surface_holder_lock_canvas` | HOST-DEX_HLE | a valid holder returns one Canvas bound to the child content buffer; unlock posts that buffer |
| BitmapFactory.decodeResource | `BitmapFactory.decodeResource`, `Bitmap.getWidth`, `Bitmap.getHeight`, `Bitmap.recycle` | `game_dex_runner.c`, `Runtime/Bitmap/agr_bitmap` | HOST-DEX_HLE | a decodable PNG/JPEG/GIF resource returns a Bitmap with host pixel backing; inJustDecodeBounds does not decode pixels |
| Canvas.drawBitmap | `Canvas.drawBitmap(Bitmap,float,float,Paint)`, native `drawBitmap__BitmapFFPaint` | `game_dex_runner.c` `canvas_draw_bitmap`, `agr_bitmap_draw` | HOST-DEX_HLE | null-Paint draw blits source pixels into the locked content Surface with clipping |
| Bitmap.createScaledBitmap | `Bitmap.createScaledBitmap` | `game_dex_runner.c` `bitmap_create_scaled`, `agr_bitmap_scale` | HOST-DEX_HLE | positive destination size returns a new Bitmap with nearest or bilinear pixels; equal size returns the source |
| DEX virtual dispatch | `dalvik vm/oo/Class.cpp` `createVtable` | `dx_vm.c` `dx_class_build_vtable`, `dx_interpreter.c` invoke-virtual | HOST-DEX | superclass slots keep their index; an override replaces that slot; a new virtual method is appended |
| java.lang.Thread.start | `libcore Thread.start` → `VMThread.create` | `dx_exec.c` `native_thread_start` | HOST-DEX | start returns after a joinable host worker begins `run`; a Java Thread context must not alias a guest pthread |
| java.lang.Character.forDigit | `libcore Character.forDigit` | `dx_vm.c` `native_character_fordigit` | HOST-DEX | radix 2..36 and digit in range return a decimal or lowercase digit character; otherwise 0 |
| Java monitor-enter / monitor-exit | Dalvik `vm/Sync.cpp` `dvmLockObject` / `dvmUnlockObject` | `dx_exec.c` `dx_vm_monitor_enter` / `dx_vm_monitor_exit` | HOST-DEX | mutual exclusion and same-context reentry; `Object.wait` / `notify` are not implemented |

Each new public path adds or updates one machine-readable entry. A problem report references the map entry, then supplies a compact `semantic-diff.json`; it does not duplicate the upstream map in prose.

Semantic comparison covers guest-observable behavior and required invariants: return/error behavior, callback and state ordering, ownership, thread affinity, blocking/wakeup, lifetime, and memory visibility. Host mechanisms may differ when these semantics remain equivalent.
