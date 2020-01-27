@echo off
:again
md.exe > input.txt
problem3.exe < input.txt > myans.txt
problem3ok.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again