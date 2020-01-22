Program librarian;
var
        n,m,i,j,t,x,k,q,r,o,re:longint;
        a:array[1..1010] of longint;
begin
        assign(input,'librarian.in');
        assign(output,'librarian.out');
        reset(input);
        rewrite(output);
        read(n,m);
        for i:=1 to n do read(a[i]);
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if a[i]>a[j] then
                        begin
                                t:=a[i];
                                a[i]:=a[j];
                                a[j]:=t;
                        end;
        r:=10;
        x:=10;
        for i:=1 to m do
        begin
                read(t,q);
                for k:=1 to t-1 do
                        x:=x*r;
                for j:=1 to n do
                begin
                        o:=a[j] mod x;
                        if o=q then
                        begin
                                writeln(a[j]);
                                x:=10;
                                re:=1;
                                break;
                        end;
                end;
                if re<>1 then writeln('-1');
                re:=0;
                x:=10;
        end;
        close(input);
        close(output);
end.
