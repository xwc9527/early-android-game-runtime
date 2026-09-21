#!/usr/bin/env python3
"""Focused API19 first-traversal and original APK evidence contract."""

import argparse
import json
from pathlib import Path

ORDER = (
    "handoff.viewroot_traversal",
    "viewroot.traversal.consumed",
    "viewroot.do_traversal",
    "viewroot.perform_traversals.enter",
    "view.dispatch_attached_to_window",
    "viewroot.perform_measure",
    "window_session.relayout.enter",
    "window_session.surface.acquired",
    "window_session.relayout.return",
    "viewroot.perform_layout",
    "viewroot.traversal.completed",
    "viewroot.traversal.rescheduled",
    "handoff.viewroot_surface_ready",
)


def check_snapshot(snapshot, width, height):
    assert snapshot["hierarchy_attached"] is True, snapshot
    assert snapshot["traversal_count"] == 1, snapshot
    assert snapshot["traversal_phase"] == 1, snapshot  # new Surface schedules another pass
    assert snapshot["traversal_scheduled"] is True, snapshot
    assert snapshot["measured_width"] == width, snapshot
    assert snapshot["measured_height"] == height, snapshot
    assert snapshot["frame"] == [0, 0, width, height], snapshot
    assert snapshot["layout_complete"] is True, snapshot
    assert snapshot["surface_valid"] is True, snapshot
    assert snapshot["surface_generation"] == 1, snapshot
    assert not snapshot["pending_exception"] and not snapshot["error"], snapshot
    trace = snapshot["framework_trace"]
    positions = [trace.index(event) for event in ORDER]
    assert positions == sorted(positions), trace
    assert trace[-1] == ORDER[-1], trace


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("result", type=Path)
    args = parser.parse_args()
    result = json.loads(args.result.read_text(encoding="utf-8"))
    width, height = result["display_width"], result["display_height"]
    assert width > 0 and height > 0, result
    assert result["sample"] == "frozen-bubble", result
    assert result["launch_result"] == 0 and result["launch_stage"] == "resumed", result
    assert result["real_owner_graph"] is True, result
    assert result["traversal_result"] == 0, result
    assert result["classification"] == "viewroot_surface_ready", result
    contract = result["contract"]
    assert contract["passed"] is True and contract["traversal_result"] == 0, contract
    assert contract["second_traversal_result"] == 0, contract
    assert contract["surface_persistent"] is True, contract
    second = contract["second_traversal"]
    assert second["traversal_count"] == 2 and second["traversal_scheduled"] is False, second
    assert second["surface_generation"] == 1 and second["surface_valid"] is True, second
    assert contract["invalid_traversal_result"] != 0, contract
    assert contract["relayout_failure_result"] != 0, contract
    assert contract["relayout_failure_snapshot"]["surface_valid"] is False, contract
    assert contract["relayout_failure_snapshot"]["traversal_scheduled"] is True, contract
    assert contract["surface_failure_result"] != 0, contract
    assert contract["surface_failure_snapshot"]["surface_valid"] is False, contract
    assert contract["surface_failure_snapshot"]["traversal_scheduled"] is True, contract
    assert contract["retry_result"] == 0 and contract["retry_snapshot"]["surface_valid"] is True, contract
    check_snapshot(contract["after_traversal"], width, height)
    check_snapshot(result["after_snapshot"], width, height)
    print(json.dumps({"synthetic": "PASS", "real_apk": "PASS",
                      "terminal": ORDER[-1], "display": [width, height]}))


if __name__ == "__main__":
    main()
