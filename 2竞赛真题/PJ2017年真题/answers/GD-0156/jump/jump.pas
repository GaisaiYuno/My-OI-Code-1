var
        n,d,k,i,j,ans,s,x:longint;
        a,y:array[0..10000]of longint;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        for i:=1 to n do
        begin
                readln(a[i],y);
                if a[i]-a[i-1]<>1 then
                begin
                        writeln(-1);
                        halt;
                end;
                s:=s+y[i];
                if s>k then
                begin
                        writeln(1);
                        halt;
                end;
        end;
        close(input);close(output);
end.
