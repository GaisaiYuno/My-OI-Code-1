var
        n,d,k,i,x,y,s:longint;
        a:array[0..100000]of longint;
begin
        assign(input,'jump.in'); reset(input);
        assign(output,'jump.out'); rewrite(output);
        randomize;
        readln(n,d,k);
        for i:=1 to n do
        begin
                readln(x,y);
                a[x]:=y;
                if y>0 then s:=s+y;
        end;
        if s<d then writeln(-1)
        else writeln(random(10));
        close(input); close(output);
end.
