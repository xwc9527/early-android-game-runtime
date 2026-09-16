# Native Bitmap/codec core

This module is the native implementation behind the current `BitmapFactory`
and `GLUtils.texImage2D` HLE boundary.  Python only owns test orchestration and
the final call into the existing GLES host bridge.

The decoder is built from Android 4.4.4 Skia's `SkImageDecoder.cpp`,
`SkImageDecoder_libpng.cpp`, decoder registry, `SkScaledBitmapSampler.cpp`, and
the minimum Skia bitmap/pixel-ref/stream support, with Android 4.4.4 libpng and
zlib.  `agr_bitmap.cpp` exposes opaque lifetime, dimensions, row bytes, config,
alpha type, pixels, and the GL format/type observed by KitKat `GLUtils`.

Pinned source revisions: Skia `54d95a38cb3a6db7e06f2cf94813f86ef84b4d00`,
libpng `b5e7fb4c103b3898cb78e9f7615cf7893626a5e9`, plus the already pinned
Android 4.4.4 zlib tree.

`host_skia_config.h` is the host-port boundary.  It suppresses Android's
build-wide configuration and preserves Android's little-endian RGBA
`SkPMColor` layout.  It does not alter the PNG decoder.

Only ARGB_8888 decode/upload is exposed for now.  Bitmap scaling, reuse,
nine-patch handling, Java density transforms, and non-PNG codec registration
remain outside this module until a real call path requires them.
