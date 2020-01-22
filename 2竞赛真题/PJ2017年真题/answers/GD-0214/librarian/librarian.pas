var     s:array[1..1000,0..8]of string;
        s1:string;
        i,j,n,m,k,ans,l,an:longint;
        bz:boolean;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        readln(n,m);
        for i:=1 to n do
        begin
                readln(s[i,0]);
                l:=length(s[i,0]);
                for j:=1 to l do s[i,j]:=copy(s[i,0],l-j+1,j);
        end;
        for i:=1 to m do
        begin
                readln(s1);
                val(copy(s1,1,1),l);
                delete(s1,1,2);
                ans:=10000000;
                bz:=true;
                for j:=1 to n do
                begin
                        if s[j,l]=s1 then
                        begin
                                val(s[j,0],an);
                                bz:=false;
                                if an<ans then ans:=an;
                        end;
                end;
                if bz then writeln(-1)
                else writeln(ans);
        end;
        close(input);
        close(output);
end.
