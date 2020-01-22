var
        a,b,c,d,e,i,j:longint;
        s:array[0..1000]of ansistring;
        s1:array[1..1000]of ansistring;
        g:char;
        o,l:ansistring;
        p:boolean;
function pd(a,b:ansistring):boolean;
var
        i:longint;
begin
        if (length(b)>length(a)) then
                exit(true);
        if (length(a)>length(b)) then
                exit(false);
        for i:=1 to length(a) do
        begin
                if a[i]>b[i] then
                        exit(false);
                if b[i]>a[i] then
                        exit(true);
        end;
        exit(false);
end;
procedure ss(l,r:longint);
var
        i,j:longint;
        mid:ansistring;
begin
        i:=l;
        j:=r;
        mid:=s[(i+j) div 2];
        while i<j do
        begin
                while (pd(s[i],mid)=true) do inc(i);
                while (pd(mid,s[j])=true) do dec(j);
                if i<=j then
                begin
                        s[0]:=s[i];
                        s[i]:=s[j];
                        s[j]:=s[0];
                        inc(i);
                        dec(j);
                end;
        end;
        if j>l then ss(l,j);
        if i<r then ss(i,r);
end;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(a,b);
        for c:=1 to a do
                readln(s[c]);
        ss(1,a);
        for c:=1 to b do
        begin

                read(d);
                read(g);
                readln(s1[c]);
        end;
        for i:=1 to b do
        begin
                o:='-1';
                p:=false;
                for j:=1 to a do
                begin
                        if length(s1[i])<=length(s[j]) then
                        begin
                                l:=copy(s[j],length(s[j])-length(s1[i])+1,length(s1[i]));
                                if (s1[i]=l) then
                                begin
                                        writeln(s[j]);
                                        p:=true;
                                        break;
                                end;
                        end;
                end;
                if p=false then
                        writeln(-1);
        end;
        close(input);
        close(output);
end.
