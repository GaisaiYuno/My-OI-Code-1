const xx:array[1..4] of longint=(-1,0,0,1);
      yy:array[1..4] of longint=(0,-1,1,0);
var first,next,y,c,q,dist:array[0..100020] of longint;
var v:array[0..100020] of boolean;
var a,f:array[0..120,0..120] of longint;
var n,m,i,j,ans,tot,x1,y1,k,l,x2,y2:longint;
procedure add(x,y1,z:longint);
begin
  inc(tot);next[tot]:=first[x];first[x]:=tot;y[tot]:=y1;c[tot]:=z;
end;
procedure spfa(s:longint);
var i,now,h,t:longint;
begin
  for i:=1 to n*n do begin dist[i]:=2147483647;v[i]:=false;end;
  dist[s]:=0;h:=0;t:=1;q[1]:=s;v[s]:=true;
  while h<t do
  begin
    inc(h);now:=q[h];i:=first[now];
    while i<>-1 do
    begin
      if dist[y[i]]>dist[now]+c[i] then
      begin
        dist[y[i]]:=dist[now]+c[i];
        if not v[y[i]] then
        begin
          inc(t);q[t]:=y[i];v[y[i]]:=true;
        end;
      end;
      i:=next[i];
    end;
    v[now]:=false;
  end;
end;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  read(n,m);
  for i:=1 to n*n do first[i]:=-1;
  for i:=1 to n do for j:=1 to n do f[i,j]:=(i-1)*n+j;
  for i:=1 to m do begin read(x1,y1,a[x1,y1]);inc(a[x1,y1]);end;
  for i:=1 to n do
    for j:=1 to n do
    begin
      if a[i,j]>0 then
      for k:=1 to 4 do
      begin
        x1:=i+xx[k];y1:=j+yy[k];
        if (x1>0) and (x1<=n) and (y1>0) and (y1<=n) then
        begin
          if a[x1,y1]>0 then
          if a[x1,y1]=a[i,j] then
          begin
            add(f[x1,y1],f[i,j],0);add(f[i,j],f[x1,y1],0);
          end else begin
            add(f[x1,y1],f[i,j],1);add(f[i,j],f[x1,y1],1);
          end;
          if a[x1,y1]=0 then
          begin
            for l:=1 to 4 do
            begin
              x2:=x1+xx[l];y2:=y1+yy[l];{orzyyl}
              if (x2>0) and (x2<=n) and (y2>0) and (y2<=n) then
              //and (x2<>i) and (y2<>j) then
              if a[x2,y2]>0 then
              if a[x2,y2]=a[i,j] then
              begin
                add(f[x2,y2],f[i,j],2);add(f[i,j],f[x2,y2],2);
              end else begin
                add(f[x2,y2],f[i,j],3);add(f[i,j],f[x2,y2],3);
              end;
            end;
          end;
        end;
      end;
    end;
  if a[n,n]=0 then
  begin
  if a[n-1,n]>0 then begin
    add(f[n,n],f[n-1,n],2);add(f[n-1,n],f[n,n],2);
  end;
  if a[n,n-1]>0 then begin
    add(f[n,n],f[n,n-1],2);add(f[n,n-1],f[n,n],2);
  end;
  if a[n-1,n-1]>0 then begin
    add(f[n,n],f[n-1,n-1],2);add(f[n-1,n-1],f[n,n],2);end;
  end;
  spfa(1);if dist[n*n]>1<<29 then writeln(-1) else writeln(dist[n*n]);
  //for i:=1 to n do begin for j:=1 to n do if dist[f[i,j]]>1<<29 then write(-1,' ') else write(dist[f[i,j]]:2,' ');writeln;end;
  close(input);close(output);
end.
