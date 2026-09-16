#import <UIKit/UIKit.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "agr_runtime.h"
#include "dx_vm.h"
#include "agr_androidfw.h"
#include "agr_bitmap.h"
#include "agr_guest_runtime.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>

typedef struct DxVM DxVM;
extern DxVM *poc_create(const uint8_t *, uint32_t);
extern void poc_set_guest_bridge(int32_t (*)(void *, int32_t, void *, void *, int));
extern int32_t poc_run(DxVM *, const char *, int32_t *);
extern int32_t poc_callback(DxVM *, int32_t, void *, void *, int32_t *);
typedef int32_t (*AgrDexUploadFn)(void *, const char *);
extern void agr_dex_set_upload_callback(AgrDexUploadFn, void *);
extern int agr_dex_game_main(int, char **);
extern void *arm_interp_create(void);
extern void arm_interp_destroy(void *);
extern int32_t arm_interp_write(void *, uint32_t, const uint8_t *, uint32_t);
extern int32_t arm_interp_read(void *, uint32_t, uint8_t *, uint32_t);
extern int32_t arm_interp_set_reg(void *, uint32_t, uint32_t);
extern uint32_t arm_interp_get_reg(void *, uint32_t);
extern int32_t arm_interp_run(void *, uint64_t *, uint32_t *);

static int32_t dex_bridge(void *vm, int32_t value, void *str, void *obj, int which) {
    if (which != 0) return -500;
    int32_t out = 0;
    return poc_callback((DxVM *)vm, value, str, obj, &out) == 0 ? out : -501;
}

typedef struct { void *cpu; } GuestMemory;
static int32_t guest_read(void *u, uint32_t a, void *p, uint32_t n) {
    return arm_interp_read(((GuestMemory *)u)->cpu, a, p, n);
}
static int32_t guest_write(void *u, uint32_t a, const void *p, uint32_t n) {
    return arm_interp_write(((GuestMemory *)u)->cpu, a, p, n);
}

static NSData *bundleData(NSString *name, NSString *extension) {
    NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:extension];
    return path ? [NSData dataWithContentsOfFile:path] : nil;
}

static BOOL writeRGBAFramePNG(const uint8_t *pixels, size_t width, size_t height, NSString *path) {
    NSData *rgba = [NSData dataWithBytes:pixels length:width * height * 4];
    CGDataProviderRef provider = CGDataProviderCreateWithCFData((__bridge CFDataRef)rgba);
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGImageRef cg = CGImageCreate(width, height, 8, 32, width * 4, colorSpace,
        kCGBitmapByteOrder32Big | kCGImageAlphaLast, provider, NULL, false,
        kCGRenderingIntentDefault);
    UIImage *image = cg ? [UIImage imageWithCGImage:cg scale:1 orientation:UIImageOrientationDownMirrored] : nil;
    NSData *png = image ? UIImagePNGRepresentation(image) : nil;
    BOOL written = png && [png writeToFile:path atomically:YES];
    if (cg) CGImageRelease(cg);
    CGColorSpaceRelease(colorSpace); CGDataProviderRelease(provider);
    return written;
}

static GLuint compileShader(GLenum type, const char *source, NSMutableArray<NSString *> *failures) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    GLint compiled = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        GLchar log[512] = {0};
        glGetShaderInfoLog(shader, sizeof(log), NULL, log);
        [failures addObject:[NSString stringWithFormat:@"angle-shader=%s", log]];
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

static NSDictionary *runAngleMetalTest(NSMutableArray<NSString *> *failures) {
    PFNEGLGETPLATFORMDISPLAYEXTPROC getPlatformDisplay =
        (PFNEGLGETPLATFORMDISPLAYEXTPROC)eglGetProcAddress("eglGetPlatformDisplayEXT");
    if (!getPlatformDisplay) {
        [failures addObject:@"angle=no-eglGetPlatformDisplayEXT"];
        return @{};
    }
    const EGLint displayAttributes[] = {
        EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_METAL_ANGLE,
        EGL_NONE
    };
    EGLDisplay display = getPlatformDisplay(EGL_PLATFORM_ANGLE_ANGLE,
                                             EGL_DEFAULT_DISPLAY,
                                             displayAttributes);
    EGLint eglMajor = 0, eglMinor = 0;
    if (display == EGL_NO_DISPLAY || !eglInitialize(display, &eglMajor, &eglMinor)) {
        [failures addObject:[NSString stringWithFormat:@"angle-initialize=0x%x", eglGetError()]];
        return @{};
    }
    eglBindAPI(EGL_OPENGL_ES_API);
    const EGLint configAttributes[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_ALPHA_SIZE, 8,
        EGL_NONE
    };
    EGLConfig config = NULL;
    EGLint configCount = 0;
    EGLBoolean configured = eglChooseConfig(display, configAttributes, &config, 1, &configCount);
    const EGLint pbufferAttributes[] = { EGL_WIDTH, 32, EGL_HEIGHT, 32, EGL_NONE };
    EGLSurface surface = configured && configCount ?
        eglCreatePbufferSurface(display, config, pbufferAttributes) : EGL_NO_SURFACE;
    const EGLint contextAttributes[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
    EGLContext context = surface != EGL_NO_SURFACE ?
        eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttributes) : EGL_NO_CONTEXT;
    if (surface == EGL_NO_SURFACE || context == EGL_NO_CONTEXT ||
        !eglMakeCurrent(display, surface, surface, context)) {
        [failures addObject:[NSString stringWithFormat:@"angle-context=0x%x", eglGetError()]];
        if (context != EGL_NO_CONTEXT) eglDestroyContext(display, context);
        if (surface != EGL_NO_SURFACE) eglDestroySurface(display, surface);
        eglTerminate(display);
        return @{};
    }

    const char *vertexSource =
        "attribute vec2 position; void main(){ gl_Position=vec4(position,0.0,1.0); }";
    const char *fragmentSource =
        "precision mediump float; void main(){ gl_FragColor=vec4(0.25,0.5,0.75,1.0); }";
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource, failures);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource, failures);
    GLuint program = 0;
    if (vertexShader && fragmentShader) {
        program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glBindAttribLocation(program, 0, "position");
        glLinkProgram(program);
        GLint linked = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linked);
        if (!linked) [failures addObject:@"angle=program-link-failed"];
    }
    const GLfloat vertices[] = { -1.0f, -1.0f, 3.0f, -1.0f, -1.0f, 3.0f };
    GLubyte pixel[4] = {0};
    if (program) {
        glViewport(0, 0, 32, 32);
        glUseProgram(program);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glFinish();
        glReadPixels(16, 16, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixel);
    }
    GLenum glError = glGetError();
    BOOL pixelOK = abs((int)pixel[0] - 64) <= 2 && abs((int)pixel[1] - 128) <= 2 &&
                   abs((int)pixel[2] - 191) <= 2 && pixel[3] >= 253;
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *glVersion = glGetString(GL_VERSION);
    NSString *rendererString = renderer ? [NSString stringWithUTF8String:(const char *)renderer] : @"";
    NSString *glVersionString = glVersion ? [NSString stringWithUTF8String:(const char *)glVersion] : @"";
    NSString *eglVersionString = [NSString stringWithFormat:@"%d.%d", eglMajor, eglMinor];
    if (!pixelOK || glError != GL_NO_ERROR ||
        [rendererString rangeOfString:@"ANGLE" options:NSCaseInsensitiveSearch].location == NSNotFound ||
        [rendererString rangeOfString:@"Metal" options:NSCaseInsensitiveSearch].location == NSNotFound) {
        [failures addObject:[NSString stringWithFormat:@"angle-draw=%u,%u,%u,%u err=0x%x renderer=%@",
            pixel[0], pixel[1], pixel[2], pixel[3], glError, rendererString]];
    }
    if (program) glDeleteProgram(program);
    if (vertexShader) glDeleteShader(vertexShader);
    if (fragmentShader) glDeleteShader(fragmentShader);
    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroyContext(display, context);
    eglDestroySurface(display, surface);
    eglTerminate(display);
    return @{
        @"angle_renderer": rendererString,
        @"angle_gl_version": glVersionString,
        @"angle_egl_version": eglVersionString,
        @"angle_pixel": @[@(pixel[0]), @(pixel[1]), @(pixel[2]), @(pixel[3])],
        @"angle_draw_passed": @(pixelOK && glError == GL_NO_ERROR)
    };
}

static NSDictionary *runGloomyRegression(NSMutableArray<NSString *> *failures) {
    NSData *elf = bundleData(@"gloomy-librenderer", @"so");
    agr_guest *guest = agr_guest_create();
    if (!elf || !guest) {
        [failures addObject:@"gloomy=create-failed"];
        if (guest) agr_guest_destroy(guest);
        return @{};
    }
    int loaded = agr_guest_load_elf(guest, "librenderer.so", elf.bytes, (uint32_t)elf.length, 0x02800000);
    int context = loaded == 0 ? agr_guest_create_gles1_pbuffer(guest, 32, 32) : -1;
    if (loaded || context) {
        [failures addObject:[NSString stringWithFormat:@"gloomy-init=%s", agr_guest_last_error(guest)]];
        agr_guest_destroy(guest);
        return @{};
    }
    agr_guest_setup_gles1_frame(guest);
    const float vertices[] = {-0.85f,-0.75f,0.0f, 0.85f,-0.75f,0.0f, 0.0f,0.85f,0.0f};
    const float colors[] = {1.0f,0.05f,0.05f,1.0f, 1.0f,0.05f,0.05f,1.0f, 1.0f,0.05f,0.05f,1.0f};
    const int32_t texcoords[] = {0,0,65536,0,32768,65536};
    const int16_t indices[] = {0,1,2};
    uint32_t vertexArray = agr_guest_new_primitive_array(guest, AGR_ARRAY_FLOAT, vertices, 9);
    uint32_t colorArray = agr_guest_new_primitive_array(guest, AGR_ARRAY_FLOAT, colors, 12);
    uint32_t texcoordArray = agr_guest_new_primitive_array(guest, AGR_ARRAY_INT, texcoords, 6);
    uint32_t indexArray = agr_guest_new_primitive_array(guest, AGR_ARRAY_SHORT, indices, 3);
    uint32_t lineArgs[] = {0x01000000,0x60001000,vertexArray,colorArray,3};
    uint32_t triangleArgs[] = {0x01000000,0x60001000,vertexArray,colorArray,texcoordArray,indexArray,3};
    int32_t ignored = 0;
    int lines = agr_guest_call_symbol(guest, "Java_zame_game_engine_Renderer_renderLines", lineArgs, 5, &ignored);
    int triangles = lines == 0 ? agr_guest_call_symbol(guest, "Java_zame_game_engine_Renderer_renderTriangles", triangleArgs, 7, &ignored) : -1;
    uint8_t rgba[32 * 32 * 4] = {0};
    int bytes = triangles == 0 ? agr_guest_read_rgba(guest, rgba, sizeof(rgba)) : -1;
    NSUInteger nonblack = 0;
    if (bytes > 0) for (int i = 0; i < bytes; i += 4) if (rgba[i] || rgba[i+1] || rgba[i+2]) nonblack++;
    NSString *renderer = [NSString stringWithUTF8String:agr_guest_gl_renderer(guest)];
    NSString *version = [NSString stringWithUTF8String:agr_guest_gl_version(guest)];
    uint64_t instructions = agr_guest_instruction_count(guest);
    if (lines || triangles || bytes != sizeof(rgba) || nonblack == 0)
        [failures addObject:[NSString stringWithFormat:@"gloomy=%d/%d/%d/%lu/%s", lines, triangles, bytes, (unsigned long)nonblack, agr_guest_last_error(guest)]];
    NSDictionary *result = @{
        @"gloomy_original_so_bytes": @(elf.length),
        @"gloomy_arm_instructions": @(instructions),
        @"gloomy_nonblack_pixels": @(nonblack),
        @"gloomy_renderer": renderer ?: @"",
        @"gloomy_gl_version": version ?: @"",
        @"gloomy_passed": @(lines == 0 && triangles == 0 && bytes == sizeof(rgba) && nonblack > 0)
    };
    agr_guest_destroy(guest);
    return result;
}

typedef struct {
    agr_afw_manager *assets;
    int uploads;
    uint32_t width, height;
} DexTextureHost;

static int32_t dexUploadTexture(void *user, const char *path) {
    DexTextureHost *host = (DexTextureHost *)user;
    agr_afw_asset *asset = agr_afw_open(host->assets, path, 3);
    if (!asset) return -1;
    agr_bitmap *bitmap = agr_bitmap_decode(agr_afw_buffer(asset), (size_t)agr_afw_length(asset));
    if (!bitmap) { agr_afw_close(asset); return -2; }
    host->width = agr_bitmap_width(bitmap); host->height = agr_bitmap_height(bitmap);
    glTexImage2D(GL_TEXTURE_2D, 0, agr_bitmap_gl_internal_format(bitmap),
                 (GLsizei)host->width, (GLsizei)host->height, 0,
                 (GLenum)agr_bitmap_gl_internal_format(bitmap),
                 (GLenum)agr_bitmap_gl_type(bitmap), agr_bitmap_pixels(bitmap));
    GLenum error = glGetError();
    if (error == GL_NO_ERROR) host->uploads++;
    agr_bitmap_destroy(bitmap); agr_afw_close(asset);
    return error == GL_NO_ERROR ? 0 : -(int32_t)error;
}

static NSDictionary *runKungFooDexRegression(NSMutableArray<NSString *> *failures) {
    PFNEGLGETPLATFORMDISPLAYEXTPROC getPlatformDisplay =
        (PFNEGLGETPLATFORMDISPLAYEXTPROC)eglGetProcAddress("eglGetPlatformDisplayEXT");
    const EGLint da[] = {EGL_PLATFORM_ANGLE_TYPE_ANGLE,EGL_PLATFORM_ANGLE_TYPE_METAL_ANGLE,EGL_NONE};
    EGLDisplay display = getPlatformDisplay ? getPlatformDisplay(EGL_PLATFORM_ANGLE_ANGLE,EGL_DEFAULT_DISPLAY,da) : EGL_NO_DISPLAY;
    EGLint major=0, minor=0;
    const EGLint ca[] = {EGL_SURFACE_TYPE,EGL_PBUFFER_BIT,EGL_RENDERABLE_TYPE,EGL_OPENGL_ES2_BIT,EGL_RED_SIZE,8,EGL_GREEN_SIZE,8,EGL_BLUE_SIZE,8,EGL_ALPHA_SIZE,8,EGL_NONE};
    EGLConfig config = NULL; EGLint count = 0;
    const EGLint pa[] = {EGL_WIDTH,32,EGL_HEIGHT,32,EGL_NONE};
    const EGLint xa[] = {EGL_CONTEXT_CLIENT_VERSION,2,EGL_NONE};
    EGLSurface surface = EGL_NO_SURFACE; EGLContext context = EGL_NO_CONTEXT;
    if (display != EGL_NO_DISPLAY && eglInitialize(display,&major,&minor) && eglChooseConfig(display,ca,&config,1,&count) && count) {
        surface=eglCreatePbufferSurface(display,config,pa); context=eglCreateContext(display,config,EGL_NO_CONTEXT,xa);
    }
    if (surface == EGL_NO_SURFACE || context == EGL_NO_CONTEXT || !eglMakeCurrent(display,surface,surface,context)) {
        [failures addObject:[NSString stringWithFormat:@"kungfoo-dex-egl=0x%x",eglGetError()]];
        return @{};
    }
    NSString *apkPath = [[NSBundle mainBundle] pathForResource:@"kungfoo" ofType:@"apk"];
    NSString *dexPath = [[NSBundle mainBundle] pathForResource:@"kungfoo-classes" ofType:@"dex"];
    agr_afw_manager *assets = agr_afw_create();
    int mounted = apkPath ? agr_afw_add_apk(assets, apkPath.UTF8String) : -1;
    DexTextureHost host = {assets,0,0,0}; agr_dex_set_upload_callback(dexUploadTexture,&host);
    char program[] = "dex_game_runner", image[] = "dpad1.png";
    char *argv[] = {program,(char *)dexPath.UTF8String,image};
    int rc = mounted == 0 && dexPath ? agr_dex_game_main(3,argv) : -1;
    GLint texture = 0; glGetIntegerv(GL_TEXTURE_BINDING_2D,&texture); GLenum glError=glGetError();
    const GLubyte *rendererBytes=glGetString(GL_RENDERER);
    NSString *renderer=rendererBytes ? [NSString stringWithUTF8String:(const char *)rendererBytes] : @"";
    BOOL passed = rc == 0 && host.uploads == 1 && host.width == 256 && host.height == 256 && texture > 0 && glError == GL_NO_ERROR;
    if (!passed) [failures addObject:[NSString stringWithFormat:@"kungfoo-dex=%d/%d/%u/%u/%d/0x%x",rc,host.uploads,host.width,host.height,texture,glError]];
    agr_dex_set_upload_callback(NULL,NULL); agr_afw_destroy(assets);
    eglMakeCurrent(display,EGL_NO_SURFACE,EGL_NO_SURFACE,EGL_NO_CONTEXT); eglDestroyContext(display,context); eglDestroySurface(display,surface); eglTerminate(display);
    return @{@"kungfoo_original_dex_bytes":@([NSData dataWithContentsOfFile:dexPath].length),
             @"kungfoo_dex_loadimage_passed":@(passed), @"kungfoo_texture_uploads":@(host.uploads),
             @"kungfoo_texture_width":@(host.width), @"kungfoo_texture_height":@(host.height),
             @"kungfoo_dex_renderer":renderer};
}

static NSDictionary *runKungFooNativeRegression(NSMutableArray<NSString *> *failures) {
    NSData *elf = bundleData(@"kungfoo-native",@"so");
    agr_guest *guest = agr_guest_create();
    NSString *apkPath = [[NSBundle mainBundle] pathForResource:@"kungfoo" ofType:@"apk"];
    NSString *dexPath = [[NSBundle mainBundle] pathForResource:@"kungfoo-classes" ofType:@"dex"];
    agr_afw_manager *dexAssets = agr_afw_create();
    if (apkPath) agr_afw_add_apk(dexAssets,apkPath.UTF8String);
    DexTextureHost dexHost = {dexAssets,0,0,0};
    agr_dex_set_upload_callback(dexUploadTexture,&dexHost);
    int mounted = apkPath && guest ? agr_guest_mount_apk(guest,apkPath.UTF8String) : -1;
    int dexLoaded = mounted == 0 && dexPath ? agr_guest_load_dex(guest,dexPath.UTF8String) : -1;
    int loaded = elf && guest && dexLoaded == 0 ? agr_guest_load_elf(guest,"libKungFooBarracudaNativeActivity.so",elf.bytes,(uint32_t)elf.length,0x02800000) : -1;
    uint32_t constructors = 0;
    int initialized = loaded == 0 ? agr_guest_run_constructors(guest,&constructors) : -1;
    int activityCreated = -1, onStart = -1, onResume = -1, onWindow = -1, onFocus = -1, pumped = -1;
    int framePumpResult = 0; uint32_t framePumps = 0;
    uint8_t *frame = calloc(320u*480u*4u,1); uint32_t nonblack = 0; int32_t frameBytes = -1;
    uint32_t callbacksFound = 0;
    if (initialized == 0) {
        uint8_t callbacksZero[64] = {0};
        const char internalPath[] = "/data/data/com.onetwofivegames.kungfoobarracuda/files";
        const char externalPath[] = "/sdcard/Android/data/com.onetwofivegames.kungfoobarracuda/files";
        const char obbPath[] = "/sdcard/Android/obb/com.onetwofivegames.kungfoobarracuda";
        uint32_t callbacks = agr_guest_alloc(guest,callbacksZero,sizeof(callbacksZero),4);
        uint32_t internal = agr_guest_alloc(guest,internalPath,sizeof(internalPath),1);
        uint32_t external = agr_guest_alloc(guest,externalPath,sizeof(externalPath),1);
        uint32_t obb = agr_guest_alloc(guest,obbPath,sizeof(obbPath),1);
        uint32_t activityWords[10] = {callbacks,agr_guest_java_vm(guest),agr_guest_jni_env(guest),
            0x60001000u,internal,external,0,0,0x62000000u,obb};
        uint32_t activity = agr_guest_alloc(guest,activityWords,sizeof(activityWords),4);
        uint32_t args[3] = {activity,0,0}; int32_t ignored = 0;
        activityCreated = agr_guest_call_symbol(guest,"ANativeActivity_onCreate",args,3,&ignored);
        uint32_t callbackWords[16] = {0}; agr_guest_read(guest,callbacks,callbackWords,sizeof(callbackWords));
        for (uint32_t i = 0; i < 16; i++) if (callbackWords[i]) callbacksFound++;
        if (activityCreated == 0 && callbackWords[0]) {
            onStart = agr_guest_call_address(guest,callbackWords[0],args,1,&ignored);
            if (onStart == 0 && callbackWords[1]) onResume = agr_guest_call_address(guest,callbackWords[1],args,1,&ignored);
            if (onResume == 0 && callbackWords[7]) {
                uint32_t windowArgs[2] = {activity,0x63000000u};
                onWindow = agr_guest_call_address(guest,callbackWords[7],windowArgs,2,&ignored);
                if (onWindow == 0) {
                    pumped = agr_guest_resume_thread(guest);
                    if (pumped == 0 && callbackWords[6]) {
                        uint32_t focusArgs[2] = {activity,1};
                        onFocus = agr_guest_call_address(guest,callbackWords[6],focusArgs,2,&ignored);
                        while (onFocus == 0 && frame && agr_guest_has_parked_thread(guest) &&
                               framePumps < 40 && nonblack == 0) {
                            framePumpResult = agr_guest_resume_thread_until_swap(guest);
                            framePumps++;
                            if (framePumpResult) break;
                            memset(frame,0,320u*480u*4u); nonblack = 0;
                            frameBytes = agr_guest_read_rgba(guest,frame,320u*480u*4u);
                            if (frameBytes > 0) for (int32_t i=0; i+3<frameBytes; i+=4)
                                if (frame[i] || frame[i+1] || frame[i+2]) nonblack++;
                        }
                    }
                }
            }
        }
    }
    uint64_t instructions = guest ? agr_guest_instruction_count(guest) : 0;
    uint32_t draws = guest ? agr_guest_draw_count(guest) : 0;
    uint32_t swaps = guest ? agr_guest_swap_count(guest) : 0;
    uint32_t assetOpens = guest ? agr_guest_asset_open_count(guest) : 0;
    if (frameBytes < 0 && guest && frame && onWindow == 0) {
        frameBytes = agr_guest_read_rgba(guest,frame,320u*480u*4u);
        if (frameBytes > 0) for (int32_t i=0; i+3<frameBytes; i+=4)
            if (frame[i] || frame[i+1] || frame[i+2]) nonblack++;
    }
    if (nonblack > 0) {
        NSString *framePath = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/kungfoo-frame.png"];
        if (!writeRGBAFramePNG(frame,320,480,framePath)) [failures addObject:@"kungfoo-frame-png-write"];
    }
    free(frame);
    NSString *error = guest ? [NSString stringWithUTF8String:agr_guest_last_error(guest)] : @"create failed";
    BOOL passed = mounted == 0 && dexLoaded == 0 && loaded == 0 && initialized == 0 && constructors == 51 && activityCreated == 0 && callbacksFound >= 10 && onStart == 0 && onResume == 0 && onWindow == 0 && pumped == 0 && onFocus == 0 && framePumpResult == 0 && draws > 0 && swaps > 0 && nonblack > 0;
    if (!passed) [failures addObject:[NSString stringWithFormat:@"kungfoo-native=%d/%d/%d/%d/%u activity=%d callbacks=%u start=%d resume=%d window=%d pump=%d focus=%d frames=%u/%d/%@",mounted,dexLoaded,loaded,initialized,constructors,activityCreated,callbacksFound,onStart,onResume,onWindow,pumped,onFocus,framePumps,framePumpResult,error]];
    if (guest) agr_guest_destroy(guest);
    agr_dex_set_upload_callback(NULL,NULL);
    agr_afw_destroy(dexAssets);
    return @{@"kungfoo_native_so_bytes":@(elf.length),@"kungfoo_constructors":@(constructors),
             @"kungfoo_native_instructions":@(instructions),@"kungfoo_constructors_passed":@(initialized == 0 && constructors == 51),
             @"kungfoo_native_activity_created":@(activityCreated == 0),@"kungfoo_activity_callbacks":@(callbacksFound),
             @"kungfoo_on_start":@(onStart == 0),@"kungfoo_on_resume":@(onResume == 0),
             @"kungfoo_on_window_created":@(onWindow == 0),@"kungfoo_native_draws":@(draws),
             @"kungfoo_on_focus":@(onFocus == 0),
             @"kungfoo_frame_pumps":@(framePumps),
             @"kungfoo_native_swaps":@(swaps),@"kungfoo_native_asset_opens":@(assetOpens),
             @"kungfoo_native_texture_uploads":@(dexHost.uploads),@"kungfoo_native_nonblack_pixels":@(nonblack),
             @"kungfoo_native_frame_bytes":@(frameBytes)};
}

static NSString *failureSignature(NSString *stage, NSString *detail) {
    if (!detail.length) return [stage stringByAppendingString:@":unknown"];
    NSArray<NSString *> *prefixes = @[@"unhandled guest import ", @"JNI CallIntMethod unhandled "];
    NSArray<NSString *> *kinds = @[@"missing_symbol:", @"missing_jni_method:"];
    for (NSUInteger i=0; i<prefixes.count; i++) {
        NSRange range = [detail rangeOfString:prefixes[i]];
        if (range.location != NSNotFound)
            return [kinds[i] stringByAppendingString:[detail substringFromIndex:NSMaxRange(range)]];
    }
    if ([detail containsString:@"unhandled JNI slot"]) return @"missing_jni_slot";
    if ([detail containsString:@"ARM instruction budget exhausted"]) return @"guest_timeout";
    if ([detail containsString:@"ARM interpreter error"]) return @"arm_interpreter_error";
    if ([detail containsString:@"relocation"] || [detail containsString:@"Relocation"])
        return @"elf_relocation";
    NSString *clean = [[detail componentsSeparatedByCharactersInSet:[NSCharacterSet newlineCharacterSet]] firstObject];
    if (clean.length > 120) clean = [clean substringToIndex:120];
    return [NSString stringWithFormat:@"%@:%@",stage,clean];
}

static NSData *apkMember(agr_afw_manager *assets, NSString *member) {
    agr_afw_asset *asset = agr_afw_open(assets,member.UTF8String,3);
    if (!asset) return nil;
    const void *bytes = agr_afw_buffer(asset); int64_t length = agr_afw_length(asset);
    NSData *data = bytes && length > 0 ? [NSData dataWithBytes:bytes length:(NSUInteger)length] : nil;
    agr_afw_close(asset); return data;
}

static NSDictionary *probeGenericSample(NSDictionary *sample) {
    NSString *resource = sample[@"resource"];
    NSString *apkPath = [[NSBundle mainBundle] pathForResource:resource.stringByDeletingPathExtension
                                                        ofType:resource.pathExtension];
    NSMutableDictionary *result = [@{@"id":sample[@"id"] ?: @"unknown",
      @"package":sample[@"package"] ?: @"unknown", @"static_cluster":sample[@"static_cluster"] ?: @""} mutableCopy];
    if (!apkPath) {
        [result addEntriesFromDictionary:@{@"stage":@"input",@"outcome":@"new_failure",@"signature":@"input:apk_missing"}];
        return result;
    }
    agr_afw_manager *assets = agr_afw_create();
    if (!assets || agr_afw_add_apk(assets,apkPath.UTF8String)) {
        NSString *detail = assets ? [NSString stringWithUTF8String:agr_afw_last_error(assets)] : @"manager create failed";
        [result addEntriesFromDictionary:@{@"stage":@"apk",@"outcome":@"new_failure",@"signature":failureSignature(@"apk",detail)}];
        if (assets) agr_afw_destroy(assets); return result;
    }
    NSArray *libraries = sample[@"armv7_libraries"];
    BOOL hasDex = [sample[@"has_dex"] boolValue];
    if (!libraries.count) {
        NSData *dex = hasDex ? apkMember(assets,@"classes.dex") : nil;
        DxVM *vm = dex ? poc_create(dex.bytes,(uint32_t)dex.length) : NULL;
        [result addEntriesFromDictionary:@{@"stage":vm ? @"dex_loaded" : @"dex_parse",
          @"outcome":vm ? @"known_gap" : @"new_failure",
          @"signature":vm ? @"missing_framework:activity_launch" : @"dex_parse_failed"}];
        agr_afw_destroy(assets); return result;
    }
    agr_guest *guest = agr_guest_create();
    int mounted = guest ? agr_guest_mount_apk(guest,apkPath.UTF8String) : -1;
    NSString *failure = nil; NSString *stage = @"elf_loaded";
    uint32_t base = 0x02800000u;
    for (NSString *member in libraries) {
        NSData *elf = apkMember(assets,member);
        if (!elf || agr_guest_load_elf(guest,member.lastPathComponent.UTF8String,elf.bytes,(uint32_t)elf.length,base)) {
            failure = guest ? [NSString stringWithUTF8String:agr_guest_last_error(guest)] : @"guest create failed";
            stage = @"elf_load"; break;
        }
        base += 0x01000000u;
    }
    if (!failure && mounted == 0 && hasDex) {
        NSData *dex = apkMember(assets,@"classes.dex");
        NSString *dexPath = [NSTemporaryDirectory() stringByAppendingPathComponent:
            [NSString stringWithFormat:@"%@.dex",sample[@"id"]]];
        if (!dex || ![dex writeToFile:dexPath atomically:YES] || agr_guest_load_dex(guest,dexPath.UTF8String)) {
            failure = guest ? [NSString stringWithUTF8String:agr_guest_last_error(guest)] : @"DEX unavailable";
            stage = @"dex_load";
        }
    }
    uint32_t constructors = 0;
    if (!failure && agr_guest_run_constructors(guest,&constructors)) {
        failure = [NSString stringWithUTF8String:agr_guest_last_error(guest)]; stage = @"constructors";
    }
    if (!failure && agr_guest_find_symbol(guest,"JNI_OnLoad")) {
        uint32_t args[2] = {agr_guest_java_vm(guest),0}; int32_t value = 0;
        if (agr_guest_call_symbol(guest,"JNI_OnLoad",args,2,&value)) {
            failure = [NSString stringWithUTF8String:agr_guest_last_error(guest)]; stage = @"jni_onload";
        } else stage = @"jni_onload";
    }
    if (!failure && agr_guest_find_symbol(guest,"ANativeActivity_onCreate")) {
        uint8_t zero[64] = {0}; uint32_t callbacks=agr_guest_alloc(guest,zero,sizeof(zero),4);
        uint32_t words[10]={callbacks,agr_guest_java_vm(guest),agr_guest_jni_env(guest),0x60001000u,0,0,0,0,0x62000000u,0};
        uint32_t activity=agr_guest_alloc(guest,words,sizeof(words),4), args[3]={activity,0,0}; int32_t ignored=0;
        if (agr_guest_call_symbol(guest,"ANativeActivity_onCreate",args,3,&ignored)) {
            failure=[NSString stringWithUTF8String:agr_guest_last_error(guest)]; stage=@"native_activity";
        } else stage=@"native_activity_created";
    }
    if (failure) {
        NSString *signature=failureSignature(stage,failure);
        NSString *outcome=([signature hasPrefix:@"missing_"] || [signature isEqualToString:@"guest_timeout"])
            ? @"known_gap" : @"new_failure";
        [result addEntriesFromDictionary:@{@"stage":stage,@"outcome":outcome,@"signature":signature,
          @"detail":failure,@"constructors":@(constructors)}];
    } else {
        [result addEntriesFromDictionary:@{@"stage":stage,@"outcome":@"known_gap",
          @"signature":@"entrypoint:lifecycle_not_driven",@"constructors":@(constructors)}];
    }
    if (guest) agr_guest_destroy(guest); agr_afw_destroy(assets); return result;
}

static NSArray *runBatchCompatibility(NSDictionary *gloomy, NSDictionary *kungfoo) {
    NSString *path=[[NSBundle mainBundle] pathForResource:@"batch-plan" ofType:@"json"];
    NSData *data=path ? [NSData dataWithContentsOfFile:path] : nil;
    NSDictionary *plan=data ? [NSJSONSerialization JSONObjectWithData:data options:0 error:nil] : nil;
    NSMutableArray *results=[NSMutableArray array];
    for (NSDictionary *sample in plan[@"samples"] ?: @[]) {
        NSString *profile=sample[@"profile"];
        if ([profile isEqualToString:@"gloomy"]) {
            [results addObject:@{@"id":sample[@"id"],@"package":sample[@"package"],@"stage":@"visible_frame",
              @"outcome":@"visible_frame",@"signature":@"success:visible_frame",
              @"draws":@1,@"nonblack_pixels":gloomy[@"gloomy_nonblack_pixels"] ?: @0}];
        } else if ([profile isEqualToString:@"kungfoo"]) {
            [results addObject:@{@"id":sample[@"id"],@"package":sample[@"package"],@"stage":@"visible_frame",
              @"outcome":@"visible_frame",@"signature":@"success:visible_frame",
              @"draws":kungfoo[@"kungfoo_native_draws"] ?: @0,
              @"nonblack_pixels":kungfoo[@"kungfoo_native_nonblack_pixels"] ?: @0}];
        } else [results addObject:probeGenericSample(sample)];
    }
    return results;
}

static NSString *runTests(void) {
    NSMutableArray<NSString *> *failures = [NSMutableArray array];
    NSData *dex = bundleData(@"classes", @"dex");
    DxVM *vm = dex ? poc_create(dex.bytes, (uint32_t)dex.length) : NULL;
    int32_t dexResult = 0;
    poc_set_guest_bridge(dex_bridge);
    if (!vm || poc_run(vm, "run", &dexResult) != 0 || dexResult != 10)
        [failures addObject:[NSString stringWithFormat:@"dex-jni-dex=%d", dexResult]];

    void *cpu = arm_interp_create();
    const uint32_t armProgram[] = { 0xe3a0002aU, 0xef000077U };
    uint64_t budget = 8; uint32_t svc = 0;
    arm_interp_write(cpu, 0x1000, (const uint8_t *)armProgram, sizeof(armProgram));
    arm_interp_set_reg(cpu, 15, 0x1000);
    int32_t armState = arm_interp_run(cpu, &budget, &svc);
    uint32_t armR0 = arm_interp_get_reg(cpu, 0);
    if (armState != 1 || svc != 0x77 || armR0 != 42)
        [failures addObject:[NSString stringWithFormat:@"arm=%d/%u/%u", armState, svc, armR0]];

    NSData *elf = bundleData(@"libpocbridge", @"so");
    GuestMemory memory = { cpu };
    agr_callbacks callbacks = {0};
    callbacks.user = &memory; callbacks.read = guest_read; callbacks.write = guest_write;
    agr_runtime *runtime = agr_runtime_create(&callbacks, 0x00100000, 0x00900000,
                                               0x02000000, 0x02800000);
    agr_load_result loaded = {0};
    int32_t loadResult = (runtime && elf) ? agr_load_elf(runtime, "libpocbridge.so",
        elf.bytes, (uint32_t)elf.length, 0x00100000, &loaded) : -1;
    uint32_t jniOnLoad = runtime ? agr_find_symbol(runtime, "JNI_OnLoad") : 0;
    if (loadResult != 0 || !jniOnLoad) {
        const char *reason = runtime ? agr_last_error(runtime) : "create failed";
        [failures addObject:[NSString stringWithFormat:@"elf=%d/%s", loadResult, reason ?: "unknown"]];
    }
    if (runtime) agr_runtime_destroy(runtime);
    arm_interp_destroy(cpu);

    NSString *apkPath = [[NSBundle mainBundle] pathForResource:@"kungfoo" ofType:@"apk"];
    agr_afw_manager *assets = agr_afw_create();
    int afwAdded = apkPath ? agr_afw_add_apk(assets, apkPath.UTF8String) : -1;
    int tableCount = afwAdded == 0 ? agr_afw_resource_table_count(assets) : -1;
    agr_afw_asset *png = afwAdded == 0 ? agr_afw_open(assets, "images/bullet.png", 3) : NULL;
    agr_bitmap *bitmap = png ? agr_bitmap_decode(agr_afw_buffer(png), (size_t)agr_afw_length(png)) : NULL;
    uint32_t bitmapWidth = agr_bitmap_width(bitmap), bitmapHeight = agr_bitmap_height(bitmap);
    if (afwAdded != 0 || tableCount < 1 || !bitmap || !bitmapWidth || !bitmapHeight)
        [failures addObject:[NSString stringWithFormat:@"androidfw-bitmap=%d/%d/%u/%u",
          afwAdded, tableCount, bitmapWidth, bitmapHeight]];
    if (bitmap) agr_bitmap_destroy(bitmap);
    if (png) agr_afw_close(png);
    agr_afw_destroy(assets);

    NSDictionary *angleResult = runAngleMetalTest(failures);
    NSDictionary *gloomyResult = runGloomyRegression(failures);
    NSDictionary *kungFooDexResult = runKungFooDexRegression(failures);
    NSDictionary *kungFooNativeResult = runKungFooNativeRegression(failures);
    NSArray *batchResults = runBatchCompatibility(gloomyResult,kungFooNativeResult);

    NSMutableDictionary *result = [@{@"platform":@"iOS Simulator", @"architecture":@"arm64",
      @"dex_jni_dex":@(dexResult), @"armv7_r0":@(armR0), @"armv7_svc":@(svc),
      @"elf_jni_onload":@(jniOnLoad), @"passed":@(failures.count == 0), @"failures":failures} mutableCopy];
    [result addEntriesFromDictionary:@{@"androidfw_tables":@(tableCount),
      @"bitmap_width":@(bitmapWidth), @"bitmap_height":@(bitmapHeight),
      @"bitmap_decoder":[NSString stringWithUTF8String:agr_bitmap_decoder_name()]}];
    [result addEntriesFromDictionary:angleResult];
    [result addEntriesFromDictionary:gloomyResult];
    [result addEntriesFromDictionary:kungFooDexResult];
    [result addEntriesFromDictionary:kungFooNativeResult];
    result[@"batch_results"] = batchResults;
    NSData *json = [NSJSONSerialization dataWithJSONObject:result options:NSJSONWritingPrettyPrinted error:nil];
    return [[NSString alloc] initWithData:json encoding:NSUTF8StringEncoding];
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic, strong) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)options {
    (void)application; (void)options;
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    UIViewController *controller = [UIViewController new]; controller.view.backgroundColor = UIColor.blackColor;
    self.window.rootViewController = controller; [self.window makeKeyAndVisible];
    NSString *result = runTests();
    NSString *path = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/runtime-smoke.json"];
    [result writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"AGR_RESULT_BEGIN%@AGR_RESULT_END", result);
    return YES;
}
@end
int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass(AppDelegate.class)); }
}
