#!/usr/bin/env python3
"""DEX layouts for surface callback success and guest throws.

OkView returns from both callbacks. ThrowCreatedView throws from
surfaceCreated. ThrowChangedView returns from surfaceCreated and throws
from surfaceChanged. The thrown type is java.lang.RuntimeException.
"""

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


def utf16(text: str) -> bytes:
    return struct.pack("<H", len(text)) + text.encode("utf-16le")


def axml(root_name: str, child_name: str, child_id: int, width: int, height: int) -> bytes:
    strings = ["layout_width", "layout_height", "id", root_name, child_name]
    pool = bytearray()
    offsets = []
    for item in strings:
        offsets.append(len(pool))
        pool.extend(utf16(item))
    align(pool)
    string_count = len(strings)
    strings_start = 28 + 4 * string_count
    chunk = bytearray()
    chunk.extend(struct.pack("<HHIIIIII", 0x0001, 28, strings_start + len(pool),
                             string_count, 0, 0, strings_start, 0))
    for offset in offsets:
        chunk.extend(struct.pack("<I", offset))
    chunk.extend(pool)

    def start_tag(name_index: int, attrs: list) -> bytes:
        body = struct.pack("<IIHHHHHH", 0xFFFFFFFF, name_index, 20, 20, len(attrs), 0, 0, 0)
        raw = bytearray(body)
        for name, value_type, value in attrs:
            raw.extend(struct.pack("<III", 0xFFFFFFFF, name, 0xFFFFFFFF))
            raw.extend(struct.pack("<HBBI", 8, 0, value_type, value & 0xFFFFFFFF))
        header_size = 16
        return struct.pack("<HHII", 0x0102, header_size, header_size + len(raw), 0) + struct.pack("<I", 0xFFFFFFFF) + bytes(raw)

    def end_tag(name_index: int) -> bytes:
        return struct.pack("<HHIIIII", 0x0103, 16, 24, 0, 0xFFFFFFFF, 0xFFFFFFFF, name_index)

    match = 0xFFFFFFFF
    elements = start_tag(3, [(0, 0x10, match), (1, 0x10, match)])
    elements += start_tag(4, [(0, 0x10, width & 0xFFFFFFFF), (1, 0x10, height & 0xFFFFFFFF), (2, 0x01, child_id)])
    elements += end_tag(4)
    elements += end_tag(3)
    blob = struct.pack("<II", 0x00080003, 8 + len(chunk) + len(elements)) + bytes(chunk) + elements
    return blob


def build_dex() -> bytes:
    strings = sorted({
        "<init>", "I", "L", "Landroid/app/Activity;", "Landroid/app/Application;",
        "Landroid/content/Context;", "Landroid/os/Bundle;", "Landroid/util/AttributeSet;",
        "Landroid/view/SurfaceHolder;", "Landroid/view/SurfaceView;",
        "Ljava/lang/RuntimeException;", "Ltest/OkView;", "Ltest/OutcomeActivity;",
        "Ltest/OutcomeApplication;", "Ltest/ThrowChangedView;", "Ltest/ThrowCreatedView;",
        "OkView.java", "OutcomeActivity.java", "OutcomeApplication.java",
        "ThrowChangedView.java", "ThrowCreatedView.java", "V", "VL", "VLIII", "VLL",
        "addCallback", "getHolder", "onCreate", "surfaceChanged", "surfaceCreated",
    })
    sidx = {item: index for index, item in enumerate(strings)}
    types = sorted({item for item in strings if item in {"I", "V"} or item.startswith("L")},
                   key=lambda item: sidx[item])
    tidx = {item: index for index, item in enumerate(types)}
    protos = [
        ("V", "V", ()),
        ("VL", "V", ("Landroid/os/Bundle;",)),
        ("VLL", "V", ("Landroid/content/Context;", "Landroid/util/AttributeSet;")),
        ("VL", "V", ("Landroid/view/SurfaceHolder;",)),
        ("L", "Landroid/view/SurfaceHolder;", ()),
        ("VLIII", "V", ("Landroid/view/SurfaceHolder;", "I", "I", "I")),
    ]
    proto_index = {proto: index for index, proto in enumerate(protos)}
    fields = []
    fidx = {}
    methods = sorted([
        ("Landroid/app/Activity;", protos[0], "<init>"),
        ("Landroid/app/Activity;", protos[1], "onCreate"),
        ("Landroid/app/Application;", protos[0], "<init>"),
        ("Landroid/view/SurfaceHolder;", protos[3], "addCallback"),
        ("Landroid/view/SurfaceView;", protos[2], "<init>"),
        ("Landroid/view/SurfaceView;", protos[4], "getHolder"),
        ("Ljava/lang/RuntimeException;", protos[0], "<init>"),
        ("Ltest/OkView;", protos[2], "<init>"),
        ("Ltest/OkView;", protos[3], "surfaceCreated"),
        ("Ltest/OkView;", protos[5], "surfaceChanged"),
        ("Ltest/OutcomeActivity;", protos[0], "<init>"),
        ("Ltest/OutcomeActivity;", protos[1], "onCreate"),
        ("Ltest/OutcomeApplication;", protos[0], "<init>"),
        ("Ltest/OutcomeApplication;", protos[0], "onCreate"),
        ("Ltest/ThrowChangedView;", protos[2], "<init>"),
        ("Ltest/ThrowChangedView;", protos[3], "surfaceCreated"),
        ("Ltest/ThrowChangedView;", protos[5], "surfaceChanged"),
        ("Ltest/ThrowCreatedView;", protos[2], "<init>"),
        ("Ltest/ThrowCreatedView;", protos[3], "surfaceCreated"),
    ], key=lambda method: (tidx[method[0]], sidx[method[2]], proto_index[method[1]]))
    midx = {method: index for index, method in enumerate(methods)}

    def invoke(opcode, method, regs):
        count = len(regs)
        packed = sum((reg & 0xF) << (index * 4) for index, reg in enumerate(regs[:4]))
        fifth = regs[4] if count == 5 else 0
        return [opcode | (count << 12) | (fifth << 8), midx[method], packed]

    def new_instance(reg, type_name):
        return [0x22 | ((reg & 0xFF) << 8), tidx[type_name]]

    def throw_v(reg):
        return [0x27 | ((reg & 0xFF) << 8)]

    surface_init = ("Landroid/view/SurfaceView;", protos[2], "<init>")
    get_holder = ("Landroid/view/SurfaceView;", protos[4], "getHolder")
    add_callback = ("Landroid/view/SurfaceHolder;", protos[3], "addCallback")
    app_base_init = ("Landroid/app/Application;", protos[0], "<init>")
    act_base_init = ("Landroid/app/Activity;", protos[0], "<init>")
    act_base_create = ("Landroid/app/Activity;", protos[1], "onCreate")
    rte_init = ("Ljava/lang/RuntimeException;", protos[0], "<init>")
    ok_init = ("Ltest/OkView;", protos[2], "<init>")
    ok_created = ("Ltest/OkView;", protos[3], "surfaceCreated")
    ok_changed = ("Ltest/OkView;", protos[5], "surfaceChanged")
    created_init = ("Ltest/ThrowCreatedView;", protos[2], "<init>")
    created_throw = ("Ltest/ThrowCreatedView;", protos[3], "surfaceCreated")
    changed_init = ("Ltest/ThrowChangedView;", protos[2], "<init>")
    changed_created = ("Ltest/ThrowChangedView;", protos[3], "surfaceCreated")
    changed_throw = ("Ltest/ThrowChangedView;", protos[5], "surfaceChanged")
    app_init = ("Ltest/OutcomeApplication;", protos[0], "<init>")
    app_create = ("Ltest/OutcomeApplication;", protos[0], "onCreate")
    act_init = ("Ltest/OutcomeActivity;", protos[0], "<init>")
    act_create = ("Ltest/OutcomeActivity;", protos[1], "onCreate")
    guest_throw = new_instance(0, "Ljava/lang/RuntimeException;") + invoke(0x70, rte_init, [0]) + throw_v(0)
    register = invoke(0x70, surface_init, [0, 1, 2]) + invoke(0x6E, get_holder, [0]) + [0x010C] + invoke(0x72, add_callback, [1, 0]) + [0x000E]

    codes = {
        app_init: invoke(0x70, app_base_init, [0]) + [0x000E],
        app_create: [0x000E],
        act_init: invoke(0x70, act_base_init, [0]) + [0x000E],
        act_create: invoke(0x6F, act_base_create, [0, 1]) + [0x000E],
        ok_init: register,
        ok_created: [0x000E],
        ok_changed: [0x000E],
        created_init: register,
        created_throw: guest_throw,
        changed_init: register,
        changed_created: [0x000E],
        changed_throw: guest_throw,
    }

    header_size = 0x70
    class_count = 5
    data_off = (header_size + 4 * len(strings) + 4 * len(types) + 12 * len(protos) +
                8 * len(fields) + 8 * len(methods) + 32 * class_count)
    data = bytearray(b"\0" * data_off)
    string_offsets = []
    for item in strings:
        string_offsets.append(len(data))
        data.extend(uleb(len(item)))
        data.extend(item.encode("utf-8"))
        data.append(0)
    align(data)

    def param_list(type_names):
        if not type_names:
            return 0
        offset = len(data)
        data.extend(struct.pack("<I", len(type_names)))
        for name in type_names:
            data.extend(struct.pack("<H", tidx[name]))
        align(data)
        return offset

    proto_params = [param_list(proto[2]) for proto in protos]
    code_offsets = {}
    for key, words in codes.items():
        align(data)
        code_offsets[key] = len(data)
        registers = 4
        data.extend(struct.pack("<HHHHII", registers, registers, registers, 0, 0, len(words)))
        data.extend(struct.pack("<" + "H" * len(words), *words))

    def class_data(static_fields, direct, virtual):
        offset = len(data)
        data.extend(uleb(len(static_fields)))
        data.extend(uleb(0))
        data.extend(uleb(len(direct)))
        data.extend(uleb(len(virtual)))
        previous = 0
        for index, field in enumerate(sorted(static_fields, key=lambda item: fidx[item])):
            current = fidx[field]
            data.extend(uleb(current if index == 0 else current - previous))
            data.extend(uleb(0x9))
            previous = current
        for group in (direct, virtual):
            previous = 0
            for index, method in enumerate(sorted(group, key=lambda item: midx[item])):
                current = midx[method]
                data.extend(uleb(current if index == 0 else current - previous))
                flags = 0x10001 if method[2] == "<init>" else 0x1
                data.extend(uleb(flags))
                data.extend(uleb(code_offsets[method]))
                previous = current
        return offset

    class_data_offsets = {
        "Ltest/OutcomeApplication;": class_data([], [app_init], [app_create]),
        "Ltest/OutcomeActivity;": class_data([], [act_init], [act_create]),
        "Ltest/OkView;": class_data([], [ok_init], [ok_created, ok_changed]),
        "Ltest/ThrowCreatedView;": class_data([], [created_init], [created_throw]),
        "Ltest/ThrowChangedView;": class_data([], [changed_init], [changed_created, changed_throw]),
    }
    classes = [
        ("Ltest/OutcomeApplication;", "Landroid/app/Application;", "OutcomeApplication.java"),
        ("Ltest/OutcomeActivity;", "Landroid/app/Activity;", "OutcomeActivity.java"),
        ("Ltest/OkView;", "Landroid/view/SurfaceView;", "OkView.java"),
        ("Ltest/ThrowCreatedView;", "Landroid/view/SurfaceView;", "ThrowCreatedView.java"),
        ("Ltest/ThrowChangedView;", "Landroid/view/SurfaceView;", "ThrowChangedView.java"),
    ]
    string_ids_off = header_size
    type_ids_off = string_ids_off + 4 * len(strings)
    proto_ids_off = type_ids_off + 4 * len(types)
    field_ids_off = proto_ids_off + 12 * len(protos)
    method_ids_off = field_ids_off + 8 * len(fields)
    class_defs_off = method_ids_off + 8 * len(methods)
    for index, offset in enumerate(string_offsets):
        struct.pack_into("<I", data, string_ids_off + index * 4, offset)
    for index, name in enumerate(types):
        struct.pack_into("<I", data, type_ids_off + index * 4, sidx[name])
    for index, (shorty, ret, _params) in enumerate(protos):
        struct.pack_into("<III", data, proto_ids_off + index * 12,
                         sidx[shorty], tidx[ret], proto_params[index])
    for index, (owner, proto, name) in enumerate(methods):
        struct.pack_into("<HHI", data, method_ids_off + index * 8,
                         tidx[owner], proto_index[proto], sidx[name])
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
    parser.add_argument("dex_output", type=pathlib.Path)
    parser.add_argument("layout_dir", type=pathlib.Path)
    args = parser.parse_args()
    args.dex_output.parent.mkdir(parents=True, exist_ok=True)
    args.layout_dir.mkdir(parents=True, exist_ok=True)
    args.dex_output.write_bytes(build_dex())
    layouts = {
        "ok.xml": axml("FrameLayout", "test.OkView", 0x7F060020, 0xFFFFFFFF, 0xFFFFFFFF),
        "throw-created.xml": axml("FrameLayout", "test.ThrowCreatedView", 0x7F060021, 0xFFFFFFFF, 0xFFFFFFFF),
        "throw-changed.xml": axml("FrameLayout", "test.ThrowChangedView", 0x7F060022, 0xFFFFFFFF, 0xFFFFFFFF),
    }
    for name, blob in layouts.items():
        (args.layout_dir / name).write_bytes(blob)


if __name__ == "__main__":
    main()
