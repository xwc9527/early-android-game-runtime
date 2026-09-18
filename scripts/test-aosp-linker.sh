#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/aosp-linker-test"; OBJ="$ROOT/build/aosp-linker-obj"
mkdir -p "$ROOT/build"
rm -rf "$OBJ"; mkdir -p "$OBJ"
INC=(-I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore")
clang -std=c11 -Wall -Wextra -Werror -O2 "${INC[@]}" -c "$ROOT/Tests/AospLinker/aosp_linker_test.c" -o "$OBJ/test.o"
clang -std=c11 -Wall -Wextra -Werror -O2 "${INC[@]}" -c "$ROOT/Runtime/Process/agr_guest_vma.c" -o "$OBJ/vma.o"
clang -std=c11 -O2 "${INC[@]}" -c "$ROOT/Runtime/NativeCore/agr_runtime.c" -o "$OBJ/runtime.o"
if [[ "$(uname -s)" == Darwin ]]; then
  clang -std=c11 -O2 "${INC[@]}" -c "$ROOT/Runtime/HostServices/agr_host_services_darwin.c" -o "$OBJ/host-services.o"
  clang -std=c11 -O2 "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_thread_attr.c" -o "$OBJ/thread-attr.o"
  for SOURCE in agr_futex_host agr_bionic_sync agr_bionic_tls agr_bionic_errno_host agr_bionic_thread_lifecycle; do
    clang++ -std=c++17 -O2 -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/Bionic/$SOURCE.cpp" -o "$OBJ/$SOURCE.o"
  done
  BIONIC_OBJECTS=("$OBJ/host-services.o" "$OBJ/thread-attr.o" "$OBJ/agr_futex_host.o" "$OBJ/agr_bionic_sync.o" "$OBJ/agr_bionic_tls.o" "$OBJ/agr_bionic_errno_host.o" "$OBJ/agr_bionic_thread_lifecycle.o")
else
  BIONIC_OBJECTS=()
fi
clang++ -std=gnu++98 -Wall -Wextra -Werror -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_linker.cpp" -o "$OBJ/linker.o"
clang++ -std=gnu++98 -Wall -Wextra -Werror -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_dynamic.cpp" -o "$OBJ/dynamic.o"
clang++ -std=gnu++98 -Wall -Wextra -Werror -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_mmap.cpp" -o "$OBJ/mmap.o"
clang++ "$OBJ/test.o" "$OBJ/vma.o" "$OBJ/runtime.o" "$OBJ/linker.o" "$OBJ/dynamic.o" "$OBJ/mmap.o" "${BIONIC_OBJECTS[@]}" -pthread -lm -o "$OUT"
"$OUT"
