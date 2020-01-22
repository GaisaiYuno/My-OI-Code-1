type aa=record
x:longint;
y:longint;
zt:longint;
end;
var i,j,k,c,d,e:longint;
    n,m,xx,yy,x1,y1:integer;
    fx:array[1..4,1..2]of integer=((1,0),(0,1),(0,-1),(-1,0));
    a:array[1..1000,1..1000]of integer;
    f:array[1..1000,1..1000,-1..1]of longint;
    b:array[1..100000]of aa;
function min(x:longint;y:longint):longint;
begin
  if x<y then min:=x
         else min:=y;
end;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  read(n,m);
  for i:=1 to m do
      begin
        read(c,d,e);
        if e=0 then a[c,d]:=-1
               else a[c,d]:=1;
      end;
  i:=1;
  j:=2;
  f[1,1,a[1,1]]:=0;
  f[1,1,-a[1,1]]:=2;
  a[1,1]:=-2;
  b[1].x:=1;b[1].y:=1;
  while (i<=j) do
  begin
    for k:=1 to 4 do
        begin
          xx:=b[i].x+fx[k,1];
          yy:=b[i].y+fx[k,2];
          if (xx>0)and(xx<=n)and(yy>0)and(yy<=n)and(a[xx,yy]<>-2) then
             begin
               x1:=b[i].x;
               y1:=b[i].y;
               e:=a[x1,y1];
               if (a[xx,yy]=0) then
               begin
                 if b[i].zt=1 then continue;
                 f[xx,yy,1]:=min(f[x1,y1,1],f[x1,y1,-1])+2;
                 f[xx,yy,-1]:=f[xx,yy,1];
                 b[j].x:=xx;
                 b[j].y:=yy;
                 b[j].zt:=1;
                 a[xx,yy]:=-2;
                 inc(j);
                 continue;
               end;
               if (f[xx,yy,1]=0)or(f[xx,yy,1]<min(f[x1,y1,1],f[x1,y1,-1]+1)) then
                  begin
                    f[xx,yy,1]:=min(f[x1,y1,1],f[x1,y1,-1]+1);
                    b[j].x:=xx;
                    b[j].y:=yy;
                    b[j].zt:=0;
                    a[xx,yy]:=-2;
                    inc(j);
                  end;
               if (f[xx,yy,-1]=0)or(f[xx,yy,-1]<min(f[x1,y1,-1],f[x1,y1,1]+1)) then
                  begin
                    f[xx,yy,-1]:=min(f[x1,y1,-1],f[x1,y1,1]+1);
                    b[j].x:=xx;
                    b[j].y:=yy;
                    b[j].zt:=0;
                    a[xx,yy]:=-2;
                    inc(j);
                  end;
             end;
        end;
    inc(i);
  end;
  if (f[n,n,1]<>0)then
     begin
     if f[n,n,-1]<>0 then writeln(min(f[n,n,1],f[n,n,-1]))
                     else writeln(f[n,n,1]);
     end
     else
      begin
        if f[n,n,-1]<>0 then writeln(f[n,n,-1])
                        else writeln(-1);
      end;
  close(input);
  close(output);
end.
