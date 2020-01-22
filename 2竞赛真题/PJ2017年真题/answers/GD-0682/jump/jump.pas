var
        w,v,f:array[1..1000]of longint;
        n,d,m,x,y,i,j,l,s,h,ans:longint;
function max(a,b:longint):longint;
begin
        if a>b then exit(a) else exit(b);
end;
function min(a,b:longint):longint;
begin
        if a<b then exit(a) else exit(b);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        read(n,d,m);
        s:=0;
        for i:=1 to n do
        begin
                read(w[i],v[i]);
                if v[i]>0 then s:=s+v[i];
                h:=max(h,w[i]);
        end;
        if s<m then
        begin
                write('-1');
                halt;
                close(input);
                close(output);
        end
        else
                write('2');
        close(input);
        close(output);
end.
