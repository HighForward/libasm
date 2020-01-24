section .text
    global ft_list_push_front
    extern malloc

ft_list_push_front:
    mov rax, 0
    push rdi
    push rsi
    mov rdi, 16
    mov rax, 0
    call malloc
    pop rsi
    pop rdi
    mov rax, 0
    ret