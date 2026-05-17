#pragma once

#include <stdint.h>

typedef struct {
    uint16_t        size;
    uint32_t        offset;
} __attribute__((packed)) idtr_t;

typedef struct {
    uint16_t        offset_low;
    uint16_t        segment_selector;

    uint8_t         reserved;
    uint8_t         flags;

    uint16_t        offset_high;
} __attribute__((packed)) idt_gate_descriptor_t;

extern idt_gate_descriptor_t idt[255];