var
        s1,s2:array[0..10000] of string;
        len1,len2:array[0..10000] of longint;
        x,s:string;
        n,m,i,j,len:longint;
        ch:char;
begin
        assign(input,'librarian.in');reset(input);
        assign(output,'librarian.out');rewrite(output);

        readln(n,m);
        for i:=1 to n do
        begin
                readln(s1[i]);
                len1[i]:=length(s1[i]);
        end;
        for i:=1 to m do readln(len2[i],ch,s2[i]);
        for i:=1 to m do
        begin
                len:=9;x:='99999999';
                for j:=1 to n do
                begin
                        if len1[j]<len2[i] then continue;
                        s:=copy(s1[j],len1[j]-len2[i]+1,len2[i]);
                        if (s=s2[i]) and ((len1[j]<len) or ((len1[j]=len) and (s1[j]<x))) then
                        begin
                                len:=len1[j];
                                x:=s1[j];
                        end;
                end;
                if x='99999999' then x:='-1';
                writeln(x);
        end;
        writeln(x);

        close(input);
        close(output);
end.
