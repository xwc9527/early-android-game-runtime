#ifndef AGR_BITMAP_H
#define AGR_BITMAP_H

#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32
#define AGR_BITMAP_API __declspec(dllexport)
#else
#define AGR_BITMAP_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct agr_bitmap agr_bitmap;

enum {
    AGR_BITMAP_CONFIG_ARGB_8888 = 5,
    /* Matches SkAlphaType on the KitKat Skia build used by this module. */
    AGR_BITMAP_ALPHA_IGNORE = 0,
    AGR_BITMAP_ALPHA_OPAQUE = 1,
    AGR_BITMAP_ALPHA_PREMUL = 2,
    AGR_BITMAP_ALPHA_UNPREMUL = 3,
    AGR_GL_RGBA = 0x1908,
    AGR_GL_UNSIGNED_BYTE = 0x1401
};

/*
 * Decoded pixels are SkPMColor with the Android host layout from
 * Runtime/Bitmap/host_skia_config.h on little-endian hosts:
 *   byte0 = R, byte1 = G, byte2 = B, byte3 = A
 * (SK_R32_SHIFT=0, SK_G32_SHIFT=8, SK_B32_SHIFT=16, SK_A32_SHIFT=24).
 * PNG/JPEG/GIF decode through KitKat SkImageDecoder to kARGB_8888_Config.
 * The alpha type is usually premultiplied after decode.
 */
AGR_BITMAP_API agr_bitmap* agr_bitmap_decode(const void* encoded, size_t size);
AGR_BITMAP_API void agr_bitmap_destroy(agr_bitmap* bitmap);
AGR_BITMAP_API uint32_t agr_bitmap_width(const agr_bitmap* bitmap);
AGR_BITMAP_API uint32_t agr_bitmap_height(const agr_bitmap* bitmap);
AGR_BITMAP_API size_t agr_bitmap_row_bytes(const agr_bitmap* bitmap);
AGR_BITMAP_API size_t agr_bitmap_byte_count(const agr_bitmap* bitmap);
AGR_BITMAP_API int agr_bitmap_config(const agr_bitmap* bitmap);
AGR_BITMAP_API int agr_bitmap_alpha_type(const agr_bitmap* bitmap);
AGR_BITMAP_API int agr_bitmap_gl_internal_format(const agr_bitmap* bitmap);
AGR_BITMAP_API int agr_bitmap_gl_type(const agr_bitmap* bitmap);
AGR_BITMAP_API const void* agr_bitmap_pixels(const agr_bitmap* bitmap);
AGR_BITMAP_API const char* agr_bitmap_decoder_name(void);

/*
 * Blit source onto a destination buffer that uses the same host SkPMColor /
 * RGBA8888 memory layout and row bytes as agr_bitmap_pixels.
 * left/top are API19 Canvas float coordinates (floor to the pixel grid).
 * clip_* are exclusive destination clip bounds.
 * Returns the number of destination pixels written, or -1 on error.
 * Completely off-screen sources return 0.
 */
AGR_BITMAP_API int agr_bitmap_draw(const agr_bitmap* src,
                                   void* dst_pixels,
                                   int dst_w,
                                   int dst_h,
                                   size_t dst_row_bytes,
                                   float left,
                                   float top,
                                   int clip_left,
                                   int clip_top,
                                   int clip_right,
                                   int clip_bottom);

#ifdef __cplusplus
}
#endif

#endif
