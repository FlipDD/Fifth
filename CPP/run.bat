@ECHO OFF
set /P Input=Enter the name to the file:

if "%Input%"=="%Input: =%" goto :normal
if not "%Input%"=="%Input: =%" goto :errors

:normal

clang-cl "%Input%".cpp 
    "%Input%".exe
exit

:errors

clang-cl -Wall "%Input:~0,-1%".cpp 
    "%Input:~0,-1%".exe
exit