var     x,s:array[0..500000]of longint;
        i,n,d,k,t,p,d1,score,jl1,j,max,w,t1:longint;
        bo:boolean;
begin
        assign(input,'jump.in');
        reset(input);
        assign(output,'jump.out');
        rewrite(output);
        readln(n,d,t1);
        for i:=1 to n do
        begin
                readln(x[i],s[i]);
        end;
        t:=x[n]-d;
        d1:=x[n];
        for i:=0 to t do
        begin
                score:=0;
                if i>=d then
                begin
                        d:=d+i;
                        p:=0;
                        w:=0;
                        while p<d1 do
                        begin
                                bo:=true;
                                max:=-1000000;
                                for j:=w+1 to n do if p<=x[j]then break;
                                for k:=j to n do
                                begin
                                        if (s[k]>max)and(x[k]-p<=d+i) then
                                        begin
                                                max:=s[k];
                                                w:=k;
                                        end;
                                end;
                                if max=-1000000 then break;
                                score:=score+max;
                                p:=x[w];
                        end;
                        d:=d-i;
                end
                else
                begin
                        p:=0;
                        w:=0;
                        while p<d1 do
                        begin
                                bo:=true;
                                max:=-1000000;
                                for j:=w+1 to n do if p<=x[j] then break;
                                for k:=j to n do
                                begin
                                        if (s[k]>max)and(x[k]-p<=d+i)and(x[k]-p>=d-i) then
                                        begin
                                                max:=s[k];
                                                w:=k;
                                        end;
                                end;
                                if max=-1000000 then break;
                                score:=score+max;
                                p:=x[w];
                        end;
                end;
                if score>=t1 then
                begin
                        writeln(i);
                        close(input);
                        close(output);
                        halt;
                end;
        end;
        writeln(-1);
        close(input);
        close(output);
end.
