const t:array[1..8]of longint
        =(10,100,1000,10000,100000,1000000,10000000,100000000);
var i,j,k,x,y,n,q:longint;
    a:array[1..1000]of longint;
    b:boolean;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;x:=a[(i+j)div 2];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
    begin
      y:=a[i];
      a[i]:=a[j];
      a[j]:=y;
      inc(i);
      dec(j);
    end;
  until i>=j;
  if i<r then sort(i,r);
  if l<j then sort(l,j);
end;

begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(n,q);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  for i:=1 to q do
  begin
    readln(x,y);
    x:=t[x];
    b:=false;
    for j:=1 to n do
      if a[j] mod x=y then begin
                             writeln(a[j]);
                             b:=true;
                             break;
                           end;
    if b=false then writeln(-1);
  end;
  close(input);close(output);
end.