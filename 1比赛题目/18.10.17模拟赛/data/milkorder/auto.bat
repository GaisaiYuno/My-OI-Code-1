@echo on
for /L %%i in (1,1,10) do (
     milkorderOK.exe <milkorder%%i.in> milkorder%%i.ans
     fc milkorder%%i.out milkorder%%i.ans
)
pause