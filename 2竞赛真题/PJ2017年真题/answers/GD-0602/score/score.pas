var
 a,b,c:longint;
begin
assign(input,'score.in');reset(input);
assign(output,'score.out');rewrite(output);
 read(a,b,c);
 a:=a div 10;
 b:=b div 10;
 c:=c div 10;
 write(a*2+b*3+c*5);
close(input);close(output);
end.
