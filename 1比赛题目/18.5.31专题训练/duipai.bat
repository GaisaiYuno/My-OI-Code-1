@echo off
:again
D:\杨培源\C++\18.5.31专题训练\makedata.exe >input.txt
D:\杨培源\C++\18.5.31专题训练\E.exe <input.txt>myans.txt
D:\杨培源\C++\18.5.31专题训练\正方形OK.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
pause 
