var
  a,b,c:longint;
  sum:real;
begin
  assign(input,'score.in');
  reset(input);
  assign(output,'score.out');
  rewrite(output);
  readln(a,b,c);
  sum:=a*(20/100)+b*(30/100)+c*(50/100);
  writeln(sum:0:0);
  close(input);
  close(output);
end.