var
        f,x,s:array[0..500000+5] of int64;
        d,g,i,j,k,n,m,l,r,mid:longint;
        p:boolean;
function max(a,b:longint):longint;
begin
        if a<b then exit(b);
        exit(a);
end;
function pd(g:longint):boolean;
var
        i,j:longint;
begin
        fillchar(f,sizeof(f),0);
        if g<d then
        begin
                for i:=1 to n do
                        f[i]:=s[i];
                for i:=2 to n do
                begin
                        for j:=1 to i-1 do
                        begin
                                if (d-g<=x[i]-x[j]) and (x[i]-x[j]<=d+g) then
                                begin
                                        f[i]:=max(f[i],f[j]+s[i]);
                                end;
                        end;
                end;
        end
        else
        begin
                for i:=1 to n do
                        f[i]:=s[i];
                for i:=2 to n do
                begin
                        for j:=1 to i-1 do
                        begin
                                if (1<=x[i]-x[j]) and (x[i]-x[j]<=d+g) then
                                begin
                                        f[i]:=max(f[i],f[j]+s[i]);
                                end;
                        end;
                end;
        end;
        for i:=1 to n do
                if f[i]>=k then
                        exit(true);
        exit(false);
end;
begin
        assign(input,'jump.in');
        reset(input);
        assign(output,'jump.out');
        rewrite(output);
        readln(n,d,k);
        for i:=1 to n do
                readln(x[i],s[i]);
        p:=false;
        l:=1;
        r:=x[n];
        while l<r do
        begin
                mid:=(l+r) div 2;
                if pd(mid) then
                        r:=mid
                else
                        l:=mid+1;
        end;
        g:=l;
        fillchar(f,sizeof(f),0);
        if g<d then
        begin
                for i:=1 to n do
                        f[i]:=s[i];
                for i:=2 to n do
                begin
                        for j:=1 to i-1 do
                        begin
                                if (d-g<=x[i]-x[j]) and (x[i]-x[j]<=d+g) then
                                begin
                                        f[i]:=max(f[i],f[j]+s[i]);
                                end;
                        end;
                end;
        end
        else
        begin
                for i:=1 to n do
                        f[i]:=s[i];
                for i:=2 to n do
                begin
                        for j:=1 to i-1 do
                        begin
                                if (1<=x[i]-x[j]) and (x[i]-x[j]<=d+g) then
                                begin
                                        f[i]:=max(f[i],f[j]+s[i]);
                                end;
                        end;
                end;
        end;
        for i:=1 to n do
                if f[i]>=k then
                begin
                        writeln(g+1);
                        p:=true;
                        break;
                end;
        if not p then
                writeln(-1);
        close(input);
        close(output);
end.

