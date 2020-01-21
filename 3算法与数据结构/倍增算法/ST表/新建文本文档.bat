@echo off
:again
H:\C++\倍增\ST表\makedata.exe >input.txt
H:\C++\倍增\ST表\POJ3368.exe <input.txt> myans.txt
H:\C++\倍增\ST表\force.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
