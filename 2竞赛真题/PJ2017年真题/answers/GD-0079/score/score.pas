var
        a,b,c,ans:longint;
begin
        assign(input,'score.in');
        reset(input);
        assign(output,'score.out');
        rewrite(output);
        readln(a,b,c);
        ans:=a div 5+b div 10*3+c div 2;
        writeln(ans);
        close(input);
        close(output);
end.