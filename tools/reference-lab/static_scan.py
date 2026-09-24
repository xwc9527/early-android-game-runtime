"""Static complement for a dependency book.

Dynamic observation is an under-approximation. This scanner records
ZIP/DEX descriptor strings and ELF DT_NEEDED names without promoting
them to OBSERVED_RUNTIME.
"""

import struct
import zipfile
from pathlib import Path

from mapper import from_static


def _dex_strings(blob):
    found = []
    token = bytearray()
    for byte in blob:
        if 32 <= byte < 127:
            token.append(byte)
            continue
        if token:
            text = token.decode("ascii")
            if text.startswith("L") and text.endswith(";") and "/" in text:
                found.append(text)
            token.clear()
    return found


def _phdrs(blob, elf_class, endian):
    if elf_class == 2:
        e_phoff, e_phentsize, e_phnum = struct.unpack_from(endian + "QQIHH", blob, 32)
    else:
        e_phoff, e_phentsize, e_phnum = struct.unpack_from(endian + "IIHH", blob, 28)
    headers = []
    for index in range(e_phnum):
        off = e_phoff + index * e_phentsize
        if elf_class == 2:
            p_type, _, p_offset, p_vaddr, _, p_filesz = struct.unpack_from(endian + "IIQQQQ", blob, off)
        else:
            p_type, p_offset, p_vaddr, _, p_filesz, _ = struct.unpack_from(endian + "IIIIIIII", blob, off)[:6]
        headers.append((p_type, p_offset, p_vaddr, p_filesz))
    return headers


def _elf_needed(blob):
    if blob[:4] != b"\x7fELF" or blob[4] not in (1, 2) or len(blob) < 64:
        return []
    elf_class = blob[4]
    endian = "<" if blob[5] == 1 else ">"
    headers = _phdrs(blob, elf_class, endian)
    dynamic = b""
    for p_type, p_offset, _, p_filesz in headers:
        if p_type == 2:
            dynamic = blob[p_offset:p_offset + p_filesz]
            break
    if not dynamic:
        return []
    tag_size = 16 if elf_class == 2 else 8
    needed = []
    strtab = None
    for cursor in range(0, len(dynamic) - tag_size + 1, tag_size):
        if elf_class == 2:
            tag, value = struct.unpack_from(endian + "QQ", dynamic, cursor)
        else:
            tag, value = struct.unpack_from(endian + "II", dynamic, cursor)
        if tag == 1:
            needed.append(value)
        elif tag == 5:
            strtab = value
        elif tag == 0:
            break
    if strtab is None:
        return []
    names = []
    for offset in needed:
        start = None
        for p_type, p_offset, p_vaddr, p_filesz in headers:
            if p_type == 1 and p_vaddr <= strtab < p_vaddr + p_filesz:
                start = p_offset + (strtab - p_vaddr) + offset
                break
        if start is None or start < 0 or start >= len(blob):
            continue
        end = blob.find(b"\x00", start)
        if end > start:
            names.append(blob[start:end].decode("ascii", "replace"))
    return names


def scan_apk(path):
    records = []
    with zipfile.ZipFile(path) as archive:
        for info in archive.infolist():
            name = info.filename
            if name.endswith(".dex"):
                for descriptor in _dex_strings(archive.read(name)):
                    records.append(from_static({
                        "kind": "JAVA_CLASS",
                        "canonical_name": descriptor,
                        "confidence": "STATIC_REFERENCED",
                        "caller": name,
                    }))
            elif name.endswith(".so"):
                for library in _elf_needed(archive.read(name)):
                    records.append(from_static({
                        "kind": "NATIVE_SYMBOL",
                        "canonical_name": library,
                        "confidence": "STATIC_REFERENCED",
                        "caller": name,
                    }))
    return records
