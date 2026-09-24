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

Phase 3, Dalvik semantics, is CLOSED. Subphases 3A0, 3A, 3B, 3C, 3D, and the final JNI gate are CLOSED. Lifecycle of the active target: `CLOSED`.

## CLOSED modules

| Module | Closure commit | Tree |
|---|---|---|
| Dalvik Boot ClassPath / ClassLoader (Phase 3A0) | `ccccca77b9a1dd11880907ef1fb3da3f83e739ab` | `5392048daa8d5b96995406b51610afa17decc7da` |
| Dalvik JNI references and exceptions (Phase 3A and 3B) | `a2e07eb37f645f39c9a968b78808e88cdc25c6e3` | `d9544ad8bff3eabc145ab40a7002b7753f136935` |
| Dalvik exceptions and native binding (Phase 3C) | `d8fdb0c55a8bcfe8f1f1074caebe37510199408d` | `e56edae4f32437df030bfe57433bcc655557c355` |
| Dalvik GC roots and object lifetime (Phase 3D) | `fcf78ce222055e4b36ad77b8d9456a184422d67c` | `4f63f6d649e27a4110efc82d0eea6008e015d3af` |
| Phase 3 final JNI gate | `851a025a14a75429c975da43853269f9d98ed8ef` | `9ece3c2b0f1bea5d8275bde75f13d91b5b3e63d6` |

Earlier merged Runtime contracts (linker, pthread, EHABI, allocator, APK bootstrap, NativeActivity/input, Activity lifecycle, ViewRoot attach, first traversal) stay CLOSED. Their commits and gates are in `docs/MODULE_STATUS.md`. Prior traversal, Surface, Intent, and physical-first-frame narrative is in `docs/history/PRE_REFERENCE_RECOVERY_STATE.md` and is not a current task.

## Active target

Phase 3 Dalvik semantics closure. It is CLOSED at `851a025a14a75429c975da43853269f9d98ed8ef` / tree `9ece3c2b0f1bea5d8275bde75f13d91b5b3e63d6`. JNI run `36039287996`, classpath `36039288141`, governance `36039288115`, protected regression `36039288207`.

## Current blocker

None for Phase 3. `API19_REFERENCE_DIFFERENTIAL` was not executed and is not claimed as PASS.

## Next architecture milestone

Phase 3 is CLOSED. R0 CLEAN guest has booted. The image is android-x86 4.4-r5, sha1 `4c0edceef12bf4b8afb1b8390d94a9af29bbbca8`, KVM, live `ro.build.version.release=4.4.4` and `ro.build.version.sdk=19`. Evidence is `tools/reference-lab/clean_boot_evidence.json`. That image is CLEAN only. TRACE is not built. `platform/dalvik@android-4.4.4_r2` revision `36e356c96640775f0a3f167bd2426ea0f0093b8b` is checked out locally. Its `JNINativeInterface` table is indexed at `tools/reference-lab/indexes/dalvik-jni-4.4.4_r2.json` (229 entry points, including `GetStaticIntField` and `CallStaticIntMethod`). Source closure for those symbols stays on `vm/Jni.cpp` and does not invent callees. The rest of the AOSP tree is not synced. The plan is `docs/AGR_REFERENCE_MIGRATION_PLAN.zh-CN.md`.

No Android-visible API, module, class, or symbol is pre-declared as a migration target.

## Reference pipeline implementation in progress

The offline tools now scan DEX class/method/field ID tables and ARM ELF32
DT_NEEDED/imports, verify TRACE event identity before building a per-run
Migration Book, union books by APK or corpus, and emit source manifests from
an explicit source index. Static-only output cannot enter source closure.
Source lookup alone is SOURCE_LOCATED; SOURCE_CLOSED requires a reviewed
closure record and source hash. The JNI table example is SOURCE_LOCATED.
These changes are IMPLEMENTED locally, not CLOSED or MERGED.

R0 remains partial: the recorded CLEAN guest boot is retained, while the
matching API19 TRACE build and event producer have not been established.
That boot used an Android-x86 4.4-r5 image, whereas the intended TRACE
source is AOSP android-4.4.4_r2. Their common build baseline is unproved,
so the boot record is a candidate CLEAN environment, not a ready
CLEAN-versus-TRACE semantic oracle.
Consequently there is no observed Frozen Bubble Migration Book, no reviewed
Framework source closure, no cluster source port, and no CLEAN-to-AGR
differential under the new pipeline. No new Android-visible production
behavior has been added by this tooling work.
