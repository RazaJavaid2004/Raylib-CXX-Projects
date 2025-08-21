@echo off
setlocal EnableExtensions EnableDelayedExpansion

rem Always operate from the script directory
pushd "%~dp0"

rem Usage: build.bat [Debug|Release] [norun]
set CONFIG=%1
if "%CONFIG%"=="" set CONFIG=Release
set NORUN=%2

set BUILD_DIR=build
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

set "SRC_FILES="
for %%f in (src\*.cpp) do (
    call set "SRC_FILES=%%SRC_FILES%% %%f"
)

set CXX=g++
set CXXFLAGS=-std=c++17 -Iinclude -Wall -Wextra -Wno-unused-parameter
if /I "%CONFIG%"=="Debug" (
    set CXXFLAGS=%CXXFLAGS% -g -O0 -DDEBUG
) else (
    set CXXFLAGS=%CXXFLAGS% -O2 -DNDEBUG
)

rem If RAYLIB_DIR is set, add its include/lib dirs
set LDFLAGS=
if defined RAYLIB_DIR (
    set CXXFLAGS=%CXXFLAGS% -I"%RAYLIB_DIR%\include"
    set LDFLAGS=-L"%RAYLIB_DIR%\lib"
)

rem Link libraries (Windows)
set LIBS=-lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 -luser32

set OUT=%BUILD_DIR%\BouncingBall.exe

echo Building %CONFIG%...
echo %CXX% %CXXFLAGS% src\*.cpp -o "%OUT%" %LDFLAGS% %LIBS%
%CXX% %CXXFLAGS% %SRC_FILES% -o "%OUT%" %LDFLAGS% %LIBS%
if errorlevel 1 (
    echo.
    echo Build failed. Ensure g++ is on PATH and raylib is installed.
    echo If raylib is not in default search paths, set RAYLIB_DIR to its root (has include\ and lib\).
    echo   Example: set RAYLIB_DIR=C:\raylib\mingw-w64
    echo Or use CMake: cmake -S . -B build && cmake --build build --config %CONFIG%
    pause
    popd
    exit /b 1
)

echo Build succeeded: "%OUT%"
if /I not "%NORUN%"=="norun" (
    echo.
    echo Running...
    pushd "%BUILD_DIR%"
    BouncingBall.exe
    popd
    pause
)

popd
pause
exit /b 0