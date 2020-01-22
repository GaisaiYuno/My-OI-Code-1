var
        a,b,c,s:longint;
begin
        assign(input,'score.in');assign(output,'score.out');
        reset(input);rewrite(output);
        readln(a,b,c);
        a:=a div 10;
        b:=b div 10;
        c:=c div 10;
        s:=a*2+b*3+c*5;
        writeln(s);
        close(input);close(output);
end.
