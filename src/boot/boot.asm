MB_MAGIC        equ 0x1BADB002
MB_MMAP_FLAG    equ 1 << 1
MB_ALIGN_FLAG   equ 1 << 0
MB_FLAGS        equ MB_ALIGN_FLAG | MB_MMAP_FLAG
MB_CHECKSUM     equ -(MB_MAGIC + MB_FLAGS)

section .multiboot
align   4

    dd          MB_MAGIC
    dd          MB_FLAGS
    dd          MB_CHECKSUM

; According to System V ABI standards, the stack must be aligned to 16-bits
section .bss
align   16

stack_bottom:
    resb        16384                           ; Reserve 16 KiB for the stack
stack_top:

section .text
global _start:function (_start.end - _start)    ; Export _start so the linker sees it
_start:

    mov esp,    stack_top                       ; Make ESP point to the top of the stack

    ; Setup some essential things like the GDT here
    ; Jump to kernel main
    extern      krnlmain
    jmp         krnlmain
    cli

.halt:
    hlt
    jmp         .halt
.end: