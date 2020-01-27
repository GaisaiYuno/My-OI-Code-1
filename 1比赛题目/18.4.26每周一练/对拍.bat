@echo off
:again
D:\杨培源\C++\18.4.26每周一练\makedata.exe >input.txt
D:\杨培源\C++\18.4.26每周一练\E.exe <input.txt>myans.txt
D:\杨培源\C++\18.4.26每周一练\E对拍.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
pause
