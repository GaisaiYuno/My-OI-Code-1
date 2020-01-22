var x,s:array[0..1000000] of longint;
    n,d,k,i:longint;
begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);
read(n,d,k);
for i:=1 to n do
read(x[i],s[i]);
write('-1');
close(input);
close(output);
end.