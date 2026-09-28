#!/usr/bin/env python3
"""Read ELF32 ARM code and public entry metadata without execution traces."""

from dataclasses import dataclass
import hashlib
import struct
from pathlib import Path


@dataclass(frozen=True)
class Section:
    name: str
    kind: int
    flags: int
    address: int
    offset: int
    size: int
    link: int
    entry_size: int


@dataclass(frozen=True)
class Function:
    address: int
    size: int
    thumb: bool
    name: str
    source: str


class Elf32Arm:
    def __init__(self, path: str | Path):
        self.path = Path(path)
        self.data = self.path.read_bytes()
        self.sha256 = hashlib.sha256(self.data).hexdigest()
        if len(self.data) < 52 or self.data[:7] != b"\x7fELF\x01\x01\x01":
            raise ValueError("expected little-endian ELF32")
        header = struct.unpack_from("<16sHHIIIIIHHHHHH", self.data)
        if header[2] != 40:
            raise ValueError("expected EM_ARM")
        program_offset, program_entry_size, program_count = header[5], header[9], header[10]
        if program_entry_size < 32 or program_count == 0 or \
                program_offset + program_entry_size * program_count > len(self.data):
            raise ValueError("missing ELF32 program headers")
        self.program_headers = tuple(struct.unpack_from("<IIIIIIII", self.data,
                                     program_offset + index * program_entry_size)
                                     for index in range(program_count))
        section_offset, section_entry_size, section_count, name_index = (
            header[6], header[11], header[12], header[13])
        if section_entry_size < 40 or section_count == 0 or name_index >= section_count:
            raise ValueError("missing ELF32 section table")
        if section_offset + section_entry_size * section_count > len(self.data):
            raise ValueError("section table outside ELF")
        headers = [struct.unpack_from("<IIIIIIIIII", self.data,
                   section_offset + index * section_entry_size)
                   for index in range(section_count)]
        names = self._slice(headers[name_index][4], headers[name_index][5])
        self.sections = [Section(self._cstring(names, row[0]), row[1], row[2],
                         row[3], row[4], row[5], row[6], row[9])
                         for row in headers]
        self.executable = tuple(section for section in self.sections
                                if section.flags & 4 and section.kind != 8)

    def first_linker_bias(self, lower_bound: int = 0x10000, page_size: int = 4096) -> int:
        """AGR's first-fit VMA bias for the first ET_DYN object with no prior maps."""
        load_vaddrs = [row[2] for row in self.program_headers if row[0] == 1 and row[5]]
        if not load_vaddrs or page_size <= 0 or page_size & (page_size - 1):
            raise ValueError("cannot derive first-linker bias")
        min_vaddr = min(load_vaddrs) & ~(page_size - 1)
        first_start = (max(lower_bound, min_vaddr) + page_size - 1) & ~(page_size - 1)
        return first_start - min_vaddr

    def _slice(self, offset: int, size: int) -> bytes:
        if offset < 0 or size < 0 or offset + size > len(self.data):
            raise ValueError("ELF range outside file")
        return self.data[offset:offset + size]

    @staticmethod
    def _cstring(data: bytes, offset: int) -> str:
        if offset >= len(data):
            return ""
        end = data.find(b"\0", offset)
        return data[offset:end if end >= 0 else len(data)].decode("utf-8", "replace")

    def code_at(self, address: int, size: int) -> bytes | None:
        for section in self.executable:
            if section.address <= address and address + size <= section.address + section.size:
                start = section.offset + address - section.address
                return self._slice(start, size)
        return None

    def symbols(self) -> list[Function]:
        functions = []
        for section in self.sections:
            if section.kind not in (2, 11) or section.entry_size < 16:
                continue
            if section.link >= len(self.sections):
                raise ValueError("symbol string table outside ELF")
            strings = self.sections[section.link]
            names = self._slice(strings.offset, strings.size)
            data = self._slice(section.offset, section.size)
            for offset in range(0, len(data) - 15, section.entry_size):
                name_offset, value, size, info, _, section_index = struct.unpack_from(
                    "<IIIBBH", data, offset)
                if info & 15 != 2 or section_index == 0 or size == 0:
                    continue
                address = value & ~1
                if self.code_at(address, min(size, 2)) is None:
                    continue
                functions.append(Function(address, size, bool(value & 1),
                                 self._cstring(names, name_offset), section.name))
        return sorted(set(functions), key=lambda item: (item.address, item.thumb, item.name))

    def init_array_entries(self) -> list[Function]:
        functions = []
        for section in self.sections:
            if section.kind not in (14, 15):
                continue
            data = self._slice(section.offset, section.size)
            for index in range(0, len(data) - 3, 4):
                value = struct.unpack_from("<I", data, index)[0]
                address = value & ~1
                if self.code_at(address, 2) is not None:
                    functions.append(Function(address, 0, bool(value & 1),
                                     f"{section.name}[{index // 4}]", section.name))
        return functions

    def exidx_starts(self) -> list[int]:
        """EHABI PREL31 unwind entries identify function regions in stripped SOs."""
        starts = set()
        for section in self.sections:
            if section.kind != 0x70000001:
                continue
            data = self._slice(section.offset, section.size)
            for offset in range(0, len(data) - 7, 8):
                relative = struct.unpack_from("<I", data, offset)[0] & 0x7fffffff
                if relative & 0x40000000:
                    relative -= 0x80000000
                address = section.address + offset + relative
                if self.code_at(address, 2) is not None:
                    starts.add(address)
        return sorted(starts)
