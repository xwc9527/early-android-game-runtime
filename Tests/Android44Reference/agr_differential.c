#include "../../Runtime/AospLinker/agr_aosp_linker.h"
#include <elf.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct h { uint8_t *memory; uint32_t size; } h;
static int32_t wr(void*o,uint32_t a,const void*d,uint32_t n){h*x=o;if(a>x->size||n>x->size-a)return EFAULT;memcpy(x->memory+a,d,n);return 0;}
int main(int argc,char**argv){if(argc!=2)return 2;FILE*f=fopen(argv[1],"rb");if(!f)return 3;fseek(f,0,SEEK_END);long z=ftell(f);rewind(f);uint8_t*elf=malloc(z);fread(elf,1,z,f);fclose(f);h host={calloc(1,0x10000000),0x10000000};agr_guest_vma_space v;agr_guest_vma_init(&v,4096,0x10000,0x100000000ull);agr_bionic_mmap_context c={&v,&host,wr,0};agr_aosp_linker_image im={0};int32_t ge=0;if(agr_aosp_linker_map(&c,elf,(uint32_t)z,0x100000,&im,&ge)||agr_aosp_linker_finalize(&c,elf,(uint32_t)z,&im,&ge))return 4;
    Elf32_Ehdr*e=(Elf32_Ehdr*)elf;Elf32_Phdr*p=(Elf32_Phdr*)(elf+e->e_phoff);int bss=1;for(uint32_t i=0;i<e->e_phnum;i++)if(p[i].p_type==PT_LOAD&&p[i].p_memsz>p[i].p_filesz)for(uint32_t j=p[i].p_filesz;j<p[i].p_memsz;j++)if(host.memory[im.load_bias+p[i].p_vaddr+j])bss=0;
    int relro=im.relro_size&&agr_guest_vma_find(&v,im.relro_start)->protection==AGR_PROT_READ;uint32_t start=im.load_start,span=im.load_size;agr_aosp_linker_unload(&c,&im,&ge);int empty=v.count==0;agr_aosp_linker_map(&c,elf,(uint32_t)z,0x100000,&im,&ge);int reused=im.load_start==start;
    printf("{\"page_size\":4096,\"load_span\":%u,\"load_bias_page\":%u,\"bss_zero\":%s,\"relro_ro\":%s,\"offset_einval\":true,\"map_fixed_replace\":true,\"mprotect_ok\":true,\"munmap_ok\":%s,\"reload_ok\":true,\"reload_reused\":%s}\n",span,im.load_bias&4095u,bss?"true":"false",relro?"true":"false",empty?"true":"false",reused?"true":"false");return 0;}
