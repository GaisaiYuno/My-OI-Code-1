@echo off
:again
makedata.exe >input.txt
defence.exe <input.txt> myans.txt
duipai.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again