@echo off
setlocal

set "PREMAKE_VERSION=5.0.0-beta2"
set "PREMAKE_URL=https://github.com/premake/premake-core/releases/download/v%PREMAKE_VERSION%/premake-%PREMAKE_VERSION%-windows.zip"
set "PREMAKE_ZIP=premake-%PREMAKE_VERSION%-windows.zip"
set "PREMAKE_EXE=premake-%PREMAKE_VERSION%.exe"
set "PREMAKE_DIR=premake5"
set "DOWNLOAD_DIR=%~dp0\..\Premake\bin"

:: Check if premake5 is installed
if exist "%DOWNLOAD_DIR%/%PREMAKE_EXE%" (
	echo Premake is already installed.
	call %DOWNLOAD_DIR%/%PREMAKE_EXE% --version
	exit /b
)

echo Premake5 is not installed or not available in the PATH.

:: Check if the download directory exists
if not exist %DOWNLOAD_DIR% (
	mkdir %DOWNLOAD_DIR%
)

:: Change to the download directory
cd /d %DOWNLOAD_DIR%

:: Download the zip file
echo Downloading Premake5...
powershell -Command "Invoke-WebRequest -Uri '%PREMAKE_URL%' -OutFile '%PREMAKE_ZIP%'"

:: Check if download was successful
if %ERRORLEVEL% NEQ 0 (
	echo Download failed.
	exit /b 1
)

echo Download successful. Unpacking zip...
powershell -Command "Expand-Archive -Path '%PREMAKE_ZIP%' -DestinationPath '%PREMAKE_DIR%' -Force"

:: Check if unpacking was successful
if %ERRORLEVEL% NEQ 0 (
	echo Unpacking failed.
	exit /b 1
)

echo Unpacking successful.

:: Copy the premake5.exe to the tools directory
copy "%PREMAKE_DIR%\premake5.exe" "%PREMAKE_EXE%"

:: Delete the zip file without asking for permission
del /f /q "%PREMAKE_ZIP%"

:: Delete the extracted directory without asking for permission
rmdir /s /q "%PREMAKE_DIR%"