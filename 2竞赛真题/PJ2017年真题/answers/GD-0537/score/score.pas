var a,b,c,d,e,f,g:longint;
begin
assign(input,'score.in');reset(input);
assign(output,'score.out');rewrite(output);
  readln(e,f,g);
  a:=e div 5+a;
  a:=f div 10*3+a;
  a:=g div 2+a;
  writeln(a);
close(input);
close(output);
end.