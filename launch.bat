@echo off
title ROBCO Industries Terminal Launcher
color 0A

:menu
cls
echo ===============================================
echo    ROBCO INDUSTRIES TERMINAL LAUNCHER
echo ===============================================
echo.
echo 1. Compile and Run Program
echo 2. Compile Only
echo 3. Run Existing Program
echo 4. Clean Build Files
echo 5. Exit
echo.
set /p choice="Select an option (1-5): "

if "%choice%"=="1" goto compile_and_run
if "%choice%"=="2" goto compile_only
if "%choice%"=="3" goto run_only
if "%choice%"=="4" goto clean
if "%choice%"=="5" goto exit
goto menu

:compile_and_run
echo.
echo Compiling program...
g++ -o program main.cpp program.cpp
if %errorlevel% neq 0 (
    echo.
    echo Compilation failed! Check for errors above.
    pause
    goto menu
)
echo Compilation successful!
echo.
echo Starting ROBCO Industries Terminal...
echo.
program
pause
goto menu

:compile_only
echo.
echo Compiling program...
g++ -o program main.cpp program.cpp
if %errorlevel% neq 0 (
    echo.
    echo Compilation failed! Check for errors above.
) else (
    echo Compilation successful!
)
pause
goto menu

:run_only
if not exist program.exe (
    echo.
    echo Program not found! Please compile first.
    pause
    goto menu
)
echo.
echo Starting ROBCO Industries Terminal...
echo.
program
pause
goto menu

:clean
echo.
echo Cleaning build files...
if exist program.exe del program.exe
if exist program del program
echo Build files cleaned!
pause
goto menu

:exit
echo.
echo Goodbye!
exit /b 0
