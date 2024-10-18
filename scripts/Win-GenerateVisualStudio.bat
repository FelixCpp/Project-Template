@echo off
pushd %~dp0\..\
call tools\premake-5.0.0-beta2.exe vs2022 --file=Build.lua --os=windows
popd
PAUSE