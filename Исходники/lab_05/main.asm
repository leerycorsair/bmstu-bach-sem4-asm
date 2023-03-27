STACK_SEG SEGMENT para STACK 'STACK'
	db 100 dup(0)
STACK_SEG ENDS

MTR_SEG SEGMENT para public 'DATA'
	ROWS db 1
	COLUMNS db 1
	MATRIX db 81 dup(0)
MTR_SEG ENDS

CODE_SEG SEGMENT para public 'CODE'
	assume CS:CODE_SEG, SS:STACK_SEG, DS: MTR_SEG

new_line proc near
	mov ah, 02h
    mov dl, 0ah
    int 21h
    mov dl, 0dh
    int 21h
	ret
new_line endp

add_space proc near
	mov ah, 02h
	mov dl, " "
	int 21h
	ret
add_space endp

suc_msg proc near
	mov ah, 02h
    mov dl, "O"
    int 21h
    mov dl, "K"
    int 21h
	ret
suc_msg endp

new_line1:
	call new_line
	jmp rm
new_line2:
	call new_line
	jmp pm
new_max:
	mov bx, di
	mov dl, MATRIX[bx]
	jmp mh

main:
	mov ax, MTR_SEG
	mov ds, ax

	mov ah, 01h
	int 21h
	sub al, "0"
	mov ROWS, al

	call add_space

	mov ah, 01h
	int 21h
	sub al, "0"
	mov COLUMNS, al

	call new_line

	mov al, ROWS
    mul COLUMNS
    mov cx, ax
	mov si, 0
	read_matrix:
		mov ah, 01h
		int 21h
		mov MATRIX[si], al
		inc si

		call add_space

		mov ax, si
		mov bl, COLUMNS
		div bl

		cmp ah, 0
		je new_line1
		rm:
		loop read_matrix
	
	mov cl, COLUMNS
	mov di, 0 
	matrix_handling:
		mov si, 0
		mov bx, si
		add bx, di
		mov dl, MATRIX[bx]
		mov dh, cl
		mov cl, ROWS
		column:
			mov ax, di
			add di, si
			cmp MATRIX[di],dl
			jge new_max
			mh:
			sub di, si
			mov ax, si
			add al, COLUMNS
			mov si, ax
			loop column
		
		mov ah, MATRIX[di]
		mov MATRIX[bx], ah
		mov MATRIX[di], dl

		mov cl, dh
		inc di
		loop matrix_handling

	call new_line

	mov al, ROWS
    mul COLUMNS
    mov cx, ax
	mov si, 0
	print_matrix:
		mov ah, 02h
		mov dl, MATRIX[si]
		int 21h
		inc si

		call add_space

		mov ax, si
		mov bl, COLUMNS
		div bl

		cmp ah, 0
		je new_line2
		pm:
		loop print_matrix

	call suc_msg

	mov ah, 4ch
	mov al, 0
    int 21h

CODE_SEG ENDS
END main