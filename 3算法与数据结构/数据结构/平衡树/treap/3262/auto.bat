@echo off
for /L %%i in (1,1,10) do (
   BZOJ3262.exe <%%i.in>%%i.ans
   fc %%i.out %%i.ans >nul
   if errorlevel 1 (
	echo Wrong answer on test %%i
   )
   
)
pause