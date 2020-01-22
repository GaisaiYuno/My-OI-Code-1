const
        w=500000;
var
        u:boolean;
        f,xi,yi:array [1..30000] of longint;
        p:array [1..4,1..2] of longint;
        a,color:array [1..300000] of longint;
        map:array [1..300,1..300] of longint;
        x,y,i,j,m,n,h,t,bol:longint;

procedure gcc;
begin
        p[1][1]:=0;p[1][2]:=1;
        p[2][1]:=1;p[2][2]:=0;
        p[3][1]:=0;p[3][2]:=-1;
        p[4][1]:=-1;p[4][2]:=0;
end;

function max(a,b:longint):longint;
begin
        if a>b then exit(b)
               else exit(a);
end;

begin
        assign(input,'chess.in');
        reset(input);
        assign(output,'chess.out');
        rewrite(output);
        fillchar(color,sizeof(color),0);
        readln(m,n);
        bol:=m*m;
        for i:=1 to m do
                for j:=1 to m do
                        map[i,j]:=2;
        for i:=1 to n do
        begin
                read(x,y);
                readln(map[x,y]);
        end;
        a[1]:=0;
        for i:=1 to m do
                for j:=1 to m do
                begin
                        xi[(i-1)*m+j]:=i;
                        yi[(i-1)*m+j]:=j;
                        f[(i-1)*m+j]:=w;
                end;
        for i:=1 to m do
                for j:=1 to m do
                begin
                        xi[(i-1)*m+j+bol]:=i;
                        yi[(i-1)*m+j+bol]:=j;
                        f[(i-1)*m+j+bol]:=w;
                end;
        gcc;
        h:=0;t:=1;
        a[1]:=1;
        f[1]:=0;
        repeat
                inc(h);
                u:=true;
                if (a[h]>m*m) then u:=false;
                for i:=1 to 4 do
                begin
                        x:=xi[a[h]]+p[i][1];
                        y:=yi[a[h]]+p[i][2];
                        if (x>0) and (x<=m) and (y>0) and (y<=m) then
                        begin

                                if (map[x,y]=2) and (u) and (f[a[h]]+2<f[(x-1)*m+y+bol]) then
                                begin
                                        inc(t);
                                        f[(x-1)*m+y+bol]:=f[a[h]]+2;
                                        a[t]:=(x-1)*m+y+bol;
                                        color[t]:=map[xi[a[h]],yi[a[h]]];
                                end;

                                if (map[x,y]<>2) then
                                begin
                                        if (map[x,y]=map[xi[a[h]],yi[a[h]]]) and (f[a[h]]<f[(x-1)*m+y]) then
                                        begin
                                                inc(t);
                                                f[(x-1)*m+y]:=f[a[h]];
                                                a[t]:=(x-1)*m+y;
                                        end
                                                                                                    else
                                        begin
                                                if (u=false) then
                                                begin
                                                        if (color[h]=map[x,y]) and (f[a[h]]<f[(x-1)*m+y]) then
                                                        begin
                                                                inc(t);
                                                                f[(x-1)*m+y]:=f[a[h]];
                                                                a[t]:=(x-1)*m+y;
                                                        end;
                                                        if (color[h]<>map[x,y]) and (f[a[h]]+1<f[(x-1)*m+y]) then
                                                        begin
                                                                inc(t);
                                                                f[(x-1)*m+y]:=f[a[h]]+1;
                                                                a[t]:=(x-1)*m+y;
                                                        end;
                                                end
                                                             else
                                                begin
                                                        if (f[a[h]]+1<f[(x-1)*m+y]) then
                                                        begin
                                                                inc(t);
                                                                f[(x-1)*m+y]:=f[a[h]]+1;
                                                                a[t]:=(x-1)*m+y;
                                                        end;
                                                end;
                                        end;
                                end;

                        end;
                end;
        until h=t;
        if (f[m*m]=w) and (f[m*m*2]=w) then writeln(-1)
                else writeln(max(f[m*m],f[2*m*m]));
        close(input);
        close(output);
end.