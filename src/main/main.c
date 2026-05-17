#include <vga/vga.h>
#include <debug/debug.h>

#include <multiboot2/mutiboot2.h>
#include <gdt/gdt.h>

#if defined(__linux)
#warning "You're not using a cross-compiler. It's strongly recommended to use a cross-compiler when building SOSy"
#endif

#if !defined(__i386)
#warning "It is recommended to use a ixx86-elf compiler when building SOSy"
#endif

void krnlmain(multiboot_info_t* info, unsigned int magic) {
    (void)info; // Not used for now

    vga_init();
    gdt_init();

    vga_write_str("Multiboot2 magic: 0x");

    char buffer[digits_of_int(magic) + 2];
    vga_write_str(itoa(magic, buffer, 16));

    vga_putc('\n');
    
    vga_set_text_color(VGA_COLOR_LIGHT_RED);
    vga_write_str("ERROR: Execution reached end of krnlmain");
}