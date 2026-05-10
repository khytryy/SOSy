#include <vga/vga.h>

uint16_t*    vga_buffer = (uint16_t* )VGA_MEMORY;

size_t       vga_row;
size_t       vga_column;

uint8_t      vga_draw_color;

void vga_init() {
    vga_row         = 0;
    vga_column      = 0;

    vga_draw_color  = VGA_COLOR_WHITE | VGA_COLOR_BLACK << 4;
}

void vga_set_draw_color(vga_color_t fg, vga_color_t bg) {
    vga_draw_color  = fg | bg << 4;
}

void vga_set_text_color(vga_color_t color) {
    vga_draw_color  = color;
}

void vga_putc_pro(char c, uint8_t color, size_t x, size_t y) {
    const size_t i = y * VGA_WIDTH + x;
    vga_buffer[i] = (uint16_t)c | (uint16_t)color << 8;
}

void vga_putc(char c) {
    if (c == '\n') {
        vga_column = 0;
        if (++vga_row == VGA_HEIGHT)
            vga_row = 0;
        return;
    }
    vga_putc_pro(c, vga_draw_color, vga_column, vga_row);

    if (++vga_column == VGA_WIDTH) {
        vga_column = 0;
        if (++vga_row == VGA_HEIGHT)
            vga_row = 0;
    }
}

void vga_write(char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        vga_putc(data[i]);
}

void vga_write_str(char* str) {
    vga_write(str, strlen(str));
}