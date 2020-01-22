var a,b,c:longint;
begin
  assign(input,'score.in'); reset(input);
  assign(output,'score.out'); rewrite(output);
  readln(a,b,c);
  write(a*20 div 100+b*30 div 100+c*50 div 100);
  close(input); close(output);
end.