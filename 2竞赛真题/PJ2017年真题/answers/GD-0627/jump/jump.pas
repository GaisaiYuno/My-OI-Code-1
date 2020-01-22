var
        n,d,k,x,y,mid,g:longint;
        a:array[0..500000,1..2] of longint;

function max(a,b:longint):longint;
begin
        if a>b then
                max:=a
        else
                max:=b;
end;

function pd(g:longint):boolean;
var
        i,j,x,y,mid,ans:longint;
        f:array[0..500000] of longint;
        b:array[0..500000] of boolean;
begin
        fillchar(f,sizeof(f),128);
        fillchar(b,sizeof(b),false);
        f[0]:=0;
        b[0]:=true;
        for i:=0 to n-1 do
        begin
                if not b[i] then
                        continue;
                ans:=n+1;
                x:=i+1;
                y:=n;
                while x<=y do
                begin
                        mid:=(x+y) div 2;
                        if a[mid,1]-a[i,1]>=max(d-g,1) then
                        begin
                                y:=mid-1;
                                ans:=mid;
                        end
                        else
                        begin
                                x:=mid+1;
                        end;
                end;
                j:=ans;
                while (j<=n)and(a[j,1]-a[i,1]<=d+g) do
                begin
                        f[j]:=max(f[j],f[i]+a[j,2]);
                        if f[j]>=k then
                                exit(true);
                        b[j]:=true;
                        j:=j+1;
                end;
        end;
        exit(false);
end;

begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);

        readln(n,d,k);
        for y:=1 to n do
        begin
                readln(a[y,1],a[y,2]);
        end;
        x:=0;
        y:=a[n,1];
        g:=-1;
        while x<=y do
        begin
                mid:=(x+y) div 2;
                if pd(mid) then
                begin
                         y:=mid-1;
                         g:=mid;
                end
                else
                begin
                        x:=mid+1;
                end;
        end;

        writeln(g);

        close(input);close(output);
end.
