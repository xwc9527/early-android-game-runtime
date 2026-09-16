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
    AGR_GL_RGBA = 0x1908,
    AGR_GL_UNSIGNED_BYTE = 0x1401
};

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

#ifdef __cplusplus
}
#endif

#endif
