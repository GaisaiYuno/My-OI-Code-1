var
        way:array[1..4,1..2] of longint=((1,0),(0,1),(-1,0),(0,-1));
        a,zx:array[0..101,0..101] of longint;
        m,n,i,j,x,y,k,ans:longint;
procedure dg(x,y,s:longint);
var
        i,j,xx,yy,x2,y2:longint;
begin
        if s>=zx[x,y] then exit
        else zx[x,y]:=s;
        if (x=m) and (y=m) then
        begin
                if ans>s then ans:=s;
                exit;
        end;
        for i:=1 to 4 do
        begin
                xx:=x+way[i,1];
                yy:=y+way[i,2];
                if (xx>=1) and (yy>=1) and (xx<=m) and (yy<=m) then
                begin
                        if a[xx,yy]=maxlongint then
                        begin
                                if (xx=m) and (yy=m) then dg(xx,yy,s+2);
                                for j:=1 to 4 do
                                begin
                                        x2:=xx+way[j,1];
                                        y2:=yy+way[j,2];
                                        if (x2>=1) and (y2>=1) and (x2<=m) and (y2<=m) then
                                        begin
                                                if a[x2,y2]<>maxlongint then
                                                begin
                                                        if a[x2,y2]<>a[x,y] then dg(x2,y2,s+3)
                                                        else dg(x2,y2,s+2);
                                                end;
                                        end;
                                end;
                        end else if a[x,y]<>a[xx,yy] then dg(xx,yy,s+1)
                        else dg(xx,yy,s);
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        for i:=0 to 101 do
                for j:=0 to 101 do
                begin
                        a[i,j]:=maxlongint;
                        zx[i,j]:=maxlongint;
                end;
        readln(m,n);
        for i:=1 to n do
        begin
               read(x,y,k);
               a[x,y]:=k;
        end;
        ans:=maxlongint;
        dg(1,1,0);
        if ans=maxlongint then writeln(-1)
        else writeln(ans);
        close(input);
        close(output);
end.