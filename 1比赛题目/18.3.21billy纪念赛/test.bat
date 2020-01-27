@echo off
:again
G:\C++\18.3.21billy纪念赛\duipai.exe >input.txt
G:\C++\18.3.21billy纪念赛\C.exe <input.txt> myans.txt
G:\C++\18.3.21billy纪念赛\test.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again

