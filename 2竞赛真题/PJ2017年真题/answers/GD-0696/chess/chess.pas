const   dx:array [1..4] of integer=(0,1,0,-1);
        dy:array [1..4] of integer=(1,0,-1,0);
var     i,j,ans,m,n,lx,ly,lc,d:longint;
        used:array [1..101,1..101] of boolean;
        map,get:array [1..101,1..101] of integer;
procedure dfs(x,y,coin,color,magic:longint);
var     lx,ly,lc,d,i:longint;
begin
        if coin>ans then exit;
        if (x=m) and (y=m) and (ans>coin) then
        begin
                ans:=coin;
                exit;
        end;
        for i:=1 to 4 do
        begin
                lx:=x+dx[i];
                ly:=y+dy[i];
                if (lx>0) and (lx<=m) and (ly>0) and (ly<=m) and (used[lx][ly]=false)  then
                begin
                        d:=0;
                        used[lx][ly]:=true;
                        if ((color<>map[lx][ly]) and (color<>2) and (map[x][y]<>-1)) then d:=1;
                        lc:=coin+d;
                        if (map[lx][ly]<>-1) and ((lc<get[lx][ly]) or (get[lx][ly]=-1)) then
                        begin
                                get[lx][ly]:=lc;
                                dfs(lx,ly,lc,map[lx][ly],0);
                        end;
                        if (map[lx][ly]=-1) and (magic=0) then d:=2;
                        lc:=coin+d;
                        if (d=2) and ((lc<get[lx][ly]) or (get[lx][ly]=-1)) then
                        begin
                                get[lx][ly]:=lc;
                                dfs(lx,ly,lc,2,1);
                        end;
                        used[lx][ly]:=false;
                end;
        end;
end;
begin
        assign(input,'chess.in');
        reset(input);
        assign(output,'chess.out');
        rewrite(output);
        read(m,n);
        for i:=1 to m do
                for j:=1 to m do
                begin
                        map[i,j]:=-1;
                        get[i,j]:=-1;
                end;
        for i:=1 to n do
        begin
                read(lx,ly,lc);
                map[lx,ly]:=lc;
        end;
        used[1][1]:=true;
        get[1][1]:=0;
        ans:=maxlongint;
        dfs(1,1,0,map[1][1],0);
        for i:=1 to m do
        begin
                for j:=1 to m do
                        write(get[i][j]:3,' ');
                writeln;
        end;
        write(ans);
        close(input);
        close(output);
end.
