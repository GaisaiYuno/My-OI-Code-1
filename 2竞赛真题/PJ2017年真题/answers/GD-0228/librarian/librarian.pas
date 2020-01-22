var n,q,i,j,k,l,m,o:longint;
    p:boolean;
    a:array[1..5000] of longint;
procedure ss(l,r:longint);
var x,y,mid,z:longint;
begin
  x:=l;
  y:=r;
  mid:=a[(x+y) div 2];
  while x<=y do begin
    while a[x]<mid do inc(x);
    while a[y]>mid do dec(y);
    if(x<=y) then begin
      z:=a[x];
      a[x]:=a[y];
      a[y]:=z;
      inc(x);
      dec(y);
    end;
  end;
  if(x<r)then ss(x,r);
  if(l<y)then ss(l,y);
end;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(n,q);
  for i:=1 to n do readln(a[i]);
  ss(1,n);
  for i:=1 to q do begin
    readln(k,l);
    m:=1;
    for o:=1 to k do m:=m*10;
    p:=false;
    for j:=1 to n do if(a[j] mod m=l)then begin
      writeln(a[j]);
      p:=true;
      break;
    end;
    if(not p)then writeln(-1);
  end;
  close(input);
  close(output);
end.