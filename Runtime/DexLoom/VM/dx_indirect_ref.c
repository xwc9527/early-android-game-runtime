#include "../Include/dx_indirect_ref.h"
#include <stdlib.h>
#include <string.h>

static uint32_t top_of(uint32_t cookie) { return cookie & 0xffffu; }
static uint32_t holes_of(uint32_t cookie) { return cookie >> 16; }

static uint32_t pack_ref(uint32_t index, uint32_t serial, int kind) {
    return (serial << 20) | (index << 2) | (uint32_t)kind;
}

int dx_iref_init(DxIRefTable *table, uint32_t initial, uint32_t max_count, int kind) {
    if (!table || initial == 0 || initial > max_count || max_count > 65536 || kind == DX_IREF_INVALID)
        return -1;
    memset(table, 0, sizeof(*table));
    table->slots = (DxIRefSlot *)calloc(initial, sizeof(DxIRefSlot));
    if (!table->slots) return -1;
    table->alloc_count = initial;
    table->max_count = max_count;
    table->kind = kind;
    return 0;
}

void dx_iref_destroy(DxIRefTable *table) {
    if (!table) return;
    free(table->slots);
    memset(table, 0, sizeof(*table));
}

uint32_t dx_iref_segment(const DxIRefTable *table) {
    if (!table) return 0;
    return (table->num_holes << 16) | (table->top_index & 0xffffu);
}

void dx_iref_restore(DxIRefTable *table, uint32_t segment) {
    uint32_t top;
    if (!table) return;
    top = top_of(segment);
    if (top > table->top_index) top = table->top_index;
    for (uint32_t i = top; i < table->top_index; i++) table->slots[i].obj = NULL;
    table->top_index = top;
    table->num_holes = holes_of(segment);
}

uint32_t dx_iref_add(DxIRefTable *table, uint32_t bottom_cookie, void *obj) {
    DxIRefSlot *slot;
    uint32_t bottom;
    int holes;
    if (!table || !obj) return 0;
    bottom = top_of(bottom_cookie);
    holes = (int)table->num_holes - (int)holes_of(bottom_cookie);
    if (holes > 0) {
        uint32_t index = table->top_index;
        while (index > bottom) {
            index--;
            if (table->slots[index].obj == NULL) {
                slot = &table->slots[index];
                table->num_holes--;
                goto fill;
            }
        }
    }
    if (table->top_index == table->alloc_count) {
        uint32_t grown = table->alloc_count * 2;
        DxIRefSlot *next;
        if (table->top_index == table->max_count) return 0;
        if (grown > table->max_count) grown = table->max_count;
        next = (DxIRefSlot *)realloc(table->slots, grown * sizeof(*next));
        if (!next) return 0;
        memset(next + table->alloc_count, 0, (grown - table->alloc_count) * sizeof(*next));
        table->slots = next;
        table->alloc_count = grown;
    }
    slot = &table->slots[table->top_index++];
fill:
    slot->obj = obj;
    slot->serial = (slot->serial + 1) & 0xfffu;
    return pack_ref((uint32_t)(slot - table->slots), slot->serial, table->kind);
}

void *dx_iref_get(const DxIRefTable *table, uint32_t iref, int *status) {
    uint32_t kind, index, serial;
    if (status) *status = DX_IREF_OK;
    if (!iref) {
        if (status) *status = DX_IREF_NULL;
        return NULL;
    }
    kind = iref & 3u;
    if (!table || kind != (uint32_t)table->kind) {
        if (status) *status = DX_IREF_WRONG_KIND;
        return NULL;
    }
    index = (iref >> 2) & 0xffffu;
    if (index >= table->top_index) {
        if (status) *status = DX_IREF_STALE;
        return NULL;
    }
    if (table->slots[index].obj == NULL) {
        if (status) *status = DX_IREF_DELETED;
        return NULL;
    }
    serial = iref >> 20;
    if (serial != table->slots[index].serial) {
        if (status) *status = DX_IREF_STALE;
        return NULL;
    }
    if (table->slots[index].obj == DX_IREF_CLEARED) {
        if (status) *status = DX_IREF_NULL;
        return NULL;
    }
    return table->slots[index].obj;
}

int dx_iref_remove(DxIRefTable *table, uint32_t bottom_cookie, uint32_t iref) {
    uint32_t index, serial, bottom;
    if (!table || (iref & 3u) != (uint32_t)table->kind) return 0;
    index = (iref >> 2) & 0xffffu;
    bottom = top_of(bottom_cookie);
    if (index < bottom || index >= table->top_index) return 0;
    serial = iref >> 20;
    if (table->slots[index].serial != serial || table->slots[index].obj == NULL) return 0;
    table->slots[index].obj = NULL;
    if (index == table->top_index - 1) {
        while (table->top_index > bottom && table->slots[table->top_index - 1].obj == NULL) {
            table->top_index--;
            if (table->num_holes) table->num_holes--;
        }
    } else {
        table->num_holes++;
    }
    return 1;
}

void dx_iref_visit(const DxIRefTable *table, void (*visit)(void *obj, void *user), void *user) {
    if (!table || !visit) return;
    for (uint32_t i = 0; i < table->top_index; i++) {
        void *obj = table->slots[i].obj;
        if (obj && obj != DX_IREF_CLEARED) visit(obj, user);
    }
}
