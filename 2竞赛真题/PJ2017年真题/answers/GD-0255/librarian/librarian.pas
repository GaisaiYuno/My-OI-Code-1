var
  a:array[1..1000]of longint;
  i,j,n,q,x,y,m,s:longint;
procedure hh(z:longint);
var
  i,l:longint;
begin
  l:=1;
  for i:=1 to z do l:=l*10;
  y:=l;
end;
begin
  assign(input,'librarian.in'); reset(input);
  assign(output,'librarian.out'); rewrite(output);
  readln(n,q);
  for i:=1 to n do readln(a[i]);
  for i:=1 to q do
  begin
    m:=maxlongint;
    readln(x,s);
    hh(x);
    for j:=1 to n do if (a[j] mod y=s)and(a[j]<m) then m:=a[j];
    if m=maxlongint then m:=-1;
    writeln(m);
  end;
  close(input);
  close(output);
end.
