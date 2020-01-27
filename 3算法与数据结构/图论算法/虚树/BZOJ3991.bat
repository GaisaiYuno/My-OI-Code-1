@echo off
:again
BZOJ3991md.exe > input.txt 
BZOJ3991.exe <input.txt>myans.txt
BZOJ3991tj.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again