var
        n,q,i,j,x,we,m,y,k,we2:longint;
        db,tx,ty,tb2:array [1..1000] of longint;
        tb:array [1..1000] of string;
        ma,bm:string;
begin
        assign(input,'librarian.in');
        reset(input);
        assign(output,'librarian.out');
        rewrite(output);
        read(n);
        readln(q);
        for i:=1 to n do
                readln(tb[i]);
        for i:=1 to q do
        begin
                read(x,db[i]);
                for j:=1 to n do
                begin
                        bm:=' ';
                        we:=0;
                        ma:=tb[j];
                        for k:=length(ma) downto 1 do
                        begin
                                inc(we);
                                bm:=bm+ma[k];
                                if we=x then
                                        break;
                        end;
                        for k:=we downto 1 do
                                tx[j]:=tx[j]*10+ord(bm[k+1])-48;
                        for k:=1 to length(ma) do
                                tb2[j]:=tb2[j]*10+ord(ma[k])-48;
                end;
                for j:=1 to n do
                begin
                        if tx[j]=db[i] then
                                y:=1;
                end;
                if y=0 then
                        writeln('-1')
                else begin
                        m:=0;
                        for k:=1 to n do
                        begin
                                if tx[k]=db[i] then
                                begin
                                        inc(m);
                                        if we2=0 then
                                                we2:=k;
                                end;
                        end;
                        if m=1 then
                                writeln(tb[we2])
                        else begin
                                we:=0;
                                for j:=we2 to n do
                                        if tx[j]=db[i] then
                                        begin
                                                inc(we);
                                                ty[j]:=tb2[j];
                                        end;
                                        for j:=1 to we do
                                        begin
                                                if ty[j]<>0 then
                                                        for k:=1 to we do
                                                                if ty[j]<=ty[k] then
                                                                        m:=1
                                                                else begin
                                                                        m:=0;
                                                                        break;
                                                                end;
                                                        if m=1 then
                                                        begin
                                                                we2:=j;
                                                                break;
                                                        end;
                                        end;
                                writeln(ty[we2]);
                        end;
                end;
                for j:=1 to n do
                begin
                        tx[j]:=0;
                        ty[j]:=0;
                        tb2[j]:=0;
                        we2:=0;
                        y:=0;
                end;
        end;
        close(input);
        close(output);
end.
