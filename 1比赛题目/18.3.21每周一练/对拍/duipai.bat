@echo off
:again
D:\��ȵ��\C++\����\makedata.exe >input.txt
D:\��ȵ��\C++\����\B.exe <input.txt>myans.txt
D:\��ȵ��\C++\����\Bok.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again