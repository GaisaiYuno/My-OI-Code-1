var
        s,i,j,k,l,n,m,ans:longint;
        a,b,c:array[0..10000] of longint;
procedure kp(l,r:longint);
var
        i,j,mid:longint;
begin
        {i:=l;
        j:=r;
        mid:=a[(l+r) div 2];
        repeat
                if (a[i]<mid) then inc(i);
                if (a[j]>mid) then dec(j);
                if (i<=j) then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        inc(i);
                        dec(j);
                end;
        until(i>j);
        if (i<r) then kp(i,r);
        if (l<j) then kp(l,j);}
        for i:=1 to r-1 do
                for j:=i+1 to r do
                        if (a[i]>a[j]) then
                        begin
                                a[0]:=a[i];
                                a[i]:=a[j];
                                a[j]:=a[0];
                        end;
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to m do
                readln(b[i],c[i]);
        kp(1,n);
        for i:=1 to m do
        begin
                ans:=-1;
                s:=1;
                for j:=1 to b[i] do
                        s:=s*10;
                for j:=1 to n do
                        if (a[j] mod s=c[i]) then
                        begin
                                ans:=a[j];
                                break;
                        end;
                writeln(ans);
        end;
        close(input);
        close(output);
end.
