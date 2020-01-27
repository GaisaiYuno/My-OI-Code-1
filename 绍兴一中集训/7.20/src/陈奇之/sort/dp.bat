:loop
mk
bf > bf.out
sort
fc bf.out sort.out
if not errorlevel==1 goto loop
pause