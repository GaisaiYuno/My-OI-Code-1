var
        i,j,k,l,n,m,x,y:longint;
        a,z,len:array[1..1000] of longint;
        bz,bz1:boolean;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do
        begin
                readln(a[i]);
                k:=a[i];
                while k>0 do
                begin
                        k:=k div 10;
                        inc(len[i]);
                end;
        end;
        for i:=1 to n-1 do
        begin
                for j:=i to n do
                begin
                        if a[i]>a[j] then
                        begin
                                k:=a[i];
                                a[i]:=a[j];
                                a[j]:=k;
                                k:=len[i];
                                len[i]:=len[j];
                                len[j]:=k;
                        end;
                end;
        end;
        for i:=1 to m do
        begin
                readln(x,y);
                bz1:=true;
                for j:=1 to n do
                begin
                        if len[j]>=x then
                        begin
                                bz:=true;
                                k:=y;
                                l:=a[j];
                                while (k>0) and (l>0) do
                                begin
                                        if k mod 10<>l mod 10 then
                                        begin
                                                bz:=false;
                                                break;
                                        end;
                                        k:=k div 10;
                                        l:=l div 10;
                                end;
                                if bz then
                                begin
                                        bz1:=false;
                                        writeln(a[j]);
                                        break;
                                end;
                        end;
                end;
                if bz1 then
                begin
                        writeln(-1);
                end;
        end;
        close(input);close(output);
end.
