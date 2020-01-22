program t1;
var a,b,c,ans:integer;
begin
assign(input,'score.in'); assign(output,'score.out');
reset(input);   rewrite(output);
readln(a,b,c);
ans:=a*20+b*30+c*50;
ans:=ans div 100;
writeln(ans);
close(input); close(output);
end.
