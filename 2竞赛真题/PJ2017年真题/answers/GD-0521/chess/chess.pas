var
        way:array[1..4,1..2] of longint=((1,0),(0,-1),(-1,0),(0,1));
        bz,map:array[0..1000,0..1000] of longint;
        m,n,i,h,l,c,min:longint;
procedure dg(x,y,f,k:longint);
var
        xx,yy,i:longint;
begin
        if k>=min then exit;
        if (x=m) and (y=m) then
        begin
                if k<min then min:=k;
                exit;
        end;
        for i:=1 to 4 do
        begin
                xx:=x+way[i,1];
                yy:=y+way[i,2];
                if (xx in [1..m]) and (yy in [1..m]) and (bz[xx,yy]=0) then
                begin
                        bz[xx,yy]:=1;
                        if (f=0) and (map[xx,yy]=0) then continue;
                        if (f=1) and (map[xx,yy]=0) then dg(xx,yy,0,k+2) else
                        if (map[xx,yy]=map[x,y]) and (map[x,y]<>0) then dg(xx,yy,1,k) else
                        if (map[xx,yy]<>map[x,y]) and (map[x,y]=0) and (f=0) then dg(xx,yy,1,k) else
                        if (map[xx,yy]<>map[x,y]) and (map[x,y]<>0) then dg(xx,yy,1,k+1);
                        bz[xx,yy]:=0;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);

        readln(m,n);
        for i:=1 to n do
        begin
                readln(h,l,c);
                if c=0 then c:=-1;
                map[h,l]:=c;
        end;
        bz[1,1]:=1;min:=m*m+m div 2;
        dg(1,1,1,0);
        if min=m*m+m div 2 then min:=-1;
        writeln(min);

        close(input);
        close(output);
end.














