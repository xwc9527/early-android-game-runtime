#!/usr/bin/env python3
"""Use a precreated file that API19 untrusted apps may append under SELinux."""

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
    old = ('                char path[96];\n'
           '                snprintf(path, sizeof(path), "/data/local/tmp/agrtrace/trace-%d.log",\n'
           '                        (int)getpid());\n'
           '                agrTraceFd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0600);\n')
    new = ('                agrTraceFd = open("/data/local/tmp/agrtrace/trace.log",\n'
           '                        O_WRONLY | O_APPEND);\n')
    if source.count(old) != 1:
        raise SystemExit("expected one per-process file sink")
    template.write_text(source.replace(old, new, 1))
    run("python2", "gen-mterp.py", "x86", "out", cwd=mterp)
    run("python2", "gen-mterp.py", "portable", "out", cwd=mterp)
    portable_asm = mterp / "out/InterpAsm-portable.S"
    if portable_asm.exists():
        portable_asm.unlink()
    for name in ("InterpC-x86.cpp", "InterpC-portable.cpp"):
        generated = (mterp / "out" / name).read_text()
        if "/data/local/tmp/agrtrace/trace.log" not in generated:
            raise SystemExit(f"generated {name} lacks shared file sink")
    print(run("git", "status", "--short", cwd=args.source_root / "dalvik"))


if __name__ == "__main__":
    main()
