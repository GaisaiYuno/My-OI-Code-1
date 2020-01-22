const dx:array[1..4]of longint=(0,1,0,-1);
      dy:array[1..4]of longint=(1,0,-1,0);
var qx,qy:array[0..5000000]of longint;
    v:array[0..250,0..250]of boolean;
    dist:array[0..250,0..250,0..5]of longint;
    a:array[0..250,0..250]of longint;
    n,m:longint;
    i,j:longint;
    x,y,c:longint;
procedure goin(x,y:longint;var tail:longint);
begin
  if not v[x,y] then
  begin
    inc(tail);
    qx[tail]:=x;
    qy[tail]:=y;
    v[x,y]:=true;
  end;
end;
procedure bfs(sx,sy:longint);
var head,tail:longint;
    i,j,k:longint;
    nowx,nowy,x,y:longint;
begin
  head:=1;
  tail:=1;
  for i:=1 to n do
  for j:=1 to n do
  begin
    v[i,j]:=false;
    for k:=1 to 5 do
    dist[i,j,k]:=1 << 25;
  end;
  qx[1]:=sx;
  qy[1]:=sy;
  dist[sx,sy,a[sx,sy]]:=0;
  while head<=tail do
  begin
    nowx:=qx[head];
    nowy:=qy[head];
    for i:=1 to 4 do
    begin
      x:=nowx+dx[i];
      y:=nowy+dy[i];
      if (x>0)and(y>0)and(x<=n)and(y<=n) then
      begin
        if a[x,y]<>0 then
        begin
          if a[x,y]=a[nowx,nowy] then
          begin
            if dist[x,y,a[x,y]]>dist[nowx,nowy,a[x,y]] then
            begin
              dist[x,y,a[x,y]]:=dist[nowx,nowy,a[x,y]];
              goin(x,y,tail);
            end;
          end else
          begin
            if a[nowx,nowy]=0 then
            begin
              for k:=1 to 2 do
              if a[x,y]=k then
              begin
                if dist[x,y,a[x,y]]>dist[nowx,nowy,k] then
                begin
                  dist[x,y,a[x,y]]:=dist[nowx,nowy,k];
                  goin(x,y,tail)
                end;
              end else
              begin
                if dist[x,y,a[x,y]]>dist[nowx,nowy,k]+1 then
                begin
                  dist[x,y,a[x,y]]:=dist[nowx,nowy,k]+1;
                  goin(x,y,tail);
                end;
              end;
            end else
            begin
              if dist[x,y,a[x,y]]>dist[nowx,nowy,a[nowx,nowy]]+1 then
              begin
                dist[x,y,a[x,y]]:=dist[nowx,nowy,a[nowx,nowy]]+1;
                goin(x,y,tail);
              end;
            end;
          end;
        end else
        begin
          if a[nowx,nowy]<>0 then
          begin
            for k:=1 to 2 do
            if a[nowx,nowy]=k then
            begin
              if dist[x,y,k]>dist[nowx,nowy,a[nowx,nowy]]+2 then
              begin
                dist[x,y,k]:=dist[nowx,nowy,a[nowx,nowy]]+2;
                goin(x,y,tail);
              end;
            end else
            begin
              if dist[x,y,k]>dist[nowx,nowy,a[nowx,nowy]]+3 then
              begin
                dist[x,y,k]:=dist[nowx,nowy,a[nowx,nowy]]+3;
                goin(x,y,tail);
              end;
            end;
          end;
        end;
      end;
    end;
    inc(head);
    v[nowx,nowy]:=false;
  end;
end;
function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  read(n,m);
  for i:=1 to m do
  begin
    read(x,y,c);
    a[x,y]:=c+1;
  end;
  bfs(1,1);
  if a[n,n]<>0 then
  begin
    if dist[n,n,a[n,n]]=1 << 25 then writeln(-1) else
       writeln(dist[n,n,a[n,n]]);
  end else
  begin
    if min(dist[n,n,1],dist[n,n,2])=1 << 25 then writeln(-1) else
    writeln(min(dist[n,n,1],dist[n,n,2]));
  end;
  close(input);
  close(output);
end.
