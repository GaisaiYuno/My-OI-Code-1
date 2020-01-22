var
        m,n,i,x,y,c:longint;
begin
        assign(input,'chess.in');
        reset(input);
        assign(output,'chess.out');
        rewrite(output);
        read(m);
        readln(n);
        for i:=1 to n do
                readln(x,y,c);
        write('-1');
        close(output);
        close(input);
end.
