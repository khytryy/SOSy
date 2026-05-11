#include <vga/vga.h>
#include <debug/debug.h>

#include <multiboot2/mutiboot2.h>

#if defined(__linux)
#warning "You're not using a cross-compiler. It's strongly recommended to use a cross-compiler when building SOSy"
#endif

#if !defined(__i386)
#warning "It is recommended to use a ixx86-elf compiler when building SOSy"
#endif

void krnlmain(multiboot_info_t* info, unsigned int magic) {
    vga_init();

    vga_write_str("Multiboot2 magic: 0x");

    char buffer[digits_of_int(magic) + 2];
    vga_write_str(itoa(magic, buffer, 16));

    vga_putc('\n');
}