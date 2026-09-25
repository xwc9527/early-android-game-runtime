import struct
import tempfile
import unittest
import zlib
from pathlib import Path

from png_frame import has_visible_variation


def chunk(name, payload):
    body = name + payload
    return struct.pack(">I", len(payload)) + body + struct.pack(">I", zlib.crc32(body))


class PngFrameTest(unittest.TestCase):
    def test_uniform_and_varied_rgb_frames(self):
        header = b"\x89PNG\r\n\x1a\n" + chunk(
            b"IHDR", struct.pack(">IIBBBBB", 2, 1, 8, 2, 0, 0, 0))
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "frame.png"
            path.write_bytes(header + chunk(b"IDAT", zlib.compress(
                b"\x00\x00\x00\x00\x00\x00\x00")) + chunk(b"IEND", b""))
            self.assertFalse(has_visible_variation(path))
            path.write_bytes(header + chunk(b"IDAT", zlib.compress(
                b"\x00\x00\x00\x00\xff\x00\x00")) + chunk(b"IEND", b""))
            self.assertTrue(has_visible_variation(path))


if __name__ == "__main__":
    unittest.main()
