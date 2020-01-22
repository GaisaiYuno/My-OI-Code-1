var     n,m,i,j,k,l,ans,t,x,y:longint;
        a:array[0..1001] of longint;
        p:array[1..8] of longint=(10,100,1000,10000,100000,1000000,10000000,100000000);
function min(a,b:longint):longint;
begin
        if a<b then min:=a else min:=b;
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do readln(a[i]);
        for i:=1 to m do
        begin
                ans:=maxlongint;
                readln(x,y);
                for j:=1 to n do
                        if a[j] mod p[x]=y then ans:=min(ans,a[j]);
                if ans=maxlongint then writeln(-1) else writeln(ans);
        end;
        close(input);close(output);
end.
