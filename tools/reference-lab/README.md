# Local Reference Lab tooling

The six current reference review gates and their evidence limits are in
[`REVIEW-GATES.md`](REVIEW-GATES.md).

Current paired runtime evidence is under `evidence/*-paired-*.json` with
matching concordance and TRACE run manifests. Frozen Bubble and Gloomy
Dungeons 2 pass x86 CLEAN/TRACE lifecycle state checks, and Vector Pinball
passes on ARMv7 with `libgdx.so` mapped in both guests. KungFoo Barracuda
passes a native-backed gameplay lifecycle with a scored game-over state.
Pixel Dungeon passes a GPU-enabled CLEAN lifecycle; the paired
TRACE run is blocked by guest data capacity on this legacy emulator, while
graphics capture also fails. The tested 512 MB and 1 GB data templates cause
system WindowManager faults before APK installation; the diagnostic is in
`evidence/pixel-reference-carrier-diagnosis.json`. Pixel sample validity and
gameplay remain undetermined. All reported invoke
sets remain observed lower bounds, not deletion evidence.

`evidence/four-game-corpus-summary.json` is generated from the four paired
evidence sets with `runtime_corpus_summary.py` and its adjacent manifest.
Across these runs, 779 distinct methods were observed: 665 in one game, 88 in
two, 24 in three, and 2 in all four. These are shared method identities, not
source-closed clusters. The summary uses owner-indexed Books built from each
matching CLEAN image's BOOTCLASSPATH. A small number of observed classes
remain `OWNER_UNRESOLVED_IN_BOOT_JARS`; broad owner assignment is not source
closure.
The two common four-game methods are
`ContextThemeWrapper.getResources()` and `AssetInputStream.close()`; their
shared use makes the Android resource path a source-review priority, not a
game-defined implementation boundary.
Their pinned Java/JNI/androidfw source edges, AGR counterpart, and unresolved
closure boundaries are recorded in
`docs/RESOURCE_CLUSTER_SOURCE_MAP_API19.md`. Both remain `SOURCE_LOCATED`;
this review does not authorize a resource-cluster port or pruning.
The three-game integer boxing cluster seed is in
`evidence/integer-boxing-source-seed.json`, with its libcore and Dalvik source
path reviewed in `docs/INTEGER_BOXING_SOURCE_MAP_API19.md`. It also remains
`SOURCE_LOCATED` pending class-initialization and GC boundary closure.
`source_mapping_queue.py` turns the four owner-indexed Books into
`evidence/four-game-source-mapping-queue.json`: 779 observed method identities,
114 shared by at least two games, and seven entries currently `SOURCE_LOCATED`
across pinned Framework and libcore source indexes. Its event counts are prioritization data, not a definition
of Runtime scope or evidence of source closure.
Frozen Bubble's earlier Book omitted sequence bounds because its old exported
event file omitted sequence fields. `rebuild_trace_sequences.py` verified the
original direct-file and event hashes, restored sequence fields from the
direct records, and regenerated its Book. All 441 aggregate observations now
have sequence bounds. All four pairs compare only
structural lifecycle state, not gameplay semantics. Gloomy's landscape
gameplay path passes CLEAN/TRACE with 301,482 complete direct-file events and
672 observed method identities.

This directory contains the local API19 source and artifact path. The
historical committed CLEAN boot record used Android-x86 4.4-r5 and cannot
pair with an AOSP TRACE image. Local `android-4.4.4_r2` CLEAN/TRACE x86 and
ARM build pairs are `BUILD_VERIFIED`. The differential gate calls
`assert_matched_reference` before treating images as a pair. Runtime evidence
and observer coverage remain separate gates.

Run the pipeline with:

    python3 tools/reference-lab/workflow.py book --apk game.apk --out book-static.json
    python3 tools/reference-lab/workflow.py book --apk game.apk --events trace.ndjson --trace-evidence trace-run.json --out book-run.json
    python3 tools/reference-lab/workflow.py union --books book-run-1.json book-run-2.json --out book-game.json
    python3 tools/reference-lab/workflow.py corpus-union --books book-game-1.json book-game-2.json --out book-corpus.json
    python3 tools/reference-lab/workflow.py closure --book book-game.json --index source-index.json --out source-manifests.json --require-closed
    python3 tools/reference-lab/cluster_seed.py --corpus-manifest four-game-corpus-manifest.json --source-index source-index.json --semantic-cluster libcore.IntegerBoxing --out cluster-seed.json
    python3 tools/reference-lab/verify_source_index.py --index source-index.json --checkout /path/to/pinned/repository

For a cross-repository source edge, also pass
`--external-checkout platform/dalvik=/path/to/pinned/dalvik`. The verifier
checks the external Git revision and each referenced file digest.

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
For a multi-file cluster, closure evidence instead requires an exact
`source_file_sha256` map for every listed file, every declared dependency edge
in `reviewed_dependency_edges`, and an empty `unresolved_dependency_edges`
list. Missing coverage keeps the entry at `SOURCE_LOCATED`.
Entries never authorize migration. The source index must name a specific
`semantic_cluster`; its separate `cluster_reviews` record must cover every
indexed entry, source file and dependency edge at the same revision before the
cluster reaches `MIGRATION_AUTHORIZED`. The closure CLI can require that state
with `--require-authorized-cluster`. Broad labels such as `Framework` and
`libcore` identify owners but do not grant cluster authority.
An unresolved `blocking_edges` list keeps the entry at `SOURCE_LOCATED` even
when review fields are present. For a closed semantic cluster, each edge review
must identify an included source path, a separately closed source cluster, or
an excluded platform boundary with its observable contract.
`source_derived_clusters` in a Source Manifest expands pinned source edges
recursively from observed Migration Book entries. Each derived owner retains
its original observed dependency ID and full source path; it is explicitly
`SOURCE_DERIVED`, never a new TRACE observation or migration authorization.
Validation rejects a missing derived owner or a path whose adjacent edge lacks
the pinned repository, revision, file hash, and symbol.
An external `SOURCE_CLOSED` edge requires a separately reviewed owner record
at the same revision and file hash, with its own nested edges and boundary
contracts resolved. The closed owner's canonical digest must also match the
entry edge review. A missing or mismatched owner fails validation. Cyclic
source paths are materialized once as `cycle_paths` and remain
`SOURCE_LOCATED`; the recursive closure check rejects their promotion. A
separate strongly connected owner review is required before such a chain can
reach `SOURCE_CLOSED`.
`closure_work_queue` enumerates every blocking edge on observed entries and
reachable source-derived owners, preserving origin dependency IDs and source
paths. Validation rejects a queue that omits or invents a denied gate.
For the Integer boot path, `inspect_boot_odex.py --clean CLEAN_CORE_ODEX
--trace TRACE_CORE_ODEX --out OUTPUT_JSON` verifies the paired embedded DEX
hash and the `VERIFIED | OPTIMIZED` flags on Integer, Number, and Comparable.
The checked output is `evidence/paired-core-odex-preverification.json`.

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
direct guest-file `AGRTRACE|v2` records and rejects malformed, duplicate, or
missing sequences per game process. The earlier logcat transport lost records
at high invoke rates and remains diagnostic only. Repeated dependency edges
are aggregated in Migration Books with count and first/last sequence; raw
ordered events remain separate. This observer covers only method calls.
Class, field, JNI, native, service, and lifecycle observers remain necessary
for a complete Dependency Mapper. `boot_owner_index.py` classifies Java owners
using exact boot JAR class definitions without claiming source closure.

`build_trace.sh TRACE_ROOT JDK6_ROOT MAKE382_ROOT TRACE_OUT CLEAN_OUT` checks
the exact Dalvik instrumentation diff and confirms the fully resolved
manifest matches CLEAN byte for byte before building. It records the TRACE
patch and output image hash in a separate output directory. The instrumentation
diff SHA-256 is
`54560f1fd7b6d1c689a559480b9ca562293fc3cb20081d73bfc2eaf77e41ce2b`.
Use the optional `--vm-only` last argument for a Dalvik compilation check
before the full image build. Once both full builds finish, `record_pair.py
--clean-out CLEAN_OUT --trace-out TRACE_OUT --out pair.json` checks the image
hashes, resolved manifest, host toolchain, and TRACE patch and writes a pair
record. A verified build pair still needs live boot and sample evidence.
`probe_pair.py --pair pair.json --apk frozen-bubble.apk --variant CLEAN`
boots the matched image in portable mode and checks API level, package
manager, installation, resumed activity, and screenshot. Run it again with
`--variant TRACE` for the instrumented image; that run also checks TRACE log
sequence continuity and writes `events.ndjson` plus `trace-run.json` for the
Migration Book importer. Each probe writes a terminal PASS or FAILED record.
The optional unpaired CLEAN smoke test omits `--pair`; it cannot establish a
matched oracle. The current local WSL emulator uses `emulator64-x86` with
`-qemu -disable-kvm` because its KVM VM creation fails despite `/dev/kvm`
being present. It needs `-memory 1024` for package management and `-wipe-data`
to initialize the writable data image. The probe checks the focused game
window so a lockscreen capture cannot pass. The unpaired AOSP CLEAN cold-start
run is recorded in `evidence/frozen-bubble-aosp-clean-cold-start.json`: Android
4.4.4/API19, portable interpreter, successful APK installation, resumed and
focused Frozen Bubble activity, and a PNG of the game frame. Its
`UNPAIRED_CLEAN_SMOKE` label withholds pair-level oracle status until the TRACE
build and pair check finish.

The repository's five locked F-Droid samples are verified with
`sample_matrix.py --lock Tests/Samples/fdroid.lock.json --apk-dir APK_DIR
--aapt AAPT --out matrix.json`. The current matrix is in
`evidence/corpus-sample-matrix.json`. `probe_corpus.py` runs the same bounded
cold-start first-frame check for each sample; it does not claim gameplay,
pause/resume, storage, audio, or exit coverage. `build_corpus_books.py` writes
per-game `STATIC_ONLY` Books and a corpus union; the current count summary is
`evidence/corpus-static-summary.json`. The source scanner ignores bundled
64-bit ELF variants because API19 is 32-bit, while the matrix retains their
names. Vector Pinball's locked APK has only ARM native libraries, so an x86
guest cannot verify its native gameplay path.

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
