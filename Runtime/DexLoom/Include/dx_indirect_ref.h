#ifndef DX_INDIRECT_REF_H
#define DX_INDIRECT_REF_H

#include <stdint.h>
#include <stddef.h>

/* API19 dalvik/vm/IndirectRefTable.h encoding.
   Low 2 bits are the kind. Index is bits 2..17. Serial is bits 20..31. */

enum {
    DX_IREF_INVALID = 0,
    DX_IREF_LOCAL = 1,
    DX_IREF_GLOBAL = 2,
    DX_IREF_WEAK = 3
};

enum {
    DX_IREF_OK = 0,
    DX_IREF_NULL = 1,
    DX_IREF_STALE = 2,
    DX_IREF_DELETED = 3,
    DX_IREF_WRONG_KIND = 4,
    DX_IREF_OVERFLOW = 5
};

typedef struct DxIRefSlot {
    void *obj;
    uint32_t serial;
} DxIRefSlot;

typedef struct DxIRefTable {
    DxIRefSlot *slots;
    uint32_t alloc_count;
    uint32_t max_count;
    uint32_t top_index;
    uint32_t num_holes;
    int kind;
} DxIRefTable;

#define DX_IREF_CLEARED ((void *)(uintptr_t)0xdead1234u)

int dx_iref_init(DxIRefTable *table, uint32_t initial, uint32_t max_count, int kind);
void dx_iref_destroy(DxIRefTable *table);
uint32_t dx_iref_segment(const DxIRefTable *table);
void dx_iref_restore(DxIRefTable *table, uint32_t segment);
uint32_t dx_iref_add(DxIRefTable *table, uint32_t bottom_cookie, void *obj);
void *dx_iref_get(const DxIRefTable *table, uint32_t iref, int *status);
int dx_iref_remove(DxIRefTable *table, uint32_t bottom_cookie, uint32_t iref);
void dx_iref_visit(const DxIRefTable *table, void (*visit)(void *obj, void *user), void *user);

#endif
