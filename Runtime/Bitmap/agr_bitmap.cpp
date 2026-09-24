#include "agr_bitmap.h"

#include "SkBitmap.h"
#include "SkColorPriv.h"
#include "SkImageDecoder.h"
#include "SkStream.h"

#include <math.h>
#include <string.h>

/* SkColorPriv's SkAlphaMulQ references this Skia global from SkBlitter.cpp.
   The Linux host bitmap contract does not link the full blitter. */
const uint32_t gMask_00FF00FF = 0x00FF00FF;

SkBitmap::Config SkImageInfoToBitmapConfig(const SkImageInfo& info) {
    switch (info.fColorType) {
        case kAlpha_8_SkColorType: return SkBitmap::kA8_Config;
        case kARGB_4444_SkColorType: return SkBitmap::kARGB_4444_Config;
        case kRGB_565_SkColorType: return SkBitmap::kRGB_565_Config;
        case kPMColor_SkColorType: return SkBitmap::kARGB_8888_Config;
        case kIndex_8_SkColorType: return SkBitmap::kIndex8_Config;
        default: return SkBitmap::kNo_Config;
    }
}

struct agr_bitmap {
    SkBitmap bitmap;
};

static bool agr_bitmap_expand_to_8888(SkBitmap* bitmap) {
    if (!bitmap || !bitmap->getPixels()) return false;
    if (bitmap->config() == SkBitmap::kARGB_8888_Config) return true;

    SkBitmap dst;
    dst.setConfig(SkBitmap::kARGB_8888_Config, bitmap->width(), bitmap->height());
    dst.setAlphaType(bitmap->alphaType());
    if (!dst.allocPixels()) return false;

    const int width = bitmap->width();
    const int height = bitmap->height();
    const size_t dst_rb = dst.rowBytes();
    uint8_t* dst_base = static_cast<uint8_t*>(dst.getPixels());

    if (bitmap->config() == SkBitmap::kIndex8_Config) {
        SkColorTable* table = bitmap->getColorTable();
        if (!table) return false;
        const SkPMColor* colors = table->lockColors();
        const uint8_t* src_base = static_cast<const uint8_t*>(bitmap->getPixels());
        const size_t src_rb = bitmap->rowBytes();
        for (int y = 0; y < height; ++y) {
            const uint8_t* src = src_base + (size_t)y * src_rb;
            uint32_t* out = reinterpret_cast<uint32_t*>(dst_base + (size_t)y * dst_rb);
            for (int x = 0; x < width; ++x) out[x] = colors[src[x]];
        }
        table->unlockColors();
        bitmap->swap(dst);
        return true;
    }

    if (bitmap->config() == SkBitmap::kRGB_565_Config) {
        const uint16_t* src_base = static_cast<const uint16_t*>(bitmap->getPixels());
        const size_t src_rb = bitmap->rowBytes();
        for (int y = 0; y < height; ++y) {
            const uint16_t* src = reinterpret_cast<const uint16_t*>(
                reinterpret_cast<const uint8_t*>(src_base) + (size_t)y * src_rb);
            uint32_t* out = reinterpret_cast<uint32_t*>(dst_base + (size_t)y * dst_rb);
            for (int x = 0; x < width; ++x) {
                out[x] = SkPixel16ToPixel32(src[x]);
            }
        }
        bitmap->swap(dst);
        return true;
    }

    return false;
}

class AgrMemoryStream : public SkStreamRewindable {
public:
    AgrMemoryStream(const void* data, size_t size)
        : data_(static_cast<const unsigned char*>(data)), size_(size), position_(0) {}
    virtual size_t read(void* buffer, size_t size) {
        size_t remaining = size_ - position_;
        if (size > remaining) size = remaining;
        if (buffer && size) memcpy(buffer, data_ + position_, size);
        position_ += size;
        return size;
    }
    virtual bool isAtEnd() const { return position_ == size_; }
    virtual bool rewind() { position_ = 0; return true; }
    virtual SkStreamRewindable* duplicate() const {
        return new AgrMemoryStream(data_, size_);
    }
private:
    const unsigned char* data_;
    size_t size_;
    size_t position_;
};

extern "C" {

agr_bitmap* agr_bitmap_decode(const void* encoded, size_t size) {
    if (!encoded || !size) return NULL;
    agr_bitmap* result = new agr_bitmap;
    AgrMemoryStream stream(encoded, size);
    SkImageDecoder* decoder = SkImageDecoder::Factory(&stream);
    if (!decoder || !decoder->decode(&stream, &result->bitmap,
                                     SkBitmap::kARGB_8888_Config,
                                     SkImageDecoder::kDecodePixels_Mode) ||
        !result->bitmap.getPixels() ||
        !agr_bitmap_expand_to_8888(&result->bitmap)) {
        delete decoder;
        delete result;
        return NULL;
    }
    delete decoder;
    return result;
}

void agr_bitmap_destroy(agr_bitmap* bitmap) { delete bitmap; }
uint32_t agr_bitmap_width(const agr_bitmap* bitmap) {
    return bitmap ? (uint32_t)bitmap->bitmap.width() : 0;
}
uint32_t agr_bitmap_height(const agr_bitmap* bitmap) {
    return bitmap ? (uint32_t)bitmap->bitmap.height() : 0;
}
size_t agr_bitmap_row_bytes(const agr_bitmap* bitmap) {
    return bitmap ? bitmap->bitmap.rowBytes() : 0;
}
size_t agr_bitmap_byte_count(const agr_bitmap* bitmap) {
    return bitmap ? bitmap->bitmap.getSize() : 0;
}
int agr_bitmap_config(const agr_bitmap* bitmap) {
    return bitmap ? (int)bitmap->bitmap.config() : 0;
}
int agr_bitmap_alpha_type(const agr_bitmap* bitmap) {
    return bitmap ? (int)bitmap->bitmap.alphaType() : 0;
}
int agr_bitmap_gl_internal_format(const agr_bitmap* bitmap) {
    return bitmap && bitmap->bitmap.config() == SkBitmap::kARGB_8888_Config
            ? AGR_GL_RGBA : -1;
}
int agr_bitmap_gl_type(const agr_bitmap* bitmap) {
    return bitmap && bitmap->bitmap.config() == SkBitmap::kARGB_8888_Config
            ? AGR_GL_UNSIGNED_BYTE : -1;
}
const void* agr_bitmap_pixels(const agr_bitmap* bitmap) {
    return bitmap ? bitmap->bitmap.getPixels() : NULL;
}
const char* agr_bitmap_decoder_name(void) {
    return "KitKat SkImageDecoder PNG/JPEG/GIF";
}

static int scale_clamp_index(float sample, int limit) {
    int index = (int)floorf(sample + 0.5f);
    if (index < 0) return 0;
    if (index >= limit) return limit - 1;
    return index;
}

static void scale_load(const uint8_t* base, size_t row_bytes, int x, int y, float* out) {
    const uint8_t* pixel = base + (size_t)y * row_bytes + (size_t)x * 4;
    out[0] = pixel[0];
    out[1] = pixel[1];
    out[2] = pixel[2];
    out[3] = pixel[3];
}

static void scale_store(uint8_t* pixel, const float* sample) {
    for (int channel = 0; channel < 4; ++channel) {
        float value = sample[channel];
        if (value < 0.f) value = 0.f;
        if (value > 255.f) value = 255.f;
        pixel[channel] = (uint8_t)(value + 0.5f);
    }
}

agr_bitmap* agr_bitmap_scale(const agr_bitmap* src, int dst_w, int dst_h, int filter) {
    if (!src || dst_w <= 0 || dst_h <= 0) return NULL;
    if (src->bitmap.config() != SkBitmap::kARGB_8888_Config || !src->bitmap.getPixels())
        return NULL;
    const int src_w = src->bitmap.width();
    const int src_h = src->bitmap.height();
    const size_t src_rb = src->bitmap.rowBytes();
    if (src_w <= 0 || src_h <= 0 || src_rb < (size_t)src_w * 4) return NULL;

    agr_bitmap* result = new agr_bitmap;
    result->bitmap.setConfig(SkBitmap::kARGB_8888_Config, dst_w, dst_h);
    result->bitmap.setAlphaType(src->bitmap.alphaType());
    if (!result->bitmap.allocPixels()) {
        delete result;
        return NULL;
    }

    const uint8_t* src_base = static_cast<const uint8_t*>(src->bitmap.getPixels());
    uint8_t* dst_base = static_cast<uint8_t*>(result->bitmap.getPixels());
    const size_t dst_rb = result->bitmap.rowBytes();
    for (int y = 0; y < dst_h; ++y) {
        const float src_y = ((float)y + 0.5f) * (float)src_h / (float)dst_h - 0.5f;
        uint8_t* dst_row = dst_base + (size_t)y * dst_rb;
        for (int x = 0; x < dst_w; ++x) {
            const float src_x = ((float)x + 0.5f) * (float)src_w / (float)dst_w - 0.5f;
            uint8_t* dst_pixel = dst_row + (size_t)x * 4;
            if (!filter) {
                float sample[4];
                scale_load(src_base, src_rb,
                           scale_clamp_index(src_x, src_w),
                           scale_clamp_index(src_y, src_h),
                           sample);
                scale_store(dst_pixel, sample);
                continue;
            }
            float sx = src_x;
            float sy = src_y;
            if (sx < 0.f) sx = 0.f;
            if (sy < 0.f) sy = 0.f;
            if (sx > (float)(src_w - 1)) sx = (float)(src_w - 1);
            if (sy > (float)(src_h - 1)) sy = (float)(src_h - 1);
            const int x0 = (int)floorf(sx);
            const int y0 = (int)floorf(sy);
            const int x1 = x0 + 1 < src_w ? x0 + 1 : src_w - 1;
            const int y1 = y0 + 1 < src_h ? y0 + 1 : src_h - 1;
            const float tx = sx - (float)x0;
            const float ty = sy - (float)y0;
            float c00[4], c10[4], c01[4], c11[4], mixed[4];
            scale_load(src_base, src_rb, x0, y0, c00);
            scale_load(src_base, src_rb, x1, y0, c10);
            scale_load(src_base, src_rb, x0, y1, c01);
            scale_load(src_base, src_rb, x1, y1, c11);
            for (int channel = 0; channel < 4; ++channel) {
                const float top = c00[channel] * (1.f - tx) + c10[channel] * tx;
                const float bottom = c01[channel] * (1.f - tx) + c11[channel] * tx;
                mixed[channel] = top * (1.f - ty) + bottom * ty;
            }
            scale_store(dst_pixel, mixed);
        }
    }
    return result;
}

int agr_bitmap_draw(const agr_bitmap* src,
                    void* dst_pixels,
                    int dst_w,
                    int dst_h,
                    size_t dst_row_bytes,
                    float left,
                    float top,
                    int clip_left,
                    int clip_top,
                    int clip_right,
                    int clip_bottom) {
    if (!src || !dst_pixels || dst_w <= 0 || dst_h <= 0 || dst_row_bytes < (size_t)dst_w * 4)
        return -1;
    if (src->bitmap.config() != SkBitmap::kARGB_8888_Config || !src->bitmap.getPixels())
        return -1;

    const int src_w = src->bitmap.width();
    const int src_h = src->bitmap.height();
    const size_t src_rb = src->bitmap.rowBytes();
    if (src_w <= 0 || src_h <= 0 || src_rb < (size_t)src_w * 4) return -1;

    /* API19 Canvas.drawBitmap float placement. KitKat nearest sampling uses
       the integer pixel grid; floor matches SRC_OVER without filterBitmap. */
    const int dst_x0 = (int)floorf(left);
    const int dst_y0 = (int)floorf(top);

    int clip_l = clip_left;
    int clip_t = clip_top;
    int clip_r = clip_right;
    int clip_b = clip_bottom;
    if (clip_l < 0) clip_l = 0;
    if (clip_t < 0) clip_t = 0;
    if (clip_r > dst_w) clip_r = dst_w;
    if (clip_b > dst_h) clip_b = dst_h;
    if (clip_r <= clip_l || clip_b <= clip_t) return 0;

    int src_x0 = 0;
    int src_y0 = 0;
    int draw_x = dst_x0;
    int draw_y = dst_y0;
    int draw_w = src_w;
    int draw_h = src_h;

    if (draw_x < clip_l) {
        src_x0 += clip_l - draw_x;
        draw_w -= clip_l - draw_x;
        draw_x = clip_l;
    }
    if (draw_y < clip_t) {
        src_y0 += clip_t - draw_y;
        draw_h -= clip_t - draw_y;
        draw_y = clip_t;
    }
    if (draw_x + draw_w > clip_r) draw_w = clip_r - draw_x;
    if (draw_y + draw_h > clip_b) draw_h = clip_b - draw_y;
    if (draw_w <= 0 || draw_h <= 0) return 0;

    const uint8_t* src_base = static_cast<const uint8_t*>(src->bitmap.getPixels());
    uint8_t* dst_base = static_cast<uint8_t*>(dst_pixels);
    const SkAlphaType alpha = src->bitmap.alphaType();
    int written = 0;

    for (int y = 0; y < draw_h; ++y) {
        const uint32_t* src_row = reinterpret_cast<const uint32_t*>(
            src_base + (size_t)(src_y0 + y) * src_rb) + src_x0;
        uint32_t* dst_row = reinterpret_cast<uint32_t*>(
            dst_base + (size_t)(draw_y + y) * dst_row_bytes) + draw_x;
        for (int x = 0; x < draw_w; ++x) {
            SkPMColor src_c = src_row[x];
            if (alpha == kUnpremul_SkAlphaType) {
                src_c = SkPreMultiplyARGB(SkGetPackedA32(src_c),
                                          SkGetPackedR32(src_c),
                                          SkGetPackedG32(src_c),
                                          SkGetPackedB32(src_c));
            } else if (alpha == kOpaque_SkAlphaType || alpha == kIgnore_SkAlphaType) {
                /* Treat RGB as opaque regardless of stored alpha. */
                src_c = SkPackARGB32(0xFF,
                                     SkGetPackedR32(src_c),
                                     SkGetPackedG32(src_c),
                                     SkGetPackedB32(src_c));
            }
            const U8CPU a = SkGetPackedA32(src_c);
            if (a == 0) {
                /* Fully transparent source leaves destination unchanged. */
            } else if (a == 0xFF) {
                dst_row[x] = src_c;
                written++;
            } else {
                dst_row[x] = SkPMSrcOver(src_c, dst_row[x]);
                written++;
            }
        }
    }
    return written;
}

}
