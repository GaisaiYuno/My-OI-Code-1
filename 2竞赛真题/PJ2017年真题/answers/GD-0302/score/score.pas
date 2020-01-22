var s1,s2,s3:longint;
    s:real;
begin
  assign (input,'score.in'); reset (input);
  assign(output,'score.out');rewrite(output);
  readln (s1,s2,s3);
  s:=s1/5+S2*3/10+s3/2;
  writeln (s:0:0);
  close(input);
  close(output);
end.