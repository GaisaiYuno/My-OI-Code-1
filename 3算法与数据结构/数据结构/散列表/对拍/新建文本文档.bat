@echo off
:again
G:\C++\���ݽṹ\ɢ�б�\����\makedata >input.txt
G:\C++\���ݽṹ\ɢ�б�\����\HDU4300 >my_output.txt
G:\C++\���ݽṹ\ɢ�б�\����\HDU4300-���� >right_output.txt
fc my_output.txt  right_output.txt>nul
if not errorlevel 1 goto again