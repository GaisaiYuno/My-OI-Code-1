program librarian(input,output,librarian);
type t:test;
var n,q,i,k,cha,b,j,dqdzbm,dqzds:integer;
    tsbm:array[1..10000] of integer;
	dzbmchang:array[1..10000] of integer;
	dzbm:array[1..10000] of integer;
begin
assign(t,librarian.in);
reset(t);
read(t,n,q);
for i:=1 to n do
begin
read(t,k);
tsbm[i]:=k;
end;
for i:=1 to q do
begin
read(t,cha,b);
dzbmchang[i]:=cha;
dzbm[i]:=b;
end;
close(t);
assign(t,librarian.out);
rewrite(t);
for i:=1 to q do
begin
dqdzbm:=dzbm[i];
dqzds:=-1;
for j:=1 to n do
begin
if tsbm[j]-dqdzbm mod dzbmchang[i]=0 then 
if dqzds>tsbm[j] then dqzds:=tsbm[j]
else if dqzds=-1 then dqzds:=tsbm[j];
end;
write(t,dqzds);
write(' ');
end;
end.