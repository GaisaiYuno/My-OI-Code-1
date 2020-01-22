var i,j,k,l:longint;
begin
  assign(output,'chess.in'); rewrite(output);
  writeln(100,' ',10000);
  for i:=1 to 100 do
    for j:=1 to 100 do
      writeln(i,' ',j,' ',1);
end.
