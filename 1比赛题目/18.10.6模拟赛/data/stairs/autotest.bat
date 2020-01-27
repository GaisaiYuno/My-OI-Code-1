@echo off
for /L %%i in (1,1,10) do (
    stairsOK.exe <stairs%%i.in> stairs%%i.ans
    fc stairs%%i.out stairs%%i.ans
) 
pause