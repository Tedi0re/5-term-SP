rem oaoaoa
@echo off

set var=0

:MARK
set /A var=%var%+1
if %var% gtr 3 (
	GOTO ENDFILE
) ELSE (
	ECHO %var%
	GOTO MARK
)
:ENDFILE
