@ECHO OFF
set /P Input=Enter some text:
:choice
set /P c=Wanna error? [Y/N]?
if /I "%c%" EQU "Y" goto :somewhere
if /I "%c%" EQU "N" goto :somewhere_else
goto :choice


:somewhere

clang-cl -Wall "%Input%".cpp
    "%Input%".exe
exit

:somewhere_else

clang-cl "%Input%".cpp
    "%Input%".exe
exit