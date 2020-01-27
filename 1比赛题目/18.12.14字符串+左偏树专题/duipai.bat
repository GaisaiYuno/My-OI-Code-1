@echo off
:again
makedata.exe > input.txt
罗马游戏.exe < input.txt > myans.txt
罗马游戏题解.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
pause