#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/build/host-services-darwin-test"
mkdir -p "$ROOT/build"
clang -std=c11 -Wall -Wextra -Werror -O2 -pthread \
  -I"$ROOT/Runtime/HostServices" \
  "$ROOT/Tests/HostServices/darwin_contracts.c" \
  "$ROOT/Runtime/HostServices/agr_host_services_darwin.c" \
  -o "$OUT"
"$OUT"
