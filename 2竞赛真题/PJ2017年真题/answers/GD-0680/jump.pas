var
        i,j,k,l,n,m,ans,d,g,max:longint;
        a,b:array[0..50001]of longint;
        f:array[0..501]of longint;
begin
assign(input,'jump.in');
reset(input);
assign(output,'jump.out');
rewrite(output);
        read(n,d,k);
        m:=0;
        l:=0;
        g:=0;
        for i:=1 to n do
        begin
                read(a[i],b[i]);
                if b[i]>0 then m:=m+b[i];
        end;
        if m<k then
        begin
                write(-1);
                close(input);
                close(output);
                halt;
        end;
        while true do
        begin
                for i:=1 to n do
                begin
                if (a[i]-a[i-1]>=d-g)and(a[i]-a[i-1]<=d+g) then
                 begin
                        max:=0;
                        for j:=i-1 downto 1 do
                                if(a[i]-a[j]>=d-g)and(a[i]-a[j]<=d+g) then
                                        if f[j]>max then
                                                max:=f[j];
                        f[i]:=b[i]+max;
                        if f[i]>=k then
                        begin
                                write(g);
                                close(input);
                                close(output);
                                halt;
                        end;
                 end
                 else if a[i]-a[i-1]>d+g then break;
                end;
                g:=g+1;
        end;
close(input);
close(output);
end.