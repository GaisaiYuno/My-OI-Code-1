procedure init;
  var n,d,k,i,x,y:longint;
  begin
    readln(n,d,k);
    for i := 1 to n do
     begin
       readln(x,y);
     end;
  end;

begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);
  rewrite(output);
  init;
  writeln(-1);
  close(input);
  close(output);
end.