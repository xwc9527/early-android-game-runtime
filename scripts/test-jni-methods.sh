#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
mkdir -p "$ROOT/build"
clang -std=c11 -O1 -g -fsanitize=address,undefined \
  "$ROOT/Tests/GuestRuntime/jni_methods_test.c" \
  "$ROOT/Runtime/GuestRuntime/agr_jni_methods.c" \
  -o "$ROOT/build/jni-methods-test"
"$ROOT/build/jni-methods-test"
