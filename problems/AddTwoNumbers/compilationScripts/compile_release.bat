@echo off
setlocal

:: 1. Znajdź ścieżkę do instalacji Visual Studio za pomocą vswhere
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

if not exist "%VSWHERE%" (
    echo [BLAD] Nie znaleziono vswhere.exe. Upewnij sie, ze Visual Studio jest zainstalowane.
    pause
    exit /b 1
)

for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
    set "VS_PATH=%%i"
)

if not defined VS_PATH (
    echo [BLAD] Nie znaleziono narzedzi Visual C++.
    pause
    exit /b 1
)

:: 2. Inicjalizacja środowiska MSVC dla wersji 32-bitowej (x86)
call "%VS_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x86

:: 3. Przejście do głównego katalogu projektu (poziom wyżej niż compilationScripts)
cd /d "%~dp0.."

:: 4. Utworzenie folderu bin na pliki wykonywalne i obiektowe
if not exist "bin" mkdir "bin"

:: 5. Kompilacja pliku main.cpp
:: /O2 - optymalizacja pod kątem prędkości (Release)
:: /EHsc - standardowa obsługa wyjątków C++
:: /W4 - wysoki poziom ostrzeżeń
:: /std:c++17 - standard C++17 (możesz zmienić np. na /std:c++20)
cl.exe /O2 /EHsc /W4 /std:c++17 src\main.cpp /Fe:bin\main.exe /Fo:bin\

if %ERRORLEVEL% equ 0 (
    echo.
    echo [SUKCES] Kompilacja zakonczona! Plik wynikowy: bin\main.exe
) else (
    echo.
    echo [BLAD] Kompilacja nie powiodla sie.
)

pause