@echo off
:again
makedata.exe > input.txt
������Ϸ.exe < input.txt > myans.txt
������Ϸ���.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
pause