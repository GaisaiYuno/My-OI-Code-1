var
  i,j,g,n,d,k:longint;
  x,s:array[0..500001]of longint;
begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);
  rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
    readln(x[i],s[i]);
  writeln('-1');
  close(input);
  close(output);
end.
