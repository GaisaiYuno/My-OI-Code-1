var
        bz:array[0..105,0..105] of 0..2;
        f,g:array[0..105,0..105] of longint;
        i,j,k,n,m,x,y,c:longint;
        way:array[1..4,1..2] of longint=((0,1),(0,-1),(1,0),(-1,0));
function min(a,b:longint):longint;
begin
        if a<b then exit(a);
        exit(b);
end;
begin
        assign(input,'chess.in');
        reset(input);
        assign(output,'chess.out');
        rewrite(output);
        readln(m,n);
        fillchar(bz,sizeof(bz),0);
        for i:=1 to n do
        begin
                readln(x,y,c);
                bz[x,y]:=c+1;
        end;
        for i:=1 to m do
        begin
                for j:=1 to m do
                begin
                        f[i,j]:=maxlongint-3;
                        g[i,j]:=maxlongint-3;
                end;
        end;
        f[1,1]:=0;
        for i:=1 to m do
        begin
                for j:=1 to m do
                begin
                        if (bz[i,j])<>0 then
                        begin
                                for k:=1 to 4 do
                                begin
                                        x:=i;
                                        y:=j;
                                        x:=x+way[k,1];
                                        y:=y+way[k,2];
                                        if (0<x) and (x<m+1) and (0<y) and (y<m+1) then
                                        begin
                                                if (bz[i,j]=bz[x,y]) then
                                                begin
                                                        f[x,y]:=min(f[i,j],f[x,y]);
                                                end
                                                else
                                                begin
                                                        if (bz[x,y]<>0) then
                                                        begin
                                                                f[x,y]:=min(f[i,j]+1,f[x,y]);
                                                        end
                                                        else
                                                        begin
                                                                if bz[i,j]=1 then
                                                                begin
                                                                        f[x,y]:=min(f[i,j]+2,f[x,y]);
                                                                end
                                                                else
                                                                        g[x,y]:=min(g[x,y],f[i,j]+2);
                                                        end;
                                                end;
                                        end;
                                end;
                        end
                        else
                        begin
                                for k:=1 to 4 do
                                begin
                                        x:=i;
                                        y:=j;
                                        x:=x+way[k,1];
                                        y:=y+way[k,2];
                                        if (0<x) and (x<m+1) and (0<y) and (y<m+1) then
                                        begin
                                                if (bz[i,j]=bz[x,y]) then
                                                begin
                                                        continue;
                                                end
                                                else
                                                begin
                                                        if (bz[x,y]=1) then
                                                        begin
                                                                f[x,y]:=min(f[i,j],f[x,y]);
                                                                f[x,y]:=min(f[x,y],g[i,j]+1);
                                                        end
                                                        else
                                                        begin
                                                                f[x,y]:=min(g[i,j],f[x,y]);
                                                                f[x,y]:=min(f[x,y],f[i,j]+1);
                                                        end;
                                                end;
                                        end;
                                end;
                        end;
                end;
        end;
        if min(f[m,m],g[m,m])=2147483644 then
                writeln(-1)
        else
                writeln(min(f[m,m],g[m,m]));
        close(input);
        close(output);
end.
