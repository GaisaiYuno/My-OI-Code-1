var
        n,p,i,j:longint;
        s,s1:array[0..2000]of longint;
        l:array[0..2000]of longint;
        mi:array[0..10]of longint;
        bz:boolean;
procedure qsort(l,r:longint);
var
        i,j,mid:longint;
begin
        i:=l;
        j:=r;
        mid:=s[(l+r)div 2];
        repeat
                while s[i]<mid do
                        inc(i);
                while s[j]>mid do
                        dec(j);
                if i<=j then
                begin
                        s[0]:=s[i];
                        s[i]:=s[j];
                        s[j]:=s[0];
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if l<j then
                qsort(l,j);
        if i<r then
                qsort(i,r);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,p);
        for i:=1 to n do
                readln(s[i]);
        for i:=1 to p do
        begin
                read(l[i]);
                readln(s1[i]);
        end;
        qsort(1,n);
        mi[0]:=1;
        for i:=1 to 8 do
                mi[i]:=mi[i-1]*10;
        for i:=1 to p do
        begin
                bz:=false;
                for j:=1 to n do
                begin
                        if (s[j]-s1[i])mod mi[l[i]]=0 then
                        begin
                                bz:=true;
                                writeln(s[j]);
                                break;
                        end;
                end;
                if bz=false then
                        writeln('-1');
        end;
        close(input);close(output);
end.