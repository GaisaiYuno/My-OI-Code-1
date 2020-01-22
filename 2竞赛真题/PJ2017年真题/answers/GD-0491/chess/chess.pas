program chess(input,output,chess);
type t:test;
var m,n,x,y,c,i,j,dx,dy,coin:integer;
    ar:array[1..250,1..250] of integer;
procedure move(var ddx,ddy:integer)
var dc:integer;
begin
dc:=ar[ddx,ddy];
if ar[ddx=1,ddy]=dc then
ddx:=ddx+1;
else if ar[ddx,ddy+1]=dc then
ddy:=ddy+1;
else if ar[ddx+1,ddy]=0 or ar[ddx+1,ddy]=1 then
begin
ddx:=ddx+1;
inc(coin);
end;
else if ar[ddx,ddy+1]=0 or ar[ddx,ddy+1]=1 then
begin
ddy:=ddy+1;
inc(coin);
else if 
end;
end;
begin
coin:=0;
assign(t,chess.in);
reset(t);
read(t,m,n);
for i:=1 to 250 do
for j:=1 to 250 do
ar[i,j]:=2;
for i:=1 to n do
begin
read(t,x,y,c);
ar[x,y]:=c;
end;
dx:=1;
dy:=1;
