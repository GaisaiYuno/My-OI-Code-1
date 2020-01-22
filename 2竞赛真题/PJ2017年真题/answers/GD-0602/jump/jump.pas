var
 sum,sum1,fs:array[0..500000]of longint;
 f:array[0..500000]of longint;
 n,d,k,i,j,l,r,l1,r1,t,m:longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(a) else exit(b);
end;
procedure ending;
begin
 close(input);
 close(output);
 halt;
end;
begin
assign(input,'jump.in');reset(input);
assign(output,'jump.out');rewrite(output);
 readln(n,d,k);
 for i:=1 to n do begin
  readln(t,fs[i]);
  sum[i]:=sum[i-1]+t;
  if fs[i]>0 then sum1[i]:=sum1[i-1]+fs[i] else sum1[i]:=sum1[i-1];
 end;
 if sum1[n]<k then begin writeln(-1);ending;end;
{ l:=1;r:=sum[n]-d;
 while l<r do
  begin
   fillchar(f,sizeof(f),0);
   for i:=1 to n do
    f[i]:=fs[i];
   m:=(l+r) div 2;
   if m<d then l1:=d-m else l1:=1;
   r1:=d+m;
 for i:=1 to n do
  for j:=i+1 to n do
   if (sum[j]-sum[i]>=l1)and(sum[j]-sum[i]<=r1) then
    f[j]:=max(f[j],f[i]+fs[j]) else break;
  if f[n]>k then l:=m else r:=m-1;
  end;
write(l);}writeln(-1);
close(input);close(output);
end.

