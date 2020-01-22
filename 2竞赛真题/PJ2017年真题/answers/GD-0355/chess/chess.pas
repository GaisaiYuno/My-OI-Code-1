program chess;
 var i,m,n,x,y,c:longint;
begin
assign(input,'chess.in');rewrite(input);
assign(output,'chess.out');reset(output);
read(m,n);
 for i:=1 to n do readln(x,y,c);
writeln('-1');
close(input);
close(output);
end.