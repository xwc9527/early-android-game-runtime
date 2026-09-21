# AGR Current State

Updated: 2026-09-21

Baseline and last known good: `main @ 975eed33963118dae1986797125b8c5ac136c834`.

Active branch: `phase/framework-viewroot-attach-1`.

Lifecycle: `IMPLEMENTED`.

## Active Target

Migrate the Android 4.4.4 ViewRoot attach cluster after WindowManager.addView: ViewRoot creation, root/parent assignment, initial traversal scheduling, WindowSession attachment, and attach completion. The phase ends at `handoff.viewroot_traversal`; performTraversals, relayout, Surface and drawing remain downstream.

## Earliest Evidenced Divergence

Focused Simulator workflow `35528665347` ran the unchanged Frozen Bubble APK and retained its VM for 2000 ms. The exact method and Framework traces ended at `coordinator.performResume.return`; no exception, method, instruction or Framework event followed. Pinned API19 `ActivityThread.handleResumeActivity` instead continues immediately with `Activity.getWindow`, DecorView acquisition, WindowManager attachment, visibility publication and idle-handler scheduling.

Classification: `ANDROID_SEMANTIC_BUG`. Semantic class: `PUBLIC_OBSERVABLE`. Causal status and evidence level: `REAL_GAME_CONFIRMED`.

## Implemented Candidate

`agr_viewroot_attach` is the formal API19 host-side ViewRoot owner. It owns a ViewRoot and AttachInfo object, Decor/parent relation, a pending first traversal and an in-process WindowSession attachment before emitting `handoff.viewroot_traversal`. The source map and semantic diff are recorded for `WindowManagerImpl.addView`, `WindowManagerGlobal.addView`, and `ViewRootImpl.setView/requestLayout/scheduleTraversals`.

This candidate is implemented but not closed. Focused contract, unchanged real-APK regression, Simulator, iphoneos and closure evidence are still required.

## Protected Boundaries

- Original APK and DEX remain unchanged.
- This is host-side DEX/Framework HLE; GUEST-ARM native ownership is unchanged.
- Existing linker, pthread, EHABI, allocator, NativeActivity/Input and graphics contracts remain protected.
- No per-game Runtime behavior is permitted; the harness may identify Frozen Bubble and assert its expected observable trace.

## Closure Contract

The candidate remains IMPLEMENTED / UNVERIFIED. Source verification, focused Simulator synthetic and unchanged Frozen Bubble results, protected regressions and iphoneos build are required before exact-commit closure. No Surface, relayout or rendering claim is made.
