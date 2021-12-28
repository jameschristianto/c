cls
@echo off

echo **************************************************
echo COMPILE START
echo **************************************************

echo compiling...
mingw32-make -f makefile.mk

echo **************************************************
echo COMPILE FINISH
echo **************************************************

if not exist bin\Debug mkdir bin\Debug
if not exist obj\Debug mkdir obj\Debug

copy *.exe bin\Debug
copy *.o obj\Debug

del *.exe
del *.o

:runApp
echo Do you want to run app?
set /p option="[y/n]:"
if %option%.==y. (
	start bin\Debug\"Trim.exe"
) else if %option%.==n. (
	goto end
) else (
	echo wrong input
	goto runApp
)

:end
pause