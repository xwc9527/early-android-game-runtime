# AGR Current State

Updated: 2026-09-20

Baseline: `main @ dd83c7425e49a33b8a87d047b39d1b36a8e5464e`

Last known good: `dd83c7425e49a33b8a87d047b39d1b36a8e5464e` on formal `main`

Active branch: `playable-vertical-slice-1` (the exact tested SHA/tree is recorded only by `run-summary.json`)

Lifecycle state: `ACTIVE` (`IMPLEMENTED` input path, not `CLOSED`, not `MERGED`)

## Active Target

Playable Vertical Slice 1 (PVS1): generic APK-derived launch through NativeActivity, window, input, guest progression, bounded stable interaction, and clean teardown.

## Primary Blocker

The Simulator app process exits after the fourth replay event has been consumed and while the harness is inside the second bounded `agr_guest_wait_for_swap` call.

Process termination is the earliest evidenced causal boundary. It is not proof that `agr_guest_wait_for_swap` causes the exit; the process may be terminated asynchronously while that call is active. The latest discovery run proves the process is no longer alive, but its available syslog tail contains no crash or termination reason.

Latest evidence:

- four injected events reached Looper, `AInputQueue_getEvent`, pre-dispatch, guest handler, and `finishEvent(handled=1)`;
- `input_consumed=4`;
- guest worker thread id is 2;
- draw/swap continued through approximately frame 216 / swap 33;
- Runtime failure signature is empty;
- latest progress is `before:replay.4.wait.2.swap.33`;
- timeout capture reports `AGRSimulator pid 27430 is no longer running`;
- the captured syslog tail contains UIKit/Metal activation messages but no crash reason;
- iphoneos arm64 build passed for the preceding Runtime commit.

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

- passive capture of the current Simulator discontinuity
- the first public Runtime or harness defect proven by that evidence
- PVS1 target gate and evidence generation
- directly required NativeActivity/Input/Looper/window teardown semantics

## Explicitly Not Current Work

- new Dalvik, GC, JNI, Audio, filesystem, clock, signal, GLES, or product features
- new games or wider compatibility sampling
- per-game Runtime behavior
- reopening stable linker, pthread, EHABI, or allocator modules without evidence

## Next Action

Capture the Simulator termination status and crash/RunningBoard report for the process that exits after replay event 4. Determine whether the exit is a host crash, watchdog/RunningBoard termination, explicit exit/abort, or external launch replacement. Apply one fix to the proven cause, add a focused contract, and run one closure CI.

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
