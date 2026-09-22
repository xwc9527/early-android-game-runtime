# AGR Current State

Updated: 2026-09-22

Active target: Android Framework Runtime Traversal Dispatch / Surface Draw Consumer Phase 1. Lifecycle: `IMPLEMENTED`. Integration base: `main @ 6e47ce9ab6da32483f049731ac04f2a8356a4b67`. Formal Runtime baseline and last known good remain `3e3db84a53ad0957e9217f804b6f718a942b9a11` / tree `1af351ebd1987d1d19b8bee83f9a7a8aa5071ffa`.

Normal Activity start still returns at `handoff.viewroot_traversal` with the traversal scheduled and `traversal_count` 0. API19 `ViewRootImpl.scheduleTraversals` posts `Choreographer.CALLBACK_TRAVERSAL` and does not call `doTraversal`. `doCallbacks` extracts due callbacks before running them, so a Surface-acquisition reschedule waits for the next frame. AGR's public consumer is one host frame: `agr_dex_game_choreographer_frame` calls `agr_viewroot_choreographer_frame` once. The first frame may acquire the Surface and reschedule; the second frame keeps that Surface and enters `performDraw`. `start_activity` does not call `do_traversal`. The closed explicit first traversal still ends at `handoff.viewroot_surface_ready` with `draw_count` 0.

Discovery run `35666933096` launched unchanged Frozen Bubble with UIKit `CADisplayLink` and no harness `do_traversal`. The report is `viewroot_draw_entered`: vsync 2, traversal counts 0 then 1 then 2, Surface generation 1, `draw_count` 1. The job then failed in the contract checker because NSJSON encoded the synthetic `passed` flag as `1`. That is a harness defect. `performDraw` of the host Decor is not a first frame. Discovery run `35668200026` reached the same draw entry, but `FrozenBubble.onCreate` calls `setContentView(int)` and the int overload was bound to `setContentView(View, LayoutParams)`, so no content child was installed. `Activity.setContentView(int)` now inflates the layout resource. Discovery run `35670955623` on `9508063` confirms the normal UIKit path: resume has `content_view_installed`, `content_child_count` 1, child id `0x7f060000`, layout -1,-1, `traversal_count` 0 and still scheduled; two host frames then reach `viewroot_draw_entered` with traversal counts 1 then 2, Surface generation 1, `draw_count` 1, and `harness_called_do_traversal` false. That draw is the host Decor. It is not an observable first frame. The protected explicit first traversal in the same run still ends at `handoff.viewroot_surface_ready` with `draw_count` 0. The SurfaceView contract now creates a distinct child Surface on the draw-pass pre-draw hook. The Linux host contract passes registration, one surfaceCreated, one surfaceChanged, identity, generation, hidden and zero-size rejection, removed callbacks, and allocation failure. A local host probe of unchanged Frozen Bubble registers GameView as the callback during onCreate. Frame 1 does not create the child Surface. Frame 2 reports generation 1, 320x480, format 4, created_count 1, changed_count 1, and an identity distinct from the root Surface. Discovery run `35683118511` on `68ed706` confirms the same UIKit path at 1206x2622: frame 1 created_count 0, frame 2 created_count 1 and changed_count 1, content identity distinct from the root Surface, classification `viewroot_draw_entered`, and `harness_called_do_traversal` false. The next stop is `GameThread.scaleFrom` with `NullPointerException`. That is not a first frame. `BitmapFactory.decodeResource(Resources, int, Options)` returns a Bitmap whose size comes from the APK PNG, JPEG, or GIF. It stores the resource path and encoded dimensions, not a pixel buffer. The `scaleFrom` null field was `GameThread.cleanUp`, reached because `GameView.<init>` pc 35 invoke-virtual method_idx 252 resolved `java.lang.Thread.start` at local vtable index 0 and `GameThread.vtable[0]` was `cleanUp`. pc 30 method_idx 247 `setRunning` already selected `GameThread.setRunning`. Framework and guest classes now share one flattened vtable: `Thread.start` is slot 10 and the same slot on `GameThread` is `java.lang.Thread.start`. The following local probe enters `Thread.start`, which runs `GameThread.run` on the caller until the shared 500000-instruction budget stops `onCreate`. That is the next runtime boundary. `java.lang.Thread` is a DEX execution context and is not a guest pthread; one guest pthread remains one Darwin pthread. Surface destruction and lockCanvas are outside this contract. This is not a first frame.

## Merged First Traversal baseline

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

## Closure Contract

Exact-commit closure and corrected post-merge validation are complete. ViewRoot attach is MERGED/STABLE for this contract. No Surface, relayout or rendering claim is made.
