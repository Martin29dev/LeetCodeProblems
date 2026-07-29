@echo off
setlocal

:: Zapisujemy katalog, z którego uruchomiono skrypt
pushd "%~dp0.."

:: 1. Znajdź ścieżkę do instalacji Visual Studio za pomocą vswhere
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

if not exist "%VSWHERE%" (
    echo [BLAD] Nie znaleziono vswhere.exe. Upewnij sie, ze Visual Studio jest zainstalowane.
    popd
    pause
    exit /b 1
)

for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
    set "VS_PATH=%%i"
)

if not defined VS_PATH (
    echo [BLAD] Nie znaleziono narzedzi Visual C++.
    popd
    pause
    exit /b 1
)

:: 2. Inicjalizacja środowiska MSVC dla wersji 32-bitowej (x86)
call "%VS_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x86

:: 3. Utworzenie folderu bin na pliki wykonywalne i obiektowe
if not exist "bin" mkdir "bin"

:: 4. Kompilacja pliku main.cpp
cl.exe /O2 /EHsc /W4 /std:c++17 src\main.cpp /Fe:bin\main.exe /Fo:bin\

if %ERRORLEVEL% equ 0 (
    echo.
    echo [SUKCES] Kompilacja zakonczona! Uruchamianie...
    echo ------------------------------------------------
    bin\main.exe
    echo ------------------------------------------------
) else (
    echo.
    echo [BLAD] Kompilacja nie powiodla sie.
)

:: Powrót do folderu, z którego skrypt został wywołany (np. compilationScripts)
popd