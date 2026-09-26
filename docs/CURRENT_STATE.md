# AGR Current State

Updated: 2026-09-26

## Current reference-migration work

The local `android-4.4.4_r2` CLEAN/TRACE x86 and ARM build pairs are
`BUILD_VERIFIED`. Four qualified games have paired lifecycle evidence and are
fixed regression probes. Pixel has no qualified paired TRACE result; no Pixel,
screenshot, or old-emulator work is active. Reference Lab work is admitted only
for a concrete source-owner, dependency-closure, or differential evidence gap.

The four-game app-to-boot invoke queue contains 779 observed method identities,
114 shared by at least two games. Two Framework resource entries and
`Integer.valueOf(int)` are `SOURCE_LOCATED`; four other observed Integer boxing
method source sets are `SOURCE_CLOSED`. Both semantic clusters remain unclosed
and `MIGRATION_AUTHORIZED` is false. `Bionic.ClockGettime` can be
`MIGRATION_AUTHORIZED` only as a `SOURCE_DERIVED` substrate manifest when its
source-derived review matches, including the Darwin realtime and monotonic
host-boundary evidence. That authorization is not production closure and does
not close Integer or Resources. The authorized `CLOCK_REALTIME` and
`CLOCK_MONOTONIC` requests now have a Bionic production port. That port is
not `PRODUCTION_CLOSED` and it is not a formal CLEAN differential producer.
The ThreadState self-suspend crossing has an exact `CROSSING_CLOSED` record.
That record does not mark `Bionic.PthreadCondition` `PRODUCTION_CLOSED`.
Absolute condition timeouts stay outside that path. `Dalvik.ThreadState` is
now `SOURCE_CLOSED` for that source path. It is not `MIGRATION_AUTHORIZED`.
`Dalvik.JNINativeBinding` stays `SOURCE_LOCATED`, and its thread-state
prerequisite stays `UNRESOLVED`.
The
current source indexes and manifests are under `tools/reference-lab/indexes`
and `tools/reference-lab/evidence`; their unresolved edges are explicit.

The older R0 narrative below records an earlier workbench state and is
superseded for current migration decisions by this section and the validated
evidence artifacts.

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

The active target is `Dalvik.JNINativeBinding API19 Repair` on `cursor/shared-substrate-prerequisite-da4f`. Its governance lifecycle is `IMPLEMENTED` and it has no closure attempt. Phase 3, including subphases 3A0, 3A, 3B, 3C, 3D, and the final JNI gate, remains a historical CLOSED target.

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

`Dalvik.JNINativeBinding API19 Repair`. `DalvikJNI` is reopened for this target. Production `dx_jni.c` and `dx_jni.h` are unchanged. The owner source status remains `SOURCE_LOCATED`.

## Current blocker

`Dalvik.JNINativeBinding` source closure is not `SOURCE_CLOSED`. `RegisterNatives` crosses `Dalvik.ThreadState`, `Dalvik.ClassInitialization`, `Dalvik.ObjectAllocation`, `Dalvik.MethodInvocation`, and `Dalvik.Monitor`, and those relationships are `UNRESOLVED`. The CLEAN differential result `DIVERGED` is not a closure PASS. Do not repair production until that source closure passes.

## Next architecture milestone

Phase 3 is CLOSED. R0 CLEAN guest has booted. The image is android-x86 4.4-r5, sha1 `4c0edceef12bf4b8afb1b8390d94a9af29bbbca8`, KVM, live `ro.build.version.release=4.4.4` and `ro.build.version.sdk=19`. Evidence is `tools/reference-lab/clean_boot_evidence.json`. That image is CLEAN only. TRACE is not built. `platform/dalvik@android-4.4.4_r2` revision `36e356c96640775f0a3f167bd2426ea0f0093b8b` is checked out locally. Its `JNINativeInterface` table is indexed at `tools/reference-lab/indexes/dalvik-jni-4.4.4_r2.json` (229 entry points, including `GetStaticIntField` and `CallStaticIntMethod`). Source closure for those symbols stays on `vm/Jni.cpp` and does not invent callees. The rest of the AOSP tree is not synced. The plan is `docs/AGR_REFERENCE_MIGRATION_PLAN.zh-CN.md`.

No Android-visible API, module, class, or symbol is pre-declared as a migration target.

## Reference pipeline implementation in progress

The offline tools now scan DEX class/method/field ID tables and ARM ELF32
DT_NEEDED/imports, verify TRACE event identity before building a per-run
Migration Book, retain the validated TRACE run manifest in Books and unions,
union books by APK or corpus, and emit source manifests from
an explicit source index. Static-only output cannot enter source closure.
Source lookup alone is SOURCE_LOCATED; SOURCE_CLOSED requires a reviewed
closure record whose hash matches the pinned source index. The JNI table
example is SOURCE_LOCATED. The local Ubuntu 22.04 WSL2 environment has
`/dev/kvm`; the verified CLEAN ISO booted again there and ADB reported
Android 4.4.4/API19 with the fingerprint recorded in
`tools/reference-lab/clean_boot_evidence.json`. The checked-out Dalvik
`vm/Jni.cpp` hashes to
`ebba645673d34d23be01b20891cb18c432ce67a4d7d76fdfbf023cc944b2dbed`;
the regenerated 229-entry index matches the committed index semantically.
`platform/frameworks/base@android-4.4.4_r2` was also checked out locally at
`63ade05d76785975fc3292ca030abbaa1dda8891` for source inspection;
this is not a complete AOSP build tree or a reviewed Framework closure.
The SHA-pinned Frozen Bubble APK produced
`tools/reference-lab/evidence/frozen-bubble-static.json` with 183 static
references. That artifact is STATIC_ONLY, not an observed TRACE run.
The CLEAN sample install probe passed a package-manager listing but
`adb install -r` timed out after 180 seconds on two attempts; the second
failure is recorded at
`tools/reference-lab/evidence/frozen-bubble-clean-probe-failed.json`.
The image has a verified boot, but sample launch has not passed.
Zulu OpenJDK 6 runs in the local WSL2 workbench; a KitKat build has not
been attempted or validated with that JDK.
The Ubuntu reference workbench was exported and imported as WSL2 distro
`Ubuntu-22.04-AGR` at `D:\1\AGR-Reference\Ubuntu-22.04-AGR` after the D:
drive gained build capacity. KVM, the pinned Framework checkout, and the
Java 6 runtime were verified in the imported distro. The AOSP
`android-4.4.4_r2` manifest was downloaded to
`/agr-reference/aosp-4.4.4-r2/default.xml`; full source sync and image
build have not run.
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
