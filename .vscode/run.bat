@echo off
rem build then run the exe, stdin stays attached to the terminal
if "%~1"=="" (
  echo usage: run.bat ^<source.cpp^>
  exit /b 2
)
call "%~dp0build.bat" "%~1"
if errorlevel 1 exit /b %errorlevel%
echo.
echo ---- run %~nx1 ----
"%~dpn1.exe"
exit /b %errorlevel%
