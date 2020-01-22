var
        a:array[0..1005] of longint;
        mi:array[0..8] of longint;
        n,i,q,j,x,y:longint;
        p:boolean;
procedure qsort(x,y:longint);
var
        i,j,mid:longint;
begin
        i:=x;
        j:=y;
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
        if i<y then qsort(i,y);
        if x<j then qsort(x,j);
end;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        readln(n,q);
        for i:=1 to n do
                read(a[i]);
        mi[0]:=1;
        for i:=1 to 8 do
                mi[i]:=mi[i-1]*10;
        qsort(1,n);
        for i:=1 to q do
        begin
                read(x,y);
                p:=false;
                for j:=1 to n do
                begin
                        if a[j] mod mi[x]=y then
                        begin
                                writeln(a[j]);
                                p:=true;
                                break;
                        end;
                end;
                if not p then
                        writeln(-1);
        end;
        close(input);
        close(output);
end.
