@echo off
:again
G:\C++\18.3.28ÿ��һ��\makedata.exe >in.txt
G:\C++\18.3.28ÿ��һ��\C.exe <in.txt> myans.txt
G:\C++\18.3.28ÿ��һ��\C2.exe <in.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again 
pause
