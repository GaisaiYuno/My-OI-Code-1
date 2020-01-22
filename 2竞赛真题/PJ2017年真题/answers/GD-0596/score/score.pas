var
  a,b,c,ans:longint;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input);
  rewrite(output);
  readln(a,b,c);
  ans:=(a*2+b*3+c*5)div 10;
  writeln(ans);
  close(input);
  close(output);
end.
