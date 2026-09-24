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
        "baseline": "android-x86-4.4-r5",
        "oracle_ready": False,
        "may_authorize_implementation": False,
    },
    "TRACE": {
        "role": "dependency_mapper",
        "instrumented": True,
        "baseline": "android-4.4.4_r2",
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


def assert_matched_reference(clean, trace):
    """A CLEAN/TRACE differential needs the same pinned source and build base."""
    if clean.get("variant") != "CLEAN" or trace.get("variant") != "TRACE":
        raise ValueError("reference roles are not CLEAN and TRACE")
    if clean.get("instrumented") is not False or trace.get("instrumented") is not True:
        raise ValueError("reference instrumentation roles are invalid")
    for key in ("baseline", "source_revision", "base_image_sha256"):
        if not clean.get(key) or clean[key] != trace.get(key):
            raise ValueError("CLEAN and TRACE have no proven common base: " + key)


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
