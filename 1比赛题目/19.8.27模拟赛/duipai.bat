@echo off
:again
Bmd.exe > input.txt
B.exe < input.txt > myans.txt
B2.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again