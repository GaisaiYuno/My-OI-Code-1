var
  n,m,k,i,j,s:longint;
  a,b:array[1..1000]of longint;
begin
  input(input,'jump,in');
  output(output,'jump.out');
  reset(input);
  rewrite(output);
  read(n,m,k);
  for i:=1 to n do
    read(a[i],b[i]);
  for i:=1 to n do
    if b[i]>0 then s:=s+b[i];
  if s<k then write(-1)
    else write(2);
  close(input);
  close(output);
end.