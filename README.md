# Early Android Game Runtime

An experimental iOS compatibility runtime for original early Android game APKs.
It preserves DEX and ARMv7 ELF code and supplies observable Android guest
behavior inside one native iOS process. It does not boot Android.

The current iOS Simulator and iphoneos runtime include:

- a KitKat-derived ARM32 linker/libdl path and guest VMA/system ABI core;
- the touchHLE ARM interpreter without JIT;
- a host DEX runtime and bidirectional JNI bridge;
- a ProcessRuntime/GuestThreadContext model backed by Darwin pthreads;
- selected Android 4.4.4 `androidfw` and KitKat Skia codec sources;
- EGL/GLES forwarding through ANGLE's Metal backend.

This repository is a partially formalized Runtime and engineering validation
harness. It is not yet a general APK launcher or a complete playable-game
product. See the project overview for the exact completion boundary.

## Reproducible Simulator regression

`.github/workflows/runtime.yml` starts from a clean macOS runner, resolves
licensed F-Droid APK inputs, verifies their published SHA-256 hashes, performs a
static APK/ELF scan, builds the Runtime once per shard, boots an iOS Simulator,
and tests every APK assigned to that shard. No third-party APK is committed to
this repository.

The current five-sample seed corpus contains Kung Foo Barracuda, Gloomy
Dungeons 2, Pixel Dungeon, Frozen Bubble, and Vector Pinball. Real games
produce dependency evidence and regression evidence. A Runtime gap does not
authorize a new Android implementation.

Artifacts include:

- `resolved.json`: exact F-Droid versions and hashes;
- `static-scan.json`: ABI, DEX, native library, `DT_NEEDED`, and imports;
- `runtime-smoke.json`: per-sample execution stages;
- `compatibility-summary.json`: frequency-ranked failure signatures;
- `kungfoo-frame.png`: guest framebuffer evidence.

To add samples, edit `Tests/Samples/fdroid.json`. Increase the workflow shard
matrix only when the corpus needs it; each shard builds the Runtime once and
reuses its Simulator process for all assigned APKs.

See `THIRD_PARTY_NOTICES.md` for component licenses.

## Documentation

Framework migration follows [REFERENCE_MIGRATION_RULES.md](REFERENCE_MIGRATION_RULES.md). That file is the highest-priority rule for later Framework work.

- [中文项目说明](docs/PROJECT_OVERVIEW.zh-CN.md)
- [中文工程交接文档](docs/HANDOFF.zh-CN.md)
- [Android 4.4.4 Runtime migration architecture](docs/MIGRATION_ARCHITECTURE_PLAN.md)
