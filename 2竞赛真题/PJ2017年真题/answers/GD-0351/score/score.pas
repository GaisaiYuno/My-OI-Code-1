var
  z,x,q,n:longint;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input);
  rewrite(output);
  read(z,x,q);
  n:=(z*20 div 100)+(x*30 div 100)+(q*50 div 100);
  write(n);
  close(input);
  close(output);
end.