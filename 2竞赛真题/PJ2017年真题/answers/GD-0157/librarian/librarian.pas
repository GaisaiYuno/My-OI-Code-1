var
        i,j,n,q,x,y:longint;
        a:array[0..10000000]of longint;
procedure dg(p:longint);
var
        i,j,w,l,k:longint;
begin
        w:=p;
        k:=1;
        l:=0;
        while w<>0 do
        begin
                l:=(w mod 10)*k+l;
                if (p<a[l])or(a[l]=0) then a[l]:=p;
                k:=k*10;
                w:=w div 10;
        end;
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,q);
        for i:=1 to n do
        begin
                readln(x);
                dg(x);
        end;
        for i:=1 to q do
        begin
                readln(x,y);
                if a[y]=0 then writeln(-1)
                else writeln(a[y]);
        end;
        close(input);
        close(output);
end.