@echo off
:again
makedata.exe >input.txt
C.exe <input.txt> myans.txt
zyd.exe <input.txt> zydans.txt
fc myans.txt zydans.txt
if not errorlevel 1 goto again
