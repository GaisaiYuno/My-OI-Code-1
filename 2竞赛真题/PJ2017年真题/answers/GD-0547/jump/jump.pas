var     l,r,mid,n,d,k,i,j,ans,head,tail,qt:longint;
        x,s,f,q:array[0..500000] of longint;
procedure delete;
begin
        while (head<=tail)and(x[q[head]]<x[i]-d-mid)do inc(head);
end;
procedure insert(x:longint);
begin
        while (head<=tail)and(f[x]>f[q[tail]])do dec(tail);
        inc(tail);
        q[tail]:=x;
end;
procedure into;
begin
        while (qt<i)and(x[qt]<=x[i]-d+mid)do
        begin
                insert(qt);
                inc(qt);
        end;
end;
function jump:boolean;
begin
        qt:=1;
        f[1]:=s[1];
        if f[1]>k then exit(true);
        for i:=2 to n do
        begin
                into;
                delete;
                f[i]:=0;
                if head>tail then continue;
                f[i]:=f[q[head]]+s[i];
                if f[i]>=k then exit(true);
        end;
        exit(false);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        dec(d);
        for i:=1 to n do readln(x[i],s[i]);
        l:=0;
        r:=x[n];
        ans:=-1;
        repeat
                mid:=(l+r)div 2;
                head:=1;
                tail:=0;
                if jump then
                begin
                        ans:=mid;
                        r:=mid-1;
                end else l:=mid+1;
        until l>r;
        writeln(ans);
        close(input);close(output);
end.
