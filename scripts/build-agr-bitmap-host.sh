#!/usr/bin/env bash
# Build KitKat SkImageDecoder (PNG/JPEG/GIF) + agr_bitmap for Linux host contracts.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="${1:-/tmp/agr-bitmap-host}"
AOSP="$ROOT/Vendor/AOSP"
BITMAP="$ROOT/Runtime/Bitmap"
AFW="$ROOT/Runtime/AndroidFw"
SKIA="$AOSP/skia"
PNG="$AOSP/libpng"
ZLIB="$AOSP/zlib"
mkdir -p "$OUT"
COMMON=(-O1 -fPIC -ffunction-sections -fdata-sections)
SKIA_INCLUDES=(-I"$BITMAP" -I"$SKIA/include/core" -I"$SKIA/include/images" -I"$SKIA/include/utils"
  -I"$SKIA/src/core" -I"$SKIA/src/image" -I"$SKIA/src/images" -I"$SKIA/src/utils" -I"$PNG" -I"$ZLIB")
CXXFLAGS=("${COMMON[@]}" -std=gnu++98 -nostdinc++ -I"$AFW/compat/include" -w -fno-exceptions -fno-rtti
  -include "$BITMAP/host_skia_config.h" "${SKIA_INCLUDES[@]}")

for SOURCE in "$PNG"/*.c "$ZLIB"/*.c; do
  base="$(basename "$SOURCE")"
  case "$base" in example.c|pngtest.c) continue;; esac
  cc "${COMMON[@]}" -w -UMACOS -I"$PNG" -I"$ZLIB" -c "$SOURCE" -o "$OUT/codec-${base%.c}.o"
done

SKIA_SOURCES=(
  "$BITMAP/agr_bitmap.cpp"
  "$SKIA/src/core/Sk64.cpp" "$SKIA/src/core/SkBitmap.cpp" "$SKIA/src/core/SkColor.cpp"
  "$SKIA/src/core/SkColorTable.cpp" "$SKIA/src/core/SkDebug.cpp" "$SKIA/src/core/SkDither.cpp"
  "$SKIA/src/core/SkError.cpp" "$SKIA/src/core/SkFlattenable.cpp" "$SKIA/src/core/SkImageInfo.cpp"
  "$SKIA/src/core/SkMallocPixelRef.cpp" "$SKIA/src/core/SkMath.cpp" "$SKIA/src/core/SkPixelRef.cpp"
  "$SKIA/src/core/SkStream.cpp" "$SKIA/src/core/SkString.cpp" "$SKIA/src/core/SkTLS.cpp"
  "$SKIA/src/core/SkTSearch.cpp" "$SKIA/src/core/SkUnPreMultiply.cpp" "$SKIA/src/core/SkUtils.cpp"
  "$SKIA/src/images/SkImageDecoder.cpp" "$SKIA/src/images/SkImageDecoder_FactoryDefault.cpp"
  "$SKIA/src/images/SkImageDecoder_FactoryRegistrar.cpp" "$SKIA/src/images/SkImageDecoder_libpng.cpp"
  "$SKIA/src/images/SkJpegUtility.cpp"
  "$BITMAP/host/SkImageDecoder_libjpeg_host.cpp"
  "$BITMAP/host/SkImageDecoder_libgif_host.cpp"
  "$SKIA/src/images/SkImageEncoder.cpp" "$SKIA/src/images/SkImageEncoder_Factory.cpp"
  "$SKIA/src/images/SkScaledBitmapSampler.cpp"
  "$SKIA/src/opts/SkUtils_opts_none.cpp"
  "$SKIA/src/ports/SkDebug_stdio.cpp" "$SKIA/src/ports/SkMemory_malloc.cpp"
  "$SKIA/src/ports/SkThread_pthread.cpp" "$SKIA/src/ports/SkTLS_pthread.cpp"
)
i=0
for SOURCE in "${SKIA_SOURCES[@]}"; do
  c++ "${CXXFLAGS[@]}" -c "$SOURCE" -o "$OUT/skia-$i.o"
  i=$((i + 1))
done
printf '%s\n' "$OUT"/*.o > "$OUT/objects.list"
echo "agr-bitmap-host objects: $i skia + codecs in $OUT"
