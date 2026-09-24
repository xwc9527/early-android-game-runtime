# Local Reference Lab tooling

This directory contains the offline artifact path. It does not build an API19
TRACE image. The committed CLEAN boot record cannot serve as TRACE evidence.
The CLEAN boot image is Android-x86 4.4-r5 and its common source/build base
with a future AOSP android-4.4.4_r2 TRACE image is unproved. The differential
gate must use assert_matched_reference before treating them as a pair.

Run the pipeline with:

    python3 tools/reference-lab/workflow.py book --apk game.apk --out book-static.json
    python3 tools/reference-lab/workflow.py book --apk game.apk --events trace.ndjson --trace-evidence trace-run.json --out book-run.json
    python3 tools/reference-lab/workflow.py union --books book-run-1.json book-run-2.json --out book-game.json
    python3 tools/reference-lab/workflow.py corpus-union --books book-game-1.json book-game-2.json --out book-corpus.json
    python3 tools/reference-lab/workflow.py closure --book book-game.json --index source-index.json --out source-manifests.json --require-closed

The TRACE run manifest must identify an instrumented dependency-mapper build
of android-4.4.4_r2, its image SHA-256, the APK SHA-256, scenario, and
the event file SHA-256. The importer rejects mismatched identity or hashes.
The validated manifest is retained in each TRACE Migration Book and in
per-game unions. An observed dependency without that run evidence is rejected
by the Book validator.
Static-only books remain STATIC_ONLY and cannot authorize source closure.

The APK scanner reads DEX Android/libcore class, field, and method ID tables,
native method declarations, plus ARM ELF32
DT_NEEDED and imported symbols. It does not infer reachability, parse binary
layout resources, or invent dynamic reflection targets. Those findings remain
STATIC_REFERENCED.

`evidence/frozen-bubble-static.json` is a static-only book generated from the
repository-locked `org.jfedor.frozenbubble_8.apk` (SHA-256
`57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569`).
It contains 183 distinct entries: 57 classes, 117 methods, and 9 fields.
The APK was fetched from the F-Droid archive mirror at
`https://ftp.agdsn.de/pub/mirrors/fdroid/archive/org.jfedor.frozenbubble_8.apk`
and verified against `Tests/Samples/fdroid.lock.json`. This book cannot
authorize source closure or a cluster port until the matching TRACE run exists.

An index entry is SOURCE_LOCATED when it names source files and symbols.
SOURCE_CLOSED additionally requires explicit closure_reviewed=true and
closure_evidence with source_sha256, reviewed_by, and closure_notes. That
evidence and the index's exact 40-character source revision must reflect
actual API19 source dependency review; the JNI table
index in this repository only locates entry symbols. Service observations
remain BOUNDARY_CANDIDATE until the excluded boundary is sourced and reviewed.

The current implementation does not provide a complete Android TRACE event
producer, Framework source closure, cluster ports, or iOS differential. Its
output is not proof that those stages are complete.

The TRACE checkout now has a reproducible first Dalvik observer. Run
`instrument_trace.py TRACE_ROOT` against an untouched `android-4.4.4_r2`
checkout. It modifies only TRACE Dalvik source and regenerates the x86 and
portable interpreter sources. Its call hook records game-classloader calls
to boot-classloader methods, including caller, dex PC, opcode, method index,
declared DEX target, and resolved callee. The TRACE guest must run with
`dalvik.vm.execution-mode=int:portable` so every interpreted call traverses
this hook; use the same execution mode for CLEAN comparisons. JIT and the x86
assembly interpreter bypass this C++ hook. `parse_trace_log.py` accepts
`adb logcat -v threadtime` captures and rejects malformed or missing sequence
records. This observer covers only method calls. Class, field, JNI, native,
service, and lifecycle observers are still needed before claiming a complete
Dependency Mapper. No successful TRACE run has been recorded yet.

`build_trace.sh TRACE_ROOT JDK6_ROOT MAKE382_ROOT TRACE_OUT CLEAN_OUT` checks
the exact Dalvik instrumentation diff and confirms the fully resolved
manifest matches CLEAN byte for byte before building. It records the TRACE
patch and output image hash in a separate output directory. The instrumentation
diff SHA-256 is
`1340359e595c934aee364fcdf3119b52fef56ef27b13af2ed820b407eaf6393f`.

`boot_clean.py --root /agr-reference --apk /path/to/game.apk --component
package/.Activity` can probe installation and launch in the CLEAN guest. It
checks the package manager, transfers the APK, then runs `pm install` as
separate bounded stages. It records a terminal PASS or FAILED result in
`emulator/clean-probe.json` and captures a PNG only on a completed launch.
The pinned Frozen Bubble APK probe
currently fails at `adb install -r` after 180 seconds; the record is
`evidence/frozen-bubble-clean-probe-failed.json`. This CLEAN candidate has
boot evidence but does not yet have a successful sample launch.

The second CLEAN probe separated transfer from package installation. Transfer
succeeded, but `adb shell pm install -r` timed out after 120 seconds. Its
record is `evidence/frozen-bubble-clean-probe-package-install-failed.json`.
Neither probe establishes a successful launch.

The local source workbench uses the official `android-4.4.4_r2` manifest. A
local manifest copy must replace its relative `fetch=".."` with
`fetch="https://android.googlesource.com/"` when `repo init -u file://...`
is used. This changes the transport base, not the pinned tag or projects.
`transport_manifest.py --transport official` performs that rewrite.
Its `--transport github` mode generates a GitHub fallback, but the aosp-mirror
organization does not contain every project in this release; it cannot
currently sync the full checkout alone.

Once the official checkout is fully synced, `build_clean.sh AOSP_ROOT
JDK6_ROOT MAKE382_ROOT OUT_DIR` builds `aosp_x86-eng` from a clean source tree. It writes
the resolved source manifest and the CLEAN `system.img` hash to a separate
output directory. The driver requires Python 2 and JDK6 in the local build
environment, uses GNU Make 3.82, and refuses dirty source projects.
The GNU Make 3.82 release archive was verified with the published MD5
`7f7c000e3b30c6840f2e9cf86b254fac`. Its local toolchain build uses libc
glob and `make-3.82-gl-lstat.patch` for current glibc. The AOSP checkout has
one build-only difference, `api19-openjdk6-build.patch`, which permits the
installed Zulu OpenJDK6. The CLEAN build driver verifies the exact diff and
records the patch SHA-256. Neither patch changes Android guest runtime code.
