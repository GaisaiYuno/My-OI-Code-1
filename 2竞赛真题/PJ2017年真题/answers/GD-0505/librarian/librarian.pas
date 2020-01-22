var
        a:array[1..1000]of longint;
        n,q,i,j,k,x,o,x1,x2:longint;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        for i:=1 to 1000 do
                a[i]:=0;
        i:=0;
        j:=0;
        k:=0;
        n:=0;
        q:=0;
        o:=0;
        x:=0;
        x1:=0;
        readln(n,q);
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to q do
                begin
                  readln(x2,x);
                  x1:=-1;
                  o:=1;
                  for j:=1 to x2 do
                        begin
                          o:=o*10;
                        end;
                  for j:=1 to n do
                        if a[j]mod o=x then
                                if (x1=-1)or(x1>a[j])then x1:=a[j];
                  writeln(x1);
                end;
        close(input);close(output);
end.
