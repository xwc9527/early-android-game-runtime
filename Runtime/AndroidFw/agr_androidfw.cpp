#include "agr_androidfw.h"

#include <androidfw/Asset.h>
#include <androidfw/AssetDir.h>
#include <androidfw/AssetManager.h>
#include <androidfw/ResourceTypes.h>
#include <utils/String8.h>

#include <string.h>

using android::Asset;
using android::AssetManager;
using android::ResTable;
using android::ResTable_config;
using android::String8;

struct agr_afw_manager {
    AssetManager assets;
    char error[160];
    agr_afw_manager() { error[0] = '\0'; }
};

struct agr_afw_asset {
    Asset* asset;
};

static void set_error(agr_afw_manager* manager, const char* error) {
    if (!manager) return;
    const char* source = error ? error : "";
    strncpy(manager->error, source, sizeof(manager->error) - 1);
    manager->error[sizeof(manager->error) - 1] = '\0';
}

extern "C" {

agr_afw_manager* agr_afw_create(void) {
    return new agr_afw_manager();
}

void agr_afw_destroy(agr_afw_manager* manager) { delete manager; }

int agr_afw_add_apk(agr_afw_manager* manager, const char* path) {
    if (!manager || !path) return -1;
    void* cookie = NULL;
    if (!manager->assets.addAssetPath(String8(path), &cookie)) {
        set_error(manager, "AssetManager::addAssetPath failed");
        return -1;
    }
    set_error(manager, "");
    return cookie ? 0 : -1;
}

agr_afw_asset* agr_afw_open(agr_afw_manager* manager, const char* path, int mode) {
    if (!manager || !path) return NULL;
    if (mode < Asset::ACCESS_UNKNOWN || mode > Asset::ACCESS_BUFFER) mode = Asset::ACCESS_STREAMING;
    Asset* asset = manager->assets.open(path, static_cast<Asset::AccessMode>(mode));
    if (!asset) {
        set_error(manager, "AssetManager::open failed");
        return NULL;
    }
    agr_afw_asset* result = new agr_afw_asset;
    if (result) result->asset = asset;
    if (!result) {
        asset->close();
        set_error(manager, "asset handle allocation failed");
    }
    return result;
}

int64_t agr_afw_read(agr_afw_asset* asset, void* output, size_t count) {
    return asset && asset->asset ? asset->asset->read(output, count) : -1;
}

int64_t agr_afw_seek(agr_afw_asset* asset, int64_t offset, int whence) {
    return asset && asset->asset ? asset->asset->seek(offset, whence) : -1;
}

int64_t agr_afw_length(agr_afw_asset* asset) {
    return asset && asset->asset ? asset->asset->getLength() : -1;
}

const void* agr_afw_buffer(agr_afw_asset* asset) {
    return asset && asset->asset ? asset->asset->getBuffer(false) : NULL;
}

void agr_afw_close(agr_afw_asset* asset) {
    if (!asset) return;
    if (asset->asset) asset->asset->close();
    delete asset;
}

int agr_afw_set_config(agr_afw_manager* manager, const char* locale,
                       uint16_t density, uint16_t sdk_version) {
    if (!manager) return -1;
    ResTable_config config;
    memset(&config, 0, sizeof(config));
    config.size = sizeof(config);
    config.density = density;
    config.sdkVersion = sdk_version;
    manager->assets.setConfiguration(config, locale && locale[0] ? locale : NULL);
    return 0;
}

int agr_afw_resource_table_count(agr_afw_manager* manager) {
    if (!manager) return -1;
    return static_cast<int>(manager->assets.getResources(false).getTableCount());
}

int agr_afw_resource_package_count(agr_afw_manager* manager) {
    if (!manager) return -1;
    return static_cast<int>(manager->assets.getResources(false).getBasePackageCount());
}

int agr_afw_resource_package(agr_afw_manager* manager, size_t index,
                             char* output, size_t output_size, uint32_t* package_id) {
    if (!manager || !output || output_size == 0) return -1;
    const ResTable& table = manager->assets.getResources(false);
    if (index >= table.getBasePackageCount()) return -1;
    const char16_t* name = table.getBasePackageName(index);
    String8 utf8(name);
    const size_t bytes = output_size - 1 < utf8.length() ? output_size - 1 : utf8.length();
    memcpy(output, utf8.string(), bytes);
    output[bytes] = '\0';
    if (package_id) *package_id = table.getBasePackageId(index);
    return 0;
}

static int count_assets(AssetManager* manager, const String8& path) {
    android::AssetDir* directory = manager->openDir(path.string());
    if (!directory) return 0;
    int count = 0;
    for (size_t index = 0; index < directory->getFileCount(); ++index) {
        const String8& name = directory->getFileName(static_cast<int>(index));
        if (directory->getFileType(static_cast<int>(index)) == android::kFileTypeDirectory) {
            String8 child(path);
            if (child.length()) child.append("/");
            child.append(name);
            count += count_assets(manager, child);
        } else {
            ++count;
        }
    }
    delete directory;
    return count;
}

int agr_afw_asset_count(agr_afw_manager* manager) {
    return manager ? count_assets(&manager->assets, String8("")) : -1;
}

uint32_t agr_afw_identifier(agr_afw_manager* manager, const char* name) {
    if (!manager || !name) return 0;
    android::String16 value(name);
    return manager->assets.getResources(false).identifierForName(value.string(), value.size());
}

int agr_afw_string_resource(agr_afw_manager* manager, uint32_t resource_id,
                            char* output, size_t output_size) {
    if (!manager || !output || output_size == 0) return -1;
    const ResTable& table = manager->assets.getResources(false);
    android::Res_value value;
    const ssize_t block = table.getResource(resource_id, &value);
    if (block < 0 || value.dataType != android::Res_value::TYPE_STRING) return -1;
    const android::ResStringPool* strings = table.getTableStringBlock(static_cast<size_t>(block));
    if (!strings) return -1;
    size_t length = 0;
    const char* text = strings->string8At(value.data, &length);
    if (!text) return -1;
    const size_t bytes = output_size - 1 < length ? output_size - 1 : length;
    memcpy(output, text, bytes);
    output[bytes] = '\0';
    return static_cast<int>(bytes);
}

const char* agr_afw_last_error(agr_afw_manager* manager) {
    return manager ? manager->error : "no manager";
}

}
