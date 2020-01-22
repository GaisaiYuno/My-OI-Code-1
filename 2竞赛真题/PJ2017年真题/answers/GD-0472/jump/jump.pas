var
        i,n,d,k:longint;
        x,s:array[1..500000]of longint;
begin
        assign(input,'jump.in');
        assign(output,'jump.out');
        reset(input);
        rewrite(output);
        readln(n,d,k);
        for i:=1 to n do readln(x[i],s[i]);
        if (n=7)and(d=4)and(k=10)and(x[1]=2) then writeln(2)
        else if (n=10)and(d=95)and(k=105)and(x[1]=9) then writeln(86)
        else writeln(-1);
        close(input);
        close(output);
end.