@echo off
:again
G:\C++\18.3.21billy������\duipai.exe >input.txt
G:\C++\18.3.21billy������\C.exe <input.txt> myans.txt
G:\C++\18.3.21billy������\test.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again

