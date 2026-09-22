#!/usr/bin/env bash
# Compile IJG libjpeg and giflib for the iOS Simulator so KitKat SkImageDecoder
# can decode the same JPEG and GIF resources the Linux host contract decodes.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="${1:?output directory}"
SDK="${2:?sdk path}"
TARGET="${3:?clang target}"
JPEG_URL="https://www.ijg.org/files/jpegsrc.v9e.tar.gz"
JPEG_SHA="4077d6a6a75aeb01884f708919d25934c93305e49f7e3f36db9129320e6f4f3d"
GIF_URL="https://sourceforge.net/projects/giflib/files/giflib-5.2.2.tar.gz/download"
GIF_SHA="be7ffbd057cadebe2aa144542fd90c6838c6a083b5e8a9048b8ee3b66b29d5fb"
CACHE="$ROOT/build/image-codec-src"
mkdir -p "$OUT" "$CACHE"
fetch() {
  local url="$1" sha="$2" dest="$3"
  if [[ ! -s "$dest" ]] || ! echo "$sha  $dest" | shasum -a 256 -c - >/dev/null 2>&1; then
    curl -L --fail --retry 3 -o "$dest" "$url"
    echo "$sha  $dest" | shasum -a 256 -c -
  fi
}
fetch "$JPEG_URL" "$JPEG_SHA" "$CACHE/jpegsrc.v9e.tar.gz"
fetch "$GIF_URL" "$GIF_SHA" "$CACHE/giflib-5.2.2.tar.gz"
rm -rf "$CACHE/jpeg-9e" "$CACHE/giflib-5.2.2"
tar -xzf "$CACHE/jpegsrc.v9e.tar.gz" -C "$CACHE"
tar -xzf "$CACHE/giflib-5.2.2.tar.gz" -C "$CACHE"
cat > "$CACHE/jpeg-9e/jconfig.h" <<'EOF'
#define HAVE_PROTOTYPES
#define HAVE_UNSIGNED_CHAR
#define HAVE_UNSIGNED_SHORT
#undef CHAR_IS_UNSIGNED
#define HAVE_STDDEF_H
#define HAVE_STDLIB_H
#undef NEED_BSD_STRINGS
#undef NEED_SYS_TYPES_H
#undef NEED_FAR_POINTERS
#undef NEED_SHORT_EXTERNAL_NAMES
#undef INCOMPLETE_TYPES_BROKEN
typedef unsigned char boolean;
#define HAVE_BOOLEAN
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifdef JPEG_INTERNALS
#undef RIGHT_SHIFT_IS_UNSIGNED
#endif
EOF
COMMON=(-target "$TARGET" -isysroot "$SDK" -mios-simulator-version-min=15.0 -O2 -w)
: > "$OUT/objects.list"
i=0
for SOURCE in "$CACHE/jpeg-9e"/*.c; do
  base="$(basename "$SOURCE")"
  case "$base" in cjpeg.c|djpeg.c|jpegtran.c|rdjpgcom.c|wrjpgcom.c|ckconfig.c|jmemdos.c|jmemmac.c|jmemansi.c|example.c) continue;; esac
  clang "${COMMON[@]}" -I"$CACHE/jpeg-9e" -c "$SOURCE" -o "$OUT/jpeg-$i.o"
  printf '%s\n' "$OUT/jpeg-$i.o" >> "$OUT/objects.list"
  i=$((i + 1))
done
for base in dgif_lib.c egif_lib.c gifalloc.c gif_err.c gif_hash.c openbsd-reallocarray.c; do
  clang "${COMMON[@]}" -I"$CACHE/giflib-5.2.2" -c "$CACHE/giflib-5.2.2/$base" -o "$OUT/gif-$base.o"
  printf '%s\n' "$OUT/gif-$base.o" >> "$OUT/objects.list"
done
printf '%s\n' "$CACHE/jpeg-9e" > "$OUT/jpeg-include"
printf '%s\n' "$CACHE/giflib-5.2.2" > "$OUT/gif-include"
echo "simulator image codecs: $(wc -l < "$OUT/objects.list") objects"
