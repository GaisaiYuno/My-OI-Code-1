@echo off
:again
G:\C++\18.3.14每周一练\makedata.exe > input.txt
G:\C++\18.3.14每周一练\A.exe <input.txt> myans.txt  
G:\C++\18.3.14每周一练\A对拍.exe <input.txt> rightans.txt
fc myans.txt rightans.txt >nul
if not errorlevel 1 goto again