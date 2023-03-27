EXTRN read_symb: far

STACK_SEG SEGMENT para STACK 'STACK'
	db 100 dup(0)
STACK_SEG ENDS


CODE_SEG1 SEGMENT para public 'CODE'
    ASSUME CS:CODE_SEG1, SS:STACK_SEG

main:
    call read_symb

    mov ah, 02h

    add al, 32
    mov dl, al
    int 21h
    
    mov ax, 4c00h
	int 21h

CODE_SEG1 ENDS

END main