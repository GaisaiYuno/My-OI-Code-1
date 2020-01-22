var
  a,b,c,ans:longint;

begin
assign(input,'score.in');reset(input);
assign(output,'score.out');rewrite(output);

  readln(a,b,c);
  a:=a div 10*2;
  b:=b div 10*3;
  c:=c div 10*5;
  ans:=a+b+c;
  writeln(ans);

close(input);close(output);
end.