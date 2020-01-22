var
        a,b:array[1..1000]of longint;
        i,j,n,m,k,o,p,l:longint;
procedure kp(r,l:longint);
var
        i,j,o,p:longint;
begin
        i:=r;
        j:=l;
        p:=a[i];
        repeat
                while a[i]<p do inc(i);
                while a[j]>p do dec(j);
                if i<=j then
                begin
                        o:=a[i];
                        a[i]:=a[j];
                        a[j]:=o;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if j>r then kp(r,j);
        if i<l then kp(i,l);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        read(n,m);
        for i:=1 to n do read(a[i]);
        kp(1,n);
        for i:=1 to m do
        begin
                read(o,p);
                l:=1;
                k:=0;
                for j:=1 to o do l:=l*10;
                for j:=1 to n do
                if a[j] mod l=p then
                begin
                        k:=1;
                        writeln(a[j]);
                        break;
                end;
                if k=0 then writeln('-1');
        end;
        close(input);close(output);
end.
