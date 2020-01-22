var
  n,d,m,i,j,k,l,r,mid,ans:longint;
  a,w:array[0..500000]of longint;

function try(mid:longint):boolean;
var
  f:array[0..500000]of longint;
  i,j,c,max,min:longint;
begin
  fillchar(f,sizeof(f),200);
  f[0]:=0;
  min:=d-mid;
  if mid>d then min:=1;
  max:=d+mid;c:=0;
  for i:=1 to n do
    begin
      for j:=c to i-1 do
        begin
          if (a[i]-a[j]>=min)and(a[i]-a[j]<=max)and(f[j]+w[i]>f[i])and(f[j]>=0) then
            f[i]:=f[j]+w[i];
          if a[i]-a[j]>max then c:=j+1;
        end;
      if f[i]>=m then exit(true);
    end;
  exit(false);
end;

begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);rewrite(output);
  readln(n,d,m);
  for i:=1 to n do
    begin
      readln(a[i],w[i]);
      if w[i]>0 then k:=k+w[i];
    end;
  if k<m then begin writeln(-1);halt;end;
  l:=0;
  r:=a[n]-d+1;
  if a[n]-d+1>d then r:=d;
  while l<=r do
    begin
      mid:=(l+r) div 2;
      if try(mid) then begin ans:=mid;r:=mid-1;end else l:=mid+1;
    end;
  writeln(ans);
  close(input);close(output);
end.