@echo off
:again
md.exe > input.txt
sort.exe < input.txt > myans.txt
sortbf.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again