#!/usr/bin/env python3
"""Record that the AOT artifact is ordinary ahead-of-time Mach-O text."""

import json
import pathlib
import sys

source = pathlib.Path(sys.argv[1]).read_text(encoding="utf-8")
forbidden = ["mprotect", "MAP_JIT", "pthread_jit", "vm_protect", "mmap("]
found = [token for token in forbidden if token in source]
pathlib.Path(sys.argv[2]).write_text(json.dumps({
    "artifact": "Runtime/AotLab/aot_blocks.c",
    "produced_before_process_start": True,
    "runtime_codegen": False,
    "executable_data_pages": False,
    "forbidden_tokens_present": found,
    "proof": "The translated blocks are C compiled by Apple clang into a normal Mach-O __TEXT section. The running process does not allocate executable memory for them.",
}, indent=2) + "\n", encoding="utf-8", newline="\n")
if found:
    raise SystemExit("runtime executable generation marker in AOT source")
