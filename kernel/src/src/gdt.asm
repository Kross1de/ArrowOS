section .text
global load_gdt

load_gdt:
        mov rax, [rdi]
        lgdt [rax]
        ret
