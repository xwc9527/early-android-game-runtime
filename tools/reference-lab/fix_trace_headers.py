#!/usr/bin/env python3
"""Move TRACE C headers out of the generated interpreter function body."""

import argparse
from pathlib import Path

from instrument_trace import run


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("source_root", type=Path)
    args = parser.parse_args()
    mterp = args.source_root / "dalvik/vm/mterp"
    template = mterp / "c/gotoTargets.cpp"
    source = template.read_text()
    includes = ("#ifdef AGR_TRACE\n#include <fcntl.h>\n#include <pthread.h>\n"
                "#include <stdio.h>\n#include <unistd.h>\n#endif\n")
    if not source.startswith(includes + "\n"):
        raise SystemExit("expected misplaced TRACE includes")
    template.write_text(source[len(includes) + 1:])
    header = mterp / "c/header.cpp"
    header_source = header.read_text()
    anchor = '#include "Dalvik.h"\n'
    if header_source.count(anchor) != 1:
        raise SystemExit("mterp header include anchor changed")
    header.write_text(header_source.replace(anchor, anchor + includes, 1))
    run("python2", "gen-mterp.py", "x86", "out", cwd=mterp)
    run("python2", "gen-mterp.py", "portable", "out", cwd=mterp)
    portable_asm = mterp / "out/InterpAsm-portable.S"
    if portable_asm.exists():
        portable_asm.unlink()
    for name in ("InterpC-x86.cpp", "InterpC-portable.cpp"):
        generated = (mterp / "out" / name).read_text()
        if "AGRTRACE|v2" not in generated or generated.index(includes) > 2000:
            raise SystemExit(f"generated {name} lacks top-level TRACE includes")
    print(run("git", "status", "--short", cwd=args.source_root / "dalvik"))


if __name__ == "__main__":
    main()
