var
        p,s,bz:array[0..500000] of longint;
        i,n,m,d,l,r,mid,x,ans:longint;
        t:int64;
procedure dg(k,z:longint);
var
        v,j:longint;
begin
        if z>t then t:=z;
        if t>m then exit;
        v:=0;
        for j:=k+1 to n do
        begin
                v:=v+p[j];
                if v>d+mid then break;
                if ((d-mid<1) and (v>0)) or ((d-mid>=1) and (v>=d-mid)) then
                begin
                        if z+s[j]>bz[j] then
                        begin
                                bz[j]:=z+s[j];
                                dg(j,bz[j]);
                                if t>m then break;
                        end;
                end
        end;
        if t>m then exit;
end;
begin
        assign(input,'jump.in'); reset(input);
        assign(output,'jump.out'); rewrite(output);
        readln(n,d,m);
        t:=0;
        r:=0;
        for i:=1 to n do
        begin
                readln(x,s[i]);
                p[i]:=x-r;
                r:=x;
                if s[i]>0 then t:=t+s[i];
        end;
        if t<m then
        begin
                writeln(-1);
                exit;
        end;
        l:=0;
        r:=abs(r-d);
        while l<=r do
        begin
                mid:=(l+r) div 2;
                t:=0;
                for i:=1 to n do
                        bz[i]:=-maxlongint;
                dg(0,0);
                if t>=m then
                begin
                        ans:=mid;
                        r:=mid-1;
                end
                else l:=mid+1;
        end;
        writeln(ans);
        close(input);
        close(output);
end.