var i:longint;
begin
  i:=1;
  assign(output,'jump.in');
  reset(output);
  writeln(-1);
  close(output);
end.