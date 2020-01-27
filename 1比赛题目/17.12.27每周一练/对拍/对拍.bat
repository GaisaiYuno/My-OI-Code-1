@echo off
:again
G:\C++\17.12.27每周一练\对拍\makedata > input
G:\C++\17.12.27每周一练\对拍\C < input > output.a
G:\C++\17.12.27每周一练\对拍\Cok < input > output.b
fc output.a output.b >nul
if not errorlevel 1 goto again
