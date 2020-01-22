var
  n,k,d,i,c,g,h:longint;
begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);
  rewrite(output);
  read(n,d,k);
  for i:=1 to n do
    begin
      read(g,h);
      c:=c+h;
    end;
  if c>=k then write(0)
          else write('-',1);
  close(input);
  close(output);
end.
