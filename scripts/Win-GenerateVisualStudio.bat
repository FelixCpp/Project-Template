@echo off
pushd %~dp0\..\
call Premake\bin\premake-5.0.0-beta2.exe vs2022 --file=Build.lua --os=windows
popd
PAUSE