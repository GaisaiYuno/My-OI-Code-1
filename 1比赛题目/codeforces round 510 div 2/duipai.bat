@echo off
:again
makedata.exe >input.txt
A.exe <input.txt>myans.txt
A2.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again