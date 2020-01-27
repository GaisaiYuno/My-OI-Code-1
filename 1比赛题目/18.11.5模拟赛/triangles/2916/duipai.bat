@echo off
for /L %%i in (1,1,8) do (
	triangles.exe < %%i.in> %%i.ans
	fc %%i.out %%i.ans
	if errorlevel 1 pause
)