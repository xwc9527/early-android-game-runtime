#ifndef AGR_JNI_METHODS_H
#define AGR_JNI_METHODS_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t handle, class_handle;
    char *name, *signature;
} agr_jni_method;

typedef struct {
    agr_jni_method *entries;
    size_t count, capacity;
    uint32_t *buckets;
    size_t bucket_count;
} agr_jni_method_table;

/* jmethodID is an opaque, stable ID for a method; it is not a local jobject. */
int agr_jni_method_id(agr_jni_method_table *table, uint32_t class_handle,
                      const char *name, const char *signature, uint32_t *handle);
const agr_jni_method *agr_jni_method_lookup(const agr_jni_method_table *table,
                                            uint32_t handle);
void agr_jni_method_table_destroy(agr_jni_method_table *table);

#endif
