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

## Current Target

The active target contract is machine-readable at `ci/targets/PVS1.json`. CI success and target closure are separate: a workflow may finish green while a target remains active, but closure CI must reject an unmet target requirement.

## Real Games

Runtime code cannot branch on game/package identity. Test harnesses may select a game, trajectory, timing, and expected observable. When a game reveals a public defect, reproduce it as a focused contract before declaring closure.

## Discovery and Closure

A discovery run maximizes evidence and may fail. A closure run executes the exact target contract against the final candidate commit/tree. Infrastructure-invalid runs do not consume the run budget.

Closure evidence must include `tested_commit`, `tested_tree`, `base_commit`, target results, relevant regressions, diagnostics mode, and `eligible_for_merge`.

## Merge Verification

The merge tool verifies candidate HEAD/tree against closure evidence. If `main` advanced since the recorded base, integrate it and rerun affected closure gates. A conflict-free merge may use a cheap post-merge gate only when the merged tree equals the closure-tested tree.
