# AGR Agent Execution Rules

## Highest Goal

Make original target Android APK, DEX, and ARMv7 binaries actually run and remain playable on iOS.

## Formal Terms

- **ACTIVE TARGET**: the one user objective currently being advanced.
- **PRIMARY BLOCKER**: the earliest causal boundary supported by evidence for the active target.
- **OBSERVATION**: a measured anomaly not yet proven to be the blocker.
- **STABLE**: the module satisfies its current contract. It is readable and diagnosable, but is not changed unless a reopen condition is met. Stable does not mean complete.
- **CLOSED**: one exact commit and tree satisfy the target closure contract with complete closure evidence.
- **MERGE-ELIGIBLE**: the closure-tested HEAD satisfies every pre-merge check.
- **MERGED**: the closure-tested tree is present on `main` and the post-merge gate passed.
- **BASELINE**: the newest commit on formal `main` that passed all required baseline gates.
- **REOPEN**: new evidence places a stable module on the primary-blocker path.

`IMPLEMENTED`, `CLOSED`, and `MERGED` are distinct. CI green does not imply CLOSED. CLOSED does not imply MERGED.

## Required Read Order

1. `AGENTS.md`
2. `docs/CURRENT_STATE.md`
3. latest `run-summary.json`
4. source directly relevant to the primary blocker

Read `docs/ARCHITECTURE.md` only if ownership, execution placement, or a locked boundary is involved. Read `docs/DECISIONS.md` only when an existing decision may be changed or reopened. Do not scan the repository by default.

## Core Rules

- No per-game behavior in Runtime code.
- Test harnesses may identify a game, replay a game-specific trajectory, and assert its observable results.
- Do not boot or recreate a complete Android OS/userspace.
- Android 4.4.4/API19 is the source and behavior baseline.
- Original ARMv7 native code and GCC exception runtime execute as GUEST-ARM.
- DEX remains host-side.
- The formal linker is the sole ELF owner.
- UIKit is a host endpoint, not an Android policy owner.
- Real games expose public-environment defects; confirmed defects become focused contracts.
- Work on one primary blocker. Keep other findings as secondary observations.
- Do not infer a cause from the first error line. The first broken boundary is the earliest causal discontinuity demonstrated by evidence.
- Nonblocking technical debt is not current work.

## Stable Module Rule

Stable modules may be read and instrumented with passive diagnostics. They are not proactively refactored. A stable module may be modified only when at least one condition is evidenced:

1. its regression gate fails;
2. the primary blocker directly enters it;
3. an architecture inconsistency is proven;
4. public Android behavior cannot be implemented above it.

Every such change requires a `stable_modules_touched` entry and a reopen reason. Suspicion is insufficient.

## Diagnostics

Passive diagnostics must use bounded memory, never wait, never call guest code, never alter scheduling, and never change Android-visible behavior.

Intrusive diagnostics include extra guest calls, input injection, lifecycle calls, framebuffer readback, EGL mutation, pauses, and timing changes. Use them only when passive evidence cannot distinguish the remaining hypotheses. Record whether diagnostics were passive or intrusive in `run-summary.json`.

Store both:

- `normalized_signature` for clustering;
- `raw_fingerprint` for deciding whether apparently similar failures are actually identical.

## Test Scheduling

Use the least expensive sufficient layer:

`static -> host unit -> API contract -> ARM synthetic -> Simulator integration -> real APK -> iphoneos -> physical device`

Independent tests continue after independent failures. A hard prerequisite failure blocks or skips dependants. A build failure must not launch a Simulator target.

Every executable test has a hard timeout, an independent result, and a failure signature. One game process must not contaminate another.

## CI Budget

Per active task:

- local/static/unit/focused checks: reasonably unlimited;
- one complete valid discovery macOS run;
- one complete valid closure macOS run;
- iphoneos may run in parallel.

A run consumes this budget only when required jobs execute on a functioning runner and required evidence is uploaded. Runner outages, GitHub service failures, artifact failures, and infrastructure crashes do not consume discovery/closure budget.

After two valid full runs without enough evidence, stop and report the single unknown and the minimum new evidence required.

## STOP Rule

Stop only when the required fix would change a locked architecture, execution-placement, ownership, process, or guest-binary boundary and existing requirements do not select one unique solution.

Report the conflicting constraints, their provenance, upstream behavior, current AGR behavior, first broken boundary, available choices, and affected locked boundary. Compilation, fixtures, tests, CI wiring, and local implementation defects are not STOP conditions.

## Branch and Closure Governance

The required lifecycle is:

`feature/phase branch -> implementation -> discovery CI -> fix -> closure CI -> closure evidence -> CLOSED -> merge review -> merge main -> post-merge smoke -> baseline update`

Before closure CI, synchronize all required changes to `CURRENT_STATE`, `MODULE_STATUS`, and `DECISIONS` into the candidate commit. Do not append a documentation-only commit after closure and reuse old evidence.

Closure means the target contract was completely verified for one exact commit and tree. It does not mean all Runtime modules are complete and does not prevent a later evidence-based reopen.

Before merge verify:

- candidate HEAD equals closure `tested_commit`;
- candidate tree equals closure `tested_tree`;
- closure base still matches the integrated base;
- stable-module changes have valid reopen reasons;
- no unexplained new relevant warning or failure exists;
- all required state documents were part of the tested tree;
- temporary or intrusive diagnostics did not enter Runtime production code.

If `main` changed after closure, integrate the new base and rerun affected closure gates. Rebase invalidates evidence for the old commit.

Prefer fast-forward when the branch is strictly ahead. Otherwise use an ordinary merge commit. Do not squash by default. For a conflict-free merge, `merged_tree == closure_tested_tree`; otherwise closure evidence does not cover the merged result.

Post-merge runs only build sanity, critical contracts, the active-module smoke, merged-tree verification, and baseline update. `last_known_good` refers only to formal `main`.

## Completion Output

Report only:

- Changed
- Evidence
- CI
- Current blocker
- State transition

Do not retell project history.
