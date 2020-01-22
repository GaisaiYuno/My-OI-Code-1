var
  x,max,i,j,k,n,d,sum,low,high,mid,l,r:longint;
  check:boolean;
  jl,f,a:array[0..1000000]of longint;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
   begin
    readln(jl[i],x);
    a[jl[i]]:=x;
    if x>0 then sum:=sum+x;
   end;
  if sum<x then
   begin write(-1);close(input);close(output);exit;end;
  l:=1;r:=jl[n]-1;a[0]:=1;
  while l<r do
   begin
    mid:=(l+r)div 2;
    if mid>=d then
     begin low:=1;high:=d+mid;end;
    if mid<d then
     begin low:=d-mid;high:=d+mid;end;
    fillchar(f,sizeof(f),0);
    f[0]:=1;sum:=0;
    for i:=1 to jl[n] do
     begin
      if a[i]=0 then continue;max:=0;
      check:=false;
      for j:=low to high do
       begin
        if i-j<0 then break;
        if a[i-j]=0 then continue;
        if f[i-j]>max then
         begin check:=true;max:=f[i-j];end;
       end;
      if (check)or(max>0) then
       begin f[i]:=a[i]+max;x:=f[i]end
       else begin x:=k;break;end;
      if x>k then break;
     end;
    if x>k then r:=mid
     else l:=mid+1;
   end;
  write(r);
  close(input);close(output);
end.
