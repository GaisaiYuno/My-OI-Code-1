@echo off
:again
D:\����Դ\C++\18.5.5ר��ѵ��\makedata.exe >input.txt
D:\����Դ\C++\18.5.5ר��ѵ��\E.exe <input.txt> myans.txt
D:\����Դ\C++\18.5.5ר��ѵ��\Eok.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again
