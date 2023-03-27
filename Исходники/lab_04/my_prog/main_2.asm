PUBLIC read_symb

CODE_SEG2 SEGMENT para public 'CODE'
    ASSUME CS:CODE_SEG2
read_symb proc far 
    mov ah, 01h
    int 21h
	ret
read_symb endp
CODE_SEG2 ENDS
END