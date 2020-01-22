const
        fx:array[1..4,1..2] of longint=((-1,0),(0,-1),(0,1),(1,0));
var
        m,n,i,head,tail,nx,ny:longint;
        queue:array[1..100*100,1..3] of longint;
        map,f:array[1..100,1..100] of longint;
        book,t:array[1..100,1..100] of boolean;
        x,y,c:longint;

procedure add(x,y,c:longint);
begin
        if not book[x,y] then
        begin
                book[x,y]:=true;
                tail:=tail mod (m*m)+1;
                queue[tail,1]:=x;
                queue[tail,2]:=y;
                queue[tail,3]:=c;
        end;
end;

procedure change(x,y,n,c:longint);
begin
        if (n<>-1)and((f[x,y]>n)or(f[x,y]=-1)) then
        begin
                f[x,y]:=n;
                add(x,y,c);
        end;
end;

procedure gx(nx,ny:longint);
var
        x,y,c:longint;
begin
        x:=queue[head,1];
        y:=queue[head,2];
        c:=queue[head,3];
        if (c<>-1)and(f[x,y]>-1) then
        begin
                if c=map[nx,ny] then
                begin
                        change(nx,ny,f[x,y],map[nx,ny]);
                end
                else
                begin
                        if c=map[x,y] then
                        begin
                                if map[nx,ny]=-1 then
                                begin
                                        change(nx,ny,f[x,y]+2,c);
                                end
                                else
                                begin
                                        change(nx,ny,f[x,y]+1,map[nx,ny]);
                                end;
                        end
                        else
                        begin
                                if map[nx,ny]<>-1 then
                                begin
                                        change(nx,ny,f[x,y]+1,map[nx,ny]);
                                end;
                        end;
                end;
        end;
end;

begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);

        readln(m,n);
        fillchar(map,sizeof(map),255);
        for i:=1 to n do
        begin
                readln(x,y,c);
                map[x,y]:=c;
        end;

        fillchar(book,sizeof(book),false);
        fillchar(f,sizeof(f),255);
        fillchar(t,sizeof(t),false);
        queue[1,1]:=1;
        queue[1,2]:=1;
        queue[1,3]:=map[1,1];
        f[1,1]:=0;
        book[1,1]:=true;
        head:=0;
        tail:=1;
        while head<>tail do
        begin
                head:=head mod (m*m) +1;
                if (queue[head,1]=4)and(queue[head,2]=5) then
                        write;
                for i:=1 to 4 do
                begin
                        nx:=queue[head,1]+fx[i,1];
                        ny:=queue[head,2]+fx[i,2];
                        if ((nx>0)and(ny>0)and(nx<=m)and(ny<=m)) then
                        begin
                                gx(nx,ny);
                        end;
                end;
                queue[head,1]:=0;
                queue[head,2]:=0;
                queue[head,3]:=0;
        end;

        writeln(f[m,m]);

        close(input);close(output);
end.
