@echo off
mkdir build
pushd build
cl -Zi /EHsc ..\src\main.cpp
popd