@echo off
:again
G:\C++\18.3.28ÿ��һ��\makedata.exe >in.txt
G:\C++\18.3.28ÿ��һ��\C-zyd.exe <in.txt> zydans.txt
G:\C++\18.3.28ÿ��һ��\C2.exe <in.txt> rightans.txt
fc zydans.txt rightans.txt
if not errorlevel 1 goto again 
pause
