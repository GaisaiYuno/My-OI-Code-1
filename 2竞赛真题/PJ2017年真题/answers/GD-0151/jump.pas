uses math;
var
        m,d,k,n,i,j,l,s:longint;
        a:array[1..10000000] of longint;
procedure dg(x,t,ans:longint);
var
        i,j,l:longint;
begin
        if ans>s then s:=ans;
        if s>=k then exit;
        for i:=max(1,d-x) to d+x do
        begin
                if a[i+t]<>maxlongint then dg(x,i+t,ans+a[i+t]);
                if s>=k then exit;
        end;
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        read(n,d,k);
        for i:=1 to 10000000 do
                a[i]:=maxlongint;
        for i:=1 to n do
        begin
                read(l,j);
                a[l]:=j;
                if l+1>m then m:=l+1;
        end;
        for i:=1 to m do
        begin
                s:=0;
                dg(i,0,0);
                if s>=k then
                begin
                        writeln(i);
                        halt;
                end;
        end;
        write(-1);
        close(input);
        close(output);
end.