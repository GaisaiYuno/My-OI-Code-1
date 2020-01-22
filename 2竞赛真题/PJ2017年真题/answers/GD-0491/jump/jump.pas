program jump(input,output,jump);
type t:test;
var n,d,k,i,j,xx,ss,su,sfok,g,zhsm:integer;
    x:array[1..10000] of integer;
function ok(h:integer):integer;
var fwdown,fwup,dq,sum:integer;
begin
if h<d then
begin
fwdown:=d-h;
fwup:=d+h;
end;
else 
begin
fwdown:=1;
fwup:=d+h;
end;
sum:=0;
dq:=0;
su:=0;
sum:=tr(fwdown,fwup,sum,dq)
if sum>=k then
su:=1;
if su=1 then ok:=1;
else ok:=0;
end;
function tr(fd,fu,sum,dq:integer):integer
var pd:integer;
begin
if dq>n then
tr:=-2;
else
begin
for i:=fd to fu do
begin
dq:=dq+i;
sum:=sum+x[dq];
pd:=tr(fd,fu,sum,dq);
if pd<>-2 then
sum:=sum+pd;
else sum:=sum;
if sum>=k then
su:=1;
end;
end;
end;
begin
assign(t,jump.in);
reset(t);
read(t,n,d,k);
for i:=1 to 10000 do
x[i]:=0;
for i:=1 to n do
begin
read(t,xx,ss);
x[xx]:=ss;
end;
close(t);
assign(t,jump.out);
rewrite(t);
zhsm:=-1;
for g:=1 to 100 do
begin
sfok:=ok(g);
if sfok=1 and zhsm:-1 then zhsm:=g;
end;
write(t,zhsm);
close(t);
end.