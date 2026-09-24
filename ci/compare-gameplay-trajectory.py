#!/usr/bin/env python3
"""Compare two executed trajectories; locate observations, never infer root cause."""

import argparse
import importlib.util
import json
from pathlib import Path

from gameplay_trajectory import APK_SHA256, EXECUTED_SCHEMA, load_canonical


def observed(step, point):
    value = step.get(point)
    return value if isinstance(value, dict) else {}


def state_label(step, point):
    return observed(step, point).get("state", {}).get("observable_state")


def image_difference(left_path, right_path, left_bounds, right_bounds):
    """Normalize image content boxes before comparing. Absence is not equality."""
    if importlib.util.find_spec("PIL") is None:
        return {"available": False, "reason": "Pillow unavailable"}
    from PIL import Image, ImageChops, ImageStat

    def prepared(path, bounds):
        with Image.open(path) as original:
            image = original.convert("RGB")
            if bounds:
                x, y, width, height = (bounds[k] for k in ("x", "y", "width", "height"))
                image = image.crop((x, y, x + width, y + height))
            return image.resize((96, 96), Image.Resampling.BILINEAR)

    left = prepared(left_path, left_bounds)
    right = prepared(right_path, right_bounds)
    mean = ImageStat.Stat(ImageChops.difference(left, right)).mean
    return {"available": True, "normalized_rgb_mean_absolute_error": round(sum(mean) / 765, 5),
            "comparison_size": [96, 96]}


def compare(canonical, android, agr, android_dir=None, agr_dir=None):
    if android.get("schema") != EXECUTED_SCHEMA or agr.get("schema") != EXECUTED_SCHEMA:
        raise ValueError("executed trajectory schema mismatch")
    if android.get("platform") != "android-api19" or agr.get("platform") != "agr-ios-simulator":
        raise ValueError("expected Android API19 and AGR iOS Simulator executions")
    expected_ids = [s["id"] for s in canonical["steps"]]
    for record in (android, agr):
        identity = record.get("identity", {})
        if identity.get("apk_sha256") != APK_SHA256:
            raise ValueError("executed APK SHA mismatch")
        actual_ids = [s.get("id") for s in record.get("steps", [])]
        if actual_ids != expected_ids[:len(actual_ids)]:
            raise ValueError("executed steps are not an ordered canonical prefix")
    env_ok = (android["identity"].get("android_release") == "4.4.4"
              and android["identity"].get("android_api") == 19
              and agr["identity"].get("ios_product_version") == "27.0"
              and agr["identity"].get("simulator_runtime_version") == "27.0")
    if not env_ok:
        return {"schema": "agr.gameplay-trajectory-diff.v1", "trajectory_result": "ENVIRONMENT_MISMATCH",
                "environment": {"android": android["identity"], "agr": agr["identity"]},
                "steps": [], "last_matching_step": None, "first_divergent_step": None}
    rows = []
    last_match = None
    first_divergence = None
    for index, specification in enumerate(canonical["steps"]):
        a = android["steps"][index] if index < len(android["steps"]) else {}
        b = agr["steps"][index] if index < len(agr["steps"]) else {}
        observations = []
        classification = "MATCH"
        a_before, a_after = observed(a, "before"), observed(a, "after")
        b_before, b_after = observed(b, "before"), observed(b, "after")
        a_state, b_state = state_label(a, "after"), state_label(b, "after")
        if not a:
            classification = "REFERENCE_FAILURE" if android.get("execution_error") else "INSUFFICIENT_EVIDENCE"
        elif not b:
            classification = "RUNTIME_FAILURE" if agr.get("execution_error") else "INSUFFICIENT_EVIDENCE"
        elif a.get("runtime_failure"):
            classification = "REFERENCE_FAILURE"
        elif b.get("runtime_failure"):
            classification = "RUNTIME_FAILURE"
        elif specification.get("action") is not None and a.get("input", {}).get("delivered") is True and b.get("input", {}).get("delivered") is False:
            classification = "INPUT_NOT_DELIVERED"
        elif specification.get("action") is not None and a.get("input", {}).get("consumed") is True and b.get("input", {}).get("consumed") is False:
            classification = "INPUT_NOT_CONSUMED"
        elif a_state is not None and b_state is not None and a_state != b_state:
            classification = "STATE_DIVERGENCE"
        elif a_after.get("state", {}).get("transition_observed") is True and b_after.get("state", {}).get("transition_observed") is False:
            classification = "TRANSITION_NOT_OBSERVED"
        elif a_state is None or b_state is None:
            classification = "INSUFFICIENT_EVIDENCE"
        if a_state != b_state:
            observations.append({"kind": "state", "android": a_state, "agr": b_state})
        if specification.get("action") is not None:
            observations.append({"kind": "input", "android": a.get("input"), "agr": b.get("input")})
        if android_dir and agr_dir and a_after.get("screenshot") and b_after.get("screenshot"):
            visual = image_difference(Path(android_dir) / a_after["screenshot"],
                                      Path(agr_dir) / b_after["screenshot"],
                                      a_after.get("content_bounds"), b_after.get("content_bounds"))
            observations.append({"kind": "visual", **visual})
            if classification in ("MATCH", "INSUFFICIENT_EVIDENCE") and visual.get("available") and visual["normalized_rgb_mean_absolute_error"] > 0.20:
                classification = "VISUAL_DIVERGENCE"
        row = {"id": specification["id"], "classification": classification,
               "android": {"observable_before": a_before.get("state"), "input": a.get("input"),
                           "observable_after": a_after.get("state")},
               "agr": {"observable_before": b_before.get("state"), "input": b.get("input"),
                       "observable_after": b_after.get("state")},
               "observations": observations}
        rows.append(row)
        if classification == "MATCH" and first_divergence is None:
            last_match = specification["id"]
        elif first_divergence is None:
            first_divergence = row
    if first_divergence is None:
        result = "MATCH_THROUGH_GAMEPLAY_INTERACTION"
    elif first_divergence["classification"] == "INSUFFICIENT_EVIDENCE":
        result = "INSUFFICIENT_EVIDENCE"
    elif first_divergence["classification"] == "REFERENCE_FAILURE":
        result = "REFERENCE_FAILURE"
    else:
        result = "DIVERGED"
    return {"schema": "agr.gameplay-trajectory-diff.v1", "trajectory_result": result,
            "last_matching_step": last_match,
            "first_divergent_step": first_divergence["id"] if first_divergence else None,
            "classification": first_divergence["classification"] if first_divergence else None,
            "first_divergence": first_divergence, "steps": rows}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--canonical", type=Path, required=True)
    parser.add_argument("--android", type=Path, required=True)
    parser.add_argument("--agr", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = compare(load_canonical(args.canonical), json.loads(args.android.read_text()),
                     json.loads(args.agr.read_text()), args.android.parent, args.agr.parent)
    args.output.write_text(json.dumps(result, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(result["trajectory_result"], result["first_divergent_step"], result.get("classification"))


if __name__ == "__main__":
    main()
