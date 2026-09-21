# AGR Architecture Falsification Report

Purpose: actively look for evidence strong enough to stop or narrow AGR before further
Framework, Graphics, Audio and Input investment. This is not a Runtime migration phase and it
makes no closure claim.

## Verdict

| Hypothesis | Result |
|---|---|
| H1 — single-process compatibility boundary holds | `PASS` |
| H2 — the public compatibility layer converges | `PASS` |
| PROJECT | `CONTINUE` |

`D001` reopen triggered: **no**.

Machine-readable result: `build/artifacts/architecture-falsification.json`.

## Exact tested identity

| Run | Purpose | Tested commit | Tested tree |
|---|---|---|---|
| `35654415068` | Discovery frontier batch (10 games) | `7790fa47c0ac2b7fc92aec9b718ad41be2f6556e` | `e19033e5822a0ecfd9178b2f7892047e1f0ba118` |
| `35656209596` | Blind Holdout batch (5 games) | `79313186846f722cad695c7bdd63f5e0928ede00` | `2aa5d208e72b7aadaa668917172a45d6d4563a6c` |

Baseline at start: formal `main @ 5a6962d2c84b06425e8c489e855d71529f50ba3b`, working tree clean,
previous ViewRoot phase `MERGED` with post-merge run `35598935478` passed.

Expensive run budget: 3 allowed, 2 used, both `VALID`. No harness, runner, collector or
workflow defect occurred; both runs produced every planned sample result.

**No production Runtime behavior was changed at any point in this experiment.** Every Runtime
module remains exactly as it was at the baseline, so the Holdout is a blind test of the existing
public layer rather than of a fix round.

## Phase A — 32-APK architecture census

`build/artifacts/architecture-census.json`, `build/artifacts/api-surface-union.json`.

The locked F-Droid sample set was expanded from 5 to 32 API19-era games, all hash-verified
against the F-Droid index and recorded in `Tests/Samples/fdroid.lock.json` with package,
versionCode, versionName, SHA-256, license, source and repository. No APK enters Git.

Execution clusters (13 in scope):

| Cluster | Samples |
|---|---|
| libgdx | flickit, geometri-destroyer, glxy, kids-memory, vector-pinball |
| custom-jni-canvas | crosswords, droidfish, hyperroid, prboom, sgt-puzzles |
| custom-jni-gl | clash-of-balls, gloomy-dungeons-1, gloomy-dungeons-2, liquid-wars |
| pure-java-canvas | andors-trail, blockinger, frozen-bubble, gravity-defied |
| pure-java-gl | pixel-dungeon, replica-island, shattered-pixel |
| godot | minilens, tanks-of-freedom |
| pure-java-webview | a2048, sudoku-free |
| soupeaucaillou | heriswap, recursive-runner |
| custom-nativeactivity | kungfoo-barracuda |
| irrlicht-nativeactivity | minetest |
| qt | qt-minesweeper |
| python-sdl | pysolfc |
| sdl | meritous |

Scope classification: 26 `IN_SCOPE`, 4 `IN_SCOPE_WITH_OPTIONAL_EXTERNAL_FEATURES`,
2 `OUT_OF_SCOPE_EXTERNAL_DEPENDENCY`, 0 `NEEDS_DYNAMIC_CLASSIFICATION`. Every classification
records its basis in the union artifact.

### Third-party SDK separation

The census found essentially no advertising, analytics, payment or Play Services reference
surface, because F-Droid builds strip them: zero samples reference those packages externally,
and only `gloomy-dungeons-1` bundles a legacy analytics receiver. SDK noise therefore cannot
explain the convergence result in either direction. The one caveat is that Framework references
made *from* bundled non-Android libraries (for example the HoloEverywhere UI compatibility layer
in `gloomy-dungeons-2`) are attributed to the app, since per-reference call-graph attribution was
not built.

### Static convergence

Contract granularity is frozen in `tools/contract_families.py` (87 families, fingerprint recorded
in every artifact that reports a number). Over the in-scope census order:

| Series | C_first (first 5) | C_last (last 5) | Union |
|---|---|---|---|
| core contract families | 9.60 | 0.00 | 54 |
| all contract families | 14.00 | 0.00 | 85 |
| raw core Android classes | 65.60 | 2.40 | 455 |
| raw core Android methods | 410.60 | 31.60 | 3173 |

`STATIC_NON_CONVERGENCE_WARNING` was **not** raised. Static surface is discovery data only: it
shows which paths exist in a binary, never which paths core gameplay executes.

## Phase B — API19 system boundary analysis

`build/artifacts/system-boundary-map.json` (experiment artifact, not a new governance map).

87 boundaries recorded, 38 of them high-risk with full fields: public API, pinned API19 source
path, caller process, original remote service, Binder or local, observable input/output/callback/
state/thread affinity/lifetime/blocking behavior, reducibility with reason, referencing games and
clusters, evidence and status.

Result: 75 `REDUCIBLE_HLE`, 12 `OPTIONAL_EXTERNAL`, 0 `IRREDUCIBLE_SYSTEM_DEPENDENCY`,
0 `UNRESOLVED`.

All twelve `OPTIONAL_EXTERNAL` boundaries (notifications, alarms, app widgets, live wallpaper,
backup, print, telephony, connectivity, wifi, camera, accessibility, search) are optional
capability, not gameplay. Where the reduction genuinely fails — posting a notification into
SystemUI, rendering RemoteViews inside the launcher, waking a dead process from AlarmManager —
the capability is by definition not part of playing a local single-player game.

Two load-bearing reducibility judgments were checked against pinned 4.4.4_r2 source rather than
asserted:

- `system.wakelock`: `PowerManager.java` shows the entire guest-visible contract is
  `mRefCounted`/`mCount` gating in `acquireLocked`/`release`, `mHandler.postDelayed(mReleaser,
  timeout)` for the timed form, `isHeld()` returning `mHeld`, and
  `RuntimeException("WakeLock under-locked <tag>")` when the count goes negative. That is finite
  local state plus one host idle-timer setting.
- `audio.soundpool`: `SoundPool.java` defines the observable contract as sound/stream ids,
  priority-then-age voice stealing at `maxStreams`, `play()` returning 0 when the new sound
  loses, tolerated calls on stale stream ids, rate range 0.5–2.0 and loop counting. Decode via
  the media service and output via AudioFlinger are placements, not observables. The earlier
  draft claim of "in-process mixing" was wrong and was corrected against the source.

## Phase C — pre-registered high-risk samples

Frozen in `build/artifacts/preregistered-samples.json` before any dynamic run: qt-minesweeper,
minetest, tanks-of-freedom, pysolfc, meritous, heriswap, flickit, gloomy-dungeons-2, crosswords,
kungfoo-barracuda, replica-island, a2048 — twelve samples spanning twelve clusters, each with a
recorded objective risk basis.

Because Phase B resolved every high-risk boundary from pinned source with no `UNRESOLVED`
remaining, the executable API19 reference layer was not needed. Under the project's own evidence
ordering, running it anyway would have been an unjustified expensive step.

## Phase D — Discovery

Selection and order are produced by a mechanical rule, not a hand-picked list: the first ten
in-scope clusters alphabetically, taking the alphabetically first sample in each. Frozen before
the first run.

Run `35654415068`, all 10 samples completed:

| # | Sample | Cluster | Last stage | Classification | Blocking contract |
|---|---|---|---|---|---|
| 0 | crosswords | custom-jni-canvas | none | KNOWN_PUBLIC_CONTRACT | app.activity_lifecycle |
| 1 | gloomy-dungeons-1 | custom-jni-gl | on_create_entered | NEW_PUBLIC_CONTRACT | audio.soundpool |
| 2 | kungfoo-barracuda | custom-nativeactivity | resumed | KNOWN_PUBLIC_CONTRACT | — |
| 3 | minilens | godot | resumed | KNOWN_PUBLIC_CONTRACT | — |
| 4 | minetest | irrlicht-nativeactivity | resumed | KNOWN_PUBLIC_CONTRACT | — |
| 5 | flickit | libgdx | context_attached | RUNTIME_INTERNAL_GAP | — |
| 6 | andors-trail | pure-java-canvas | on_create_entered | KNOWN_PUBLIC_CONTRACT | app.context |
| 7 | pixel-dungeon | pure-java-gl | on_create_entered | KNOWN_PUBLIC_CONTRACT | app.context |
| 8 | a2048 | pure-java-webview | resumed | KNOWN_PUBLIC_CONTRACT | — |
| 9 | pysolfc | python-sdl | resumed | KNOWN_PUBLIC_CONTRACT | — |

Five games — a NativeActivity C++ engine, Godot 2, Irrlicht, python-for-android/SDL2 and a
WebView game — reach `activity_resumed` through the full ViewRoot attach handoff on the unchanged
Runtime. The five that stop, stop on:

- `Context.getPackageName()` returning null (pixel-dungeon) and `Context.getResources()` returning
  null (andors-trail) — the same `app.context` family, two unrelated clusters.
- Platform `Activity` subclass resolution (crosswords: `GamesList -> XWListActivity ->
  android.app.ListActivity`, verified from `classes.dex`) — a gap inside the implemented
  `app.activity_lifecycle` contract, shared by every app using `ListActivity`,
  `ExpandableListActivity`, `TabActivity` or `PreferenceActivity`.
- `SoundPool.load` (gloomy-dungeons-1) — the one genuinely new public contract family.
- An AGR host DEX type-system `ClassCastException` while constructing a generic array inside
  libGDX (flickit) — not an Android contract at all.

`GAME_SPECIFIC` requirements: **0**. `UNRESOLVED`: **0**.

Metrics over the frozen order, counting the API19 contract families each game actually executed:
`C_first = 1.8`, `C_last = 0.2`, ratio `0.111`, threshold `<= 0.50` met.

### Attribution method and its one correction

Blocking contracts are attributed from the executed API19 method trace, not from error text. The
first classifier version read only error strings and produced five `UNRESOLVED`; the trace is
strictly better evidence and was always the intent of "contracts actually exposed". The contract
granularity table was **not** changed and its fingerprint is identical across every artifact.

Three attributions the mechanical rule cannot make are recorded explicitly with their evidence in
`tools/classify_frontier.py` (crosswords' superclass chain; flickit and geometri-destroyer's
identical generic-array cast failure; qt-minesweeper's `java.lang.Class` reflection stop).

### No fix round was run

The plan allowed a public-fix round followed by a second Discovery run. It was not executed: with
three expensive runs budgeted and the Holdout requiring one, and with the experiment explicitly
forbidden from becoming a Runtime development project, the remaining run was spent on the blind
Holdout. This makes the Holdout harder rather than easier, because nothing was fixed in response
to Discovery and nothing could be overfitted to it.

## Holdout — blind

Frozen with Discovery, run only after Discovery was complete, against a Runtime that had not
changed. Run `35656209596`, all 5 samples completed:

| Sample | Cluster | Last stage | Classification | Blocking contract |
|---|---|---|---|---|
| qt-minesweeper | qt | on_create_entered | RUNTIME_INTERNAL_GAP | — |
| meritous | sdl | resumed | KNOWN_PUBLIC_CONTRACT | — |
| heriswap | soupeaucaillou | on_create_entered | KNOWN_PUBLIC_CONTRACT | app.activity_lifecycle |
| geometri-destroyer | libgdx | context_attached | RUNTIME_INTERNAL_GAP | — |
| droidfish | custom-jni-canvas | on_create_entered | KNOWN_PUBLIC_CONTRACT | app.activity_lifecycle |

`holdout_reuse_ratio = 1.00` (threshold `>= 0.70`). `GAME_SPECIFIC`: **0**. No Holdout game
required a new public contract family, and none required game identity, game-specific state,
game-specific return values or a game-specific callback order.

Three previously unexercised clusters (Qt, SDL, SoupeAuCaillou) produced no new public contract
family. `geometri-destroyer` reproduced `flickit`'s exact stopping frame, which is direct evidence
that a single shared defect — not two per-game problems — explains both.

## Anti-manipulation checks

- **Ordering.** `build/artifacts/order-sensitivity.json`: the registered order gives `0.111`, the
  reversed order gives `0.429`, and `95.5%` of 20,000 random permutations meet the `<= 0.50`
  threshold with a median of `0.111`. The convergence is a property of the sample set, not of the
  frozen order.
- **Granularity.** One family table, frozen before the first dynamic run, identical fingerprint in
  the census, union, boundary map, pre-registration and both classifications. No family was split,
  merged or added after data was seen.
- **SDK noise.** Near-zero ad/analytics/payment surface across the census, so the result is not
  produced by discarding third-party references.

## Limitations

- **First-blocker censoring.** One run of a game exposes only its current frontmost blocker. Fixing
  `Context.getPackageName` would reveal whatever pixel-dungeon needs next. H2 `PASS` therefore
  means: *at the compatibility frontier currently reached, and on the statically visible surface,
  the public layer shows clear reuse and marginal convergence with no game-specific production
  requirement.* It does **not** mean that complete gameplay paths have been proven to converge.
- **Holdout denominator.** Only three of the five Holdout games reached a public-contract
  boundary; the other two stopped on AGR-internal defects. A reuse ratio of 1.00 over three games
  is a weak denominator, even though it is unambiguous.
- **Trace truncation.** The method trace is a 64-entry ring, so per-sample executed-family sets are
  a lower bound. This can only understate the surface each game touches.
- **heriswap attribution.** Its stop is attributed to `app.activity_lifecycle` by the mechanical
  last-executed-API19-method rule; the precise null-returning accessor was not isolated in this run.
- **No frame or gameplay claim.** Reaching `activity_resumed` is a launch and window-attach result.
  No sample was shown to render gameplay or accept input in this experiment.

## Consequences for the next Runtime work

These are findings, not decisions, and none of them was implemented here.

1. `app.context` completion (`getPackageName`, `getResources`) blocks two games in two unrelated
   clusters and is the cheapest cross-cluster unblock.
2. Platform `Activity` subclass resolution (`ListActivity` and siblings) is a small, clearly public
   extension of an already stable contract.
3. The host DEX type system's handling of generic array casts blocks two libGDX games identically,
   and `java.lang.Class` reflection blocks Qt. Both are core-library completeness gaps in the
   host DEX runtime rather than Framework work.
4. `audio.soundpool` is the first genuinely new public Framework contract the frontier demands.

Exclusion list, with objective reasons, stays as recorded in the census: `prboom`
(core content downloaded from a retired host) and `clash-of-balls` (multiplayer-only over
AllJoyn, no single-player mode in the DEX). Neither is an Android cross-process semantic
dependency, so neither bears on H1.

## Baseline Compensation Validation — post First-Traversal formal main

This section is appended, not a rewrite. Everything above describes
**Architecture Falsification — baseline `5a6962d2`** and is preserved unmodified.

### Why a compensation run was requested

The dynamic Discovery and Holdout runs above executed against formal
`main @ 5a6962d2c84b06425e8c489e855d71529f50ba3b`. The
`First Traversal / Relayout / Surface Acquisition Phase 1` work was not in that baseline, so the
observed frontier could have been shallower than the Runtime's real reach. The compensation task
is to re-measure H2 on a newer formal baseline that includes First Traversal, with the frozen
sample sets, frozen granularity fingerprint and frozen thresholds, so that a deeper frontier is
allowed to overturn the earlier `PASS`.

### Status: `BLOCKED_PRECONDITION` — not run

Machine-readable: `build/artifacts/architecture-falsification-compensation.json`.

First Traversal has **not** entered the formal baseline. Verified against the live remote:

| Check | Required | Observed |
|---|---|---|
| Phase merged into formal `main` | yes | `3e3db84a` is **not** an ancestor of `main` |
| Closure ledger state | `MERGED` | `IMPLEMENTED`, `closure_tested_commit: null`, `eligible_for_merge: false` |
| Closure attempts used | ≥ 1 `VALID_PASS` | `0`, `last_closure_attempt: "none for current target"` |
| Post-merge gate passed for the phase | yes | newest `main` gate is `35599543077` at `5a6962d2`, the ViewRoot lineage |
| Baseline promoted | to the merged phase commit | governance baseline on `main` is still `a6256ba4` |
| Formal `main` advanced | beyond `5a6962d2` | still exactly `5a6962d2` |

`phase/framework-first-traversal-surface-1` carries six unmerged commits and only *discovery* CI
runs (latest `35634763769`, success). Its own `docs/CURRENT_STATE.md` states
`Lifecycle: IMPLEMENTED / UNVERIFIED; no closure or merge claim applies to this branch`, and
records that protected regressions and the iphoneos build have not yet been verified for the
candidate.

The compensation task's own precondition rule requires stopping in exactly this situation, so the
single permitted expensive macOS run was **not** spent. Running it now would have re-measured the
identical `5a6962d2` Runtime and produced the original numbers again while consuming the budget.

Note on the request's premise: First Traversal has not merely failed to merge, it has not yet had
a closure attempt at all. The next step is its closure CI, not a merge.

### Prepared so the compensation run is a single action

No production Runtime code was touched. The following is measurement plumbing only, verified
locally without any macOS run:

- `falsification-compensation` sample profile: the exact union of the frozen Discovery 10 and
  Holdout 5, ordered Discovery-first in the frozen Discovery order, so all 15 samples are probed
  in one compile, one ANGLE preparation, one Simulator boot and one Runtime binary.
- The workflow classifies a combined result file against each frozen set separately, emitting
  both `frontier-classification-discovery.json` and `frontier-classification-holdout.json`.
- Verified by replaying the two previous run results as one combined file: the split reproduces
  both committed classifications bit-for-bit, including `C_first 1.8 / C_last 0.2` and
  `holdout_reuse_ratio 1.00`.
- `tools/baseline_compensation.py` performs the precondition check, the old/new per-game frontier
  comparison and the frozen-threshold H2 restatement, and refuses to emit a verdict while the
  precondition is unmet.

Once First Traversal is `CLOSED`, merged, post-merge green and baseline-promoted, the compensation
run is triggered by setting `ci/falsification-run-request.json` to
`sample_set: "falsification-compensation"` with an incremented `request_id`.

### What this section does and does not claim

It does not revalidate H2 on a deeper frontier, and it does not weaken the original result. The
original verdicts stand as measured on `5a6962d2`, with the first-blocker censoring limit already
stated above. Whether the convergence survives the deeper First Traversal frontier is still an
open question, and this task deliberately left the expensive run unspent rather than answer it
with the wrong Runtime.

## Final answer

On a heterogeneous set of 32 real API19-era games spanning 13 execution clusters, no gameplay-
critical Android behavior was found that requires a second process, a remote Binder object
identity, remote death semantics or an external system authority. The pre-registered
`3 games / 2 clusters` irreducibility threshold was not approached: the count is zero. At the
reachable frontier, unrelated engines fail on the same small set of shared API19 contracts, a
blind holdout across three previously unexercised clusters introduced no new public contract and
no game-specific requirement, and no per-game Runtime behavior was needed or added.

The current architecture — original APK/DEX/ARMv7 binaries plus an API19 public environment inside
one host process — remains the high-ROI path. Return to normal Runtime migration.
