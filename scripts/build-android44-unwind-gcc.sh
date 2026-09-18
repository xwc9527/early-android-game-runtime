#!/bin/bash
# Compile the Android 4.4 EHABI oracle with NDK r10e GCC 4.8 libgcc.
# NDK r23+ Clang/LLVM libunwind is not a valid reference for this fixture.
#
# Two link layers:
#   A/B/C  — gcc -c, then the same toolchain's arm-linux-androideabi-ld -shared.
#            No GCC driver, CRT, -static-libgcc, libc, or libgcc on the link line.
#   probe/reference — GCC driver. probe uses -static-libgcc so _Unwind_Backtrace
#            is GCC 4.8 libgcc (__gnu_Unwind_Backtrace / __gnu_unwind_execute).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
NDK="${NDK_R10E:?NDK_R10E must point at an unpacked android-ndk-r10e tree}"
OUT="${UNWIND_OUT:-$ROOT/unwind}"
SYSROOT="$NDK/platforms/android-19/arch-arm"
PREBUILT="$(echo "$NDK"/toolchains/arm-linux-androideabi-4.8/prebuilt/*)"
CC="$PREBUILT/bin/arm-linux-androideabi-gcc"
LD="$PREBUILT/bin/arm-linux-androideabi-ld"
NM="$PREBUILT/bin/arm-linux-androideabi-nm"
READELF="$PREBUILT/bin/arm-linux-androideabi-readelf"
OBJDUMP="$PREBUILT/bin/arm-linux-androideabi-objdump"
test -x "$CC"
test -x "$LD"
test -x "$NM"
test -x "$READELF"
test -x "$OBJDUMP"
test -d "$SYSROOT"
mkdir -p "$OUT"

# GCC 4.8.5 invoke.texi: -c compiles and does not link.
COMPILE=(
  --sysroot="$SYSROOT"
  -march=armv7-a
  -mfloat-abi=softfp
  -mfpu=vfpv3-d16
  -fPIC
  -O0
  -fno-inline
  -fno-exceptions
  -funwind-tables
)

# GNU ld: --no-copy-dt-needed-entries is the default from binutils 2.22 (ld/NEWS).
# Pass it explicitly so C's link against probe does not copy probe's libc/libdl.
# --hash-style=sysv: KitKat AGR dynamic linker requires DT_HASH.
LD_SHARED=(
  -shared
  --hash-style=sysv
  --no-copy-dt-needed-entries
  -z relro
  -z now
  -L"$OUT"
)

DRIVER_COMMON=(
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

audit_exidx() {
  local so="$1"
  local size
  size="$("$READELF" -S -W "$so" | awk '{
    for (i = 1; i <= NF; i++) {
      if ($i == ".ARM.exidx") { print $(i + 4); exit }
    }
  }')"
  if [[ -z "$size" || "$size" == "000000" || "$size" == "0" ]]; then
    echo "$so: missing or empty .ARM.exidx" >&2
    "$READELF" -S -W "$so" >&2 || true
    exit 1
  fi
  if ! "$READELF" -l -W "$so" | grep -Eq '^[[:space:]]*(ARM_)?EXIDX[[:space:]]'; then
    echo "$so: missing PT_ARM_EXIDX" >&2
    "$READELF" -l -W "$so" >&2 || true
    exit 1
  fi
}

audit_unwind_decode() {
  local so="$1"
  local symbol="$2"
  local decoded
  if ! decoded="$("$READELF" --unwind -W "$so" 2>&1)"; then
    echo "$so: readelf --unwind failed" >&2
    echo "$decoded" >&2
    dump_elf_evidence "$so"
    exit 1
  fi
  if ! echo "$decoded" | grep -Eq "Unwind (section|table index) '.ARM.exidx'" ||
     ! echo "$decoded" | grep -q "<$symbol>" ||
     echo "$decoded" | grep -Eiq 'corrupt|cannot decode|failed to decode'; then
    echo "$so: no parseable unwind entry for $symbol" >&2
    echo "$decoded" >&2
    dump_elf_evidence "$so"
    exit 1
  fi
}

audit_dynamic_relocations() {
  local so="$1"
  local relocs
  relocs="$("$READELF" -r -W "$so" 2>&1)"
  if echo "$relocs" | grep -Eq '__aeabi_unwind_cpp_pr[012]'; then
    echo "$so: final dynamic relocations retain an EHABI personality dependency" >&2
    dump_elf_evidence "$so"
    exit 1
  fi
  if echo "$relocs" | grep -E 'R_ARM_NONE' | grep -Eq '__aeabi_unwind_cpp_pr[012]'; then
    echo "$so: final dynamic relocations retain an R_ARM_NONE personality marker" >&2
    dump_elf_evidence "$so"
    exit 1
  fi
}

audit_needed() {
  local so="$1"
  local expect="$2"
  local got
  got="$("$READELF" -d "$so" | awk -F'[][]' '/\(NEEDED\)/{print $2}' | tr '\n' ' ' | sed 's/[[:space:]]*$//')"
  if [[ "$got" != "$expect" ]]; then
    echo "$so: DT_NEEDED='$got' expected '$expect'" >&2
    "$READELF" -d "$so" >&2 || true
    exit 1
  fi
  if echo "$got" | grep -Eiq 'libc\.so|libdl\.so|libgcc|libstdc\+\+|libm\.so|liblog\.so'; then
    echo "$so: forbidden extra DT_NEEDED in '$got'" >&2
    exit 1
  fi
}

dump_elf_evidence() {
  local so="$1"
  echo "---- $so symbols ----" >&2
  "$READELF" -s -W "$so" >&2 || true
  echo "---- $so sections ----" >&2
  "$READELF" -S -W "$so" >&2 || true
  echo "---- $so dynamic ----" >&2
  "$READELF" -d "$so" >&2 || true
  echo "---- $so relocations ----" >&2
  "$READELF" -r -W "$so" >&2 || true
  echo "---- $so undefined ----" >&2
  "$NM" -D -u "$so" >&2 || true
  echo "---- $so .ARM.exidx ----" >&2
  "$OBJDUMP" -s -j .ARM.exidx "$so" >&2 || true
  echo "---- $so .ARM.extab ----" >&2
  "$OBJDUMP" -s -j .ARM.extab "$so" >&2 || true
  echo "---- $so decoded unwind ----" >&2
  "$READELF" --unwind -W "$so" >&2 || true
}

audit_undefined() {
  local so="$1"
  local allow="$2"
  local extra
  extra="$("$NM" -D -u "$so" 2>/dev/null | awk '{print $NF}' | grep -v "^${allow}$" || true)"
  if [[ -n "$extra" ]]; then
    echo "$so: extra undefined symbols; allowed only '$allow'" >&2
    echo "$extra" >&2
    dump_elf_evidence "$so"
    exit 1
  fi
}

# AAELF32: STT_FUNC Thumb symbols have odd st_value; ARM symbols have even.
# Mapping symbols $t/$a only confirm the function address falls in that
# half-open mapping region; the mapping address need not equal the entry.
audit_mode() {
  local so="$1"
  local sym="$2"
  local expect="$3"
  local value
  value="$("$READELF" -s -W "$so" | awk -v s="$sym" '$NF==s && /FUNC/ {print $2; exit}')"
  if [[ -z "$value" ]]; then
    echo "$so: missing FUNC symbol $sym" >&2
    "$READELF" -s -W "$so" >&2 || true
    exit 1
  fi
  local last=$((0x$value & 1))
  if [[ "$expect" == thumb && "$last" -ne 1 ]]; then
    echo "$so: $sym st_value=$value is even; AAELF32 Thumb FUNC must be odd" >&2
    dump_elf_evidence "$so"
    exit 1
  fi
  if [[ "$expect" == arm && "$last" -ne 0 ]]; then
    echo "$so: $sym st_value=$value is odd; AAELF32 ARM FUNC must be even" >&2
    dump_elf_evidence "$so"
    exit 1
  fi
  local func_addr=$((0x$value & ~1))
  local map
  map="$("$READELF" -s -W "$so" | awk -v addr="$func_addr" '
    function h2d(h, i, c, n) {
      n = 0
      h = tolower(h)
      gsub(/^0x/, "", h)
      for (i = 1; i <= length(h); i++) {
        c = substr(h, i, 1)
        n = n * 16 + index("0123456789abcdef", c) - 1
      }
      return n
    }
    $4=="NOTYPE" && $5=="LOCAL" && ($NF ~ /^\$a(\.|$)/ || $NF ~ /^\$t(\.|$)/ || $NF ~ /^\$d(\.|$)/) {
      v = h2d($2)
      if (v <= addr && v >= best) { best = v; name = $NF }
    }
    END { if (name != "") print name }
  ')"
  if [[ -z "$map" ]]; then
    echo "$so: no AAELF mapping symbol covers $sym at $value" >&2
    "$READELF" -s -W "$so" >&2 || true
    exit 1
  fi
  if [[ "$expect" == thumb && "$map" != \$t && "$map" != \$t.* ]]; then
    echo "$so: $sym mapping region is '$map', expected \$t (Thumb)" >&2
    "$READELF" -s -W "$so" >&2 || true
    exit 1
  fi
  if [[ "$expect" == arm && "$map" != \$a && "$map" != \$a.* ]]; then
    echo "$so: $sym mapping region is '$map', expected \$a (ARM)" >&2
    "$READELF" -s -W "$so" >&2 || true
    exit 1
  fi
}

"$CC" "${DRIVER_COMMON[@]}" -shared -Wl,--no-undefined -Wl,-soname,libagr_unwind_probe.so \
  "$ROOT/Tests/Android44Unwind/probe.c" -ldl -o "$OUT/libagr_unwind_probe.so"

"$CC" "${COMPILE[@]}" -mthumb -c "$ROOT/Tests/Android44Unwind/c.c" -o "$OUT/c.o"
"$CC" "${COMPILE[@]}" -marm -c "$ROOT/Tests/Android44Unwind/b.c" -o "$OUT/b.o"
"$CC" "${COMPILE[@]}" -mthumb -c "$ROOT/Tests/Android44Unwind/a.c" -o "$OUT/a.o"

"$LD" "${LD_SHARED[@]}" -soname libagr_unwind_C.so \
  -o "$OUT/libagr_unwind_C.so" "$OUT/c.o" -lagr_unwind_probe
"$LD" "${LD_SHARED[@]}" -soname libagr_unwind_B.so \
  -o "$OUT/libagr_unwind_B.so" "$OUT/b.o" -lagr_unwind_C
"$LD" "${LD_SHARED[@]}" -soname libagr_unwind_A.so \
  -o "$OUT/libagr_unwind_A.so" "$OUT/a.o" -lagr_unwind_B

"$CC" "${DRIVER_COMMON[@]}" -fPIE -pie "$ROOT/Tests/Android44Unwind/reference.c" -ldl \
  -o "$OUT/android44-unwind-reference"

audit_exidx "$OUT/libagr_unwind_A.so"
audit_exidx "$OUT/libagr_unwind_B.so"
audit_exidx "$OUT/libagr_unwind_C.so"
audit_unwind_decode "$OUT/libagr_unwind_A.so" A
audit_unwind_decode "$OUT/libagr_unwind_B.so" B
audit_unwind_decode "$OUT/libagr_unwind_C.so" C
audit_dynamic_relocations "$OUT/libagr_unwind_A.so"
audit_dynamic_relocations "$OUT/libagr_unwind_B.so"
audit_dynamic_relocations "$OUT/libagr_unwind_C.so"
audit_mode "$OUT/libagr_unwind_A.so" A thumb
audit_mode "$OUT/libagr_unwind_B.so" B arm
audit_mode "$OUT/libagr_unwind_C.so" C thumb
audit_needed "$OUT/libagr_unwind_A.so" "libagr_unwind_B.so"
audit_needed "$OUT/libagr_unwind_B.so" "libagr_unwind_C.so"
audit_needed "$OUT/libagr_unwind_C.so" "libagr_unwind_probe.so"
audit_undefined "$OUT/libagr_unwind_A.so" B
audit_undefined "$OUT/libagr_unwind_B.so" C
audit_undefined "$OUT/libagr_unwind_C.so" agr_unwind_probe

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
