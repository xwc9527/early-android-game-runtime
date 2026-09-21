#!/usr/bin/env python3
"""Validate the actual synthetic and unchanged-APK ViewRoot attach result."""
import argparse
import json
from pathlib import Path

ORDER = (
    "window_manager.add_view.enter",
    "window_manager_global.add_view",
    "viewroot.create",
    "viewroot.set_view.enter",
    "viewroot.root_assigned",
    "viewroot.request_layout",
    "viewroot.traversal.scheduled",
    "window_session.add_to_display",
    "viewroot.parent_assigned",
    "viewroot.attach.complete",
    "handoff.viewroot_traversal",
)
FLAGS = (
    "viewroot_created", "viewroot_root_assigned", "traversal_scheduled",
    "window_session_attached", "view_parent_assigned", "viewroot_attach_completed",
)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("result", type=Path)
    args = parser.parse_args()
    result = json.loads(args.result.read_text(encoding="utf-8"))
    contract = result["contract"]
    snapshot = result["after_snapshot"]
    trace = snapshot["framework_trace"]
    synthetic_trace = contract["framework_trace"]
    positions = [trace.index(event) for event in ORDER]
    assert positions == sorted(positions), trace
    assert trace[-1] == ORDER[-1], trace
    synthetic_positions = [synthetic_trace.index(event) for event in ORDER]
    assert synthetic_positions == sorted(synthetic_positions), synthetic_trace
    assert synthetic_trace[-1] == ORDER[-1], synthetic_trace
    assert contract["passed"] is True, contract
    assert contract["owner_graph"] is True and result["real_owner_graph"] is True, result
    assert all(contract.get(field) == 1 for field in FLAGS), contract
    assert all(snapshot.get(field) == 1 for field in FLAGS), snapshot
    assert all(snapshot.get(field) == 1 for field in
               ("window_attached", "window_added", "window_visible", "idle_handler_scheduled")), snapshot
    assert result["sample"] == "frozen-bubble" and result["launch_result"] == 0, result
    assert result["classification"] == "viewroot_traversal_handoff", result
    assert not snapshot["pending_exception"] and not snapshot["error"], snapshot
    print(json.dumps({"synthetic": "PASS", "real_apk": "PASS", "terminal": ORDER[-1]}))

if __name__ == "__main__":
    main()
