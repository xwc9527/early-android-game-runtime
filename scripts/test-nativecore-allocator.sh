#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/allocator-test"
mkdir -p "$ROOT/build"
clang -std=c11 -O1 -g -fsanitize=address,undefined \
  "$ROOT/Tests/NativeCore/allocator_test.c" \
  "$ROOT/Runtime/NativeCore/agr_runtime.c" \
  "$ROOT/Runtime/AospLinker/agr_aosp_linker.c" \
  "$ROOT/Runtime/Bionic/agr_bionic_mmap.c" \
  "$ROOT/Runtime/Process/agr_guest_vma.c" -lm -o "$OUT"
"$OUT"
