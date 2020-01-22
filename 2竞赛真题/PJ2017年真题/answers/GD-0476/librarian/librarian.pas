var n,m,i,j,c:longint;
    z1,z2:string;
    b:array[0..1005] of longint;
    d:array[0..1005,0..5] of longint;
procedure sort(l,r:longint);
var t,mid:longint;
begin
  i:=l;j:=r;mid:=b[(l+j) div 2];
  while i<=j do
  begin
    while b[i]<mid do inc(i);
    while b[j]>mid do dec(j);
    if i<=j then
    begin
      t:=b[i];
      b[i]:=b[j];
      b[j]:=t;
      inc(i);dec(j);
    end;
  end;
  if i<r then sort(i,r);
  if l<j then sort(l,j);
end;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    readln(b[i]);
  sort(1,n);
  for i:=1 to m do
    read(d[i,1],d[i,2]);
 for i:=1 to m do
  begin
    str(d[i,2],z2);
    for j:=1 to n do
    begin
      str(b[j],z1);
      if copy(z1,length(z1)-d[i,1]+1,d[i,1])=z2 then
      begin
        writeln(z1);
        break;
      end;
      if j=n then writeln('-1');
    end;
  end;
  close(input);
  close(output);
end.
