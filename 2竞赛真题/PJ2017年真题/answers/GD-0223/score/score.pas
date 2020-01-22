Program score;
var a,b,c:longint;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input);
  rewrite(output);
  readln(a,b,c);
  writeln((a div 5)+(b div 10)*3+(c div 2));
  close(input);
  close(output);
end.
