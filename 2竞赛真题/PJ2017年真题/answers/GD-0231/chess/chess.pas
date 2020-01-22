procedure go(x,y,f:integer;chessboard:array[1..100,1..100]of integer;t:integer;m:integer);
var i,a,b,xa,yb:integer;
begin
 for i:=1 to 4 do
 begin
  a:=0;
  b:=0;
  case i of
   1:a:=1;
   2:b:=1;
   3:a:=-1;
   4:b:=-1;
  end;
  xa:=x+a;
  yb:=x+b;
  if ((xa>0) and (xa<=m) and (yb>0) and (yb<m)) then
  begin
   if chessboard[xa,yb]=chessboard[x,y] then
   begin
    chessboard[x,y]:=2;
    go(xa,yb,0,chessboard,t,m);
   end;
   if chessboard[xa,yb]<>chessboard[x,y] then
   begin
    chessboard[x,y]:=2;
    go(xa,yb,0,chessboard,t+1,m);
   end;
   if (chessboard[xa,yb]=-1)and(f=0) then
   begin
    chessboard[x,y]:=2;
    chessboard[xa,yb]:=chessboard[x,y];
    go(xa,yb,1,chessboard,t+2,m);
   end;
  end;
 end;
end;
var m,n,x,y,i,j,t:longint;
 a,b,f,c:integer;
 fin,fout:text;
 chessboard:array[1..100,1..100]of integer;
begin
 assign(fin,'chess.in');
 reset(fin);
 assign(fout,'chess.out');
 rewrite(fout);
 read(m,n);
 for i:=1 to m do
  for j:=1 to n do
   chessboard[i,j]:=-1;
 for i:=1 to n do
 begin
  read(x,y,c);
  chessboard[x,y]:=c;
 end;
 go(1,1,0,chessboard,0);
end.
