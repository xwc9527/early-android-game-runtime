#!/usr/bin/env bash
set -euo pipefail
root=/agr-reference
scripts=/mnt/c/Users/47763/Documents/Codex/2026-09-25/he/work/agr-reference-audit/tools/reference-lab
status=$root/build-queue.status
printf 'TRACE_FULL_RUNNING\n' > "$status"
if ! bash "$scripts/build_trace.sh" "$root/aosp-trace-4.4.4-r2" \
    "$root/toolchains/zulu6.22.0.3-jdk6.0.119-linux_x64" \
    "$root/toolchains/make-3.82/install" "$root/trace-image/build-out" \
    "$root/clean-image/build-out" > "$root/trace-image/build-resume-2.log" 2>&1; then
    printf 'TRACE_FULL_FAILED\n' > "$status"
    exit 1
fi
printf 'PAIR_VERIFY_RUNNING\n' > "$status"
if ! python3 "$scripts/record_pair.py" --clean-out "$root/clean-image/build-out" \
    --trace-out "$root/trace-image/build-out" --out "$root/reference-pair.json" \
    > "$root/pair-verify.log" 2>&1; then
    printf 'PAIR_VERIFY_FAILED\n' > "$status"
    exit 1
fi
printf 'BUILD_PAIR_VERIFIED\n' > "$status"
