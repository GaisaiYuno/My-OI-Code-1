var
        i,j,k,m,n,o,p,l,min:longint;
        s,t:ansistring;
        a,b:array[1..1000] of ansistring;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do readln(a[i]);
        for i:=1 to m do begin
                readln(o,p);
                str(p,b[i]);
        end;
        for i:=1 to m do begin
                s:=a[i];  min:=maxlongint;
                for j:=1 to n do begin
                        t:='';
                        if (length(a[j])<length(b[i])) then continue;
                        for k:=length(a[j])-length(b[i])+1 to length(a[j]) do begin
                                s:=a[j];
                                t:=t+s[k];
                        end;
                        if b[i]=t then begin
                                val(a[j],o);
                                if o<min then min:=o;
                        end;
                end;
                if min=maxlongint then min:=-1;
                writeln(min);
        end;
        close(input);close(output);
end.
