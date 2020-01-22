var
        b:boolean;
        st:string;
        w,s,a,p:array [1..1000] of longint;
        l:array [1..9] of longint;
        i,j,q,n,med:longint;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        readln(n,q);
        l[1]:=10;
        for i:=2 to 9 do
                l[i]:=l[i-1]*10;
        for i:=1 to n do
        begin
                readln(st);
                val(st,a[i]);
                w[i]:=length(st);
        end;
        for i:=1 to q do
                readln(s[i],p[i]);
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if a[j]<a[i] then
                        begin
                                med:=a[i];a[i]:=a[j];a[j]:=med;
                                med:=w[i];w[i]:=w[j];w[j]:=med;
                        end;
        for i:=1 to q do
        begin
                b:=true;
                for j:=1 to n do
                        if (w[j]>=s[i]) and ((a[j] mod l[s[i]])=p[i]) then
                        begin
                                b:=false;
                                writeln(a[j]);
                                break;
                        end;
                if (b=true) then writeln(-1);
        end;
        close(input);
        close(output);
end.