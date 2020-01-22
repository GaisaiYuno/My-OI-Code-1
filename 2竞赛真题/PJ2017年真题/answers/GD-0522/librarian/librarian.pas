var
        a:array[0..1001]of longint;
        d:array[0..10]of longint;
        n,q,i,k,j,h,t:longint;
        bz:boolean;
procedure qsort(l,r:longint);
var
        i,j,h,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=a[(l+r)div 2];
        repeat
                while a[i]<mid do
                        inc(i);
                while a[j]>mid do
                        dec(j);
                if i<=j then
                        begin
                                h:=a[i];
                                a[i]:=a[j];
                                a[j]:=h;
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if i<r then
                qsort(i,r);
        if l<j then
                qsort(l,j);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        k:=1;
        for i:=1 to 9 do
                begin
                        k:=k*10;
                        d[i]:=k;
                end;
        read(n,q);
        for i:=1 to n do
                read(a[i]);
        qsort(1,n);
        for i:=1 to q do
                begin
                        read(t,k);
                        bz:=false;
                        for j:=1 to n do
                                if a[j] mod d[t]=k then
                                        begin
                                                bz:=true;
                                                break;
                                        end;
                        if bz=true then
                                begin
                                        writeln(a[j]);
                                end
                        else
                                begin
                                        writeln('-1');
                                end;
                end;
        close(input);
        close(output);
end.