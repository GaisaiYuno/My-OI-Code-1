@echo off
:again
G:\C++\18.3.28每周一练\makedata.exe >in.txt
G:\C++\18.3.28每周一练\C-zyd.exe <in.txt> zydans.txt
G:\C++\18.3.28每周一练\C.exe <in.txt> myans.txt
fc zydans.txt myans.txt
if not errorlevel 1 goto again 
pause
