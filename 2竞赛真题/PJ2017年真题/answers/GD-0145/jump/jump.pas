var
        x,s,n,d,k,i,j:longint;
        a:array[0..2000]of longint;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        for i:=1 to n do
        begin
                readln(x,s);
                if s>0 then a[x mod d]:=a[x mod d]+s;
        end;
        for i:=1 to 2000 do
        begin
                j:=j+a[i];
                if j>=k then
                begin
                        writeln(i);
                        close(input);
                        close(output);
                        exit;
                end;
        end;
        writeln(-1);
        close(input);
        close(output);
end.