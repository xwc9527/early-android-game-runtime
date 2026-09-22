# AGR Module Status

Status controls modification permission, not total completeness. `stable` means the current contract is met and protected; `active` means it belongs to the active target; `experimental` means it has no closure claim.

| Module | Status | Closure commit | Regression gate | Reopen condition |
|---|---|---|---|---|
| Formal linker/libdl | stable | `6ec6673` lineage | API19 linker/libdl contracts and differential | direct mapping, symbol, relocation, or lifecycle regression |
| pthread/TLS/futex | stable | `bionic-thread-migration` closure lineage | Bionic pthread/futex contracts | proven guest-thread semantic failure |
| EHABI/C++ exceptions | stable | `503f88a`/`eb024d4`/`da20772` lineage | EHABI Phase 1/2A/2B differential | guest GCC exception regression |
| API19 allocator | stable | `dd83c742` baseline lineage | allocator contract/stress and API19 differential | heap semantic regression on primary path |
| APK bootstrap | stable | `1111664` | PVS bootstrap gate | manifest, DEX startup, loadLibrary, or binding regression |
| NativeActivity/Window | stable | `09d6953e` | PVS1 target gate | proven lifecycle/window regression |
| Looper/InputQueue | stable | `09d6953e` | PVS1 input contract | proven queue, ownership, or consumption regression |
| Simulator regression harness | stable | `09d6953e` | bounded smoke and evidence gate | proven harness contract defect affecting active evidence |
| DEX Runtime Activity lifecycle | stable | `a5c5958` | Activity/Window source, contract and real-APK gate | proven regression before or within the ViewRoot/Surface handoff |
| Framework ViewRoot attach | stable | `a6256ba4` (post-merge `35598935478`) | focused ViewRoot attach contract and real-APK gate | proven attach-order, parent, traversal-schedule, or session-ownership regression |
| Framework first traversal / root Surface | stable | `3e3db84a` (post-merge `35662355600`) | focused first-traversal contract, protected regressions, iphoneos build, closure `35634763769` | proven measure, relayout, layout, or persistent root-Surface regression |
| Framework traversal dispatch / SurfaceView lifecycle | active | — | host SurfaceHolder lock/post; Bitmap pixel backing + Canvas.drawBitmap; Simulator discovery `35683118511` confirmed surfaceCreated; Linux vtable, Java Thread, canvas lock, and agr-bitmap-draw contracts | a production change to measure, relayout, layout, or root Surface identity follows the first-traversal reopen rule. Virtual dispatch, `Thread.start`, and lockCanvas ownership stay closed. Local unchanged Frozen Bubble produced FIRST_CONTENT_FRAME (PARTIAL) at 320x480. Simulator discovery `35711118165` on `4f229c5` confirms FIRST_CONTENT_FRAME: lock 1, draw_bitmap 2, pixel_change 3450366, post 1, and a changed buffer hash for `background.jpg`. `Character.forDigit` is REAL_GAME_CONFIRMED on the local unchanged APK. Canvas save, clipRect(REPLACE), and restore are REAL_GAME_CONFIRMED on that APK. `java.util.Vector` core (`Vector()`, `size`, `addElement`, `removeElement`, `elementAt`) is REAL_GAME_CONFIRMED on that APK: `GameScreen.paint` reaches `PenguinSprite.paint`. `Activity.requestWindowFeature(FEATURE_NO_TITLE)` is REAL_GAME_CONFIRMED on that APK and was not a proven blocker. `Activity.getIntent()` is REAL_GAME_CONFIRMED on that APK: it returns the Activity `_intent` launch Intent. The first unresolved public invoke directly observed on execution context 0 is now `FrozenBubble.onCreate` `Intent.getExtras`. Execution context 1 recorded zero unresolved invokes during that observation window (`count=0`, `dropped=0`). Visual completeness stays partial. Physical-device runtime confirmation is still the active gate and is not confirmed. The device entry now keeps a durable run file, an append-only trace, and a final summary, with a host watchdog and a fixed crash image for catchable signals. `Intent.getExtras` stays the next execution-context-0 encounter and is not a selected blocker. Screen presentation is not claimed. |
| DEX/Dalvik completeness | experimental | — | focused DEX/JNI contracts | future declared migration target |
| Framework HLE | experimental | — | focused public API contracts | gameplay proves a public missing behavior |
| Audio/OpenSL ES | experimental | — | — | declared gameplay target requires audio |
| Product UI/library | experimental | — | — | product phase begins |

Stable modules are readable and diagnosable. Discovery may trace, instrument, or temporarily experiment on them without a formal reopen. A production change carried into closure requires an evidence-backed reopen reason in machine-readable run metadata. Stable means the current contract is protected, not that the module is complete.
