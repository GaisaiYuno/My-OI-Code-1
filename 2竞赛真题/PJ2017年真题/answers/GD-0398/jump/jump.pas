var
  ju,a:array[0..500001] of longint;
  i,n,d,k,ans,mid,l,r:longint;
  bo:boolean;

function max(x,y:longint):longint;
begin
  if x<y then exit(y)
   else exit(x);
end;

procedure search(now,f:longint);
var
  s,t,i,j,low,high:longint;
begin
  if f>=k then begin
    bo:=true;
    exit;
  end;
  if bo then exit;
  low:=max(1,d-mid);
  high:=d+mid;
  s:=0;
  t:=0;
  for i:=n downto now+1 do
   if ju[i]-ju[now]<=high then begin
     t:=i;
     break;
   end;
  for i:=now+1 to n do
   if ju[i]-ju[now]>=low then begin
     s:=i;
     break;
   end;
  if (s=0) or (t=0) then exit;

  for i:=s to t do
   if f+a[i]>=k then begin
     bo:=true;
     exit;
   end;
  for i:=s to t do begin
    if bo then exit;
    search(i,f+a[i]);
   // if bo then exit;
  end;
  //if bo then write(1);


end;

begin
assign(input,'jump.in');reset(input);
assign(output,'jump.out');rewrite(output);

  readln(n,d,k);
  for i:=1 to n do begin
    readln(ju[i],a[i]);
    if i=1 then ans:=a[i]
    else if a[i]>0 then ans:=ans+a[i];
  end;
  if ans<k then begin
    writeln(-1);
    close(input);close(output);
    halt;
  end;

  l:=0;
  r:=max(ju[n],d);
  while l<r do begin
    mid:=(l+r) div 2;
    bo:=false;
    search(0,0);
    if bo then r:=mid
    else l:=mid+1;
  end;
  writeln(l);

close(input);close(output);
end.
