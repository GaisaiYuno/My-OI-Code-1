var
        fx:array[1..4,1..2]of longint=((1,0),
                                       (0,1),
                                       (-1,0),
                                       (0,-1));
        map,maw:array[1..100,1..100]of longint;
        d:array[1..100000,1..4]of longint;
        bj:array[1..100,1..100]of boolean;
        n,m,i,j,x,y,z,ans:longint;
function min(a,b:longint):longint;
begin
        if a<b then
                exit(a);
        exit(b);
end;
procedure bfs;
var
        head,tail,i,x,y,xx,yy:longint;
begin
        d[1,1]:=1;
        d[1,2]:=1;
        d[1,4]:=map[1,1];
        maw[1,1]:=0;
        head:=0;
        tail:=1;
        while head<tail do
        begin
                inc(head);
                x:=d[head,1];
                y:=d[head,2];
                for i:=1 to 4 do
                begin
                        xx:=x+fx[i,1];
                        yy:=y+fx[i,2];
                        if (xx>0) and (xx<=n) and (yy>0) and (yy<=n) then
			begin
			        inc(tail);
				d[tail,1]:=xx;
				d[tail,2]:=yy;
                                if map[xx,yy]=d[head,4] then
				begin
                                        d[tail,3]:=d[head,3];
                                        if maw[xx,yy]<=d[tail,3] then
                                        begin
                                                dec(tail);
                                                continue;
                                        end
                                        else
                                                maw[xx,yy]:=d[tail,3];
                                        d[tail,4]:=map[xx,yy];
                                        if (xx=n) and (yy=n) then
                                        begin
                                                ans:=min(ans,d[tail,3]);
                                                dec(tail);
                                                continue;
                                        end;
					continue;
				end;
                                if (map[xx,yy]=0) and (bj[x,y]=false) then
                                begin
                                        d[tail,3]:=d[head,3]+2;
                                        if maw[xx,yy]<=d[tail,3] then
                                        begin
                                                dec(tail);
                                                continue;
                                        end
                                        else
                                                maw[xx,yy]:=d[tail,3];
                                        d[tail,4]:=map[x,y];
                                        if (xx=n) and (yy=n) then
                                        begin
                                                ans:=min(ans,d[tail,3]);
                                                dec(tail);
                                                continue;
                                        end;
                                        bj[xx,yy]:=true;
				        continue;
			        end;
                                if (map[xx,yy]<>d[head,4]) and (map[xx,yy]<>0) then
                                begin
                                        d[tail,3]:=d[head,3]+1;
                                        if maw[xx,yy]<=d[tail,3] then
                                        begin
                                                dec(tail);
                                                continue;
                                        end
                                        else
                                                maw[xx,yy]:=d[tail,3];
                                        d[tail,4]:=map[xx,yy];
                                        if (xx=n) and (yy=n) then
                                        begin
                                                ans:=min(ans,d[tail,3]);
                                                dec(tail);
                                                continue;
                                        end;
				        continue;
                                end;
			        dec(tail);
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');
        assign(output,'chess.out');
        reset(input);
        rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(x,y,z);
                map[x,y]:=z+1;
        end;
        fillchar(maw,sizeof(maw),127);
        ans:=maxlongint;
        bfs;
        if ans=2147483647 then
                writeln(-1)
        else
                writeln(ans);
        close(input);
        close(output);
end.