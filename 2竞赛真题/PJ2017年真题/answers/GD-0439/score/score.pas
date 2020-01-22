var
        a,b,c,sum:longint;
begin
        assign(input,'score.in');
        reset(input);
        assign(output,'score.out');
        rewrite(output);
        readln(a,b,c);
        sum:=0;
        if (a<>0) then sum:=sum+(a div 5);
        if (b<>0) then sum:=sum+((b*3) div 10);
        if (c<>0) then sum:=sum+(c div 2);
        writeln(sum);
        close(input);
        close(output);
end.