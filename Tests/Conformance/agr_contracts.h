#ifndef AGR_CONTRACTS_H
#define AGR_CONTRACTS_H
#include <stdint.h>
typedef struct {
    const char *id;
    const char *module;
    const char *source_case;
    int passed;
    uint32_t observed;
    uint32_t expected;
} agr_contract_result;
uint32_t agr_run_contracts(agr_contract_result *results, uint32_t capacity);
#endif
