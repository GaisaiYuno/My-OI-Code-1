var
        d,s,f:array[0..500001]of longint;
        n,d1,k,i,j,ans,l,r,mid:longint;
function bb(w:longint):longint;
begin
        if d1-w<=0 then
                bb:=1
        else
                bb:=d1-w;
end;
procedure dg(k:longint);
var
        i:longint;
begin
        if f[k]<>-maxlongint then
        begin
        if k=3 then
                begin
                        k:=3;
                end;
                i:=k+1;
                while (d[i]-d[k]<=d1+mid)and(i<=n)do
                begin
                        if (d[i]-d[k]>=bb(mid)) then
                        if f[k]+s[i]>f[i] then
                                begin
                                        f[i]:=f[k]+s[i];
                                        if f[i]>ans then
                                                ans:=f[i];
                                        dg(i);
                                end;
                        inc(i);
                end;
        end;
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        read(n,d1,k);
        for i:=1 to n do
                read(d[i],s[i]);
        l:=1;
        r:=abs(n-d1)+1;
        mid:=1;
        repeat
                mid:=(l+r)div 2;
                ans:=0;
                for i:=1 to n do
                        f[i]:=-maxlongint;
                f[1]:=s[1];
                if bb(mid)<=d[1]then
                        begin
                                ans:=s[1];
                                f[1]:=s[1];
                                dg(1);
                        end;
                if (ans>k) then
                        r:=mid-1
                else
                        l:=mid+1;
                if ans=k then
                        begin
                                writeln(mid);
                                close(input);
                                close(output);
                                exit;
                        end;

        until r<l;
        if ans>=k then
        writeln(mid)
        else
        writeln('-1');
        close(input);
        close(output);
end.
