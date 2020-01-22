var
        d:array[0..2000]of longint;
        a:array[0..10]of longint;
        s,s1:string;
        n,q,i,j,x,ans,y,m:longint;
procedure qsort(l,r:longint);
var
        i,j,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=d[(l+r) div 2];
        repeat
                while d[i]>mid do inc(i);
                while d[j]<mid do dec(j);
                if i<=j then
                begin
                        d[0]:=d[i];
                        d[i]:=d[j];
                        d[j]:=d[0];
                        inc(i); dec(j);
                end;
        until i>j;
        if l<j then qsort(l,j);
        if i<r then qsort(i,r);
end;
begin
        assign(input,'librarian.in'); reset(input);
        assign(output,'librarian.out'); rewrite(output);
        readln(n,q);
        for i:=1 to n do
        begin
                readln(d[i]);
        end;
        qsort(1,n);
        for i:=1 to 9 do
                a[i]:=n;
        for j:=1 to q do
        begin
                readln(x,y);
                str(y,s);
                ans:=0;
                for i:=a[x] downto 1 do
                begin
                        str(d[i],s1);
                        m:=length(s1);
                        if m<=x then
                                if a[x]>d[i] then a[x]:=i;
                        delete(s1,1,m-x);
                        if s=s1 then
                        begin
                                ans:=d[i];
                                break;
                        end;
                end;
                if ans=0 then writeln(-1)
                else writeln(ans);
        end;

        close(input); close(output);
end.
