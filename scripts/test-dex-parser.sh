#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"; BUILD="$ROOT/build/dex-parser-contract"
mkdir -p "$BUILD"
cc -std=c11 -O2 -D_POSIX_C_SOURCE=200809L -I"$ROOT/Runtime/DexLoom/Include" \
  "$ROOT/Tests/DexLoom/dex_parser_probe.c" \
  "$ROOT/Runtime/DexLoom/Base/dx_log.c" \
  "$ROOT/Runtime/DexLoom/Base/dx_memory.c" \
  "$ROOT/Runtime/DexLoom/Base/dx_arena.c" \
  "$ROOT/Runtime/DexLoom/DEX/dx_dex.c" -o "$BUILD/dex_parser_probe"
status=0
for dex in "$@"; do
  if ! "$BUILD/dex_parser_probe" "$dex"; then
    status=1
  fi
done
exit "$status"
