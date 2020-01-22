program score;
var
  a,b,c,d:longint;
begin
  assign(input,'score.in');
  reset(input);
  assign(output,'score.out');
  rewrite(output);
  readln(a,b,c);
  a:=a div 10;
  b:=b div 10;
  c:=c div 10;
  d:=a*2+b*3+c*5;
  writeln(d);
  close(input);
  close(output);
end.
