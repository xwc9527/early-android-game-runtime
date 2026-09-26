#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/allocator-test"; OBJ="$ROOT/build/allocator-obj"
rm -rf "$OBJ"; mkdir -p "$OBJ"
SAN=(-O1 -g -fsanitize=address,undefined); INC=(-I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore")
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Tests/NativeCore/allocator_test.c" -o "$OBJ/test.o"
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/NativeCore/agr_runtime.c" -o "$OBJ/runtime.o"
clang++ -std=c++17 -fno-exceptions -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_allocator.cpp" -o "$OBJ/allocator.o"
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Process/agr_guest_vma.c" -o "$OBJ/vma.o"
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/HostServices/agr_host_services_darwin.c" -o "$OBJ/host-services.o"
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_thread_attr.c" -o "$OBJ/thread-attr.o"
clang++ -std=gnu++98 -fno-exceptions -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_linker.cpp" -o "$OBJ/linker.o"
clang++ -std=gnu++98 -fno-exceptions -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_dynamic.cpp" -o "$OBJ/dynamic.o"
clang++ -std=gnu++98 -fno-exceptions -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_mmap.cpp" -o "$OBJ/mmap.o"
clang++ -std=c++17 -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_futex_host.cpp" -o "$OBJ/futex.o"
clang++ -std=c++17 -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_sync.cpp" -o "$OBJ/sync.o"
clang++ -std=c++17 -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_tls.cpp" -o "$OBJ/tls.o"
clang++ -std=c++17 -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_errno_host.cpp" -o "$OBJ/errno.o"
clang -std=c11 "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_clock.c" -o "$OBJ/clock.o"
clang++ -std=c++17 -fno-rtti "${SAN[@]}" "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_thread_lifecycle.cpp" -o "$OBJ/lifecycle.o"
clang++ "${SAN[@]}" "$OBJ/test.o" "$OBJ/runtime.o" "$OBJ/allocator.o" "$OBJ/vma.o" "$OBJ/host-services.o" "$OBJ/thread-attr.o" "$OBJ/linker.o" "$OBJ/dynamic.o" "$OBJ/mmap.o" "$OBJ/futex.o" "$OBJ/sync.o" "$OBJ/tls.o" "$OBJ/errno.o" "$OBJ/clock.o" "$OBJ/lifecycle.o" -pthread -lm -framework CoreFoundation -framework Security -o "$OUT"
"$OUT"
"$OUT" invalid-free
"$OUT" double-free
