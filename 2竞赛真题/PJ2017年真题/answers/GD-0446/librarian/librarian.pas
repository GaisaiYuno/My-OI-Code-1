var
        a:array[1..1000]of longint;
        b:array[1..1000,1..2]of longint;
        n,q,i,j,t,s,l,min:longint;
        bz:boolean;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,q);
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to q do
        begin
                readln(b[i,1],b[i,2]);
                t:=1; min:=maxlongint;
                bz:=true; s:=0;
                for j:=1 to b[i,1]do
                        t:=t*10;
                for j:=1 to n do
                begin
                        l:=a[j]mod t;
                        if l=b[i,2]then
                                s:=a[j];
                        if(s<min)and(s<>0) then min:=s;
                end;
                if min<>maxlongint then writeln(min)
                else writeln(-1);
        end;
        close(input);close(output);
end.