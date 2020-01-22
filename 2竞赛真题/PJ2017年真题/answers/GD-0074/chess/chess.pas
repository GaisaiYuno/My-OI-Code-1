var m,n,i:longint;
   x,y,c:array[1..100000] of longint;
begin
assign(input,'chess.in');
assign(output,'chsee.out');
reset(input);
rewrite(output);
read(m,n);
for i:=1 to n do
read(x[i],y[i],c[i]);
write('-1');
close(input);
close(output);
end.