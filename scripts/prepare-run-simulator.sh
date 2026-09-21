#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PROFILE="${1:-full}"
ARTIFACTS="$ROOT/build/artifacts"
mkdir -p "$ARTIFACTS"
: > "$ARTIFACTS/ci-stage-timings.jsonl"
BOOT_LOG="$ARTIFACTS/simulator-boot.log"

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
python3 - "$BOOT_LOG" "$ARTIFACTS/ci-stage-timings.jsonl" "$PROFILE" "${GITHUB_JOB:-local}" <<'PY'
import datetime, json, pathlib, sys
log_path, timings_path, profile, job = sys.argv[1:]
requested = ready = None
for line in pathlib.Path(log_path).read_text(encoding="utf-8").splitlines():
    fields = line.split(maxsplit=2)
    if len(fields) != 3 or fields[0] != "AGR_SMOKE_PHASE":
        continue
    stamp = datetime.datetime.fromisoformat(fields[1].replace("Z", "+00:00"))
    event = fields[2].split()
    if event[:3] == ["simulator", "boot", "requested"]:
        requested = stamp
    elif event[:3] == ["simulator", "boot", "ready"]:
        ready = stamp
if requested is None or ready is None or ready < requested:
    raise SystemExit(f"missing or invalid Simulator boot markers in {log_path}")
duration = round((ready - requested).total_seconds())
record = {"stage":"simulator_boot_total", "job":job, "profile":profile,
          "exit_code":0, "duration_seconds":duration,
          "started_epoch":int(requested.timestamp()), "finished_epoch":int(ready.timestamp())}
with pathlib.Path(timings_path).open("a", encoding="utf-8") as out:
    out.write(json.dumps(record) + "\n")
print("AGR_CI_STAGE_RESULT " + json.dumps(record, sort_keys=True))
PY
BOOT_PID=""
trap - EXIT
record install bash "$ROOT/scripts/build-and-run-simulator.sh" install
cp "$ARTIFACTS/simulator-device.txt" "$ARTIFACTS/zero-input-device.txt"
printf 'AGR_CI_SETUP_COMPLETE profile=%s\n' "$PROFILE"
