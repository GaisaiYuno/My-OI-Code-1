@echo off
:again
for /L %%i in (1,1,10) do ( 
        Planar[HNOI2010].exe < %%i.in > %%i.ans
        fc %%i.out %%i.ans > result.txt
        if errorlevel 1 echo WA on test %%i
)
pause