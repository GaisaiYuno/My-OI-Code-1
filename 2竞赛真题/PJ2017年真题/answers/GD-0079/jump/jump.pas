const
        w=-1000000000;
var
        f:array [0..100000] of longint;
        a,v:array [0..100000] of longint;
        i,max,left,right,n,d,q,mid:longint;

function gcc(p:longint):boolean;
var
        i,x,y,j,pl,k:longint;
begin
        if (d>p) then x:=d-p
                 else x:=1;
        y:=p+d;
        for i:=1 to n do
                f[i]:=w;
        f[0]:=0;
        max:=w;
        for i:=1 to n do
        begin
                for k:=0 to i-1 do
                if (a[i]-a[k]<=y) and (a[i]-a[k]>=x) and (f[k]<>w) then
                begin
                        if (f[k]+v[i]>f[i]) then f[i]:=f[k]+v[i];
                end;
                if (f[i]>max) then max:=f[i];
        end;
        exit(max>=q);
end;

begin
        assign(input,'jump.in');
        reset(input);
        assign(output,'jump.out');
        rewrite(output);
        readln(n,d,q);
        right:=0;
        a[0]:=0;
        for i:=1 to n do
        begin
                readln(a[i],v[i]);
                if a[i]>right then right:=a[i];
        end;
        left:=0;
        repeat
                mid:=(left+right) div 2;
                if (gcc(mid)) then right:=mid
                              else left:=mid+1;
        until left>=right;
        if (gcc(right)) then writeln(right)
                        else if (gcc(left)) then writeln(left)
                                            else writeln(-1);
        close(input);
        close(output);
end.