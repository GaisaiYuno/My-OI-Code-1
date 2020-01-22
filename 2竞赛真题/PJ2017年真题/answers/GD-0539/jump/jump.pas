var
        d,i,j,n,m,k,ans,s,q:longint;
        a:array[0..500000,1..2] of longint;
function max(a,b:longint):longint;
begin
        if (a>b) then
                exit(a)
        else
                exit(b);
end;
function min(a,b:longint):longint;
begin
        if (a<b) then
                exit(a)
        else
                exit(b);
end;
procedure dg(t,g,x:longint);
var
        i,j,k,l:longint;
begin
        if (ans<g) then
                exit;
        if (x>m) then
        begin
                s:=1;
                ans:=min(ans,g);
                exit;
        end;
        if (t>=n) then
                exit;
        for i:=t+1 to n do
        begin
                if (ans<g) then
                        exit;
                j:=max(1,d-g);
                k:=d+g;
                if (a[i,1]-a[t,1]>=j)and(a[i,1]-a[t,1]<=k) then
                begin
                        dg(i,g,x+a[i,2]);
                end
                else
                begin
                        if (a[i,1]-a[t,1]<j) then
                        begin
                                dg(i,g+j-a[i,1]+a[t,1],x+a[i,2]);
                        end
                        else
                        begin
                                dg(i,g+a[i,1]-a[t,1]-j,x+a[i,2]);
                        end;
                end;
        end;
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        ans:=maxlongint;
        s:=0;
        a[0,1]:=0;
        a[0,2]:=0;
        s:=0;
        readln(n,d,m);
        for i:=1 to n do
        begin
                readln(a[i,1],a[i,2]);
                s:=s+max(a[i,2],0);
        end;
        if (s<m) then
                writeln(-1)
        else
        begin
                s:=0;
                dg(0,0,0);
                writeln(ans);
        end;
        close(input);
        close(output);
end.
