var
        a:array[0..1000]of longint;
        n,m,i,j,p,q:longint;
        bz:boolean;
procedure qsort(l,r:longint);
var
        i,j,mid:longint;
begin
        i:=l; j:=r; mid:=a[(l+r)div 2];
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
        if j>l then qsort(l,j);
end;
function pd(x,y,z:longint):boolean;
var
        s,s1:ansistring;
        i,len,j:longint;
begin
        str(y,s);
        str(z,s1);
        len:=length(s1);
        if length(s)>len then exit(false);
        j:=1;
        for i:=len-x+1 to len do
        begin
                if s[j]<>s1[i] then
                        exit(false)
                else
                        inc(j);
        end;
        exit(true);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        read(n,m);
        for i:=1 to n do read(a[i]);
        qsort(1,n);
        for i:=1 to m do
        begin
                read(p,q);
                bz:=false;
                for j:=1 to n do
                        if pd(p,q,a[j]) then
                        begin
                                writeln(a[j]);
                                bz:=true;
                                break;
                        end;
                if (not bz) then writeln('-1');
        end;
        close(input);
        close(output);
end.
