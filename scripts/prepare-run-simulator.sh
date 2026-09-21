#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PROFILE="${1:-full}"
ARTIFACTS="$ROOT/build/artifacts"
mkdir -p "$ARTIFACTS"
: > "$ARTIFACTS/ci-stage-timings.jsonl"
BOOT_LOG="$ARTIFACTS/simulator-boot.log"
BOOT_STARTED="$(date -u +%s)"

record() {
  local name="$1" start end status
  shift
  start="$(date -u +%s)"
  printf 'AGR_CI_STAGE_START %s %s\n' "$name" "$(date -u +%Y-%m-%dT%H:%M:%SZ)"
  set +e
  "$@"
  status=$?
  set -e
  end="$(date -u +%s)"
  printf '{"stage":"%s","job":"%s","profile":"%s","exit_code":%s,"duration_seconds":%s,"started_epoch":%s,"finished_epoch":%s}\n' \
    "$name" "${GITHUB_JOB:-local}" "$PROFILE" "$status" "$((end-start))" "$start" "$end" >> "$ARTIFACTS/ci-stage-timings.jsonl"
  printf 'AGR_CI_STAGE_RESULT {"stage":"%s","exit_code":%s,"duration_seconds":%s}\n' \
    "$name" "$status" "$((end-start))"
  return "$status"
}

bash "$ROOT/scripts/build-and-run-simulator.sh" boot >"$BOOT_LOG" 2>&1 &
BOOT_PID=$!
cleanup() {
  if kill -0 "$BOOT_PID" 2>/dev/null; then
    kill "$BOOT_PID" 2>/dev/null || true
    wait "$BOOT_PID" 2>/dev/null || true
  fi
}
trap cleanup EXIT

record sample_preparation bash "$ROOT/scripts/build-and-run-simulator.sh" prepare "$PROFILE"
record dependency_preparation bash "$ROOT/scripts/build-and-run-simulator.sh" deps
record compile_link bash "$ROOT/scripts/build-and-run-simulator.sh" build
record simulator_boot_wait wait "$BOOT_PID"
BOOT_READY="$(date -u +%s)"
printf '{"stage":"simulator_boot_total","job":"%s","profile":"%s","exit_code":0,"duration_seconds":%s,"started_epoch":%s,"finished_epoch":%s}\n' \
  "${GITHUB_JOB:-local}" "$PROFILE" "$((BOOT_READY-BOOT_STARTED))" "$BOOT_STARTED" "$BOOT_READY" >> "$ARTIFACTS/ci-stage-timings.jsonl"
BOOT_PID=""
trap - EXIT
record install bash "$ROOT/scripts/build-and-run-simulator.sh" install
cp "$ARTIFACTS/simulator-device.txt" "$ARTIFACTS/zero-input-device.txt"
printf 'AGR_CI_SETUP_COMPLETE profile=%s\n' "$PROFILE"
