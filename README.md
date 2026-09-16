# Early Android Game Runtime

An experimental iOS compatibility runtime for original early Android game APKs.
It preserves DEX and ARMv7 ELF code and supplies observable Android guest
behavior inside one native iOS process. It does not boot Android.

The current iOS Simulator runtime includes:

- a native ARM32 ELF loader and guest system ABI core;
- the touchHLE ARM interpreter without JIT;
- a host DEX runtime and bidirectional JNI bridge;
- selected Android 4.4.4 `androidfw` and KitKat Skia codec sources;
- EGL/GLES forwarding through ANGLE's Metal backend.

## Reproducible Simulator regression

`.github/workflows/ios-simulator.yml` starts from a clean macOS runner, resolves
licensed F-Droid APK inputs, verifies their published SHA-256 hashes, performs a
static APK/ELF scan, builds the Runtime once per shard, boots an iOS Simulator,
and tests every APK assigned to that shard. No third-party APK is committed to
this repository.

The current five-sample seed corpus contains Kung Foo Barracuda, Gloomy
Dungeons 2, Pixel Dungeon, Frozen Bubble, and Vector Pinball. The two established
native regressions must reach a visible framebuffer. Other samples run through
the generic APK/DEX/ELF probe until success or the first normalized Runtime gap.

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
