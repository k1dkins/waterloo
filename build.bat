@echo off
mkdir build
pushd build
cl -Zi /EHsc ..\main.cpp
popd