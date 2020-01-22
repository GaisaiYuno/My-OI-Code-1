var     n,q,i,j,t,r,need,y:longint;
        book:array [1..1002] of longint;
        flag:boolean;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        read(n,q);
        for i:=1 to n do read(book[i]);
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if book[i]>book[j] then
                        begin
                                t:=book[i];
                                book[i]:=book[j];
                                book[j]:=t;
                        end;
        for i:=1 to q do
        begin
                read(r,need);
                y:=1;
                for j:=1 to r do y:=y*10;
                flag:=true;
                for j:=1 to n do
                        if book[j] mod y=need then
                        begin
                                writeln(book[j]);
                                flag:=false;
                                break;
                        end;
                if flag then writeln(-1);
        end;
        close(input);
        close(output);
end.