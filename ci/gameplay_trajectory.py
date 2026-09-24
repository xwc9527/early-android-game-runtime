"""Shared test-only trajectory contract; no AGR Runtime imports."""

import hashlib
import json
from pathlib import Path

CANONICAL_SCHEMA = "agr.gameplay-trajectory.v1"
EXECUTED_SCHEMA = "agr.executed-gameplay-trajectory.v1"
APK_SHA256 = "57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569"


def load_canonical(path):
    trajectory = json.loads(Path(path).read_text(encoding="utf-8"))
    if trajectory.get("schema") != CANONICAL_SCHEMA:
        raise ValueError("unsupported canonical trajectory schema")
    game = trajectory.get("game", {})
    if (game.get("package"), game.get("version_code"), game.get("version_name"),
            game.get("apk_sha256")) != ("org.jfedor.frozenbubble", 8, "1.7", APK_SHA256):
        raise ValueError("canonical trajectory does not name the exact APK")
    reference = trajectory.get("reference", {})
    if (reference.get("android_api"), reference.get("android_release")) != (19, "4.4.4"):
        raise ValueError("canonical trajectory requires Android 4.4.4/API19")
    steps = trajectory.get("steps")
    if not isinstance(steps, list) or not steps:
        raise ValueError("canonical trajectory must contain observed steps")
    ids = set()
    for step in steps:
        step_id = step.get("id")
        if not isinstance(step_id, str) or not step_id or step_id in ids:
            raise ValueError("trajectory step IDs must be nonempty and unique")
        ids.add(step_id)
        if not isinstance(step.get("wait_ms"), int) or not 0 <= step["wait_ms"] <= 60000:
            raise ValueError(f"invalid wait_ms for {step_id}")
        action = step.get("action")
        if action is None:
            continue
        if action.get("type") not in ("tap", "swipe", "long_press", "keyevent"):
            raise ValueError(f"unsupported action for {step_id}")
        if action["type"] != "keyevent":
            if action.get("coordinate_space") not in ("normalized_root_view", "normalized_content_view"):
                raise ValueError(f"unmapped coordinate space for {step_id}")
            keys = ("x", "y") if action["type"] != "swipe" else ("x0", "y0", "x1", "y1")
            for key in keys:
                value = action.get(key)
                if not isinstance(value, (int, float)) or not 0.0 <= value <= 1.0:
                    raise ValueError(f"{step_id}.{key} must be normalized")
    return trajectory


def map_action(action, viewport):
    """Convert one normalized action to a measured platform viewport."""
    if action is None:
        return None
    if action["type"] == "keyevent":
        return dict(action)
    if action["coordinate_space"] != viewport.get("coordinate_space"):
        raise ValueError("requested and measured viewport coordinate spaces differ")
    x0, y0, width, height = (viewport.get(k) for k in ("x", "y", "width", "height"))
    if not all(isinstance(v, int) for v in (x0, y0, width, height)) or width < 1 or height < 1:
        raise ValueError("invalid measured viewport")
    mapped = {"type": action["type"], "coordinate_space": action["coordinate_space"]}
    for axis in ("x", "y", "x0", "y0", "x1", "y1"):
        if axis in action:
            origin, extent = (x0, width) if axis.startswith("x") else (y0, height)
            mapped[axis] = origin + round(action[axis] * (extent - 1))
    for name in ("duration_ms", "keycode"):
        if name in action:
            mapped[name] = action[name]
    mapped["viewport"] = dict(viewport)
    return mapped


def file_sha256(path):
    digest = hashlib.sha256()
    with open(path, "rb") as stream:
        for chunk in iter(lambda: stream.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()
