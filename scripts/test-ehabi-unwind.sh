#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/ehabi-unwind-test"; OBJ="$ROOT/build/ehabi-unwind-obj"
mkdir -p "$ROOT/build"
rm -rf "$OBJ"; mkdir -p "$OBJ"
if ! command -v cargo >/dev/null 2>&1; then
  echo "cargo is required to build the ARM interpreter for EHABI unwind contracts" >&2
  exit 1
fi
INC=(-I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore" -I"$ROOT/Runtime/Ehabi" -I"$ROOT/Runtime/GuestRuntime")
cargo build --manifest-path "$ROOT/Runtime/ArmInterpreter/Cargo.toml" --release
INTERP="$ROOT/Runtime/ArmInterpreter/target/release/libtouchhle_arm_interpreter.a"
clang -std=c11 -Wall -Wextra -Werror -O2 "${INC[@]}" -c "$ROOT/Tests/Ehabi/ehabi_unwind_test.c" -o "$OBJ/test.o"
clang -std=c11 -Wall -Wextra -Werror -O2 "${INC[@]}" -c "$ROOT/Runtime/Ehabi/agr_ehabi.c" -o "$OBJ/ehabi.o"
clang -std=c11 -O2 "${INC[@]}" -c "$ROOT/Runtime/Process/agr_guest_vma.c" -o "$OBJ/vma.o"
clang -std=c11 -O2 "${INC[@]}" -c "$ROOT/Runtime/NativeCore/agr_runtime.c" -o "$OBJ/runtime.o"
clang++ -std=c++17 -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_allocator.cpp" -o "$OBJ/allocator.o"
clang++ -std=gnu++98 -Wall -Wextra -Werror -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_linker.cpp" -o "$OBJ/linker.o"
clang++ -std=gnu++98 -Wall -Wextra -Werror -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/AospLinker/agr_aosp_dynamic.cpp" -o "$OBJ/dynamic.o"
clang++ -std=gnu++98 -Wall -Wextra -Werror -O2 -fno-exceptions -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_mmap.cpp" -o "$OBJ/mmap.o"
if [[ "$(uname -s)" == Darwin ]]; then
  clang -std=c11 -O2 "${INC[@]}" -c "$ROOT/Runtime/HostServices/agr_host_services_darwin.c" -o "$OBJ/host-services.o"
  clang -std=c11 -O2 "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_thread_attr.c" -o "$OBJ/thread-attr.o"
  for SOURCE in agr_futex_host agr_bionic_sync agr_bionic_tls agr_bionic_errno_host agr_bionic_thread_lifecycle; do
    clang++ -std=c++17 -O2 -fno-rtti "${INC[@]}" -c "$ROOT/Runtime/Bionic/$SOURCE.cpp" -o "$OBJ/$SOURCE.o"
  done
  clang -std=c11 -O2 "${INC[@]}" -c "$ROOT/Runtime/Bionic/agr_bionic_clock.c" -o "$OBJ/agr_bionic_clock.o"
  EXTRA=("$OBJ/host-services.o" "$OBJ/thread-attr.o" "$OBJ/agr_futex_host.o" "$OBJ/agr_bionic_sync.o" "$OBJ/agr_bionic_tls.o" "$OBJ/agr_bionic_errno_host.o" "$OBJ/agr_bionic_clock.o" "$OBJ/agr_bionic_thread_lifecycle.o" -framework CoreFoundation -framework Security)
else
  EXTRA=()
fi
clang++ "$OBJ/test.o" "$OBJ/ehabi.o" "$OBJ/vma.o" "$OBJ/runtime.o" "$OBJ/allocator.o" "$OBJ/linker.o" "$OBJ/dynamic.o" "$OBJ/mmap.o" "${EXTRA[@]}" "$INTERP" -pthread -ldl -lm -o "$OUT"
"$OUT"
