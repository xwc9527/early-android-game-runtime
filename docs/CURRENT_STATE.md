# AGR Current State

Updated: 2026-09-21

Baseline and last known good: `main @ a5c5958af1a65763808fc2a4de669c4e76694876`.

Active branch: `main`.

Lifecycle: `MERGED/STABLE`.

## Active Target

Migrate the Android 4.4.4 `ActivityThread.handleResumeActivity` semantic cluster from a successfully resumed Activity through Window/decor attachment, `WindowManager.addView`, Activity visibility, and idle-handler scheduling. The cluster ends at the explicit `ViewRoot/Surface` ownership handoff; ViewRoot, Surface and traversal are not claimed by this phase.

## Earliest Evidenced Divergence

Focused Simulator workflow `35528665347` ran the unchanged Frozen Bubble APK and retained its VM for 2000 ms. The exact method and Framework traces ended at `coordinator.performResume.return`; no exception, method, instruction or Framework event followed. Pinned API19 `ActivityThread.handleResumeActivity` instead continues immediately with `Activity.getWindow`, DecorView acquisition, WindowManager attachment, visibility publication and idle-handler scheduling.

Classification: `ANDROID_SEMANTIC_BUG`. Semantic class: `PUBLIC_OBSERVABLE`. Causal status and evidence level: `REAL_GAME_CONFIRMED`.

## Implemented Candidate

The host-side ActivityThread coordinator now owns the continuous Activity/Window state transition. It preserves Window, DecorView, LayoutParams and WindowManager object identity; executes the observable framework calls in API19 order; records attachment/add/visibility/idle state; and stops at `handoff.viewroot_surface`.

Focused Simulator workflow `35529992439` passed on candidate `d0bda55456600a08fca08e1042f8ff4eb5d1b4b5`. The synthetic contract and unchanged Frozen Bubble both reported `window_attached`, `window_added`, `window_visible`, `idle_handler_scheduled`, and `viewroot_handoff`; the exact ordered trace ended at `handoff.viewroot_surface` with no exception or Runtime error. Runtime, governance, and iphoneos workflows on the same commit also passed.

Exact-candidate closure `35530434859` passed as `VALID_PASS` for commit `a5c5958af1a65763808fc2a4de669c4e76694876`, tree `ee8c0889437e79dacf9e8ed068a7d569100189de`. The candidate was fast-forwarded to `main` without tree changes. Post-merge gate `35530860389`, governance, and iphoneos all passed. The next subsystem begins at the recorded `ViewRoot/Surface` ownership handoff.

## Protected Boundaries

- Original APK and DEX remain unchanged.
- This is host-side DEX/Framework HLE; GUEST-ARM native ownership is unchanged.
- Existing linker, pthread, EHABI, allocator, NativeActivity/Input and graphics contracts remain protected.
- No per-game Runtime behavior is permitted; the harness may identify Frozen Bubble and assert its expected observable trace.

## Closure Contract

The closure contract is satisfied and remains protected by the source, focused Simulator, Runtime regression, iphoneos, and post-merge gates above.
