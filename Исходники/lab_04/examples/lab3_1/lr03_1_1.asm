EXTRN output_X: near ; Объявление внешнего идентификатора, тип перехода ближний (2 байта)

STK SEGMENT PARA STACK 'STACK' 	; Определение сегмента стека размером 100 байт,
	db 100 dup(0)				; инициализированного нулями.
STK ENDS

DSEG SEGMENT PARA PUBLIC 'DATA' ; Определение сегмента данных
	X db 'R'
DSEG ENDS

CSEG SEGMENT PARA PUBLIC 'CODE'	; Определение сегмента кода
	assume CS:CSEG, DS:DSEG, SS:STK
main:
	mov ax, DSEG
	mov ds, ax

	call output_X	; Вызов фукнции 

	mov ax, 4c00h
	int 21h
CSEG ENDS

PUBLIC X ; Объявление индентификатора, доступного внешним модулям

END main