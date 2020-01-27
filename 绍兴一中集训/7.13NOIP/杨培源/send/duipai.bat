@echo off
:again
md.exe > input.txt
send.exe < input.txt > myans.txt
send2.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again