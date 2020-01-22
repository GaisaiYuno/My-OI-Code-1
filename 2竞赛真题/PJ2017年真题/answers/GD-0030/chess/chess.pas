const
  move:array[1..4,1..2]of integer=((1,0),(-1,0),(0,-1),(0,1));
var
  map:array[1..100,1..100]of longint;
  bc,b:array[1..100,1..100]of boolean;
  n,m,x,y,c,i,j,k,first,last,newx,newy,len,min:longint;
  a,f:array[-1..10000]of record
    x,y,date:longint;
  end;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  read(m,n);
  f[-1].date:=maxint;
  for i:=1 to m do
    for j:=1 to m do
    begin
      map[i,j]:=-1;b[i,j]:=true;bc[i,j]:=true;
    end;
  for i:=1 to n do
  begin
    read(x,y,c);
    map[x,y]:=c;
  end;
  a[1].x:=1;a[1].y:=1;a[1].date:=0; b[1,1]:=false;
  first:=1;last:=1;   len:=0;
  while first<=last do
  begin
    for i:=1 to 4 do
    begin
      newx:=a[first].x+move[i,1];
      newy:=a[first].y+move[i,2];
      if (newx>0)and(newx<=m)and(newy>0)and(newy<=m)then
        if bc[a[first].x,a[first].y] then
        begin
          if (b[newx,newy])then
          begin
            inc(len);
            b[newx,newy]:=false;
            f[len].x:=newx;f[len].y:=newy;
            if map[a[first].x,a[first].y]=map[newx,newy]then
              f[len].date:=a[first].date
            else
              if map[a[first].x,a[first].y]+map[newx,newy]=1 then f[len].date:=a[first].date+1
              else
                begin
                  map[newx,newy]:=map[a[first].x,a[first].y];
                  bc[newx,newy]:=false;
                  f[len].date:=a[first].date+2;
                end;
            if (newx=m)and(newy=m)then
            begin
              writeln(f[len].date);
              close(input);close(output);
              exit;
            end;
          end;
        end
        else
          begin
            if (b[newx,newy])and(map[newx,newy]<>-1) then
            begin
              inc(len);
              b[newx,newy]:=false;
              f[len].x:=newx;f[len].y:=newy;
              if map[a[first].x,a[first].y]=map[newx,newy]then
                f[len].date:=a[first].date
                else
                  if map[a[first].x,a[first].y]+map[newx,newy]=1 then
                  f[len].date:=a[first].date+1;
              if (newx=m)and(newy=m)then
              begin
                writeln(f[len].date);
                close(input);close(output);
                exit;
              end;
            end;
          end;
    end;
    min:=-1;
    for i:=1 to len do
      if (f[min].date>f[i].date)and(f[i].date<>-1) then min:=i;
    if min<>-1 then
    begin
      inc(last);
      a[last].x:=f[min].x;a[last].y:=f[min].y;a[last].date:=f[min].date;
      f[min].date:=-1;
    end;
    inc(first);
  end;
  writeln(-1);
  close(input);close(output);
end.


