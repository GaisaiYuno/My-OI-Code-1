var
        n,m,x,y,c:longint;
        i,j:longint;
        a,f:array[0..100,0..100] of longint;
function up(x,y:longint):longint;
begin
        if x-1=0 then exit(maxlongint div 3);
        if a[x-1,y]=0 then exit(maxlongint div 3);
        if a[x-1,y]=a[x,y] then exit(f[x-1,y]+0) else exit(f[x-1,y]+1);
end;
function left(x,y:longint):longint;
begin
        if y-1=0 then exit(maxlongint div 3);
        if a[x,y-1]=0 then exit(maxlongint div 3);
        if a[x,y-1]=a[x,y] then exit(f[x,y-1]+0) else exit(f[x,y-1]+1);
end;
function martix(x,y:longint):longint;
begin
        if (x-1=0) or (y-1=0) then exit(0);
        if (a[x-1,y-1]=0) then exit(maxlongint div 3);
        if (a[x-1,y]=a[x,y]) or (a[x-1,y]=a[x-1,y-1]) or (a[x,y-1]=a[x,y]) or (a[x,y-1]=a[x-1,y-1]) then
                if a[x,y]=a[x-1,y-1] then exit(f[x-1,y-1]+0)
                else exit(f[x-1,y-1]+1);
        if a[x,y]=a[x-1,y-1] then exit(f[x-1,y-1]+2)
        else exit(f[x-1,y-1]+3);
end;
function min(a,b:longint):longint;
begin
        if a<b then exit(a);
        exit(b);
end;
begin
        assign(input,'chess.in');
        assign(output,'chess.out');
        reset(input);
        rewrite(output);
        read(n,m);
        for i:=1 to m do
        begin
                read(x,y,c);
                a[x,y]:=c+1;
        end;
        for i:=1 to n do
                for j:=1 to n do
                         if a[i,j]<>0 then
                                f[i,j]:=min(up(i,j),min(left(i,j),martix(i,j)));
        if f[n,n]>=maxlongint div 3 then writeln('-1') else writeln(f[n,n]);
        close(input);
        close(output);
end.
