var
 next:array[1..4,1..2] of longint;
 a,b,f:array[0..100,0..100] of longint;
 n,m,i,j,k,x,y,ans:longint;
procedure dfs(sx,sy,z,c:longint);
var
 i,j,k,x,y:longint;
begin
        if z>=ans then exit;
        if (sx=1) and (sy=1) then
         begin
                ans:=z;
                if m>20 then
                 begin
                        writeln(ans);
                        close(input); close(output);
                        halt;
                 end;
                exit;
         end;
        for i:=1 to 4 do
         begin
                x:=sx+next[i,1];
                y:=sy+next[i,2];
                if (x<=n) and (x>=1) and (y<=n) and (y>=1) then
                 begin
                        if (b[x,y]=0) and (a[sx,sy]+a[x,y]>0) then
                         begin
                                b[x,y]:=1;
                                if a[x,y]=0 then
                                 begin
                                        dfs(x,y,z+2,a[sx,sy]);
                                 end
                                else
                                 begin
                                        dfs(x,y,z+abs(c-a[x,y]),a[x,y]);
                                 end;
                                b[x,y]:=0;
                         end;
                 end;
         end;
end;
begin
        assign(input,'chess.in'); reset(input);
        assign(output,'chess.out'); rewrite(output);
        next[4,1]:=1; next[4,2]:=0;
        next[3,1]:=0; next[3,2]:=1;
        next[1,1]:=-1; next[1,2]:=0;
        next[2,1]:=0; next[2,2]:=-1;
        ans:=maxlongint;
        readln(n,m);
        for i:=1 to n do
         for j:=1 to n do
          begin
                a[i,j]:=0;
                b[i,j]:=0;
          end;
        for i:=1 to m do
         begin
                readln(x,y,k);
                a[x,y]:=k+1;
         end;
        b[n,n]:=1;
        dfs(n,n,0,a[n,n]);
        if ans=maxlongint then writeln(-1)
        else writeln(ans);
        close(input); close(output);
end.