#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
NDK="${NDK_R10E:?NDK_R10E must point at Android NDK r10e}"
OUT="${EHABI2B_GATE_OUT:-$ROOT/ehabi2b-gate}"
PROJECT="$ROOT/Tests/Android44EhabiPhase2BGate"
PREBUILT="$(echo "$NDK"/toolchains/arm-linux-androideabi-4.8/prebuilt/*)"
READELF="$PREBUILT/bin/arm-linux-androideabi-readelf"
NM="$PREBUILT/bin/arm-linux-androideabi-nm"
OBJDUMP="$PREBUILT/bin/arm-linux-androideabi-objdump"
rm -rf "$OUT"; mkdir -p "$OUT/evidence"
"$NDK/ndk-build" -C "$PROJECT" NDK_OUT="$OUT/obj" NDK_LIBS_OUT="$OUT/libs" -j2
ABI="$OUT/libs/armeabi-v7a"; test -x "$ABI/agr_eh2b_reference"
for elf in "$ABI"/*.so "$ABI/agr_eh2b_reference"; do
  base="$(basename "$elf")"
  "$READELF" -s -W "$elf" > "$OUT/evidence/$base.symbols.txt"
  "$READELF" -r -W "$elf" > "$OUT/evidence/$base.relocations.txt"
  "$READELF" -d -W "$elf" > "$OUT/evidence/$base.dynamic.txt"
  "$READELF" --unwind -W "$elf" > "$OUT/evidence/$base.unwind.txt"
  "$READELF" -S -W "$elf" > "$OUT/evidence/$base.sections.txt"
  "$OBJDUMP" -s -j .ARM.exidx "$elf" > "$OUT/evidence/$base.exidx.txt" 2>&1 || true
  "$OBJDUMP" -s -j .ARM.extab "$elf" > "$OUT/evidence/$base.extab.txt" 2>&1 || true
done
symbols='__cxa_allocate_exception __cxa_free_exception __cxa_throw __cxa_type_match __cxa_begin_catch __cxa_end_catch __cxa_rethrow __cxa_get_globals __cxa_get_globals_fast __cxa_current_exception_type __gxx_personality_v0 _Unwind_RaiseException _Unwind_Resume __aeabi_unwind_cpp_pr0 __aeabi_unwind_cpp_pr1 __aeabi_unwind_cpp_pr2'
: > "$OUT/evidence/symbol-ownership.txt"
for elf in "$ABI"/*.so "$ABI/agr_eh2b_reference"; do
  for symbol in $symbols; do
    "$NM" -D --defined-only "$elf" 2>/dev/null | awk -v s="$symbol" -v f="$(basename "$elf")" '$NF==s{print "DEFINED " f " " s}' >> "$OUT/evidence/symbol-ownership.txt" || true
    "$NM" -D -u "$elf" 2>/dev/null | awk -v s="$symbol" -v f="$(basename "$elf")" '$NF==s{print "UNDEFINED " f " " s}' >> "$OUT/evidence/symbol-ownership.txt" || true
  done
done
for so in libagr_eh2b_suite.so libagr_eh2b_C.so libagr_eh2b_B.so libagr_eh2b_A.so; do
  grep -Eq "Unwind (section|table index) '.ARM.exidx'" "$OUT/evidence/$so.unwind.txt"
  ! grep -Eiq 'corrupt|cannot decode|failed to decode' "$OUT/evidence/$so.unwind.txt"
done
for symbol in _ZTI4Base _ZTI4Left _ZTI5Right _ZTI7Derived _ZTI5Wrong; do
  "$NM" -D --defined-only "$ABI/libagr_eh2b_types.so" | awk -v s="$symbol" '$NF==s{found=1}END{exit !found}'
done
"$READELF" -s -W "$ABI/libagr_eh2b_types.so" | grep -E '_ZTI|_ZTS|_ZTV' > "$OUT/evidence/rtti-symbols.txt"
"$READELF" -r -W "$ABI/libagr_eh2b_suite.so" "$ABI/libagr_eh2b_A.so" "$ABI/libagr_eh2b_C.so" | grep -E '_ZTI|_ZTV|_ZTS' > "$OUT/evidence/rtti-relocations.txt" || true
for tuple in 'libagr_eh2b_A.so:libagr_eh2b_B.so' 'libagr_eh2b_B.so:libagr_eh2b_C.so' 'libagr_eh2b_C.so:libagr_eh2b_types.so' 'libagr_eh2b_suite.so:libagr_eh2b_types.so'; do
  so="${tuple%%:*}"; need="${tuple#*:}"
  "$READELF" -d -W "$ABI/$so" | awk -F'[][]' '/\(NEEDED\)/{print $2}' | grep -qx "$need"
done
value(){ "$READELF" -s -W "$1" | awk -v s="$2" '$4=="FUNC"&&$NF==s{print $2;exit}'; }
AV="$(value "$ABI/libagr_eh2b_A.so" agr_eh2b_cross)"; BV="$(value "$ABI/libagr_eh2b_B.so" agr_eh2b_B_call)"; CV="$(value "$ABI/libagr_eh2b_C.so" agr_eh2b_C_throw)"
test $((0x$AV&1)) -eq 1; test $((0x$BV&1)) -eq 0; test $((0x$CV&1)) -eq 1
printf 'A=%s thumb\nB=%s arm\nC=%s thumb\n' "$AV" "$BV" "$CV" > "$OUT/evidence/arm-thumb-modes.txt"
echo "EHABI Phase 2B source/oracle fixture: $OUT"
