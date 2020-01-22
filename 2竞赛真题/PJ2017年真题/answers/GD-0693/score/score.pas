var
  s,a,b,c:longint;
begin
assign(input,'score.in');
assign(output,'score.out');
reset(input);
rewrite(output);
  readln(a,b,c);
  s:=(a div 5)+(b div 10*3)+(c div 2);
  writeln(s);
close(input);
close(output);
end.
