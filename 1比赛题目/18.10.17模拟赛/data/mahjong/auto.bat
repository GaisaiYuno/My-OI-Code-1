@echo on
for /L %%i in (1,1,10) do (
     mahjongOK.exe <mahjong%%i.in> mahjong%%i.ans
     fc mahjong%%i.out mahjong%%i.ans
)
pause