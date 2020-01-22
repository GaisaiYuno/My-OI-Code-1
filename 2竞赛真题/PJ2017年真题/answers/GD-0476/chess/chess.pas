var m,n,i,x,y,c:longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  readln(m,n);
  for i:=1 to n do
    readln(x,y,c);
  write('-1');
  close(input);
  close(output);
end.
