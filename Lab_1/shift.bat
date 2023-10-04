@echo off
call :sub1 A1 A2 A3 A4 A5 A6 A7 A8 A9 A10
pause
exit/b
REM Подпрограмма, которой передаются параметры A1…A10
:sub1
echo First parameter before shift - %1
:doshift
Shift
REM Обработка параметра
echo First parameter after shift - %1
REM проверка условия для завершения работы – после SHIFT, параметр %1 стал пустым.
if "%1"=="" goto endsub
goto doshift
:endsub
echo First parameter empty. End job.
exit/b