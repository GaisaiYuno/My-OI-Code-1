@echo off
:again
md.exe > input.txt
problem2.exe < input.txt > myans.txt
tj.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again