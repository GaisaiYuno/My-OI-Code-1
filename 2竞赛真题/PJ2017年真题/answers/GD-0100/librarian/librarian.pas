var
        i,j,n,q,min,x,y,len:longint;
        a:array[1..1000]of longint;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,q);
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to q do
        begin
                readln(x,y);
                len:=1;
                for j:=1 to x do
                        len:=len*10;
                min:=maxlongint;
                for j:=1 to n do
                        if (a[j]-y)mod len=0 then
                                if a[j]<min then min:=a[j];
                if min<>maxlongint then writeln(min) else writeln('-1');
        end;
        close(input);close(output);
end.