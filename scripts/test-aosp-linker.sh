#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/aosp-linker-test"
mkdir -p "$ROOT/build"
clang -std=c11 -Wall -Wextra -Werror -O2 \
  -I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" \
  -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore" \
  "$ROOT/Tests/AospLinker/aosp_linker_test.c" \
  "$ROOT/Runtime/AospLinker/agr_aosp_linker.c" \
  "$ROOT/Runtime/Bionic/agr_bionic_mmap.c" \
  "$ROOT/Runtime/Process/agr_guest_vma.c" -o "$OUT"
"$OUT"
