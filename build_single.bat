@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Insiders\VC\Auxiliary\Build\vcvars64.bat" >NUL 2>&1
if %errorlevel% neq 0 exit /b %errorlevel%
cl.exe /Zi /EHsc /nologo /std:c++17 /Fe:%~dp0%1.exe %~dp0%1.cpp
