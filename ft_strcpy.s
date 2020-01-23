section .text
    global _ft_strcpy

_ft_strcpy:
    mov rax, -1

loop:
    inc rax
    mov cl, [rsi + rax]
    mov r8b, [rdi + rax]
    cmp cl, 0
    je end
    mov [rdi + rax], cl
    jmp loop

end:
    mov cl, 0
    mov [rdi + rax], cl
    mov rax, rdi
    ret
