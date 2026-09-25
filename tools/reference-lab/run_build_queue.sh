#!/usr/bin/env bash
# Resume both pinned builds in sequence and retain a one-line status.
set -euo pipefail

root=/agr-reference
scripts=/mnt/c/Users/47763/Documents/Codex/2026-09-25/he/work/agr-reference-audit/tools/reference-lab
jdk=$root/toolchains/zulu6.22.0.3-jdk6.0.119-linux_x64
make=$root/toolchains/make-3.82/install
clean_source=$root/aosp-official-sync-4.4.4-r2
trace_source=$root/aosp-trace-4.4.4-r2
clean_out=$root/clean-image/build-out
trace_out=$root/trace-image/build-out
status=$root/build-queue.status

printf 'CLEAN_RUNNING\n' > "$status"
if ! bash "$scripts/build_clean.sh" "$clean_source" "$jdk" "$make" "$clean_out" \
    > "$root/clean-image/build-resume.log" 2>&1; then
    printf 'CLEAN_FAILED\n' > "$status"
    exit 1
fi

printf 'TRACE_VM_RUNNING\n' > "$status"
if ! bash "$scripts/build_trace.sh" "$trace_source" "$jdk" "$make" \
    "$trace_out" "$clean_out" --vm-only > "$root/trace-image/vm-build-resume.log" 2>&1; then
    printf 'TRACE_VM_FAILED\n' > "$status"
    exit 1
fi

printf 'TRACE_FULL_RUNNING\n' > "$status"
if ! bash "$scripts/build_trace.sh" "$trace_source" "$jdk" "$make" \
    "$trace_out" "$clean_out" > "$root/trace-image/build.log" 2>&1; then
    printf 'TRACE_FULL_FAILED\n' > "$status"
    exit 1
fi

printf 'PAIR_VERIFY_RUNNING\n' > "$status"
if ! python3 "$scripts/record_pair.py" --clean-out "$clean_out" \
    --trace-out "$trace_out" --out "$root/reference-pair.json"; then
    printf 'PAIR_VERIFY_FAILED\n' > "$status"
    exit 1
fi
printf 'BUILD_PAIR_VERIFIED\n' > "$status"
