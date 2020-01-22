type
        arr=record
                s:longint;
                h:longint;
            end;
var
        a,b:array[0..500010]of arr;
        n,d,k,t2,t,s,sum,t1,p1,p2,i,l,r,bza,bzb,ans:longint;
function ef(l,r,m:longint):longint;
var
        mid:longint;
begin
        while l<=r do
        begin
                mid:=(l+r)div 2;
                if a[mid].h>m then r:=mid-1
                else l:=mid+1;
        end;
        exit(l-1);
end;
function max(x,y:longint):longint;
begin
        if x>y then exit(x);
        exit(y);
end;
function min(x,y:longint):longint;
begin
        if x<y then exit(x);
        exit(y);
end;
procedure dg(o,u:longint);
var
        i,t:longint;
begin
        for i:=o to bzb do
        begin
                if b[i].s<=u then
                begin
                        t:=ef(1,bza,b[i].h);
                        t1:=min(t1,max(b[i].h-a[t].h,a[t+1].h-b[i].h));
                        t2:=max(t2,min(b[i].h-a[t].h,a[t+1].h-b[i].h));
                        if i<>bzb then
                        dg(i+1,u-b[i].s);
                end;
        end;
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        t2:=2147483647;
        for i:=1 to n do
        begin
                readln(l,r);
                s:=max(s,l);
                if r>0 then
                begin
                        inc(bza);
                        a[bza].s:=r;
                        a[bza].h:=l;
                        sum:=sum+a[bza].s;
                        p1:=p2;
                        p2:=a[bza].h;
                        t1:=max(t1,p2-p1);
                        t2:=min(t2,p2-p1);
                end
                else
                begin
                        inc(bzb);
                        b[bzb].s:=abs(r);
                        b[bzb].h:=l;
                end;
        end;
        if sum<k then
        begin
                writeln(-1);
                halt;
        end;
        if sum=k then
        begin
                writeln(max(abs(t1-d),abs(t2-d)));
                halt;
        end;
        sum:=sum-k;
        ans:=max(abs(t1-d),abs(t2-d));
        for i:=1 to bzb do
        begin
                if b[i].s<=sum then
                begin
                        t:=ef(1,bza,b[i].h);
                        t1:=min(t1,max(b[i].h-a[t].h,a[t+1].h-b[i].h));
                        t2:=max(t2,min(b[i].h-a[t].h,a[t+1].h-b[i].h));
                        dg(i+1,sum-b[i].s);
                end;
        end;
        writeln(max(abs(t1-d),abs(t2-d)));
        close(input);close(output);
end.