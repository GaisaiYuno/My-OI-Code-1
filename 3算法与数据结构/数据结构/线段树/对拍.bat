@echo off
:again
G:\C++\���ݽṹ\�߶���\makedata> input.txt
G:\C++\���ݽṹ\�߶���\HDU3016#< input.txt > my_ans.txt
G:\C++\���ݽṹ\�߶���\HDU3016���� < input.txt > right_ans.txt
fc my_ans.txt right_ans.txt>nul
if not errorlevel 1 goto again
