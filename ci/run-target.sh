#!/bin/bash
set -euo pipefail
TARGET="${1:-PVS1}"
case "$TARGET" in
  PVS1) exec bash scripts/run-simulator-regressions.sh ;;
  *) echo "unknown AGR target: $TARGET" >&2; exit 2 ;;
esac
