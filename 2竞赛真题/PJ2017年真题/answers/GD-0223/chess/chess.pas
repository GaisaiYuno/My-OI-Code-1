Program chess;
var sq,sq1:array[1..100,1..100] of integer;
    s,i,j,x,y,min,m,n:longint;
procedure dg(x1,y1,x,y,s:longint;boo:boolean);
begin
  sq1[x,y]:=-2;
  if (x=m) and (y=m) then
  begin
    if s<min then min:=s;
    for i:=1 to m do
      for j:=1 to m do sq1[i,j]:=sq[i,j];
    exit;
  end;
  if (sq[x+1,y]<>-2) and (sq[x+1,y]>-1) and (x+1<>x1) and (x<m) then
  begin
    if sq[x,y]=sq[x+1,y] then dg(x,y,x+1,y,s,false);
    if sq[x,y]<>sq[x+1,y] then dg(x,y,x+1,y,s+1,false);
  end;
  if (sq[x+1,y]<>-2) and (sq[x+1,y]=-1) and (x+1<>x1) and (x<m) then
    if boo=false then dg(x,y,x+1,y,s+2,true);
  if (sq[x,y+1]<>-2) and (sq[x,y+1]>-1) and (y+1<>y1) and (y<m) then
  begin
    if sq[x,y]=sq[x,y+1] then dg(x,y,x,y+1,s,false);
    if sq[x,y]<>sq[x,y+1] then dg(x,y,x,y+1,s+1,false);
  end;
  if (sq[x,y+1]<>-2) and (sq[x,y+1]=-1) and (y+1<>y1) and (y<m) then
    if boo=false then dg(x,y,x+1,y,s+2,true);
  if (sq[x-1,y]<>-2) and (sq[x-1,y]>-1) and (x-1<>x1) and (x>1) then
  begin
    if sq[x,y]=sq[x-1,y] then dg(x,y,x-1,y,s,false);
    if sq[x,y]<>sq[x-1,y] then dg(x,y,x-1,y,s+1,false);
  end;
  if (sq[x-1,y]<>-2) and (sq[x-1,y]=-1) and (x-1<>x1) and (x>1) then
    if boo=false then dg(x,y,x-1,y,s+2,true);
  if (sq[x,y-1]<>-2) and (sq[x,y-1]>-1) and (y-1<>y1) and (y>1) then
  begin
    if sq[x,y]=sq[x,y-1] then dg(x,y,x,y-1,s,false);
    if sq[x,y]<>sq[x,y-1] then dg(x,y,x,y-1,s+1,false);
  end;
  if (sq[x,y-1]<>-2) and (sq[x,y-1]=-1) and (y-1<>y1) and (y>1) then
    if boo=false then dg(x,y,x,y-1,s+2,true);
  for i:=1 to m do
    for j:=1 to m do sq1[i,j]:=sq[i,j];
end;
begin
  min:=0;
  readln(m,n);
  for i:=1 to m do
    for j:=1 to m do sq[i,j]:=-1;
  s:=-1;
  for i:=1 to n do readln(x,y,sq[x,y]);
  dg(0,0,1,1,0,false);
  if s=-1 then writeln(-1)
           else writeln(s+1);
end.

