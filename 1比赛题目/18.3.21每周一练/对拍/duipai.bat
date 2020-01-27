@echo off
:again
D:\ÁõÈµÁá\C++\¶ÔÅÄ\makedata.exe >input.txt
D:\ÁõÈµÁá\C++\¶ÔÅÄ\B.exe <input.txt>myans.txt
D:\ÁõÈµÁá\C++\¶ÔÅÄ\Bok.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again