#include "agr_bitmap.h"

#include "SkBitmap.h"
#include "SkImageDecoder.h"
#include "SkStream.h"

#include <string.h>

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
        !result->bitmap.getPixels()) {
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
const char* agr_bitmap_decoder_name(void) { return "KitKat SkImageDecoder_libpng"; }

}
