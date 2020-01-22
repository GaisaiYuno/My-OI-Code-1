var
        a:array[0..1001]of string;
        i,j,k,n,m,x,y,min:longint;
        s,t:string;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,m);
        min:=maxlongint;
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to m do
        begin
                read(x); if x=0 then continue;
                readln(t); delete(t,1,1);  s:='';
                for j:=1 to n do
                begin
                        s:='';
                        if x>length(a[j]) then continue;
                        for k:=length(a[j]) downto length(a[j])-x+1 do
                                s:=a[j,k]+s;
                        if s=t then
                        begin
                                val(a[j],y);
                                if y<min then min:=y;
                        end;
                end;
                if min=maxlongint then min:=-1;
                writeln(min);
                min:=maxlongint;
        end;
        close(input);close(output);
end.