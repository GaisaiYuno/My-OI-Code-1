const cs=5000000;
var
        data:array[0..5000000,1..4] of longint;
        a,b:array[0..100000] of longint;
        n,d,k,i,st,en,max:longint;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);

        readln(n,d,k);
        for i:=1 to n do
        begin
                readln(a[i],b[i]);
                if b[i]>0 then max:=max+b[i];
        end;
        if max<k then
        begin
                writeln(-1);
                close(input);
                close(output);
                exit;
        end;
        st:=0;en:=1;data[1,1]:=1;data[1,2]:=d;data[1,3]:=0;data[1,4]:=0;
        while st<en do
        begin
                st:=st mod cs+1;
                if data[st,3]=k then
                begin
                        writeln(data[1,2]-d,' ',en);
                        close(input);
                        close(output);
                        exit;
                end;
                for i:=1 to a[n]-data[st,2] do
                begin
                        en:=en mod cs+1;
                        data[en]:=data[st];
                        data[en,2]:=data[en,2]+i;
                        data[en,4]:=i;
                end;
                i:=1;
                while (data[st,1]+data[st,2]>=a[i])
                and ((data[st,4]>=data[st,2]-data[st,4])
                or ((data[st,4]<data[st,2]-data[st,4])
                and (a[i]>=data[st,2]-data[st,4])))
                and (i<=n) do
                begin
                        en:=en mod cs+1;
                        data[en]:=data[st];
                        data[en,1]:=a[i];
                        data[en,3]:=data[en,3]+b[i];
                        inc(i);
                end;
        end;
        writeln(-1);

        close(input);
        close(output);
end.
