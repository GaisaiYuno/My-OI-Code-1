var
        i,j,n,m,o,t,sum:longint;
        a,l,f:array[1..1000]  of  longint;
Procedure       qsort(l,r:longint);
var
        i,j,mid,t:longint;
begin
        i:=l;   j:=r;   mid:=a[(i+j)  shr  1];
        repeat
                while  a[i]<mid  do  inc(i);
                while  a[j]>mid  do  dec(j);
                if  i<j  then
                begin
                        t:=a[i];  a[i]:=a[j];  a[j]:=t;
                        inc(i);   dec(j);
                end;
        until   i>=j;
        if  i<l  then  qsort(i,r);
        if  j<r  then  qsort(l,j);
end;
begin
        assign(input,'librarian.in');
        assign(output,'librarian.out');
        reset(input);
        rewrite(output);
        readln(n,m);
        for  i:=1  to  n  do
                readln(a[i]);
        qsort(1,n);
        for  i:=1  to  m  do
        begin
                readln(l[i],f[i]);
                t:=1;
                for  j:=1  to  l[i]  do  t:=t*10;
                for  j:=1  to  n  do
                     if  abs(a[j]  mod  t)=f[i]  then
                     begin
                        writeln(a[j]);
                        break;
                     end
                     else       if  j=n  then   writeln(-1);
        end;
        close(input);
        close(output);
end.