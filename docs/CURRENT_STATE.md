# AGR Current State

Updated: 2026-09-20

Baseline: `main @ dd83c7425e49a33b8a87d047b39d1b36a8e5464e`

Last known good: `dd83c7425e49a33b8a87d047b39d1b36a8e5464e` on formal `main`

Active branch: `playable-vertical-slice-1` (the exact tested SHA/tree is recorded only by `run-summary.json`)

Lifecycle state: `IMPLEMENTED` (closure candidate under verification, not `CLOSED`, not `MERGED`)

## Active Target

Playable Vertical Slice 1 (PVS1): generic APK-derived launch through NativeActivity, window, input, guest progression, bounded stable interaction, and clean teardown.

## Observed Discontinuity

Closure run `35469009073` terminated `simulator-real-apk` with exit 124 at `180.161s`, while the target app remained alive through the full 150-second observation interval. Independent contracts, Simulator smoke, and iphoneos passed.

## Mapped Android Subsystem

The previously observed Runtime crash mapped to Dalvik GC roots and NativeActivity lifecycle ownership. The current discontinuity maps to the CI regression harness and is not an Android Runtime subsystem failure.

## Upstream Source Path

For the repaired Runtime defect: `frameworks/base/core/java/android/app/NativeActivity.java` keeps the launched Activity in the managed lifecycle, and `dalvik/vm/alloc/MarkSweep.cpp` marks process roots before reclaiming objects.

For the current harness discontinuity there is no Android upstream path; its contract is the test runner's own bounded-time hierarchy.

## AGR Source Path

Runtime path: `Runtime/DexLoom/game_dex_runner.c -> DxVM.activity_instance -> Dalvik root traversal -> original DEX loadImage`.

Harness path: `ci/run-suite.py -> forensic collector 150-second observation -> up to two bounded 60-second evidence queries`.

## First Proven Semantic Difference

The Runtime defect was that `create_game` retained the Activity only in a host pointer while `DxVM.activity_instance` remained unset, allowing a major GC to reclaim it. That defect is fixed and covered by `activity_gc_root_contract`.

The current harness defect was that its 180-second outer timeout was shorter than the collector's declared maximum duration. The timeout hierarchy is corrected in the current candidate.

## Remaining Uncertainty

The corrected candidate has not completed a valid closure run on its exact commit/tree, so PVS1 remains `IMPLEMENTED`.

## Next Validation

Run the exact corrected candidate through one valid closure workflow after the closure budget is explicitly reset. The run must finish its bounded real-APK evidence collection and satisfy the existing PVS1 closure contract.

## Proven Working

- APK-derived package and Activity discovery
- host-side DEX startup
- formal linker native load and `JNI_OnLoad`
- NativeActivity create/start/resume
- window and input queue creation
- `APP_CMD_INIT_WINDOW`
- Looper ownership and polling
- MotionEvent injection, retrieval, pre-dispatch, guest handling, and finish
- nonzero guest thread identities
- continued frame/draw/swap after consumed input

## Excluded Hypotheses

- initial InputQueue routing failure
- missing Looper attachment
- first input not reaching guest code
- coordinates being the reason `input_consumed` remains zero
- Runtime failure being reported before the current discontinuity
- synchronous work in `didFinishLaunching` being the remaining cause
- a live host mutex/wait deadlock at timeout (the process has exited)

## Current Allowed Work

- closure verification of the proven DEX Activity ownership fix
- focused Activity GC-root, bounded swap-wait, and concurrent InputQueue contracts
- PVS1 target gate and evidence generation
- directly required NativeActivity/Input/Looper/window teardown semantics

## Explicitly Not Current Work

- new Dalvik, GC, JNI, Audio, filesystem, clock, signal, GLES, or product features
- new games or wider compatibility sampling
- per-game Runtime behavior
- reopening stable linker, pthread, EHABI, or allocator modules without evidence

## Next Action

The configured closure budget has been consumed by run `35469009073`. PVS1 remains not closed. A further closure run requires an explicit budget reset because the corrected harness changes the candidate tree.

## Closure Contract

PVS1 is CLOSED only when one exact commit and tree prove:

- generic APK bootstrap succeeds;
- NativeActivity starts and receives a window;
- input queue is attached to its owner Looper;
- injected input is delivered to and consumed by guest code;
- guest execution and frame/swap progress after input;
- teardown completes in bounded time;
- no Runtime failure signature exists;
- required stable regressions pass;
- iphoneos arm64 builds from the same candidate tree;
- closure evidence names that exact commit/tree and marks it merge-eligible.

`novel_frame=false` alone is not a failure.
