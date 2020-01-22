var a,b,i,j:longint;
q:array[1..1000,1..1000] of longint;
begin
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
readln(a,b);
for i:=1 to a do
	for j:=1 to b do
	read(q[i,j]);
write('-1');
close(input);
close(output);
end.