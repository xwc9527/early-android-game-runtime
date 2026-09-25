#!/usr/bin/env python3
"""Classify observed API19 owners using exact boot JAR class definitions."""

import argparse
import hashlib
import json
import struct
import zipfile
from pathlib import Path

from static_scan import _u32, _uleb


# Each entry is an original AOSP owner, not a migration-completeness claim.
BOOT_OWNERS = {
    "core.jar": ("libcore", "platform/libcore"),
    "conscrypt.jar": ("Conscrypt", "platform/external/conscrypt"),
    "okhttp.jar": ("OkHttp", "platform/external/okhttp"),
    "core-junit.jar": ("libcore/JUnit", "platform/libcore"),
    "bouncycastle.jar": ("BouncyCastle", "platform/external/bouncycastle"),
    "ext.jar": ("Framework/ext", "platform/frameworks/base"),
    "framework.jar": ("Framework", "platform/frameworks/base"),
    "framework2.jar": ("Framework/secondary", "platform/frameworks/base"),
    "telephony-common.jar": ("Telephony", "platform/frameworks/opt/telephony"),
    "voip-common.jar": ("VoIP", "platform/frameworks/opt/net/voip"),
    "mms-common.jar": ("MMS", "platform/frameworks/opt/mms"),
    "android.policy.jar": ("Framework/policy", "platform/frameworks/base"),
    "services.jar": ("Framework/services", "platform/frameworks/base"),
    "apache-xml.jar": ("Apache XML", "platform/external/apache-xml"),
    "webviewchromium.jar": ("WebView", "platform/external/chromium_org"),
}


def class_definitions(blob):
    if len(blob) < 112 or blob[:4] != b"dex\n" or _u32(blob, 32) != len(blob):
        raise ValueError("invalid DEX blob")
    string_count, string_start = struct.unpack_from("<II", blob, 56)
    type_count, type_start = struct.unpack_from("<II", blob, 64)
    class_count, class_start = struct.unpack_from("<II", blob, 96)
    if string_start + string_count * 4 > len(blob) or \
            type_start + type_count * 4 > len(blob) or \
            class_start + class_count * 32 > len(blob):
        raise ValueError("DEX class index out of bounds")
    strings = []
    for i in range(string_count):
        offset = _u32(blob, string_start + i * 4)
        _, offset = _uleb(blob, offset)
        end = blob.find(b"\0", offset)
        if end < 0:
            raise ValueError("unterminated DEX string")
        strings.append(blob[offset:end].decode("utf-8", "replace"))
    types = [strings[_u32(blob, type_start + i * 4)] for i in range(type_count)]
    return {types[_u32(blob, class_start + i * 32)] for i in range(class_count)}


def index_boot_jars(framework_dir):
    entries = {}
    hashes = {}
    for name, (cluster, repo) in BOOT_OWNERS.items():
        path = framework_dir / name
        with zipfile.ZipFile(path) as archive:
            blob = archive.read("classes.dex")
        hashes[name] = hashlib.sha256(path.read_bytes()).hexdigest()
        for descriptor in class_definitions(blob):
            if descriptor in entries:
                raise ValueError(f"duplicate boot class definition: {descriptor}")
            entries[descriptor] = {"owner_cluster": cluster,
                                   "source_repo": repo,
                                   "boot_jar": name,
                                   "boot_jar_sha256": hashes[name],
                                   "owner_basis": "BOOT_JAR_CLASS_DEFINITION"}
    return {"schema_version": 1, "baseline": "android-4.4.4_r2",
            "boot_jar_hashes": hashes, "classes": entries}


def classify_book(book, index):
    result = json.loads(json.dumps(book))
    counts = {}
    for item in result["dependencies"]:
        descriptor = item["canonical_name"].split("->", 1)[0]
        owner = index["classes"].get(descriptor)
        if owner:
            item.update(owner)
            counts[owner["owner_cluster"]] = counts.get(owner["owner_cluster"], 0) + 1
        else:
            item["owner_basis"] = "UNRESOLVED"
    result["owner_index_basis"] = "boot JAR class definitions in verified CLEAN image"
    result["owner_counts"] = counts
    result["owner_index_jar_hashes"] = index["boot_jar_hashes"]
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--framework-dir", required=True, type=Path)
    parser.add_argument("--book", required=True, type=Path)
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    result = classify_book(json.loads(args.book.read_text()),
                           index_boot_jars(args.framework_dir))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({"owner_counts": result["owner_counts"],
                      "unresolved": sum(item["owner_basis"] == "UNRESOLVED"
                                        for item in result["dependencies"])}))


if __name__ == "__main__":
    main()
