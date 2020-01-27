@echo off
:again
makedata2.exe >input2.txt
C2.exe <input2.txt> myans2.txt
bf.exe <input2.txt> rightans.txt
fc myans2.txt rightans.txt
if not errorlevel 1 goto again
