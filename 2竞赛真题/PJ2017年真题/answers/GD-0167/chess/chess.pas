var
        a,b,c,i,j,k,q1,q2,x,y,ans,ans1,q11,q22:longint;
        p:array[1..100,1..100]of longint;
        v:array[1..100000,1..2]of longint;
        t:array[1..100,1..100]of longint;
const
        r:array[1..4,1..2]of longint=((1,0),(0,1),(-1,0),(0,-1));
        r1:array[1..8,1..2]of longint=((2,0),(0,2),(-2,0),(0,-2),(-1,1),(1,-1),(-1,-1),(1,1));
function min(a,b:longint):longint;
begin
        if a<b then
                exit(a)
        else
                exit(b);
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(a,b);
        for c:=1 to b do
        begin
                readln(i,j,k);
                p[i,j]:=k+1;
        end;
        ans1:=maxlongint;
        fillchar(t,sizeof(t),127);
        q2:=1;
        v[1,1]:=1;
        v[1,2]:=1;
        t[1,1]:=0;
        while q1+q11*100000<q2+q22*100000 do
        begin
                inc(q1);
                if q1>100000 then
                begin
                        q1:=1;
                        inc(q11);
                end;
                for i:=1 to 4 do
                begin
                        if (v[q1,1]+r[i,1]>=1)and(v[q1,1]+r[i,1]<=a)
                        and(v[q1,2]+r[i,2]>=1)and(v[q1,2]+r[i,2]<=a) then
                        begin
                                x:=v[q1,1]+r[i,1];
                                y:=v[q1,2]+r[i,2];
                                if p[x,y]<>0 then
                                begin
                                        if p[x,y]<>p[v[q1,1],v[q1,2]] then
                                                ans:=t[v[q1,1],v[q1,2]]+1
                                        else
                                                ans:=t[v[q1,1],v[q1,2]];
                                        if t[x,y]>ans then
                                        begin
                                                t[x,y]:=ans;
                                                inc(q2);
                                                if q2>100000 then
                                                begin
                                                        q2:=1;
                                                        inc(q22);
                                                end;
                                                v[q2,1]:=x;
                                                v[q2,2]:=y;
                                                if (x=a)and(y=a) then
                                                        ans1:=min(ans1,ans);
                                        end;
                                end
                                        else
                                if (x=a)and(y=a) then
                                begin
                                        t[x,y]:=min(t[x,y],t[v[q1,1],v[q1,2]]+2);
                                        ans1:=min(ans1,t[x,y]);
                                end;
                        end;
                end;
                for i:=1 to 8 do
                begin
                        if (v[q1,1]+r1[i,1]>=1)and(v[q1,1]+r1[i,1]<=a)
                        and(v[q1,2]+r1[i,2]>=1)and(v[q1,2]+r1[i,2]<=a) then
                        begin
                                x:=v[q1,1]+r1[i,1];
                                y:=v[q1,2]+r1[i,2];
                                if p[x,y]<>0 then
                                begin
                                        if p[x,y]<>p[v[q1,1],v[q1,2]] then
                                                ans:=t[v[q1,1],v[q1,2]]+3
                                        else
                                                ans:=t[v[q1,1],v[q1,2]]+2;
                                        if t[x,y]>ans then
                                        begin
                                                t[x,y]:=ans;
                                                inc(q2);
                                                if q2>100000 then
                                                begin
                                                        q2:=1;
                                                        inc(q22);
                                                end;
                                                v[q2,1]:=x;
                                                v[q2,2]:=y;
                                                if (x=a)and(y=a) then
                                                        ans1:=min(ans1,ans);
                                        end;
                                end;
                        end;
                end;
        end;
        if ans1=maxlongint then
                writeln(-1)
        else
                writeln(ans1);
        close(input);
        close(output);
end.
