var
        a,b,c:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);

        readln(a,b,c);
        writeln(a*2 div 10+b*3 div 10+c*5 div 10);

        close(input);close(output);
end.