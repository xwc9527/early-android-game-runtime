#!/usr/bin/env python3
"""Static contract for closure job isolation and explicit prerequisites."""

import pathlib
import re

ROOT = pathlib.Path(__file__).resolve().parents[1]
WORKFLOW = (ROOT / ".github/workflows/framework-activity-launch.yml").read_text(encoding="utf-8")


def require(value, message):
    if not value:
        raise AssertionError(message)


def main():
    for job in ("source-and-fixture:", "focused-simulator:", "runtime-regressions:", "iphoneos:", "closure-evidence:"):
        require(re.search(rf"^  {re.escape(job)}", WORKFLOW, re.MULTILINE), f"missing job {job}")
    require("needs: source-and-fixture" in WORKFLOW, "focused/runtime jobs must declare source prerequisite")
    require("name: Download isolated Runtime evidence" in WORKFLOW,
            "closure evidence must consume explicit Runtime artifact")
    require("--stage-results build/artifacts/closure-stage-results.json" in WORKFLOW,
            "closure summary must use declared job results")
    require("--runtime-prerequisite build/runtime-input/closure-prerequisite-failure.json" in WORKFLOW,
            "closure summary must classify missing Runtime prerequisites")
    require("framework-activity-simulator-results" in WORKFLOW and
            "framework-activity-runtime-regressions" in WORKFLOW,
            "focused and stable Runtime evidence must use separate artifacts")
    require("MISSING_PREREQUISITE" in (ROOT / "scripts/run-simulator-regressions.sh").read_text(encoding="utf-8"),
            "stable regression must enforce its own prerequisites")
    require("if: ${{ always()" in WORKFLOW, "closure evidence must run to classify incomplete stages")
    print("framework activity workflow contracts passed: isolated jobs and explicit prerequisites")


if __name__ == "__main__":
    main()
