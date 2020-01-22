var i,m,n,k,zhong,da,da1:longint;
a,b:array[1..1000]of longint;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  readln(m,n,k);
  for i:=1 to n do
  begin
  read(a[i],b[i]);
  if b[i]>0 then
  zhong:=zhong+b[i];
  if b[i]<da then
  begin
    da1:=a[i];
    da:=b[i];
  end;
  end;
  if zhong<k then writeln(-1)
  else writeln(da1);
  close(input);
  close(output);
end.



