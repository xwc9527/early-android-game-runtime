#!/usr/bin/env python3
"""Upgrade an already instrumented API19 TRACE checkout to lossless file capture."""

import argparse
from pathlib import Path

from instrument_trace import HOOK, run


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("source_root", type=Path)
    args = parser.parse_args()
    dalvik = args.source_root / "dalvik"
    template = dalvik / "vm/mterp/c/gotoTargets.cpp"
    source = template.read_text()
    start = source.index("#ifdef AGR_TRACE\n        if (curMethod != NULL")
    end = source.index("#endif", start) + len("#endif\n")
    old = source[start:end]
    if "AGRTRACE|v1" not in old or source.count("AGRTRACE|v1") != 1:
        raise SystemExit("expected one existing v1 observer")
    template.write_text(source[:start] + HOOK + source[end:])
    header = dalvik / "vm/mterp/c/header.cpp"
    header_text = header.read_text()
    header_anchor = '#include "Dalvik.h"\n'
    includes = ("#ifdef AGR_TRACE\n#include <fcntl.h>\n#include <pthread.h>\n"
                "#include <stdio.h>\n#include <unistd.h>\n#endif\n")
    if header_text.count(header_anchor) != 1:
        raise SystemExit("mterp header include anchor changed")
    header.write_text(header_text.replace(header_anchor,
                                         header_anchor + includes, 1))
    mterp = dalvik / "vm/mterp"
    run("python2", "gen-mterp.py", "x86", "out", cwd=mterp)
    run("python2", "gen-mterp.py", "portable", "out", cwd=mterp)
    portable_asm = mterp / "out/InterpAsm-portable.S"
    if portable_asm.exists():
        portable_asm.unlink()
    for name in ("InterpC-x86.cpp", "InterpC-portable.cpp"):
        if "AGRTRACE|v2" not in (mterp / "out" / name).read_text():
            raise SystemExit(f"generated {name} lacks file observer")
    print(run("git", "status", "--short", cwd=dalvik))


if __name__ == "__main__":
    main()
