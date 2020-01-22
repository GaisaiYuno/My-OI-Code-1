program jump;
uses math;
var
  l,r,mid,l1,r1,i,j,n,m,c,k:longint;
  a,t:array[0..1000000] of longint;
function check(x:longint):boolean;
var i,j,sum,l,r,ans,wz,h:longint; f:array[0..10000] of longint;
begin
  l:=max(1,c-x); r:=c+x; ans:=0;
  {i:=1; wz:=0; sum:=0; ans:=0;
  while i<=n do begin
    if t[wz]+r<t[i] then break;
    if (a[i]<0) and (t[wz]+r>=t[i+1]) then begin inc(i); continue; end;
    if (t[wz]+l>t[i]) then begin inc(i); continue; end;
    if a[i]>0 then begin wz:=i; sum:=sum+a[i]; inc(i); if sum>ans then ans:=sum; continue; end;
    if (a[i]<0) and (t[wz]+l<=t[i]) and (t[wz]+r>=t[i]) then begin wz:=i; sum:=sum+a[i]; inc(i); continue; end;
  end;
  if ans>=k then check:=true else check:=false; }
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=0 to i-1 do
      if (t[j]+l<=t[i]) and (t[j]+r>=t[i]) then begin
        f[i]:=max(f[i],f[j]+a[i]);
      end;
  for i:=1 to n do if f[i]>ans then ans:=f[i];
  if ans>=k then check:=true else check:=false;
end;
begin
  assign(input,'jump.in'); reset(input);
  assign(output,'jump.out'); rewrite(output);
  readln(n,c,k);
  for i:=1 to n do readln(t[i],a[i]);
  l:=1; r:=t[n];
  while l<r do begin
    mid:=(l+r) div 2;
    if check(mid) then r:=mid
    else l:=mid+1;
  end;
  if check(t[n])=false then writeln(-1)
  else writeln(l);
  close(input); close(output);
end.