var a,s,d,g,h,x:longint;
    f:array[1..10000] of int64;
    y:int64;
    p:boolean;
procedure ss(l,r:longint);
var i,j,t,k:longint;
begin
  i:=l;
  j:=r;
  k:=f[(l+r) div 2];
  repeat
    while f[i]<k do inc(i);
    while f[j]>k do dec(j);
    if i<=j then begin
      t:=f[i];
      f[i]:=f[j];
      f[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then ss(l,j);
  if r>i then ss(i,r);
end;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(a,s);
  for d:=1 to a do readln(f[d]);
  ss(1,a);
  for d:=1 to s do begin
    readln(x,y);
    g:=1;
    for h:=1 to x do g:=g*10;
    p:=true;
    for h:=1 to a do if f[h] mod g=y then begin
      writeln(f[h]);
      p:=false;
      break;
    end;
    if p then writeln(-1);
  end;
  close(input);
  close(output);
end.
