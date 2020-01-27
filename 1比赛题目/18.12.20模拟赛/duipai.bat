@echo off
:again
makedata.exe >input.txt
T3ok.exe <input.txt>myans.txt
T3bf.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again