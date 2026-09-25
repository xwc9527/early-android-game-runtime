"""Distinguish API19 Zygote preload state from app-triggered observations."""

import hashlib
import re
import zipfile


def preload_inventory(framework_jar, boot_log):
    with zipfile.ZipFile(framework_jar) as archive:
        source = archive.read("preloaded-classes")
    classes = sorted({line.strip() for line in source.decode("utf-8").splitlines()
                      if line.strip() and not line.lstrip().startswith("#")})
    completed = re.findall(r"\.\.\.preloaded (\d+) classes in \d+ms", boot_log)
    missing = re.findall(r"Class not found for preloading: ([\w.$]+)", boot_log)
    link_errors = re.findall(r"Problem preloading ([\w.$]+):", boot_log)
    fatal = [line for line in boot_log.splitlines() if "Error preloading " in line]
    failed_classes = sorted(set(missing + link_errors))
    proven = (len(completed) == 1 and not fatal and
              int(completed[0]) == len(classes) - len(failed_classes) and
              all(name in classes for name in failed_classes))
    preloaded = sorted(set(classes) - set(failed_classes)) if proven else []
    return {
        "configured_class_count": len(classes),
        "configured_classes_sha256": hashlib.sha256(source).hexdigest(),
        "completed_count": int(completed[0]) if len(completed) == 1 else None,
        "failed_classes": failed_classes,
        "fatal_errors": fatal,
        "class_state": "PRELOADED_IN_ZYGOTE" if proven else "PRELOAD_CONFIGURED_ONLY",
        "configured_classes": classes,
        "preloaded_classes": preloaded,
        "scope": "Zygote class list only; resources, OpenGL, and native libraries need separate evidence",
    }
