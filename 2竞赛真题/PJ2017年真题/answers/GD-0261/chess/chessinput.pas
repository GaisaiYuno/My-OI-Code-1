var     i,j,k,x,y,t:longint;
begin
        assign(output,'chess.in');rewrite(output);
        writeln('100 1000');
        x:=1;
        y:=1;
        randomize;
        for i:=1 to 1000 do
        begin
                writeln(x,' ',y,' ',random(2));
                inc(x);
                if x=101 then x:=1;
                inc(y);
                if t=1 then
                begin
                        if y>=71 then y:=1;
                end
                else
                begin
                        if y=101 then
                        begin
                                inc(t);
                                y:=11;
                        end;
                end;
        end;
        close(input);close(output);
end.
