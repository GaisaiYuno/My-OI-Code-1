var a,b,c,d:longint;
begin
  assign(input,'score.in');reset(input);
  assign(output,'score.out');rewrite(output);
  readln(a,b,c);
  a:=a*2 div 10;
  b:=b*3 div 10;
  c:=c*5 div 10;
  d:=a+b+c;
  writeln(d);
  close(input);
  close(output);
end.
