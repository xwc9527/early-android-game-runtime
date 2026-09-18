#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
NDK="${NDK_R10E:?NDK_R10E must point at Android NDK r10e}"
OUT="${EHABI2_GATE_OUT:-$ROOT/ehabi2-gate}"
PROJECT="$ROOT/Tests/Android44EhabiPhase2Gate"
PREBUILT="$(echo "$NDK"/toolchains/arm-linux-androideabi-4.8/prebuilt/*)"
READELF="$PREBUILT/bin/arm-linux-androideabi-readelf"
NM="$PREBUILT/bin/arm-linux-androideabi-nm"
OBJDUMP="$PREBUILT/bin/arm-linux-androideabi-objdump"
GXX="$PREBUILT/bin/arm-linux-androideabi-g++"
rm -rf "$OUT"
mkdir -p "$OUT/evidence"
"$GXX" --version > "$OUT/evidence/compiler-version.txt"
"$NDK/ndk-build" -C "$PROJECT" NDK_OUT="$OUT/obj" NDK_LIBS_OUT="$OUT/libs" -j2
ABI="$OUT/libs/armeabi-v7a"
test -x "$ABI/agr_eh2_reference"
for elf in "$ABI"/libagr_eh2_*.so "$ABI/agr_eh2_reference"; do
  base="$(basename "$elf")"
  "$READELF" -s -W "$elf" > "$OUT/evidence/$base.symbols.txt"
  "$READELF" -r -W "$elf" > "$OUT/evidence/$base.relocations.txt"
  "$READELF" -d -W "$elf" > "$OUT/evidence/$base.dynamic.txt"
  "$READELF" --unwind -W "$elf" > "$OUT/evidence/$base.unwind.txt"
  "$READELF" -S -W "$elf" > "$OUT/evidence/$base.sections.txt"
  "$OBJDUMP" -s -j .ARM.exidx "$elf" > "$OUT/evidence/$base.exidx.txt" 2>&1 || true
  "$OBJDUMP" -s -j .ARM.extab "$elf" > "$OUT/evidence/$base.extab.txt" 2>&1 || true
done
symbols='_Unwind_RaiseException _Unwind_Resume __gxx_personality_v0 __aeabi_unwind_cpp_pr0 __aeabi_unwind_cpp_pr1 __aeabi_unwind_cpp_pr2 __cxa_throw'
: > "$OUT/evidence/symbol-ownership.txt"
for elf in "$ABI"/*.so "$ABI/agr_eh2_reference"; do
  for symbol in $symbols; do
    if "$NM" -D --defined-only "$elf" 2>/dev/null | awk -v s="$symbol" '$NF==s {found=1} END{exit !found}'; then
      echo "DEFINED $(basename "$elf") $symbol" >> "$OUT/evidence/symbol-ownership.txt"
    fi
    if "$NM" -D -u "$elf" 2>/dev/null | awk -v s="$symbol" '$NF==s {found=1} END{exit !found}'; then
      echo "UNDEFINED $(basename "$elf") $symbol" >> "$OUT/evidence/symbol-ownership.txt"
    fi
  done
done
# Record static GCC ownership as well.  This distinguishes code copied into an
# output ELF from symbols supplied by gnustl_shared at Android load time.
while IFS= read -r archive; do
  for symbol in $symbols; do
    "$NM" -A --defined-only "$archive" 2>/dev/null | awk -v s="$symbol" -v a="$archive" \
      '$NF==s { print "ARCHIVE_DEFINED " a " " $0 }' \
      >> "$OUT/evidence/symbol-ownership.txt" || true
  done
done < <(find "$PREBUILT" -type f \( -name 'libgcc.a' -o -name 'libgcc_eh.a' \) | sort)

section_size() {
  "$READELF" -S -W "$1" | awk -v wanted="$2" '{
    for (i = 1; i <= NF; i++) {
      if ($i == wanted) { print $(i + 4); exit }
    }
  }'
}

for so in libagr_eh2_same.so libagr_eh2_A.so libagr_eh2_B.so libagr_eh2_C.so; do
  exidx_size="$(section_size "$ABI/$so" .ARM.exidx)"
  extab_size="$(section_size "$ABI/$so" .ARM.extab)"
  test -n "$exidx_size" && test "$exidx_size" != 0 && test "$exidx_size" != 000000
  test -n "$extab_size" && test "$extab_size" != 0 && test "$extab_size" != 000000
  grep -Eq "Unwind (section|table index) '.ARM.exidx'" "$OUT/evidence/$so.unwind.txt"
  ! grep -Eiq 'corrupt|cannot decode|failed to decode' "$OUT/evidence/$so.unwind.txt"
done

symbol_value() {
  "$READELF" -s -W "$1" | awk -v wanted="$2" '$4=="FUNC" && $NF==wanted { print $2; exit }'
}

cover_map() {
  local elf="$1" addr="$2" expect="$3" map
  map="$("$READELF" -s -W "$elf" | awk -v addr="$addr" '
    function h2d(h, i, c, n) {
      n=0; h=tolower(h); gsub(/^0x/,"",h)
      for (i=1;i<=length(h);i++) { c=substr(h,i,1); n=n*16+index("0123456789abcdef",c)-1 }
      return n
    }
    $4=="NOTYPE" && $5=="LOCAL" && ($NF ~ /^\$a(\.|$)/ || $NF ~ /^\$t(\.|$)/ || $NF ~ /^\$d(\.|$)/) {
      v=h2d($2); if (v<=addr && v>=best) { best=v; name=$NF }
    }
    END { if (name!="") print name }
  ')"
  test -n "$map"
  case "$expect" in
    thumb) [[ "$map" == \$t || "$map" == \$t.* ]] ;;
    arm) [[ "$map" == \$a || "$map" == \$a.* ]] ;;
  esac
}

SAME_VALUE="$(symbol_value "$ABI/libagr_eh2_same.so" agr_eh2_same_run)"
A_VALUE="$(symbol_value "$ABI/libagr_eh2_A.so" agr_eh2_cross_run)"
B_VALUE="$(symbol_value "$ABI/libagr_eh2_B.so" agr_eh2_B_call)"
C_VALUE="$(symbol_value "$ABI/libagr_eh2_C.so" agr_eh2_C_throw)"
test $((0x$SAME_VALUE & 1)) -eq 1
test $((0x$A_VALUE & 1)) -eq 1
test $((0x$B_VALUE & 1)) -eq 0
test $((0x$C_VALUE & 1)) -eq 1
cover_map "$ABI/libagr_eh2_same.so" $((0x$SAME_VALUE & ~1)) thumb
cover_map "$ABI/libagr_eh2_A.so" $((0x$A_VALUE & ~1)) thumb
cover_map "$ABI/libagr_eh2_B.so" $((0x$B_VALUE & ~1)) arm
cover_map "$ABI/libagr_eh2_C.so" $((0x$C_VALUE & ~1)) thumb

{
  for elf in "$ABI"/*.so "$ABI/agr_eh2_reference"; do
    echo "=== $(basename "$elf") ==="
    "$READELF" -d -W "$elf" | awk -F'[][]' '/\(NEEDED\)/ { print $2 }'
  done
} > "$OUT/evidence/dt-needed.txt"
echo "EHABI Phase 2 source/oracle fixture: $OUT"
