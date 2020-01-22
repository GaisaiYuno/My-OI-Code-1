var
        a,f:array[0..500000] of longint;
        i,j,n,k,d:longint;
function max(a,b:longint):longint;
begin
        if a>b then
                exit(a)
        else exit(b);
end;
function dg(x,t,fen:longint):boolean;
var
        j:longint;
begin
        if fen>=k then exit(true);
        j:=1;
        while f[t+j]-f[t]in[max(d-x,1)..d+x] do
        begin
                dg(x,t+1,fen+a[t+1]);
                inc(j);
        end;
        exit(false);
end;
BEGIN
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        for i:=1 to n do readln(f[i],a[i]);
        for i:=1 to f[n] do
        begin
                if dg(i,0,0) then
                begin
                        writeln(i);
                        close(input);close(output);
                        halt;
                end;
        end;
        writeln(-1);
        close(input);close(output);
END.
