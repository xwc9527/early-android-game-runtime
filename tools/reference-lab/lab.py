"""Local Android 4.4.4 Reference Lab roles.

CLEAN is the uninstrumented semantic oracle. TRACE is the dependency
mapper input. TRACE is not the oracle, and neither role authorizes an
original AGR implementation.
"""

import json
from pathlib import Path

ROLES = {
    "CLEAN": {
        "role": "semantic_oracle",
        "instrumented": False,
        "baseline": "Android 4.4.4_r2",
        "may_authorize_implementation": False,
    },
    "TRACE": {
        "role": "dependency_mapper",
        "instrumented": True,
        "baseline": "Android 4.4.4_r2",
        "may_authorize_implementation": False,
    },
}

LAYOUT = (
    "aosp-4.4.4-r2",
    "clean-image",
    "trace-image",
    "emulator",
    "mapper",
    "source-index",
    "migration-books",
    "source-manifests",
)


def describe(variant):
    if variant not in ROLES:
        raise ValueError("unknown reference variant: " + str(variant))
    return dict(ROLES[variant])


def assert_not_oracle(description):
    if description.get("role") == "semantic_oracle" and description.get("instrumented"):
        raise ValueError("TRACE cannot be the semantic oracle")
    if description.get("variant") == "TRACE" and description.get("role") == "semantic_oracle":
        raise ValueError("TRACE cannot be the semantic oracle")


def ensure_layout(root):
    root = Path(root)
    for name in LAYOUT:
        (root / name).mkdir(parents=True, exist_ok=True)
    clean = describe("CLEAN")
    trace = describe("TRACE")
    clean["variant"] = "CLEAN"
    trace["variant"] = "TRACE"
    assert_not_oracle(clean)
    assert_not_oracle(trace)
    document = {
        "schema_version": 1,
        "baseline": "Android 4.4.4_r2",
        "clean": clean,
        "trace": trace,
        "images_provisioned": False,
        "rule": "TRACE discovers dependencies. CLEAN verifies semantics. Neither authorizes an original AGR implementation.",
    }
    (root / "lab.json").write_text(json.dumps(document, indent=2) + "\n", encoding="utf-8")
    return document
