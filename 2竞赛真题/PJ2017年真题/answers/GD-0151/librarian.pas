var
        c,l,k,b,n,m,i,j:longint;
        a:array[1..1000000] of ansistring;
        hehe,min,st:ansistring;
        bz:boolean;
        ch:char;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do
                readln(a[i]);
        for i:=1 to m do
        begin
                bz:=false;
                readln(hehe);
                for l:=1 to length(hehe) do
                begin
                        if bz then st:=st+hehe[l];
                        if hehe[l]=' ' then bz:=true;
                end;
                min:='5648646543213215645423123233231213';
                for j:=1 to n do
                begin
                        bz:=false;
                        if length(st)>length(a[j]) then continue;
                        for l:=length(st) downto 1 do
                        begin
                                if a[j,length(a[j])-length(st)+l]<>st[l] then
                                begin
                                        bz:=true;
                                        break;
                                end;
                        end;
                        if not bz then
                        begin

                                if length(min)>length(a[j]) then min:=a[j]
                                else if length(min)=length(a[j]) then
                                begin
                                        val(min,b);
                                        val(a[j],c);
                                        if b>c then min:=a[j];
                                end;
                        end;
                end;
                if min<>'5648646543213215645423123233231213' then writeln(min)
                else writeln('-1');
                st:='';
        end;
        close(input);
        close(output);
end.
