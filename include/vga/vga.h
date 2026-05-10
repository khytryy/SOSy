#pragma once

#include <stdint.h>
#include <stddef.h>

#include <common/common.h>

typedef enum {
	VGA_COLOR_BLACK             = 0,
	VGA_COLOR_BLUE              = 1,
	VGA_COLOR_GREEN             = 2,
	VGA_COLOR_CYAN              = 3,
	VGA_COLOR_RED               = 4,
	VGA_COLOR_MAGENTA           = 5,
	VGA_COLOR_BROWN             = 6,
	VGA_COLOR_LIGHT_GREY        = 7,
	VGA_COLOR_DARK_GREY         = 8,
	VGA_COLOR_LIGHT_BLUE        = 9,
	VGA_COLOR_LIGHT_GREEN       = 10,
	VGA_COLOR_LIGHT_CYAN        = 11,
	VGA_COLOR_LIGHT_RED         = 12,
	VGA_COLOR_LIGHT_MAGENTA     = 13,
	VGA_COLOR_LIGHT_BROWN       = 14,
	VGA_COLOR_WHITE             = 15
} vga_color_t;

#define VGA_WIDTH   80
#define VGA_HEIGHT  25
#define VGA_MEMORY  0xB8000

extern uint16_t*    vga_buffer;

extern size_t       vga_row;
extern size_t       vga_column;

extern uint8_t      vga_draw_color;

void vga_init();

void vga_set_draw_color(vga_color_t fg, vga_color_t bg);
void vga_set_text_color(vga_color_t color);

void vga_putc_pro(char c, uint8_t color, size_t x, size_t y);
void vga_putc(char c);

void vga_write(char* data, size_t size);
void vga_write_str(char* str);