# AGR Current State

Updated: 2026-09-20

Baseline: `main @ dd83c7425e49a33b8a87d047b39d1b36a8e5464e`

Last known good: `dd83c7425e49a33b8a87d047b39d1b36a8e5464e` on formal `main`

Active branch: `playable-vertical-slice-1` (the exact tested SHA/tree is recorded only by `run-summary.json`)

Lifecycle state: `IMPLEMENTED` (closure candidate under verification, not `CLOSED`, not `MERGED`)

## Active Target

Playable Vertical Slice 1 (PVS1): generic APK-derived launch through NativeActivity, window, input, guest progression, bounded stable interaction, and clean teardown.

## Primary Blocker

Closure verification of the Activity process-root fix, focused wait/InputQueue contracts, real-APK progression, and clean teardown.

Discovery run `35467254664` classified the former unexplained exit as `HOST_CRASH`. The macOS crash report records `EXC_BAD_ACCESS/SIGSEGV` in `dx_vm_get_field`, reached through `dx_vm_execute_method -> agr_dex_game_invoke_int -> call_address -> guest_thread_execute`. Immediately before the crash, DexLoom completed a major GC and the next original DEX instruction was `iget-object` in `loadImage`.

The earliest causal defect was lifecycle ownership: `create_game` retained the launched Activity in a host pointer, while the minimal NativeActivity constructor was a no-op and never installed it in `DxVM.activity_instance`, the VM process root traversed by GC. The bounded swap wait was only the last harness marker and now has an independent timing contract.

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

Run the single closure Simulator workflow and iphoneos build against one exact candidate commit/tree. PVS1 remains not closed until the resulting evidence proves all closure requirements.

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
