@echo off
:again
G:\C++\数据结构\散列表\对拍\makedata >input.txt
G:\C++\数据结构\散列表\对拍\HDU4300 >my_output.txt
G:\C++\数据结构\散列表\对拍\HDU4300-对拍 >right_output.txt
fc my_output.txt  right_output.txt>nul
if not errorlevel 1 goto again