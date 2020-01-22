var
        n,d,k,i,j,x,y,z,s,ls,l,r,mid:longint;
        a:array[0..500001,1..2]of longint;
function max(x,y:longint):longint;
begin
        if x>y then exit(x)
        else exit(y);
end;
function pd(l,r,k:longint):boolean;
var
        i,j,x,y,z,s,ls,ll,rr,p:longint;
        f:array[0..500001]of longint;
        d:array[0..500001,1..2]of longint;
begin
        ll:=1;
        rr:=1;
        d[1,1]:=0;
        d[1,2]:=0;
        p:=1;
        for i:=1 to n do
        begin
                f[i]:=-maxlongint-1;
                while (rr>=ll)and((a[i,1]-d[ll,2]>l)or(a[i,1]-d[ll,2]<r)) do
                inc(ll);
                while ((a[i,1]-a[p,1])>=r)and(p<=n) do
                begin
                        if a[i,1]-a[p,1]<=l then
                        begin
                                while (rr>=ll)and(d[rr,1]<=f[p]) do
                                dec(rr);
                                inc(rr);
                                d[rr,1]:=f[p];
                                d[rr,2]:=a[p,1];
                        end;
                        inc(p);
                end;
                if (ll<=rr)and(d[ll,1]<>-maxlongint-1) then f[i]:=d[ll,1]+a[i,2];
                if f[i]>=k then exit(true);

        end;
        exit(false);
end;
begin
        assign(input,'jump.in');
        reset(input);
        assign(output,'jump.out');
        rewrite(output);
        readln(n,d,k);
        for i:=1 to n do
        readln(a[i,1],a[i,2]);
        l:=0;
        r:=a[n,1];
        s:=-1;
        while l<=r do
        begin
                mid:=(l+r) div 2;
                if pd(d+mid,max(1,d-mid),k) then
                begin
                        s:=mid;
                        r:=mid-1;
                end
                else l:=mid+1;
        end;
        writeln(s);
        close(input);
        close(output);
end.
