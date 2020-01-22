var a,b,c:integer;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input);
  rewrite(output);
  readln(a,b,c);
  writeln(a*20 div 100+b*30 div 100+c div 2);
  close(input);
  close(output);
end.