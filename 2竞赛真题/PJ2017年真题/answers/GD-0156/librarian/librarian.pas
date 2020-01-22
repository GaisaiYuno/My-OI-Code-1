var
        n,i,j,k,x,f,z,ss:longint;
        tot,ans:int64;
        bz:boolean;
        a:array[0..1000]of int64;
        s,t:ansistring;
procedure qsort(x,y:longint);
var
        mid,i,j:longint;
begin
        i:=x;
        j:=y;
        mid:=a[x];
        while i<j do
        begin
                while a[i]<mid do inc(i);
                while a[j]>mid do dec(j);
                if i<=j then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        inc(i);
                        dec(j);
                end;
        end;
        if x<j then qsort(x,j);
        if i<y then qsort(i,y);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,k);
        for i:=1 to n do
        begin
                readln(a[i]);
        end;
        qsort(1,n);
        for i:=1 to k do
        begin
                readln(x,tot);
                str(tot,s);
                bz:=false;
                ss:=x;
                for j:=1 to n do
                begin
                        str(a[j],t);
                        f:=length(t);
                        x:=ss;
                        for z:=f downto 1 do
                        begin
                                if t[z]=s[x] then
                                begin
                                        dec(x);
                                end
                                else break;
                                if x=0 then
                                begin
                                        bz:=true;
                                        break;
                                end;
                        end;
                        if bz then
                        begin
                                writeln(a[j]);
                                break;
                        end;
                end;
                if not bz then writeln(-1);
        end;
        close(input);close(output);
end.

