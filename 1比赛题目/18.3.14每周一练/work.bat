@echo off
:again
G:\C++\18.3.14ÿ��һ��\makedata.exe > input.txt
G:\C++\18.3.14ÿ��һ��\A.exe <input.txt> myans.txt  
G:\C++\18.3.14ÿ��һ��\A����.exe <input.txt> rightans.txt
fc myans.txt rightans.txt >nul
if not errorlevel 1 goto again