#include <stdint.h>
int agr_reference_value = 0x12345678;
unsigned char agr_reference_bss[8192];
const void * const agr_reference_relro = &agr_reference_value;
int agr_reference_entry(void) { return agr_reference_value + agr_reference_bss[0]; }
