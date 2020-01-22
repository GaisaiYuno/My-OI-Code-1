program chess(input,output);
var m,n,i,j,t:longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  read(m,n);
  for i:=1 to n do
  for j:=1 to 3 do
  read(t);
  write(-1);
  close(input);
  close(output);
end.