@echo off
:again
md.exe > input.txt
C.exe < input.txt > myans.txt
echo ok!!!
goto again