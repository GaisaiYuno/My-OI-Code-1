@echo off
for /L %%i in (1,1,10) do (
    legacyOK.exe <legacy%%i.in> legacy%%i.ans
    fc legacy%%i.out legacy%%i.ans
) 
pause