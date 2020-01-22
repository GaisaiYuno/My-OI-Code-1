VAR a,b,c,a1,b1,c1:longint;
begin
  assign(input,'score.in');
  reset(input);
  assign(output,'score.out');
  rewrite(output);
  read(a,b,c);
  a1:=(a div 10)*2;
  b1:=(b div 10)*3;
  c1:=(c div 10)*5;
  writeln(a1+b1+c1);
  close(input);
  close(output);
end.