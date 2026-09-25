"""Check whether an Android screencap contains more than one RGB color."""

import struct
import zlib


def has_visible_variation(path):
    data = path.read_bytes()
    if not data.startswith(b"\x89PNG\r\n\x1a\n"):
        raise ValueError("not a PNG")
    offset = 8
    pixels = bytearray()
    width = height = channels = None
    while offset < len(data):
        size = struct.unpack_from(">I", data, offset)[0]
        name = data[offset + 4:offset + 8]
        chunk = data[offset + 8:offset + 8 + size]
        offset += 12 + size
        if name == b"IHDR":
            width, height, depth, color, compression, filtering, interlace = \
                struct.unpack(">IIBBBBB", chunk)
            if depth != 8 or color not in (2, 6) or compression or filtering or interlace:
                raise ValueError("unsupported screenshot PNG format")
            channels = 3 if color == 2 else 4
        elif name == b"IDAT":
            pixels.extend(chunk)
        elif name == b"IEND":
            break
    if not width or not height or not pixels:
        raise ValueError("incomplete screenshot PNG")
    raw = zlib.decompress(pixels)
    stride = width * channels
    if len(raw) != height * (stride + 1):
        raise ValueError("incorrect screenshot PNG dimensions")
    previous = bytearray(stride)
    first = None
    for row_index in range(height):
        start = row_index * (stride + 1)
        filtering = raw[start]
        line = bytearray(raw[start + 1:start + 1 + stride])
        if filtering not in range(5):
            raise ValueError("invalid screenshot PNG filter")
        for i in range(stride):
            left = line[i - channels] if i >= channels else 0
            above = previous[i]
            upper_left = previous[i - channels] if i >= channels else 0
            if filtering == 1:
                predictor = left
            elif filtering == 2:
                predictor = above
            elif filtering == 3:
                predictor = (left + above) // 2
            elif filtering == 4:
                p = left + above - upper_left
                distances = (abs(p - left), abs(p - above), abs(p - upper_left))
                predictor = (left, above, upper_left)[distances.index(min(distances))]
            else:
                predictor = 0
            line[i] = (line[i] + predictor) & 255
        for i in range(0, stride, channels):
            color = bytes(line[i:i + 3])
            if first is None:
                first = color
            elif color != first:
                return True
        previous = line
    return False
