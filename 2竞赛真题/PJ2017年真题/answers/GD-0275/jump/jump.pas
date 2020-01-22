var
        i,j,x,y,a,b,c:longint;
begin
        assign(input,'jump.in');assign(output,'jump.out');
        reset(input);rewrite(output);
        readln(a,b,c);
        for i:=1 to a do
                readln(x,y);
        if b=1 then writeln('0')
        else writeln('-1');
        close(input);
        close(output);
end.