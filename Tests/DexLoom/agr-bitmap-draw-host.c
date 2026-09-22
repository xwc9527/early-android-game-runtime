/* Synthetic agr_bitmap decode + blit contract.
   Verifies channel layout, SRC_OVER, clipping, and off-screen safety. */
#include "agr_bitmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int g_failures = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static uint8_t *read_file(const char *path, size_t *size) {
    FILE *file = fopen(path, "rb");
    if (!file) return NULL;
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);
    uint8_t *bytes = malloc((size_t)length);
    if (!bytes || fread(bytes, 1, (size_t)length, file) != (size_t)length) {
        free(bytes);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *size = (size_t)length;
    return bytes;
}

static uint32_t pixel_at(const uint8_t *base, size_t rb, int x, int y) {
    const uint8_t *p = base + (size_t)y * rb + (size_t)x * 4;
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

int main(int argc, char **argv) {
    const char *png_path = argc > 1 ? argv[1] : "/tmp/fixture-2x2.png";
    const char *jpg_path = argc > 2 ? argv[2] : "/tmp/fb-background.jpg";
    const char *gif_path = argc > 3 ? argv[3] : "/tmp/fb-bubble.gif";
    size_t size = 0;
    uint8_t *bytes = read_file(png_path, &size);
    expect(bytes != NULL, "read fixture png");
    if (!bytes) return 1;

    agr_bitmap *src = agr_bitmap_decode(bytes, size);
    free(bytes);
    expect(src != NULL, "decode 2x2 png");
    if (!src) return 1;
    expect(agr_bitmap_width(src) == 2 && agr_bitmap_height(src) == 2, "fixture size");
    expect(agr_bitmap_config(src) == AGR_BITMAP_CONFIG_ARGB_8888, "ARGB_8888 config");
    expect(agr_bitmap_row_bytes(src) == 8, "fixture row bytes");
    const uint8_t *sp = (const uint8_t *)agr_bitmap_pixels(src);
    /* Host layout from host_skia_config.h: R G B A */
    expect(sp[0] == 0xff && sp[1] == 0x00 && sp[2] == 0x00 && sp[3] == 0xff, "opaque red RGBA");
    expect(sp[4] == 0x00 && sp[5] == 0xff && sp[6] == 0x00 && sp[7] == 0xff, "opaque green RGBA");

    const int dst_w = 4, dst_h = 4;
    const size_t dst_rb = (size_t)dst_w * 4;
    uint8_t *dst = calloc((size_t)dst_h, dst_rb);
    expect(dst != NULL, "alloc destination");
    int wrote = agr_bitmap_draw(src, dst, dst_w, dst_h, dst_rb, 1.0f, 1.0f, 0, 0, dst_w, dst_h);
    expect(wrote > 0, "draw wrote pixels");
    expect(pixel_at(dst, dst_rb, 1, 1) == 0xff0000ff, "red at (1,1)");
    expect(pixel_at(dst, dst_rb, 2, 1) == 0xff00ff00, "green at (2,1)");
    expect(pixel_at(dst, dst_rb, 0, 0) == 0, "untouched origin stays zero");

    memset(dst, 0, dst_h * dst_rb);
    wrote = agr_bitmap_draw(src, dst, dst_w, dst_h, dst_rb, 100.0f, 100.0f, 0, 0, dst_w, dst_h);
    expect(wrote == 0, "fully off-screen writes nothing");
    expect(pixel_at(dst, dst_rb, 0, 0) == 0 && pixel_at(dst, dst_rb, 3, 3) == 0,
           "off-screen did not corrupt");

    memset(dst, 0, dst_h * dst_rb);
    wrote = agr_bitmap_draw(src, dst, dst_w, dst_h, dst_rb, -1.0f, 0.0f, 0, 0, dst_w, dst_h);
    expect(wrote > 0, "partial left clip still writes");
    expect(pixel_at(dst, dst_rb, 0, 0) == 0xff00ff00, "clipped green at (0,0)");

    expect(agr_bitmap_scale(NULL, 4, 2, 0) == NULL, "scale rejects a null source");
    expect(agr_bitmap_scale(src, 0, 2, 1) == NULL, "scale rejects a non-positive width");
    agr_bitmap *nearest = agr_bitmap_scale(src, 4, 2, 0);
    expect(nearest != NULL, "nearest scale allocates");
    expect(nearest && agr_bitmap_width(nearest) == 4 && agr_bitmap_height(nearest) == 2,
           "nearest scale uses the requested size");
    expect(agr_bitmap_width(src) == 2 && agr_bitmap_height(src) == 2, "scale leaves the source size");
    if (nearest) {
        const uint8_t *np = (const uint8_t *)agr_bitmap_pixels(nearest);
        size_t nrb = agr_bitmap_row_bytes(nearest);
        expect(pixel_at(np, nrb, 0, 0) == 0xff0000ff, "nearest left pixel stays red");
        expect(pixel_at(np, nrb, 1, 0) == 0xff0000ff, "nearest second pixel stays red");
        expect(pixel_at(np, nrb, 2, 0) == 0xff00ff00, "nearest third pixel stays green");
        expect(pixel_at(np, nrb, 3, 0) == 0xff00ff00, "nearest fourth pixel stays green");
    }
    agr_bitmap *filtered = agr_bitmap_scale(src, 4, 2, 1);
    expect(filtered != NULL && agr_bitmap_width(filtered) == 4, "bilinear scale allocates");
    if (filtered) {
        const uint8_t *fp = (const uint8_t *)agr_bitmap_pixels(filtered);
        size_t frb = agr_bitmap_row_bytes(filtered);
        expect(pixel_at(fp, frb, 0, 0) == 0xff0000ff, "bilinear edge stays source red");
        expect(fp[3] == 0xff, "bilinear keeps opaque alpha");
    }
    agr_bitmap_destroy(nearest);
    agr_bitmap_destroy(filtered);
    agr_bitmap_destroy(src);

    bytes = read_file(jpg_path, &size);
    if (bytes) {
        agr_bitmap *jpg = agr_bitmap_decode(bytes, size);
        free(bytes);
        expect(jpg != NULL && agr_bitmap_width(jpg) == 640 && agr_bitmap_height(jpg) == 480,
               "decode Frozen Bubble background.jpg");
        expect(agr_bitmap_config(jpg) == AGR_BITMAP_CONFIG_ARGB_8888, "jpeg expands to 8888");
        expect(agr_bitmap_alpha_type(jpg) == AGR_BITMAP_ALPHA_OPAQUE, "jpeg opaque alpha");
        agr_bitmap_destroy(jpg);
    } else {
        printf("SKIP jpeg sample missing\n");
    }

    bytes = read_file(gif_path, &size);
    if (bytes) {
        agr_bitmap *gif = agr_bitmap_decode(bytes, size);
        free(bytes);
        expect(gif != NULL && agr_bitmap_width(gif) == 32 && agr_bitmap_height(gif) == 32,
               "decode Frozen Bubble bubble_1.gif");
        expect(agr_bitmap_config(gif) == AGR_BITMAP_CONFIG_ARGB_8888, "gif expands Index8 to 8888");
        agr_bitmap_destroy(gif);
    } else {
        printf("SKIP gif sample missing\n");
    }

    free(dst);
    printf("agr bitmap draw contract: %s\n", g_failures ? "FAIL" : "PASS");
    printf("decoder=%s\n", agr_bitmap_decoder_name());
    return g_failures ? 1 : 0;
}
