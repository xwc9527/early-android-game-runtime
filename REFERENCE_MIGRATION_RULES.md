# Reference migration rules

This file is the highest-priority rule for later Framework migration. `README.md`, `docs/HANDOFF.zh-CN.md`, and `docs/MIGRATION_ARCHITECTURE_PLAN.md` are subordinate to it for that work.

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

A real game produces dependency evidence and regression evidence. A Runtime gap, an unresolved invoke, or a missing public API found in a game does not authorize a new Android implementation or HLE.

Android-visible semantics come from pinned Android 4.4.4/API19 source after that source has an owner. AGR does not invent a parallel Android semantics.

No Framework class is pre-declared as a migration target. The owner of a Framework class is produced only by:

Migration Book → API19 Source Closure → Cluster Source Manifest

A source port starts only after that API19 source owner exists.

HLE is not an implementation of Android semantics. A call chain may terminate as HLE only when it reaches an explicitly excluded Linux kernel, Binder/system_server, SurfaceFlinger, AudioFlinger, or real device/service boundary.

## What is not an input

These files are history. Active governance and later Work must not read them as production migration input or as a task decision:

- `ci/governance/history/java-public-owner.json`
- `ci/governance/history/java-legacy-migration.json`
- `ci/governance/history/reopens-pre-reference.json`
- `docs/history/PRE_REFERENCE_RECOVERY_STATE.md`

The required development order is:

Phase 3 closure → Local Android Reference Lab → Game Dependency Mapper → Migration Book → API19 Source Closure → Cluster Source Port → Differential
