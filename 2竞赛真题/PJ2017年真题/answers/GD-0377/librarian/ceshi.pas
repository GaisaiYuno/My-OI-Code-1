var
        i,j,s,t:longint;
begin
        assign(output,'librarian.in'); rewrite(output);
        writeln(1000,' ',1000);
        randomize;
        for i:=1 to 1000 do writeln(random(9000000)+1000000);
        for i:=1 to 1000 do writeln(' ',random(9000));
end.
