@echo off
:again
D:\—Ó≈‡‘¥\C++\codeforces\makedata.exe >input.txt
D:\—Ó≈‡‘¥\C++\codeforces\145E.exe <input.txt>myans.txt
D:\—Ó≈‡‘¥\C++\codeforces\145E-tj.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again