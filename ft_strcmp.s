section .text
    global  ft_strcmp

ft_strcmp:
    mov rax, -1

loop:
    inc rax
    mov cl, [rdi + rax]
    mov r8b, [rsi + rax]
    cmp cl, 0
    je end
    cmp r8b, 0
    je end
    cmp cl, r8b
    jne end
    jmp loop

end:
    sub r8b, cl
    movsx rax, r8b
    ret