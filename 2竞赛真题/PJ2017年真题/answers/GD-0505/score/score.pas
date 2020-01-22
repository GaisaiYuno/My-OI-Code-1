var
        a,b,c,d:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);
        a:=0;
        b:=0;
        c:=0;
        d:=0;
        readln(a,b,c);
        d:=(a div 5)+((b div 10) *3)+ (c div 2);
        writeln(d);
        close(input);close(output);
end.