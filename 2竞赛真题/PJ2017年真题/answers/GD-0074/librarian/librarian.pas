var n,t,x,g,z,q,i,j,e,s,v:longint;
    p,a,b,d,c:array[1..1000000] of longint;
    k,m:string;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
read(n,q);
s:=1;
for i:=1 to n do
read(a[i]);
for i:=1 to q do
begin
read(b[i],c[i]);
str(a[i],k);
str(c[i],m);
delete(k,1,length(k)-b[i]);
  for j:=1 to n do
  begin
  if k[j]=m[j] then begin inc(v); d[v]:=a[j]; end;
  x:=d[1];
  for t:=2 to v do
  if x>d[t] then x:=d[t];
  for g:=1 to q do
  if p[g]=a[g] then   p[g]:=a[g]  else p[g]:=0;
end;
end;
for i:=1 to t do
if p[g]=0 then writeln('-1') else writeln(p[g]);
close(input);
close(output);
end.
