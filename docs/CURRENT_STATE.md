# AGR Current State

Updated: 2026-09-24

## Identity

Working branch and HEAD are resolved from Git at execution time:

```text
git branch --show-current
git rev-parse HEAD
```

Active phase branch and target are defined by `ci/governance/state.json`.

Phase base: `recovery/phase3-dalvik-semantics` @ `a8ff40ef9debfaa132861bc0655bb72871157ded`

Formal `main` baseline remains `3e3db84a53ad0957e9217f804b6f718a942b9a11`. This document does not reopen that baseline.

## Current phase

Phase 3, Dalvik semantics. Subphases 3A0, 3A, 3B, 3C, and 3D are CLOSED. Phase 3 as a whole is not CLOSED. Lifecycle of the active target: `IMPLEMENTED`.

## CLOSED modules

| Module | Closure commit | Tree |
|---|---|---|
| Dalvik Boot ClassPath / ClassLoader (Phase 3A0) | `ccccca77b9a1dd11880907ef1fb3da3f83e739ab` | `5392048daa8d5b96995406b51610afa17decc7da` |
| Dalvik JNI references and exceptions (Phase 3A and 3B) | `a2e07eb37f645f39c9a968b78808e88cdc25c6e3` | `d9544ad8bff3eabc145ab40a7002b7753f136935` |
| Dalvik exceptions and native binding (Phase 3C) | `d8fdb0c55a8bcfe8f1f1074caebe37510199408d` | `e56edae4f32437df030bfe57433bcc655557c355` |
| Dalvik GC roots and object lifetime (Phase 3D) | `fcf78ce222055e4b36ad77b8d9456a184422d67c` | `4f63f6d649e27a4110efc82d0eea6008e015d3af` |

Earlier merged Runtime contracts (linker, pthread, EHABI, allocator, APK bootstrap, NativeActivity/input, Activity lifecycle, ViewRoot attach, first traversal) stay CLOSED. Their commits and gates are in `docs/MODULE_STATUS.md`. Prior traversal, Surface, Intent, and physical-first-frame narrative is in `docs/history/PRE_REFERENCE_RECOVERY_STATE.md` and is not a current task.

## Active target

Phase 3 Dalvik semantics closure, specifically the Phase 3 final gate.

## Current blocker

The Phase 3 final-gate host contract passes: JNI Call variants invoke the selected method, and static field getters read the static slot. A zero return with no pending exception is a real result. A call or field access that does not run leaves a pending exception. `API19_REFERENCE_DIFFERENTIAL` has not been executed. Phase 3 is not CLOSED.

## Next architecture milestone

Finish the Phase 3 final gate, then close Phase 3. Context reset is finished. The engineering plan is `docs/AGR_REFERENCE_MIGRATION_PLAN.zh-CN.md`. It does not start until Phase 3 is CLOSED.

Phase 3 final gate → Phase 3 CLOSED → R0 Reference Lab → R1 Game Dependency Mapper → R2 Migration Book → R3 API19 Source Closure → R4 Cluster Source Port → R5 CLEAN differential → R6 corpus union

Reference Lab is not started. No Android-visible API, module, class, or symbol is pre-declared as a migration target.
