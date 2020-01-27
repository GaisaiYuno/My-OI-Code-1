@echo off
for /L %%i in (1,1,20) do (
     D.exe < %%i.in > %%i.ans
     fc %%i.out %%i.ans
)
pause