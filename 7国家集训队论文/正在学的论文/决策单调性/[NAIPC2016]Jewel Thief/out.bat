@echo off
for /L %%i in (1,1,10) do (
tj.exe < %%i.in > %%i.out
)
pause