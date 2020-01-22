var a,b:array[-11..1111] of longint;
    //b:array[-11..1111] of longint;
    n,m,i,j,k,t,s:longint;
    f:boolean;
procedure qsort(l,r:longint);
var i,j,mid:longint;
begin
  i:=l; j:=r; mid:=a[(i+j) div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
    begin
      a[0]:=a[i]; a[i]:=a[j]; a[j]:=a[0];
      b[0]:=b[i]; b[i]:=b[j]; b[j]:=b[0];
      inc(i); dec(j);
    end;
  until i>j;
  if j>l then qsort(l,j);
  if i<r then qsort(i,r);
end;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  read(n,m);
  for i:=1 to n do
  begin
    read(a[i]); s:=a[i];
    while s>0 do
    begin
      inc(b[i]);
      s:=s div 10;
    end;
  end;
  qsort(1,n);
  for i:=1 to m do
  begin
    read(s);
    read(s);
    for j:=1 to n do
    begin
      t:=1; f:=false;
      for k:=1 to b[j] do
      begin
        t:=t*10;
        if s=a[j] mod t then
        begin
          f:=true; break;
        end;
      end;
      if f then
      begin
        writeln(a[j]); break;
      end;
    end;
    if not f then writeln(-1);
  end;
  close(input);
  close(output);
end.

















