var
        m,n,x,y,c,ans,i:longint;
        map:array[1..100,1..100] of longint;
        book:array[1..100,1..100] of boolean;
        fx:array[1..4,1..2] of longint=((-1,0),(0,-1),(0,1),(1,0));

procedure dg(x,y,o:longint;b:boolean);
var
        nx,ny,i:longint;
begin
        if (x=m)and(y=m) then
        begin
                if (ans=-1)or(ans>o) then
                begin
                        ans:=o;
                end;
                exit;
        end;
        book[x,y]:=true;
        for i:=1 to 4 do
        begin
                nx:=x+fx[i,1];
                ny:=y+fx[i,2];
                if (nx>0)and(ny>0)and(nx<=m)and(ny<=m)and(not book[nx,ny]) then
                begin
                        if map[x,y]=map[nx,ny] then
                        begin
                                dg(nx,ny,o,false);
                        end
                        else
                        begin
                                if (map[nx,ny]=-1) then
                                begin
                                        if not b then
                                        begin
                                                map[nx,ny]:=map[x,y];
                                                dg(nx,ny,o+2,true);
                                                map[nx,ny]:=-1;
                                        end;
                                end
                                else
                                begin
                                        dg(nx,ny,o+1,false);
                                end;
                        end;
                end;
        end;
        book[x,y]:=false;
end;

begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.ans');rewrite(output);

        readln(m,n);
        fillchar(map,sizeof(map),255);
        for i:=1 to n do
        begin
                readln(x,y,c);
                map[x,y]:=c;
        end;

        ans:=-1;
        dg(1,1,0,false);

        writeln(ans);

        close(input);close(output);
end.