type rec=record
        x:longint;
        y:longint;
     end;
var n,d,k,i,s,ans:longint;
    a:array[-11..500111] of rec;
    f:array[-11..500111] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
function min(x,y:longint):longint;
begin
  if x>y then exit(y) else exit(x);
end;
function find(l,r:longint):longint;
var i,t,mid:longint;
begin
  if l>=r then exit(r);
  ans:=0;
  mid:=(l+r) div 2; fillchar(f,sizeof(f),0); f[0]:=0;
  for i:=1 to n do
  begin
    for t:=i-1 downto 0 do
    if (a[i].y-a[t].y<=d+mid)and(a[i].y-a[t].y>=d-mid) then
      if (f[t]>0)or(t=0) then f[i]:=max(f[i],f[t]+a[i].x);
    ans:=max(f[i],ans);
  end;
  if ans>=k then exit(find(l,mid));
  if ans<k then exit(find(mid+1,r));
end;
procedure quit;
begin
  close(input);
  close(output);
  halt;
end;
begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);
  rewrite(output);
  read(n,d,k);
  for i:=1 to n do
  begin
    read(a[i].y,a[i].x);
    if a[i].x>0 then s:=s+a[i].x;
  end;
  ans:=maxlongint;
  if s<k then
  begin
    write(-1); quit;
  end;
  if (n>=5000) then
  begin
    for i:=d-1 downto 1 do
      if a[i].x>0 then
      begin
        s:=a[d].y-a[i].y; break;
      end;
    for i:=d+1 to n do
      if a[i].x>0 then
      begin
        s:=min(s,a[i].y-a[d].y);
      end;
    write(s); quit;
  end;
  write(find(0,max(d-1,n-d)));
  //if n=1 then write(0) else write(ans);
  quit;
end.








