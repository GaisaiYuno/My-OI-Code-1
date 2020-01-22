var i,j,k,n,m:longint;
begin
  assign(input,'score.in');reset(input);
  assign(output,'score.out');rewrite(output);
  read(k,n,m);
  k:=k div 10;
  n:=n div 10;
  m:=m div 10;
  write(k*2+n*3+m*5);
  close(input);close(output);
end.