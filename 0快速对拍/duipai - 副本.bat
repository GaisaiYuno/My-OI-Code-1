@echo off
:again
md.exe > input.txt
my.exe < input.txt > myans.txt
type myans.txt
if not errorlevel 1 goto again