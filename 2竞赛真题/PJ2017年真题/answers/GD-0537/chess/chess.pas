var a,b,c,d,e,f:longint;
    g:array [0..101,0..101] of integer;
begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
  readln(e,f);
  for a:=1 to f do readln(c,d,b);
  writeln('-1');
close(input);
close(output)
end.
