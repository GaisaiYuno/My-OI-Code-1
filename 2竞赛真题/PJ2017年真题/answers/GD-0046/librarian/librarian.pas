var n,q:longint;
    i,j:longint;
    a:array[0..2500]of longint;
    len,x:longint;
    ten:array[0..20]of longint;
    ok:boolean;
procedure qs(l,r:longint);
var
  i,j,t,m:longint;
begin
  i:=l;
  j:=r;
  m:=a[(l+r)>>1];;
  repeat
    while a[i]<m do inc(i);
    while a[j]>m do dec(j);
    if i<=j then
    begin
      t:=a[i];a[i]:=a[j];a[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then qs(l,j);
  if i<r then qs(i,r);
end;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  read(n,q);
  for i:=1 to n do
  read(a[i]);
  qs(1,n);
  ten[0]:=1;
  for i:=1 to 8 do
  ten[i]:=ten[i-1]*10;
  for i:=1 to q do
  begin
    read(len,x);
    ok:=false;
    for j:=1 to n do
    if (a[j] mod ten[len]=x) then
    begin
      writeln(a[j]);
      ok:=true;
      break;
    end;
    if not ok then writeln(-1);
  end;
  close(input);
  close(output);
end.
