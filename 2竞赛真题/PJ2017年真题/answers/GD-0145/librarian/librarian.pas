var
        n,m,i,j,s,x,y,k:longint;
        a:array[0..1001]of longint;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do readln(a[i]);
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if a[i]>a[j] then
                        begin
                                a[0]:=a[i];
                                a[i]:=a[j];
                                a[j]:=a[0];
                        end;
        for i:=1 to m do
        begin
                readln(y,x);
                k:=1;
                for j:=1 to y do k:=k*10;
                for j:=1 to n+1 do
                begin
                        if a[j] mod k=x then
                        begin
                                writeln(a[j]);
                                break;
                        end;
                        if j=n+1 then
                        begin
                                writeln('-1');
                                break;
                        end;
                end;
        end;
        close(input);
        close(output);
end.