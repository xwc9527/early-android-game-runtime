"""Conservative APK dependency scan. Static evidence never claims runtime use."""

import hashlib
import struct
import zipfile
from pathlib import Path

from mapper import from_static


def _u16(blob, off):
    return struct.unpack_from("<H", blob, off)[0]


def _u32(blob, off):
    return struct.unpack_from("<I", blob, off)[0]


def _uleb(blob, off):
    value = 0
    for shift in range(0, 35, 7):
        byte = blob[off]
        off += 1
        value |= (byte & 127) << shift
        if not byte & 128:
            return value, off
    raise ValueError("invalid DEX uleb128")


ANDROID_PACKAGES = ("Landroid/", "Lcom/android/", "Ljava/", "Ljavax/",
                    "Ldalvik/", "Lorg/apache/harmony/", "Lorg/xml/", "Lorg/w3c/")


def _is_android_owner(descriptor):
    return descriptor.startswith(ANDROID_PACKAGES)


def _dex_refs(blob, member):
    if len(blob) < 112 or blob[:4] != b"dex\n" or blob[7] != 0:
        raise ValueError(f"invalid DEX header: {member}")
    if _u32(blob, 32) != len(blob) or _u32(blob, 36) != 112 or _u32(blob, 40) != 0x12345678:
        raise ValueError(f"invalid DEX size or byte order: {member}")
    tables = {}
    for name, off, width in (("strings", 56, 4), ("types", 64, 4),
                             ("protos", 72, 12), ("fields", 80, 8), ("methods", 88, 8)):
        size, start = struct.unpack_from("<II", blob, off)
        if size and (start < 112 or start + size * width > len(blob)):
            raise ValueError(f"DEX {name} out of bounds: {member}")
        tables[name] = size, start
    size, start = tables["strings"]
    strings = []
    for i in range(size):
        off = _u32(blob, start + i * 4)
        if off >= len(blob):
            raise ValueError("DEX string offset out of bounds")
        _, off = _uleb(blob, off)
        end = blob.find(b"\0", off)
        if end < 0:
            raise ValueError("unterminated DEX string")
        strings.append(blob[off:end].decode("utf-8", "replace"))
    size, start = tables["types"]
    types = [strings[_u32(blob, start + i * 4)] for i in range(size)]
    size, start = tables["protos"]
    protos = []
    for i in range(size):
        _, return_idx, params_off = struct.unpack_from("<III", blob, start + i * 12)
        params = []
        if params_off:
            if params_off + 4 > len(blob):
                raise ValueError("DEX proto out of bounds")
            count = _u32(blob, params_off)
            if params_off + 4 + count * 2 > len(blob):
                raise ValueError("DEX proto out of bounds")
            params = [types[_u16(blob, params_off + 4 + k * 2)] for k in range(count)]
        protos.append("(" + "".join(params) + ")" + types[return_idx])
    records = []
    for descriptor in types:
        if _is_android_owner(descriptor) and descriptor.endswith(";"):
            records.append(from_static({"kind": "JAVA_CLASS", "canonical_name": descriptor,
                                        "confidence": "STATIC_REFERENCED", "caller": member}))
    size, start = tables["fields"]
    for i in range(size):
        owner, typ, name = struct.unpack_from("<HHI", blob, start + i * 8)
        if _is_android_owner(types[owner]):
            records.append(from_static({"kind": "JAVA_FIELD",
                                        "canonical_name": f"{types[owner]}->{strings[name]}:{types[typ]}",
                                        "confidence": "STATIC_REFERENCED", "caller": member}))
    size, start = tables["methods"]
    method_names = []
    for i in range(size):
        owner, proto, name = struct.unpack_from("<HHI", blob, start + i * 8)
        canonical = f"{types[owner]}->{strings[name]}{protos[proto]}"
        method_names.append(canonical)
        if _is_android_owner(types[owner]):
            records.append(from_static({"kind": "JAVA_METHOD",
                                        "canonical_name": canonical,
                                        "confidence": "STATIC_REFERENCED", "caller": member}))
    class_count, class_start = struct.unpack_from("<II", blob, 96)
    if class_count and (class_start < 112 or class_start + class_count * 32 > len(blob)):
        raise ValueError("DEX class table out of bounds")
    for i in range(class_count):
        data_off = _u32(blob, class_start + i * 32 + 24)
        if not data_off:
            continue
        if data_off >= len(blob):
            raise ValueError("DEX class data out of bounds")
        counts = []
        for _ in range(4):
            count, data_off = _uleb(blob, data_off)
            counts.append(count)
        for count in counts[:2]:
            for _ in range(count):
                _, data_off = _uleb(blob, data_off)
                _, data_off = _uleb(blob, data_off)
        for count in counts[2:]:
            method_idx = 0
            for _ in range(count):
                delta, data_off = _uleb(blob, data_off)
                method_idx += delta
                flags, data_off = _uleb(blob, data_off)
                _, data_off = _uleb(blob, data_off)
                if flags & 0x100:
                    records.append(from_static({"kind": "JNI_BINDING",
                                                "canonical_name": method_names[method_idx],
                                                "confidence": "STATIC_REFERENCED",
                                                "caller": member, "origin": "DEX_NATIVE_DECLARATION"}))
    return records


def _elf_refs(blob, member):
    if len(blob) < 52 or blob[:5] != b"\x7fELF\x01" or blob[5] != 1:
        raise ValueError(f"expected little-endian ELF32: {member}")
    phoff = _u32(blob, 28)
    phentsize, phnum = struct.unpack_from("<HH", blob, 42)
    if phentsize < 32 or phoff + phentsize * phnum > len(blob):
        raise ValueError(f"ELF program headers out of bounds: {member}")
    loads, dynamic = [], None
    for i in range(phnum):
        kind, off, vaddr, _, size, _, _, _ = struct.unpack_from("<IIIIIIII", blob, phoff + i * phentsize)
        if off + size > len(blob):
            raise ValueError(f"ELF segment out of bounds: {member}")
        if kind == 1:
            loads.append((vaddr, off, size))
        elif kind == 2:
            dynamic = off, size
    if dynamic is None:
        return []
    def mapped(addr):
        for vaddr, off, size in loads:
            if vaddr <= addr < vaddr + size:
                return off + addr - vaddr
        raise ValueError(f"unmapped ELF address {addr:#x}: {member}")
    tags = {}
    for off in range(dynamic[0], dynamic[0] + dynamic[1], 8):
        tag, value = struct.unpack_from("<II", blob, off)
        if tag == 0:
            break
        tags.setdefault(tag, []).append(value)
    if 5 not in tags:
        return []
    strtab = mapped(tags[5][0])
    strsz = tags.get(10, [len(blob) - strtab])[0]
    if strtab + strsz > len(blob):
        raise ValueError(f"ELF string table out of bounds: {member}")
    strings = blob[strtab:strtab + strsz]
    def string_at(off):
        if off >= len(strings):
            raise ValueError(f"ELF string offset out of bounds: {member}")
        end = strings.find(b"\0", off)
        if end < 0:
            raise ValueError(f"ELF string unterminated: {member}")
        return strings[off:end].decode("utf-8", "replace")
    needed = {string_at(off) for off in tags.get(1, [])}
    symbol_count = 0
    if 4 in tags:
        _, symbol_count = struct.unpack_from("<II", blob, mapped(tags[4][0]))
    for address_tag, size_tag in ((17, 18), (23, 2)):
        if address_tag in tags:
            off, size = mapped(tags[address_tag][0]), tags.get(size_tag, [0])[0]
            if off + size > len(blob):
                raise ValueError(f"ELF relocations out of bounds: {member}")
            for cursor in range(off, off + size, 8):
                symbol_count = max(symbol_count, (_u32(blob, cursor + 4) >> 8) + 1)
    imports = set()
    if 6 in tags:
        symtab, syment = mapped(tags[6][0]), tags.get(11, [16])[0]
        if syment < 16 or symtab + symbol_count * syment > len(blob):
            raise ValueError(f"ELF symbols out of bounds: {member}")
        for i in range(symbol_count):
            name, _, _, _, _, section = struct.unpack_from("<IIIBBH", blob, symtab + i * syment)
            if section == 0 and name:
                imports.add(string_at(name))
    records = []
    for library in sorted(needed):
        records.append(from_static({"kind": "NATIVE_LIBRARY", "canonical_name": library,
                                    "confidence": "STATIC_REFERENCED", "caller": member,
                                    "origin": "DT_NEEDED"}))
    for symbol in sorted(imports):
        records.append(from_static({"kind": "NATIVE_SYMBOL", "canonical_name": symbol,
                                    "confidence": "STATIC_REFERENCED", "caller": member,
                                    "origin": "ELF_IMPORT"}))
    return records


def scan_apk(path):
    records = []
    with zipfile.ZipFile(path) as archive:
        for member in sorted(archive.namelist()):
            if member.endswith(".dex"):
                records.extend(_dex_refs(archive.read(member), member))
            elif member.startswith("lib/") and member.endswith(".so"):
                # API19 Dalvik and its supported guest ABIs are 32-bit. Modern
                # F-Droid APKs may bundle 64-bit variants beside the selected
                # x86/ARM library; retain the ABI list in the sample matrix.
                abi = member.split("/", 2)[1]
                if abi in {"arm64-v8a", "x86_64", "mips64"}:
                    continue
                records.extend(_elf_refs(archive.read(member), member))
    return records


def apk_identity(path):
    path = Path(path)
    return {"name": path.name, "sha256": hashlib.sha256(path.read_bytes()).hexdigest()}
