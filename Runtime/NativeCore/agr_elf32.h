#ifndef AGR_ELF32_H
#define AGR_ELF32_H
#include <stdint.h>

typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Off;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf32_Word;

#define EI_NIDENT 16
typedef struct { unsigned char e_ident[EI_NIDENT]; Elf32_Half e_type,e_machine; Elf32_Word e_version; Elf32_Addr e_entry; Elf32_Off e_phoff,e_shoff; Elf32_Word e_flags; Elf32_Half e_ehsize,e_phentsize,e_phnum,e_shentsize,e_shnum,e_shstrndx; } Elf32_Ehdr;
typedef struct { Elf32_Word p_type; Elf32_Off p_offset; Elf32_Addr p_vaddr,p_paddr; Elf32_Word p_filesz,p_memsz,p_flags,p_align; } Elf32_Phdr;
typedef struct { Elf32_Word sh_name,sh_type,sh_flags; Elf32_Addr sh_addr; Elf32_Off sh_offset; Elf32_Word sh_size,sh_link,sh_info,sh_addralign,sh_entsize; } Elf32_Shdr;
typedef struct { Elf32_Word st_name; Elf32_Addr st_value; Elf32_Word st_size; unsigned char st_info,st_other; Elf32_Half st_shndx; } Elf32_Sym;
typedef struct { Elf32_Addr r_offset; Elf32_Word r_info; } Elf32_Rel;
typedef struct { Elf32_Sword d_tag; union { Elf32_Word d_val; Elf32_Addr d_ptr; } d_un; } Elf32_Dyn;

#define ELFMAG "\177ELF"
#define SELFMAG 4
#define EI_CLASS 4
#define ELFCLASS32 1
#define EM_ARM 40
#define PT_LOAD 1
#define PT_DYNAMIC 2
#define SHT_DYNSYM 11
#define SHN_UNDEF 0
#define STB_GLOBAL 1
#define STB_WEAK 2
#define STT_NOTYPE 0
#define STT_OBJECT 1
#define STT_FUNC 2
#define ELF32_ST_BIND(i) ((i)>>4)
#define ELF32_ST_TYPE(i) ((i)&0xf)
#define ELF32_R_SYM(i) ((i)>>8)
#define ELF32_R_TYPE(i) ((unsigned char)(i))

#define DT_NULL 0
#define DT_NEEDED 1
#define DT_PLTRELSZ 2
#define DT_PLTGOT 3
#define DT_HASH 4
#define DT_STRTAB 5
#define DT_SYMTAB 6
#define DT_RELA 7
#define DT_RELASZ 8
#define DT_STRSZ 10
#define DT_SYMENT 11
#define DT_INIT 12
#define DT_FINI 13
#define DT_SYMBOLIC 16
#define DT_REL 17
#define DT_RELSZ 18
#define DT_RELENT 19
#define DT_PLTREL 20
#define DT_JMPREL 23
#define DT_TEXTREL 22
#define DT_INIT_ARRAY 25
#define DT_FINI_ARRAY 26
#define DT_INIT_ARRAYSZ 27
#define DT_FINI_ARRAYSZ 28
#define DT_PREINIT_ARRAY 32
#define DT_PREINIT_ARRAYSZ 33

#define R_ARM_NONE 0
#define R_ARM_ABS32 2
#define R_ARM_REL32 3
#define R_ARM_COPY 20
#define R_ARM_GLOB_DAT 21
#define R_ARM_JUMP_SLOT 22
#define R_ARM_RELATIVE 23
#endif
