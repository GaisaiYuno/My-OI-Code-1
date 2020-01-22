var
 a,b,c,ans:longint;
begin
 assign(input,'score.in'):
 assign(output,'score.out');
 reset(input);
 rewrite(output);
 read(a,b,c);
 ans:=a div 10*2+b div 10*3+c div 10*5;
 write(ans);
 close(input);
 close(output);
end.