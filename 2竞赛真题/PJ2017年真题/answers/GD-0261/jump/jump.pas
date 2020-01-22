var     n,d,s,i,j,k,suma,x,y,l,r,mid,ans:longint;
        a,b:array[0..500001] of longint;
function can(t:longint):boolean;
var     x,i,j,k:longint;
        da,f:array[0..500001] of longint;
begin
        if t>=d then
        begin
                if a[1]<t+d then
                begin
                        da[1]:=1;
                        f[1]:=b[1];
                end
                else exit(false);
        end
        else
        begin
                if (a[1]>=d-t)and(a[1]<=d+t) then
                begin
                        da[1]:=1;
                        f[1]:=b[1];
                end
                else exit(false);
        end;
        i:=0;
        j:=1;
        while i<=j do
        begin
                inc(i);
                for k:=da[i]+1 to n do
                begin
                        if t>=d then
                        begin
                                if a[da[i]]+t+d>=a[k] then
                                begin
                                        inc(j);
                                        da[j]:=k;
                                        f[j]:=f[i]+b[k];
                                        if f[j]>=s then exit(true);
                                end
                                else break;
                        end
                        else
                        begin
                                if (a[da[i]]+d-t<=a[k])and(a[da[i]]+d+t>=a[k]) then
                                begin
                                        inc(j);
                                        da[j]:=k;
                                        f[j]:=f[i]+b[k];
                                        if f[j]>=s then exit(true);
                                end
                                else break;
                        end;
                end;
        end;
        exit(false);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,s);
        for i:=1 to n do
        begin
                readln(a[i],b[i]);
                if b[i]>0 then inc(suma,b[i]);
        end;
        if s>suma then writeln(-1)
        else
        begin
                l:=1;
                r:=a[n];
                while l<r do
                begin
                        mid:=(l+r) div 2;
                        if can(mid) then
                        begin
                                r:=mid-1;
                                ans:=mid;
                        end
                        else l:=mid;
                end;
                writeln(ans);
        end;
        close(input);close(output);
end.
