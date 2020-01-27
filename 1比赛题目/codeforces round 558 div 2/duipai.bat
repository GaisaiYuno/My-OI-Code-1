@echo off
:again
Cmd.exe  > in.txt
C.exe < in.txt > my.txt
Ctj.exe < in.txt > right.txt
fc my.txt right.txt
if not errorlevel 1 goto again