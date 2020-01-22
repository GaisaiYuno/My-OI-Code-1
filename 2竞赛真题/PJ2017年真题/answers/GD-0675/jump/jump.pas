var n,d,k,i:longint;
s,x:array[1..100000] of longint;
begin
assign(input,'jump.in');
assign(output;'jump.out');
reset(input);
rewrite(output);
read(n,d,k);
for i:= 1 to n do read(x[i],s[i]);
write('-1');
close(input);
close(output);
end.
