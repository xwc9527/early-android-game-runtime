#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/guest-fd-darwin-test"
mkdir -p "$ROOT/build"
clang -std=c11 -Wall -Wextra -Werror -O2 \
  -I"$ROOT/Runtime/HostServices" -I"$ROOT/Runtime/Process" \
  "$ROOT/Tests/Process/guest_fd_test.c" \
  "$ROOT/Runtime/Process/agr_guest_fd.c" \
  "$ROOT/Runtime/HostServices/agr_host_services_darwin.c" \
  -o "$OUT"
"$OUT"
