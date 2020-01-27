@echo off
for /L %%i in (1,1,10) do (
    pressureOK.exe <%%i.in>%%i.ans
    fc %%i.ans %%i.out >nul
    if %errorlevel%==1 (
     echo wrong answer on test %%i !
    ) else echo right output on test %%i!
)
pause