#!/usr/bin/env bash
# Build a separate matched API19 ARM pair for APKs without x86 native code.
set -euo pipefail

root=/agr-reference
scripts=/mnt/c/Users/47763/Documents/Codex/2026-09-25/he/work/agr-reference-audit/tools/reference-lab
jdk=$root/toolchains/zulu6.22.0.3-jdk6.0.119-linux_x64
make=$root/toolchains/make-3.82/install
clean_source=$root/aosp-official-sync-4.4.4-r2
trace_source=$root/aosp-trace-4.4.4-r2
clean_out=$root/arm-clean-image/build-out
trace_out=$root/arm-trace-image/build-out
status=$root/arm-build-queue.status
export AGR_BUILD_TARGET=aosp_arm-eng

printf 'WAITING_FOR_X86_PAIR\n' > "$status"
while [[ $(cat "$root/build-queue.status") == TRACE_FULL_RUNNING ||
         $(cat "$root/build-queue.status") == PAIR_VERIFY_RUNNING ]]; do
    sleep 30
done
if [[ $(cat "$root/build-queue.status") != BUILD_PAIR_VERIFIED ]]; then
    printf 'X86_BUILD_NOT_VERIFIED\n' > "$status"
    exit 1
fi

mkdir -p "$root/arm-clean-image" "$root/arm-trace-image"
printf 'ARM_CLEAN_RUNNING\n' > "$status"
if ! bash "$scripts/build_clean.sh" "$clean_source" "$jdk" "$make" "$clean_out" \
    > "$root/arm-clean-image/build.log" 2>&1; then
    printf 'ARM_CLEAN_FAILED\n' > "$status"
    exit 1
fi

printf 'ARM_TRACE_VM_RUNNING\n' > "$status"
if ! bash "$scripts/build_trace.sh" "$trace_source" "$jdk" "$make" \
    "$trace_out" "$clean_out" --vm-only > "$root/arm-trace-image/vm-build.log" 2>&1; then
    printf 'ARM_TRACE_VM_FAILED\n' > "$status"
    exit 1
fi

printf 'ARM_TRACE_FULL_RUNNING\n' > "$status"
if ! bash "$scripts/build_trace.sh" "$trace_source" "$jdk" "$make" \
    "$trace_out" "$clean_out" > "$root/arm-trace-image/build.log" 2>&1; then
    printf 'ARM_TRACE_FULL_FAILED\n' > "$status"
    exit 1
fi

printf 'ARM_PAIR_VERIFY_RUNNING\n' > "$status"
if ! python3 "$scripts/record_pair.py" --arch arm --clean-out "$clean_out" \
    --trace-out "$trace_out" --out "$root/arm-reference-pair.json"; then
    printf 'ARM_PAIR_VERIFY_FAILED\n' > "$status"
    exit 1
fi
printf 'ARM_BUILD_PAIR_VERIFIED\n' > "$status"
