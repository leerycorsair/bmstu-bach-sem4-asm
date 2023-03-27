global my_strncpy
section .text

; rdi - a destination string
; rsi - a source string
; rdx - copy length

my_strncpy:
    mov rcx, rdx

    cmp rsi, rdi
    je quit
    jl reverse_copy
    jg normal_copy
 
reverse_copy:
    add rsi, rdx
    add rdi, rdx

reverse_loop:
    dec rsi
    dec rdi
    mov al, [rsi]
    mov [rdi], al
    loop reverse_loop
    jmp quit

normal_copy:
normal_loop:
    mov al, [rsi]
    mov [rdi], al
    inc rsi
    inc rdi
    loop normal_loop
    jmp quit

quit:
    ret
    