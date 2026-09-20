# AGR Current State

Updated: 2026-09-20

Baseline: `main @ 09d6953e3e2f2bf6ca63565e5458a71815d298e7`

Last known good: `09d6953e3e2f2bf6ca63565e5458a71815d298e7` on formal `main`

Active branch: `feature/evidence-classifier-v2.1` (PVS1 closure-tested tree merged; evidence-classifier governance correction in progress)

Lifecycle state: `MERGED` (`PVS1` closure-tested tree is on main)

## Active Target

Playable Vertical Slice 1 (PVS1): generic APK-derived launch through NativeActivity, window, input, guest progression, bounded stable interaction, and clean teardown.

## Observed Discontinuity

Closure run `35485955807` passed every PVS1 requirement and completed all 100,000 InputQueue lifecycles in order, but the regression harness failed because shared-runner elapsed time was 32.468 seconds instead of an arbitrary 10-second threshold. iphoneos passed on the same commit.

## Mapped Android Subsystem

The previously observed Runtime crash mapped to Dalvik GC roots and NativeActivity lifecycle ownership. The current discontinuity maps to the Simulator InputQueue contract harness and is not an Android Runtime subsystem failure.

## Upstream Source Path

For the repaired Runtime defect: `frameworks/base/core/java/android/app/NativeActivity.java` keeps the launched Activity in the managed lifecycle, and `dalvik/vm/alloc/MarkSweep.cpp` marks process roots before reclaiming objects.

For the current harness discontinuity there is no Android upstream performance path. API19 owns InputQueue ordering and lifecycle behavior, while shared-host elapsed time is not guest-visible compatibility semantics.

## AGR Source Path

Runtime path: `Runtime/DexLoom/game_dex_runner.c -> DxVM.activity_instance -> Dalvik root traversal -> original DEX loadImage`.

Harness path: `agr_guest_run_core_contracts -> input_elapsed_ms -> fixed 10000 ms pass/fail threshold`.

## Earliest Evidenced Divergence

The Runtime divergence was that `create_game` retained the Activity only in a host pointer while `DxVM.activity_instance` remained unset, allowing a major GC to reclaim it. Semantic class: `SEMANTIC_INVARIANT`. Causal status and evidence level: `REAL_GAME_CONFIRMED`. It is fixed and covered by `activity_gc_root_contract`.

The current harness divergence is that a fixed wall-clock threshold was treated as Android compatibility even though ordering, lifecycle completion, guest input consumption, progress, and teardown all passed. Semantic class: `UPSTREAM_IMPLEMENTATION_DETAIL`. Causal status and evidence level: `CONTRACT_CONFIRMED`.

## Remaining Uncertainty

No PVS1 closure uncertainty remains. The evidence classifier is being corrected so a passing target cannot retain a normalized failure signature or a process-death class inferred from unrelated system logs.

## Next Validation

Run the focused evidence-classifier governance contracts. A full PVS1 closure rerun is not required because this correction does not change Runtime production behavior.

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

- evidence-classifier governance correction
- focused failure-signature and target-process termination contracts
- establishing the next active target from the latest formal main after this governance correction merges

## Explicitly Not Current Work

- new Dalvik, GC, JNI, Audio, filesystem, clock, signal, GLES, or product features
- new games or wider compatibility sampling
- per-game Runtime behavior
- reopening stable linker, pthread, EHABI, or allocator modules without evidence

## Next Action

Finish the focused evidence-classifier contracts, then create `DEX Parser Compatibility Phase 1` from the latest formal main.

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
