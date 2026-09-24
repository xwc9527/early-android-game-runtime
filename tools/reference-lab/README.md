# Local Reference Lab tooling

This directory contains the offline artifact path. It does not build an API19
TRACE image. The committed CLEAN boot record cannot serve as TRACE evidence.

Run the pipeline with:

    python3 tools/reference-lab/workflow.py book --apk game.apk --out book-static.json
    python3 tools/reference-lab/workflow.py book --apk game.apk --events trace.ndjson --trace-evidence trace-run.json --out book-run.json
    python3 tools/reference-lab/workflow.py union --books book-run-1.json book-run-2.json --out book-game.json
    python3 tools/reference-lab/workflow.py corpus-union --books book-game-1.json book-game-2.json --out book-corpus.json
    python3 tools/reference-lab/workflow.py closure --book book-game.json --index source-index.json --out source-manifests.json --require-closed

The TRACE run manifest must identify an instrumented dependency-mapper build
of android-4.4.4_r2, its image SHA-256, the APK SHA-256, scenario, and
the event file SHA-256. The importer rejects mismatched identity or hashes.
Static-only books remain STATIC_ONLY and cannot authorize source closure.

The APK scanner reads DEX Android/libcore class, field, and method ID tables,
native method declarations, plus ARM ELF32
DT_NEEDED and imported symbols. It does not infer reachability, parse binary
layout resources, or invent dynamic reflection targets. Those findings remain
STATIC_REFERENCED.

An index entry is SOURCE_LOCATED when it names source files and symbols.
SOURCE_CLOSED additionally requires explicit closure_reviewed=true and
closure_evidence with source_sha256, reviewed_by, and closure_notes. That
evidence and the index's exact 40-character source revision must reflect
actual API19 source dependency review; the JNI table
index in this repository only locates entry symbols. Service observations
remain BOUNDARY_CANDIDATE until the excluded boundary is sourced and reviewed.

The current implementation does not provide an Android TRACE event producer,
Framework source closure, cluster ports, or iOS differential. Its output is
not proof that those stages are complete.
