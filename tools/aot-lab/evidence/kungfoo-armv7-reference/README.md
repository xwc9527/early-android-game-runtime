# KungFoo ARMv7 Android reference

This evidence was collected on 2026-09-27 from `/agr-reference`, using the
verified Android `android-4.4.4_r2` ARM CLEAN/TRACE pair. It belongs to AOT
route validation branch `validation/aot-route-evidence`, based exactly on
`experiment/armv7-arm64-aot-poc` commit
`ddb04ad8e1da8df879bccaee912bdf0881d06e6a` (tree
`3fea506f50b63b728b35dcede1e4dfe6db1cef61`).

Input APK: `/agr-reference/samples/fdroid/kungfoo-barracuda.apk`, SHA-256
`097ade628ad0837e312da4ca48afe0906eb99c3b992d497c7da33e2b2267eb22`.
The installed ARM package maps
`libKungFooBarracudaNativeActivity.so`; its `armeabi-v7a` APK member is
882,136 bytes and has SHA-256
`010baa4964cd7dbcf1ba038428ab4d6afc13ffd0a180b447be07b8f088f9ba9d`.
The APK ABI inventory is in `apk-native-identity.json`.

Both `clean/probe.json` and `trace/probe.json` report `PASS`. The same scenario
and input actions exercised launch, two taps, a wait, Home, resume, force stop,
and relaunch. At every live step the ARM process mapped the app's native ELF.
The probe records process survival, CPU time, thread count, resumed/focused
Activity, and native library maps. `concordance.json` recomputes to
`STATE_CONCORDANT` for structural lifecycle state; it does not assert game
state, audio, pixels, or timing equivalence. The TRACE `screen-02-tap.png`
captures active play with sprites and score 0; both runs' `screen-03-wait.png`
capture the same game-over frame with score 5 (matching SHA-256
`16ff26250a17ae17933cff6366110e3749cc5571a59ed0bd0c3e1c63efabf421`).
Those frames corroborate the live process, growing CPU time, native ELF map,
and completed lifecycle observations; they are not the sole health criterion.

TRACE recorded 6,695 events. `trace/trace-direct/trace-all.log.gz` contains
the unmodified guest direct trace bytes, and `trace/events.ndjson.gz` contains
the parsed event stream. Both are gzip archives that round-trip to the
`archive-manifest.json` source SHA-256 values. The observer coverage is
`APP_DEX_TO_BOOT_METHOD_INVOKE`, so these events are **not** a native ARM
instruction trace. The Zygote preload and app maps are separate original
records. Build outputs (`userdata.img`, `guest-framework.jar`, and
`guest-libdvm.so`) were excluded; their identities and configuration are
bound by `arm-reference-pair.json` and the probes.

For the native ELF scale check, `*-armv7-readelf.txt` are raw GNU readelf 2.38
outputs from `readelf -hSWdrs` on the original `armeabi-v7a` APK members.
KungFoo `.text` is `0x83d2c` (539,948) bytes; Gloomy `.text` is `0xf6e`
(3,950) bytes. This static size comparison is not execution coverage or a
performance measurement. Gloomy's ELF SHA-256 is
`2b8672e79da33de4661f6aa0bcb79df2a302637aca9829d53fff8077a6895638`.
The raw `readelf -A` outputs show both ELF files declare ARMv7, Thumb-2,
and VFPv3-D16. They do not show which floating point instructions execute in
the tested paths.

Reproduction uses `tools/reference-lab/probe_pair.py --arch arm` with the
locked `tools/reference-lab/scenarios/kungfoo-landscape-gameplay.json`
actions, variants CLEAN and TRACE, and
`tools/reference-lab/pair_concordance.py`. The exact emulator commands,
image hashes, kernel hash, Dalvik interpreter mode, JIT status, action hash,
and runtime observations are in the original probes. Repackaging is done by
`tools/aot-lab/archive_arm_reference.py`; it checks byte-for-byte recovery.
