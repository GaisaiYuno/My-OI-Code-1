@echo off
:again
D:\����Դ\C++\18.6.14ÿ��һ��\makedata.exe >input.txt
D:\����Դ\C++\18.6.14ÿ��һ��\B.exe <input.txt>myans.txt
D:\����Դ\C++\18.6.14ÿ��һ��\Bduipai.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
pause