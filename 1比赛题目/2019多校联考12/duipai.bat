@echo off
:again
Amd.exe > input.txt
A.exe < input.txt > myans.txt
Abf.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again