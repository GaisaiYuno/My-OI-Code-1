type
        new=record
                x:longint;
                y:longint;
                cos:longint;
                sf:boolean;
                co:longint;
        end;
var
        head,tail,i,j,k,l,n,m,x,y,v:longint;
        a:array[1..1000000] of new;
        z,ans:array[1..100,1..100] of longint;
        fx:array[1..4,1..2] of longint=((-1,0),(1,0),(0,-1),(0,1));
procedure bfs(dep:longint);
var
        i,j,k,l,x,y:longint;
begin
        for i:=1 to 4 do
        begin
                x:=fx[i,1]+a[dep].x;
                y:=fx[i,2]+a[dep].y;
                k:=0;
                l:=0;
                if (x>0) and (x<=m) and (y>0) and (y<=m) then
                begin
                        if (a[dep].sf) then
                        begin
                                if z[x,y]>0 then
                                begin
                                        if a[dep].co=z[x,y] then
                                        k:=a[dep].cos
                                        else
                                        k:=a[dep].cos+1;
                                        if ans[x,y]>-1 then
                                        begin
                                                if ans[x,y]>k then
                                                begin
                                                        ans[x,y]:=k;
                                                        inc(tail);
                                                        if tail>1000000 then tail:=1;
                                                        a[tail].x:=x;
                                                        a[tail].y:=y;
                                                        a[tail].cos:=k;
                                                        a[tail].sf:=false;
                                                        a[tail].co:=z[x,y];
                                                end;
                                        end
                                        else
                                        begin
                                                ans[x,y]:=k;
                                                inc(tail);
                                                if tail>1000000 then tail:=1;
                                                a[tail].x:=x;
                                                a[tail].y:=y;
                                                a[tail].cos:=k;
                                                a[tail].sf:=false;
                                                a[tail].co:=z[x,y];
                                        end;
                                end;
                        end
                        else
                        begin
                                if z[x,y]=0 then
                                begin
                                        k:=a[dep].cos+2;
                                        if ans[x,y]>-1 then
                                        begin
                                                if ans[x,y]>k then
                                                begin
                                                        ans[x,y]:=k;
                                                        inc(tail);
                                                        if tail>1000000 then tail:=1;
                                                        a[tail].x:=x;
                                                        a[tail].y:=y;
                                                        a[tail].cos:=k;
                                                        a[tail].sf:=true;
                                                        a[tail].co:=a[dep].co;
                                                end;
                                        end
                                        else
                                        begin
                                                ans[x,y]:=k;
                                                inc(tail);
                                                if tail>1000000 then tail:=1;
                                                a[tail].x:=x;
                                                a[tail].y:=y;
                                                a[tail].cos:=k;
                                                a[tail].sf:=true;
                                                a[tail].co:=a[dep].co;
                                        end;
                                end
                                else
                                begin
                                        if a[dep].co=z[x,y] then
                                        k:=a[dep].cos
                                        else
                                        k:=a[dep].cos+1;
                                        if ans[x,y]>-1 then
                                        begin
                                                if ans[x,y]>k then
                                                begin
                                                        ans[x,y]:=k;
                                                        inc(tail);
                                                        if tail>1000000 then tail:=1;
                                                        a[tail].x:=x;
                                                        a[tail].y:=y;
                                                        a[tail].cos:=k;
                                                        a[tail].sf:=false;
                                                        a[tail].co:=z[x,y];
                                                end;
                                        end
                                        else
                                        begin
                                                ans[x,y]:=k;
                                                inc(tail);
                                                if tail>1000000 then tail:=1;
                                                a[tail].x:=x;
                                                a[tail].y:=y;
                                                a[tail].cos:=k;
                                                a[tail].sf:=false;
                                                a[tail].co:=z[x,y];
                                        end;
                                end;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        for i:=1 to n do
        begin
                readln(x,y,v);
                z[x,y]:=v+1;
        end;
        fillchar(ans,sizeof(ans),255);
        ans[1,1]:=0;
        head:=1;tail:=1;
        a[1].x:=1;
        a[1].y:=1;
        a[1].co:=z[1,1];
        repeat
                bfs(head);
                inc(head);
                if head>1000000 then head:=1;
        until head>tail;
        writeln(ans[m,m]);
        close(input);close(output);
end.
