# AGR Agent Execution Rules

## Highest Goal

Make original target Android APK, DEX, and ARMv7 binaries actually run and remain playable on iOS.

## Formal Terms

- **ACTIVE TARGET**: the user objective currently being advanced.
- **DISCOVERY**: evidence gathering that locates the Android path and the first proven semantic difference. It may retain several active explanations.
- **OBSERVED DISCONTINUITY**: measured behavior only, without an inferred cause.
- **SOURCE PATH**: the pinned API19/AOSP call path that owns the observable contract and its AGR counterpart.
- **ACTIVE EXPLANATIONS**: remaining causal candidates after source inspection; use them only when source evidence does not decide the issue.
- **EARLIEST EVIDENCED DIVERGENCE**: the earliest evidenced difference on the same semantic path. It is an investigation focus, not automatically a defect or root cause.
- **CLOSURE**: removal of experiments followed by contract, regression, exact-identity, and merge-eligibility verification.
- **STABLE**: the module satisfies its current contract. Discovery may inspect, trace, or experiment on it; permanent changes require an evidence-backed reopen. Stable does not mean complete.
- **CLOSED**: one exact commit and tree satisfy the target closure contract with complete closure evidence.
- **MERGE-ELIGIBLE**: the closure-tested HEAD satisfies every pre-merge check.
- **MERGED**: the closure-tested tree is present on `main` and the post-merge gate passed.
- **BASELINE**: the newest commit on formal `main` that passed all required baseline gates.
- **REOPEN**: evidence proves a stable module contains the public semantic defect selected for a production fix.

`IMPLEMENTED`, `CLOSED`, and `MERGED` are distinct. CI green does not imply CLOSED. CLOSED does not imply MERGED.

## Required Read Order

1. `AGENTS.md`
2. `docs/CURRENT_STATE.md`
3. latest `run-summary.json`
4. matching entry in `docs/UPSTREAM_MAP.md` and `ci/governance/upstream-map.json`, when VALID
5. pinned Android 4.4.4/API19 source whenever the map is absent, stale, insufficient, or worth bypassing
6. AGR source implementing the same observable contract

Read `docs/ARCHITECTURE.md` when ownership, execution placement, or a locked boundary is involved. Read `docs/DECISIONS.md` when an existing decision may be changed or reopened. Do not scan unrelated repository areas by default.

## Core Rules

- No per-game behavior in Runtime code.
- Test harnesses may identify a game, replay a game-specific trajectory, and assert its observable results.
- Do not boot or recreate a complete Android OS/userspace.
- Android 4.4.4/API19 is the behavior oracle. Its internal mechanism may be replaced when guest-visible semantics and required invariants remain equivalent.
- Evidence priority is pinned source, runtime evidence, validated contract, upstream map, then inference. The upstream map is a navigation cache, never an oracle.
- Original ARMv7 native code and GCC exception runtime execute as GUEST-ARM.
- DEX remains host-side.
- The formal linker is the sole ELF owner.
- UIKit is a host endpoint, not an Android policy owner.
- Real games produce dependency evidence and regression evidence. A Runtime gap does not authorize a new Android implementation or HLE.
- Framework migration follows `REFERENCE_MIGRATION_RULES.md`. That file outranks this document for Framework owner selection, source port, and HLE termination.
- Do not infer a cause from the last marker or first error line.
- Nonblocking technical debt is not current work.

## Default Discovery Workflow

`observe -> map Android subsystem -> inspect or bypass upstream map -> read API19 source -> extract semantics/invariants -> map AGR path -> semantic differential -> earliest evidenced divergence -> discriminating experiment if needed -> focused validation -> public fix -> contract -> real APK confirmation`

Source inspection precedes open-ended hypotheses whenever Android has an authoritative counterpart. Compare return/error behavior, callback ordering, ownership, blocking and wake behavior, lifecycle, object lifetime, state mutation, memory visibility, and resource visibility. Source-code shape alone is not evidence of a semantic defect.

Every compatibility diagnosis records one classification: `ANDROID_SEMANTIC_BUG`, `HOST_ADAPTATION_BUG`, `AGR_INTERNAL_BUG`, `HARNESS_BUG`, `REFERENCE_MISMATCH`, or `UNKNOWN`.

Classify each divergence as `PUBLIC_OBSERVABLE`, `SEMANTIC_INVARIANT`, `ARCHITECTURE_INVARIANT`, or `UPSTREAM_IMPLEMENTATION_DETAIL`. Record causal status separately as `OBSERVED`, `PLAUSIBLE`, `COUNTERFACTUAL_SUPPORTED`, `CONTRACT_CONFIRMED`, or `REAL_GAME_CONFIRMED`. Difference does not imply defect or cause.

Use `ci/semantic-diff.py` and `artifacts/schema/semantic-diff.schema.json`. Evidence level is derived from named artifacts; subjective confidence is forbidden. When source evidence leaves multiple causal explanations, record one experiment that distinguishes at least two concrete explanations. Do not manufacture a hypothesis tree when the divergence already explains the behavior.

## Stable Module Rule

During Discovery, stable modules may be read, traced, instrumented, or temporarily altered for a marked counterfactual experiment without formal reopen. Experiments may cross adjacent modules but may not change locked ownership or architecture. They are not production fixes and cannot enter closure evidence.

When evidence selects a stable module for the permanent public fix, record its `stable_modules_touched` entry and reopen reason before Closure. Closure rejects unexplained stable-module changes and any remaining experimental or behavior-changing diagnostic code.

## Diagnostics and Experiments

Passive diagnostics must use bounded memory, never wait, never call guest code, never alter scheduling, and never change Android-visible behavior.

Discovery may use intrusive diagnostics or temporary counterfactual behavior when source and passive runtime evidence cannot discriminate the remaining explanations. Register it in `ci/experiments.json`, enable it through `AGR_EXPERIMENTAL_<NAME>` or a test-only path, record its two-sided expected outcomes, and remove it before Closure. An experimental patch is never promoted directly into the production fix. Diagnostic cut points are test interfaces, never production compatibility shortcuts.

Differential has three levels: source-derived semantic model by default; executable API19 reference only for unresolved observable ambiguity; targeted runtime trace only for race, timing, cross-thread, callback, or lifecycle ordering. Reference traces are on-demand, not default CI.

Trace boundary events such as enqueue, wake, poll, dequeue, callback enter/exit, finish, lifecycle transition, EGL ownership, JNI crossing, and guest/host crossing. Do not trace every helper, allocation, or instruction unless the active question requires it. Use a fixed-capacity ring buffer with fixed-size records; never wait, allocate unbounded memory, call guest code, or change scheduling. Mark potentially perturbing traces `TIMING_SENSITIVE`; they cannot alone establish causality.

Store both `normalized_signature` for clustering and `raw_fingerprint` for identity.

## Test Scheduling

Use the least expensive sufficient layer:

`static -> host unit -> API19 differential/contract -> ARM synthetic -> Simulator integration -> real APK -> iphoneos -> physical device`

Independent tests continue after independent failures. A hard prerequisite failure blocks or skips dependants. A build failure must not launch a Simulator target. Every executable test has a hard timeout, independent result, and failure signature.

## Expensive Run Admission

Discovery has no fixed run count. Before each full macOS/Simulator run, record the question, current uncertainty, outcomes A/B and what each excludes, and why source/local/reference/focused tests are insufficient. “Run again” and “add more logs” are not admissible questions.

After two consecutive expensive runs without a new divergence, causal evidence, eliminated major explanation, smaller subsystem, or reproducible contract, stop expensive runs and change strategy to source audit, minimal reproducer, reference differential, counterfactual experiment, or cut-point test.

Closure candidates retain strict run budgeting. Only a `VALID_PASS` or `VALID_FAIL` attempt consumes budget. A closure attempt is valid only when every required stage had its configured opportunity to reach a terminal result and all required evidence was collected. Harness, runner, collector, artifact, timeout-hierarchy, and workflow defects classify the attempt as `INVALID` and consume no budget. After fixing an `INVALID` attempt, one automatic rerun is permitted without user approval. A second run after `VALID_FAIL` requires explicit approval.

## STOP Rule

Stop only when the required fix would change a locked architecture, execution-placement, ownership, process, or guest-binary boundary and existing requirements do not select one unique solution. Compilation, fixtures, tests, CI wiring, experiments, and local implementation defects are not STOP conditions.

## Branch and Closure Governance

`feature/phase branch -> implementation -> discovery CI -> fix -> closure CI -> closure evidence -> CLOSED -> merge review -> merge main -> post-merge smoke -> baseline update`

Before closure CI, synchronize `CURRENT_STATE`, `MODULE_STATUS`, `DECISIONS`, upstream mappings, semantic differential, and required contracts into the candidate commit. Do not append even documentation-only changes after closure and reuse old evidence.

Closure means the target contract was completely verified for one exact commit and tree. Before merge verify:

- candidate HEAD equals closure `tested_commit`;
- candidate tree equals closure `tested_tree`;
- closure base still matches the integrated base;
- stable-module production changes have valid reopen reasons;
- no unexplained relevant warning or failure exists;
- temporary experiments and unnecessary intrusive diagnostics are absent.

If `main` changed after closure, integrate it and rerun affected closure gates. Prefer fast-forward when strictly ahead; otherwise use an ordinary merge commit. Do not squash by default. A conflict-free merge must satisfy `merged_tree == closure_tested_tree`; otherwise old closure evidence is invalid.

Post-merge runs build sanity, critical contracts, active-module smoke, merged-tree verification, and baseline update. `last_known_good` refers only to formal `main`.

## Completion Output

Report only:

- Changed
- Evidence
- CI
- Current blocker
- State transition

Do not retell project history.
