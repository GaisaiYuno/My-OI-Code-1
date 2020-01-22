var i,j,k,n,m,l,r,x,y:longint;
a,b:array[1..700000]of longint;
check:boolean;
procedure f(s,t,max,min,now:longint);
var g,h:longint;
begin
  if max>=k then
  begin
    check:=true;
    exit;
  end;
  for g:=s to t do
  begin
    if check then
    exit;
    for h:=now+1 to n do
    begin
      if a[h]>g+min then
      break;
      if a[h]=g+min then
      begin
        if b[h]>0 then
        f(s,t,max+b[h],a[h],h);
        break;
      end;
    end;
  end;
  for g:=s to t do
  begin
    if check then
    exit;
    for h:=now+1 to n do
    begin
      if a[h]>g+min then
      break;
      if a[h]=g+min then
      begin
        if b[h]<0 then
        f(s,t,max+b[h],a[h],h);
        break;
      end;
    end;
  end;
end;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  read(n,m,k);
  for i:=1 to n do
  read(a[i],b[i]);
  f(1,a[n],0,0,0);
  if not check then
  begin
    writeln(-1);
    close(input);close(output);
    exit;
  end;
  l:=0;
  if m>a[n]div 2 then
  r:=m
  else
  r:=a[n]-m;
  while l<r do
  begin
    check:=false;
    j:=(l+r)div 2;
    if j>m then
    x:=1
    else
    x:=m-j;
    if j+m>a[n]then
    y:=a[n]
    else
    y:=j+m;
    f(x,y,0,0,0);
    if check then
    r:=j
    else
    l:=j+1;
  end;
  write(r);
  close(input);close(output);
end.