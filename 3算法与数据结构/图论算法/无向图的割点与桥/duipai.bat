@echo off
:again
D:\����Դ\C++\ͼ���㷨\����ͼ�ĸ������\�������ͼ.exe >input.txt
D:\����Դ\C++\ͼ���㷨\����ͼ�ĸ������\luoguP2783.exe <input.txt >myans.txt
D:\����Դ\C++\ͼ���㷨\����ͼ�ĸ������\luoguP2783-duipai.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again