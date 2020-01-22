program score;
var     i,j,k,n,m,d,p,l,r,max,bo:longint;
        z:array[0..100000,0..3]of longint;
        f:array[0..100000]of longint;
begin
        assign(input,'jump.in');
        reset(input);
        assign(output,'jump.out');
        rewrite(output);
        readln(n,d,p);
        for i:=1 to n do
        begin
                readln(z[i,1],z[i,2]);
        end;
        bo:=1;
        max:=-maxlongint div 10;
        for i:=0 to n do
        begin
                l:=d-i;
                r:=d+i;
                if l<0 then l:=1;
                for j:=1 to n do
                        f[j]:=-maxlongint div 10;
                for j:=1 to n do
                begin
                        for k:=j-1 downto 0 do
                        begin
                                if (z[j,1]-z[k,1]>=l)and
                                (z[j,1]-z[k,1]<=r)and
                                (f[j]<f[k])then
                                        f[j]:=f[k];
                        end;
                        f[j]:=f[j]+z[j,2];
                        if max<f[j] then
                                max:=f[j];
                end;
                if max>=p then
                begin
                        bo:=0;
                        write(i);
                        break;
                end;
        end;
        if bo=1 then
                write(-1);
        close(input);
        close(output);
end.
