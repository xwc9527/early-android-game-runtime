#ifndef AGR_ANDROIDFW_H
#define AGR_ANDROIDFW_H

#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32
#define AGR_AFW_EXPORT __declspec(dllexport)
#else
#define AGR_AFW_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct agr_afw_manager agr_afw_manager;
typedef struct agr_afw_asset agr_afw_asset;

AGR_AFW_EXPORT agr_afw_manager* agr_afw_create(void);
AGR_AFW_EXPORT void agr_afw_destroy(agr_afw_manager* manager);
AGR_AFW_EXPORT int agr_afw_add_apk(agr_afw_manager* manager, const char* path);
AGR_AFW_EXPORT agr_afw_asset* agr_afw_open(agr_afw_manager* manager, const char* path, int mode);
AGR_AFW_EXPORT int64_t agr_afw_read(agr_afw_asset* asset, void* output, size_t count);
AGR_AFW_EXPORT int64_t agr_afw_seek(agr_afw_asset* asset, int64_t offset, int whence);
AGR_AFW_EXPORT int64_t agr_afw_length(agr_afw_asset* asset);
AGR_AFW_EXPORT const void* agr_afw_buffer(agr_afw_asset* asset);
AGR_AFW_EXPORT void agr_afw_close(agr_afw_asset* asset);
AGR_AFW_EXPORT int agr_afw_set_config(agr_afw_manager* manager, const char* locale,
                                      uint16_t density, uint16_t sdk_version);
AGR_AFW_EXPORT int agr_afw_resource_table_count(agr_afw_manager* manager);
AGR_AFW_EXPORT int agr_afw_resource_package_count(agr_afw_manager* manager);
AGR_AFW_EXPORT int agr_afw_resource_package(agr_afw_manager* manager, size_t index,
                                            char* output, size_t output_size,
                                            uint32_t* package_id);
AGR_AFW_EXPORT int agr_afw_asset_count(agr_afw_manager* manager);
AGR_AFW_EXPORT uint32_t agr_afw_identifier(agr_afw_manager* manager, const char* name);
AGR_AFW_EXPORT int agr_afw_string_resource(agr_afw_manager* manager, uint32_t resource_id,
                                           char* output, size_t output_size);
AGR_AFW_EXPORT const char* agr_afw_last_error(agr_afw_manager* manager);

#ifdef __cplusplus
}
#endif

#endif
