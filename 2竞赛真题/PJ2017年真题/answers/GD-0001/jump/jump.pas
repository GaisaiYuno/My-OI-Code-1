program jump;
var a,b:array[1..500000] of longint;
    i,j,k,l,m,n,o,p:longint;
begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input); rewrite(output);
  readln(n,m,l); j:=0; i:=0;
  for k:=1 to n do
      begin
      readln(o,p);
      if p>0 then begin
         inc(j); a[j]:=o; b[j]:=p;
         end;
      end;
  o:=1; p:=1;
  for k:=1 to j do
      if a[k+1]-a[k]>o
         then o:=a[k+1]-a[k]
         else if a[k+1]-a[k]<p
            then p:=a[k+1]-a[k];
  for k:=1 to j do
      i:=i+a[k];
  while m-o>p do inc(o);
  if i<l then write(-1)
      else write(o);
  close(input); close(output);
end.