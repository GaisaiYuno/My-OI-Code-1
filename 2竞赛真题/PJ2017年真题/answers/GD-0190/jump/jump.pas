var
        n,d,k,l,r,mid,js:longint;
        i,j:longint;
        a:array[0..500000,1..2] of longint;
        bz:boolean;
function max(x,y:longint):longint;
begin
        if x>y then exit(x)
        else
                exit(y);
end;
procedure search(t,x,s:longint);
var
        l:longint;
begin
        if s>=k then
        begin
                bz:=true;
                exit;
        end;
        for l:=t+1 to n do
        begin
                if (a[t,1]+d-x<=a[l,1]) and (a[t,1]+d+x>=a[l,1]) then
                begin
                        search(l,x,s+a[l,2]);
                        if bz then exit;
                end;
        end;
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        read(n,d,k);
        a[0,1]:=0;
        a[0,2]:=0;
        for i:=1 to n do
        begin
                read(a[i,1],a[i,2]);
        end;
        l:=0;
        r:=max(d,n-d);
        js:=r;
        while l<r do
        begin
                mid:=(l+r) div 2;
                bz:=false;
                search(0,mid,0);
                if bz then
                begin
                        r:=mid;
                end
                else
                begin
                        l:=mid+1;
                end;
        end;
        if r=js then r:=-1;
        write(r);
        close(input);
        close(output);
end.