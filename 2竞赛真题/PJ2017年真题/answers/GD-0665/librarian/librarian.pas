program librarian;
var
  ten:array[0..8] of longint;
  a,x,k:array[1..1000] of longint;
  i,j,n,q:longint; b:boolean;
procedure qsort(l,r:longint);
var i,j,mid,p:longint;
begin
  i:=l; j:=r; mid:=a[(l+r) div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then begin
      p:=a[i]; a[i]:=a[j]; a[j]:=p;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;
begin
  assign(input,'librarian.in'); reset(input);
  assign(output,'librarian.out'); rewrite(output);
  readln(n,q);
  ten[0]:=1;
  for i:=1 to 8 do ten[i]:=ten[i-1]*10;
  for i:=1 to n do readln(a[i]);
  qsort(1,n);
  for i:=1 to q do begin
    readln(k[i],x[i]); b:=false;
    for j:=1 to n do
      if a[j] mod ten[k[i]]=x[i] then begin b:=true; break; end;
    if b then writeln(a[j]) else writeln(-1);
  end;
  close(input); close(output);
end.
