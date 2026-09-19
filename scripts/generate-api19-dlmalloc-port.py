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
text = text.replace("sizeof(char*)", "sizeof(agr_guest_address_t)")

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
    "#define is_aligned(A)       (((agr_dl_size_t)((A)) & (CHUNK_ALIGN_MASK)) == 0)":
        "#define is_aligned(A)       ((agr_dl_host_to_guest((const void*)(A)) & CHUNK_ALIGN_MASK) == 0)",
    "#define MCHUNK_SIZE         (sizeof(mchunk))":
        "#define MCHUNK_SIZE         ((agr_dl_size_t)sizeof(mchunk))",
    "#define MAX_REQUEST         ((-MIN_CHUNK_SIZE) << 2)":
        "#define MAX_REQUEST         ((agr_dl_size_t)((SIZE_T_ZERO - (agr_dl_size_t)MIN_CHUNK_SIZE) << 2))",
    "#define align_offset(A)\\\n ((((agr_dl_size_t)(A) & CHUNK_ALIGN_MASK) == 0)? 0 :\\\n  ((MALLOC_ALIGNMENT - ((agr_dl_size_t)(A) & CHUNK_ALIGN_MASK)) & CHUNK_ALIGN_MASK))":
        "#define align_offset(A)\\\n (((agr_dl_host_to_guest((const void*)(A)) & CHUNK_ALIGN_MASK) == 0)? 0 :\\\n  ((MALLOC_ALIGNMENT - (agr_dl_host_to_guest((const void*)(A)) & CHUNK_ALIGN_MASK)) & CHUNK_ALIGN_MASK))",
    "if ((((agr_dl_size_t)(mem)) & (alignment - 1)) != 0)":
        "if ((agr_dl_host_to_guest(mem) & (alignment - 1)) != 0)",
    "#define is_page_aligned(S)\\\n   (((agr_dl_size_t)(S) & (mparams.page_size - SIZE_T_ONE)) == 0)":
        "#define is_page_aligned(S)\\\n   ((agr_dl_host_to_guest((const void*)(S)) & (mparams.page_size - SIZE_T_ONE)) == 0)",
    "#define is_granularity_aligned(S)\\\n   (((agr_dl_size_t)(S) & (mparams.granularity - SIZE_T_ONE)) == 0)":
        "#define is_granularity_aligned(S)\\\n   ((agr_dl_host_to_guest((const void*)(S)) & (mparams.granularity - SIZE_T_ONE)) == 0)",
    "ssize += (page_align((agr_dl_size_t)base) - (agr_dl_size_t)base);":
        "ssize += (page_align(agr_dl_host_to_guest(base)) - agr_dl_host_to_guest(base));",
    "char* br = (char*)mem2chunk((agr_dl_size_t)(((agr_dl_size_t)((char*)mem + alignment -\n                                                       SIZE_T_ONE)) &\n                                             -alignment));":
        "char* br = (char*)mem2chunk(agr_dl_align_host_pointer(mem, alignment));",
    "assert(((agr_dl_size_t)mem & (alignment - 1)) == 0);":
        "assert((agr_dl_host_to_guest(mem) & (alignment - 1)) == 0);",
}
for old, new in replacements.items():
    if old not in text:
        raise SystemExit(f"pinned source shape changed; missing: {old!r}")
    text = text.replace(old, new)

output.write_text(text, encoding="utf-8", newline="\n")
