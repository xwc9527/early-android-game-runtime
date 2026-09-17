#include "agr_guest_vma.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

static int is_power_of_two(uint32_t value) {
    return value && !(value & (value - 1u));
}

static int round_length(const agr_guest_vma_space *space, uint64_t length,
                        uint64_t *rounded) {
    if (!space || !length || !rounded) return EINVAL;
    uint64_t mask = (uint64_t)space->page_size - 1u;
    if (length > UINT64_MAX - mask) return ENOMEM;
    *rounded = (length + mask) & ~mask;
    return *rounded ? 0 : ENOMEM;
}

static int ensure_capacity(agr_guest_vma_space *space, size_t required) {
    if (required <= space->capacity) return 0;
    size_t capacity = space->capacity ? space->capacity : 8u;
    while (capacity < required) {
        if (capacity > SIZE_MAX / 2u) return ENOMEM;
        capacity *= 2u;
    }
    if (capacity > SIZE_MAX / sizeof(*space->regions)) return ENOMEM;
    void *grown = realloc(space->regions, capacity * sizeof(*space->regions));
    if (!grown) return ENOMEM;
    space->regions = (agr_guest_vma_region *)grown;
    space->capacity = capacity;
    return 0;
}

static void erase_region(agr_guest_vma_space *space, size_t index) {
    if (index + 1u < space->count) {
        memmove(&space->regions[index], &space->regions[index + 1u],
                (space->count - index - 1u) * sizeof(*space->regions));
    }
    --space->count;
}

static int insert_region(agr_guest_vma_space *space, size_t index,
                         agr_guest_vma_region region) {
    int result = ensure_capacity(space, space->count + 1u);
    if (result) return result;
    if (index < space->count) {
        memmove(&space->regions[index + 1u], &space->regions[index],
                (space->count - index) * sizeof(*space->regions));
    }
    space->regions[index] = region;
    ++space->count;
    return 0;
}

static void coalesce(agr_guest_vma_space *space) {
    size_t index = 0;
    while (index + 1u < space->count) {
        agr_guest_vma_region *left = &space->regions[index];
        agr_guest_vma_region *right = &space->regions[index + 1u];
        if (left->end == right->start &&
            left->protection == right->protection) {
            left->end = right->end;
            erase_region(space, index + 1u);
        } else {
            ++index;
        }
    }
}

int agr_guest_vma_init(agr_guest_vma_space *space, uint32_t page_size,
                       uint32_t lower_bound, uint64_t upper_bound) {
    if (!space || !is_power_of_two(page_size) || page_size < 4096u ||
        (lower_bound & (page_size - 1u)) ||
        (upper_bound & (page_size - 1u)) ||
        upper_bound > 0x100000000ull || lower_bound >= upper_bound) {
        return EINVAL;
    }
    *space = (agr_guest_vma_space){
        .page_size = page_size,
        .lower_bound = lower_bound,
        .upper_bound = upper_bound,
    };
    return 0;
}

void agr_guest_vma_destroy(agr_guest_vma_space *space) {
    if (!space) return;
    free(space->regions);
    memset(space, 0, sizeof(*space));
}

static int range_for(const agr_guest_vma_space *space, uint32_t address,
                     uint64_t length, uint64_t *end) {
    uint64_t rounded = 0;
    int result = round_length(space, length, &rounded);
    if (result) return result;
    uint64_t candidate_end = (uint64_t)address + rounded;
    if ((address & (space->page_size - 1u)) ||
        address < space->lower_bound || candidate_end > space->upper_bound ||
        candidate_end <= address) return EINVAL;
    *end = candidate_end;
    return 0;
}

int agr_guest_vma_unmap(agr_guest_vma_space *space, uint32_t address,
                        uint64_t length) {
    if (!space) return EINVAL;
    uint64_t end = 0;
    int result = range_for(space, address, length, &end);
    if (result) return result;

    for (size_t index = 0; index < space->count;) {
        agr_guest_vma_region current = space->regions[index];
        if (current.end <= address) { ++index; continue; }
        if (current.start >= end) break;
        if (address <= current.start && end >= current.end) {
            erase_region(space, index);
            continue;
        }
        if (address > current.start && end < current.end) {
            space->regions[index].end = address;
            agr_guest_vma_region tail = {
                .start = (uint32_t)end,
                .end = current.end,
                .protection = current.protection,
            };
            return insert_region(space, index + 1u, tail);
        }
        if (address <= current.start) {
            space->regions[index].start = (uint32_t)end;
            break;
        }
        space->regions[index].end = address;
        ++index;
    }
    return 0;
}

static int find_first_fit(const agr_guest_vma_space *space, uint32_t hint,
                          uint64_t length, uint32_t *address) {
    uint64_t cursor = hint >= space->lower_bound ? hint : space->lower_bound;
    uint64_t mask = (uint64_t)space->page_size - 1u;
    cursor = (cursor + mask) & ~mask;
    for (size_t index = 0; index < space->count; ++index) {
        const agr_guest_vma_region *region = &space->regions[index];
        if (region->end <= cursor) continue;
        if (cursor + length <= region->start) break;
        cursor = region->end;
    }
    if (cursor > UINT32_MAX || cursor + length > space->upper_bound ||
        cursor + length <= cursor) return ENOMEM;
    *address = (uint32_t)cursor;
    return 0;
}

static int overlaps(const agr_guest_vma_space *space, uint32_t start,
                    uint64_t end) {
    for (size_t index = 0; index < space->count; ++index) {
        const agr_guest_vma_region *region = &space->regions[index];
        if (region->end <= start) continue;
        return region->start < end;
    }
    return 0;
}

int agr_guest_vma_map(agr_guest_vma_space *space, uint32_t address,
                      uint64_t length, uint32_t protection, uint32_t flags,
                      uint32_t *mapped_address) {
    if (!space || !mapped_address ||
        (flags & ~(AGR_GUEST_VMA_FIXED | AGR_GUEST_VMA_NOREPLACE)) ||
        ((flags & AGR_GUEST_VMA_NOREPLACE) && !(flags & AGR_GUEST_VMA_FIXED))) {
        return EINVAL;
    }
    uint64_t rounded = 0;
    int result = round_length(space, length, &rounded);
    if (result) return result;

    uint32_t start = address;
    uint64_t end = 0;
    if (flags & AGR_GUEST_VMA_FIXED) {
        result = range_for(space, address, rounded, &end);
        if (result) return result;
        if ((flags & AGR_GUEST_VMA_NOREPLACE) && overlaps(space, start, end)) {
            return EEXIST;
        }
        if (!(flags & AGR_GUEST_VMA_NOREPLACE)) {
            result = agr_guest_vma_unmap(space, start, rounded);
            if (result) return result;
        }
    } else {
        result = find_first_fit(space, address, rounded, &start);
        if (result) return result;
        end = (uint64_t)start + rounded;
    }

    size_t index = 0;
    while (index < space->count && space->regions[index].start < start) ++index;
    result = insert_region(space, index, (agr_guest_vma_region){
        .start = start, .end = end, .protection = protection,
    });
    if (result) return result;
    coalesce(space);
    *mapped_address = start;
    return 0;
}

static int split_at(agr_guest_vma_space *space, uint64_t point) {
    if (point > UINT32_MAX) return 0;
    for (size_t index = 0; index < space->count; ++index) {
        agr_guest_vma_region *region = &space->regions[index];
        if (point <= region->start) return 0;
        if (point >= region->end) continue;
        agr_guest_vma_region right = {
            .start = (uint32_t)point,
            .end = region->end,
            .protection = region->protection,
        };
        region->end = point;
        return insert_region(space, index + 1u, right);
    }
    return 0;
}

int agr_guest_vma_protect(agr_guest_vma_space *space, uint32_t address,
                          uint64_t length, uint32_t protection) {
    if (!space) return EINVAL;
    uint64_t end = 0;
    int result = range_for(space, address, length, &end);
    if (result) return result;

    uint64_t covered = address;
    for (size_t index = 0; index < space->count && covered < end; ++index) {
        const agr_guest_vma_region *region = &space->regions[index];
        if (region->end <= covered) continue;
        if (region->start > covered) return ENOMEM;
        covered = region->end < end ? region->end : end;
    }
    if (covered < end) return ENOMEM;

    result = split_at(space, address);
    if (result) return result;
    result = split_at(space, end);
    if (result) return result;
    for (size_t index = 0; index < space->count; ++index) {
        agr_guest_vma_region *region = &space->regions[index];
        if (region->end <= address) continue;
        if (region->start >= end) break;
        region->protection = protection;
    }
    coalesce(space);
    return 0;
}

const agr_guest_vma_region *agr_guest_vma_find(const agr_guest_vma_space *space,
                                                uint32_t address) {
    if (!space) return NULL;
    for (size_t index = 0; index < space->count; ++index) {
        const agr_guest_vma_region *region = &space->regions[index];
        if (address < region->start) return NULL;
        if (address < region->end) return region;
    }
    return NULL;
}

int agr_guest_vma_validate(const agr_guest_vma_space *space) {
    if (!space || !is_power_of_two(space->page_size) ||
        space->lower_bound >= space->upper_bound ||
        space->upper_bound > 0x100000000ull) return EINVAL;
    uint64_t previous_end = space->lower_bound;
    for (size_t index = 0; index < space->count; ++index) {
        const agr_guest_vma_region *region = &space->regions[index];
        if ((region->start & (space->page_size - 1u)) ||
            (region->end & (space->page_size - 1u)) ||
            region->start < previous_end || region->start >= region->end ||
            region->end > space->upper_bound) return EINVAL;
        previous_end = region->end;
    }
    return 0;
}
