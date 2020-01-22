var
        n,d,k,i:longint;
        a:array[0..50000,1..2] of longint;

function pd(o:longint):boolean;
var
        i,j:longint;
        f:array[0..50000] of longint;
begin
        fillchar(f,sizeof(f),128);
        f[0]:=0;
        for i:=0 to n-1 do
        begin
                for j:=i+1 to n do
                begin
                        if (a[j,1]-a[i,1]>=d-o)and(a[j,1]-a[i,1]<=d+o) then
                        begin
                                if f[i]+a[j,2]>f[j] then
                                        f[j]:=f[i]+a[j,2];
                                if f[j]>=k then
                                begin
                                        exit(true);
                                end;
                        end;
                end;
        end;
        exit(false);
end;

begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.ans');rewrite(output);

        readln(n,d,k);
        for i:=1 to n do
        begin
                readln(a[i,1],a[i,2]);
        end;

        for i:=0 to a[n,1] do
        begin
                if pd(i) then
                begin
                        writeln(i);
                        halt;
                end;
        end;
        writeln(-1);

        close(input);close(output);
end.