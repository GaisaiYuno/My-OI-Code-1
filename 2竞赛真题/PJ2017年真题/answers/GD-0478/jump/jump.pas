var
        i,j,k,m,n,o,p,l,s,t,d,r,mid,cun,zuo,you,zuo1,you1,x,y:longint;
        a,b,f:array[-1000000..1000000] of longint;
function max(a,b:longint):longint;
begin
        if a>b then exit(a) else exit(b);
end;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,k);
        for i:=1 to n do readln(a[i],b[i]);
        l:=1;r:=1000000;mid:=(l+r) div 2;
        while l<=r do begin
                fillchar(f,sizeof(f),0);
                zuo1:=max(1,d-mid);
                you1:=d+mid;
                fillchar(f,sizeof(f),0);
                for i:=1 to n do begin
                        x:=a[i]-you1+1;
                        y:=a[i]-zuo1; zuo:=0;you:=0;
                        f[i]:=b[i];
                        for j:=1 to n do begin

                                if (a[j]>=x) and (a[j]<=y) then
                                        if zuo=0 then zuo:=j;
                        end;
                        for j:=n downto 1 do begin
                                if (a[j]>=x) and (a[j]<=y) then
                                        if you=0 then you:=j;
                        end;
                        for j:=zuo to you do begin
                                f[i]:=max(f[i],f[j]+b[i]);
                        end;
                end;
                if a[1]>mid then f[n]:=-maxlongint;
                if f[n]<k then begin
                        //cun:=mid;
                        l:=mid+1;mid:=(l+r) div 2;
                end else begin
                         cun:=mid;
                        r:=mid-1;mid:=(l+r) div 2;

                end;

        end;
        if cun=0 then dec(cun);
        writeln(cun);
        close(input);close(output);
end.
