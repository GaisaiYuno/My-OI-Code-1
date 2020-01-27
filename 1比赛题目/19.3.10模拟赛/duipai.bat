@echo off
:again
md.exe > input.txt
Bok.exe < input.txt> myans.txt
Btj.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again