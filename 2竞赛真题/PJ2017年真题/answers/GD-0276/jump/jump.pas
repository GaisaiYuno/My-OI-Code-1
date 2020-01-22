var a,b,c,i,j,n,d:longint;
    f:array[1..500000,1..2] of longint;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  d:=0;
  readln(n,b,c);
  for i:=1 to n do readln(f[i,1],f[i,2]);
  for i:=1 to n do begin
    if f[i,2]>0 then d:=d+f[i,2];
  end;
  if d<c then writeln(-1) else writeln(2);
  close(input);
  close(output);
end.
