var
        a:array[0..500000,1..2]of longint;
        n,d,k,i,j,ans,h,max,z:longint;
function min(a,b:longint):longint;
begin
        if a<b then
                exit(a);
        exit(b);
end;
procedure dg(x:longint);
var
        i:longint;
begin
        for i:=x+1 to n do
        begin
                h:=h+a[i,2];
                z:=max;
                if max<a[i,1]-a[x,1] then
                        max:=a[i,1]-a[x,1];
                if h>d then
                begin
                        ans:=min(ans,abs(k-max)-d);
                        exit;
                end;
                dg(i);
                h:=h-a[i,2];
                max:=z;
        end;
end;
begin
        {assign(input,'jump.in');
        assign(output,'jump.out');
        reset(input);
        rewrite(output); }
        readln(n,d,k);
        for i:=1 to n do
                readln(a[i,1],a[i,2]);
        ans:=maxlongint;
        dg(0);
        writeln(ans);
        close(input);
        close(output);
end.
