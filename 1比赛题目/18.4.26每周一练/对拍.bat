@echo off
:again
D:\����Դ\C++\18.4.26ÿ��һ��\makedata.exe >input.txt
D:\����Դ\C++\18.4.26ÿ��һ��\E.exe <input.txt>myans.txt
D:\����Դ\C++\18.4.26ÿ��һ��\E����.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
pause
