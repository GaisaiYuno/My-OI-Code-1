var a,b,c:longint;  ans:real;
begin
  assign(input,'score.in'); assign(output,'score.out');
  reset(input); rewrite(output);
  readln(a,b,c);
  ans:=(a*0.2)+(b*0.3)+(c*0.5);
  writeln(ans:0:0);
  close(input); close(output);
end.