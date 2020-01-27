@echo off
for /L %%i in (1,1,10) do (
	julaoOK2.exe<julao%%i.in>julao%%i.ans
	fc julao%%i.ans julao%%i.out 
)
pause