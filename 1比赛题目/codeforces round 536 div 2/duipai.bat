@echo off
:again
makedata.exe > input.txt
B.exe <input.txt> myans.txt
yxcB.exe <input.txt> yxcans.txt
fc myans.txt yxcans.txt
if not errorlevel 1 goto again