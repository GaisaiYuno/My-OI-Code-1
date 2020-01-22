var rmb,n,m,lrmb:longint;
  c:array[1..1000,1..1000] of longint;
  t:boolean;
procedure cc(x,y:longint);
begin
  if(x=n) and (y=n) and (rmb>lrmb) then
    begin
      rmb:=lrmb;
      exit;
    end;
  if(y<n) then
    begin
    if(c[x][y+1]=2) and not(t) then
        begin
          lrmb:=lrmb+2;
          t:=true;
          c[x,y+1]:=c[x,y];
          cc(x,y+1);
          c[x,y+1]:=2;
          t:=false;
          lrmb:=lrmb-2;
        end
      else if(c[x][y+1]=c[x][y]) and (c[x][y+1]<>2) then
        begin
          t:=false;
          cc(x,y+1);
        end
      else if(c[x][y+1]<>2) then begin
          t:=false;
          lrmb:=lrmb+1;
          cc(x,y+1);
          lrmb:=lrmb-1;
        end;
    end;
  if(x<n) then
    begin
      if(c[x+1][y]=2) and not(t) then
        begin
          lrmb:=lrmb+2;
          t:=true;
          c[x+1][y]:=c[x][y];
          cc(x+1,y);
          c[x+1][y]:=2;
          t:=false;
          lrmb:=lrmb-2;
        end
      else if(c[x+1][y]=c[x][y]) and (c[x+1][y]<>2) then
        begin
          t:=false;
          cc(x+1,y);
        end
      else if(c[x+1][y]<>2) then begin
          t:=false;
          lrmb:=lrmb+1;
          cc(x+1,y);
          lrmb:=lrmb-1;
        end;
    end;
end;
var i,j,x,y:longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do
      c[i][j]:=2;
  rmb:=maxlongint;
  for i:=1 to m do
    readln(x,y,c[x][y]);
  cc(1,1);
  if(rmb<maxlongint) then
    writeln(rmb)
  else
    writeln(-1);
  close(input);
  close(output);
end.