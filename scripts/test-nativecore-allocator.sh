#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/allocator-test"; OBJ="$ROOT/build/allocator-obj"
rm -rf "$OBJ"; mkdir -p "$OBJ"
SAN=(-O1 -g -fsanitize=address,undefined); INC=(-I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore")
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Tests/NativeCore/allocator_test.c" -o "$OBJ/test.o"
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/NativeCore/agr_runtime.c" -o "$OBJ/runtime.o"
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Process/agr_guest_vma.c" -o "$OBJ/vma.o"
clang++ -std=gnu++98 -fno-exceptions -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_linker.cpp" -o "$OBJ/linker.o"
clang++ -std=gnu++98 -fno-exceptions -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_dynamic.cpp" -o "$OBJ/dynamic.o"
clang++ -std=gnu++98 -fno-exceptions -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_mmap.cpp" -o "$OBJ/mmap.o"
clang++ "${SAN[@]}" "$OBJ/test.o" "$OBJ/runtime.o" "$OBJ/vma.o" "$OBJ/linker.o" "$OBJ/dynamic.o" "$OBJ/mmap.o" -lm -o "$OUT"
"$OUT"
