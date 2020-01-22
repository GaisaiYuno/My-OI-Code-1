var
        i,j,k,l,r,n,m,mid,ned,x,y,ans:longint;
        a,d,v,z:array[0..500000] of longint;
        f:array[0..500000] of int64;
function max(x,y:longint):longint;
begin
        if x>y then exit(x)
        else exit(y);
end;
function pd(c:longint):boolean;
var
        i,j,y,x:longint;
        k,sum:int64;
begin
        y:=0;
        x:=0;
        k:=-maxlongint;
        f[0]:=v[0];
        k:=max(k,f[0]);
        if k>=ned then exit(true);
        for i:=1 to n do
        begin
                while (y+1<i) and (z[y+1]>=z[i]-(m+c)) and (z[y+1]<=z[i]-(m-c)) do inc(y);
                while (x<i) and ((z[x]+m-c>z[i]) or (z[x]+m+c<z[i])) do inc(x);
                f[i]:=v[i];
                sum:=-maxlongint div 2;
                for j:=x to y do
                begin
                        sum:=max(sum,f[j]);
                end;
                f[i]:=f[i]+sum;
                if x>y then
                begin
                        f[i]:=-maxlongint div 3;
                        x:=0;
                end;
                k:=max(k,f[i]);
                if k>=ned then exit(true);
        end;
        exit(false);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,m,ned);
        z[0]:=0;v[0]:=0;
        for i:=1 to n do
        begin
                readln(z[i],v[i]);
        end;
        l:=0;
        r:=z[n]-m;
        while l<=r do
        begin
                mid:=(l+r) div 2;
                if pd(mid) then
                begin
                        r:=mid-1;
                        ans:=mid;
                end
                else
                begin
                        l:=mid+1;
                end;
        end;
        if (ans=0) and (pd(0)) then
        writeln(ans)
        else
        if (ans=0) and (not pd(0)) then writeln(-1)
        else
        writeln(ans);
        close(input);close(output);
end.
