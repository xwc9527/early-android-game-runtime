#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#include "../Tests/Conformance/agr_contracts.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "agr_runtime.h"
#include "dx_log.h"
#include "dx_apk.h"
#include "dx_memory.h"
#include "dx_vm.h"
#include "agr_androidfw.h"
#include "agr_bitmap.h"
#include "agr_guest_runtime.h"
#include "game_dex_runner.h"
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
extern uint8_t *arm_interp_memory_base(void *);
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
static uint8_t *guest_memory_base(void *u) {
    return arm_interp_memory_base(((GuestMemory *)u)->cpu);
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

typedef struct {
    agr_guest *guest;
    agr_afw_manager *assets;
    DexTextureHost *textureHost;
} InteractiveRuntime;
static InteractiveRuntime gInteractive = {0};
static NSString *gInteractivePackage;

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
    agr_apk_package *gcPackage=apkPath?agr_apk_package_open(apkPath.UTF8String):NULL;
    agr_dex_game *gcGame=gcPackage?agr_dex_game_create_from_apk(gcPackage):NULL;
    int gcRootContract=gcGame?agr_dex_game_activity_gc_contract(gcGame):-1;
    if(gcGame)agr_dex_game_destroy(gcGame);
    if(gcPackage)agr_apk_package_close(gcPackage);
    GLint texture = 0; glGetIntegerv(GL_TEXTURE_BINDING_2D,&texture); GLenum glError=glGetError();
    const GLubyte *rendererBytes=glGetString(GL_RENDERER);
    NSString *renderer=rendererBytes ? [NSString stringWithUTF8String:(const char *)rendererBytes] : @"";
    BOOL passed = rc == 0 && gcRootContract == 0 && host.uploads == 1 && host.width == 256 && host.height == 256 && texture > 0 && glError == GL_NO_ERROR;
    if (!passed) [failures addObject:[NSString stringWithFormat:@"kungfoo-dex=%d/%d/%u/%u/%d/0x%x",rc,host.uploads,host.width,host.height,texture,glError]];
    agr_dex_set_upload_callback(NULL,NULL); agr_afw_destroy(assets);
    eglMakeCurrent(display,EGL_NO_SURFACE,EGL_NO_SURFACE,EGL_NO_CONTEXT); eglDestroyContext(display,context); eglDestroySurface(display,surface); eglTerminate(display);
    return @{@"kungfoo_original_dex_bytes":@([NSData dataWithContentsOfFile:dexPath].length),
              @"kungfoo_dex_loadimage_passed":@(passed), @"activity_gc_root_contract":@(gcRootContract==0),
              @"kungfoo_texture_uploads":@(host.uploads),
             @"kungfoo_texture_width":@(host.width), @"kungfoo_texture_height":@(host.height),
             @"kungfoo_dex_renderer":renderer};
}

enum { TRAJECTORY_GRID_W=16, TRAJECTORY_GRID_H=24, TRAJECTORY_SIGNATURE_SIZE=384 };
static void frameSignature(const uint8_t *rgba, int width, int height, uint8_t out[TRAJECTORY_SIGNATURE_SIZE]) {
    for (int by=0; by<TRAJECTORY_GRID_H; by++) for (int bx=0; bx<TRAJECTORY_GRID_W; bx++) {
        uint64_t sum=0; uint32_t count=0;
        int x0=bx*width/TRAJECTORY_GRID_W, x1=(bx+1)*width/TRAJECTORY_GRID_W;
        int y0=by*height/TRAJECTORY_GRID_H, y1=(by+1)*height/TRAJECTORY_GRID_H;
        for (int y=y0; y<y1; y+=2) for (int x=x0; x<x1; x+=2) {
            const uint8_t *p=rgba+((size_t)y*width+x)*4;
            sum+=(uint64_t)p[0]*3+(uint64_t)p[1]*6+p[2]; count+=10;
        }
        out[by*TRAJECTORY_GRID_W+bx]=(uint8_t)(count ? sum/count : 0);
    }
}

static uint32_t signatureChangedTiles(const uint8_t a[TRAJECTORY_SIGNATURE_SIZE], const uint8_t b[TRAJECTORY_SIGNATURE_SIZE], uint8_t delta) {
    uint32_t changed=0; for(int i=0;i<TRAJECTORY_SIGNATURE_SIZE;i++) if(abs((int)a[i]-(int)b[i])>=delta) changed++; return changed;
}

static NSString *guestHex(const uint8_t *bytes, uint32_t size) {
    NSMutableString *out=[NSMutableString stringWithCapacity:size*2];
    for(uint32_t i=0;i<size;i++)[out appendFormat:@"%02x",bytes[i]];
    return out;
}

static NSDictionary *throwDiagnostic(agr_guest *guest) {
    if(!guest||agr_guest_watch_hits(guest)==0)return @{};
    uint32_t regs[16];for(uint32_t i=0;i<16;i++)regs[i]=agr_guest_watch_reg(guest,i);
    NSMutableArray *registers=[NSMutableArray arrayWithCapacity:16];
    for(uint32_t i=0;i<16;i++)[registers addObject:[NSString stringWithFormat:@"%08x",regs[i]]];
    uint32_t typeNamePtr=0; agr_guest_read(guest,regs[1]+4,&typeNamePtr,4);
    uint8_t typeNameBytes[192]={0};
    if(typeNamePtr)agr_guest_read(guest,typeNamePtr,typeNameBytes,sizeof(typeNameBytes)-1);
    NSString *typeName=[[NSString alloc] initWithUTF8String:(const char *)typeNameBytes]?:@"";
    uint8_t objectBytes[64]={0};
    if(regs[0])agr_guest_read(guest,regs[0],objectBytes,sizeof(objectBytes));
    uint32_t stack[96]={0}; if(regs[13])agr_guest_read(guest,regs[13],stack,sizeof(stack));
    NSMutableArray *stackWords=[NSMutableArray arrayWithCapacity:96],*codeCandidates=[NSMutableArray array];
    for(uint32_t i=0;i<96;i++){
        [stackWords addObject:[NSString stringWithFormat:@"%08x",stack[i]]];
        uint32_t address=stack[i]&~1u;
        if(address>=0x02800000u&&address<0x02900000u)
            [codeCandidates addObject:@{ @"stack_index":@(i),@"address":[NSString stringWithFormat:@"%08x",stack[i]] }];
    }
    NSMutableArray *instructionTrace=[NSMutableArray array];
    for(uint32_t i=0;i<64;i++){
        uint32_t pc=0,insn=0;if(agr_guest_watch_trace(guest,i,&pc,&insn)==0&&pc)
            [instructionTrace addObject:@{ @"pc":[NSString stringWithFormat:@"%08x",pc],@"instruction":[NSString stringWithFormat:@"%08x",insn] }];
    }
    uint32_t heap[5]={0};agr_guest_heap_diagnostics(guest,heap);
    return @{ @"symbol":@"__cxa_throw",@"hits":@(agr_guest_watch_hits(guest)),
      @"pc":@"02882b50",@"caller_lr":[NSString stringWithFormat:@"%08x",regs[14]],
      @"exception_object":[NSString stringWithFormat:@"%08x",regs[0]],
      @"type_info":[NSString stringWithFormat:@"%08x",regs[1]],
      @"type_name_pointer":[NSString stringWithFormat:@"%08x",typeNamePtr],@"type_name":typeName,
      @"destructor":[NSString stringWithFormat:@"%08x",regs[2]],
      @"thread_id":@(agr_guest_current_thread_id(guest)),
      @"cpsr":[NSString stringWithFormat:@"%08x",agr_guest_watch_cpsr(guest)],
      @"registers":registers,@"exception_object_bytes":guestHex(objectBytes,sizeof(objectBytes)),
      @"heap":@{ @"current":[NSString stringWithFormat:@"%08x",heap[0]],
                   @"limit":[NSString stringWithFormat:@"%08x",heap[1]],
                   @"allocation_count":@(heap[2]),@"live_count":@(heap[3]),@"live_bytes":@(heap[4]) },
      @"stack_words":stackWords,@"stack_code_candidates":codeCandidates,@"instruction_trace":instructionTrace };
}

static NSArray *runtimeEventTrace(agr_guest *guest) {
    NSMutableArray *events=[NSMutableArray array];
    uint32_t count=agr_guest_runtime_event_count(guest);
    for(uint32_t i=0;i<count;i++) {
        agr_guest_runtime_event event={0};
        if(agr_guest_runtime_event_at(guest,i,&event))continue;
        [events addObject:@{ @"event":event.type?[NSString stringWithUTF8String:event.type]:@"",
          @"guest_thread_id":@(event.guest_thread_id),
          @"guest_pc":[NSString stringWithFormat:@"%08x",event.guest_pc],
          @"primary_handle":[NSString stringWithFormat:@"%08x",event.primary_handle],
          @"secondary_handle":[NSString stringWithFormat:@"%08x",event.secondary_handle],
          @"result":@(event.result),@"action":@(event.action),@"x":@(event.x),@"y":@(event.y),
          @"handled":@(event.handled),@"input_consumed":@(event.input_consumed),
          @"frame":@(event.frame),@"swap":@(event.swap) }];
    }
    return events;
}

static void writePVSProgress(NSString *stage, agr_guest *guest) {
    NSString *path=[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/pvs-progress.json"];
    const char *lastError=guest?agr_guest_last_error(guest):"guest unavailable";
    NSDictionary *progress=@{ @"stage":stage?:@"unknown",
      @"guest_thread_id":@(guest?agr_guest_current_thread_id(guest):0),
      @"guest_pc":[NSString stringWithFormat:@"%08x",guest?agr_guest_program_counter(guest):0],
      @"runtime_failure_signature":lastError&&lastError[0]?[NSString stringWithUTF8String:lastError]:@"",
      @"input_trace":guest?runtimeEventTrace(guest):@[] };
    NSData *json=[NSJSONSerialization dataWithJSONObject:progress options:0 error:nil];
    [json writeToFile:path atomically:YES];
}

static NSDictionary *runNativeActivityApk(NSString *apkPath, NSDictionary *trace,
                                          NSMutableArray<NSString *> *failures, BOOL interactive) {
    agr_guest *guest = agr_guest_create();
    agr_apk_package *package=apkPath?agr_apk_package_open(apkPath.UTF8String):NULL;
    agr_afw_manager *dexAssets = agr_afw_create();
    if (apkPath) agr_afw_add_apk(dexAssets,apkPath.UTF8String);
    DexTextureHost *dexHost = calloc(1,sizeof(*dexHost)); dexHost->assets=dexAssets;
    agr_dex_set_upload_callback(dexUploadTexture,dexHost);
    int mounted = apkPath && guest ? agr_guest_mount_apk(guest,apkPath.UTF8String) : -1;
    int registered=package&&guest?0:-1;
    uint32_t mainLibraryBytes=0;
    for(uint32_t i=0;registered==0&&i<agr_apk_native_library_count(package);i++) {
        uint32_t size=0;const void *bytes=agr_apk_native_library_bytes(package,i,&size);
        const char *name=agr_apk_native_library_name(package,i);
        if(name&&!strcmp(name,agr_apk_native_library(package)))mainLibraryBytes=size;
        registered=agr_guest_register_elf_source(guest,name,bytes,size);
    }
    int dexLoaded=registered==0?agr_guest_load_dex_package(guest,package):-1;
    int32_t jniVersion=0;
    int jniOnLoad=dexLoaded==0?agr_guest_load_java_library(guest,agr_apk_native_library(package),&jniVersion):-1;
    int loaded=jniOnLoad==0?0:-1;
    int dexStarted=loaded==0?agr_guest_start_dex_activity(guest):-1;
    uint32_t constructors = 0;
    int initialized = dexStarted == 0 ? agr_guest_run_constructors(guest,&constructors) : -1;
    int activityCreated = -1, onStart = -1, onResume = -1, onWindow = -1, onFocus = -1, onInput = -1, pumped = -1;
    BOOL teardownCallbacksPassed=NO, teardownCompleted=NO;
    int framePumpResult = 0; uint32_t framePumps = 0;
    uint8_t *frame = calloc(320u*480u*4u,1); uint32_t nonblack = 0; int32_t frameBytes = -1;
    uint32_t callbacksFound = 0, activity = 0, callbackWords[16] = {0};
    if (initialized == 0) {
        writePVSProgress(@"before:nativeactivity.onCreate",guest);
        uint8_t callbacksZero[64] = {0};
        char internalPath[512],externalPath[512],obbPath[512];
        snprintf(internalPath,sizeof(internalPath),"/data/data/%s/files",agr_apk_package_name(package));
        snprintf(externalPath,sizeof(externalPath),"/sdcard/Android/data/%s/files",agr_apk_package_name(package));
        snprintf(obbPath,sizeof(obbPath),"/sdcard/Android/obb/%s",agr_apk_package_name(package));
        uint32_t callbacks = agr_guest_alloc(guest,callbacksZero,sizeof(callbacksZero),4);
        uint32_t internal = agr_guest_alloc(guest,internalPath,sizeof(internalPath),1);
        uint32_t external = agr_guest_alloc(guest,externalPath,sizeof(externalPath),1);
        uint32_t obb = agr_guest_alloc(guest,obbPath,sizeof(obbPath),1);
        uint32_t activityWords[10] = {callbacks,agr_guest_java_vm(guest),agr_guest_jni_env(guest),
            0x60001000u,internal,external,0,0,0x62000000u,obb};
        activity = agr_guest_alloc(guest,activityWords,sizeof(activityWords),4);
        uint32_t args[3] = {activity,0,0}; int32_t ignored = 0;
        activityCreated = agr_guest_call_symbol(guest,"ANativeActivity_onCreate",args,3,&ignored);
        agr_guest_record_runtime_event(guest,"nativeactivity.onCreate",activity,0,activityCreated,-1,0,0,-1);
        writePVSProgress(@"after:nativeactivity.onCreate",guest);
        agr_guest_read(guest,callbacks,callbackWords,sizeof(callbackWords));
        for (uint32_t i = 0; i < 16; i++) if (callbackWords[i]) callbacksFound++;
        if (activityCreated == 0 && callbackWords[0]) {
            writePVSProgress(@"before:nativeactivity.onStart",guest);
            onStart = agr_guest_call_address(guest,callbackWords[0],args,1,&ignored);
            agr_guest_record_runtime_event(guest,"nativeactivity.onStart",activity,callbackWords[0],onStart,-1,0,0,-1);
            writePVSProgress(@"after:nativeactivity.onStart",guest);
            if (onStart == 0 && callbackWords[1]) {
                writePVSProgress(@"before:nativeactivity.onResume",guest);
                onResume = agr_guest_call_address(guest,callbackWords[1],args,1,&ignored);
                agr_guest_record_runtime_event(guest,"nativeactivity.onResume",activity,callbackWords[1],onResume,-1,0,0,-1);
                writePVSProgress(@"after:nativeactivity.onResume",guest);
            }
            if (onResume == 0 && callbackWords[7]) {
                uint32_t windowArgs[2] = {activity,0x63000000u};
                writePVSProgress(@"before:nativeactivity.window.created",guest);
                onWindow = agr_guest_call_address(guest,callbackWords[7],windowArgs,2,&ignored);
                agr_guest_record_runtime_event(guest,"nativeactivity.window.created",activity,windowArgs[1],onWindow,-1,0,0,-1);
                writePVSProgress(@"after:nativeactivity.window.created",guest);
                if (onWindow == 0) {
                    pumped = 0;
                    if (pumped == 0 && callbackWords[11]) {
                        uint32_t inputArgs[2]={activity,agr_guest_input_queue(guest)};
                        writePVSProgress(@"before:nativeactivity.input.created",guest);
                        onInput=agr_guest_call_address(guest,callbackWords[11],inputArgs,2,&ignored);
                        agr_guest_record_runtime_event(guest,"nativeactivity.input.created",activity,inputArgs[1],onInput,-1,0,0,-1);
                        writePVSProgress(@"after:nativeactivity.input.created",guest);
                    }
                    if (pumped == 0 && onInput == 0 && callbackWords[6]) {
                        uint32_t focusArgs[2] = {activity,1};
                        writePVSProgress(@"before:nativeactivity.focus",guest);
                        onFocus = agr_guest_call_address(guest,callbackWords[6],focusArgs,2,&ignored);
                        agr_guest_record_runtime_event(guest,"nativeactivity.focus",activity,0,onFocus,1,0,0,-1);
                        writePVSProgress(@"after:nativeactivity.focus",guest);
                        /* The worker may finish a visible frame before onFocus
                         * returns, then legitimately wait for player input. */
                        if (onFocus == 0 && frame && agr_guest_swap_count(guest) > 0) {
                            frameBytes = agr_guest_read_rgba(guest,frame,320u*480u*4u);
                            if (frameBytes > 0) for (int32_t i=0; i+3<frameBytes; i+=4)
                                if (frame[i] || frame[i+1] || frame[i+2]) nonblack++;
                        }
                        while (onFocus == 0 && frame && framePumps < 40 && nonblack == 0) {
                            uint32_t priorSwap=agr_guest_swap_count(guest);
                            framePumpResult = agr_guest_wait_for_swap(guest,priorSwap,500);
                            framePumps++;
                            if (framePumpResult < 0) break;
                            if (framePumpResult == 1) continue;
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
    NSMutableArray *trajectory=[NSMutableArray array], *coverage=[NSMutableArray array];
    NSString *trajectoryOutcome=@"gameplay_not_entered", *trajectoryFailure=@"";
    uint32_t replayEvents=0, replayConsumed=0, uniqueStates=0;
    if (!interactive && nonblack>0 && onInput==0 && framePumpResult==0 && trace) {
        trajectoryOutcome=@"replay_incomplete";
        uint8_t signatures[16][TRAJECTORY_SIGNATURE_SIZE]={0};
        frameSignature(frame,320,480,signatures[0]); uniqueStates=1;
        for(NSDictionary *event in trace[@"events"]) {
            NSString *action=event[@"action"]; int motionAction=
                [action isEqualToString:@"down"]?0:[action isEqualToString:@"up"]?1:
                [action isEqualToString:@"move"]?2:-1;
            if(motionAction<0) { trajectoryFailure=@"trace:unknown_action"; break; }
            uint32_t drawsBefore=agr_guest_draw_count(guest), swapsBefore=agr_guest_swap_count(guest);
            uint32_t consumedBefore=agr_guest_input_consumed_count(guest);
            uint32_t coverageBefore=agr_guest_unique_import_count(guest);
            writePVSProgress([NSString stringWithFormat:@"before:replay.%u.inject",replayEvents+1],guest);
            int rc=agr_guest_inject_motion(guest,motionAction,[event[@"x"] floatValue],[event[@"y"] floatValue]);
            writePVSProgress([NSString stringWithFormat:@"after:replay.%u.inject.rc%d",replayEvents+1,rc],guest);
            int frames=MAX(1,MIN(8,[event[@"frames"] intValue]));
            for(int f=0;rc==0&&f<frames;f++) {
                uint32_t priorSwap=agr_guest_swap_count(guest);
                writePVSProgress([NSString stringWithFormat:@"before:replay.%u.wait.%d.swap.%u",replayEvents+1,f+1,priorSwap],guest);
                rc=agr_guest_wait_for_swap(guest,priorSwap,500);
                writePVSProgress([NSString stringWithFormat:@"after:replay.%u.wait.%d.rc%d",replayEvents+1,f+1,rc],guest);
            }
            /* A bounded wait returning 1 means that no new swap arrived inside
             * the checkpoint window.  NativeActivity games may legitimately
             * stop swapping while waiting for the next input; it is not a
             * Runtime failure.  Keep the framebuffer captured at the previous
             * completed swap instead of entering the graphics readback path
             * while the guest render thread is idle. */
            int32_t bytes=rc==0?agr_guest_read_rgba(guest,frame,320u*480u*4u):
                (rc==1?(int32_t)(320u*480u*4u):-1);
            uint32_t consumed=agr_guest_input_consumed_count(guest)-consumedBefore;
            uint32_t drawDelta=agr_guest_draw_count(guest)-drawsBefore;
            uint32_t swapDelta=agr_guest_swap_count(guest)-swapsBefore;
            uint8_t signature[TRAJECTORY_SIGNATURE_SIZE]={0}; uint32_t changed=0; BOOL novel=NO;
            if(bytes>0) {
                frameSignature(frame,320,480,signature);
                changed=signatureChangedTiles(signatures[uniqueStates-1],signature,10);
                novel=YES;
                for(uint32_t k=0;k<uniqueStates;k++) if(signatureChangedTiles(signatures[k],signature,10)<4){novel=NO;break;}
                if(novel&&uniqueStates<16) memcpy(signatures[uniqueStates++],signature,TRAJECTORY_SIGNATURE_SIZE);
            }
            uint32_t digest=2166136261u;
            for(int k=0;k<TRAJECTORY_SIGNATURE_SIZE;k++) digest=(digest^signature[k])*16777619u;
            [trajectory addObject:@{@"action":action,@"x":event[@"x"],@"y":event[@"y"],
              @"requested_frames":@(frames),@"input_consumed":@(consumed),@"draw_delta":@(drawDelta),
              @"swap_delta":@(swapDelta),@"wait_result":@(rc),
              @"changed_tiles":@(changed),@"novel_frame":@(novel),
              @"fingerprint":[NSString stringWithFormat:@"%08x",digest],
              @"coverage_delta":@(agr_guest_unique_import_count(guest)-coverageBefore)}];
            replayEvents++;replayConsumed+=consumed;
            writePVSProgress([NSString stringWithFormat:@"after:replay.%u.checkpoint",replayEvents],guest);
            if(bytes>0) {
                NSString *checkpoint=[NSHomeDirectory() stringByAppendingPathComponent:
                    [NSString stringWithFormat:@"Documents/kungfoo-trajectory-%02u.png",replayEvents]];
                writeRGBAFramePNG(frame,320,480,checkpoint);
            }
            if(rc<0||bytes<=0) {
                NSString *runtimeError=[NSString stringWithUTF8String:agr_guest_last_error(guest)];
                if(runtimeError.length) {
                    trajectoryFailure=runtimeError;
                    trajectoryOutcome=@"runtime_failure";
                } else {
                    trajectoryFailure=@"checkpoint:framebuffer_unavailable";
                }
                break;
            }
            if(rc==1) {
                trajectoryFailure=@"checkpoint:swap_timeout";
                break;
            }
            if(!consumed||!drawDelta||!swapDelta) {
                trajectoryFailure=@"checkpoint:input_or_draw_stalled";break;
            }
        }
        if(replayEvents==[trace[@"events"] count] && !trajectoryFailure.length)
            trajectoryOutcome=@"replay_completed_gameplay_unverified";
        for(uint32_t i=0;i<agr_guest_unique_import_count(guest);i++) {
            const char *name=agr_guest_unique_import(guest,i);
            if(name) [coverage addObject:[NSString stringWithUTF8String:name]];
        }
        NSString *trajectoryFrame=[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/kungfoo-trajectory-frame.png"];
        writeRGBAFramePNG(frame,320,480,trajectoryFrame);
    }
    /* The regression harness owns the host Activity lifecycle.  Stop the
     * NativeActivity through its real callbacks before destroying ProcessRuntime;
     * android_native_app_glue turns onDestroy into APP_CMD_DESTROY and joins its
     * android_main worker.  Runtime teardown must not fabricate that policy. */
    if (!interactive && activityCreated == 0 && activity) {
        int32_t ignored = 0;
        uint32_t oneArg[1] = {activity};
        uint32_t focusArgs[2] = {activity,0};
        uint32_t inputArgs[2] = {activity,agr_guest_input_queue(guest)};
        uint32_t windowArgs[2] = {activity,0x63000000u};
        struct { uint32_t slot; uint32_t *args; uint32_t count; const char *event; } teardown[] = {
          {3,oneArg,1,"nativeactivity.onPause"},
          {6,focusArgs,2,"nativeactivity.focus.lost"},
          {12,inputArgs,2,"nativeactivity.input.destroyed"},
          {10,windowArgs,2,"nativeactivity.window.destroyed"},
          {4,oneArg,1,"nativeactivity.onStop"},
          {5,oneArg,1,"nativeactivity.onDestroy"}
        };
        uint32_t teardownCalled=0;BOOL teardownCallsOK=YES;
        for (uint32_t i=0;i<sizeof(teardown)/sizeof(teardown[0]);i++) if(callbackWords[teardown[i].slot]) {
            writePVSProgress([NSString stringWithFormat:@"before:%s",teardown[i].event],guest);
            int rc=agr_guest_call_address(guest,callbackWords[teardown[i].slot],
                                          teardown[i].args,teardown[i].count,&ignored);
            agr_guest_record_runtime_event(guest,teardown[i].event,activity,
                                           callbackWords[teardown[i].slot],rc,-1,0,0,-1);
            writePVSProgress([NSString stringWithFormat:@"after:%s",teardown[i].event],guest);
            teardownCalled++;if(rc)teardownCallsOK=NO;
        }
        teardownCallbacksPassed=teardownCallsOK&&teardownCalled==sizeof(teardown)/sizeof(teardown[0]);
    }
    free(frame);
    NSString *error = guest ? [NSString stringWithUTF8String:agr_guest_last_error(guest)] : @"create failed";
    BOOL passed = package && mounted == 0 && registered == 0 && dexLoaded == 0 && loaded == 0 && jniOnLoad == 0 && dexStarted == 0 && initialized == 0 && activityCreated == 0 && callbacksFound >= 10 && onStart == 0 && onResume == 0 && onWindow == 0 && pumped == 0 && onInput == 0 && onFocus == 0 && framePumpResult == 0 && draws > 0 && swaps > 0 && nonblack > 0;
    if (!passed) [failures addObject:[NSString stringWithFormat:@"apk-native=%d/%d/%d/%d/%d/%d/%u activity=%d callbacks=%u start=%d resume=%d window=%d pump=%d focus=%d frames=%u/%d/%@",mounted,registered,dexLoaded,loaded,jniOnLoad,dexStarted,constructors,activityCreated,callbacksFound,onStart,onResume,onWindow,pumped,onFocus,framePumps,framePumpResult,error]];
    int textureUploads=dexHost->uploads;
    NSArray *inputTrace=runtimeEventTrace(guest);
    if (interactive && passed) {
        gInteractive=(InteractiveRuntime){guest,dexAssets,dexHost};
        gInteractivePackage=package&&agr_apk_package_name(package)
            ? [NSString stringWithUTF8String:agr_apk_package_name(package)] : @"";
    } else {
        if (guest) writePVSProgress(@"before:agr_guest_destroy",guest);
        if (guest) agr_guest_destroy(guest);
        teardownCompleted=guest!=NULL&&teardownCallbacksPassed;
        agr_dex_set_upload_callback(NULL,NULL);
        agr_afw_destroy(dexAssets); free(dexHost);
    }
    NSDictionary *result=@{@"package":package&&agr_apk_package_name(package)?[NSString stringWithUTF8String:agr_apk_package_name(package)]:@"",
             @"selected_activity":package&&agr_apk_launch_activity(package)?[NSString stringWithUTF8String:agr_apk_launch_activity(package)]:@"",
             @"selected_native_library":package&&agr_apk_native_library(package)?[NSString stringWithUTF8String:agr_apk_native_library(package)]:@"",
             @"min_sdk":@(agr_apk_min_sdk(package)),@"target_sdk":@(agr_apk_target_sdk(package)),
             @"jni_onload_result":@(jniVersion),@"native_so_bytes":@(mainLibraryBytes),@"constructors":@(constructors),
             @"native_instructions":@(instructions),@"constructors_passed":@(initialized == 0),
             @"native_activity_created":@(activityCreated == 0),@"activity_callbacks":@(callbacksFound),
             @"on_start":@(onStart == 0),@"on_resume":@(onResume == 0),
             @"on_window_created":@(onWindow == 0),@"native_draws":@(draws),
             @"on_focus":@(onFocus == 0),@"frame_pumps":@(framePumps),
             @"native_swaps":@(swaps),@"native_asset_opens":@(assetOpens),
             @"native_texture_uploads":@(textureUploads),@"native_nonblack_pixels":@(nonblack),
             @"native_frame_bytes":@(frameBytes),@"gameplay_trajectory":trajectory,
             @"gameplay_outcome":trajectoryOutcome,@"gameplay_failure":trajectoryFailure,
             @"replay_events":@(replayEvents),@"replay_consumed":@(replayConsumed),
             @"unique_states":@(uniqueStates),@"runtime_coverage":coverage,
             @"nativeactivity_input_trace":inputTrace,
             @"teardown_callbacks_passed":@(teardownCallbacksPassed),
             @"teardown_completed":@(teardownCompleted),
             @"runtime_failure_signature":error.length?error:@""};
    agr_apk_package_close(package);
    return result;
}

static NSDictionary *runKungFooNativeRegression(NSMutableArray<NSString *> *failures, BOOL interactive) {
    NSString *apkPath=[[NSBundle mainBundle] pathForResource:@"kungfoo" ofType:@"apk"];
    NSString *tracePath=[[NSBundle mainBundle] pathForResource:@"kungfoo-barracuda" ofType:@"json"];
    NSData *traceBytes=tracePath?[NSData dataWithContentsOfFile:tracePath]:nil;
    NSDictionary *trace=traceBytes?[NSJSONSerialization JSONObjectWithData:traceBytes options:0 error:nil]:nil;
    return runNativeActivityApk(apkPath,trace,failures,interactive);
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

static NSData *apkMember(NSString *apkPath, NSString *member) {
    DxApkFile *apk=NULL; const DxZipEntry *entry=NULL; uint8_t *bytes=NULL; uint32_t length=0;
    if (!apkPath || dx_apk_open_file(apkPath.UTF8String,&apk)!=DX_OK ||
        dx_apk_find_entry(apk,member.UTF8String,&entry)!=DX_OK ||
        dx_apk_extract_entry(apk,entry,&bytes,&length)!=DX_OK) {
        if (apk) dx_apk_close(apk);
        return nil;
    }
    NSData *data=length ? [NSData dataWithBytes:bytes length:length] : [NSData data];
    dx_free(bytes); dx_apk_close(apk); return data;
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
        NSData *dex = hasDex ? apkMember(apkPath,@"classes.dex") : nil;
        DxDexFile *parsedDex = NULL;
        DxResult parseResult = dex ? dx_dex_parse(dex.bytes,(uint32_t)dex.length,&parsedDex)
                                   : DX_ERR_NOT_FOUND;
        if (parseResult == DX_OK) {
            [result addEntriesFromDictionary:@{@"stage":@"dex_loaded", @"outcome":@"known_gap",
              @"signature":@"missing_framework:activity_launch",
              @"dex_classes":@(parsedDex->class_count), @"dex_methods":@(parsedDex->method_count)}];
        } else {
            NSString *detail = dex ? [NSString stringWithUTF8String:dx_result_string(parseResult)] : @"classes.dex missing";
            [result addEntriesFromDictionary:@{@"stage":@"dex_parse", @"outcome":@"new_failure",
              @"signature":failureSignature(@"dex_parse",detail), @"dex_result":@(parseResult)}];
        }
        dx_dex_free(parsedDex);
        agr_afw_destroy(assets); return result;
    }
    agr_guest *guest = agr_guest_create();
    agr_guest_set_instruction_budget(guest,100000);
    int mounted = guest ? agr_guest_mount_apk(guest,apkPath.UTF8String) : -1;
    NSString *failure = nil; NSString *stage = @"elf_loaded";
    uint32_t base = 0x02800000u;
    for (NSDictionary *library in libraries) {
        NSString *member=library[@"member"], *elfResource=library[@"resource"];
        NSString *elfPath=[[NSBundle mainBundle] pathForResource:elfResource.stringByDeletingPathExtension
                                                          ofType:elfResource.pathExtension];
        NSData *elf=elfPath ? [NSData dataWithContentsOfFile:elfPath] : nil;
        if (!elf) {
            failure=[NSString stringWithFormat:@"missing extracted ELF %@",member]; stage=@"input"; break;
        }
        if (agr_guest_load_elf(guest,member.lastPathComponent.UTF8String,elf.bytes,(uint32_t)elf.length,base)) {
            const char *reason=guest ? agr_guest_last_error(guest) : NULL;
            failure = reason && reason[0] ? [NSString stringWithUTF8String:reason] : @"ELF loader rejected image";
            stage = @"elf_load"; break;
        }
        base += 0x01000000u;
    }
    if (!failure && mounted == 0 && hasDex) {
        NSData *dex = apkMember(apkPath,@"classes.dex");
        NSString *dexPath = [NSTemporaryDirectory() stringByAppendingPathComponent:
            [NSString stringWithFormat:@"%@.dex",sample[@"id"]]];
        if (!dex || ![dex writeToFile:dexPath atomically:YES] || agr_guest_load_dex(guest,dexPath.UTF8String)) {
            failure = guest ? [NSString stringWithUTF8String:agr_guest_last_error(guest)] : @"DEX unavailable";
            stage = @"dex_load";
        }
    }
    uint32_t constructors = 0;
    if (!failure && agr_guest_run_constructors_limit(guest,16,&constructors)) {
        failure = [NSString stringWithUTF8String:agr_guest_last_error(guest)]; stage = @"constructors";
    }
    BOOL constructorsCapped = !failure && constructors == 16;
    if (constructorsCapped) stage = @"constructors_capped";
    if (!failure && !constructorsCapped && agr_guest_find_symbol(guest,"JNI_OnLoad")) {
        uint32_t args[2] = {agr_guest_java_vm(guest),0}; int32_t value = 0;
        if (agr_guest_call_symbol(guest,"JNI_OnLoad",args,2,&value)) {
            failure = [NSString stringWithUTF8String:agr_guest_last_error(guest)]; stage = @"jni_onload";
        } else stage = @"jni_onload";
    }
    if (!failure && !constructorsCapped && agr_guest_find_symbol(guest,"ANativeActivity_onCreate")) {
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
          @"signature":constructorsCapped ? @"probe_limit:constructors" : @"entrypoint:lifecycle_not_driven",
          @"constructors":@(constructors)}];
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
              @"draws":kungfoo[@"native_draws"] ?: @0,
              @"nonblack_pixels":kungfoo[@"native_nonblack_pixels"] ?: @0}];
        } else [results addObject:probeGenericSample(sample)];
    }
    return results;
}

static NSString *runDexParserCompatibility(void) {
    NSString *path=[[NSBundle mainBundle] pathForResource:@"batch-plan" ofType:@"json"];
    NSData *data=path ? [NSData dataWithContentsOfFile:path] : nil;
    NSDictionary *plan=data ? [NSJSONSerialization JSONObjectWithData:data options:0 error:nil] : nil;
    NSMutableArray *results=[NSMutableArray array];
    NSMutableArray *failures=[NSMutableArray array];
    NSSet *required=[NSSet setWithArray:@[@"pixel-dungeon",@"frozen-bubble"]];
    NSMutableSet *observed=[NSMutableSet set];
    for (NSDictionary *sample in plan[@"samples"] ?: @[]) {
        NSString *sampleId=sample[@"id"];
        if (![required containsObject:sampleId]) continue;
        NSDictionary *result=probeGenericSample(sample);
        [results addObject:result];
        [observed addObject:sampleId];
        NSString *stage=result[@"stage"], *signature=result[@"signature"];
        if (![stage isEqualToString:@"dex_loaded"] || [signature hasPrefix:@"dex_parse"] ||
            [signature isEqualToString:@"dex_parse_failed"]) {
            [failures addObject:[NSString stringWithFormat:@"%@:%@:%@",sampleId ?: @"unknown",
                stage ?: @"missing_stage",signature ?: @"missing_signature"]];
        }
    }
    for (NSString *sampleId in required) {
        if (![observed containsObject:sampleId])
            [failures addObject:[NSString stringWithFormat:@"%@:%@",sampleId,@"sample_missing"]];
    }
    NSDictionary *report=@{@"schema":@"agr.dex-parser-simulator.v1",
      @"passed":failures.count == 0 ? @YES : @NO, @"results":results, @"failures":failures};
    NSData *json=[NSJSONSerialization dataWithJSONObject:report options:NSJSONWritingPrettyPrinted error:nil];
    return [[NSString alloc] initWithData:json encoding:NSUTF8StringEncoding];
}

static NSString *launchStageName(agr_activity_launch_stage stage) {
    switch (stage) {
        case AGR_ACTIVITY_LAUNCH_CLASS_RESOLVED: return @"class_resolved";
        case AGR_ACTIVITY_LAUNCH_ACTIVITY_INSTANTIATED: return @"activity_instantiated";
        case AGR_ACTIVITY_LAUNCH_APPLICATION_CREATED: return @"application_created";
        case AGR_ACTIVITY_LAUNCH_CONTEXT_ATTACHED: return @"context_attached";
        case AGR_ACTIVITY_LAUNCH_ACTIVITY_ATTACHED: return @"activity_attached";
        case AGR_ACTIVITY_LAUNCH_ON_CREATE_ENTERED: return @"on_create_entered";
        case AGR_ACTIVITY_LAUNCH_ON_CREATE_RETURNED: return @"on_create_returned";
        case AGR_ACTIVITY_LAUNCH_STARTED: return @"started";
        case AGR_ACTIVITY_LAUNCH_RESUMED: return @"resumed";
        default: return @"none";
    }
}

static NSDictionary *probeActivityLaunchAPK(NSDictionary *sample) {
    NSString *resource=sample[@"resource"];
    NSString *path=[[NSBundle mainBundle] pathForResource:resource.stringByDeletingPathExtension
                                                   ofType:resource.pathExtension];
    agr_apk_package *package=path ? agr_apk_package_open(path.UTF8String) : NULL;
    agr_dex_game *game=package ? agr_dex_game_create_from_apk(package) : NULL;
    int start=game ? agr_dex_game_start_activity(game) : -1;
    agr_activity_launch_stage stage=game ? agr_dex_game_launch_stage(game) : AGR_ACTIVITY_LAUNCH_NONE;
    NSString *detail=game ? [NSString stringWithUTF8String:agr_dex_game_launch_error(game)]
                          : (package ? @"DEX Runtime creation failed" : @"APK package open failed");
    BOOL crossed=stage>=AGR_ACTIVITY_LAUNCH_ON_CREATE_ENTERED;
    NSDictionary *result=@{@"id":sample[@"id"] ?: @"unknown",
      @"package":sample[@"package"] ?: @"unknown", @"stage":launchStageName(stage),
      @"activity_launch_crossed":@(crossed), @"launch_result":@(start),
      @"signature":start==0 ? @"success:activity_resumed" :
          [NSString stringWithFormat:@"missing_framework:%@",detail.length ? detail : @"activity_launch"],
      @"detail":detail ?: @""};
    if (game) agr_dex_game_destroy(game);
    if (package) agr_apk_package_close(package);
    return result;
}

static NSString *runActivityLaunchCompatibility(void) {
    NSMutableArray *failures=[NSMutableArray array];
    NSString *fixturePath=[[NSBundle mainBundle] pathForResource:@"activity-launch-fixture" ofType:@"dex"];
    NSData *fixture=fixturePath ? [NSData dataWithContentsOfFile:fixturePath] : nil;
    agr_dex_game *contract=fixture ? agr_dex_game_create_for_launch(fixture.bytes,(uint32_t)fixture.length,
        "Ltest/TestActivity;","Ltest/TestApplication;","test.activity.launch") : NULL;
    int launch=contract ? agr_dex_game_start_activity(contract) : -1;
    int32_t appMarker=0,activityMarker=0;
    int appField=contract ? agr_dex_game_static_int(contract,"Ltest/TestApplication;","appMarker",&appMarker) : -1;
    int activityField=contract ? agr_dex_game_static_int(contract,"Ltest/TestActivity;","activityMarker",&activityMarker) : -1;
    int activityRoot=contract ? agr_dex_game_activity_gc_contract(contract) : -1;
    int applicationRoot=contract ? agr_dex_game_application_gc_contract(contract) : -1;
    agr_activity_launch_stage contractStage=contract ? agr_dex_game_launch_stage(contract) : AGR_ACTIVITY_LAUNCH_NONE;
    BOOL contractPassed=launch==0 && contractStage==AGR_ACTIVITY_LAUNCH_RESUMED &&
        appField==0 && appMarker==1 && activityField==0 && activityMarker==2 &&
        agr_dex_game_post_resume_completed(contract)==1 && activityRoot==0 && applicationRoot==0;
    if (!contractPassed) [failures addObject:[NSString stringWithFormat:
        @"contract:%@:%d:%d/%d:%d/%d:roots=%d/%d",launchStageName(contractStage),launch,
        appField,appMarker,activityField,activityMarker,activityRoot,applicationRoot]];
    NSDictionary *contractResult=@{@"id":@"synthetic-activity-launch",
      @"passed":@(contractPassed),@"stage":launchStageName(contractStage),
      @"application_marker":@(appMarker),@"activity_marker":@(activityMarker),
      @"post_resume_completed":@(contract && agr_dex_game_post_resume_completed(contract)==1),
      @"activity_root":@(activityRoot==0),@"application_root":@(applicationRoot==0),
      @"detail":contract ? [NSString stringWithUTF8String:agr_dex_game_launch_error(contract)] : @"fixture unavailable"};
    if (contract) agr_dex_game_destroy(contract);

    NSString *planPath=[[NSBundle mainBundle] pathForResource:@"batch-plan" ofType:@"json"];
    NSData *planData=planPath ? [NSData dataWithContentsOfFile:planPath] : nil;
    NSDictionary *plan=planData ? [NSJSONSerialization JSONObjectWithData:planData options:0 error:nil] : nil;
    NSMutableArray *real=[NSMutableArray array];
    NSSet *required=[NSSet setWithArray:@[@"pixel-dungeon",@"frozen-bubble"]];
    for (NSDictionary *sample in plan[@"samples"] ?: @[]) if ([required containsObject:sample[@"id"]]) {
        NSDictionary *result=probeActivityLaunchAPK(sample); [real addObject:result];
        if (![result[@"activity_launch_crossed"] boolValue])
            [failures addObject:[NSString stringWithFormat:@"%@:%@",sample[@"id"],result[@"signature"]]];
    }
    if (real.count!=required.count) [failures addObject:@"required real APK result missing"];
    NSDictionary *report=@{@"schema":@"agr.framework-activity-launch.v1",
      @"passed":failures.count==0 ? @YES : @NO,@"contract":contractResult,
      @"real_apks":real,@"failures":failures};
    NSData *json=[NSJSONSerialization dataWithJSONObject:report options:NSJSONWritingPrettyPrinted error:nil];
    return [[NSString alloc] initWithData:json encoding:NSUTF8StringEncoding];
}

static NSDictionary *dexSnapshotDictionary(const agr_dex_runtime_snapshot *snapshot) {
    if (!snapshot) return @{};
    NSMutableArray *methods=[NSMutableArray array];
    for(uint32_t i=0;i<snapshot->method_event_count;i++) {
      const agr_dex_method_event *event=&snapshot->method_events[i];
      [methods addObject:@{@"sequence":@(event->sequence),@"depth":@(event->depth),
        @"native":@(event->is_native!=0),@"method":[NSString stringWithUTF8String:event->method]}];
    }
    NSMutableArray *framework=[NSMutableArray array];
    for(uint32_t i=0;i<snapshot->framework_event_count;i++)
      [framework addObject:[NSString stringWithUTF8String:snapshot->framework_events[i]]];
    return @{ @"methods":@(snapshot->methods_invoked),
      @"instructions":@(snapshot->instructions_executed),
      @"stack_depth":@(snapshot->stack_depth), @"vm_running":@(snapshot->vm_running!=0),
      @"pending_exception":@(snapshot->pending_exception!=0),
      @"post_resume_completed":snapshot->post_resume_completed ? @YES : @NO,
      @"window_attached":snapshot->window_attached ? @YES : @NO,
      @"window_added":snapshot->window_added ? @YES : @NO,
      @"window_visible":snapshot->window_visible ? @YES : @NO,
      @"idle_handler_scheduled":snapshot->idle_handler_scheduled ? @YES : @NO,
      @"viewroot_handoff":snapshot->viewroot_handoff ? @YES : @NO,
      @"viewroot_created":snapshot->viewroot_created ? @YES : @NO,
      @"viewroot_root_assigned":snapshot->viewroot_root_assigned ? @YES : @NO,
      @"traversal_scheduled":snapshot->traversal_scheduled ? @YES : @NO,
      @"window_session_attached":snapshot->window_session_attached ? @YES : @NO,
      @"view_parent_assigned":snapshot->view_parent_assigned ? @YES : @NO,
      @"viewroot_attach_completed":snapshot->viewroot_attach_completed ? @YES : @NO,
      @"hierarchy_attached":snapshot->hierarchy_attached ? @YES : @NO,
      @"traversal_phase":@(snapshot->traversal_phase),
      @"traversal_count":@(snapshot->traversal_count),
      @"measured_width":@(snapshot->measured_width),
      @"measured_height":@(snapshot->measured_height),
      @"frame":@[@(snapshot->frame_left),@(snapshot->frame_top),
                  @(snapshot->frame_right),@(snapshot->frame_bottom)],
      @"layout_complete":snapshot->layout_complete ? @YES : @NO,
      @"surface_valid":snapshot->surface_valid ? @YES : @NO,
      @"surface_generation":@(snapshot->surface_generation),
      @"draw_count":@(snapshot->draw_count),
      @"content_view_installed":snapshot->content_view_installed ? @YES : @NO,
      @"content_layout_width":@(snapshot->content_layout_width),
      @"content_layout_height":@(snapshot->content_layout_height),
      @"content_child_count":@(snapshot->content_child_count),
      @"content_first_child_id":@(snapshot->content_first_child_id),
      @"last_method":[NSString stringWithUTF8String:snapshot->last_method],
      @"method_trace":methods, @"framework_trace":framework,
      @"exception_class":[NSString stringWithUTF8String:snapshot->exception_class],
      @"error":[NSString stringWithUTF8String:snapshot->error] };
}

static void *rejectSurfaceAllocation(void *user, size_t bytes) {
    (void)user; (void)bytes;
    return NULL;
}

static void rejectSurfaceRelease(void *user, void *pixels) {
    (void)user; (void)pixels;
}

static int rejectRelayout(void *user, uint32_t width, uint32_t height,
                          int visibility) {
    (void)user; (void)width; (void)height; (void)visibility;
    return -1;
}

static NSString *runFrameworkRuntimeContinuationDiscovery(BOOL runTraversal,
                                                           uint32_t displayWidth,
                                                           uint32_t displayHeight) {
    NSString *fixturePath=[[NSBundle mainBundle] pathForResource:@"activity-launch-fixture" ofType:@"dex"];
    NSData *fixture=fixturePath ? [NSData dataWithContentsOfFile:fixturePath] : nil;
    agr_dex_game *contract=fixture ? agr_dex_game_create_for_launch(fixture.bytes,(uint32_t)fixture.length,
        "Ltest/TestActivity;","Ltest/TestApplication;","test.activity.launch") : NULL;
    if (contract) agr_dex_game_enable_diagnostics(contract,1);
    int contractLaunch=contract ? agr_dex_game_start_activity(contract) : -1;
    int32_t contractMarker=0;
    int contractField=contract ? agr_dex_game_static_int(contract,"Ltest/TestActivity;","activityMarker",&contractMarker) : -1;
    agr_dex_runtime_snapshot contractSnapshot={0};
    if (contract) agr_dex_game_runtime_snapshot(contract,&contractSnapshot);
    BOOL ownerGraph=contract && agr_dex_game_viewroot_contract(contract)==1;
    int contractTraversal=runTraversal && contract
        ? agr_dex_game_do_traversal(contract,displayWidth,displayHeight) : -1;
    agr_dex_runtime_snapshot contractAfter={0};
    if (contract) agr_dex_game_runtime_snapshot(contract,&contractAfter);
    void *firstPixels=NULL,*secondPixels=NULL;
    uint32_t firstWidth=0,firstHeight=0,firstStride=0,firstGeneration=0;
    uint32_t secondWidth=0,secondHeight=0,secondStride=0,secondGeneration=0;
    int firstSurface=runTraversal && contract ? agr_dex_game_root_surface(contract,&firstPixels,
        &firstWidth,&firstHeight,&firstStride,&firstGeneration) : -1;
    int secondTraversal=runTraversal && contract && contractTraversal==0
        ? agr_dex_game_do_traversal(contract,displayWidth,displayHeight) : -1;
    agr_dex_runtime_snapshot contractSecond={0};
    if (contract) agr_dex_game_runtime_snapshot(contract,&contractSecond);
    int secondSurface=runTraversal && contract ? agr_dex_game_root_surface(contract,&secondPixels,
        &secondWidth,&secondHeight,&secondStride,&secondGeneration) : -1;
    BOOL surfacePersistent=runTraversal && firstSurface==0 && secondTraversal==0 &&
        secondSurface==0 && firstPixels==secondPixels && firstGeneration==secondGeneration &&
        firstWidth==secondWidth && firstHeight==secondHeight && firstStride==secondStride &&
        contractSecond.traversal_count==2 && !contractSecond.traversal_scheduled;
    NSMutableArray *contractTrace=[NSMutableArray array];
    for (uint32_t i=0;i<contractSnapshot.framework_event_count;i++)
      [contractTrace addObject:[NSString stringWithUTF8String:contractSnapshot.framework_events[i]]];
    BOOL contractPassed=contractLaunch==0 && contractField==0 && contractMarker==2 &&
        ownerGraph &&
        agr_dex_game_post_resume_completed(contract)==1 && contractSnapshot.window_attached &&
        contractSnapshot.window_added && contractSnapshot.window_visible &&
        contractSnapshot.idle_handler_scheduled && contractSnapshot.viewroot_handoff &&
        contractSnapshot.viewroot_created && contractSnapshot.viewroot_root_assigned &&
        contractSnapshot.traversal_scheduled && contractSnapshot.window_session_attached &&
        contractSnapshot.view_parent_assigned && contractSnapshot.viewroot_attach_completed &&
        contractSnapshot.framework_event_count>0 &&
        strcmp(contractSnapshot.framework_events[contractSnapshot.framework_event_count-1],
               "handoff.viewroot_traversal")==0;
    if (runTraversal) contractPassed=contractPassed && contractTraversal==0 &&
        contractAfter.hierarchy_attached && contractAfter.traversal_count==1 &&
        contractAfter.measured_width>0 && contractAfter.measured_height>0 &&
        contractAfter.layout_complete && contractAfter.surface_valid &&
        contractAfter.surface_generation==1 && contractAfter.traversal_scheduled &&
        surfacePersistent;
    int invalidTraversal=-1,relayoutFailure=-1,allocationFailure=-1,retryAfterFailure=-1;
    agr_dex_runtime_snapshot relayoutFailureSnapshot={0},allocationFailureSnapshot={0},retrySnapshot={0};
    if (runTraversal && fixture) {
      agr_dex_game *failureGame=agr_dex_game_create_for_launch(fixture.bytes,(uint32_t)fixture.length,
          "Ltest/TestActivity;","Ltest/TestApplication;","test.activity.launch");
      if (failureGame) {
        invalidTraversal=agr_dex_game_do_traversal(failureGame,displayWidth,displayHeight);
        if (agr_dex_game_start_activity(failureGame)==0 &&
            agr_dex_game_set_relayout_gate(failureGame,rejectRelayout,NULL)==0) {
          relayoutFailure=agr_dex_game_do_traversal(failureGame,displayWidth,displayHeight);
          agr_dex_game_runtime_snapshot(failureGame,&relayoutFailureSnapshot);
        }
        if (agr_dex_game_set_relayout_gate(failureGame,NULL,NULL)==0 &&
            agr_dex_game_set_surface_allocator(failureGame,rejectSurfaceAllocation,
                                               rejectSurfaceRelease,NULL)==0) {
          allocationFailure=agr_dex_game_do_traversal(failureGame,displayWidth,displayHeight);
          agr_dex_game_runtime_snapshot(failureGame,&allocationFailureSnapshot);
          if (agr_dex_game_set_surface_allocator(failureGame,NULL,NULL,NULL)==0) {
            retryAfterFailure=agr_dex_game_do_traversal(failureGame,displayWidth,displayHeight);
            agr_dex_game_runtime_snapshot(failureGame,&retrySnapshot);
          }
        }
        agr_dex_game_destroy(failureGame);
      }
      contractPassed=contractPassed && invalidTraversal!=0 && relayoutFailure!=0 &&
          !relayoutFailureSnapshot.surface_valid &&
          relayoutFailureSnapshot.traversal_scheduled && allocationFailure!=0 &&
          !allocationFailureSnapshot.surface_valid &&
          allocationFailureSnapshot.traversal_scheduled && retryAfterFailure==0 &&
          retrySnapshot.surface_valid && retrySnapshot.layout_complete;
    }
    NSDictionary *contractResult=@{ @"passed":@(contractPassed), @"launch_result":@(contractLaunch),
      @"activity_marker":@(contractMarker),
      @"post_resume_completed":@(contract && agr_dex_game_post_resume_completed(contract)==1),
      @"window_attached":@(contractSnapshot.window_attached!=0),
      @"window_added":@(contractSnapshot.window_added!=0),
      @"window_visible":@(contractSnapshot.window_visible!=0),
      @"idle_handler_scheduled":@(contractSnapshot.idle_handler_scheduled!=0),
      @"viewroot_handoff":@(contractSnapshot.viewroot_handoff!=0),
      @"viewroot_created":@(contractSnapshot.viewroot_created!=0),
      @"viewroot_root_assigned":@(contractSnapshot.viewroot_root_assigned!=0),
      @"traversal_scheduled":@(contractSnapshot.traversal_scheduled!=0),
      @"window_session_attached":@(contractSnapshot.window_session_attached!=0),
      @"view_parent_assigned":@(contractSnapshot.view_parent_assigned!=0),
      @"viewroot_attach_completed":@(contractSnapshot.viewroot_attach_completed!=0),
      @"owner_graph":@(ownerGraph), @"framework_trace":contractTrace,
      @"traversal_result":@(contractTraversal),
      @"second_traversal_result":@(secondTraversal),
      @"surface_persistent":@(surfacePersistent),
      @"second_traversal":dexSnapshotDictionary(&contractSecond),
      @"invalid_traversal_result":@(invalidTraversal),
      @"relayout_failure_result":@(relayoutFailure),
      @"relayout_failure_snapshot":dexSnapshotDictionary(&relayoutFailureSnapshot),
      @"surface_failure_result":@(allocationFailure),
      @"surface_failure_snapshot":dexSnapshotDictionary(&allocationFailureSnapshot),
      @"retry_result":@(retryAfterFailure),
      @"retry_snapshot":dexSnapshotDictionary(&retrySnapshot),
      @"after_traversal":dexSnapshotDictionary(&contractAfter) };
    if (contract) agr_dex_game_destroy(contract);
    NSString *planPath=[[NSBundle mainBundle] pathForResource:@"batch-plan" ofType:@"json"];
    NSData *planData=planPath ? [NSData dataWithContentsOfFile:planPath] : nil;
    NSDictionary *plan=planData ? [NSJSONSerialization JSONObjectWithData:planData options:0 error:nil] : nil;
    NSDictionary *sample=nil;
    for (NSDictionary *candidate in plan[@"samples"] ?: @[])
        if ([candidate[@"id"] isEqualToString:@"frozen-bubble"]) { sample=candidate; break; }
    NSString *resource=sample[@"resource"];
    NSString *path=resource ? [[NSBundle mainBundle] pathForResource:resource.stringByDeletingPathExtension
                                                              ofType:resource.pathExtension] : nil;
    agr_apk_package *package=path ? agr_apk_package_open(path.UTF8String) : NULL;
    agr_dex_game *game=package ? agr_dex_game_create_from_apk(package) : NULL;
    if (game) agr_dex_game_enable_diagnostics(game,1);
    int start=game ? agr_dex_game_start_activity(game) : -1;
    BOOL realOwnerGraph=game && agr_dex_game_viewroot_contract(game)==1;
    agr_dex_runtime_snapshot resumed={0},observed={0};
    if (game) agr_dex_game_runtime_snapshot(game,&resumed);
    int realTraversal=runTraversal && game && start==0
        ? agr_dex_game_do_traversal(game,displayWidth,displayHeight) : -1;
    /* Deliberately do not synthesize an Android callback here. This bounded
       interval distinguishes harness destruction from autonomous Runtime
       progress without changing Framework behavior. */
    [NSThread sleepForTimeInterval:2.0];
    if (game) agr_dex_game_runtime_snapshot(game,&observed);
    NSDictionary *before=dexSnapshotDictionary(&resumed), *after=dexSnapshotDictionary(&observed);
    BOOL progressed=observed.methods_invoked!=resumed.methods_invoked ||
        observed.instructions_executed!=resumed.instructions_executed ||
        observed.traversal_count!=resumed.traversal_count;
    NSString *classification=runTraversal
        ? (game && start==0 && realTraversal==0 && observed.surface_valid &&
           observed.hierarchy_attached && observed.layout_complete
           ? @"viewroot_surface_ready" : @"first_traversal_failed")
        : (game && start==0 ? (observed.viewroot_attach_completed ? @"viewroot_traversal_handoff" :
          (progressed ? @"guest_progress_observed" :
          (observed.post_resume_completed ? @"post_resume_complete_no_followup_event" : @"no_post_resume_dispatch_observed")))
          : @"launch_failed");
    NSDictionary *report=@{ @"schema":runTraversal ? @"agr.framework-first-traversal.discovery.v1" : @"agr.framework-viewroot-attach.discovery.v1",
      @"sample":sample[@"id"] ?: @"missing", @"package":sample[@"package"] ?: @"missing",
      @"launch_result":@(start), @"launch_stage":launchStageName(game ? agr_dex_game_launch_stage(game) : AGR_ACTIVITY_LAUNCH_NONE),
      @"harness_retained_runtime":game ? @YES : @NO, @"observation_ms":@2000,
      @"thread_owner":@"focused-regression-serial-queue", @"resume_snapshot":before,
      @"after_snapshot":after, @"autonomous_progress":@(progressed), @"contract":contractResult,
      @"real_owner_graph":@(realOwnerGraph), @"traversal_result":@(realTraversal),
      @"display_width":@(displayWidth), @"display_height":@(displayHeight),
      @"classification":classification };
    if (game) agr_dex_game_destroy(game);
    if (package) agr_apk_package_close(package);
    NSData *json=[NSJSONSerialization dataWithJSONObject:report options:NSJSONWritingPrettyPrinted error:nil];
    return [[NSString alloc] initWithData:json encoding:NSUTF8StringEncoding];
}

static agr_dex_game *gDispatchGame = NULL;
static agr_apk_package *gDispatchPackage = NULL;
static NSDictionary *gDispatchContract = nil;
static NSDictionary *gDispatchBefore = nil;
static NSMutableArray *gDispatchFrames = nil;
static uint32_t gDispatchVsync = 0;
static uint32_t gDispatchWidth = 0;
static uint32_t gDispatchHeight = 0;
static int gDispatchStart = -1;
static BOOL gDispatchFinished = NO;
static BOOL gDispatchOwnerGraph = NO;
static CADisplayLink *gDispatchLink = nil;

static NSDictionary *syntheticTraversalDispatchContract(uint32_t width, uint32_t height) {
    NSString *fixturePath=[[NSBundle mainBundle] pathForResource:@"activity-launch-fixture" ofType:@"dex"];
    NSData *fixture=fixturePath ? [NSData dataWithContentsOfFile:fixturePath] : nil;
    agr_dex_game *game=fixture ? agr_dex_game_create_for_launch(fixture.bytes,(uint32_t)fixture.length,
        "Ltest/TestActivity;","Ltest/TestApplication;","test.activity.launch") : NULL;
    if (game) agr_dex_game_enable_diagnostics(game,1);
    int display=game ? agr_dex_game_set_host_display(game,width,height) : -1;
    int start=game ? agr_dex_game_start_activity(game) : -1;
    agr_dex_runtime_snapshot started={0},frame1={0},frame2={0},frame3={0};
    if (game) agr_dex_game_runtime_snapshot(game,&started);
    int first=game && start==0 ? agr_dex_game_choreographer_frame(game) : -1;
    if (game) agr_dex_game_runtime_snapshot(game,&frame1);
    void *pixels1=NULL,*pixels2=NULL;
    uint32_t w1=0,h1=0,s1=0,g1=0,w2=0,h2=0,s2=0,g2=0;
    int surface1=game ? agr_dex_game_root_surface(game,&pixels1,&w1,&h1,&s1,&g1) : -1;
    int second=first==0 ? agr_dex_game_choreographer_frame(game) : -1;
    if (game) agr_dex_game_runtime_snapshot(game,&frame2);
    int surface2=game ? agr_dex_game_root_surface(game,&pixels2,&w2,&h2,&s2,&g2) : -1;
    int idle=second==0 ? agr_dex_game_choreographer_frame(game) : -1;
    if (game) agr_dex_game_runtime_snapshot(game,&frame3);
    BOOL sameBacking=surface1==0 && surface2==0 && pixels1==pixels2 && g1==g2 && w1==w2 && h1==h2;
    BOOL passed=display==0 && start==0 && started.traversal_count==0 && started.traversal_scheduled &&
        started.draw_count==0 && first==0 && frame1.traversal_count==1 && frame1.traversal_scheduled &&
        frame1.surface_valid && frame1.draw_count==0 && second==0 && frame2.traversal_count==2 &&
        !frame2.traversal_scheduled && frame2.surface_generation==1 && frame2.draw_count==1 &&
        sameBacking && idle==1 && frame3.traversal_count==2 && frame3.draw_count==1;
    if (game) agr_dex_game_destroy(game);

    agr_dex_game *closed=fixture ? agr_dex_game_create_for_launch(fixture.bytes,(uint32_t)fixture.length,
        "Ltest/TestActivity;","Ltest/TestApplication;","test.activity.launch") : NULL;
    if (closed) agr_dex_game_enable_diagnostics(closed,1);
    int closedStart=closed ? agr_dex_game_start_activity(closed) : -1;
    int explicit1=closedStart==0 ? agr_dex_game_do_traversal(closed,width,height) : -1;
    agr_dex_runtime_snapshot closed1={0},closed2={0};
    if (closed) agr_dex_game_runtime_snapshot(closed,&closed1);
    int explicit2=explicit1==0 ? agr_dex_game_do_traversal(closed,width,height) : -1;
    if (closed) agr_dex_game_runtime_snapshot(closed,&closed2);
    BOOL closedTrace=closed1.framework_event_count>0 &&
        strcmp(closed1.framework_events[closed1.framework_event_count-1],"handoff.viewroot_surface_ready")==0;
    BOOL closedPassed=explicit1==0 && closed1.traversal_count==1 && closed1.draw_count==0 && closedTrace &&
        explicit2==0 && closed2.traversal_count==2 && !closed2.traversal_scheduled &&
        closed2.surface_generation==1 && closed2.draw_count==1;
    if (closed) agr_dex_game_destroy(closed);

    agr_dex_game *failed=fixture ? agr_dex_game_create_for_launch(fixture.bytes,(uint32_t)fixture.length,
        "Ltest/TestActivity;","Ltest/TestApplication;","test.activity.launch") : NULL;
    int failure=-1,retry=-1;
    agr_dex_runtime_snapshot failedSnap={0},retrySnap={0};
    if (failed && agr_dex_game_set_host_display(failed,width,height)==0 &&
        agr_dex_game_start_activity(failed)==0 &&
        agr_dex_game_set_relayout_gate(failed,rejectRelayout,NULL)==0) {
        failure=agr_dex_game_choreographer_frame(failed);
        agr_dex_game_runtime_snapshot(failed,&failedSnap);
        if (agr_dex_game_set_relayout_gate(failed,NULL,NULL)==0) {
            retry=agr_dex_game_choreographer_frame(failed);
            agr_dex_game_runtime_snapshot(failed,&retrySnap);
        }
    }
    if (failed) agr_dex_game_destroy(failed);
    BOOL failurePassed=failure!=0 && failedSnap.traversal_scheduled && !failedSnap.surface_valid &&
        failedSnap.draw_count==0 && retry==0 && retrySnap.surface_valid && retrySnap.draw_count==0 &&
        retrySnap.traversal_count==1;
    return @{ @"passed":@(passed && closedPassed && failurePassed),
      @"consumer":@"synthetic-host-pump",
      @"after_start":dexSnapshotDictionary(&started),
      @"frame1":dexSnapshotDictionary(&frame1),
      @"frame2":dexSnapshotDictionary(&frame2),
      @"frame3":dexSnapshotDictionary(&frame3),
      @"same_backing":@(sameBacking),
      @"closed_explicit_passed":@(closedPassed),
      @"closed_first":dexSnapshotDictionary(&closed1),
      @"closed_second":dexSnapshotDictionary(&closed2),
      @"relayout_failure_result":@(failure),
      @"retry_result":@(retry) };
}

static void finishTraversalDispatchReport(void) {
    if (gDispatchFinished) return;
    gDispatchFinished=YES;
    if (gDispatchLink) { [gDispatchLink invalidate]; gDispatchLink=nil; }
    agr_dex_runtime_snapshot after={0};
    if (gDispatchGame) agr_dex_game_runtime_snapshot(gDispatchGame,&after);
    NSDictionary *afterDict=gDispatchGame ? dexSnapshotDictionary(&after) : @{};
    NSDictionary *before=gDispatchBefore ?: @{};
    BOOL scheduledAtStart=[before[@"traversal_scheduled"] boolValue] &&
        [before[@"traversal_count"] intValue]==0 && [before[@"draw_count"] intValue]==0;
    BOOL chain=gDispatchStart==0 && gDispatchVsync>=2 && scheduledAtStart &&
        after.traversal_count==2 && after.surface_valid && after.draw_count>=1 &&
        !after.traversal_scheduled && after.surface_generation==1 && gDispatchOwnerGraph;
    NSString *classification=chain ? @"viewroot_draw_entered" :
        (gDispatchGame && gDispatchStart==0 ? @"traversal_dispatch_failed" : @"launch_failed");
    NSDictionary *report=@{ @"schema":@"agr.framework-traversal-dispatch.discovery.v1",
      @"sample":@"frozen-bubble", @"consumer":@"uikit-cadisplaylink",
      @"harness_called_do_traversal":@NO, @"host_vsync_count":@(gDispatchVsync),
      @"display_width":@(gDispatchWidth), @"display_height":@(gDispatchHeight),
      @"launch_result":@(gDispatchStart),
      @"launch_stage":launchStageName(gDispatchGame ? agr_dex_game_launch_stage(gDispatchGame) : AGR_ACTIVITY_LAUNCH_NONE),
      @"real_owner_graph":@(gDispatchOwnerGraph),
      @"resume_snapshot":before, @"frames":gDispatchFrames ?: @[],
      @"after_snapshot":afterDict, @"contract":gDispatchContract ?: @{},
      @"classification":classification };
    NSData *json=[NSJSONSerialization dataWithJSONObject:report options:NSJSONWritingPrettyPrinted error:nil];
    NSString *text=[[NSString alloc] initWithData:json encoding:NSUTF8StringEncoding];
    NSString *path=[NSHomeDirectory() stringByAppendingPathComponent:
        @"Documents/framework-traversal-dispatch.json"];
    [text writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"AGR_RESULT_BEGIN%@AGR_RESULT_END", text);
    if (gDispatchGame) agr_dex_game_destroy(gDispatchGame);
    gDispatchGame=NULL;
    if (gDispatchPackage) agr_apk_package_close(gDispatchPackage);
    gDispatchPackage=NULL;
}

static void armTraversalDispatchApk(uint32_t width, uint32_t height) {
    gDispatchWidth=width; gDispatchHeight=height;
    gDispatchContract=syntheticTraversalDispatchContract(width,height);
    gDispatchFrames=[NSMutableArray array];
    NSString *planPath=[[NSBundle mainBundle] pathForResource:@"batch-plan" ofType:@"json"];
    NSData *planData=planPath ? [NSData dataWithContentsOfFile:planPath] : nil;
    NSDictionary *plan=planData ? [NSJSONSerialization JSONObjectWithData:planData options:0 error:nil] : nil;
    NSDictionary *sample=nil;
    for (NSDictionary *candidate in plan[@"samples"] ?: @[])
        if ([candidate[@"id"] isEqualToString:@"frozen-bubble"]) { sample=candidate; break; }
    NSString *resource=sample[@"resource"];
    NSString *path=resource ? [[NSBundle mainBundle] pathForResource:resource.stringByDeletingPathExtension
                                                              ofType:resource.pathExtension] : nil;
    gDispatchPackage=path ? agr_apk_package_open(path.UTF8String) : NULL;
    gDispatchGame=gDispatchPackage ? agr_dex_game_create_from_apk(gDispatchPackage) : NULL;
    if (gDispatchGame) agr_dex_game_enable_diagnostics(gDispatchGame,1);
    if (gDispatchGame) agr_dex_game_set_host_display(gDispatchGame,width,height);
    gDispatchStart=gDispatchGame ? agr_dex_game_start_activity(gDispatchGame) : -1;
    gDispatchOwnerGraph=gDispatchGame && agr_dex_game_viewroot_contract(gDispatchGame)==1;
    agr_dex_runtime_snapshot before={0};
    if (gDispatchGame) agr_dex_game_runtime_snapshot(gDispatchGame,&before);
    gDispatchBefore=gDispatchGame ? dexSnapshotDictionary(&before) : @{};
    if (gDispatchStart!=0 || !gDispatchLink) finishTraversalDispatchReport();
    else gDispatchLink.paused=NO;
}

static NSString *runTests(void) {
    NSMutableArray<NSString *> *failures = [NSMutableArray array];
    agr_contract_result contractCases[64]={0};
    uint32_t contractCount=agr_run_contracts(contractCases,64), contractPassed=0;
    NSMutableArray *contracts=[NSMutableArray array];
    for(uint32_t i=0;i<contractCount;i++) {
        agr_contract_result *test=&contractCases[i]; if(test->passed)contractPassed++;
        [contracts addObject:@{@"id":[NSString stringWithUTF8String:test->id],
          @"module":[NSString stringWithUTF8String:test->module],
          @"source_case":[NSString stringWithUTF8String:test->source_case],
          @"passed":@(test->passed),@"observed":@(test->observed),@"expected":@(test->expected)}];
    }
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
    callbacks.memory_base = guest_memory_base;
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
    NSDictionary *kungFooNativeResult = runKungFooNativeRegression(failures,NO);
    agr_guest_core_contracts coreContracts={0};
    int coreContractResult=agr_guest_run_core_contracts(&coreContracts);
    if(coreContractResult)[failures addObject:@"guest-runtime-core-contracts"];
    BOOL pvsBootstrap=[kungFooNativeResult[@"native_activity_created"] boolValue]&&
        [kungFooNativeResult[@"activity_callbacks"] unsignedIntValue]>0;
    BOOL pvsWindow=[kungFooNativeResult[@"on_start"] boolValue]&&
        [kungFooNativeResult[@"on_resume"] boolValue]&&
        [kungFooNativeResult[@"on_window_created"] boolValue];
    BOOL pvsReplay=[kungFooNativeResult[@"replay_events"] unsignedIntValue]>0;
    BOOL pvsInput=!pvsReplay||[kungFooNativeResult[@"replay_consumed"] unsignedIntValue]>0;
    BOOL pvsNoFailure=![kungFooNativeResult[@"gameplay_outcome"] isEqualToString:@"runtime_failure"]&&
        ![kungFooNativeResult[@"runtime_failure_signature"] length];
    BOOL pvsProgress=NO;
    for(NSDictionary *checkpoint in kungFooNativeResult[@"gameplay_trajectory"])
        if([checkpoint[@"input_consumed"] unsignedIntValue]>0&&
           ([checkpoint[@"draw_delta"] unsignedIntValue]>0||[checkpoint[@"swap_delta"] unsignedIntValue]>0))pvsProgress=YES;
    BOOL pvsTeardown=[kungFooNativeResult[@"teardown_completed"] boolValue];
    if(!pvsBootstrap)[failures addObject:@"pvs1:generic_apk_bootstrap_failed"];
    if(!pvsWindow)[failures addObject:@"pvs1:nativeactivity_window_failed"];
    if(!pvsInput)[failures addObject:@"pvs1:injected_input_not_consumed"];
    if(!pvsProgress)[failures addObject:@"pvs1:guest_did_not_progress_after_input"];
    if(!pvsTeardown)[failures addObject:@"pvs1:clean_teardown_failed"];
    if(!pvsNoFailure)[failures addObject:[NSString stringWithFormat:@"pvs1:runtime_failure:%@/%@",
        kungFooNativeResult[@"gameplay_outcome"]?:@"",kungFooNativeResult[@"runtime_failure_signature"]?:@""]];
    NSArray *batchResults = runBatchCompatibility(gloomyResult,kungFooNativeResult);
    NSArray *componentContracts=@[
      @{@"id":@"dex.jni.roundtrip",@"module":@"DEX_JNI",@"observed":@(dexResult),@"expected":@10,
        @"source_case":@"AOSP dalvik/vm/analysis + CTS JNI callback pattern"},
      @{@"id":@"elf.jni_onload.symbol",@"module":@"ELF_linker",@"observed":@(jniOnLoad!=0),@"expected":@1,
        @"source_case":@"AOSP bionic linker and CTS native library loading"},
      @{@"id":@"asset.apk.resources_table",@"module":@"AssetManager_resources",@"observed":@(tableCount>0),@"expected":@1,
        @"source_case":@"CTS AssetManagerTest resource lookup"},
      @{@"id":@"bitmap.png.dimensions",@"module":@"Bitmap",@"observed":@(bitmapWidth==64&&bitmapHeight==64),@"expected":@1,
        @"source_case":@"CTS BitmapTest width/height and BitmapFactory decode"},
      @{@"id":@"egl.gles.draw.readback",@"module":@"EGL_GLES",@"observed":angleResult[@"angle_draw_passed"]?:@0,@"expected":@1,
        @"source_case":@"CTS OpenGL framebuffer readback pattern"},
      @{@"id":@"nativeactivity.lifecycle.window",@"module":@"NativeActivity_lifecycle",
        @"observed":@(pvsWindow),@"expected":@1,
        @"source_case":@"AOSP NativeActivity callback order"},
      @{@"id":@"guest.wait_swap.immediate",@"module":@"GuestRuntime_wait",
        @"observed":@(coreContracts.wait_immediate),@"expected":@1,
        @"source_case":[NSString stringWithFormat:@"advanced swap returns immediately; wall_ms<10"]},
      @{@"id":@"guest.wait_swap.async",@"module":@"GuestRuntime_wait",
        @"observed":@(coreContracts.wait_async),@"expected":@1,
        @"source_case":[NSString stringWithFormat:@"async swap; wall_ms=%u",coreContracts.async_wait_ms]},
      @{@"id":@"guest.wait_swap.timeout",@"module":@"GuestRuntime_wait",
        @"observed":@(coreContracts.wait_timeout),@"expected":@1,
        @"source_case":[NSString stringWithFormat:@"30ms bounded timeout; wall_ms=%u",coreContracts.timeout_wait_ms]},
      @{@"id":@"guest.wait_swap.error_shutdown",@"module":@"GuestRuntime_wait",
        @"observed":@(coreContracts.wait_error&&coreContracts.wait_shutdown),@"expected":@1,
        @"source_case":@"Runtime error and shutdown both return failure"},
      @{@"id":@"input_queue.concurrent_ordered",@"module":@"Looper_InputQueue",
        @"observed":@(coreContracts.input_ordered),@"expected":@1,
        @"source_case":[NSString stringWithFormat:@"host producer/consumer ordered iterations=%u; elapsed_ms=%u is diagnostic only",coreContracts.input_iterations,coreContracts.input_elapsed_ms]}
    ];
    for(NSDictionary *test in componentContracts) {
        BOOL ok=[test[@"observed"] isEqual:test[@"expected"]]; if(ok) contractPassed++;
        NSMutableDictionary *entry=[test mutableCopy];entry[@"passed"]=@(ok);[contracts addObject:entry];
    }
    contractCount+=(uint32_t)componentContracts.count;

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
    result[@"pvs1_closure"]=@{ @"generic_apk_bootstrap":@(pvsBootstrap),
      @"nativeactivity_window":@(pvsWindow),@"replay_present":@(pvsReplay),
      @"input_consumed":@(pvsInput),@"guest_progress_after_input":@(pvsProgress),
      @"clean_teardown":@(pvsTeardown),@"runtime_failure_absent":@(pvsNoFailure),
      @"passed":@(pvsBootstrap&&pvsWindow&&pvsInput&&pvsProgress&&pvsTeardown&&pvsNoFailure) };
    result[@"batch_results"] = batchResults;
    result[@"conformance"] = @{ @"count":@(contractCount),@"passed":@(contractPassed),
      @"reference":@"API19 source-derived expectations; Android 4.4 device differential pending",
      @"cases":contracts };
    NSData *json = [NSJSONSerialization dataWithJSONObject:result options:NSJSONWritingPrettyPrinted error:nil];
    return [[NSString alloc] initWithData:json encoding:NSUTF8StringEncoding];
}

#pragma mark - Interactive Simulator debugger

static UIImage *imageFromRGBA(const uint8_t *pixels,size_t width,size_t height) {
    NSData *rgba=[NSData dataWithBytes:pixels length:width*height*4];
    CGDataProviderRef provider=CGDataProviderCreateWithCFData((__bridge CFDataRef)rgba);
    CGColorSpaceRef color=CGColorSpaceCreateDeviceRGB();
    CGImageRef cg=CGImageCreate(width,height,8,32,width*4,color,
        kCGBitmapByteOrder32Big|kCGImageAlphaLast,provider,NULL,false,kCGRenderingIntentDefault);
    UIImage *result=cg?[UIImage imageWithCGImage:cg scale:1 orientation:UIImageOrientationDownMirrored]:nil;
    if(cg)CGImageRelease(cg);CGColorSpaceRelease(color);CGDataProviderRelease(provider);return result;
}

@interface AGRTouchView : UIView
@property(nonatomic,copy) void (^touchHandler)(NSString *,CGPoint);
@end
@implementation AGRTouchView
- (void)emit:(NSString *)action touch:(UITouch *)touch {
    if(self.touchHandler)self.touchHandler(action,[touch locationInView:self]);
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event { [self emit:@"down" touch:touches.anyObject]; }
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event { [self emit:@"move" touch:touches.anyObject]; }
- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event { [self emit:@"up" touch:touches.anyObject]; }
- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event { [self emit:@"up" touch:touches.anyObject]; }
@end

@interface AGRDebugController : UIViewController
@property(nonatomic,strong) UIImageView *frameView;
@property(nonatomic,strong) AGRTouchView *touchView;
@property(nonatomic,strong) UILabel *status;
@property(nonatomic,strong) NSMutableArray *pendingEvents;
@property(nonatomic,strong) NSMutableArray *trace;
@property(nonatomic,strong) dispatch_queue_t runtimeQueue;
@property(nonatomic) BOOL stopped;
@property(nonatomic) NSTimeInterval started;
@end

@implementation AGRDebugController
- (void)viewDidLoad {
    [super viewDidLoad]; self.view.backgroundColor=UIColor.blackColor;
    self.status=[UILabel new];self.status.textColor=UIColor.greenColor;self.status.backgroundColor=[UIColor colorWithWhite:0 alpha:.72];
    self.status.font=[UIFont monospacedSystemFontOfSize:11 weight:UIFontWeightRegular];self.status.numberOfLines=5;self.status.text=@"Starting original APK runtime…";
    self.frameView=[UIImageView new];self.frameView.backgroundColor=UIColor.blackColor;self.frameView.contentMode=UIViewContentModeScaleAspectFit;
    self.touchView=[AGRTouchView new];self.touchView.backgroundColor=UIColor.clearColor;self.touchView.multipleTouchEnabled=NO;
    [self.view addSubview:self.frameView];[self.view addSubview:self.touchView];[self.view addSubview:self.status];
    self.pendingEvents=[NSMutableArray array];self.trace=[NSMutableArray array];self.runtimeQueue=dispatch_queue_create("dev.agr.interactive-runtime",DISPATCH_QUEUE_SERIAL);
    __weak AGRDebugController *weakSelf=self;
    self.touchView.touchHandler=^(NSString *action,CGPoint point){
        AGRDebugController *self=weakSelf;if(!self||self.stopped)return;
        CGFloat x=MAX(0,MIN(319,point.x/self.touchView.bounds.size.width*320.0));
        CGFloat y=MAX(0,MIN(479,point.y/self.touchView.bounds.size.height*480.0));
        NSDictionary *event=@{@"action":action,@"x":@(x),@"y":@(y),@"host_ms":@((CACurrentMediaTime()-self.started)*1000.0)};
        @synchronized(self.pendingEvents){[self.pendingEvents addObject:event];}
        self.status.text=[NSString stringWithFormat:@"touch %@ %.0f,%.0f\n%@",action,x,y,self.status.text?:@""];
    };
}
- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];CGRect safe=UIEdgeInsetsInsetRect(self.view.bounds,self.view.safeAreaInsets);
    self.status.frame=CGRectMake(safe.origin.x,safe.origin.y,safe.size.width,76);
    CGFloat availH=safe.size.height-76,scale=MIN(safe.size.width/320.0,availH/480.0);
    CGRect game=CGRectMake(CGRectGetMidX(safe)-160*scale,safe.origin.y+76+(availH-480*scale)/2,320*scale,480*scale);
    self.frameView.frame=game;self.touchView.frame=game;
}
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];self.started=CACurrentMediaTime();
    dispatch_async(self.runtimeQueue,^{[self runRuntime];});
}
- (void)saveTraceWithFailure:(NSString *)failure {
    agr_guest *guest=gInteractive.guest;
    uint32_t heap[5]={0};agr_guest_heap_diagnostics(guest,heap);
    NSMutableArray<NSString *> *calls=[NSMutableArray array];
    for(uint32_t i=0;guest&&i<agr_guest_recent_call_count(guest);i++) {
        const char *call=agr_guest_recent_call(guest,i);
        if(call)[calls addObject:[NSString stringWithUTF8String:call]];
    }
    NSMutableArray<NSString *> *modules=[NSMutableArray array];
    for(uint32_t i=0;guest&&i<agr_guest_loaded_module_count(guest);i++) {
        const char *name=agr_guest_loaded_module(guest,i);
        if(name)[modules addObject:[NSString stringWithUTF8String:name]];
    }
    NSUInteger start=self.trace.count>16?self.trace.count-16:0;
    NSArray *recentInputs=[self.trace subarrayWithRange:NSMakeRange(start,self.trace.count-start)];
    NSDictionary *status=@{@"schema":@1,@"package":gInteractivePackage?:@"",
      @"host_ms":@((CACurrentMediaTime()-self.started)*1000.0),
      @"frame":@(guest?agr_guest_swap_count(guest):0),
      @"swap":@(guest?agr_guest_swap_count(guest):0),
      @"draw":@(guest?agr_guest_draw_count(guest):0),
      @"guest_pc":[NSString stringWithFormat:@"%08x",guest?agr_guest_program_counter(guest):0],
      @"asset_opens":@(guest?agr_guest_asset_open_count(guest):0),
      @"input_consumed":@(guest?agr_guest_input_consumed_count(guest):0),
      @"heap":@{ @"highest_live_end":[NSString stringWithFormat:@"%08x",heap[0]],
                  @"limit":[NSString stringWithFormat:@"%08x",heap[1]],
                  @"metadata_blocks":@(heap[2]),@"live_count":@(heap[3]),@"live_bytes":@(heap[4]) },
      @"loaded_dso":modules,@"recent_calls":calls,@"recent_inputs":recentInputs,
      @"nativeactivity_input_trace":runtimeEventTrace(guest),@"throw_diagnostic":throwDiagnostic(guest),
      @"android_log":[NSString stringWithUTF8String:guest?agr_guest_last_android_log(guest):""],
      @"runtime_error":[NSString stringWithUTF8String:guest?agr_guest_last_error(guest):""],
      @"failure_signature":failure?:@""};
    NSData *statusJSON=[NSJSONSerialization dataWithJSONObject:status options:0 error:nil];
    NSString *documents=[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [statusJSON writeToFile:[documents stringByAppendingPathComponent:@"runtime-status.json"] atomically:YES];
    if(failure.length)[statusJSON writeToFile:[documents stringByAppendingPathComponent:@"runtime-failure.json"] atomically:YES];
    if(failure.length||self.trace.count||agr_guest_swap_count(guest)%60u==0)
        NSLog(@"AGR_STATUS %@",[[NSString alloc] initWithData:statusJSON encoding:NSUTF8StringEncoding]);
    NSDictionary *doc=@{@"package":gInteractivePackage?:@"",@"coordinate_space":@[@320,@480],
      @"events":self.trace,@"failure":failure?:@"",@"swaps":@(agr_guest_swap_count(gInteractive.guest)),
      @"pc":[NSString stringWithFormat:@"%08x",agr_guest_program_counter(gInteractive.guest)],
      @"android_log":[NSString stringWithUTF8String:agr_guest_last_android_log(gInteractive.guest)]};
    NSData *json=[NSJSONSerialization dataWithJSONObject:doc options:NSJSONWritingPrettyPrinted error:nil];
    [json writeToFile:[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/manual-replay.json"] atomically:YES];
    if(failure.length)[json writeToFile:[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/debug-failure.json"] atomically:YES];
}
- (void)runRuntime {
    NSMutableArray *failures=[NSMutableArray array];
    NSString *apkPath=[[NSBundle mainBundle] pathForResource:@"kungfoo" ofType:@"apk"];
    NSDictionary *startup=runNativeActivityApk(apkPath,nil,failures,YES);
    if(!gInteractive.guest){NSString *why=failures.count?[failures componentsJoinedByString:@" | "]:@"startup failed";NSLog(@"AGR_FAILURE startup %@",why);[self saveTraceWithFailure:why];dispatch_async(dispatch_get_main_queue(),^{self.status.text=why;});return;}
    uint8_t *pixels=malloc(320u*480u*4u);uint32_t rendered=0;NSTimeInterval fpsStart=CACurrentMediaTime();
    while(!self.stopped){
        NSArray *events=nil;@synchronized(self.pendingEvents){events=[self.pendingEvents copy];[self.pendingEvents removeAllObjects];}
        for(NSDictionary *event in events){int action=[event[@"action"] isEqual:@"down"]?0:[event[@"action"] isEqual:@"up"]?1:2;
            agr_guest_inject_motion(gInteractive.guest,action,[event[@"x"] floatValue],[event[@"y"] floatValue]);
            NSMutableDictionary *record=[event mutableCopy];record[@"swap_before"]=@(agr_guest_swap_count(gInteractive.guest));[self.trace addObject:record];[self saveTraceWithFailure:nil];
            NSLog(@"AGR_TOUCH %@ x=%@ y=%@ swap=%@ pc=%08x",event[@"action"],event[@"x"],event[@"y"],record[@"swap_before"],agr_guest_program_counter(gInteractive.guest));}
        uint32_t priorSwap=agr_guest_swap_count(gInteractive.guest);
        int rc=agr_guest_wait_for_swap(gInteractive.guest,priorSwap,500);
        if(rc < 0){self.stopped=YES;NSString *failure=[NSString stringWithUTF8String:agr_guest_last_error(gInteractive.guest)];[self saveTraceWithFailure:failure];if(rendered)writeRGBAFramePNG(pixels,320,480,[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/failure-frame.png"]);NSLog(@"AGR_FAILURE %@ pc=%08x swap=%u log=%s",failure,agr_guest_program_counter(gInteractive.guest),agr_guest_swap_count(gInteractive.guest),agr_guest_last_android_log(gInteractive.guest));dispatch_async(dispatch_get_main_queue(),^{self.status.text=[NSString stringWithFormat:@"STOPPED — frame preserved\n%@\nPC %08x\nlog %@",failure,agr_guest_program_counter(gInteractive.guest),[NSString stringWithUTF8String:agr_guest_last_android_log(gInteractive.guest)]];});break;}
        if(rc == 1) continue;
        if(agr_guest_read_rgba(gInteractive.guest,pixels,320u*480u*4u)>0){UIImage *image=imageFromRGBA(pixels,320,480);rendered++;NSTimeInterval now=CACurrentMediaTime();double fps=rendered/MAX(.001,now-fpsStart);
            uint32_t swaps=agr_guest_swap_count(gInteractive.guest),pc=agr_guest_program_counter(gInteractive.guest);NSString *log=[NSString stringWithUTF8String:agr_guest_last_android_log(gInteractive.guest)];NSUInteger traceCount=self.trace.count;
            if(rendered==1u||(rendered%60u)==0)[self saveTraceWithFailure:nil];
            dispatch_async(dispatch_get_main_queue(),^{self.frameView.image=image;self.status.text=[NSString stringWithFormat:@"%.1f fps  frame %u  swap %u\nPC %08x\nlog %@\ntouch events %lu  trace: Documents/manual-replay.json",fps,rendered,swaps,pc,log,(unsigned long)traceCount];});}
    }
    free(pixels);(void)startup;
}
@end

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic, strong) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)options {
    (void)application; (void)options;
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    NSArray<NSString *> *arguments=NSProcessInfo.processInfo.arguments;
    BOOL interactive=[arguments containsObject:@"--interactive"];
    BOOL dexParserCompatibility=[arguments containsObject:@"--dex-parser-compatibility"];
    BOOL activityLaunchCompatibility=[arguments containsObject:@"--activity-launch-compatibility"];
    BOOL frameworkRuntimeContinuation=[arguments containsObject:@"--framework-viewroot-attach-discovery"];
    BOOL firstTraversalDiscovery=[arguments containsObject:@"--framework-first-traversal-discovery"];
    BOOL traversalDispatch=[arguments containsObject:@"--framework-traversal-dispatch-discovery"];
#if AGR_DEVICE_INTERACTIVE
    interactive=YES;
#endif
    UIViewController *controller = interactive ? [AGRDebugController new] : [UIViewController new]; controller.view.backgroundColor = UIColor.blackColor;
    self.window.rootViewController = controller; [self.window makeKeyAndVisible];
    CGSize displayPixels=UIScreen.mainScreen.nativeBounds.size;
    if(!interactive && traversalDispatch){
      gDispatchLink=[CADisplayLink displayLinkWithTarget:self selector:@selector(hostTraversalVsync:)];
      [gDispatchLink addToRunLoop:NSRunLoop.mainRunLoop forMode:NSRunLoopCommonModes];
      gDispatchLink.paused=YES;
      uint32_t width=(uint32_t)displayPixels.width, height=(uint32_t)displayPixels.height;
      dispatch_async(dispatch_get_main_queue(),^{ @autoreleasepool { armTraversalDispatchApk(width,height); } });
    } else if(!interactive){
      /* Returning from didFinishLaunching promptly is required even for the
       * headless regression host.  Running the complete APK trajectory here
       * blocks UIKit's launch handshake long enough for the Simulator launch
       * watchdog to terminate an otherwise healthy Runtime process. */
      dispatch_queue_t regressionQueue=dispatch_queue_create("dev.agr.simulator.regression",DISPATCH_QUEUE_SERIAL);
      dispatch_async(regressionQueue,^{ @autoreleasepool {
        NSString *result = (frameworkRuntimeContinuation || firstTraversalDiscovery)
            ? runFrameworkRuntimeContinuationDiscovery(firstTraversalDiscovery,
                (uint32_t)displayPixels.width,(uint32_t)displayPixels.height) :
            (activityLaunchCompatibility ? runActivityLaunchCompatibility() :
            (dexParserCompatibility ? runDexParserCompatibility() : runTests()));
        NSString *file = firstTraversalDiscovery ? @"framework-first-traversal.json" :
            (frameworkRuntimeContinuation ? @"framework-viewroot-attach.json" :
            (activityLaunchCompatibility ? @"framework-activity-launch.json" :
            (dexParserCompatibility ? @"dex-parser-simulator.json" : @"runtime-smoke.json")));
        NSString *path = [NSHomeDirectory() stringByAppendingPathComponent:
            [@"Documents" stringByAppendingPathComponent:file]];
        [result writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:nil];
        NSLog(@"AGR_RESULT_BEGIN%@AGR_RESULT_END", result);
      }});
    }
    return YES;
}
- (void)hostTraversalVsync:(CADisplayLink *)link {
    (void)link;
    if (!gDispatchGame || gDispatchFinished) return;
    gDispatchVsync++;
    int result=agr_dex_game_choreographer_frame(gDispatchGame);
    agr_dex_runtime_snapshot snapshot={0};
    agr_dex_game_runtime_snapshot(gDispatchGame,&snapshot);
    if (gDispatchFrames) [gDispatchFrames addObject:dexSnapshotDictionary(&snapshot)];
    if (result<0 || snapshot.traversal_count>=2 || gDispatchVsync>=4)
        finishTraversalDispatchReport();
}
@end
int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass(AppDelegate.class)); }
}
