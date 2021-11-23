@echo off
echo %1
del %1.exe
g++ %1.cpp -g -o %1
.\%1