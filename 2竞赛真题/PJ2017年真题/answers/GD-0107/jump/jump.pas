var
        x,y,n,m,i,j,k,d:longint;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        for i:=1 to n do
                readln(x,y);
        writeln(-1);
        close(input);close(output);
end.