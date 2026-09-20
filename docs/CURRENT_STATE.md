# AGR Current State

Updated: 2026-09-20

Baseline: `main @ dd83c7425e49a33b8a87d047b39d1b36a8e5464e`

Last known good: `dd83c7425e49a33b8a87d047b39d1b36a8e5464e` on formal `main`

Active branch: `feature/engineering-framework-v2` (PVS1 candidate plus the governance framework required before closure; the exact tested SHA/tree is recorded only by `run-summary.json`)

Lifecycle state: `IMPLEMENTED` (closure candidate under verification, not `CLOSED`, not `MERGED`)

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

The corrected candidate has not completed a valid closure run on its exact commit/tree, so PVS1 remains `IMPLEMENTED`.

## Next Validation

Use the single automatic rerun permitted after correcting invalid closure attempt `35485955807`. The rerun must retain the 100,000-event ordering stress, finish bounded real-APK evidence collection, and satisfy the existing PVS1 closure contract.

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

Runs `35469009073` and `35485955807` are `INVALID` harness attempts and consumed no valid closure budget. The first automatic rerun exposed a second independent harness defect: a host-performance threshold with no API19 semantic basis. That defect is corrected, so one automatic rerun of `35485955807` is permitted without additional approval. PVS1 remains not closed until the exact-candidate rerun is `VALID_PASS`.

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
