var
        a,b,c:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);
        readln(a,b,c);
        if a<>0 then
                a:=(a*2)div 10;
        if b<>0 then
                b:=(b*3)div 10;
        if c<>0 then
                c:=(c*5)div 10;
        writeln(a+b+c);
        close(input);
        close(output);
end.