var a,b,c,s:longint;
begin
  assign(input,'score.in');
  reset(input);
  assign(output,'score.out');
  rewrite(output);
  read(a,b,c);
  s:=a*20 div 100+b*30 div 100+c*50 div 100;
  write(s);
  close(input);
  close(output);
end.