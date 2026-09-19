#!/usr/bin/env python3
"""Generate the reviewable ARM32 guest-address adaptation of API19 dlmalloc."""
from pathlib import Path
import re

root = Path(__file__).resolve().parents[1]
source = root / "Vendor/AOSP/bionic-api19/libc/upstream-dlmalloc/malloc.c"
output = root / "Runtime/Bionic/agr_api19_dlmalloc_source.inc"
text = source.read_text(encoding="utf-8")

# KitKat's source assumes sizeof(size_t) == sizeof(void*) == 4. The host port
# spells those guest ABI scalar types explicitly instead of inheriting arm64.
text = re.sub(r"\bsize_t\b", "agr_dl_size_t", text)
text = re.sub(r"\bptrdiff_t\b", "agr_dl_ptrdiff_t", text)
text = re.sub(r"sizeof\(void\s*\*\)", "sizeof(agr_guest_address_t)", text)

replacements = {
    "  struct malloc_chunk* fd;": "  agr_guest_ptr<struct malloc_chunk> fd;",
    "  struct malloc_chunk* bk;": "  agr_guest_ptr<struct malloc_chunk> bk;",
    "typedef struct malloc_chunk* mchunkptr;": "typedef agr_guest_ptr<struct malloc_chunk> mchunkptr;",
    "typedef struct malloc_chunk* sbinptr;": "typedef agr_guest_ptr<struct malloc_chunk> sbinptr;",
    "  struct malloc_tree_chunk* fd;": "  agr_guest_ptr<struct malloc_tree_chunk> fd;",
    "  struct malloc_tree_chunk* bk;": "  agr_guest_ptr<struct malloc_tree_chunk> bk;",
    "  struct malloc_tree_chunk* child[2];": "  agr_guest_ptr<struct malloc_tree_chunk> child[2];",
    "  struct malloc_tree_chunk* parent;": "  agr_guest_ptr<struct malloc_tree_chunk> parent;",
    "typedef struct malloc_tree_chunk* tchunkptr;": "typedef agr_guest_ptr<struct malloc_tree_chunk> tchunkptr;",
    "typedef struct malloc_tree_chunk* tbinptr;": "typedef agr_guest_ptr<struct malloc_tree_chunk> tbinptr;",
    "  char*        base;": "  agr_guest_ptr<char> base;",
    "  struct malloc_segment* next;": "  agr_guest_ptr<struct malloc_segment> next;",
    "typedef struct malloc_segment* msegmentptr;": "typedef agr_guest_ptr<struct malloc_segment> msegmentptr;",
    "  char*      least_addr;": "  agr_guest_ptr<char> least_addr;",
    "  void*      extp;": "  agr_guest_ptr<void> extp;",
    "typedef struct malloc_state*    mstate;": "typedef agr_guest_ptr<struct malloc_state> mstate;",
    "static struct malloc_params mparams;": "#define mparams (*agr_dl_current_params())",
    "static struct malloc_state _gm_;\n#define gm                 (&_gm_)\n#define is_global(M)       ((M) == &_gm_)":
        "#define gm                 (agr_dl_current_gm())\n#define is_global(M)       ((M) == agr_dl_current_gm())",
}
for old, new in replacements.items():
    if old not in text:
        raise SystemExit(f"pinned source shape changed; missing: {old!r}")
    text = text.replace(old, new)

output.write_text(text, encoding="utf-8", newline="\n")
