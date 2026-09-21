# AGR Current State

Updated: 2026-09-21

Runtime baseline and last known good: `main @ a6256ba4e4f0d8124bc5a2348039b882f2c91dc8`. The governance-only follow-up `beff6b2232c5473bc09fc2145abefda30c117b91` passed post-merge gate `35598935478`.

Active branch: `main`; next phase branches from this formal main.

Lifecycle: `MERGED/STABLE`. ViewRoot closure-tested commit `a6256ba4e4f0d8124bc5a2348039b882f2c91dc8` / tree `9d0dedc1b6bcd92ad40a595b386ce798d5da3025`; exact-target post-merge run `35598935478` passed on governance-only follow-up `beff6b2232c5473bc09fc2145abefda30c117b91`.

## Active Target

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

## Closure Contract

Exact-commit closure and corrected post-merge validation are complete. ViewRoot attach is MERGED/STABLE for this contract. No Surface, relayout or rendering claim is made.
