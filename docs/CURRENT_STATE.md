# AGR Current State

Updated: 2026-09-20

Baseline: `main @ 09d6953e3e2f2bf6ca63565e5458a71815d298e7`

Last known good: `09d6953e3e2f2bf6ca63565e5458a71815d298e7` on formal `main`

Active branch: `phase/framework-activity-launch-1`

Lifecycle state: `IMPLEMENTED`

## Previous Target

DEX Parser Compatibility Phase 1 is `VERIFIED` at `a37432310af6b304402e546377b4cc3a02a9d081` by focused run `35500912993`. Pixel Dungeon parsed 877 classes and 6112 methods; Frozen Bubble parsed 23 classes and 333 methods. Both unchanged APKs reached `dex_loaded`, and both exposed the next common boundary `missing_framework:activity_launch`. No production parser change was required; the defect was the generic harness conflating parse success with a later project-only class binding.

## Active Target

Framework / Activity Launch Compatibility Phase 1: preserve the API19 observable launch sequence for a single in-process Android application without importing system_server, Binder, WindowManager, or a full ActivityThread implementation.

## Upstream Source Path

Pinned Android 4.4.4_r2 path: `ActivityThread.performLaunchActivity -> Instrumentation.newActivity -> LoadedApk.makeApplication -> Activity.attach -> Instrumentation.callActivityOnCreate -> Activity.performStart -> ActivityThread.handleResumeActivity`.

The source gate pins and hashes `ActivityThread.java`, `Instrumentation.java`, `LoadedApk.java`, `Activity.java`, and `Application.java` and verifies the relevant symbols.

## AGR Source Path

`App/main.m:probeActivityLaunchAPK -> agr_apk_package_open -> agr_dex_game_create_from_apk -> create_game -> agr_dex_game_start_activity -> dx_vm_execute_method`.

The host DEX lifecycle coordinator now resolves the manifest Application and Activity, creates stable base Context and Intent objects, attaches their observable relationships, calls Application.onCreate before Activity.onCreate, then starts and resumes the Activity. Process roots preserve Application, Activity, contexts, and launch Intent across GC.

## Earliest Evidenced Divergence

Before this implementation, the generic probe returned immediately after DEX parsing and reported `missing_framework:activity_launch`; it did not call any Activity launch Runtime path. The pre-existing runner separately constructed only a minimal NativeActivity and omitted manifest Application creation, Context/Intent attachment, start, and resume.

Classification: `ANDROID_SEMANTIC_BUG`. Semantic class: `PUBLIC_OBSERVABLE`. Causal status and evidence level: `CONTRACT_CONFIRMED`.

## Current Blocker

The implementation and deterministic synthetic DEX fixture exist, but the compiled iOS Simulator has not executed them. The next real Framework boundary for Pixel Dungeon and Frozen Bubble is therefore still unknown.

## Next Validation

Run one focused discovery workflow: verify pinned API19 sources, build/parse the synthetic Activity plus Application DEX, execute its lifecycle and GC-root contract in Simulator, then run the same launch coordinator against the unchanged Pixel Dungeon and Frozen Bubble APKs.

## Allowed Work

- Activity/Application class resolution, construction, attachment, lifecycle, and roots
- manifest Application discovery
- focused synthetic and real-APK launch evidence
- the first directly encountered public API19 Framework behavior required to cross this launch boundary

## Explicitly Not Current Work

- full ActivityThread, Binder, system_server, WindowManager, or Android OS emulation
- broad Dalvik, JNI, Framework, Audio, Input, filesystem, clock, signal, GLES, or product expansion
- per-game Runtime behavior
- reopening stable linker, pthread, EHABI, allocator, or NativeActivity/Input semantics without evidence

## Closure Contract

This phase can become `CLOSED` only when one exact commit and tree prove the synthetic Application/Activity launch contract, GC root lifetime, and both unchanged real APKs cross the former `activity_launch` boundary; required regressions and iphoneos build must pass on that same candidate. A green discovery workflow alone is not closure.
