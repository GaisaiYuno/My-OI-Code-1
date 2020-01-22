var
        n,d,k:int64;
        i:longint;
        x,s:array [1..500000] of longint;
begin
        assign(input,'jump.in');
        reset(input);
        assign(output,'jump.out');
        rewrite(output);
        read(n,d);
        readln(k);
        for i:=1 to n do
                read(x[i],s[i]);
        write('-1');
        close(input);
        close(output);
end.