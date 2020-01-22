var n:longint;
    a,f:array[0..100,0..100]of longint;
    d:array[0..100,0..100]of boolean;
procedure mg(x,y,s,t:longint);
begin
  if (x=n) and (y=n) then if s<f[n,n] then begin f[n,n]:=s; exit; end;
  if (s>=f[x,y]) and (f[x,y]<>0) then exit
                                 else f[x,y]:=s;
  d[x,y]:=true;
  if (x+1<=n) and (not d[x+1,y]) then
    if (a[x+1,y]=0) then mg(x+1,y,s+2,t)
      else if (a[x+1,y]=t) then mg(x+1,y,s,t)
        else if t=1 then mg(x+1,y,s+1,2)
                    else mg(x+1,y,s+1,1);
  if (y+1<=n) and (not d[x,y+1]) then
    if (a[x,y+1]=0) then mg(x,y+1,s+2,t)
      else if (a[x,y+1]=t) then mg(x,y+1,s,t)
        else if t=1 then mg(x+1,y,s+1,2)
                    else mg(x+1,y,s+1,1);
  if (x-1>0) and (not d[x-1,y]) then
    if (a[x-1,y]=0) then mg(x-1,y,s+2,t)
      else if (a[x-1,y]=t) then mg(x-1,y,s,t)
        else if t=1 then mg(x+1,y,s+1,2)
                    else mg(x+1,y,s+1,1);
  if (y-1>0) and (not d[x,y-1]) then
    if (a[x,y-1]=0) then mg(x,y-1,s+2,t)
      else if (a[x,y-1]=t) then mg(x,y-1,s,t)
        else if t=1 then mg(x+1,y,s+1,2)
                    else mg(x+1,y,s+1,1);
  d[x,y]:=false;
end;
var x,y,c,i,m:longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);

  read(n,m);
  for i:=1 to m do
  begin
    read(x,y,c);
    a[x,y]:=c+1;
  end;
  mg(1,1,0,a[1,1]);
  write(f[n,n]);

  close(input);
  close(output);
end.
