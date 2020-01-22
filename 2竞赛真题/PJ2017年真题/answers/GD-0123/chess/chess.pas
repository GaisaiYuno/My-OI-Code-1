var
        m,n,i,j,x,s,y,ans:longint;
        a:array[0..1001,0..1001]of longint;
        bz:array[0..1001,0..1001]of boolean;
        w:array[1..4,1..2]of longint=((0,1),(1,0),(0,-1),(-1,0));
procedure dg(x,y,s,t:longint);
var
        i,j,xx,yy:longint;
begin
        if (x=m)and(y=m) then
        begin
                if s<ans then ans:=s;
                exit;
        end;
        for i:=1 to 4 do
        begin
                xx:=x+w[i,1];
                yy:=y+w[i,2];
                if (xx>0)and(xx<=m)and(yy>0)and(yy<=m) then
                begin
                        if (a[xx,yy]>0)and(bz[xx,yy])or(t=1)and(a[xx,yy]=0) then
                        begin
                                if a[xx,yy]=0 then
                                begin
                                        a[xx,yy]:=a[x,y];
                                        dg(xx,yy,s+2,0);
                                        a[xx,yy]:=0;
                                end
                                else
                                begin
                                        bz[xx,yy]:=false;
                                        if a[xx,yy]<>a[x,y] then dg(xx,yy,s+1,1)
                                        else dg(xx,yy,s,1);
                                        bz[xx,yy]:=true;
                                end;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in'); reset(input);
        assign(output,'chess.out'); rewrite(output);
        readln(m,n);
        for i:=1 to n do
        begin
                readln(x,y,s);
                a[x,y]:=s+1;
                bz[x,y]:=true;
        end;
        ans:=maxlongint;
        bz[1,1]:=false;
        dg(1,1,0,1);
        if ans=maxlongint then writeln(-1)
        else writeln(ans);

        close(input); close(output);
end.
