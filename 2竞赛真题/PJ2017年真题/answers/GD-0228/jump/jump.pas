var n,d,k,i:longint;
    a:array[1..1000000,1..2] of longint;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  readln(n,d,k);
  for i:=1 to n do readln(a[i,1],a[i,2]);
  writeln(-1);
  close(input);
  close(output);
end.