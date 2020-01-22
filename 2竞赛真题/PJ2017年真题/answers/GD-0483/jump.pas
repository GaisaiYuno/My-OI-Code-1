var
 x,a,f:array[0..500000] of longint;
 n,d,k,m,i,j,s,t:longint;
function max(x,y:longint):longint;
begin
        if x>y then exit(x)
        else exit(y);
end;
begin
        assign(input,'jump.in'); reset(input);
        assign(output,'jump.out'); rewrite(output);
        readln(n,d,k);
        s:=0;
        for i:=1 to n do
         begin
                readln(x[i],a[i]);
                if a[i]>0 then s:=s+a[i];
                t:=max(t,x[i]-x[i-1]);
         end;
        if s<k then
         begin
                writeln(-1);
                close(output);
                halt;
         end;
        if t-d<0 then t:=0
        else t:=t-d;
        for s:=t to x[n] do
         begin
                f[0]:=0;
                x[0]:=0;
                for i:=1 to n do
                 begin
                        f[i]:=-99999999;
                        for j:=i-1 downto 0 do
                         begin
                                if (x[i]-x[j]<=d+s) and (x[i]-x[j]>=d-s) then
                                 begin
                                        f[i]:=max(f[i],f[j]+a[i]);
                                 end
                                else break;
                         end;
                        if f[i]>=k then
                         begin
                                writeln(s);
                                close(input);
                                halt;
                         end;
                 end;
         end;
end.