#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/aosp-linker-test"; OBJ="$ROOT/build/aosp-linker-obj"
mkdir -p "$ROOT/build"
rm -rf "$OBJ"; mkdir -p "$OBJ"
INC=(-I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore")
clang -std=c11 -Wall -Wextra -Werror -O2 "${INC[@]}" -c "$ROOT/Tests/AospLinker/aosp_linker_test.c" -o "$OBJ/test.o"
clang -std=c11 -Wall -Wextra -Werror -O2 "${INC[@]}" -c "$ROOT/Runtime/Process/agr_guest_vma.c" -o "$OBJ/vma.o"
clang++ -std=gnu++98 -Wall -Wextra -Werror -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_linker.cpp" -o "$OBJ/linker.o"
clang++ -std=gnu++98 -Wall -Wextra -Werror -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_mmap.cpp" -o "$OBJ/mmap.o"
clang++ "$OBJ/test.o" "$OBJ/vma.o" "$OBJ/linker.o" "$OBJ/mmap.o" -o "$OUT"
"$OUT"
