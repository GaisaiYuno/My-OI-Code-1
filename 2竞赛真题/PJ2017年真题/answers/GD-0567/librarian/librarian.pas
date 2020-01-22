var
        a:array[1..1000]of longint;
        n,i,x,y,j,k,l,q:longint;
        bz:boolean;
        t,t1:string;
procedure qsort(l,r:longint);
var
        i,j,mid,t:longint;
begin
        i:=l;
        j:=r;
        mid:=a[(i+j)div 2];
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
                readln(a[i]);
        qsort(1,n);
        for i:=1 to q do
        begin
                readln(x,y);
                str(y,t);
                for j:=1 to n do
                begin
                        str(a[j],t1);
                        if length(t)>=x then
                        begin
                                bz:=true;
                                l:=length(t1);
                                for k:=1 to x do
                                begin
                                        if t1[l-k+1]<>t[x-k+1] then
                                        begin
                                                bz:=false;
                                                break;
                                        end;
                                end;
                                if bz=true then
                                begin
                                        writeln(a[j]);
                                        break;
                                end;
                        end;
                end;
                if bz=false then writeln('-1');
        end;
        close(input);
        close(output);
end.
