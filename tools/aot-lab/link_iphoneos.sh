#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
SDK="$(xcrun --sdk iphoneos --show-sdk-path)"
OUT="$ROOT/build/aot-iphoneos"
mkdir -p "$OUT"
clang -target arm64-apple-ios15.0 -isysroot "$SDK" -miphoneos-version-min=15.0 -O2 -std=c11 \
  -I"$ROOT/Runtime/AotLab" -c "$ROOT/Runtime/AotLab/agr_aot.c" -o "$OUT/agr_aot.o"
clang -target arm64-apple-ios15.0 -isysroot "$SDK" -miphoneos-version-min=15.0 -O2 -std=c11 \
  -I"$ROOT/Runtime/AotLab" -c "$ROOT/Runtime/AotLab/aot_blocks.c" -o "$OUT/aot_blocks.o"
clang -target arm64-apple-ios15.0 -isysroot "$SDK" -miphoneos-version-min=15.0 -r -nostdlib \
  "$OUT/agr_aot.o" "$OUT/aot_blocks.o" -o "$OUT/gloomy-aot-arm64.o"
file "$OUT/gloomy-aot-arm64.o"
otool -hv "$OUT/aot_blocks.o"
echo "IPHONEOS_AOT_LINK_OK"
