var
        n,m,i,j,x,l:longint;
        a:array[0..1001] of longint;
        xx:char;
        s,ss,js:string;
        bz:boolean;
procedure q(l,r:longint);
var
        z,y,mid,t:longint;
begin
        z:=l;
        y:=r;
        mid:=a[(l+r) div 2];
        while l<r do
        begin
                while a[l]<mid do inc(l);
                while a[r]>mid do dec(r);
                if l<=r then
                begin
                        t:=a[l];
                        a[l]:=a[r];
                        a[r]:=t;
                        inc(l);
                        dec(r);
                end;
        end;
        if l<y then q(l,y);
        if z<r then q(z,r);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        read(n,m);
        for i:=1 to n do
        begin
                read(a[i]);
        end;
        q(1,n);
        for i:=1 to m do
        begin
                read(x);
                read(xx);
                readln(js);
                bz:=false;
                for j:=1 to n do
                begin
                        str(a[j],s);
                        l:=length(s);
                        if l<x then continue
                        else
                        begin
                                ss:=copy(s,l-(x-1),l);
                                if ss=js then
                                begin
                                        writeln(s);
                                        bz:=true;
                                        break;
                                end;
                        end;
                end;
                if bz=false then writeln(-1);
        end;
        close(input);
        close(output);
end.