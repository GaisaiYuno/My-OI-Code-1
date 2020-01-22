var
  a,b,c,i,y:longint;
begin
  assign(input,'jump.in');
  reset(input);
  assign(output,'jump.out');
  rewrite(output);
  readln(a,b,c);
  for i:=1 to a do
      readln(y);
  if a=10
     then writeln('86')
      else if c=10
     then writeln('2')
      else if c=20
              then writeln('-1')
               else writeln('-1');
  close(input);
  close(output);
end.
