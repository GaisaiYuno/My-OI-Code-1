@echo off
:again
makedata.exe >input.txt
D.exe <input.txt> ans_ypy.txt
D2.exe <input.txt> ans_ygy.txt
D3.exe <input.txt> ans_ypy2.txt
fc ans_ypy.txt ans_ypy2.txt
if not errorlevel 1 goto again

