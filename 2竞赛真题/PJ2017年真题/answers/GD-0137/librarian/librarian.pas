var
        ycl:array[1..8] of longint=(10,100,1000,10000,100000,1000000,10000000,100000000);
        a:array[0..1000] of longint;
        b:array[0..1000,1..2] of longint;
        n,q,i,j,k:longint;
procedure qsort(l,r:longint);
var
        i,j,mid,t:longint;
begin
        i:=l;
        j:=r;
        mid:=a[(l+r) div 2];
        repeat
                while a[i]<mid do inc(i);
                while a[j]>mid do dec(j);
                if i<=j then
                begin
                        t:=a[i];
                        a[i]:=a[j];
                        a[j]:=t;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then qsort(i,r);
        if l<j then qsort(l,j);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,q);
        for i:=1 to n do
                read(a[i]);
        for i:=1 to q do
                read(b[i,1],b[i,2]);
        qsort(1,n);
        for i:=1 to q do
        begin
                j:=1;
                while (a[j] mod ycl[b[i,1]]<>b[i,2]) and (j<=q) do inc(j);
                if j>q then writeln(-1)
                else writeln(a[j]);
        end;
        close(input);
        close(output);
end.