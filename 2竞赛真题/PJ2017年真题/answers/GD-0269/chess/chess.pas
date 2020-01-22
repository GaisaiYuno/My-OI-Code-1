var
        x,y,c,m,n,i,j:longint;
        map,f:array[0..200,0..200]of longint;
        bz:array[0..200,0..200]of boolean;
        fx:array[1..4,1..2]of longint=((-1,0),(0,1),(1,0),(0,-1));
procedure dg(x,y,s,k,b:longint);
var
        i,xx,yy:longint;
begin
        if f[x,y]<=s then
                exit;
        f[x,y]:=s;
        if (x=m)and(y=m) then
                exit;
        for i:=1 to 4 do
        begin
                xx:=x+fx[i,1];
                yy:=y+fx[i,2];
                if (xx<=m)and(yy<=m)and(xx>=1)and(yy>=1)and(bz[xx,yy]=false) then
                begin
                        bz[xx,yy]:=true;
                        if (map[xx,yy]=0) then
                        begin
                                if b=1 then
                                        dg(xx,yy,s+2,k,0);
                        end
                        else
                        begin
                                if map[xx,yy]<>k then
                                        dg(xx,yy,s+1,map[xx,yy],1)
                                else
                                        dg(xx,yy,s,k,1);
                        end;
                        bz[xx,yy]:=false;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        fillchar(f,sizeof(f),60);
        fillchar(map,sizeof(map),60);
        for i:=1 to m do
                for j:=1 to m do
                        map[i,j]:=0;
        for i:=1 to n do
        begin
                readln(x,y,c);
                map[x,y]:=c+1;
        end;
        dg(1,1,0,map[1,1],1);
        if f[m,m]>20000 then
                writeln('-1')
        else
                writeln(f[m,m]);
        close(input);close(output);
end.
