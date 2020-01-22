var
        a,b,l:array[0..1000]of longint;
        n,m,i,j,k:longint;
        s,s1:string;
        bz:boolean;
procedure dg(l,r:longint);
var
        i,j,m,t:longint;
begin
        i:=l;
        j:=r;
        m:=a[i];
        repeat
                while a[i]<m do
                        inc(i);
                while a[j]>m do
                        dec(j);
                if (i<=j) then
                begin
                        t:=a[i];
                        a[i]:=a[j];
                        a[j]:=t;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if (i<r) then
                dg(i,r);
        if (j>l) then
                dg(l,j);
end;
begin
        assign(input,'librarian.in');
        assign(output,'librarian.out');
        reset(input);
        rewrite(output);
        readln(n,m);
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to m do
                readln(l[i],b[i]);
        dg(1,n);
        for i:=1 to m do
        begin
                bz:=false;
                for j:=1 to n do
                begin
                        str(b[i],s);
                        str(a[j],s1);
                        k:=length(s1);
                        if (pos(s,s1)=k-l[i]+1) and (k>=l[i]) then
                        begin
                                writeln(s1);
                                bz:=true;
                                break;
                        end;
                end;
                if bz=false then
                        writeln(-1);
        end;
        close(input);
        close(output);
end.
