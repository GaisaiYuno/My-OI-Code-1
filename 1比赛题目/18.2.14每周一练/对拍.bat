@echo off
:again
G:\C++\18.2.14每周一练\makedata > input
G:\C++\18.2.14每周一练\B < input > output.a
G:\C++\18.2.14每周一练\B对拍 < input > output.b
fc output.a output.b >nul
if not errorlevel 1 goto again
