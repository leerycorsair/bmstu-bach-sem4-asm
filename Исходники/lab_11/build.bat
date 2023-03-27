@echo off

if not exist interface.rc goto over1
\masm32\bin\rc /v interface.rc
\masm32\bin\cvtres /machine:ix86 interface.res
 :over1
 
if exist "main.obj" del "main.obj"
if exist "main.exe" del "main.exe"

\masm32\bin\ml /c /coff "main.asm"
if errorlevel 1 goto errasm

if not exist interface.obj goto nores

\masm32\bin\Link /SUBSYSTEM:WINDOWS "main.obj" interface.res
 if errorlevel 1 goto errlink

dir "main.*"
goto TheEnd

:nores
 \masm32\bin\Link /SUBSYSTEM:WINDOWS "main.obj"
 if errorlevel 1 goto errlink
dir "main.*"
goto TheEnd

:errlink
 echo _
echo Link error
goto TheEnd

:errasm
 echo _
echo Assembly Error
goto TheEnd

:TheEnd
 
pause
