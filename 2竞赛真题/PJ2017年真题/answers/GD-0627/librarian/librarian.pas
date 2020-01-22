var
        n,q,l,i:longint;
        book:array[0..1000] of string;
        c:char;
        t:string;

function cmp(a,b:longint):longint;
begin
        if length(book[a])>length(book[b]) then
        begin
                exit(1);
        end
        else
        begin
                if length(book[a])<length(book[b]) then
                begin
                        exit(-1);
                end
                else
                begin
                        if book[a]>book[b] then
                                exit(1);
                        if book[a]<book[b] then
                                exit(-1);
                end;
        end;
        exit(0);
end;

procedure qsort(l,r:longint);
var
        i,j:longint;
        mid,temp:string;
begin
        i:=l;
        j:=r;
        book[0]:=book[(l+r) div 2];
        while i<=j do
        begin
                while cmp(j,0)>0 do
                        j:=j-1;
                while cmp(i,0)<0 do
                        i:=i+1;
                if i<=j then
                begin
                        temp:=book[i];
                        book[i]:=book[j];
                        book[j]:=temp;
                        i:=i+1;
                        j:=j-1;
                end;
        end;
        if i<r then
                qsort(i,r);
        if j>l then
                qsort(l,j);
end;

procedure find(l:longint;t:string);
var
        i,j,len:longint;
        b:boolean;
begin
        for i:=1 to n do
        begin
                len:=length(book[i])-l+1;
                b:=true;
                for j:=1 to l do
                begin
                        if book[i,len+j-1]<>t[j] then
                        begin
                                b:=false;
                                break;
                        end;
                end;
                if b then
                begin
                        writeln(book[i]);
                        exit;
                end;
        end;
        writeln(-1);
end;

begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);

        readln(n,q);
        for i:=1 to n do
                readln(book[i]);
        qsort(1,n);

        for i:=1 to q do
        begin
                readln(l,c,t);
                find(l,t);
        end;

        close(input);close(output);
end.
