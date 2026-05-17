global gdt_load

gdt_load:
    mov     eax,    [esp + 4]
    lgdt    [eax]
    ret