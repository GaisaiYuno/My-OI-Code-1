var
        map,pd:array[0..101,0..101]of longint;
        ans,i,j,n,m,x,y,z:longint;
procedure dg(x,y,t,a,use:longint);
begin
        if (x=m)and(y=m) then
        begin
                if (t<ans) then ans:=t;
                exit;
        end;
        if(pd[x,y]<t) then exit;
        pd[x,y]:=t;
        if (a<>2) then
        begin
                if (y+1<=m) then
                begin
                if (a=map[x,y+1]) then dg(x,y+1,t,a,0) else
                begin
                        if (map[x,y+1]=2) then
                        begin
                                if (use=0) then dg(x,y+1,t+2,a,1);
                        end else dg(x,y+1,t+1,map[x,y+1],0);
                end;
                end;
                if (x+1<=m) then
                begin
                if (a=map[x+1,y]) then dg(x+1,y,t,a,0) else
                begin
                        if (map[x+1,y]=2) then
                        begin
                                if (use=0) then dg(x+1,y,t+2,a,1);
                        end else dg(x+1,y,t+1,map[x+1,y],0);
                end;
                end;
        end;
end;
begin
        assign(input,'chess.in'); reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        for i:=0 to m+1 do
        begin
                for j:=0 to m+1 do
                begin
                        map[i,j]:=2;
                        pd[i,j]:=maxlongint;
                end;
        end;
        for i:=1 to n do
        begin
                readln(x,y,z);
                map[x,y]:=z;
        end;
        ans:=maxlongint;
        dg(1,1,0,map[1,1],0);
        if (ans=maxlongint)then ans:=-1;
        writeln(ans);
end.
