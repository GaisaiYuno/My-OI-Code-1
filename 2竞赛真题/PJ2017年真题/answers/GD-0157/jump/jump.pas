var
        i,j,n,d,k,l,r,mid,ans,ma:longint;
        a:array[0..500000,1..2]of longint;
function max(x,y:longint):longint;
begin
        if x>y then exit(x)
        else exit(y);
end;
function dp(x:longint):boolean;
var
        i,j,g,w:longint;
        sd:int64;
begin
        sd:=0;
        g:=0;
        w:=0;
        while g<n do
        begin
                for i:=g+1 to n do
                begin
                        if (a[g,1]+max(1,d-x)<=a[i,1])and(a[g,1]+d+x>=a[i,1]) then
                        begin
                                if ((a[i,2]<0)and(a[i,2]>a[w,2]))or(a[i,2]>=0) then
                                begin
                                        w:=i;
                                end;
                                if a[w,2]>=0 then break;
                        end;
                        if a[g,1]+d+x<a[i,1] then break;
                end;
                if w=0 then break
                else
                begin
                        sd:=sd+a[w,2];
                        g:=w;
                        if sd>=k then break;
                end;
                w:=0;
        end;
        if sd>=k then exit(true)
        else exit(false);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        a[0,1]:=0;
        a[0,2]:=-10001;
        for i:=1 to n do
        begin
                readln(a[i,1],a[i,2]);
                ma:=max(a[i,1],ma);
        end;
        l:=1;
        r:=max(ma-d,d-1);
        while l<=r do
        begin
                mid:=(l+r) div 2;
                if dp(mid) then
                begin
                        r:=mid-1;
                        ans:=mid;
                end
                else
                begin
                        l:=mid+1;
                end;
        end;
        if ans>0 then writeln(ans)
        else writeln(-1);
        close(input);
        close(output);
end.
