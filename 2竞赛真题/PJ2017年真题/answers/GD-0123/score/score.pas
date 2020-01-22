var
        a,b,c,s:longint;
begin
        assign(input,'score.in'); reset(input);
        assign(output,'score.out'); rewrite(output);
        readln(a,b,c);
        s:=(a div 10)*2+(b div 10)*3+(c div 10)*5;
        writeln(s);

        close(input); close(output);
end.