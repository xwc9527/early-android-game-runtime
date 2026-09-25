#!/usr/bin/env python3
"""Record a built API19 CLEAN/TRACE pair after checking its common base."""

import argparse
import hashlib
import json
from pathlib import Path

from lab import assert_matched_reference

TRACE_PATCH_SHA256 = "54560f1fd7b6d1c689a559480b9ca562293fc3cb20081d73bfc2eaf77e41ce2b"


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


def record_pair(clean_out, trace_out, arch="x86"):
    if arch not in ("x86", "arm"):
        raise ValueError(f"unsupported API19 architecture: {arch}")
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
              "build_flavor": f"aosp_{arch}-eng", "execution_mode": "int:portable"}
    product_dir = Path("target/product") / ("generic_x86" if arch == "x86" else "generic")
    product = product_dir / "system.img"
    clean_dvm = sha256(clean_out / product_dir / "system/lib/libdvm.so")
    trace_dvm = sha256(trace_out / product_dir / "system/lib/libdvm.so")
    if clean_dvm == trace_dvm:
        raise ValueError("TRACE libdvm is identical to uninstrumented CLEAN libdvm")
    clean = dict(common, variant="CLEAN", instrumented=False,
                 role="semantic_oracle", host_toolchain_sha256=clean_toolchain,
                 libdvm_sha256=clean_dvm,
                 image_sha256=checked_recorded_hash(clean_out / "system.img.sha256",
                                                    clean_out / product))
    trace = dict(common, variant="TRACE", instrumented=True,
                 role="dependency_mapper", host_toolchain_sha256=trace_toolchain,
                 libdvm_sha256=trace_dvm,
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
    parser.add_argument("--arch", choices=("x86", "arm"), default="x86")
    args = parser.parse_args()
    pair = record_pair(args.clean_out, args.trace_out, args.arch)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(pair, indent=2, sort_keys=True) + "\n")
    print(json.dumps({"status": pair["status"], "source_manifest_sha256":
                      pair["clean"]["source_manifest_sha256"]}))


if __name__ == "__main__":
    main()
