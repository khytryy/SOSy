#include <gdt/gdt.h>

gdt_segment_t   gdt_entries[5];
gdtr_t          gdtr;

void gdt_load(gdtr_t* gdtr);

void gdt_init() {
    gdtr.size   = (sizeof(gdt_segment_t) * 5) - 1;
    gdtr.offset = (uint32_t)gdt_entries;

    gdt_set_entry(0, 0, 0, 0, 0);                   // Null descriptor

    gdt_set_entry(1, 0, LIMIT_4KIB, 0x9A, 0xCF);    // Kernel mode code segment
    gdt_set_entry(2, 0, LIMIT_4KIB, 0x92, 0xCF);    // Kernel mode data segment

    gdt_set_entry(3, 0, LIMIT_4KIB, 0xFA, 0xCF);    // User mode code segment
    gdt_set_entry(4, 0, LIMIT_4KIB, 0xF2, 0xCF);    // User mode data segment

    gdt_load(&gdtr);
}

void gdt_set_entry(uint32_t entry, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {
    // Encode the base
    uint16_t    base_low        = (base & 0x0000FFFF);
    uint8_t     base_middle     = (base & 0x00FF0000) >> 16;
    uint8_t     base_high       = (base & 0xFF000000) >> 24;

    gdt_entries[entry].base_low     = base_low;
    gdt_entries[entry].base_middle  = base_middle;
    gdt_entries[entry].base_high    = base_high;

    // Encode the limit
    uint16_t    limit_low       = (limit & 0x0000FFFF);
    uint8_t limit_high          = (limit & 0x000F0000) >> 16;

    // Because limit_high and flags live together, we have to do some bitshift magic to fit them together in a 8-bit value
    gdt_entries[entry].limit_low    =   limit_low;
    gdt_entries[entry].flags        =   limit_high;
    gdt_entries[entry].flags        |=  (flags & 0xFF00);

    gdt_entries[entry].access       =   access;
}