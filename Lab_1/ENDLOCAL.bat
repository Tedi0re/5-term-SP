@echo off
set var=1
echo %var%
setlocal
set var=2
echo %var%
endlocal
echo %var%