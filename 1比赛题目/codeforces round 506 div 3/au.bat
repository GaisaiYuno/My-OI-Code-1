@echo off
:again
makedata.exe >input.txt
B.exe <input.txt>myans.txt
Bright.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again