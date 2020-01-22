var     n,q,l,i,j,len:longint;
        mn,reader,x,s:string;
        book:array[0..1001]of string;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        readln(n,q);
        for i:=1 to n do readln(book[i]);
        for i:=1 to q do
        begin
                readln(x);
                l:=pos(' ',x);
                reader:=copy(x,l+1,length(x)-l);
                x:=copy(x,1,l-1);
                val(x,len);
                mn:='10000001';
                for j:=1 to n do
                begin
                        s:=copy(book[j],length(book[j])-len+1,len);
                        if (pos(reader,s)<>0) then
                                if (length(book[j])<length(mn))or(length(book[j])=length(mn))and(book[j]<mn) then
                                        mn:=book[j];
                end;
                if (mn<>'10000001') then writeln(mn)
                                    else writeln(-1);
        end;
        close(input);
        close(output);
end.