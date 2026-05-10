ENTRY(_start)

SECTIONS {
    . = 2M;

    /* Align everything to a page */
    /* Our multiboot header and code */
    .text BLOCK(4K) : ALIGN(4K) {
        /* The multiboot header must be on top, or else GRUB will not recognize the file format */
        *(.multiboot)
        *(.text)
    }

    /* Read-only data */
    .rodata BLOCK(4K) : ALIGN(4K) {
        *(.rodata)
    }

    /* Read-write data (initialized) */
    .data BLOCK(4K) : ALIGN(4K) {
        *(.data)
    }

    /* Read-write data (zero initialized) and unitialized data */
    .bss BLOCK(4K) : ALIGN(4K) {
        *(COMMON)
        *(.bss)
    }
}