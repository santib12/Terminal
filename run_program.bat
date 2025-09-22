@echo off
title ROBCO Industries Terminal
echo Compiling program...
g++ -o program main.cpp program.cpp
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b 1
)
echo Compilation successful!
echo Starting ROBCO Industries Terminal...
echo.
program
pause
