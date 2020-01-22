var
        i:longint;
begin
        assign(output,'jump.in');
        rewrite(output);
        writeln(5000,' ',2000,' ',random(1000000000)+1);
        for i:=1 to 5000 do
          begin
           writeln(random(1000000000),' ',random(200000)-100000);
          end;
        close(output);
end.
