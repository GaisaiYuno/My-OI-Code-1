var
        f:array[1..500000]of longint;
        a:array[1..500000,1..2]of longint;
        l,r,n,i,mid,d,k,min,s:longint;
function pd(x:longint):boolean;
var
        i,j,y:longint;
begin
        y:=d-x;
        if y<=0 then y:=1;
        if(a[1,1]>x+d)or(a[1,1]<y)then exit(false);
        f[1]:=a[1,2];
        for i:=2 to n do
        begin
                f[i]:=-maxlongint+500000;
                j:=i-1;
                while(a[i,1]<=a[j,1]+x+d)and(a[i,1]>=a[j,1]+y)do
                begin
                        if f[j]+a[i,2]>f[i] then f[i]:=f[j]+a[i,2];
                        dec(j);
                        if j=0 then break;
                end;
                if f[i]>=k then exit(true);
        end;
        exit(false);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        min:=maxlongint;
        for i:=1 to n do
        begin
                readln(a[i,1],a[i,2]);
                if a[i,2]>0 then inc(s,a[i,2]);
        end;
        if s<k then
        begin
                writeln('-1');
                close(input);
                close(output);
                halt;
        end;
        l:=0;
        r:=a[n,1]-d;
        while l<=r do
        begin
                mid:=(l+r)div 2;
                if pd(mid)=true then
                begin
                        r:=mid-1;
                        min:=mid;
                end
                else l:=mid+1;
        end;
        write(min);
        close(input);
        close(output);
end.
