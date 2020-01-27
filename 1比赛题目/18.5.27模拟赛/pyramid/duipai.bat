@echo off
:again
makedata.exe >input.txt
pyramid.exe <input.txt> rightans.txt
pyramid3.exe <input.txt> myans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again