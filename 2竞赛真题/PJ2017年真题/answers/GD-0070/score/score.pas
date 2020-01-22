var
  a,b,c:real;
begin
  assign(input,'score.in');
  reset(input);
  assign(output,'score.out');
  rewrite(output);
  readln(a,b,c);
  a:=a*0.2; b:=b*0.3; c:=c/2;
  writeln(a+b+c:0:0);
  close(input);
  close(output);
end.