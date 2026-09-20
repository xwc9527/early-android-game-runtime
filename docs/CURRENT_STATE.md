# AGR Current State

Updated: 2026-09-21

Baseline and last known good: `main @ 75fbe9d6dc5ad0e535fcba8e25182927d207bd3e`.

Active branch: `phase/framework-runtime-continuation-1`.

Lifecycle: `IMPLEMENTED`, pending focused Simulator validation.

## Active Target

Migrate the Android 4.4.4 `ActivityThread.handleResumeActivity` semantic cluster from a successfully resumed Activity through Window/decor attachment, `WindowManager.addView`, Activity visibility, and idle-handler scheduling. The cluster ends at the explicit `ViewRoot/Surface` ownership handoff; ViewRoot, Surface and traversal are not claimed by this phase.

## Earliest Evidenced Divergence

Focused Simulator workflow `35528665347` ran the unchanged Frozen Bubble APK and retained its VM for 2000 ms. The exact method and Framework traces ended at `coordinator.performResume.return`; no exception, method, instruction or Framework event followed. Pinned API19 `ActivityThread.handleResumeActivity` instead continues immediately with `Activity.getWindow`, DecorView acquisition, WindowManager attachment, visibility publication and idle-handler scheduling.

Classification: `ANDROID_SEMANTIC_BUG`. Semantic class: `PUBLIC_OBSERVABLE`. Causal status and evidence level: `REAL_GAME_CONFIRMED`.

## Implemented Candidate

The host-side ActivityThread coordinator now owns the continuous Activity/Window state transition. It preserves Window, DecorView, LayoutParams and WindowManager object identity; executes the observable framework calls in API19 order; records attachment/add/visibility/idle state; and stops at `handoff.viewroot_surface`.

The synthetic Activity contract and unchanged Frozen Bubble probe require the complete ordered cluster. A focused Simulator run is the next validation. Exact-candidate Runtime regressions, iphoneos build and closure evidence follow only after focused evidence passes.

## Protected Boundaries

- Original APK and DEX remain unchanged.
- This is host-side DEX/Framework HLE; GUEST-ARM native ownership is unchanged.
- Existing linker, pthread, EHABI, allocator, NativeActivity/Input and graphics contracts remain protected.
- No per-game Runtime behavior is permitted; the harness may identify Frozen Bubble and assert its expected observable trace.

## Closure Contract

One exact commit/tree must prove the pinned API19 ordering, complete synthetic and unchanged-real-APK Window cluster, terminal `handoff.viewroot_surface`, no Runtime exception, required regressions, and iphoneos build. A green discovery run alone does not close the target.
