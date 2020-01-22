var
        n,m,i,j,k,x,y,z,s,ls,ans:longint;
        st,st1:string;
        a:array[0..1001]of string;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        readln(n,m);
        for i:=1 to n do
        readln(a[i]);
        for i:=1 to m do
        begin
                readln(st);
                for j:=1 to length(st) do
                if st[j]=' ' then break;
                inc(j);
                x:=length(st)-j+1;
                st:=copy(st,j,x);
                ans:=maxlongint;
                for j:=1 to n do
                begin
                        st1:=copy(a[j],length(a[j])-x+1,x);
                        if st1=st then
                        begin
                                val(a[j],y);
                                if ans>y then ans:=y;
                        end;
                end;
                if ans=maxlongint then writeln(-1)
                else writeln(ans);
        end;
        close(input);
        close(output);
end.
