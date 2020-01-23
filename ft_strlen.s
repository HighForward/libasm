section .text
	global _ft_strlen

_ft_strlen:
	mov rax, -1         ;rax = valeur de retour

loop:
    inc rax             ; incrementation de rax;
    mov cl, [rdi + rax] ; cl = 8 bits == 1 octet, rdi = premier argument
    cmp cl, 0           ; compare cl et 0
    je return           ; si cl == 0, go return
    jmp loop            ; sinon reloop

return:
	ret                 ; return