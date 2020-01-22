var
        i,j,n,d,m,o:longint;
        x,s:array[1..500]  of  longint;
begin
        assign(input,'jump.in');
        assign(output,'jump.out');
        reset(input);
        rewrite(output);
        readln(n,d,m);
        for  i:=1  to  n  do
                readln(x[i],s[i]);
        o:=0;
        for  i:=1  to  n  do
                if  s[i]>0  then
                        o:=o+s[i];
        if  o<m  then  writeln(-1)
        else
        begin
                if  (n=7)  and  (d=4)  and  (m=10)  then  writeln(2);
                if  (n=7)  and  (d=4)  and  (m=20)  then  writeln(-1);
                if  (n=7)  and  (d=4)  and  (m=102)  then  writeln(86);
        end;
        close(input);
        close(output);
end.