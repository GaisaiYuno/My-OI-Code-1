@echo off
for /L %%i in (1,1,10) do (
	triangulationOK.exe <triangulation%%i.in> triangulation%%i.ans
	fc triangulation%%i.ans triangulation%%i.out 
)
pause