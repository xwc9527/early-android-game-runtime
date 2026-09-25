#!/usr/bin/env python3
"""Record a built API19 CLEAN/TRACE pair after checking its common base."""

import argparse
import hashlib
import json
from pathlib import Path

from lab import assert_matched_reference

TRACE_PATCH_SHA256 = "1340359e595c934aee364fcdf3119b52fef56ef27b13af2ed820b407eaf6393f"


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def checked_recorded_hash(path, artifact):
    expected = path.read_text().split()[0]
    actual = sha256(artifact)
    if actual != expected:
        raise ValueError(f"recorded hash mismatch for {artifact}")
    return actual


def record_pair(clean_out, trace_out):
    clean_manifest = clean_out / "source-manifest.xml"
    trace_manifest = trace_out / "source-manifest.xml"
    if clean_manifest.read_bytes() != trace_manifest.read_bytes():
        raise ValueError("resolved CLEAN and TRACE manifests differ")
    clean_toolchain = sha256(clean_out / "host-toolchain.txt")
    trace_toolchain = sha256(trace_out / "host-toolchain.txt")
    patch_name = (clean_out / "host-build-patch.sha256").read_text().split()[0]
    trace_patch = checked_recorded_hash(
        trace_out / "dalvik-trace.patch.sha256", trace_out / "dalvik-trace.patch")
    if trace_patch != TRACE_PATCH_SHA256:
        raise ValueError("TRACE instrumentation differs from reviewed diff")
    common = {"baseline": "android-4.4.4_r2",
              "source_manifest_sha256": sha256(clean_manifest),
              "build_only_patch_sha256": patch_name,
              "build_flavor": "aosp_x86-eng", "execution_mode": "int:portable"}
    product = Path("target/product/generic_x86/system.img")
    clean = dict(common, variant="CLEAN", instrumented=False,
                 role="semantic_oracle", host_toolchain_sha256=clean_toolchain,
                 image_sha256=checked_recorded_hash(clean_out / "system.img.sha256",
                                                    clean_out / product))
    trace = dict(common, variant="TRACE", instrumented=True,
                 role="dependency_mapper", host_toolchain_sha256=trace_toolchain,
                 trace_patch_sha256=trace_patch,
                 image_sha256=checked_recorded_hash(trace_out / "system.img.sha256",
                                                    trace_out / product))
    assert_matched_reference(clean, trace)
    return {"schema_version": 1, "status": "BUILD_VERIFIED", "clean": clean, "trace": trace,
            "oracle_ready": False, "mapper_run_ready": False}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--clean-out", required=True, type=Path)
    parser.add_argument("--trace-out", required=True, type=Path)
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    pair = record_pair(args.clean_out, args.trace_out)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(pair, indent=2, sort_keys=True) + "\n")
    print(json.dumps({"status": pair["status"], "source_manifest_sha256":
                      pair["clean"]["source_manifest_sha256"]}))


if __name__ == "__main__":
    main()
