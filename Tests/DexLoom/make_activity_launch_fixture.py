#!/usr/bin/env python3
"""Build a small, self-contained DEX 035 Activity launch contract fixture."""

import argparse
import hashlib
import pathlib
import struct
import zlib


def uleb(value: int) -> bytes:
    out = bytearray()
    while True:
        b = value & 0x7F
        value >>= 7
        out.append(b | (0x80 if value else 0))
        if not value:
            return bytes(out)


def align(data: bytearray, amount: int = 4) -> None:
    while len(data) % amount:
        data.append(0)


def build() -> bytes:
    strings = sorted({
        "<init>", "I", "Landroid/app/Activity;", "Landroid/app/Application;",
        "Landroid/os/Bundle;", "Ltest/TestActivity;", "Ltest/TestApplication;",
        "TestActivity.java", "TestApplication.java", "V", "VL", "appMarker",
        "activityMarker", "onCreate",
    })
    sidx = {s: i for i, s in enumerate(strings)}
    types = sorted({s for s in strings if s in {"I", "V"} or s.startswith("L")},
                   key=lambda s: sidx[s])
    tidx = {s: i for i, s in enumerate(types)}

    # shorty, return type, parameter descriptors
    protos = [("V", "V", ()), ("VL", "V", ("Landroid/os/Bundle;",))]
    proto_index = {p: i for i, p in enumerate(protos)}

    fields = sorted([
        ("Ltest/TestActivity;", "I", "activityMarker"),
        ("Ltest/TestApplication;", "I", "appMarker"),
    ], key=lambda f: (tidx[f[0]], sidx[f[2]], tidx[f[1]]))
    fidx = {f: i for i, f in enumerate(fields)}

    methods = sorted([
        ("Landroid/app/Activity;", ("V", "V", ()), "<init>"),
        ("Landroid/app/Activity;", ("VL", "V", ("Landroid/os/Bundle;",)), "onCreate"),
        ("Landroid/app/Application;", ("V", "V", ()), "<init>"),
        ("Ltest/TestActivity;", ("V", "V", ()), "<init>"),
        ("Ltest/TestActivity;", ("VL", "V", ("Landroid/os/Bundle;",)), "onCreate"),
        ("Ltest/TestApplication;", ("V", "V", ()), "<init>"),
        ("Ltest/TestApplication;", ("V", "V", ()), "onCreate"),
    ], key=lambda m: (tidx[m[0]], sidx[m[2]], proto_index[m[1]]))
    midx = {m: i for i, m in enumerate(methods)}

    header_size = 0x70
    string_ids_off = header_size
    type_ids_off = string_ids_off + 4 * len(strings)
    proto_ids_off = type_ids_off + 4 * len(types)
    field_ids_off = proto_ids_off + 12 * len(protos)
    method_ids_off = field_ids_off + 8 * len(fields)
    class_defs_off = method_ids_off + 8 * len(methods)
    data_off = class_defs_off + 32 * 2
    data = bytearray(b"\0" * data_off)

    string_offsets = []
    for s in strings:
        string_offsets.append(len(data))
        raw = s.encode("utf-8")
        data.extend(uleb(len(s))); data.extend(raw); data.append(0)
    align(data)

    bundle_params_off = len(data)
    data.extend(struct.pack("<I", 1))
    data.extend(struct.pack("<H", tidx["Landroid/os/Bundle;"]))
    align(data)

    code_offsets = {}

    def add_code(key, registers, ins, outs, words):
        align(data)
        code_offsets[key] = len(data)
        data.extend(struct.pack("<HHHHII", registers, ins, outs, 0, 0, len(words)))
        data.extend(struct.pack("<" + "H" * len(words), *words))

    def invoke(opcode, method, regs):
        count = len(regs); cdef = sum((r & 0xF) << (i * 4) for i, r in enumerate(regs[:4]))
        g = regs[4] if count == 5 else 0
        return [opcode | (count << 12) | (g << 8), midx[method], cdef]

    app_base_init = ("Landroid/app/Application;", ("V", "V", ()), "<init>")
    act_base_init = ("Landroid/app/Activity;", ("V", "V", ()), "<init>")
    act_base_create = ("Landroid/app/Activity;", ("VL", "V", ("Landroid/os/Bundle;",)), "onCreate")
    app_init = ("Ltest/TestApplication;", ("V", "V", ()), "<init>")
    app_create = ("Ltest/TestApplication;", ("V", "V", ()), "onCreate")
    act_init = ("Ltest/TestActivity;", ("V", "V", ()), "<init>")
    act_create = ("Ltest/TestActivity;", ("VL", "V", ("Landroid/os/Bundle;",)), "onCreate")

    add_code(app_init, 1, 1, 1, invoke(0x70, app_base_init, [0]) + [0x000E])
    add_code(app_create, 1, 1, 0,
             [0x1012, 0x0067, fidx[("Ltest/TestApplication;", "I", "appMarker")], 0x000E])
    add_code(act_init, 1, 1, 1, invoke(0x70, act_base_init, [0]) + [0x000E])
    add_code(act_create, 2, 2, 2,
             invoke(0x6F, act_base_create, [0, 1]) +
             [0x1012, 0x0067, fidx[("Ltest/TestActivity;", "I", "activityMarker")], 0x000E])

    class_data_offsets = {}

    def add_class_data(desc, field, direct, virtual):
        class_data_offsets[desc] = len(data)
        data.extend(uleb(1)); data.extend(uleb(0)); data.extend(uleb(len(direct))); data.extend(uleb(len(virtual)))
        data.extend(uleb(fidx[field])); data.extend(uleb(0x9))  # public static
        for group in (direct, virtual):
            previous = 0
            for n, method in enumerate(sorted(group, key=lambda m: midx[m])):
                current = midx[method]
                data.extend(uleb(current if n == 0 else current - previous))
                data.extend(uleb(0x10001 if method[2] == "<init>" else (0x4 if desc.endswith("Activity;") else 0x1)))
                data.extend(uleb(code_offsets[method])); previous = current

    add_class_data("Ltest/TestApplication;", ("Ltest/TestApplication;", "I", "appMarker"), [app_init], [app_create])
    add_class_data("Ltest/TestActivity;", ("Ltest/TestActivity;", "I", "activityMarker"), [act_init], [act_create])

    # Identifier tables.
    for i, off in enumerate(string_offsets): struct.pack_into("<I", data, string_ids_off + i * 4, off)
    for i, t in enumerate(types): struct.pack_into("<I", data, type_ids_off + i * 4, sidx[t])
    for i, (shorty, ret, params) in enumerate(protos):
        struct.pack_into("<III", data, proto_ids_off + i * 12, sidx[shorty], tidx[ret], bundle_params_off if params else 0)
    for i, (owner, typ, name) in enumerate(fields):
        struct.pack_into("<HHI", data, field_ids_off + i * 8, tidx[owner], tidx[typ], sidx[name])
    for i, (owner, proto, name) in enumerate(methods):
        struct.pack_into("<HHI", data, method_ids_off + i * 8, tidx[owner], proto_index[proto], sidx[name])

    classes = [
        ("Ltest/TestApplication;", "Landroid/app/Application;", "TestApplication.java"),
        ("Ltest/TestActivity;", "Landroid/app/Activity;", "TestActivity.java"),
    ]
    for i, (desc, sup, source) in enumerate(classes):
        struct.pack_into("<IIIIIIII", data, class_defs_off + i * 32,
                         tidx[desc], 0x1, tidx[sup], 0, sidx[source], 0,
                         class_data_offsets[desc], 0)

    file_size = len(data)
    data_size = file_size - data_off
    header = struct.pack("<8sI20s20I", b"dex\n035\0", 0, b"\0" * 20,
                         file_size, header_size, 0x12345678, 0, 0, 0,
                         len(strings), string_ids_off, len(types), type_ids_off,
                         len(protos), proto_ids_off, len(fields), field_ids_off,
                         len(methods), method_ids_off, len(classes), class_defs_off,
                         data_size, data_off)
    data[:header_size] = header
    data[12:32] = hashlib.sha1(data[32:]).digest()
    struct.pack_into("<I", data, 8, zlib.adler32(data[12:]) & 0xFFFFFFFF)
    return bytes(data)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("output", type=pathlib.Path)
    args = parser.parse_args()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(build())


if __name__ == "__main__":
    main()
