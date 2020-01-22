var n,d,k:longint;
    i,j:longint;
    x,a:array[0..550000]of int64;
    first,last:array[0..550000]of longint;
    dp:array[0..550000]of int64;
    sum:int64;
    l,r,m:longint;
    ok:boolean;
function low(g:longint):longint;
begin
  if g<d then exit(d-g) else exit(1);
end;
function find(y,l,r,g:longint):longint;
var m:longint;
begin
  while l<=r do
  begin
    m:=(l+r)>>1;
    if x[m]-x[y]<low(g) then l:=m+1 else r:=m-1;
  end;
  exit(l);
end;
function find2(y,l,r,g:longint):longint;
var m:longint;
begin
  while l<=r do
  begin
    m:=(l+r)>>1;
    if x[m]-x[y]>d+g then r:=m-1 else l:=m+1;
  end;
  exit(r);
end;
procedure get(g:longint);
var i,j:longint;
begin
  for i:=0 to n do
  begin
    first[i]:=0;
    last[i]:=0;
  end;
  for i:=0 to n do
  begin
    first[i]:=find(i,i+1,n+1,g);
    last[i]:=find2(i,i+1,n+1,g);
  end;
end;
function max(a,b:int64):int64;
begin
  if a>b then exit(a) else exit(b);
end;
procedure workdp;
var i,j:longint;
begin
  for i:=1 to n do
  dp[i]:=-1 << 30;
  dp[0]:=0;
  for i:=0 to n do
    for j:=first[i] to last[i] do
    dp[j]:=max(dp[j],dp[i]+a[j]);
end;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  read(n,d,k);
  for i:=1 to n do
  begin
    read(x[i],a[i]);
    if a[i]>0 then inc(sum,a[i]);
  end;
  x[n+1]:=maxlongint;
  if k>sum then
  begin
    writeln(-1);
    close(input);
    close(output);
    exit;
  end;
  l:=0;
  r:=x[n];
  while l<=r do
  begin
    ok:=false;
    m:=(l+r)>>1;
    get(m);
    workdp;
    for j:=1 to n do
    if dp[j]>=k then
    begin
      ok:=true;
      break;
    end;
    if ok then r:=m-1 else l:=m+1;
  end;
  writeln(l);
  close(input);
  close(output);
end.
