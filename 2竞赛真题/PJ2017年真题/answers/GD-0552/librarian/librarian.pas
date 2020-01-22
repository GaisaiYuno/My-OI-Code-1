var b,c:array[1..1000] of longint;i,j,minn,min,t,n,q,tmp,non:longint;a:array[1..1000] of string;
minnum,fair,tmps:string;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
readln(n,q);
for tmp:=1 to n do readln(a[tmp]);
for tmp:=1 to q do readln(b[tmp],c[tmp]);
for i:=1 to q do
        begin
        str(c[i],fair);
        min:=10000000;
        minn:=-1;
        for j:=1 to n do
                begin
                tmps:=a[j];
                while (pos(fair,tmps)<>length(tmps)-b[i]+1) and (pos(fair,tmps)<>0) do delete(tmps,pos(fair,tmps),b[i]);
                if pos(fair,tmps)<>0 then
                        begin
                        val(a[j],non);
                        if non<min then
                                begin
                                min:=non;
                                minn:=j;
                                minnum:=a[j];
                                end;
                        end;
                end;
        if minn>-1 then
                begin
                writeln(minnum);
                end else writeln(-1);
        end;
close(input);close(output);
end.
