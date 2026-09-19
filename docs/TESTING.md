# AGR Testing and Evidence

## Layers

| Layer | Purpose |
|---|---|
| L0 Static | source, format, schema, provenance, and policy checks |
| L1 Host unit | host-only algorithms and adapters |
| L2 API contract | Android-visible API/ABI behavior |
| L3 ARM guest synthetic | real ARM32 instructions, ABI, DSO, thread, and exception fixtures |
| L4 Simulator integration | exact native Runtime integrated in an iOS Simulator app |
| L5 Real APK regression | original APK/DEX/native binary as an environment probe |
| L6 iphoneos build | arm64 device SDK compile/link and optional signing |
| L7 Physical device | manual/automated device execution and evidence |

Use the lowest sufficient layer first. A failure in an independent test does not cancel other independent tests. A failed hard prerequisite marks dependent tests blocked/skipped.

## Evidence Rules

Every executable test has a hard timeout, its own result artifact, a normalized signature, and a raw fingerprint. Full dumps are retained for the first raw fingerprint; repeats increment occurrence metadata.

Warnings are deltas only when they are new relative to the baseline and originate in AGR-owned code or relevant toolchain output. Persistent upstream AOSP/compiler warnings are not repeatedly reported as new.

Passive diagnostics are always available and bounded. Intrusive diagnostics are explicitly marked and cannot supply closure evidence if they change the behavior under test.

## Source and Runtime Differential

For a compatibility failure, identify the owning Android public path before changing Runtime behavior. Consult `ci/governance/upstream-map.json`; if it is incomplete, inspect the pinned Android 4.4.4/API19 source and extend the map. Extract guest-visible semantics and required invariants, then compare the AGR path in `semantic-diff.json`.

The comparison concerns behavior, not implementation shape. Host mechanisms such as Darwin condition variables, pipes, UIKit, or ANGLE may replace Linux/Android internals when return values, errors, ordering, ownership, wake behavior, lifecycle, object lifetime, and visibility remain equivalent.

Where an Android 4.4 ARM reference can execute the contract, run the same input on the reference and AGR. Canonicalize addresses and host timing while comparing results, errno, callback/event sequence, thread semantics, lifetime, state transitions, duration class, and error behavior.

Differential trace records use `global_seq`, `monotonic_time`, `host_thread`, `guest_thread`, `guest_pc`, `boundary`, `operation`, `object`, `input_state`, `output_state`, `result`, `frame`, and `swap`. Once a segment is equivalent, do not keep investigating its internal implementation.

Test-only cut points are registered in `ci/governance/diagnostic-cutpoints.json`. They may inject or observe at a defined boundary, but may not become a production compatibility path.

## Current Target

The active target contract is machine-readable at `ci/targets/PVS1.json`. CI success and target closure are separate: a workflow may finish green while a target remains active, but closure CI must reject an unmet target requirement.

## Real Games

Runtime code cannot branch on game/package identity. Test harnesses may select a game, trajectory, timing, and expected observable. When a game reveals a public defect, reproduce it as a focused contract before declaring closure.

## Discovery and Closure

A discovery run maximizes evidence and may fail. It may use explicitly marked intrusive diagnostics or counterfactual implementation changes when source evidence cannot choose between active explanations. These experiments must be recorded in the semantic differential and removed before closure.

A closure run executes the exact target contract against the final candidate commit/tree. It rejects active experiments, behavior-changing diagnostics, unexplained stable-module production changes, and semantic differentials that still require an experiment. Infrastructure-invalid runs do not consume the run budget.

Closure evidence must include `tested_commit`, `tested_tree`, `base_commit`, target results, relevant regressions, diagnostics mode, and `eligible_for_merge`.

## Merge Verification

The merge tool verifies candidate HEAD/tree against closure evidence. If `main` advanced since the recorded base, integrate it and rerun affected closure gates. A conflict-free merge may use a cheap post-merge gate only when the merged tree equals the closure-tested tree.
