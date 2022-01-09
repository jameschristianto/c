cls
@echo off

set option=%1

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

if %option%.==/r. (
	start bin\Debug\"Hash Table.exe"
) else (
	goto end
)

:end
pause