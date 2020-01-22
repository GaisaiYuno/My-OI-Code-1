var
        n,q,i,j,k,l,x,bz,y,m,p,bz1:longint;
        a,b:array[0..1001] of longint;
procedure kp(l,r:longint);
var
        i,j:longint;
        m:longint;
begin
        i:=l;
        j:=r;
        m:=a[(l+r) div 2];
        repeat
                while a[i]<m do
                        inc(i);
                while a[j]>m do
                        dec(j);
                if i<=j then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then kp(i,r);
        if l<j then kp(l,j);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,q);
        for i:=1 to n do
        begin
                readln(a[i]);
        end;
        kp(1,n);
        for i:=1 to q do
        begin
                read(x,y);
                bz1:=0;
                for j:=1 to n do
                begin
                        k:=a[j];
                        l:=y;
                        bz:=0;
                        while (l>0) do
                        begin
                                m:=k mod 10;
                                p:=l mod 10;
                                if m=p then
                                begin
                                        l:=l div 10;
                                        k:=k div 10;
                                end
                                else
                                begin
                                        bz:=1;
                                        break;
                                end;
                        end;
                        if bz=0 then
                        begin
                                writeln(a[j]);
                                bz1:=1;
                                break;
                        end;
                end;
                if bz1=0 then writeln(-1);
        end;
        close(input);close(output);
end.