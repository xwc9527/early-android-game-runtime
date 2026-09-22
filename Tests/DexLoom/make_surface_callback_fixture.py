#!/usr/bin/env python3
"""DEX and binary layouts for the SurfaceHolder callback contract.

The activity does not register callbacks. Each SurfaceView subclass does that
in its own constructor, which is the guest path Frozen Bubble uses.
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
        "Landroid/view/Surface;", "Landroid/view/SurfaceHolder;", "Landroid/view/SurfaceView;",
        "Landroid/view/View;", "Ltest/CallbackView;", "Ltest/HiddenView;", "Ltest/RemovedView;",
        "Ltest/SurfaceActivity;", "Ltest/SurfaceApplication;", "CallbackView.java",
        "HiddenView.java", "RemovedView.java", "SurfaceActivity.java",
        "SurfaceApplication.java", "activityMarker", "appMarker", "V", "VI", "VL", "VLIII", "VLL", "addCallback",
        "changed", "created", "format", "getHolder", "getSurface", "height", "onCreate",
        "removeCallback", "requestLayout", "setVisibility", "surfaceChanged",
        "surfaceCreated", "width",
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
        ("L", "Landroid/view/Surface;", ()),
        ("VI", "V", ("I",)),
        ("VLIII", "V", ("Landroid/view/SurfaceHolder;", "I", "I", "I")),
    ]
    proto_index = {proto: index for index, proto in enumerate(protos)}
    fields = sorted([
        ("Ltest/CallbackView;", "I", "created"),
        ("Ltest/CallbackView;", "I", "changed"),
        ("Ltest/CallbackView;", "I", "format"),
        ("Ltest/CallbackView;", "I", "width"),
        ("Ltest/CallbackView;", "I", "height"),
        ("Ltest/SurfaceActivity;", "I", "activityMarker"),
        ("Ltest/SurfaceApplication;", "I", "appMarker"),
    ], key=lambda field: (tidx[field[0]], sidx[field[2]], tidx[field[1]]))
    fidx = {field: index for index, field in enumerate(fields)}
    methods = sorted([
        ("Landroid/app/Activity;", protos[0], "<init>"),
        ("Landroid/app/Activity;", protos[1], "onCreate"),
        ("Landroid/app/Application;", protos[0], "<init>"),
        ("Landroid/view/SurfaceHolder;", protos[3], "addCallback"),
        ("Landroid/view/SurfaceHolder;", protos[3], "removeCallback"),
        ("Landroid/view/SurfaceHolder;", protos[5], "getSurface"),
        ("Landroid/view/SurfaceView;", protos[2], "<init>"),
        ("Landroid/view/SurfaceView;", protos[4], "getHolder"),
        ("Landroid/view/View;", protos[6], "setVisibility"),
        ("Landroid/view/View;", protos[0], "requestLayout"),
        ("Ltest/CallbackView;", protos[2], "<init>"),
        ("Ltest/CallbackView;", protos[3], "surfaceCreated"),
        ("Ltest/CallbackView;", protos[7], "surfaceChanged"),
        ("Ltest/HiddenView;", protos[2], "<init>"),
        ("Ltest/RemovedView;", protos[2], "<init>"),
        ("Ltest/SurfaceActivity;", protos[0], "<init>"),
        ("Ltest/SurfaceActivity;", protos[1], "onCreate"),
        ("Ltest/SurfaceApplication;", protos[0], "<init>"),
        ("Ltest/SurfaceApplication;", protos[0], "onCreate"),
    ], key=lambda method: (tidx[method[0]], sidx[method[2]], proto_index[method[1]]))
    midx = {method: index for index, method in enumerate(methods)}

    def invoke(opcode, method, regs):
        count = len(regs)
        packed = sum((reg & 0xF) << (index * 4) for index, reg in enumerate(regs[:4]))
        fifth = regs[4] if count == 5 else 0
        return [opcode | (count << 12) | (fifth << 8), midx[method], packed]

    def sput(reg, field):
        return [(reg << 8) | 0x67, fidx[field]]

    def sget(reg, field):
        return [(reg << 8) | 0x60, fidx[field]]

    surface_init = ("Landroid/view/SurfaceView;", protos[2], "<init>")
    get_holder = ("Landroid/view/SurfaceView;", protos[4], "getHolder")
    add_callback = ("Landroid/view/SurfaceHolder;", protos[3], "addCallback")
    remove_callback = ("Landroid/view/SurfaceHolder;", protos[3], "removeCallback")
    get_surface = ("Landroid/view/SurfaceHolder;", protos[5], "getSurface")
    set_visibility = ("Landroid/view/View;", protos[6], "setVisibility")
    request_layout = ("Landroid/view/View;", protos[0], "requestLayout")
    app_base_init = ("Landroid/app/Application;", protos[0], "<init>")
    act_base_init = ("Landroid/app/Activity;", protos[0], "<init>")
    act_base_create = ("Landroid/app/Activity;", protos[1], "onCreate")
    callback_init = ("Ltest/CallbackView;", protos[2], "<init>")
    callback_created = ("Ltest/CallbackView;", protos[3], "surfaceCreated")
    callback_changed = ("Ltest/CallbackView;", protos[7], "surfaceChanged")
    hidden_init = ("Ltest/HiddenView;", protos[2], "<init>")
    removed_init = ("Ltest/RemovedView;", protos[2], "<init>")
    app_init = ("Ltest/SurfaceApplication;", protos[0], "<init>")
    app_create = ("Ltest/SurfaceApplication;", protos[0], "onCreate")
    act_init = ("Ltest/SurfaceActivity;", protos[0], "<init>")
    act_create = ("Ltest/SurfaceActivity;", protos[1], "onCreate")
    created_field = ("Ltest/CallbackView;", "I", "created")
    changed_field = ("Ltest/CallbackView;", "I", "changed")
    format_field = ("Ltest/CallbackView;", "I", "format")
    width_field = ("Ltest/CallbackView;", "I", "width")
    height_field = ("Ltest/CallbackView;", "I", "height")

    codes = {
        app_init: invoke(0x70, app_base_init, [0]) + [0x000E],
        app_create: [0x1012, 0x0067, fidx[("Ltest/SurfaceApplication;", "I", "appMarker")], 0x000E],
        act_init: invoke(0x70, act_base_init, [0]) + [0x000E],
        act_create: invoke(0x6F, act_base_create, [0, 1]) +
                    [0x1012, 0x0067, fidx[("Ltest/SurfaceActivity;", "I", "activityMarker")], 0x000E],
        callback_init: invoke(0x70, surface_init, [0, 1, 2]) +
                       invoke(0x6E, get_holder, [0]) + [0x010C] +
                       invoke(0x72, add_callback, [1, 0]) + [0x000E],
        callback_created: invoke(0x72, get_surface, [1]) + [0x020C, 0x0238, 0x0008] +
                          sget(2, created_field) + [0x02D8, 0x0102] + sput(2, created_field) + [0x000E],
        callback_changed: sget(5, changed_field) + [0x05D8, 0x0105] + sput(5, changed_field) +
                          sput(2, format_field) + sput(3, width_field) + sput(4, height_field) +
                          invoke(0x6E, request_layout, [0]) + [0x000E],
        hidden_init: invoke(0x70, surface_init, [0, 1, 2]) + [0x4312] +
                     invoke(0x6E, set_visibility, [0, 3]) +
                     invoke(0x6E, get_holder, [0]) + [0x030C] +
                     invoke(0x72, add_callback, [3, 0]) + [0x000E],
        removed_init: invoke(0x70, surface_init, [0, 1, 2]) +
                      invoke(0x6E, get_holder, [0]) + [0x030C] +
                      invoke(0x72, add_callback, [3, 0]) +
                      invoke(0x72, remove_callback, [3, 0]) + [0x000E],
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
        registers = 6 if key == callback_changed else 4
        data.extend(struct.pack("<HHHHII", registers, registers, registers, 0, 0, len(words)))
        data.extend(struct.pack("<" + "H" * len(words), *words))

    def class_data(desc, static_fields, direct, virtual):
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
        "Ltest/SurfaceApplication;": class_data(
            "Ltest/SurfaceApplication;",
            [("Ltest/SurfaceApplication;", "I", "appMarker")], [app_init], [app_create]),
        "Ltest/SurfaceActivity;": class_data(
            "Ltest/SurfaceActivity;",
            [("Ltest/SurfaceActivity;", "I", "activityMarker")], [act_init], [act_create]),
        "Ltest/CallbackView;": class_data(
            "Ltest/CallbackView;",
            [created_field, changed_field, format_field, width_field, height_field],
            [callback_init], [callback_created, callback_changed]),
        "Ltest/HiddenView;": class_data("Ltest/HiddenView;", [], [hidden_init], []),
        "Ltest/RemovedView;": class_data("Ltest/RemovedView;", [], [removed_init], []),
    }
    classes = [
        ("Ltest/SurfaceApplication;", "Landroid/app/Application;", "SurfaceApplication.java"),
        ("Ltest/SurfaceActivity;", "Landroid/app/Activity;", "SurfaceActivity.java"),
        ("Ltest/CallbackView;", "Landroid/view/SurfaceView;", "CallbackView.java"),
        ("Ltest/HiddenView;", "Landroid/view/SurfaceView;", "HiddenView.java"),
        ("Ltest/RemovedView;", "Landroid/view/SurfaceView;", "RemovedView.java"),
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
    for index, (owner, typ, name) in enumerate(fields):
        struct.pack_into("<HHI", data, field_ids_off + index * 8, tidx[owner], tidx[typ], sidx[name])
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
        "callback.xml": axml("FrameLayout", "test.CallbackView", 0x7F060010, 0xFFFFFFFF, 0xFFFFFFFF),
        "hidden.xml": axml("FrameLayout", "test.HiddenView", 0x7F060011, 0xFFFFFFFF, 0xFFFFFFFF),
        "zero.xml": axml("FrameLayout", "test.CallbackView", 0x7F060012, 0, 0),
        "removed.xml": axml("FrameLayout", "test.RemovedView", 0x7F060013, 0xFFFFFFFF, 0xFFFFFFFF),
    }
    for name, blob in layouts.items():
        (args.layout_dir / name).write_bytes(blob)


if __name__ == "__main__":
    main()
