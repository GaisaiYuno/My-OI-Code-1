@echo off
:again
G:\C++\18.2.14ÿ��һ��\makedata > input
G:\C++\18.2.14ÿ��һ��\B < input > output.a
G:\C++\18.2.14ÿ��һ��\B���� < input > output.b
fc output.a output.b >nul
if not errorlevel 1 goto again
