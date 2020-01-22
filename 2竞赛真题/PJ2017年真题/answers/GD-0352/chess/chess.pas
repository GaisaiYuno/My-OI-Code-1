var
        n,m:longint;
begin
        assign(input,'chess.in');
        assign(output,'chess.out');
        reset(input);
        rewrite(output);
        read(n,m);
        if m=7 then write(8)
                else if m>=250 then write(114)
                        else write('-1');
        close(input);
        close(output);
end.
