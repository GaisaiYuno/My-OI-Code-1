var
        m,n,i,x,y,z:longint;
        a:array[1..100,1..100]of longint;
begin
        assign(output,'chess.in');rewrite(output);
        randomize;
        m:=50;
        n:=1000;
        writeln(m,' ',n);
        for i:=1 to n do
        begin
                x:=random(m)+1;
                y:=random(m)+1;
                while a[x,y]=1 do
                begin
                        x:=random(m)+1;
                        y:=random(m)+1;
                end;
                a[x,y]:=1;
                z:=random(2)+1;
                writeln(x,' ',y,' ',z);
        end;
        close(output);
end.