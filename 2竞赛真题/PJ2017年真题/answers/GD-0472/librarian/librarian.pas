var
        i,j,n,q,t:longint;
        tf:boolean;
        a,l,need:array[0..1000]of longint;
        s:array[0..1000]of string;
function times(x:longint):longint;
var
        k:longint;
begin
        times:=1;
        for k:=1 to x do times:=times*10;
end;
begin
        assign(input,'librarian.in');
        assign(output,'librarian.out');
        reset(input);
        rewrite(output);
        readln(n,q);
        for i:=1 to n do readln(a[i]);
        for i:=1 to q do readln(l[i],need[i]);
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if a[i]>a[j] then
                                begin
                                        t:=a[i];
                                        a[i]:=a[j];
                                        a[j]:=t;
                                end;
        for j:=1 to q do
                begin
                        tf:=true;
                        for i:=1 to n do
                                begin
                                        t:=a[i] mod times(l[j]);
                                        if (t=need[j])and(tf) then
                                                begin
                                                        writeln(a[i]);
                                                        tf:=false;
                                                end;
                                end;
                        if tf then writeln(-1);
                end;
        close(input);
        close(output);
end.
