Var
        n,d,k,i,gold,num,j:longint;
        x,s:array[1..500000]of longint;
        ch:boolean;

Procedure dfs(wz,zh,jl1,jl2,gz:longint);
var
        i,j:longint;
Begin
        if gz=n then
                exit;
        if zh>=k then
        begin
                ch:=true;
                exit;
        end;

        for i:=jl1 to jl2 do
                for j:=gz+1 to n do
                        if (wz+i>=x[j]) and (zh+s[j]>=0) then
                                dfs(wz+i,zh+s[j],jl1,jl2,j);
End;

Begin
assign(input,'jump.in');reset(input);
assign(output,'jump.out');rewrite(output);

        readln(n,d,k);
        for i:=1 to n do
        begin
                readln(x[i],s[i]);
                if s[i]>0 then
                        num:=num+s[i];
        end;
        if num<k then
                writeln(-1)
        else
        begin
                gold:=1;
                while not ch do
                begin
                        if gold<d then
                                for i:=d-gold to d+gold do
                                        for j:=1 to n do
                                                if i>=x[j] then
                                                        dfs(i,s[j],d-gold,d+gold,j);

                        if gold>=d then
                                for i:=1 to d+gold do
                                        for j:=1 to n do
                                                if i>=x[j] then
                                                        dfs(i,s[j],1,d+gold,j);
                        inc(gold);
                end;
                writeln(gold);
        end;
        readln;

close(input);close(output);
End.
