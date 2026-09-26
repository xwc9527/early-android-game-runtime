# Reference migration rules

`REFERENCE_MIGRATION_RULES.md` 是所有 Android-visible semantics 的最高优先级迁移规则。

它优先于 `AGENTS.md`、`README.md`、`docs/HANDOFF.zh-CN.md`、`docs/MIGRATION_ARCHITECTURE_PLAN.md`、`docs/ARCHITECTURE.md`、`docs/TESTING.md` 和 `docs/DECISIONS.md` 中关于 Android-visible source ownership 的表述。

覆盖：

- Dalvik
- libcore
- Framework
- JNI semantics
- Bionic
- Android native userspace
- 以及其他存在 API19/AOSP source owner 的 Android 行为

## Rules

```text
NO GAME-DRIVEN IMPLEMENTATION.
NO NEW ANDROID-VISIBLE MIGRATION WITHOUT MIGRATION BOOK.
NO ORIGINAL ANDROID SEMANTICS.
NO SOURCE PORT WITHOUT MIGRATION BOOK + API19 SOURCE OWNER + SOURCE CLOSURE.
NOT_OBSERVED != UNUSED.

GAME
→ REFERENCE MAP
→ MIGRATION BOOK
→ API19 SOURCE CLOSURE
→ CLUSTER PORT
→ DIFFERENTIAL

HLE ONLY TERMINATES AN EXCLUDED HOST/SERVICE BOUNDARY.
```

## Meaning

只要 API19/AOSP 存在源码 owner，AGR 就不得原创、近似实现或仅凭语义等价自行重写该 Android 行为。

允许替换机制的地方仅限明确排除的：

- Linux kernel
- Binder/system_server
- SurfaceFlinger
- AudioFlinger
- 真实 device/service boundary
- 以及纯 HostServices primitive

Semantic equivalence alone does not authorize an original AGR implementation.

A real game produces dependency evidence and regression evidence. A Runtime gap does not authorize a new Android implementation or HLE.

No Android-visible API, module, class, or symbol is pre-declared as a new migration target. This covers Dalvik, libcore, Framework, JNI semantics, Bionic, Android native userspace, and any other Android-visible behavior that has an API19/AOSP source owner. Existing CLOSED Runtime is not reopened by this rule. New production migration authority comes only from:

Migration Book → API19 Source Closure → Cluster Source Manifest

A source port starts only after that API19 source owner exists.

`OBSERVED` records a validated reference entry; `SOURCE_LOCATED` records its
API19 source location; `SOURCE_CLOSED` records review of the semantic owner's
state, initialization, internal and cross-layer dependencies, and declared
stopping boundaries. None of these is migration authority by itself.
`MIGRATION_AUTHORIZED` applies only to a reviewed semantic cluster Source
Manifest, never to an individual method or a broad module label.

TRACE absence is never evidence that Android source is unused. A REMOVE or
pruning decision requires source closure for the affected cluster, an explicit
removal scope, and an identical-trajectory API19 CLEAN differential after
removal with no divergence. Existing games are discovery and regression probes;
their observed calls do not define the Android implementation scope.

This context reset does not rewrite existing pre-reference implementations.

Existing regression evidence remains valid, but does not grant those implementations source ownership, migration authority, or CLOSED status.

Their future disposition is decided only by:

Migration Book → API19 Source Closure → Cluster Source Manifest

A prior REAL_GAME_CONFIRMED result, a passing contract, or an upstream-map entry does not promote an implementation to CLOSED or to a source owner. This reset freezes rewriting for now. It does not keep those implementations permanently.

HLE is not an implementation of Android semantics. A call chain may terminate as HLE only when it reaches an explicitly excluded Linux kernel, Binder/system_server, SurfaceFlinger, AudioFlinger, or real device/service boundary.
At that boundary the closure records the app-process observable request,
response, callbacks, lifecycle, and errors. Android-owned behavior before the
boundary remains in the source cluster.

## Shared runtime substrate

An upper cluster stops only on a prerequisite that names one of its own crossing edges. A source-derived owner may carry `prerequisite_edges` for its own `cross_cluster_source_edges` only. The stop is bound to that current owner, the exact crossing, and the origin that reached the owner. Observed-entry stop keys do not propagate down the recursive tree, and a different owner is not stopped merely because it targets the same substrate owner. Dependencies behind the stopped edge belong to the substrate closure. `Framework.ZygotePreload` remains in the upper closure when it is the derived owner; only the substrate crossings it declares are truncated.

Confirmed substrate owners are:

- `Libcore.BootClassLoading`
- `Dalvik.BootClassResolution`
- `Dalvik.ClassInitialization`
- `Dalvik.ClassVerification`
- `Dalvik.Monitor`
- `Dalvik.ThreadState`
- `Dalvik.MethodInvocation`
- `Dalvik.ObjectAllocation`
- `Dalvik.StaticFieldArrayRoots`
- `Dalvik.JNINativeBinding`
- `Bionic.PthreadCondition`
- `Bionic.ClockGettime`

`Framework.ZygotePreload` is not substrate. It remains the Integer startup-environment source owner. `Framework.ZygoteVMOptions` and `AndroidNative.InitZygote` keep their existing narrow source-owner identity. Any additional substrate owner requires explicit confirmation before it is added to this list.

The upper cluster records the crossing on `prerequisite_edges`. This relationship is not an owner source status. Owner records keep `SOURCE_LOCATED` or `SOURCE_CLOSED`. The relationship has exactly three states:

| Relationship | Meaning |
|---|---|
| `UNRESOLVED` | The exact crossing is recorded, recursion stops for that origin only, and the closure work queue keeps this blocker. The upper cluster cannot close or authorize migration. |
| `PREREQUISITE_CLOSED` | The exact crossing passes `external_edge_closed`, and `ci/governance/substrate-production-contracts.json` has a `PRODUCTION_CLOSED` record for that same semantic owner. The record binds that owner's source digest and revision, production module, tested commit and tree, and `closure_run`. `closure_run` must be the single `VALID_PASS` row in `ci/governance/closure-attempts.json` with that same tested commit and tree, and `git rev-parse <tested_commit>^{tree}` must equal the tested tree. Source `SOURCE_CLOSED` alone is not production closure. The registry does not carry a reopen list; production module reopens stay in `ci/governance/reopens.json`. This repository has no API19 CLEAN differential producer, so every `PREREQUISITE_CLOSED` relationship is rejected. A ledger `VALID_PASS`, a matching git tree, and a handwritten differential are not that producer. Absence of that producer does not block an `UNRESOLVED` reclassification. |
| `REOPEN_REQUIRED` | Pinned API19 source shows the existing CLOSED or STABLE contract is insufficient or divergent. Recursion stops for the declaring origin, and the closure work queue keeps this blocker. The upper cluster cannot close or authorize migration. |

The prerequisite record must repeat the crossing edge's edge name, owner, repository, revision, file, symbol, and SHA-256. A record that does not match one crossing source edge of the owner that declares it is rejected. `UNRESOLVED` and `REOPEN_REQUIRED` work items copy that declaring owner's `origin_dependency_ids` and full `source_paths`. `PREREQUISITE_CLOSED` is rejected until a formal API19 CLEAN differential producer exists, so it cannot satisfy an upper prerequisite or be omitted from the work queue as closed. The registry starts empty. It cannot certify a substrate owner by itself, and this rule does not map any real substrate owner to a production module.

`PREREQUISITE_CLOSED` does not lower `MIGRATION_AUTHORIZED`. The upper cluster still needs its own source files, inline edges, boundary contracts, zero unresolved edges, and cluster review. `UNRESOLVED` and `REOPEN_REQUIRED` block both `SOURCE_CLOSED` and `MIGRATION_AUTHORIZED`.

A private copy of a substrate source file, `SERVICE_HLE`, an excluded HLE boundary, or `GAME_PATCH` cannot satisfy or skip the prerequisite. A substrate defect is repaired by reopening that public owner, then by its own source repair, differential, and CLOSE. The upper cluster references that result afterward. Recording `REOPEN_REQUIRED` is not itself a reopen. A real reopen is a separate step that names the module, evidence, and reopen condition.

Integer records six real crossings as `UNRESOLVED` and does not write `PREREQUISITE_CLOSED`. `valueOf` stops at `Dalvik.ClassInitialization`, `Dalvik.ObjectAllocation`, `Dalvik.MethodInvocation`, and `Dalvik.StaticFieldArrayRoots`. `Framework.ZygotePreload` stays in the Integer closure and stops at `Dalvik.ClassInitialization` and `Libcore.BootClassLoading`. `Dalvik.StaticFieldArrayRoots` keeps source status `SOURCE_CLOSED` while its relationship stays `UNRESOLVED`. The Integer cluster remains `SOURCE_LOCATED` with `MIGRATION_AUTHORIZED=false`. Resources records one real crossing as `REOPEN_REQUIRED` and does not write `PREREQUISITE_CLOSED`: `AndroidNative.JNIHelp` stops at `Dalvik.JNINativeBinding` on `Dalvik RegisterNatives method binding`. Pinned CLEAN image `2d4f0d0a7a193b829349c0f9247b670c600ee2690eeb1f8949fc5794b2639645` and Dalvik `36e356c96640775f0a3f167bd2426ea0f0093b8b` `vm/Jni.cpp` `RegisterNatives` / `dvmRegisterJNIMethod` diverge from `Runtime/DexLoom/VM/dx_jni.c` `jni_RegisterNatives` on `missing_signature`, `non_native`, `null_fn`, and `fast_static`. This relationship record is not a module reopen. `AndroidNative.JNIHelp` stays in the Resources closure. Its two blocking edges stay, because the source map separates nativehelper class resolution and the `RegisterNatives` call from Dalvik method binding. The Resources cluster remains `SOURCE_LOCATED` with `MIGRATION_AUTHORIZED=false`.

## What is not an input

These files are history. Active governance and later Work must not read them as production migration input or as a task decision:

- `ci/governance/history/java-public-owner.json`
- `ci/governance/history/java-legacy-migration.json`
- `ci/governance/history/reopens-pre-reference.json`
- `docs/history/PRE_REFERENCE_RECOVERY_STATE.md`

Every upstream-map entry has `migration_authority: false`. The map is a navigation cache. It may record source paths, hashes, and historical differential or regression evidence. It cannot authorize a migration target, continued legacy HLE, a source port, or production source ownership, and it cannot replace a Migration Book or API19 Source Closure. `legacy_navigation_only: true` marks pre-reference history. `legacy_navigation_only: false` marks source-navigation evidence that is still current and still has no migration authority.

工程方案是 `docs/AGR_REFERENCE_MIGRATION_PLAN.zh-CN.md`。它服从本文件。当前仍先完成 Phase 3 final gate。Phase 3 CLOSED 之后的顺序是：

Phase 3 CLOSED → Phase R0 Local Android Reference Lab → Phase R1 Game Dependency Mapper → Phase R2 Migration Book → Phase R3 API19 Source Closure → Phase R4 Cluster Source Port → Phase R5 CLEAN differential → Phase R6 corpus union

API19 TRACE 是 Dependency Mapper 的默认输入。API19 CLEAN 是 semantic oracle。TRACE 不授权原创实现。
