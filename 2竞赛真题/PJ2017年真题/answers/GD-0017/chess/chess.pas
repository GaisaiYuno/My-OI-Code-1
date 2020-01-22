var
    n,m,i,x,y,z:longint;
begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
    readln(n,m);
    for i:=1 to m do
    begin
        readln(x,y,z);
    end;
    writeln('-1');
close(input);
close(output);
end.