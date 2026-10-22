@echo off
rem ---------------------------------------------------------------
rem  Visual Studio (MSVC 14.51 x64) single-file build
rem  VS  : F:\<custom folder>     SDK : F:\Windows Kits\10
rem  Paths are hard-coded on purpose: this Visual Studio was moved to a
rem  custom folder and never registered, so vswhere / vcvars64.bat cannot
rem  find it or its Windows SDK.
rem
rem  usage: build.bat <source.cpp>          quick build (small exe)
rem         build.bat <source.cpp> dbg      build with debug symbols
rem ---------------------------------------------------------------
set "MSVC=F:\新建文件夹\VC\Tools\MSVC\14.51.36231"
set "SDKINC=F:\Windows Kits\10\Include\10.0.26100.0"
set "SDKLIB=F:\Windows Kits\10\Lib\10.0.26100.0"
set "PATH=%MSVC%\bin\Hostx64\x64;F:\Windows Kits\10\bin\10.0.26100.0\x64;%PATH%"
set "INCLUDE=%MSVC%\include;%SDKINC%\ucrt;%SDKINC%\shared;%SDKINC%\um;%SDKINC%\winrt"
set "LIB=%MSVC%\lib\x64;%SDKLIB%\ucrt\x64;%SDKLIB%\um\x64"

if "%~1"=="" (
  echo usage: build.bat ^<source.cpp^> [dbg]
  exit /b 2
)
if /i "%~2"=="dbg" goto :dbg

cl /nologo /EHsc /std:c++17 /utf-8 /MT /O2 /W3 /Fo:"%~dpn1.obj" /Fe:"%~dpn1.exe" "%~1"
set "RC=%errorlevel%"
if "%RC%"=="0" if exist "%~dpn1.obj" del /q "%~dpn1.obj"
exit /b %RC%

:dbg
cl /nologo /EHsc /std:c++17 /utf-8 /MT /Od /Zi /W3 /Fd:"%~dpn1.pdb" /Fo:"%~dpn1.obj" /Fe:"%~dpn1.exe" "%~1"
set "RC=%errorlevel%"
if "%RC%"=="0" if exist "%~dpn1.obj" del /q "%~dpn1.obj"
exit /b %RC%
