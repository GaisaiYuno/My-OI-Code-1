@echo off
:again
makedata.exe >input.txt
校门外的区间.exe <input.txt>rightans.txt
校门外的区间OK.exe <input.txt>myans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again