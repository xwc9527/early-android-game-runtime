#ifndef AGR_AOSP_DYNAMIC_H
#define AGR_AOSP_DYNAMIC_H

#include <stdint.h>
#include "agr_aosp_linker.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct agr_aosp_dynamic agr_aosp_dynamic;

typedef int32_t (*agr_dynamic_read_fn)(void*, uint32_t, void*, uint32_t);
typedef int32_t (*agr_dynamic_write_fn)(void*, uint32_t, const void*, uint32_t);
typedef uint32_t (*agr_dynamic_import_fn)(void*, const char*, uint32_t);
typedef int32_t (*agr_dynamic_invoke_fn)(void*, uint32_t);

typedef struct agr_aosp_dynamic_callbacks {
  void* opaque;
  agr_dynamic_read_fn read_guest;
  agr_dynamic_write_fn write_loader;
  agr_dynamic_import_fn resolve_import;
  agr_dynamic_invoke_fn invoke_guest_function;
} agr_aosp_dynamic_callbacks;

typedef struct agr_aosp_dynamic_load_result {
  uint32_t object_handle;
  uint32_t needed_start, needed_count;
  uint32_t relocation_start, relocation_count;
  uint32_t constructor_start, constructor_count;
  uint32_t symbol_start, symbol_count;
} agr_aosp_dynamic_load_result;

typedef struct agr_aosp_dynamic_relocation {
  uint32_t type;
  uint32_t address;
  const char* symbol;
  const char* object_name;
} agr_aosp_dynamic_relocation;

agr_aosp_dynamic* agr_aosp_dynamic_create(agr_bionic_mmap_context*,
                                           const agr_aosp_dynamic_callbacks*);
void agr_aosp_dynamic_destroy(agr_aosp_dynamic*);

/* Registers bytes for AOSP find_library/load_library DT_NEEDED traversal. */
int32_t agr_aosp_dynamic_register(agr_aosp_dynamic*, const char* name,
                                  const void* bytes, uint32_t size,
                                  uint32_t preferred_load_bias);
int32_t agr_aosp_dynamic_load(agr_aosp_dynamic*, const char* name,
                              const void* bytes, uint32_t size,
                              uint32_t preferred_load_bias,
                              agr_aosp_dynamic_load_result*);

uint32_t agr_aosp_dynamic_find_symbol(agr_aosp_dynamic*, const char*);
uint32_t agr_aosp_dynamic_dlopen(agr_aosp_dynamic*, const char*, int flags);
uint32_t agr_aosp_dynamic_dlsym(agr_aosp_dynamic*, uint32_t, const char*);
int32_t agr_aosp_dynamic_dlclose(agr_aosp_dynamic*, uint32_t);
const char* agr_aosp_dynamic_dlerror(agr_aosp_dynamic*);
int32_t agr_aosp_dynamic_dladdr(agr_aosp_dynamic*, uint32_t address,
                                char* object_name, uint32_t object_name_size,
                                uint32_t* object_base,
                                char* symbol_name, uint32_t symbol_name_size,
                                uint32_t* symbol_address);

uint32_t agr_aosp_dynamic_symbol_count(const agr_aosp_dynamic*);
const char* agr_aosp_dynamic_symbol_name(const agr_aosp_dynamic*, uint32_t);
uint32_t agr_aosp_dynamic_symbol_address(const agr_aosp_dynamic*, uint32_t);
uint32_t agr_aosp_dynamic_needed_count(const agr_aosp_dynamic*);
const char* agr_aosp_dynamic_needed_name(const agr_aosp_dynamic*, uint32_t);
uint32_t agr_aosp_dynamic_loaded_count(const agr_aosp_dynamic*);
const char* agr_aosp_dynamic_loaded_name(const agr_aosp_dynamic*, uint32_t);
uint32_t agr_aosp_dynamic_constructor_count(const agr_aosp_dynamic*);
uint32_t agr_aosp_dynamic_constructor_address(const agr_aosp_dynamic*, uint32_t);
uint32_t agr_aosp_dynamic_finalizer_count(const agr_aosp_dynamic*);
uint32_t agr_aosp_dynamic_finalizer_address(const agr_aosp_dynamic*, uint32_t);
uint32_t agr_aosp_dynamic_relocation_count(const agr_aosp_dynamic*);
int32_t agr_aosp_dynamic_relocation_at(const agr_aosp_dynamic*, uint32_t,
                                       agr_aosp_dynamic_relocation*);
typedef struct agr_aosp_exidx_module {
  const char* name;
  uint32_t load_start, load_size, load_bias;
  uint32_t exidx, exidx_count;
} agr_aosp_exidx_module;

/* Looks up the already-loaded soinfo that owns `pc`. This is an adapter over
 * the formal linker solist, not a second DSO/exidx registry. */
int32_t agr_aosp_dynamic_find_module_by_pc(const agr_aosp_dynamic*, uint32_t pc,
                                           agr_aosp_exidx_module* out);
uint32_t agr_aosp_dynamic_find_exidx(const agr_aosp_dynamic*, uint32_t pc,
                                     uint32_t* count);

#ifdef __cplusplus
}
#endif
#endif
