var
        i:longint;
begin
        assign(output,'librarian.in');
        rewrite(output);
        writeln(1000,' ',1000);
        for i:=1 to 1000 do
          writeln(random(10000000)+1);
        for i:=1 to 1000 do
          begin
            writeln(4,' ',random(9000)+1000);
          end;
        close(output);
end.
