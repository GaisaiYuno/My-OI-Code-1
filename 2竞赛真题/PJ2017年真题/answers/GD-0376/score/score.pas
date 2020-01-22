var
 a,b,c:integer;
begin
assign(input,'score.in');reset(input);
assign(output,'score.out');rewrite(output);
 read(a,b,c);
 write(a div 5+(b*3)div 10+c div 2);
close(input);close(output);
end.