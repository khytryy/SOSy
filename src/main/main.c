#include <vga/vga.h>

#if defined(__linux)
#warning "You're not using a cross-compiler. It's strongly recommended to use a cross-compiler when building SOSy"
#endif

#if !defined(__i386)
#warning "It is recommended to use a ixx86-elf compiler when building SOSy"
#endif

void krnlmain() {
    vga_init();

    vga_write_str("Krabba!\n");
    vga_write_str("Newlines!\n");
}