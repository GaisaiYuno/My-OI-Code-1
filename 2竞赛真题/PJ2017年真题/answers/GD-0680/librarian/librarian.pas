var
        i,j,k,l,n,m,ans,p:longint;
        t:boolean;
        a,b:array[0..2000]of longint;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        read(n,p);
        for i:=1 to n do
                read(a[i]);
        for i:=1 to p do
        begin
                read(l,k);
                l:=k;
                m:=1;
                while l>0 do
                begin
                        l:=l div 10;
                        m:=m*10;
                end;
                ans:=maxlongint;
                t:=false;
                for j:=1 to n do
                        if (ans>a[j])and(a[j] mod m=k) then
                        begin
                                ans:=a[j];
                                t:=true;
                        end;
                if t then
                        writeln(ans)
                else writeln(-1);
        end;
        close(input);
        close(output);
end.