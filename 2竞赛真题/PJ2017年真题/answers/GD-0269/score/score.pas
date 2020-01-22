var
        a,b,c:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);
        readln(a,b,c);
        writeln(a div 5+b*3 div 10+c div 2);
        close(input);close(output);
end.