@echo off
makedata.exe¡¡> input.txt
my.exe <input.txt>myans.txt
right.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again