@echo off
:again
makedata.exe > input.txt
D.exe < input.txt > myans.txt
Dbf.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again