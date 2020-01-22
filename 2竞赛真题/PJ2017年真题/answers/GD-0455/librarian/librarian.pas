var
        i,j,k,s,t,n,m,l:longint;
        a:array[0..10001] of string;
        st:string;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
        readln(n,m);
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to m do
        begin
                readln(t,k);
                l:=maxlongint;
                for j:=1 to n do
                begin
                        if t>length(a[j]) then continue;
                        st:=a[j];
                        t:=0;
                        while st<>'' do
                        begin
                                val(st,s);
                                if s=k then begin t:=1; break; end;
                                delete(st,1,1);
                        end;
                        if t<>0 then
                        begin
                                val(a[j],s);
                                if s<l then l:=s;
                        end;
                end;
                if l<>maxlongint then writeln(l) else writeln(-1);
        end;
close(input);
close(output);
end.
