var n,q,i,j,k,l,m:longint;
    b:boolean;
    a:array[-10..1100] of longint;
procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); j:=j-1;
    end;
  until i>j;
  if l<j then
    sort(l,j);
  if i<r then
    sort(i,r);
end;
begin
  assign(input,'librarian.in'); reset(input);
  assign(output,'librarian.out'); rewrite(output);
  readln(n,q);
  for i:=1 to n do
    readln(a[i]);
  sort(1,n);
  for i:=1 to q do
  begin
    readln(l,m);
    b:=false;
    k:=1;
    for j:=1 to l do
      k:=k*10;
    for j:=1 to n do
      if a[j] mod k=m then
      begin
        b:=true; break;
      end;
    if b then writeln(a[j])
    else writeln(-1);
  end;
  close(input); close(output);
end.
