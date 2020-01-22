uses math;
var     x,s:array[0..500000]of longint;
        n,d,i:longint;
        k,sum:int64;

procedure bfs;
var     head,tail,ans,i,mx,mn:longint;
        state:array[0..1000000,1..3]of longint;
begin
        head:=0; tail:=1;
        state[1,1]:=0; state[1,2]:=0; state[1,3]:=0;
        ans:=maxlongint;
        while (head<tail) do
        begin
                head:=head+1;
                for i:=state[head,1]+1 to n do
                begin
                        if state[head,2]>=d then
                        begin
                                mx:=d+state[head,2];
                                mn:=1;
                        end
                        else
                        begin
                                mx:=d+state[head,2];
                                mn:=d-state[head,2];
                        end;
                        if ((x[i]-x[state[head,1]])>=mn)and((x[i]-x[state[head,1]])<=mx) then
                        begin
                                inc(tail);
                                state[tail,1]:=i;
                                state[tail,2]:=state[head,2];
                                state[tail,3]:=state[head,3]+s[i];
                                if state[tail,3]>=k then ans:=min(ans,state[tail,2]);
                        end;
                        if (x[i]-x[state[head,1]])<mn then
                        begin
                                inc(tail);
                                state[tail,1]:=i;
                                state[tail,2]:=state[head,2]+mn-(x[i]-x[state[head,1]]);
                                state[tail,3]:=state[head,3]+s[i];
                                if state[tail,3]>=k then ans:=min(ans,state[tail,2]);
                        end;
                        if (x[i]-x[state[head,1]])>mx then
                        begin
                                inc(tail);
                                state[tail,1]:=i;
                                state[tail,2]:=state[head,2]+(x[i]-x[state[head,1]])-mx;
                                state[tail,3]:=state[head,3]+s[i];
                                if state[tail,3]>=k then ans:=min(ans,state[tail,2]);
                        end;
                end;
        end;
        if ans=maxlongint then write(-1) else write(ans);
end;

begin
        assign(input,'jump.in');
        assign(output,'jump.out');
        reset(input);
        rewrite(output);
        readln(n,d,k);
        for i:=1 to n do
        begin
                readln(x[i],s[i]);
                if (s[i]>0) then sum:=sum+s[i];
        end;
        if sum<k then
        begin
                write(-1);
                close(input);
                close(output);
                halt;
        end;
        bfs;
        close(input);
        close(output);
end.