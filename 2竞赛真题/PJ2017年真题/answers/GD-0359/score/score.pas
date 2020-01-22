var
        n,m,k:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);
        read(n,m,k);
        writeln(n div 10*2+m div 10*3+k div 10*5);
        close(input);close(output);
end.

