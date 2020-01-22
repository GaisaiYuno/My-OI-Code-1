program score(input,output);
var
  a,b,c,s,a1,b1,c1:longint;
begin
  assign(input,'score.in');reset(input);
  assign(output,'score.out');rewrite(output);
  read(a,b,c);
  a1:=(a*2) div 10;
  b1:=(b*3) div 10;
  c1:=(c*5) div 10;
  s:=a1+b1+c1;
  write(s);
  close(input);
  close(output);
end.