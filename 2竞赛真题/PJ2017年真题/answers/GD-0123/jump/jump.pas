var
        n,d,k,g,i,j,m,ans,min,max,x:longint;
        a,b,c:array[0..500001]of longint;
        p:boolean;
procedure fun(i,j,t:longint);
begin
        if t>=k then
        begin
                writeln(g);
                close(input); close(output);
                halt;
        end;
        while j<=n do
        begin
                inc(j);
                x:=abs(a[j]-(i+d));
                if x<=g then fun(a[j],j,t+b[j]);
        end;
end;
begin
        assign(input,'jump.in'); reset(input);
        assign(output,'jump.out'); rewrite(output);
        readln(n,d,k);
        min:=maxlongint;
        max:=-min;
        for i:=1 to n do
        begin
                readln(a[i],b[i]);
                c[i]:=a[i]-a[i-1];
                if b[i]>0 then m:=m+b[i];
        end;
        if m<k then
        begin
                writeln(-1);
                close(input); close(output);
                halt;
        end;
        g:=-1;
        p:=true;
        while p do
        begin
                inc(g);
                m:=0;
                fun(0,0,m);
        end;
        writeln(g);

        close(input); close(output);
end.
