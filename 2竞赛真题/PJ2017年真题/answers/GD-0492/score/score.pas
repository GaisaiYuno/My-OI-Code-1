program score;
var     a,b,c,d:longint;
begin
        assign(input,'score.in');
        reset(input);
        assign(output,'score.out');
        rewrite(output);
        read(a,b,c);
        d:=a*2 div 10+b*3 div 10+c*5 div 10;
        write(d);
        close(input);
        close(output);
end.