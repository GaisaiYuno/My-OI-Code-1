var a,s,d:longint;
begin
  assign(input,'score.in');reset(input);
  assign(output,'score.out');rewrite(output);
  readln(a,s,d);
  writeln(a*0.2+s*0.3+d*0.5:0:0);
  close(input);
  close(output);
end.
