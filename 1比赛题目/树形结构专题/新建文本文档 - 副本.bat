@echo off
:again
makedata2.exe >input.txt
Mok.exe <input.txt>rightans.txt
M.exe <input.txt>myans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again