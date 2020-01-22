var a,b,c:longint;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input);
  rewrite(output);
  readln(a,b,c);
  a:=a div 10 * 2;
  b:=b div 10 * 3;
  c:=c div 10 * 5;
  writeln(a+b+c);
  close(input);
  close(output);
end.
