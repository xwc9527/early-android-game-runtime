#!/usr/bin/env python3
"""Host and normal-path contracts for Runtime traversal dispatch."""

import argparse
import json
from pathlib import Path


def require(condition, detail):
    if not condition:
        raise SystemExit(f"traversal dispatch contract failed: {detail}")


def flag(value):
    """NSJSONSerialization boxes some ObjC expressions as 0/1."""
    return value is True or value == 1


def clear(value):
    return value is False or value == 0


def check_host(result):
    require(result.get("passed") is True, result)
    require(result["frame1"]["traversal_count"] == 1, result["frame1"])
    require(result["frame1"]["draw_count"] == 0, result["frame1"])
    require(result["frame1"]["traversal_scheduled"] is True, result["frame1"])
    require(result["frame1"]["surface_generation"] == 1, result["frame1"])
    require(result["frame2"]["traversal_count"] == 2, result["frame2"])
    require(result["frame2"]["draw_count"] == 1, result["frame2"])
    require(result["frame2"]["traversal_scheduled"] is False, result["frame2"])
    require(result["frame2"]["same_backing"] is True, result["frame2"])
    require(result["frame3"]["result"] == 1, result["frame3"])
    require(result["frame3"]["traversal_count"] == 2, result["frame3"])
    require(result["after_start"]["traversal_count"] == 0, result["after_start"])
    require(result["after_start"]["traversal_scheduled"] is True, result["after_start"])
    closed = result["closed_explicit"]
    require(closed["first_terminal"] == "handoff.viewroot_surface_ready", closed)
    require(closed["first_draw_count"] == 0 and closed["second_draw_count"] == 1, closed)
    require(result["relayout_failure_result"] != 0, result)
    require(result["relayout_failure_scheduled"] is True, result)
    require(result["relayout_failure_surface_valid"] is False, result)
    layout = result["layout_install"]
    require(layout["content_view_installed"] is True, layout)
    require(layout["content_child_count"] == 1, layout)
    require(layout["content_first_child_id"] == 0x7F060001, layout)
    require(layout["content_layout_width"] == -1 and layout["content_layout_height"] == -1, layout)
    require(layout["traversal_count"] == 0 and layout["traversal_scheduled"] is True, layout)
    require(layout["draw_count"] == 0, layout)
    surface = result["surface_callback"]
    require(surface["created_count"] == 1 and surface["changed_count"] == 1, surface)
    require(surface["callback_count"] == 1 and surface["generation"] == 1, surface)
    require(surface["width"] == result["display"][0] and surface["height"] == result["display"][1], surface)
    require(surface["format"] == 4 and surface["valid"] is True, surface)
    require(surface["owner_id"] == 0x7F060010, surface)
    require(surface["identity_differs_from_root"] is True, surface)
    require(surface["repeat_created_count"] == 1, surface)
    require(surface["static_created"] == 1 and surface["static_changed"] == 1, surface)
    require(surface["static_format"] == 4, surface)
    require(surface["static_width"] == result["display"][0], surface)
    require(surface["static_height"] == result["display"][1], surface)
    hidden = result["surface_hidden"]
    require(hidden["valid"] is False and hidden["created_count"] == 0 and hidden["callback_count"] == 1, hidden)
    zero = result["surface_zero"]
    require(zero["valid"] is False and zero["created_count"] == 0 and zero["callback_count"] == 1, zero)
    removed = result["surface_removed"]
    require(removed["valid"] is True and removed["created_count"] == 0 and removed["callback_count"] == 0, removed)
    require(removed["generation"] == 1, removed)
    failed = result["surface_alloc_failed"]
    require(failed["valid"] is False and failed["created_count"] == 0 and failed["root_valid"] is True, failed)


def ordered(trace, events):
    positions = [trace.index(event) for event in events]
    require(positions == sorted(positions) and len(set(positions)) == len(positions), trace)


def check_discovery(result):
    require(result.get("display_width") == 1080, result.get("display_width"))
    require(result.get("display_height") == 2340, result.get("display_height"))
    require(result.get("sample") == "frozen-bubble", result.get("sample"))
    require(result.get("consumer") == "uikit-cadisplaylink", result.get("consumer"))
    require(clear(result.get("harness_called_do_traversal")), result)
    require(result.get("host_vsync_count", 0) >= 2, result.get("host_vsync_count"))
    require(result.get("launch_result") == 0, result.get("launch_result"))
    require(result.get("launch_stage") == "resumed", result.get("launch_stage"))
    require(flag(result.get("real_owner_graph")), result)
    require(result.get("classification") == "viewroot_draw_entered", result.get("classification"))
    before = result["resume_snapshot"]
    require(before["traversal_count"] == 0 and flag(before["traversal_scheduled"]), before)
    require(before["draw_count"] == 0 and clear(before["surface_valid"]), before)
    require(flag(before.get("content_view_installed")), before)
    require(before.get("content_layout_width") == -1, before)
    require(before.get("content_layout_height") == -1, before)
    require(before.get("content_child_count", 0) >= 1, before)
    frames = result["frames"]
    require(len(frames) >= 2, frames)
    first, second = frames[0], frames[1]
    require(first["traversal_count"] == 1 and first["draw_count"] == 0, first)
    require(first.get("content_surface_created_count", 0) == 0, first)
    require(flag(first["surface_valid"]) and flag(first["traversal_scheduled"]), first)
    require(first["surface_generation"] == 1, first)
    require(second["traversal_count"] == 2 and second["draw_count"] >= 1, second)
    require(clear(second["traversal_scheduled"]) and second["surface_generation"] == 1, second)
    require(flag(second["surface_valid"]), second)
    require(flag(second.get("content_surface_valid")), second)
    require(second.get("content_surface_created_count") == 1, second)
    require(second.get("content_surface_changed_count") == 1, second)
    require(second.get("content_surface_generation") == 1, second)
    require(second.get("content_surface_callback_count", 0) >= 1, second)
    require(second.get("content_surface_identity") not in (0, None), second)
    require(second.get("content_surface_identity") != second.get("root_surface_identity"), second)
    require("surface_holder.surface_created" in second["framework_trace"], second["framework_trace"])
    require(second["framework_trace"].index("surface_holder.surface_created") <
            second["framework_trace"].index("viewroot.perform_draw"), second["framework_trace"])
    after = result["after_snapshot"]
    require(after["traversal_count"] == 2 and after["draw_count"] >= 1, after)
    require(flag(after["surface_valid"]) and clear(after["traversal_scheduled"]), after)
    content = {
        "harness_called_do_traversal": result.get("harness_called_do_traversal"),
        "harness_called_render_api": result.get("harness_called_render_api"),
        "content_surface_created_count": after.get("content_surface_created_count"),
        "content_surface_changed_count": after.get("content_surface_changed_count"),
        "canvas_lock_count": after.get("canvas_lock_count"),
        "canvas_draw_bitmap_count": after.get("canvas_draw_bitmap_count"),
        "canvas_pixel_change_count": after.get("canvas_pixel_change_count"),
        "canvas_post_count": after.get("canvas_post_count"),
        "canvas_buffer_hash_before": after.get("canvas_buffer_hash_before"),
        "canvas_buffer_hash_after": after.get("canvas_buffer_hash_after"),
    }
    require(clear(result.get("harness_called_render_api")), content)
    require(after.get("content_surface_created_count") == 1, content)
    require(after.get("content_surface_changed_count") == 1, content)
    require(after.get("canvas_lock_count", 0) > 0, content)
    require(after.get("canvas_draw_bitmap_count", 0) > 0, content)
    require(after.get("canvas_pixel_change_count", 0) > 0, content)
    require(after.get("canvas_post_count", 0) > 0, content)
    require(after.get("canvas_buffer_hash_before") != after.get("canvas_buffer_hash_after"), content)
    require(after.get("content_surface_width") == 1080, after.get("content_surface_width"))
    require(after.get("content_surface_height") == 2340, after.get("content_surface_height"))
    trace = after["framework_trace"]
    ordered(trace, (
        "choreographer.frame",
        "choreographer.traversal.callback",
        "viewroot.traversal.consumed",
        "viewroot.traversal.rescheduled",
        "viewroot.perform_draw",
        "view.draw",
    ))
    require(trace.index("viewroot.traversal.rescheduled") <
            trace.index("viewroot.perform_draw"), trace)
    consumed = [index for index, event in enumerate(trace) if event == "viewroot.traversal.consumed"]
    require(len(consumed) >= 2 and consumed[1] > trace.index("viewroot.traversal.rescheduled"), trace)
    require("viewroot.perform_draw" not in first["framework_trace"], first["framework_trace"])
    contract = result["contract"]
    require(flag(contract.get("passed")), contract.get("passed"))
    require(contract.get("consumer") == "synthetic-host-pump", contract)
    require(flag(contract.get("same_backing")), contract)
    require(flag(contract.get("closed_explicit_passed")), contract)
    closed = contract["closed_first"]
    require(closed["framework_trace"][-1] == "handoff.viewroot_surface_ready", closed["framework_trace"])
    require(closed["draw_count"] == 0, closed)
    require("viewroot.perform_draw" not in closed["framework_trace"], closed["framework_trace"])
    require("choreographer.frame" not in closed["framework_trace"], closed["framework_trace"])
    require(contract["closed_second"]["traversal_count"] == 2, contract["closed_second"])
    require(contract["closed_second"]["draw_count"] == 1, contract["closed_second"])
    require(contract["relayout_failure_result"] != 0, contract)
    require(contract["retry_result"] == 0, contract)
    environment = result.get("environment") or {}
    require(environment.get("target_type") == "simulator", environment.get("target_type"))
    require(environment.get("kernel_role") == "host_derived", environment.get("kernel_role"))
    require(bool(environment.get("os", {}).get("system_version")), environment.get("os"))
    hardware = environment.get("hardware") or {}
    require(bool(hardware.get("hw_machine")), hardware)
    display = environment.get("display") or {}
    require(display.get("runtime_host_width") == 1080, display)
    require(display.get("runtime_host_height") == 2340, display)
    require(display.get("native_width") not in (None, 0), display)
    require(display.get("source") == "AGR_HOST_DISPLAY_OVERRIDE", display.get("source"))
    roles = {item.get("role"): item for item in environment.get("binaries") or []}
    for role in ("executable", "libEGL", "libGLESv2"):
        item = roles.get(role) or {}
        require(len(str(item.get("uuid") or "")) >= 32, item)
        require(len(str(item.get("sha256") or "")) == 64, item)
    frames = result.get("display_link_frames") or []
    require(len(frames) >= 2, frames)
    for frame in frames[:2]:
        for key in ("timestamp", "targetTimestamp", "duration", "maximumFPS", "callback_delta", "thread", "application_state"):
            require(key in frame, frame)
    require(result.get("stop_reason") in ("CONTENT_PRODUCED", "OBSERVATION_DEADLINE", "FRAME_BUDGET"), result.get("stop_reason"))
    require(result.get("observation_start_monotonic", 0) > 0, result.get("observation_start_monotonic"))
    require(result.get("observation_deadline", 0) > result.get("observation_start_monotonic", 0), result.get("observation_deadline"))
    ci_environment = result.get("ci_environment") or {}
    require(ci_environment.get("simulator_runtime_requested"), ci_environment)
    require(ci_environment.get("simulator_runtime_requested") == ci_environment.get("simulator_runtime_actual"), ci_environment)
    require(ci_environment.get("simulator_device_type_requested") == "com.apple.CoreSimulator.SimDeviceType.iPhone-16-Pro", ci_environment)
    require(ci_environment.get("simulator_device_type_actual") == ci_environment.get("simulator_device_type_requested"), ci_environment)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("result", type=Path)
    args = parser.parse_args()
    result = json.loads(args.result.read_text(encoding="utf-8"))
    schema = result.get("schema")
    if schema == "agr.framework-traversal-dispatch.host.v1":
        check_host(result)
    elif schema == "agr.framework-traversal-dispatch.discovery.v1":
        check_discovery(result)
    else:
        raise SystemExit(f"unknown traversal dispatch schema: {schema}")
    print(json.dumps({"schema": schema, "result": "PASS"}))


if __name__ == "__main__":
    main()
