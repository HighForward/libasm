section .text
    global ft_strdup
    extern ft_strlen
    extern malloc

ft_strdup:
    mov rax, 0
    call ft_strlen
    inc rax
    mov rbx, rax
    push rbx
    call malloc
    cmp rax, 0
    je error
    mov r8, rax
    mov rax, -1
    jmp loop

loop:
    inc rax
    mov cl, [rdi + rax]
    cmp cl, 0
    jmp end
    je end
    mov [r8 + rax], cl
    jmp loop

end:
    mov rax, r8
    ret

error:
    ret