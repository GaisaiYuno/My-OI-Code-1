var
        i,n,d,k,l:longint;
begin
        assign(output,'jump.in');rewrite(output);
        randomize;
        n:=500;
        d:=random(2000)+1;
        k:=random(10000000)+1;
        writeln(n,' ',d,' ',k);
        l:=0;
        for i:=1 to n do
        begin
                l:=l+random(10)+1;
                writeln(l,' ',random(200000)-10000);
        end;
        close(output);
end.
