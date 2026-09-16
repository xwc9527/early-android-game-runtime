#ifndef AGR_GUEST_RUNTIME_H
#define AGR_GUEST_RUNTIME_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct agr_guest agr_guest;

enum {
    AGR_ARRAY_SHORT = 1,
    AGR_ARRAY_INT = 2,
    AGR_ARRAY_FLOAT = 3,
};

agr_guest *agr_guest_create(void);
void agr_guest_destroy(agr_guest *guest);
const char *agr_guest_last_error(agr_guest *guest);

int32_t agr_guest_load_elf(agr_guest *guest, const char *name,
                           const void *bytes, uint32_t size, uint32_t base);
uint32_t agr_guest_find_symbol(agr_guest *guest, const char *symbol);
uint32_t agr_guest_new_primitive_array(agr_guest *guest, uint32_t kind,
                                       const void *bytes, uint32_t count);
int32_t agr_guest_call_symbol(agr_guest *guest, const char *symbol,
                              const uint32_t *arguments, uint32_t argument_count,
                              int32_t *result);
int32_t agr_guest_call_address(agr_guest *guest, uint32_t address,
                               const uint32_t *arguments, uint32_t argument_count,
                               int32_t *result);
int32_t agr_guest_run_constructors(agr_guest *guest, uint32_t *executed);
uint32_t agr_guest_alloc(agr_guest *guest, const void *bytes, uint32_t size, uint32_t alignment);
int32_t agr_guest_read(agr_guest *guest, uint32_t address, void *bytes, uint32_t size);
int32_t agr_guest_write(agr_guest *guest, uint32_t address, const void *bytes, uint32_t size);
uint32_t agr_guest_jni_env(agr_guest *guest);
uint32_t agr_guest_java_vm(agr_guest *guest);
int32_t agr_guest_mount_apk(agr_guest *guest, const char *path);
int32_t agr_guest_load_dex(agr_guest *guest, const char *path);
int32_t agr_guest_resume_thread(agr_guest *guest);
int32_t agr_guest_resume_thread_until_swap(agr_guest *guest);
int32_t agr_guest_has_parked_thread(agr_guest *guest);

int32_t agr_guest_create_gles1_pbuffer(agr_guest *guest, int width, int height);
void agr_guest_setup_gles1_frame(agr_guest *guest);
int32_t agr_guest_read_rgba(agr_guest *guest, void *pixels, uint32_t capacity);
const char *agr_guest_gl_renderer(agr_guest *guest);
const char *agr_guest_gl_version(agr_guest *guest);
uint64_t agr_guest_instruction_count(agr_guest *guest);
uint32_t agr_guest_draw_count(agr_guest *guest);
uint32_t agr_guest_swap_count(agr_guest *guest);
uint32_t agr_guest_asset_open_count(agr_guest *guest);

#ifdef __cplusplus
}
#endif
#endif
