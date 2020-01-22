var
        a,b,c,ans:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);
        readln(a,b,c);
        a:=a div 10;
        b:=b div 10;
        c:=c div 10;
        ans:=a*2+b*3+c*5;
        writeln(ans);
        close(input);
        close(output);
end.
