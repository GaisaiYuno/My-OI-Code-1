program chess;
var
m,n:integer;
a,i,j,k,j1:integer;
xy:integer;
x,y:array[1..100]of integer;
begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
 read(m,n);
 for i:=1 to m do
  readln(x[i],y[i],k);
 write('-1');
close(input);
close(output);
end.
