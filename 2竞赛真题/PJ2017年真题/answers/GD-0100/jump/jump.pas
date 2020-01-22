var
        n,d,k,i,g,max,l:longint;
        x,s,f:array[0..500000]of longint;
procedure sou(w,v:longint);
var
        l,i:longint;
begin
        if v>max then max:=v;
        if max>k then
        begin
                writeln(g);
                close(input);close(output);
                halt;
        end;
        for i:=w+1 to n do
        begin
                if (x[i]-x[w]>=d-g)and(x[i]-x[w]<=d+g)and((f[i]=-1)or(v+s[i]>f[i])) then
                begin
                        f[i]:=v+s[i];
                        sou(i,v+s[i]);
                end;
        end;
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        for i:=1 to n do
                readln(x[i],s[i]);
        l:=0;
        for i:=1 to n do
                if s[i]>0 then l:=l+s[i];
        if l<k then
        begin
                writeln('-1');
                close(input);close(output);
                exit;
        end;
        g:=0;
        while max<k do
        begin
                max:=0;
                inc(g);
                for i:=1 to n do
                        f[i]:=-1;
                sou(0,0);
        end;
        close(input);close(output);
end.
