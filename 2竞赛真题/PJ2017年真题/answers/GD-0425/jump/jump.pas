var
        a:array [0..500000] of longint;
        b:array [1..500000] of longint;
        n,i,j,d,k,t,x,y,ju,tot,ans,g:longint;
function pd(l,r,w:longint):longint;
        var
                i:longint;
        begin
                if l>=1 then
                begin
                        for i:=l to r do
                        begin
                                if (w mod i=0) or (w mod i>=l) then
                                begin
                                        exit((r-l) div 2);
                                end;
                        end;
                end
                else exit((r-l) div 2);
                pd:=pd(l-1,r+1,w);
        end;
begin
        assign(input,'jump.in'); reset(input);
        assign(output,'jump.out'); rewrite(output);

        readln(n,d,k);
        ans:=0;
        g:=0;
        ju:=-maxlongint;
        for i:=1 to n do
        begin
                read(b[i]);
                read(a[b[i]]);
                if a[b[i]]>0 then inc(tot,a[b[i]]);
                inc(t,a[b[i]]);
        end;
        if tot<k then
        begin
                writeln(-1);
                close(input);
                close(output);
        end;
        if (d=1) and (tot>=k) then
        begin
                if (t>=k) then writeln(0)
                else writeln(1);
                close(input);
                close(output);
        end;
        for i:=1 to n do
        begin
                if a[b[i]]>0 then
                begin
                        ju:=pd(d-g,d+g,b[i]);
                        inc(ans,a[b[i]]);
                end;
                if ju>g then
                begin
                        g:=ju;
                end;
                if ans>=k then
                begin
                        writeln(ju);
                        close(input); close(output);
                end;
        end;
end.
