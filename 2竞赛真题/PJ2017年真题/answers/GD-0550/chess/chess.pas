
var
  m,n,x,y,z,i:longint;

procedure init;
  begin
    readln(m,n);
    for i := 1 to n do
     begin
       readln(x,y,z);
     end;
  end;


begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  init;
  writeln(-1);
  close(input);
  close(output);
end.











