var
  i,j,n,k,d,t,x,s:longint;
begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
  begin
    readln(x,s);
    if s>0 then t:=t+x;
  end;
  if t>=k then write(d-1) else write(-1);
close(input);
close(output);
end.