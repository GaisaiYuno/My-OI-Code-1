var a,b,c,d:longint;
begin
  assign(input,'score.in');reset(input);
  assign(output,'score.out');rewrite(output);
  readln(a,b,c);
  d:=trunc(a*0.2+b*0.3+c*0.5);
  writeln(d);
  close(input);close(output);
end.