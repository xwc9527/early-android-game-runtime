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
NO ORIGINAL ANDROID SEMANTICS.
NO FRAMEWORK WORK WITHOUT MIGRATION BOOK.
NO SOURCE PORT WITHOUT API19 SOURCE OWNER.

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

No Framework class is pre-declared as a migration target. The owner of a Framework class is produced only by:

Migration Book → API19 Source Closure → Cluster Source Manifest

A source port starts only after that API19 source owner exists. Existing CLOSED implementations, including Character.forDigit, Vector, Random, and older Framework HLE, stay closed. This document marks their historical ownership. It does not rewrite them.

HLE is not an implementation of Android semantics. A call chain may terminate as HLE only when it reaches an explicitly excluded Linux kernel, Binder/system_server, SurfaceFlinger, AudioFlinger, or real device/service boundary.

## What is not an input

These files are history. Active governance and later Work must not read them as production migration input or as a task decision:

- `ci/governance/history/java-public-owner.json`
- `ci/governance/history/java-legacy-migration.json`
- `ci/governance/history/reopens-pre-reference.json`
- `docs/history/PRE_REFERENCE_RECOVERY_STATE.md`

Upstream-map entries with `legacy_navigation_only: true` and `migration_authority: false` are historical source navigation and regression evidence only. They do not authorize continued HLE, a source port, or the next migration target, and they do not replace a Migration Book or API19 Source Closure.

The required development order is:

Phase 3 closure → Local Android Reference Lab → Game Dependency Mapper → Migration Book → API19 Source Closure → Cluster Source Port → Differential
