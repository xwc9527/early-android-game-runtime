# ARM execution route evidence status, 2026-09-27

Status: `ROUTE_DECISION_NOT_READY`. This is a validation record, not a change
to D011 or a selection of the CPU backend.

The validation branch was created from
`experiment/armv7-arm64-aot-poc` at
`ddb04ad8e1da8df879bccaee912bdf0881d06e6a`, tree
`3fea506f50b63b728b35dcede1e4dfe6db1cef61`. The proof branch was not
modified. D011 remains unchanged.

The local Android reference is `android-4.4.4_r2` on the verified ARM
CLEAN/TRACE pair (`kungfoo-armv7-reference/arm-reference-pair.json`). CLEAN
system image SHA-256 is
`55c5ca31b556d522b9a266df7774281544c1abb680b9e73c9e82c796d984cc3a`;
TRACE is
`55f0cf0211ccb19558200d0f537f1a04394e9b707ec5bd7b03b57d2c6796881a`.
Both use Dalvik `int:portable` with JIT disabled. The original KungFoo APK
and ARMv7 native member hashes are in `kungfoo-armv7-reference/apk-native-identity.json`.

The KungFoo ARM CLEAN/TRACE probes both passed. Each loaded the actual
ARMv7 `libKungFooBarracudaNativeActivity.so` and completed launch, taps,
gameplay, game-over score 5, Home, resume, force stop, and relaunch. The
structural lifecycle comparator returned `STATE_CONCORDANT`. The raw guest
TRACE stream has 6,695 complete-sequence Dalvik invocation events across
the two observed app PIDs. Its declared coverage is only
`APP_DEX_TO_BOOT_METHOD_INVOKE`; it does not measure ARM instructions.
Original probe records, maps, logs, frames, direct trace bytes, parsed events,
pair manifest, and archive byte hashes are in `kungfoo-armv7-reference/`.

The original ARMv7 KungFoo ELF has 539,948 bytes of `.text`; the Gloomy
renderer has 3,950 bytes of `.text` in the same static inspection. Both
declare ARMv7, Thumb-2, and VFPv3-D16 attributes. These are binary scale and
target capability observations, not executed instruction coverage. Raw
`readelf` output is in the KungFoo evidence directory.

The existing Gloomy proof's repository differential reports 153 executed
guest instructions, 30 translated blocks, zero fallback, matching host
sequence and framebuffer. It reports approximately 1.031 ms interpreter
guest time and 0.151 ms AOT guest time, but the wall interval is dominated by
host/import boundaries. The original CI artifact for run `36308503927`,
artifact `10928445760`, is reported as valid by the public Actions API;
`gloomy-armv7-arm64-aot-poc/artifact-metadata.json` binds its digest and
tested commit. The repository still lacks several original CI files listed
in `gloomy-armv7-arm64-aot-poc/ci.json`. Until those bytes are recovered,
the partial Gloomy repository evidence is not a complete route authority.

The current translator (`tools/aot-lab/translate.py`) takes an interpreter
instruction trace as its input and emits only the PCs decoded in that trace.
`Runtime/AotLab/agr_aot.c` returns `AGR_AOT_MISS` for unknown blocks. This
is a successful narrow trace-guided proof; it does not establish automatic
offline coverage for a newly installed APK. No KungFoo AGR interpreter
instruction trace, AOT generated code, AOT differential, or backend-isolating
performance run has been added in this validation branch.

Key route questions remain `UNPROVEN`: reusable instruction capability
across actual executed KungFoo code, how misses or unseen code are handled
without game-specific patches, offline preparation cost and generated code
size at KungFoo scale, guest-heavy runtime performance, and a grounded
AOT-versus-JIT comparison under the same AGR guest/runtime contract. The
Android ARM reference closes the sample ABI/reference gap; it does not close
these CPU-backend gaps. No linker, Bionic, JNI, EHABI, Dalvik, Framework,
NativeActivity, or EGL ownership was changed.
