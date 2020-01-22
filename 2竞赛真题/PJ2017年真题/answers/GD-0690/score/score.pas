var
  s,a,b,c:longint;
begin
  input(input,'score.in');
  output(output,'score.out');
  reset(input);
  rewrite(output);
  read(a,b,c);
  s:=a div 10*2+b div 10*3+c div 10*5;
  write(s);
  close(input);
  close(output);
end.

