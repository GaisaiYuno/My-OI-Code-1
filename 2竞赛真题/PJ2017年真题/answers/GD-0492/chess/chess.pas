program score;
var     i,j,k,n,m,a,b,c,h,t,x,y:longint;
        map:array[0..101,0..101]of longint;
        f:array[0..101,0..101,0..2]of longint;
        li:array[0..5000001,0..3]of longint;
        way:array[0..5,0..5]of integer;
        bo:array[0..101,0..101,0..3]of integer;
begin
        assign(input,'chess.in');
        reset(input);
        assign(output,'chess.out');
        rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(a,b,c);
                c:=c+1;
                map[a,b]:=c;
        end;
        for i:=1 to n do
                for j:=1 to n do
                begin
                        f[i,j,1]:=maxlongint;
                        f[i,j,2]:=maxlongint;
                end;
        li[1,1]:=1;
        li[1,2]:=1;
        li[1,3]:=map[1,1];
        t:=1;
        h:=1;
        f[1,1,map[1,1]]:=0;
        bo[1,1,map[1,1]]:=1;
        way[1,1]:=0;way[1,2]:=1;way[2,1]:=1;way[2,2]:=0;
        way[3,1]:=0;way[3,2]:=-1;way[4,1]:=-1;way[4,2]:=0;
        while h<=t do
        begin
                for i:=1 to 4 do
                begin
                        x:=li[h,1]+way[i,1];
                        y:=li[h,2]+way[i,2];
                        if (x>0)and(x<=n)and(y>0)and(y<=n) then
                        begin
                                if map[x,y]<>0 then
                                begin
                                        k:=0;
                                        if map[x,y]<>li[h,3] then
                                                k:=1;
                                        if f[x,y,map[x,y]]>f[li[h,1],li[h,2],li[h,3]]+k then
                                        begin
                                                f[x,y,map[x,y]]:=f[li[h,1],li[h,2],li[h,3]]+k;
                                                if bo[x,y,map[x,y]]=0 then
                                                begin
                                                        t:=t+1;
                                                        li[t,1]:=x;
                                                        li[t,2]:=y;
                                                        li[t,3]:=map[x,y];
                                                        bo[x,y,map[x,y]]:=1;
                                                end;
                                        end;
                                end;
                                if (map[x,y]=0)and(map[li[h,1],li[h,2]]<>0)then
                                begin
                                        k:=2;
                                        map[x,y]:=1;
                                        if map[x,y]<>li[h,3] then
                                                k:=k+1;
                                        if f[x,y,map[x,y]]>f[li[h,1],li[h,2],li[h,3]]+k then
                                        begin
                                                f[x,y,map[x,y]]:=f[li[h,1],li[h,2],li[h,3]]+k;
                                                if bo[x,y,map[x,y]]=0 then
                                                begin
                                                        t:=t+1;
                                                        li[t,1]:=x;
                                                        li[t,2]:=y;
                                                        li[t,3]:=map[x,y];
                                                        bo[x,y,map[x,y]]:=1;
                                                end;
                                        end;
                                        map[x,y]:=2;
                                        k:=2;
                                        if map[x,y]<>li[h,3] then
                                                k:=k+1;
                                        if f[x,y,map[x,y]]>f[li[h,1],li[h,2],li[h,3]]+k then
                                        begin
                                                f[x,y,map[x,y]]:=f[li[h,1],li[h,2],li[h,3]]+k;
                                                if bo[x,y,map[x,y]]=0 then
                                                begin
                                                        t:=t+1;
                                                        li[t,1]:=x;
                                                        li[t,2]:=y;
                                                        li[t,3]:=map[x,y];
                                                        bo[x,y,map[x,y]]:=1;
                                                end;
                                        end;
                                        map[x,y]:=0;
                                end;
                        end;
                end;
                bo[li[h,1],li[h,2],li[h,3]]:=0;
                h:=h+1;
        end;
        if (f[n,n,1]=maxlongint)and(f[n,n,2]=maxlongint)then
                write(-1)
        else
                if f[n,n,1]<f[n,n,2] then
                        write(f[n,n,1])
                else
                        write(f[n,n,2]);
        close(input);
        close(output);
end.
