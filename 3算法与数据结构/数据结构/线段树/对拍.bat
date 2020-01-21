@echo off
:again
G:\C++\数据结构\线段树\makedata> input.txt
G:\C++\数据结构\线段树\HDU3016#< input.txt > my_ans.txt
G:\C++\数据结构\线段树\HDU3016对拍 < input.txt > right_ans.txt
fc my_ans.txt right_ans.txt>nul
if not errorlevel 1 goto again
