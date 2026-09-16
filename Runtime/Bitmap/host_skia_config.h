#ifndef AGR_HOST_SKIA_CONFIG_H
#define AGR_HOST_SKIA_CONFIG_H

/* Replace Android's build-wide SkUserConfig while preserving the Android
 * framework pixel layout used by BitmapFactory/GLUtils (RGBA in memory on
 * little-endian hosts).  This is a host-port boundary, not a Skia fork. */
#define SkUserConfig_DEFINED
#define SK_BUILD_FOR_IOS
#define SK_RELEASE
#define SK_SUPPORT_GPU 0
#define SK_SCALAR_IS_FLOAT
#define SK_API
#define SK_R32_SHIFT 0
#define SK_G32_SHIFT 8
#define SK_B32_SHIFT 16
#define SK_A32_SHIFT 24

#endif
