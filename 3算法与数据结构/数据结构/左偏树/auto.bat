@echo off
:again
md.exe > input.txt
���ֵĲ���.exe < input.txt > myans.txt
���ֵĲ���tj.exe < input.txt > rtans.txt
fc myans.txt rtans.txt
if not errorlevel 1 goto again