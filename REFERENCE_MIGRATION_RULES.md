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

This context reset does not rewrite existing pre-reference implementations.

Existing regression evidence remains valid, but does not grant those implementations source ownership, migration authority, or CLOSED status.

Their future disposition is decided only by:

Migration Book → API19 Source Closure → Cluster Source Manifest

A prior REAL_GAME_CONFIRMED result, a passing contract, or an upstream-map entry does not promote an implementation to CLOSED or to a source owner. This reset freezes rewriting for now. It does not keep those implementations permanently.

HLE is not an implementation of Android semantics. A call chain may terminate as HLE only when it reaches an explicitly excluded Linux kernel, Binder/system_server, SurfaceFlinger, AudioFlinger, or real device/service boundary.

## What is not an input

These files are history. Active governance and later Work must not read them as production migration input or as a task decision:

- `ci/governance/history/java-public-owner.json`
- `ci/governance/history/java-legacy-migration.json`
- `ci/governance/history/reopens-pre-reference.json`
- `docs/history/PRE_REFERENCE_RECOVERY_STATE.md`

Every upstream-map entry has `migration_authority: false`. The map is a navigation cache. It may record source paths, hashes, and historical differential or regression evidence. It cannot authorize a migration target, continued legacy HLE, a source port, or production source ownership, and it cannot replace a Migration Book or API19 Source Closure. `legacy_navigation_only: true` marks pre-reference history. `legacy_navigation_only: false` marks source-navigation evidence that is still current and still has no migration authority.

The required development order is:

Phase 3 closure → Local Android Reference Lab → Game Dependency Mapper → Migration Book → API19 Source Closure → Cluster Source Port → Differential
