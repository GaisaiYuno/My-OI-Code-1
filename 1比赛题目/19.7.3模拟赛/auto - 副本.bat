@echo off
:again
makedata.exe > input.txt
D.exe < input.txt > myans.txt
echo "ok!!!"
if not errorlevel 1 goto again