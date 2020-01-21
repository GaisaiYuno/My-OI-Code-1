@echo off
:again
md.exe > input.txt
my.exe < input.txt > my_ans.txt
tj.exe < input.txt > right_ans.txt
fc my_ans.txt right_ans.txt>nul
if not errorlevel 1 goto again
