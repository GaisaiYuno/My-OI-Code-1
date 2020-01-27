@echo off
:again
BZOJ2599md.exe > input.txt 
BZOJ2599.exe <input.txt>myans.txt
BZOJ2599tj.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again