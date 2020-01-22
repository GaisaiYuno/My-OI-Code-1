uses math;
var
 a:array[0..500000,1..2]of longint;
 f:array[0..500000]of int64;
 n,d,k,sum,l,r,ans,mid,i:longint;
 p:boolean;
procedure dg(x,sum:int64);
var
 i,k:longint;
begin
 k:=d-mid;
 if k<1 then k:=1;
 for i:=x+1 to n do begin
  if(a[i,1]>a[x,1]+d+mid)or(p)then exit;
  if(a[i,1]>=a[x,1]+k)and(sum+a[i,2]>f[i])then begin
   f[i]:=sum+a[i,2];
   if f[i]>=k then begin
    p:=true;
    exit;
   end;
   dg(i,sum+a[i,2]);
  end;
 end;
end;
begin
 assign(input,'jump.in');reset(input);
 assign(output,'jump.out');rewrite(output);
 read(n,d,k);
 for i:=1 to n do read(a[i,1],a[i,2]);
 ans:=-1;
 l:=0;
 r:=a[n,1];
 while l<=r do begin
  mid:=(l+r)div 2;
  fillchar(f,sizeof(f),0);
  p:=false;
  dg(0,0);
  if p then begin
   ans:=mid;
   r:=mid-1;
  end else l:=mid+1;
 end;
 write(ans);
end.
