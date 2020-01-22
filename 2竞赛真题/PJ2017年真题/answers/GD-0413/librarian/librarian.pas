type
        tlist=array[1..1000] of longint;
var
        n,q,len:longint;
        book:tlist;
        s,need:string;
        i,j:longint;
        flag:boolean;
procedure qsort(var a : tlist);
    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
    begin
       sort(1,n);
    end;
begin
        assign(input,'librarian.in');
        assign(output,'librarian.out');
        reset(input);
        rewrite(output);
        read(n,q);
        for i:=1 to n do
                readln(book[i]);
        qsort(book);
        for i:=1 to q do
        begin
                readln(need);
                need:=copy(need,3,length(need)-2);
                len:=length(need);
                flag:=true;
                for j:=1 to n do
                begin
                        str(book[j],s);
                        if length(s)<len then continue;
                        s:=copy(s,length(s)-len+1,len);
                        if s=need then
                        begin
                                writeln(book[j]);
                                flag:=false;
                                break;
                        end;
                end;
                if flag then writeln('-1');
        end;
        close(input);
        close(output);
end.
