var a,b,c:longint;
begin
  assign(input,'score.in');
  reset(input);
  assign(output,'score.out');
  rewrite(output);
  read(a,b,c);
  write(a*0.2+b*0.3+c*0.5:0:0);
  close(input);
  close(output);
end.