@echo off
g++ test.cpp -o test.exe -I"C:/msys64/ucrt64/include" -L"C:/msys64/ucrt64/lib" -lraylib -lglfw3 -lopengl32 -lgdi32 -lwinmm
if %errorlevel% neq 0 (
    echo Compilation failed.
) else (
    echo Running test.exe...
    test.exe
)
pause