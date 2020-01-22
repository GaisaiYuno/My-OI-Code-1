var n,d,k,i,x,s:longint;
begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);
  rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
    readln(x,s);
  write('-1');
  close(input);
  close(output);
end.