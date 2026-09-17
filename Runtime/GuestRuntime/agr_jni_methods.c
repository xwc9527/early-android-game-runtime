#include "agr_jni_methods.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define METHOD_BASE 0x65000000u

static uint32_t hash_byte(uint32_t hash, uint8_t byte) {
    return (hash ^ byte) * 16777619u;
}
static uint32_t method_hash(uint32_t class_handle, const char *name, const char *signature) {
    uint32_t hash=2166136261u;
    for (unsigned i=0;i<4;i++) hash=hash_byte(hash,(uint8_t)(class_handle>>(8*i)));
    for (const unsigned char *p=(const unsigned char *)name;*p;p++) hash=hash_byte(hash,*p);
    hash=hash_byte(hash,0);
    for (const unsigned char *p=(const unsigned char *)signature;*p;p++) hash=hash_byte(hash,*p);
    return hash;
}
static char *duplicate(const char *text) {
    size_t length=strlen(text)+1;
    char *result=(char *)malloc(length);
    if (result) memcpy(result,text,length);
    return result;
}
static int rehash(agr_jni_method_table *table, size_t count) {
    if (count>SIZE_MAX/sizeof(uint32_t)) return -1;
    uint32_t *buckets=(uint32_t *)calloc(count,sizeof(*buckets));
    if (!buckets) return -1;
    for (size_t i=0;i<table->count;i++) {
        const agr_jni_method *entry=&table->entries[i];
        size_t slot=method_hash(entry->class_handle,entry->name,entry->signature)&(count-1);
        while (buckets[slot]) slot=(slot+1)&(count-1);
        buckets[slot]=(uint32_t)i+1;
    }
    free(table->buckets); table->buckets=buckets; table->bucket_count=count;
    return 0;
}
int agr_jni_method_id(agr_jni_method_table *table, uint32_t class_handle,
                      const char *name, const char *signature, uint32_t *handle) {
    if (!table || !class_handle || !name || !signature || !handle) return -1;
    if (!table->bucket_count && rehash(table,16)) return -1;
    uint32_t hash=method_hash(class_handle,name,signature);
    size_t slot=hash&(table->bucket_count-1);
    while (table->buckets[slot]) {
        const agr_jni_method *entry=&table->entries[table->buckets[slot]-1];
        if (entry->class_handle==class_handle && !strcmp(entry->name,name) &&
            !strcmp(entry->signature,signature)) { *handle=entry->handle; return 0; }
        slot=(slot+1)&(table->bucket_count-1);
    }
    if (table->count >= (UINT32_MAX-METHOD_BASE)/4u) return -1;
    if (table->count+1 >= table->bucket_count-table->bucket_count/4u) {
        if (table->bucket_count>SIZE_MAX/2 || rehash(table,table->bucket_count*2)) return -1;
        slot=hash&(table->bucket_count-1);
        while (table->buckets[slot]) slot=(slot+1)&(table->bucket_count-1);
    }
    if (table->count==table->capacity) {
        size_t next=table->capacity?table->capacity*2:16;
        if (next<table->capacity || next>SIZE_MAX/sizeof(*table->entries)) return -1;
        agr_jni_method *grown=(agr_jni_method *)realloc(table->entries,next*sizeof(*grown));
        if (!grown) return -1;
        table->entries=grown;table->capacity=next;
    }
    char *name_copy=duplicate(name), *signature_copy=duplicate(signature);
    if (!name_copy || !signature_copy) { free(name_copy);free(signature_copy);return -1; }
    size_t index=table->count++;
    table->entries[index]=(agr_jni_method){METHOD_BASE+(uint32_t)index*4u,
                                             class_handle,name_copy,signature_copy};
    table->buckets[slot]=(uint32_t)index+1;
    *handle=table->entries[index].handle;
    return 0;
}
const agr_jni_method *agr_jni_method_lookup(const agr_jni_method_table *table,
                                            uint32_t handle) {
    if (!table || handle<METHOD_BASE || ((handle-METHOD_BASE)&3u)) return NULL;
    uint32_t index=(handle-METHOD_BASE)/4u;
    if (index>=table->count) return NULL;
    return &table->entries[index];
}
void agr_jni_method_table_destroy(agr_jni_method_table *table) {
    if (!table) return;
    for (size_t i=0;i<table->count;i++) {
        free(table->entries[i].name);free(table->entries[i].signature);
    }
    free(table->entries);free(table->buckets);
    memset(table,0,sizeof(*table));
}
