#include "../../Runtime/Process/agr_guest_vma.h"

#include <errno.h>
#include <stdint.h>
#include <stdio.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); return 1; \
} } while (0)

enum { READ = 1, WRITE = 2, EXEC = 4 };

int main(void) {
    agr_guest_vma_space vma;
    CHECK(agr_guest_vma_init(&vma, 4096, 0x10000, 0x100000000ull) == 0);

    uint32_t base = 0;
    CHECK(agr_guest_vma_map(&vma, 0, 3 * 4096, READ | WRITE, 0, &base) == 0);
    CHECK(base == 0x10000 && vma.count == 1 && agr_guest_vma_validate(&vma) == 0);

    CHECK(agr_guest_vma_unmap(&vma, base + 4096, 4096) == 0);
    CHECK(vma.count == 2 && agr_guest_vma_find(&vma, base + 4096) == NULL);
    uint32_t reused = 0;
    CHECK(agr_guest_vma_map(&vma, base + 4096, 4096, READ | WRITE, 0, &reused) == 0);
    CHECK(reused == base + 4096 && vma.count == 1);

    CHECK(agr_guest_vma_protect(&vma, base + 4096, 4096, READ) == 0);
    CHECK(vma.count == 3);
    CHECK(agr_guest_vma_find(&vma, base)->protection == (READ | WRITE));
    CHECK(agr_guest_vma_find(&vma, base + 4096)->protection == READ);
    CHECK(agr_guest_vma_find(&vma, base + 8192)->protection == (READ | WRITE));
    CHECK(agr_guest_vma_protect(&vma, base + 4096, 4096, READ | WRITE) == 0);
    CHECK(vma.count == 1);

    uint32_t fixed = 0;
    CHECK(agr_guest_vma_map(&vma, base + 4096, 4096, EXEC,
                            AGR_GUEST_VMA_FIXED | AGR_GUEST_VMA_NOREPLACE,
                            &fixed) == EEXIST);
    CHECK(agr_guest_vma_map(&vma, base + 4096, 4096, EXEC,
                            AGR_GUEST_VMA_FIXED, &fixed) == 0);
    CHECK(fixed == base + 4096 && vma.count == 3);
    CHECK(agr_guest_vma_find(&vma, fixed)->protection == EXEC);

    CHECK(agr_guest_vma_unmap(&vma, base, 3 * 4096) == 0);
    CHECK(vma.count == 0 && agr_guest_vma_validate(&vma) == 0);

    for (uint32_t iteration = 0; iteration < 100000; ++iteration) {
        uint32_t address = 0;
        uint64_t size = (uint64_t)((iteration % 31u) + 1u) * 4096u;
        CHECK(agr_guest_vma_map(&vma, 0, size, READ | WRITE, 0, &address) == 0);
        CHECK(address == 0x10000);
        CHECK(agr_guest_vma_unmap(&vma, address, size) == 0);
        CHECK(vma.count == 0);
    }

    uint32_t fragmented[128];
    for (size_t index = 0; index < 128; ++index) {
        CHECK(agr_guest_vma_map(&vma, 0, 4096, READ, 0, &fragmented[index]) == 0);
    }
    for (size_t index = 0; index < 128; index += 2) {
        CHECK(agr_guest_vma_unmap(&vma, fragmented[index], 4096) == 0);
    }
    for (size_t index = 0; index < 64; ++index) {
        uint32_t address = 0;
        CHECK(agr_guest_vma_map(&vma, 0, 4096, READ, 0, &address) == 0);
        CHECK(address == fragmented[index * 2]);
    }
    CHECK(agr_guest_vma_validate(&vma) == 0);

    agr_guest_vma_destroy(&vma);
    puts("PASS guest 32-bit VMA split/coalesce/protect/reuse/stress contracts");
    return 0;
}
