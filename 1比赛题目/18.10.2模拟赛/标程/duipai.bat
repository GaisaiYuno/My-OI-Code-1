@echo off
:again
makedata.exe >input.txt
aOK.exe <input.txt>myans.txt
a.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again