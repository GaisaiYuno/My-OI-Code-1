@echo off
:again
D:\H02\circle\makedata.exe >input.txt
D:\H02\circle\circle.exe <input.txt>myans.txt
D:\H02\circle\right,exe <input.txt>rightans.txt
fc myans.txt rightans.txt 
if not errorlevel 1 goto again