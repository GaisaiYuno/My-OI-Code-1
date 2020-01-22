const dx:array[1..4]of integer=(0,0,1,-1);
      dy:array[1..4]of integer=(1,-1,0,0);
var     n,m,x,y,c,i:longint;
        a:array[0..101,0..101]of integer;

function pd1(x,y:longint):boolean;
begin
        if (a[x,y+1]=0)and(a[x+1,y]=0)and(a[x-1,y]=0)and(a[x,y-1]=0)then exit(false);
        exit(true);
end;

function pd(x,y:longint):boolean;
begin
        if (x<1)or(y<1)or(x>n)or(y>n) then exit(false);
        exit(true);
end;
procedure bfs;
var     k:array[0..101,0..101]of longint;
        head,tail,i,xx,yy,j,s:longint;
        state:array[0..100000,0..2]of longint;
        m,z:array[0..100000]of integer;
begin
        for i:=1 to n do
                for j:=1 to n do k[i,j]:=maxlongint;
        head:=0; tail:=1;
        state[1,1]:=1; state[1,2]:=1; k[1,1]:=0; m[head]:=0;
        while (head<tail) do
        begin
                inc(head);
                for i:=1 to 4 do
                begin
                        xx:=state[head,1]+dx[i]; yy:=state[head,2]+dy[i];
                        if pd(xx,yy) then
                        begin
                                if (a[state[head,1],state[head,2]]=0) then s:=a[state[z[head],1],state[z[head],2]]
                                else s:=a[state[head,1],state[head,2]];
                                if (a[xx,yy]=s) then
                                begin
                                        if k[xx,yy]>k[state[head,1],state[head,2]] then
                                        begin
                                                inc(tail);
                                                state[tail,1]:=xx; state[tail,2]:=yy;
                                                k[xx,yy]:=k[state[head,1],state[head,2]];
                                                m[tail]:=0;
                                        end;
                                end;
                                if (a[xx,yy]<>s)and(a[xx,yy]<>0) then
                                begin
                                        if k[xx,yy]>=k[state[head,1],state[head,2]]+1 then
                                        begin
                                                inc(tail);
                                                state[tail,1]:=xx; state[tail,2]:=yy;
                                                k[xx,yy]:=k[state[head,1],state[head,2]]+1;
                                                m[tail]:=0;
                                        end;
                                end;
                                if (a[xx,yy]=0)and(m[head]=0) then
                                begin
                                        if k[xx,yy]>k[state[head,1],state[head,2]]+2 then
                                        begin
                                                if pd1(xx,yy)=true then
                                                begin
                                                        inc(tail);
                                                        if (tail=1000000) then write(-1);
                                                        state[tail,1]:=xx; state[tail,2]:=yy;
                                                        k[xx,yy]:=k[state[head,1],state[head,2]]+2;
                                                        m[tail]:=1;
                                                        z[tail]:=head;
                                                end;
                                        end;
                                end;
                        end;
                end;
        end;
        if k[n,n]=maxlongint then writeln(-1) else writeln(k[n,n]);
end;

begin
        assign(input,'chess.in');
        assign(output,'chess.out');
        reset(input);
        rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(x,y,c);
                a[x,y]:=c+1;
        end;
        bfs;
        close(input);
        close(output);
end.
