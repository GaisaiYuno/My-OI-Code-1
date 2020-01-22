program score;
var a,b,c,d:real;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input); rewrite(output);
  read(a,b,c);
  d:=a*0.2+b*0.3+c/2;
  write(d:1:0);
  close(input); close(output);
end.