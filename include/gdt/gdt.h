#pragma once

#include <stdint.h>

#define LIMIT_4KIB 0xFFFFF

typedef struct {
    uint16_t        limit_low;

    uint16_t        base_low;
    uint8_t         base_middle;

    uint8_t         access;
    uint8_t         flags;

    uint8_t         base_high;
} __attribute__((packed)) gdt_segment_t;

typedef struct {
    uint16_t        size;
    unsigned int    offset;
} __attribute__((packed)) gdtr_t;

extern void             gdt_load(gdtr_t* gdtr);

extern gdt_segment_t    gdt_entries[5];
extern gdtr_t           gdtr;

void gdt_init();
void gdt_set_entry(uint32_t entry, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags);