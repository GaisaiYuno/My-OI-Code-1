@echo off
:again
D:\杨培源\C++\图论算法\无向图的割点与桥\随机生成图.exe >input.txt
D:\杨培源\C++\图论算法\无向图的割点与桥\luoguP2783.exe <input.txt >myans.txt
D:\杨培源\C++\图论算法\无向图的割点与桥\luoguP2783-duipai.exe <input.txt> rightans.txt
fc myans.txt rightans.txt
if not errorlevel 1 goto again