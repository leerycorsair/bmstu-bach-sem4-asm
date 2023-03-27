.386
.model flat, stdcall
option casemap :none

include \masm32\include\windows.inc
include \masm32\macros\macros.asm
uselib kernel32, user32, masm32, comctl32
 
WndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD

MAINWINDOW = 1000
N1_ENT = 1001
N2_ENT = 1002
SUM_BTN = 1005
SUB_BTN = 1006
MUL_BTN = 1007

.data 
  err db "Error", 0
  suc db "Success", 0
  str_containter db 256 dup (0)
  str_formatter db "Result = %d", 0

.data?
  hInstance dd ?
  hWnd dd ?
  icce INITCOMMONCONTROLSEX <>
  num1 dd ?
  num2 dd ?
  sum dd ?
  err_flag dd ?

.code
  start:
    mov icce.dwSize, SIZEOF INITCOMMONCONTROLSEX
    mov icce.dwICC, ICC_DATE_CLASSES or \
                    ICC_INTERNET_CLASSES or \
                    ICC_PAGESCROLLER_CLASS or \
                    ICC_COOL_CLASSES

    invoke InitCommonControlsEx, offset icce
    invoke GetModuleHandle, NULL
    mov hInstance, eax

    invoke DialogBoxParam, hInstance, MAINWINDOW, 0, offset WndProc, 0
    invoke ExitProcess,eax

WndProc proc hWin :DWORD, uMsg :DWORD, wParam :DWORD, lParam :DWORD
  switch uMsg
    case WM_INITDIALOG
      invoke SendMessage, hWin, WM_SETICON, 1, FUNC(LoadIcon, NULL, IDI_ASTERISK)
    case WM_COMMAND     
      switch wParam
        case SUM_BTN
          invoke GetDlgItemInt, hWin, N1_ENT, offset err_flag, TRUE
          .if !err_flag
            invoke MessageBox, hWin, chr$("The first number is incorrect."), offset err, MB_ICONEXCLAMATION
            xor eax, eax
            ret
          .endif
          mov num1, eax
          invoke GetDlgItemInt, hWin, N2_ENT, offset err_flag, TRUE
          .if !err_flag
            invoke MessageBox, hWin, chr$("The second number is incorrect."), offset err, MB_ICONEXCLAMATION
            xor eax, eax
            ret
          .endif
          mov num2, eax
          mov eax, num1
          add eax, num2
          invoke wsprintf, addr str_containter, addr str_formatter, eax
          invoke MessageBox, hWin, addr str_containter, addr suc, MB_ICONEXCLAMATION
        case SUB_BTN
          invoke GetDlgItemInt, hWin, N1_ENT, offset err_flag, TRUE
          .if !err_flag
            invoke MessageBox, hWin, chr$("The first number is incorrect."), offset err, MB_ICONEXCLAMATION
            xor eax, eax
            ret
          .endif
          mov num1, eax
          invoke GetDlgItemInt, hWin, N2_ENT, offset err_flag, TRUE
          .if !err_flag
            invoke MessageBox, hWin, chr$("The second number is incorrect."), offset err, MB_ICONEXCLAMATION
            xor eax, eax
            ret
          .endif
          mov num2, eax
          mov eax, num1
          sub eax, num2
          invoke wsprintf, addr str_containter, addr str_formatter, eax
          invoke MessageBox, hWin, addr str_containter, addr suc, MB_ICONEXCLAMATION
        case MUL_BTN
          invoke GetDlgItemInt, hWin, N1_ENT, offset err_flag, TRUE
          .if !err_flag
            invoke MessageBox, hWin, chr$("The first number is incorrect."), offset err, MB_ICONEXCLAMATION
            xor eax, eax
            ret
          .endif
          mov num1, eax
          invoke GetDlgItemInt, hWin, N2_ENT, offset err_flag, TRUE
          .if !err_flag
            invoke MessageBox, hWin, chr$("The second number is incorrect."), offset err, MB_ICONEXCLAMATION
            xor eax, eax
            ret
          .endif
          mov num2, eax
          mov eax, num1
          mul num2
          invoke wsprintf, addr str_containter, addr str_formatter, eax
          invoke MessageBox, hWin, addr str_containter, addr suc, MB_ICONEXCLAMATION
      endsw
    case WM_CLOSE
      exit_program:
      invoke EndDialog, hWin, 0
    endsw
  xor eax,eax
ret
WndProc ENDP
end start