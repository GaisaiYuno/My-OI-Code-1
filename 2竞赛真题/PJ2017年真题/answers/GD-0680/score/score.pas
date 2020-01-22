var
        a,b,c,ans:longint;
begin
        assign(input,'score.in');
        reset(input);
        assign(output,'score.out');
        rewrite(output);
                read(a,b,c);
                ans:=(a*2+b*3+c*5)div 10;
                write(ans);
        close(input);
        close(output);
end.
