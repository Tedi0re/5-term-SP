:: %0 - имя файл сценария(с полным путем и расширением)
:: %~n0 - файл сценария(чисто имя без пути и расширения)
:: %~t0 - файл сценария(чисто время создания/изменения)
:: %~dpnx0 - для получения полного пути к файлу сценария вместе с его именем и расширением(без кавычек))
:: %~d0 Диск, на котором находится файл
:: %~p0 Путь к файлу (без имени файла)
:: %~x0 Расширение файла


@echo off
cls

:: Получение информации о файле сценария
for %%A in ("%~dpnx0") do (
  set "FilePath=%%~fA"
  set "FileName=%%~nA"
)

:: Получение даты и времени создания файла
for /f "tokens=1-2" %%B in ('dir /tc "%FilePath%" ^| find "%FileName%"') do (
  set "FileCreateDateDate=%%B"
  set "FileCreateTime=%%C"
)

echo --File name:     %FileName%
echo --File created date:  %FileCreateDateDate%
echo --File created time:  %FileCreateTime%
echo --File path:     %FilePath%
pause
