@echo off
:again
makedata.exe > input.txt
T5.exe < input.txt > myans.txt
T5ok.exe < input.txt > rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again