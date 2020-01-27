@echo off
:again
Cmd.exe > input.txt
Cok.exe < input.txt > myans.txt
Cbf.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again