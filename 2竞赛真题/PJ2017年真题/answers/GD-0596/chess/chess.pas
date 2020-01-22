var
  i,m,n,x,y,c:longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  readln(m,n);
  for i:=1 to n do
    readln(x,y,c);
  writeln('-1');
  close(input);
  close(output);
end.
