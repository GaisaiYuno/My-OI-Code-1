@echo off
:again
makedata.exe >input.txt
У���������.exe <input.txt>rightans.txt
У���������OK.exe <input.txt>myans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again