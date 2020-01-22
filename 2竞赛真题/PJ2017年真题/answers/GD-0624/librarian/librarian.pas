var
        a:array[0..100010]of longint;
        m:array[1..9]of longint;
        n,q,i,j,n1,n2:longint;
        bz:boolean;
procedure qsort(l,r:longint);
var
        i,j,mid:longint;
begin
        i:=l;j:=r;
        mid:=a[(i+j) div 2];
        repeat
                while a[i]<mid do inc(i);
                while a[j]>mid do dec(j);
                if i<=j then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
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
        m[1]:=10;
        for i:=2 to 9 do m[i]:=m[i-1]*10;
        for i:=1 to n do readln(a[i]);
        qsort(1,n);
        for i:=1 to q do
        begin
                readln(n1,n2);
                bz:=false;
                for j:=1 to n do
                begin
                        if a[j] mod m[n1]=n2 then
                        begin
                                writeln(a[j]);
                                bz:=true;
                                break;
                        end;
                end;
                if bz=false then writeln(-1);
        end;
        close(input);close(output);
end.
