@echo off
:again
H:\C++\����\ST��\makedata.exe >input.txt
H:\C++\����\ST��\POJ3368.exe <input.txt> myans.txt
H:\C++\����\ST��\force.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
