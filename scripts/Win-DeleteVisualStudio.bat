@echo off
setlocal

:: Delete all Files recursively with the following extensions:
	:: .sln
	:: .vcxproj
	:: .vcxproj.filters

pushd %~dp0\..\

echo Deleting *.sln files ...
for /r %%i in (*.sln) do (
	del "%%i"
)

echo Deleting *.vcxproj files ...
for /r %%i in (*.vcxproj) do (
	del "%%i"
)

echo Deleting *.vcxproj.filters files ...
for /r %%i in (*.vcxproj.filters) do (
	del "%%i"
)

:: Delete the build directory
echo Deleting build directory ...
rmdir /s /q build

popd