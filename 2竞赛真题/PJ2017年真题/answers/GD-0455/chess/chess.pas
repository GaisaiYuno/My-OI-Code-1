var
        i,j,k,m,n:longint;
        f,a:array[-1..1001,-1..1001] of longint;
function min(x,y:longint):longint;
begin
        if x>y then exit(y) else exit(x);
end;
begin
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
        readln(m,n);
        for i:=1 to n do
        begin
                read(j,k);
                readln(a[j,k]);
                inc(a[j,k]);
        end;
        for i:=-1 to m+1 do
                for j:=-1 to m+1 do
                        f[i,j]:=maxlongint div 2;
        f[1,1]:=0;
        for i:=1 to m do
                for j:=1 to m do
                begin
                        if (a[i-1,j]<>0) and (a[i,j]<>0) then
                                f[i,j]:=min(f[i,j],f[i-1,j]+abs(a[i-1,j]-a[i,j]));
                        if (a[i,j-1]<>0) and (a[i,j]<>0) then
                                f[i,j]:=min(f[i,j],f[i,j-1]+abs(a[i,j-1]-a[i,j]));
                        if a[i-1,j-1]<>0 then
                                if (a[i-1,j]<>0) and (a[i,j-1]<>0) or (a[i,j]<>0) then
                                        f[i,j]:=min(f[i,j],f[i-1,j-1]+abs(a[i-1,j-1]-a[i,j])+2);
                        if a[i-1,j]=0 then
                                if (a[i-2,j]<>0) and (a[i,j]<>0) then
                                        f[i,j]:=min(f[i,j],f[i-2,j]+abs(a[i-2,j]-a[i,j])+2);
                        if a[i,j]=0 then
                        begin
                                if (a[i-2,j]<>0) and (a[i-1,j]<>0) then
                                        f[i,j]:=min(f[i,j],f[i-2,j]+abs(a[i-2,j]-a[i-1,j])+2);
                                if (a[i,j-2]<>0) and (a[i,j-1]<>0) then
                                        f[i,j]:=min(f[i,j],f[i,j-2]+abs(a[i,j-2]-a[i,j-1])+2);
                        end;
                        if a[i,j-1]=0 then
                                if (a[i,j-2]<>0) and (a[i,j]<>0) then
                                        f[i,j]:=min(f[i,j],f[i,j-2]+abs(a[i,j-2]-a[i,j])+2);
                end;
        if f[m,m]=maxlongint div 2 then writeln(-1) else writeln(f[m,m]);
close(input);
close(output);
end.