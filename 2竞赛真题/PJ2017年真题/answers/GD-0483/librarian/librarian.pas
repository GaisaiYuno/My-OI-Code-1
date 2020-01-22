var
 a:array[1..1000,1..9] of longint;
 b:array[1..1000] of longint;
 n,p,i,j,k,s,t,m,min:longint;
begin
        assign(input,'librarian.in'); reset(input);
        assign(output,'librarian.out'); rewrite(output);
        readln(n,p);
        for i:=1 to n do
         begin
                m:=0;
                readln(m);
                a[i,9]:=m;
                for j:=1 to 8 do
                 begin
                        a[i,j]:=m mod 10;
                        m:=m div 10;
                 end;
         end;
        for i:=1 to p do
         begin
                read(m);
                readln(s);
                for j:=1 to n do
                 begin
                        b[j]:=1;
                 end;
                for j:=1 to m do
                 begin
                        t:=s mod 10;
                        for k:=1 to n do
                         begin
                                if a[k,j]<>t then b[k]:=0;
                         end;
                        s:=s div 10;
                 end;
                min:=-1;
                for j:=1 to n do
                 begin
                        if b[j]=1 then
                         begin
                                if (min=-1) or (a[j,9]<min) then min:=a[j,9];
                         end;
                 end;
                writeln(min);
         end;
        close(input); close(output);
end.
