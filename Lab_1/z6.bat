echo off
cls
echo -- params string: %*
echo -- mode: %1
echo -- file name: %2


:: Справка при отсутствии параметров
if "%1" equ "" ( 
	echo ---+  %~n0 file mode
	echo ---++  mode = {create, delete}
	echo ---++  file  = file name
	goto EXIT
)

:: Первый параметр (delete, create)
if not "%1" equ "delete" if not "%1" equ "create" (
	echo ---+ mode set incorrectly
	goto EXIT
)
 
if "%1" equ "delete" if "%2" equ "" (
	echo ---+ file name not set
	goto EXIT
)

if "%1" equ "create" if "%2" equ "" (
	echo ---+ file name not set
	goto EXIT
)

:: Ошибка при отсутствии файла в режиме "удалить"
if "%1" equ "delete" if not exist "%2" (
	echo ---+ file %2 not found
	goto EXIT
)

:: Ошибка при существовании файла в режиме "создать"
if "%1" equ "create" if exist "%2" (
	echo ---+ file %2 already exists
	goto EXIT
)


if "%1" equ "создать" if "%2" equ "" (
	echo ---+ file name not set
	goto EXIT
)



:: Обработка верной команды создать
if "%1" equ "create" (
	copy NUL %2 >NUL
	echo ---+ file %2 created
)

:: Обработка верной команды удалить
if "%1" equ "delete" (
	del "%2"
	echo ---+ file %2 deleted
)



:EXIT
pause