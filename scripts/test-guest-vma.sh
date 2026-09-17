#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/guest-vma-test"
mkdir -p "$ROOT/build"
clang -std=c11 -Wall -Wextra -Werror -O2 \
  -I"$ROOT/Runtime/Process" \
  "$ROOT/Tests/Process/guest_vma_test.c" \
  "$ROOT/Runtime/Process/agr_guest_vma.c" \
  -o "$OUT"
"$OUT"
