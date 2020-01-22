var
        a,b,f:array[0..500000]of longint;
        i,n,m,k,r,l,o,p,u:longint;
function max(x,y:longint):longint;
begin
        if x<y then exit(y) else exit(x);
end;
function er(y,x:longint):longint;
var
        r,l,m:longint;
begin
        r:=0;
        l:=y;
        while l-r>1 do
        begin
                m:=(l+r) div 2;
                if a[y+1]-a[m]>=x then r:=m else l:=m;
        end;
        if a[y+1]-a[l]>=x then exit(l) else if a[y+1]-a[r]>=x then exit(r)
        else exit(-1);
end;
function pd(x:longint):boolean;
var
        i,j,t:longint;
begin
        fillchar(f,sizeof(f),128);
        f[0]:=0;
        if x<m then
        begin
                for i:=1 to n do
                begin
                        t:=er(i-1,m-x);
                        for j:=t downto o do
                        begin
                                if (a[i]-a[j]<=x+m) then
                                f[i]:=max(f[i],f[j]+b[i])
                                else break;
                        end;
                end;
                if f[n]>=k then exit(true) else exit(false);
        end
        else
        begin
                for i:=1 to n do
                  for j:=i-1 downto 0 do
                  begin
                        if (a[i]-a[j]<=x+m) then
                        f[i]:=max(f[i],f[j]+b[i])
                        else break;
                  end;
                if f[n]>=k then exit(true) else exit(false);
        end;
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        read(n,m,k);
        for i:=1 to n do
        read(a[i],b[i]);
        r:=1;
        l:=a[n];
        while l-r>1 do
        begin
                u:=(r+l) div 2;
                if pd(u) then l:=u else r:=u;
        end;
        if pd(r) then writeln(r) else if pd(l) then writeln(l)
         else writeln('-1');
        close(input);close(output);
end.
