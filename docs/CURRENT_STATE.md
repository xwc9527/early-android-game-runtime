# AGR Current State

Updated: 2026-09-22

Formal baseline and last known good: `main @ 3e3db84a53ad0957e9217f804b6f718a942b9a11` / tree `1af351ebd1987d1d19b8bee83f9a7a8aa5071ffa`. First Traversal is `MERGED`. Closure run `35634763769` is `VALID_PASS`: linux-source-contract, focused Simulator, protected Runtime contracts, bounded Simulator smoke, protected Runtime and real-game regressions, and the arm64 iphoneos build all passed. Post-merge run `35662355600` passed on governance-only follow-up `79d47bc6578a36c7af6a10d5b5ec03122fdbd1da`.

The candidate commit's ledger still said `IMPLEMENTED` with `closure_tested_commit = null` because that commit is the exact tested tree. The closure artifact was produced after it. That ledger is not evidence that closure did not occur.

The prior `handoff.viewroot_traversal` is now consumed by a host-side API19 ViewRoot first traversal. Focused Simulator run `35631242737` executed a synthetic Activity and the unchanged Frozen Bubble APK through attachment, root measurement, WindowSession relayout, persistent Surface acquisition and layout. The synthetic contract also observed first-Surface rescheduling, the second traversal retaining the same backing identity, relayout rejection, Surface allocation failure and retry. The current terminal is `handoff.viewroot_surface_ready`; draw/Canvas/GLSurfaceView and gameplay remain outside this phase.

The authoritative source path is pinned `android-4.4.4_r2` `ViewRootImpl.doTraversal/performTraversals`, `View.measure/layout`, `IWindowSession.relayout`, and `Surface` validity. UIKit supplies display dimensions; the in-process WindowSession HLE owns Android frame/Surface policy. The source map and semantic differential for this phase are under `ci/governance`.

## Previous closed ViewRoot attach baseline

Prior ViewRoot attach lifecycle: `MERGED/STABLE`. Its closure-tested commit `a6256ba4e4f0d8124bc5a2348039b882f2c91dc8` / tree `9d0dedc1b6bcd92ad40a595b386ce798d5da3025` passed exact-target post-merge run `35598935478`.

## Previous target

Migrate the Android 4.4.4 ViewRoot attach cluster after WindowManager.addView: ViewRoot creation, root/parent assignment, initial traversal scheduling, WindowSession attachment, and attach completion. The phase ends at `handoff.viewroot_traversal`; performTraversals, relayout, Surface and drawing remain downstream.

## Earliest Evidenced Divergence

Focused Simulator workflow `35528665347` ran the unchanged Frozen Bubble APK and retained its VM for 2000 ms. The exact method and Framework traces ended at `coordinator.performResume.return`; no exception, method, instruction or Framework event followed. Pinned API19 `ActivityThread.handleResumeActivity` instead continues immediately with `Activity.getWindow`, DecorView acquisition, WindowManager attachment, visibility publication and idle-handler scheduling.

Classification: `ANDROID_SEMANTIC_BUG`. Semantic class: `PUBLIC_OBSERVABLE`. Causal status and evidence level: `REAL_GAME_CONFIRMED`.

## Implemented Candidate

`agr_viewroot_attach` is the formal API19 host-side ViewRoot owner. It owns a ViewRoot and AttachInfo object, Decor/parent relation, a pending first traversal and an in-process WindowSession attachment before emitting `handoff.viewroot_traversal`. The source map and semantic diff are recorded for `WindowManagerImpl.addView`, `WindowManagerGlobal.addView`, and `ViewRootImpl.setView/requestLayout/scheduleTraversals`.

The exact candidate passed focused contract, unchanged real-APK regression, Simulator, iphoneos and closure run `35595440089` as `VALID_PASS`. Post-merge run `35596315143` selected unrelated historical PVS1 evidence and remains INVALID. Corrected run `35598935478` bound the ViewRoot closure to the exact merged tree and passed identity, governance, JNI and focused ViewRoot gates.

## Protected Boundaries

- Original APK and DEX remain unchanged.
- This is host-side DEX/Framework HLE; GUEST-ARM native ownership is unchanged.
- Existing linker, pthread, EHABI, allocator, NativeActivity/Input and graphics contracts remain protected.
- No per-game Runtime behavior is permitted; the harness may identify Frozen Bubble and assert its expected observable trace.

## Architecture Falsification Gate

The falsification experiment on `phase/architecture-falsification-1` returned `H1 = PASS`,
`H2 = PASS`, `PROJECT = CONTINUE`; `D001` was not reopened. Evidence is
`docs/ARCHITECTURE_FALSIFICATION_REPORT.md` and `build/artifacts/architecture-falsification.json`,
from discovery run `35654415068` and blind holdout run `35656209596`. No production Runtime
behavior was changed by the experiment. Its meaning is bounded by first-blocker censoring: it
describes the compatibility frontier currently reached, not complete gameplay paths.

First Traversal is `MERGED` on formal `main`. Closure run `35634763769` is `VALID_PASS` for
commit `3e3db84a53ad0957e9217f804b6f718a942b9a11` / tree
`1af351ebd1987d1d19b8bee83f9a7a8aa5071ffa`. Post-merge run `35662355600` passed. The governance
baseline commit is that tested commit. Compensation run `35662803136` remeasured the frozen 15
APKs on that Runtime: `H1 = PASS`, `H2 = PASS` (`C_first 1.8`, `C_last 0.2`, holdout reuse
`3/3`), `GAME_SPECIFIC = 0`, `PROJECT = CONTINUE`. Last stage, blocker, and executed families
were unchanged; no sample completed a root Surface.

## Closure Contract

Exact-commit closure and corrected post-merge validation are complete. ViewRoot attach is MERGED/STABLE for this contract. No Surface, relayout or rendering claim is made.
