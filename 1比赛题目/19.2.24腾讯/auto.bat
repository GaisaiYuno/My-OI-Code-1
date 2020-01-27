@echo off
:again
makedata.exe > input.txt
B.exe < input.txt> myans.txt
echo ok!
goto again