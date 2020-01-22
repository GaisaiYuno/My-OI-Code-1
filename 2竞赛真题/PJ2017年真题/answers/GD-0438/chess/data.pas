var
        i,t:longint;
begin
        assign(output,'chess.in');
        rewrite(output);
        writeln(100,' ',100);
        randomize;
        for i:=1 to 100 do
          begin
            if i mod 2=0 then
              t:=1
            else
              t:=0;
            writeln(i,' ',i,' ',t);
          end;
        close(output);
end.
