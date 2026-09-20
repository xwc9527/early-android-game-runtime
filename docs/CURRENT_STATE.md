# AGR Current State

Updated: 2026-09-21

Baseline: `main @ 75fbe9d6dc5ad0e535fcba8e25182927d207bd3e`

Last known good: `75fbe9d6dc5ad0e535fcba8e25182927d207bd3e` on formal `main`

Active branch: `phase/framework-runtime-continuation-1`

Lifecycle state: `ACTIVE` (`Android Framework Continuation Phase 1`)

## Active Target

Continue the unchanged Frozen Bubble VM from the closed `onPostResume` boundary to the first stable guest-visible work or the next independent subsystem handoff. Discovery reuses the existing APK, VM retention, synthetic Activity fixture, method telemetry, focused Simulator workflow, source gate, regression gate and iphoneos gate.

The current primary blocker is an observation, not a root-cause claim: closure run `35521035773` recorded `post_resume_complete_no_followup_event`. The active discovery adds a bounded passive ring of actual method entries and Framework coordinator events so one focused workflow can establish the earliest causal divergence.

## Previous Target

Framework / Activity Launch Compatibility Phase 1 is `MERGED/STABLE`. Its exact closure commit was `59d5dce5397c924e0625a73abd34901afd5e2742`; post-merge gate `35516313459` passed and promotion commit `03e104282debde07d331a6e7791a1ab89b18cb09` is the formal baseline.

## Active Target

Complete the Android 4.4.4 `Activity.performResume` sequence through the original APK Activity's `onPostResume`, without expanding into the subsequent event/callback boundary.

## Upstream Source Path

Pinned `Android 4.4.4_r2` `core/java/android/app/Activity.java`, SHA-256 `03874ea13f230ff2b92bc6d99522011f63a3076e9101655aa0249addc590cc4b`:

`Activity.performResume -> Instrumentation.callActivityOnResume -> Activity.onPostResume`.

## AGR Source Path

`App/main.m:runFrozenBubblePostResumeDiscovery -> agr_apk_package_open -> agr_dex_game_create_from_apk -> agr_dex_game_start_activity -> dx_vm_execute_method`.

## Earliest Evidenced Divergence

Focused workflow `35519334286` retained the unchanged Frozen Bubble VM for 2000 ms after `onResume`. Both snapshots reported methods `9`, instructions `45`, stack depth `0`, no exception, and last method `Landroid/app/Activity;->onResumeV`. AGR had returned from its launch coordinator where API19 proceeds to `onPostResume`.

Classification: `ANDROID_SEMANTIC_BUG`. Semantic class: `PUBLIC_OBSERVABLE`. Causal status and evidence level: `REAL_GAME_CONFIRMED`.

## Current Evidence

Commit `6ea0baba717a73b4f6f3c2ca8e50ef1a07d40c5d` restores virtual `onPostResume` dispatch. Focused run `35520119540` passed the pinned source gate and Simulator probe. Its synthetic contract observed marker `2` and `post_resume_completed`; Frozen Bubble's last successful method became `Landroid/app/Activity;->onPostResumeV`, with no exception.

The same artifact records the next independent boundary as `post_resume_complete_no_followup_event`: no method or instruction was scheduled during the following bounded interval. This phase does not implement that next boundary.

Exact-candidate automatic discovery runs also passed Runtime (`35520119547`) and iphoneos (`35520119504`). These are discovery evidence; closure must rerun all required gates on the final candidate commit/tree.

## Next Validation

Run the phase closure workflow on one exact candidate containing source mapping, semantic differential, state, contracts, Runtime regressions, and iphoneos build. Closure success may move the branch to `READY_TO_MERGE`; merge approval remains separate.

## Allowed Work

- API19 `Activity.performResume/onPostResume` callback order and failure propagation
- bounded passive method/instruction/lifecycle evidence
- exact-candidate contract, Runtime regression, iphoneos, and closure evidence

## Explicitly Not Current Work

- selecting or implementing the next post-resume event, callback, Looper, View, Surface, rendering, input, audio, or thread boundary
- per-game Runtime behavior
- reopening linker, pthread, EHABI, allocator, NativeActivity/Input, or broader DEX/Framework behavior without new evidence

## Closure Contract

One exact commit/tree must prove the pinned API19 ordering, a synthetic overriding `onPostResume` marker, unchanged Frozen Bubble reaching the callback without Runtime error, the new next boundary recorded, stable Runtime/real-game regressions, and iphoneos build. Green discovery CI alone does not close the target.
