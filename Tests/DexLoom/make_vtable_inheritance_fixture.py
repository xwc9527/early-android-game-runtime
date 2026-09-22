#!/usr/bin/env python3
"""DEX fixture for framework/guest vtable slot identity."""

import argparse
import hashlib
import pathlib
import struct
import zlib


def uleb(value: int) -> bytes:
    out = bytearray()
    while True:
        byte = value & 0x7F
        value >>= 7
        out.append(byte | (0x80 if value else 0))
        if not value:
            return bytes(out)


def align(data: bytearray, amount: int = 4) -> None:
    while len(data) % amount:
        data.append(0)


def build() -> bytes:
    strings = sorted({
        "<init>", "Base.java", "I", "IL", "Kid.java", "L", "Lsynth/Base;",
        "Lsynth/Kid;", "Lsynth/Markers;", "Lsynth/ObjChild;", "Lsynth/ObjOver;",
        "Lsynth/Probe;", "Lsynth/Worker;", "Ljava/lang/Object;", "Ljava/lang/Thread;",
        "Markers.java", "ObjChild.java", "ObjOver.java", "Probe.java", "V",
        "Worker.java", "a", "b", "c", "cleanUp", "hashCode", "hit", "probeBaseB",
        "probeC", "probeHash", "probeKidA", "probeKidB", "probeKidC", "probeOverC",
        "probeOverHash", "probeOverToString", "probeStart", "probeToString", "run",
        "start", "toString",
    })
    sidx = {text: index for index, text in enumerate(strings)}
    types = sorted({text for text in strings if text.startswith("L") or text in {"I", "V"}},
                   key=lambda text: sidx[text])
    tidx = {text: index for index, text in enumerate(types)}
    protos = [
        ("V", "V", ()),
        ("I", "I", ()),
        ("L", "Ljava/lang/Object;", ()),
        ("IL", "I", ("Lsynth/ObjChild;",)),
        ("IL", "I", ("Lsynth/ObjOver;",)),
        ("IL", "I", ("Lsynth/Base;",)),
        ("IL", "I", ("Lsynth/Kid;",)),
        ("IL", "I", ("Lsynth/Worker;",)),
    ]
    proto_index = {proto: index for index, proto in enumerate(protos)}

    fields = [("Lsynth/Markers;", "I", "hit")]
    fidx = {field: index for index, field in enumerate(fields)}

    def method(owner, proto, name):
        return (owner, proto, name)

    methods = sorted([
        method("Ljava/lang/Object;", protos[0], "<init>"),
        method("Ljava/lang/Object;", protos[2], "toString"),
        method("Ljava/lang/Object;", protos[1], "hashCode"),
        method("Ljava/lang/Thread;", protos[0], "start"),
        method("Lsynth/ObjChild;", protos[0], "<init>"),
        method("Lsynth/ObjChild;", protos[1], "c"),
        method("Lsynth/ObjOver;", protos[0], "<init>"),
        method("Lsynth/ObjOver;", protos[1], "hashCode"),
        method("Lsynth/ObjOver;", protos[1], "c"),
        method("Lsynth/Base;", protos[0], "<init>"),
        method("Lsynth/Base;", protos[1], "a"),
        method("Lsynth/Base;", protos[1], "b"),
        method("Lsynth/Kid;", protos[0], "<init>"),
        method("Lsynth/Kid;", protos[1], "b"),
        method("Lsynth/Kid;", protos[1], "c"),
        method("Lsynth/Worker;", protos[0], "<init>"),
        method("Lsynth/Worker;", protos[0], "cleanUp"),
        method("Lsynth/Worker;", protos[0], "run"),
        method("Lsynth/Probe;", protos[3], "probeToString"),
        method("Lsynth/Probe;", protos[3], "probeHash"),
        method("Lsynth/Probe;", protos[3], "probeC"),
        method("Lsynth/Probe;", protos[4], "probeOverHash"),
        method("Lsynth/Probe;", protos[4], "probeOverC"),
        method("Lsynth/Probe;", protos[4], "probeOverToString"),
        method("Lsynth/Probe;", protos[5], "probeBaseB"),
        method("Lsynth/Probe;", protos[6], "probeKidA"),
        method("Lsynth/Probe;", protos[6], "probeKidB"),
        method("Lsynth/Probe;", protos[6], "probeKidC"),
        method("Lsynth/Probe;", protos[7], "probeStart"),
    ], key=lambda item: (tidx[item[0]], sidx[item[2]], proto_index[item[1]]))
    midx = {item: index for index, item in enumerate(methods)}

    classes = [
        ("Lsynth/Markers;", "Ljava/lang/Object;", "Markers.java"),
        ("Lsynth/ObjChild;", "Ljava/lang/Object;", "ObjChild.java"),
        ("Lsynth/ObjOver;", "Ljava/lang/Object;", "ObjOver.java"),
        ("Lsynth/Base;", "Ljava/lang/Object;", "Base.java"),
        ("Lsynth/Kid;", "Lsynth/Base;", "Kid.java"),
        ("Lsynth/Worker;", "Ljava/lang/Thread;", "Worker.java"),
        ("Lsynth/Probe;", "Ljava/lang/Object;", "Probe.java"),
    ]
    header_size = 0x70
    string_ids_off = header_size
    type_ids_off = string_ids_off + 4 * len(strings)
    proto_ids_off = type_ids_off + 4 * len(types)
    field_ids_off = proto_ids_off + 12 * len(protos)
    method_ids_off = field_ids_off + 8 * len(fields)
    class_defs_off = method_ids_off + 8 * len(methods)
    data_off = class_defs_off + 32 * len(classes)
    data = bytearray(b"\0" * data_off)

    string_offsets = []
    for text in strings:
        string_offsets.append(len(data))
        raw = text.encode("utf-8")
        data.extend(uleb(len(text)))
        data.extend(raw)
        data.append(0)
    align(data)

    param_offs = {}
    for proto in protos:
        params = proto[2]
        if not params or params in param_offs:
            continue
        param_offs[params] = len(data)
        data.extend(struct.pack("<I", len(params)))
        for param in params:
            data.extend(struct.pack("<H", tidx[param]))
        align(data)

    code_offsets = {}

    def add_code(key, registers, ins, outs, words):
        align(data)
        code_offsets[key] = len(data)
        data.extend(struct.pack("<HHHHII", registers, ins, outs, 0, 0, len(words)))
        data.extend(struct.pack("<" + "H" * len(words), *words))

    def invoke(opcode, owner, proto, name, regs):
        count = len(regs)
        encoded = sum((reg & 0xF) << (index * 4) for index, reg in enumerate(regs[:4]))
        fifth = regs[4] if count == 5 else 0
        return [opcode | (count << 12) | (fifth << 8), midx[method(owner, proto, name)], encoded]

    def const4(reg, value):
        return [0x12 | ((reg & 0xF) << 8) | ((value & 0xF) << 12)]

    def const32(reg, value):
        value &= 0xFFFFFFFF
        return [0x14 | ((reg & 0xFF) << 8), value & 0xFFFF, (value >> 16) & 0xFFFF]

    def sput(reg, field):
        return [0x67 | ((reg & 0xFF) << 8), fidx[field]]

    def sget(reg, field):
        return [0x60 | ((reg & 0xFF) << 8), fidx[field]]

    def ret_int(reg):
        return [0x0F | ((reg & 0xFF) << 8)]

    hit = ("Lsynth/Markers;", "I", "hit")
    obj_init = ("Ljava/lang/Object;", protos[0], "<init>")
    base_init = ("Lsynth/Base;", protos[0], "<init>")

    def ret_const(key, value):
        words = const32(0, value) if value > 7 else const4(0, value)
        words += sput(0, hit) + ret_int(0)
        add_code(key, 2, 1, 0, words)

    child_init = method("Lsynth/ObjChild;", protos[0], "<init>")
    child_c = method("Lsynth/ObjChild;", protos[1], "c")
    over_init = method("Lsynth/ObjOver;", protos[0], "<init>")
    over_hash = method("Lsynth/ObjOver;", protos[1], "hashCode")
    over_c = method("Lsynth/ObjOver;", protos[1], "c")
    base_a = method("Lsynth/Base;", protos[1], "a")
    base_b = method("Lsynth/Base;", protos[1], "b")
    kid_init = method("Lsynth/Kid;", protos[0], "<init>")
    kid_b = method("Lsynth/Kid;", protos[1], "b")
    kid_c = method("Lsynth/Kid;", protos[1], "c")
    worker_init = method("Lsynth/Worker;", protos[0], "<init>")
    worker_cleanup = method("Lsynth/Worker;", protos[0], "cleanUp")
    worker_run = method("Lsynth/Worker;", protos[0], "run")

    add_code(child_init, 1, 1, 1, invoke(0x70, *obj_init, [0]) + [0x000E])
    ret_const(child_c, 5)
    add_code(over_init, 1, 1, 1, invoke(0x70, *obj_init, [0]) + [0x000E])
    ret_const(over_hash, 0x13572468)
    ret_const(over_c, 6)
    add_code(method("Lsynth/Base;", protos[0], "<init>"), 1, 1, 1, invoke(0x70, *obj_init, [0]) + [0x000E])
    ret_const(base_a, 1)
    ret_const(base_b, 2)
    add_code(kid_init, 1, 1, 1, invoke(0x70, *base_init, [0]) + [0x000E])
    ret_const(kid_b, 8)
    ret_const(kid_c, 3)
    add_code(worker_init, 1, 1, 1, invoke(0x70, *obj_init, [0]) + [0x000E])
    add_code(worker_cleanup, 2, 1, 0, [0x0013, 20, 0x0067, fidx[hit], 0x000E])
    add_code(worker_run, 2, 1, 0, [0x0013, 11, 0x0067, fidx[hit], 0x000E])

    def probe_ignore(key, owner, proto, name, arg_proto):
        add_code(key, 2, 1, 1, invoke(0x6E, owner, proto, name, [1]) + const4(0, 1) + ret_int(0))

    def probe_result(key, owner, proto, name):
        add_code(key, 2, 1, 1, invoke(0x6E, owner, proto, name, [1]) + [0x000A] + ret_int(0))

    probe_ignore(method("Lsynth/Probe;", protos[3], "probeToString"), "Ljava/lang/Object;", protos[2], "toString", None)
    probe_result(method("Lsynth/Probe;", protos[3], "probeHash"), "Ljava/lang/Object;", protos[1], "hashCode")
    probe_result(method("Lsynth/Probe;", protos[3], "probeC"), "Lsynth/ObjChild;", protos[1], "c")
    probe_result(method("Lsynth/Probe;", protos[4], "probeOverHash"), "Ljava/lang/Object;", protos[1], "hashCode")
    probe_result(method("Lsynth/Probe;", protos[4], "probeOverC"), "Lsynth/ObjOver;", protos[1], "c")
    probe_ignore(method("Lsynth/Probe;", protos[4], "probeOverToString"), "Ljava/lang/Object;", protos[2], "toString", None)
    probe_result(method("Lsynth/Probe;", protos[5], "probeBaseB"), "Lsynth/Base;", protos[1], "b")
    probe_result(method("Lsynth/Probe;", protos[6], "probeKidA"), "Lsynth/Base;", protos[1], "a")
    probe_result(method("Lsynth/Probe;", protos[6], "probeKidB"), "Lsynth/Base;", protos[1], "b")
    probe_result(method("Lsynth/Probe;", protos[6], "probeKidC"), "Lsynth/Kid;", protos[1], "c")
    add_code(method("Lsynth/Probe;", protos[7], "probeStart"), 2, 1, 1,
             invoke(0x6E, "Ljava/lang/Thread;", protos[0], "start", [1]) + sget(0, hit) + ret_int(0))

    class_data_offsets = {}

    def add_class_data(desc, static_fields, direct, virtual):
        class_data_offsets[desc] = len(data)
        data.extend(uleb(len(static_fields)))
        data.extend(uleb(0))
        data.extend(uleb(len(direct)))
        data.extend(uleb(len(virtual)))
        previous = 0
        for index, field in enumerate(static_fields):
            current = fidx[field]
            data.extend(uleb(current if index == 0 else current - previous))
            data.extend(uleb(0x9))
            previous = current
        for group, default_access in ((direct, 0x9), (virtual, 0x1)):
            previous = 0
            ordered = sorted(group, key=lambda item: midx[item[0]])
            for index, (item, access) in enumerate(ordered):
                current = midx[item]
                data.extend(uleb(current if index == 0 else current - previous))
                data.extend(uleb(access))
                data.extend(uleb(code_offsets[item]))
                previous = current

    add_class_data("Lsynth/Markers;", [hit], [], [])
    add_class_data("Lsynth/ObjChild;", [], [(child_init, 0x10001)], [(child_c, 0x1)])
    add_class_data("Lsynth/ObjOver;", [], [(over_init, 0x10001)], [(over_hash, 0x1), (over_c, 0x1)])
    add_class_data("Lsynth/Base;", [], [(method("Lsynth/Base;", protos[0], "<init>"), 0x10001)],
                   [(base_a, 0x1), (base_b, 0x1)])
    add_class_data("Lsynth/Kid;", [], [(kid_init, 0x10001)], [(kid_b, 0x1), (kid_c, 0x1)])
    add_class_data("Lsynth/Worker;", [], [(worker_init, 0x10001)],
                   [(worker_cleanup, 0x1), (worker_run, 0x1)])
    add_class_data("Lsynth/Probe;", [], [
        (method("Lsynth/Probe;", protos[3], "probeToString"), 0x9),
        (method("Lsynth/Probe;", protos[3], "probeHash"), 0x9),
        (method("Lsynth/Probe;", protos[3], "probeC"), 0x9),
        (method("Lsynth/Probe;", protos[4], "probeOverHash"), 0x9),
        (method("Lsynth/Probe;", protos[4], "probeOverC"), 0x9),
        (method("Lsynth/Probe;", protos[4], "probeOverToString"), 0x9),
        (method("Lsynth/Probe;", protos[5], "probeBaseB"), 0x9),
        (method("Lsynth/Probe;", protos[6], "probeKidA"), 0x9),
        (method("Lsynth/Probe;", protos[6], "probeKidB"), 0x9),
        (method("Lsynth/Probe;", protos[6], "probeKidC"), 0x9),
        (method("Lsynth/Probe;", protos[7], "probeStart"), 0x9),
    ], [])

    for index, offset in enumerate(string_offsets):
        struct.pack_into("<I", data, string_ids_off + index * 4, offset)
    for index, text in enumerate(types):
        struct.pack_into("<I", data, type_ids_off + index * 4, sidx[text])
    for index, (shorty, ret, params) in enumerate(protos):
        struct.pack_into("<III", data, proto_ids_off + index * 12, sidx[shorty], tidx[ret],
                         param_offs.get(params, 0))
    for index, (owner, typ, name) in enumerate(fields):
        struct.pack_into("<HHI", data, field_ids_off + index * 8, tidx[owner], tidx[typ], sidx[name])
    for index, (owner, proto, name) in enumerate(methods):
        struct.pack_into("<HHI", data, method_ids_off + index * 8, tidx[owner], proto_index[proto], sidx[name])
    for index, (desc, sup, source) in enumerate(classes):
        struct.pack_into("<IIIIIIII", data, class_defs_off + index * 32,
                         tidx[desc], 0x1, tidx[sup], 0, sidx[source], 0,
                         class_data_offsets[desc], 0)

    file_size = len(data)
    header = struct.pack("<8sI20s20I", b"dex\n035\0", 0, b"\0" * 20,
                         file_size, header_size, 0x12345678, 0, 0, 0,
                         len(strings), string_ids_off, len(types), type_ids_off,
                         len(protos), proto_ids_off, len(fields), field_ids_off,
                         len(methods), method_ids_off, len(classes), class_defs_off,
                         file_size - data_off, data_off)
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
