@echo off
:again
md.exe > input.txt
棘手的操作.exe < input.txt > myans.txt
棘手的操作tj.exe < input.txt > rtans.txt
fc myans.txt rtans.txt
if not errorlevel 1 goto again