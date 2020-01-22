var
        n,q,i,j,x,p,s:longint;
        a:array[1..1000] of longint;
        z:array[1..9] of longint;
begin
        assign(input,'librarian.in'); reset(input);
        assign(output,'librarian.out'); rewrite(output);
        readln(n,q);
        z[1]:=10;
        for i:=2 to 9 do
                z[i]:=z[i-1]*10;
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to q  do
        begin
                readln(x,p);
                s:=maxlongint;
                for j:=1 to n do
                        if (a[j] mod z[x]=p) and (a[j]<s) then s:=a[j];
                if s=maxlongint then writeln(-1) else writeln(s);
        end;
        close(input);
        close(output);
end.