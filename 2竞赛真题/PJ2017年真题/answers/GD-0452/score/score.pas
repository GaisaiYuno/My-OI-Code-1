program score;
var
a,b,c,d:integer;
begin
assign(input,'score.in');reset(input);
assign(output,'score.out');rewrite(output);
 read(a,b,c);
 d:=a*2+b*3+c*5;
 d:=d div 10;
 write(d);
close(input);
close(output);
end.
