@echo off
:again
D:\����Դ\C++\18.5.31ר��ѵ��\makedata.exe >input.txt
D:\����Դ\C++\18.5.31ר��ѵ��\E.exe <input.txt>myans.txt
D:\����Դ\C++\18.5.31ר��ѵ��\������OK.exe <input.txt>rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
pause 
