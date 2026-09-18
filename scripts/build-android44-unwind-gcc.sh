#!/bin/bash
# Compile the Android 4.4 EHABI oracle with NDK r10e GCC 4.8 libgcc.
# NDK r23+ Clang/LLVM libunwind is not a valid reference for this fixture.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
NDK="${NDK_R10E:?NDK_R10E must point at an unpacked android-ndk-r10e tree}"
OUT="${UNWIND_OUT:-$ROOT/unwind}"
SYSROOT="$NDK/platforms/android-19/arch-arm"
PREBUILT="$(echo "$NDK"/toolchains/arm-linux-androideabi-4.8/prebuilt/*)"
CC="$PREBUILT/bin/arm-linux-androideabi-gcc"
NM="$PREBUILT/bin/arm-linux-androideabi-nm"
test -x "$CC"
test -d "$SYSROOT"
mkdir -p "$OUT"

COMMON=(
  --sysroot="$SYSROOT"
  -march=armv7-a
  -mfloat-abi=softfp
  -mfpu=vfpv3-d16
  -fPIC
  -O0
  -fno-inline
  -fno-exceptions
  -funwind-tables
  -static-libgcc
  -Wl,--hash-style=sysv
  -Wl,-z,relro
  -Wl,-z,now
  -L"$OUT"
)

"$CC" "${COMMON[@]}" -shared -Wl,--no-undefined -Wl,-soname,libagr_unwind_probe.so \
  "$ROOT/Tests/Android44Unwind/probe.c" -ldl -o "$OUT/libagr_unwind_probe.so"
"$CC" "${COMMON[@]}" -mthumb -shared -Wl,-soname,libagr_unwind_C.so \
  "$ROOT/Tests/Android44Unwind/c.c" -lagr_unwind_probe -o "$OUT/libagr_unwind_C.so"
"$CC" "${COMMON[@]}" -marm -shared -Wl,-soname,libagr_unwind_B.so \
  "$ROOT/Tests/Android44Unwind/b.c" -lagr_unwind_C -o "$OUT/libagr_unwind_B.so"
"$CC" "${COMMON[@]}" -mthumb -shared -Wl,-soname,libagr_unwind_A.so \
  "$ROOT/Tests/Android44Unwind/a.c" -lagr_unwind_B -o "$OUT/libagr_unwind_A.so"
"$CC" "${COMMON[@]}" -fPIE -pie "$ROOT/Tests/Android44Unwind/reference.c" -ldl \
  -o "$OUT/android44-unwind-reference"

if ! "$NM" -g "$OUT/libagr_unwind_probe.so" | grep -q ' __gnu_Unwind_Backtrace$'; then
  echo "libagr_unwind_probe.so does not contain GCC __gnu_Unwind_Backtrace" >&2
  "$NM" -g "$OUT/libagr_unwind_probe.so" >&2 || true
  exit 1
fi
if ! "$NM" -g "$OUT/libagr_unwind_probe.so" | grep -q ' __gnu_unwind_execute$'; then
  echo "libagr_unwind_probe.so does not contain GCC __gnu_unwind_execute" >&2
  exit 1
fi
if "$NM" -g "$OUT/libagr_unwind_probe.so" | grep -E ' unw_getcontext$| unw_init_local$'; then
  echo "libagr_unwind_probe.so looks like LLVM libunwind; GCC libgcc is required" >&2
  exit 1
fi
echo "GCC 4.8 ARM EHABI oracle: $OUT"
