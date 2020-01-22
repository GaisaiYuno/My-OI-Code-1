var
        i,j,n,m,x,y,c,t,w,ans:longint;
        a,f,bz:array[1..100,1..100]of longint;
        d:array[1..1000000,1..3]of longint;
        fx:array[1..4,1..2]of longint=((-1,0),(0,1),(1,0),(0,-1));
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        fillchar(f,sizeof(f),60);
        ans:=maxlongint;
        for i:=1 to n do
        begin
                readln(x,y,c);
                a[x,y]:=c+1;
        end;
        t:=1;
        w:=1;
        d[1,1]:=1;
        d[1,2]:=1;
        d[1,3]:=a[x,y];
        f[1,1]:=0;
        bz[1,1]:=1;
        while t<=w do
        begin
                for i:=1 to 4 do
                begin
                        x:=d[t,1]+fx[i,1];
                        y:=d[t,2]+fx[i,2];
                        if (x>0)and(x<=m)and(y>0)and(y<=m) then
                        begin
                                if a[x,y]=0 then
                                begin
                                        if d[t,3]=a[d[t,1],d[t,2]] then
                                        begin
                                                if f[x,y]>f[d[t,1],d[t,2]]+2 then
                                                begin
                                                        f[x,y]:=f[d[t,1],d[t,2]]+2;
                                                        if (bz[x,y]=0) then
                                                        begin
                                                                inc(w);
                                                                bz[x,y]:=w;
                                                                d[w,1]:=x;
                                                                d[w,2]:=y;
                                                                d[w,3]:=d[t,3];
                                                        end
                                                        else
                                                        begin
                                                                d[bz[x,y],3]:=d[t,3];
                                                        end;
                                                end;
                                        end;
                                end
                                else
                                begin
                                        if a[x,y]<>d[t,3] then
                                        begin
                                                if f[x,y]>f[d[t,1],d[t,2]]+1 then
                                                begin
                                                        f[x,y]:=f[d[t,1],d[t,2]]+1;
                                                        if bz[x,y]=0 then
                                                        begin
                                                                inc(w);
                                                                bz[x,y]:=w;
                                                                d[w,1]:=x;
                                                                d[w,2]:=y;
                                                                d[w,3]:=a[x,y];
                                                        end;
                                                end;
                                        end
                                        else
                                        begin
                                                if f[x,y]>f[d[t,1],d[t,2]] then
                                                begin
                                                        f[x,y]:=f[d[t,1],d[t,2]];
                                                        if bz[x,y]=0 then
                                                        begin
                                                                inc(w);
                                                                bz[x,y]:=w;
                                                                d[w,1]:=x;
                                                                d[w,2]:=y;
                                                                d[w,3]:=a[x,y];
                                                        end;
                                                end;
                                        end;
                                end;
                        end;
                end;
                bz[d[t,1],d[t,2]]:=0;
                inc(t);
        end;
        ans:=f[m,m];
        if ans>40000 then writeln(-1)
        else writeln(ans);
        close(input);
        close(output);
end.