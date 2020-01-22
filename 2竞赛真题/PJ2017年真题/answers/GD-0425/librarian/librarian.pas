var
        a:array [0..1000] of longint;
        b:array [0..1000,1..2] of longint;
        n,q,i,j,s:longint;
        pd:boolean;
procedure kp(i,j:longint);
        var
                l,r,mid:longint;
        begin
                l:=i;
                r:=j;
                mid:=a[random(j-i)+i];
                repeat
                        while a[i]<mid do inc(i);
                        while a[j]>mid do dec(j);
                        if i<=j then
                        begin
                                a[0]:=a[i];
                                a[i]:=a[j];
                                a[j]:=a[0];
                                inc(i);
                                dec(j);
                        end;
                until i>j;
                if l<j then kp(l,j);
                if i<r then kp(i,r);
        end;
begin
        assign(input,'librarian.in'); reset(input);
        assign(output,'librarian.out'); rewrite(output);

        readln(n,q);
        for i:=1 to n do
        begin
                readln(a[i]);
        end;
        kp(1,n);
        for i:=1 to q do
        begin
                pd:=false;
                s:=1;
                readln(b[i,1],b[i,2]);
                for j:=1 to b[i,1] do
                begin
                        s:=s*10;
                end;
                for j:=1 to n do
                begin
                        if a[j] mod s=b[i,2] then
                        begin
                                pd:=true;
                                writeln(a[j]);
                                break;
                        end;
                end;
                if pd=false then
                begin
                        writeln(-1);
                end;
        end;


        close(input); close(output);
end.