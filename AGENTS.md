# AGR Agent Execution Rules

## Highest Goal

Make original target Android APK, DEX, and ARMv7 binaries actually run and remain playable on iOS.

## Formal Terms

- **ACTIVE TARGET**: the user objective currently being advanced.
- **DISCOVERY**: evidence gathering that locates the Android path and the first proven semantic difference. It may retain several active explanations.
- **OBSERVED DISCONTINUITY**: measured behavior only, without an inferred cause.
- **SOURCE PATH**: the pinned API19/AOSP call path that owns the observable contract and its AGR counterpart.
- **ACTIVE EXPLANATIONS**: remaining causal candidates after source inspection; use them only when source evidence does not decide the issue.
- **FIRST PROVEN SEMANTIC DIFFERENCE**: the earliest evidenced difference that can change guest-visible behavior or a required internal invariant. It is not the first log line, code difference, or exception string.
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
4. matching entry in `docs/UPSTREAM_MAP.md` and `ci/governance/upstream-map.json`
5. pinned Android 4.4.4/API19 source when the map is insufficient
6. AGR source implementing the same observable contract

Read `docs/ARCHITECTURE.md` when ownership, execution placement, or a locked boundary is involved. Read `docs/DECISIONS.md` when an existing decision may be changed or reopened. Do not scan unrelated repository areas by default.

## Core Rules

- No per-game behavior in Runtime code.
- Test harnesses may identify a game, replay a game-specific trajectory, and assert its observable results.
- Do not boot or recreate a complete Android OS/userspace.
- Android 4.4.4/API19 is the behavior oracle. Its internal mechanism may be replaced when guest-visible semantics and required invariants remain equivalent.
- Original ARMv7 native code and GCC exception runtime execute as GUEST-ARM.
- DEX remains host-side.
- The formal linker is the sole ELF owner.
- UIKit is a host endpoint, not an Android policy owner.
- Real games discover public-environment defects and confirm final behavior. Focused contracts isolate the defect.
- Do not infer a cause from the last marker or first error line.
- Nonblocking technical debt is not current work.

## Default Discovery Workflow

`observe -> map Android subsystem -> inspect upstream map -> read API19 source -> extract semantics/invariants -> map AGR path -> semantic differential -> first proven semantic difference -> discriminating experiment if needed -> focused validation -> public fix -> contract -> real APK confirmation`

Source inspection precedes open-ended hypotheses whenever Android has an authoritative counterpart. Compare return/error behavior, callback ordering, ownership, blocking and wake behavior, lifecycle, object lifetime, state mutation, memory visibility, and resource visibility. Source-code shape alone is not evidence of a semantic defect.

Every compatibility diagnosis records one classification: `ANDROID_SEMANTIC_BUG`, `HOST_ADAPTATION_BUG`, `AGR_INTERNAL_BUG`, `HARNESS_BUG`, `REFERENCE_MISMATCH`, or `UNKNOWN`.

Use `ci/semantic-diff.py` and `artifacts/schema/semantic-diff.schema.json`. When source evidence leaves multiple causal explanations, record one discriminating experiment. Do not manufacture a hypothesis tree when the first relevant semantic difference is already sufficient.

## Stable Module Rule

During Discovery, stable modules may be read, traced, instrumented, or temporarily altered for a marked counterfactual experiment without formal reopen. Experiments may cross adjacent modules but may not change locked ownership or architecture. They are not production fixes and cannot enter closure evidence.

When evidence selects a stable module for the permanent public fix, record its `stable_modules_touched` entry and reopen reason before Closure. Closure rejects unexplained stable-module changes and any remaining experimental or behavior-changing diagnostic code.

## Diagnostics and Experiments

Passive diagnostics must use bounded memory, never wait, never call guest code, never alter scheduling, and never change Android-visible behavior.

Discovery may use intrusive diagnostics or temporary counterfactual behavior when source and passive runtime evidence cannot discriminate the remaining explanations. Mark it `EXPERIMENTAL`, record its result in `semantic-diff.json`, and remove it before Closure. Diagnostic cut points are test interfaces, never production compatibility shortcuts.

Differential trace events use: `global_seq`, `monotonic_time`, `host_thread`, `guest_thread`, `guest_pc`, `boundary`, `operation`, `object`, `input_state`, `output_state`, `result`, `frame`, and `swap`.

Store both `normalized_signature` for clustering and `raw_fingerprint` for identity.

## Test Scheduling

Use the least expensive sufficient layer:

`static -> host unit -> API19 differential/contract -> ARM synthetic -> Simulator integration -> real APK -> iphoneos -> physical device`

Independent tests continue after independent failures. A hard prerequisite failure blocks or skips dependants. A build failure must not launch a Simulator target. Every executable test has a hard timeout, independent result, and failure signature.

## CI Budget

Per active task: local/static/unit/focused checks are reasonably unlimited; one complete valid discovery macOS run and one complete valid closure macOS run are budgeted; iphoneos may run in parallel. A run counts only when required jobs execute on a functioning runner and required evidence uploads. Runner outages, GitHub failures, and artifact failures do not consume budget.

After two valid full runs without enough evidence, stop and report the minimum missing evidence.

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
