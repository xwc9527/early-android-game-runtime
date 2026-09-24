"""Index the API19 Dalvik JNINativeInterface table.

The table in vm/Jni.cpp is the source owner for JNI Call and field
entry points. Names that are not in that table are not added.
"""

import json
import hashlib
import re
from pathlib import Path

TABLE = re.compile(r"static const struct JNINativeInterface gNativeInterface = \{")
SYMBOL = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def index_jni_table(path):
    text = Path(path).read_text(encoding="utf-8", errors="replace")
    match = TABLE.search(text)
    if not match:
        raise ValueError("JNINativeInterface table not found")
    body = text[match.end():]
    end = body.find("};")
    if end < 0:
        raise ValueError("JNINativeInterface table is unterminated")
    symbols = []
    for raw in body[:end].splitlines():
        line = raw.split("/*", 1)[0].strip().rstrip(",").strip()
        if not line or line.startswith("//") or line == "NULL":
            continue
        if not SYMBOL.match(line):
            continue
        symbols.append(line)
    if "GetStaticIntField" not in symbols or "CallIntMethod" not in symbols:
        raise ValueError("JNINativeInterface table is missing Call or GetStatic entry points")
    return symbols


def build_index(path, revision="36e356c96640775f0a3f167bd2426ea0f0093b8b"):
    symbols = index_jni_table(path)
    source_sha256 = hashlib.sha256(Path(path).read_bytes()).hexdigest()
    entries = {}
    for name in symbols:
        entries[name] = {
            "owner_cluster": "JNI",
            "source_repo": "platform/dalvik",
            "source_revision": "android-4.4.4_r2",
            "source_module": "vm",
            "source_file": "vm/Jni.cpp",
            "source_symbol": name,
            "source_files": ["platform/dalvik/vm/Jni.cpp"],
            "required_symbols": [name],
        }
    return {
        "schema_version": 1,
        "baseline": "Android 4.4.4_r2",
        "revision": revision,
        "source": "platform/dalvik/vm/Jni.cpp",
        "source_sha256": source_sha256,
        "entries": entries,
    }


def write_index(path, document):
    Path(path).write_text(json.dumps(document, indent=2) + "\n", encoding="utf-8")
    return document
