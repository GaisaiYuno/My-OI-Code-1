var
  a:array[1..1000] of longint;
  b,c:array[1..1000] of string[8];
  n,q,i,j,ok,s,w:longint;
procedure jh(var x,y:longint);
var t:longint;
begin
  t:=x;x:=y;y:=t;
end;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,q);
  for i:=1 to n do
      readln(a[i]);
  for i:=1 to q do
      begin
      readln(s,b[i]);
      delete(b[i],1,1);
      end;
  for i:=1 to n do
      for j:=i+1 to n do
          if a[i]>a[j]
             then jh(a[i],a[j]);
  for i:=1 to n do
      str(a[i],c[i]);
  for i:=1 to q do
      begin
      ok:=0;
      for j:=1 to n do
          if copy(c[j],length(c[j])-length(b[i])+1,length(b[i]))=b[i]
             then begin
                  writeln(c[j]);ok:=1;break;
                  end;
      if ok=0
         then writeln('-1');
      end;
  close(input);
  close(output);
end.
