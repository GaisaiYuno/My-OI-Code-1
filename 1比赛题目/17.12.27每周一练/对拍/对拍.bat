@echo off
:again
G:\C++\17.12.27ÿ��һ��\����\makedata > input
G:\C++\17.12.27ÿ��һ��\����\C < input > output.a
G:\C++\17.12.27ÿ��һ��\����\Cok < input > output.b
fc output.a output.b >nul
if not errorlevel 1 goto again
