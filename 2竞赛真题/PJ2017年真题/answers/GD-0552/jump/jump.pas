var n,d,k,m,tmp,ant,lu,max:longint;la,road,qz:array[0..500000] of longint;
function jdz(x:longint):longint;
begin
if x>0 then
exit(x) else exit(-x)
end;
begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);
readln(n,d,k);
for tmp:=1 to n do
begin
lu:=ant;
read(ant);
if ((ant-lu)>(d+max)) or ((ant-lu)<(d-max)) then max:=jdz(d-(ant-lu));
read(road[ant]);
qz[tmp]:=road[ant]+qz[tmp-1];
if qz[tmp]>k then break;
end;
if qz[tmp]>k then writeln(max)
else writeln(-1);
close(input);
close(output);
end.
