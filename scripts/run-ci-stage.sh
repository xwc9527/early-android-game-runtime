#!/bin/bash
set -euo pipefail

if [[ $# -lt 2 ]]; then
  echo "usage: $0 <stage-name> <command> [args...]" >&2
  exit 2
fi

STAGE="$1"
shift
ARTIFACTS="${AGR_CI_ARTIFACTS:-build/artifacts}"
TIMINGS="$ARTIFACTS/ci-stage-timings.jsonl"
PROFILE="${AGR_SIMULATOR_PROFILE:-full}"
mkdir -p "$ARTIFACTS"
START="$(date -u +%s)"
printf 'AGR_CI_STAGE_START %s %s\n' "$STAGE" "$(date -u +%Y-%m-%dT%H:%M:%SZ)"
set +e
"$@"
STATUS=$?
set -e
END="$(date -u +%s)"
DURATION="$((END-START))"
printf '{"stage":"%s","job":"%s","profile":"%s","exit_code":%s,"duration_seconds":%s,"started_epoch":%s,"finished_epoch":%s}\n' \
  "$STAGE" "${GITHUB_JOB:-local}" "$PROFILE" "$STATUS" "$DURATION" "$START" "$END" >> "$TIMINGS"
printf 'AGR_CI_STAGE_RESULT {"stage":"%s","exit_code":%s,"duration_seconds":%s}\n' \
  "$STAGE" "$STATUS" "$DURATION"
exit "$STATUS"
