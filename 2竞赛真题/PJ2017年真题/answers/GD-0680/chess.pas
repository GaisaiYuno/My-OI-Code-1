const
        x1:array[1..4]of integer= (-1,-1,1,1);
        y1:array[1..4]of integer= (-1,1,-1,1);
var
        i,j,k,l,n,m,ans:longint;
        t:boolean;
        visit:array[-5..105,-5..105]of boolean;
        a:array[-5..105,-5..105]of longint;
 procedure dfs(x,y,g:longint);
 var i:longint;
 begin
        if (g<ans)and(x>0)and(x<=m)and(y>0)and(y<=m)and(visit[x,y]) then
        begin
                if(x=m)and(y=m) then
                begin
                        ans:=g;
                        t:=true;
                end
                else
                begin
                        visit[x,y]:=false;
                        if a[x+1,y]=a[x,y] then
                                dfs(x+1,y,g)
                        else if a[x+1,y]=1-a[x,y] then
                                dfs(x+1,y,g+1);

                        if a[x-1,y]=a[x,y] then
                                dfs(x-1,y,g)
                        else if a[x-1,y]=1-a[x,y] then
                                dfs(x-1,y,g+1);

                        if a[x,y+1]=a[x,y] then
                                dfs(x,y+1,g)
                        else if a[x,y+1]=1-a[x,y] then
                                dfs(x,y+1,g+1);

                        if a[x,y-1]=a[x,y] then
                                dfs(x,y-1,g)
                        else if a[x,y-1]=1-a[x,y] then
                                dfs(x,y-1,g+1);

                        for i:=1 to 4 do
                        if(a[x+x1[i],y]=2)and(a[x,y+y1[i]]=2) then
                        begin
                                if a[x+x1[i],y+y1[i]]=a[x,y] then
                                        dfs(x+x1[i],y+y1[i],g+2)
                                else if a[x+x1[i],y+y1[i]]=1-a[x,y] then
                                        dfs(x+x1[i],y+y1[i],g+3);
                        end;
                        if a[x+1,y]=2 then
                        begin
                                if a[x+2,y]=a[x,y] then
                                        dfs(x+2,y,g+2)
                                else if a[x+2,y]=1-a[x,y] then
                                        dfs(x+2,y,g+3);
                        end;
                        if a[x-1,y]=2 then
                        begin
                                if a[x-2,y]=a[x,y] then
                                        dfs(x-2,y,g+2)
                                else if a[x-2,y]=1-a[x,y] then
                                        dfs(x-2,y,g+3);
                        end;
                        if a[x,y+1]=2 then
                        begin
                                if a[x,y+2]=a[x,y] then
                                        dfs(x,y+2,g+2)
                                else if a[x,y+2]=1-a[x,y] then
                                        dfs(x,y+2,g+3);
                        end;
                        if a[x,y-1]=2 then
                        begin
                                if a[x,y-2]=a[x,y] then
                                        dfs(x,y-2,g+2)
                                else if a[x,y-2]=1-a[x,y] then
                                        dfs(x,y-2,g+3);
                        end;
                   visit[x,y]:=true;
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
                        a[i,j]:=2;
                        visit[i,j]:=true;
                end;
        for i:=1 to n do
        begin
                read(k,l);
                read(a[k,l]);
        end;
        t:=false;
        ans:=maxlongint;
        dfs(1,1,0);
        if t then write(ans)
                else write(-1);
        close(input);
        close(output);
end.
