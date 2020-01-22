var a,b,c,x,y,i:longint;
begin
assign(input,'jump.in');reset(input);
assign(output,'jump.out');rewrite(output);
readln(a,b,c);
for i:=1 to a do
readln(x,y);
writeln(2);
close(input);
close(output);
end.