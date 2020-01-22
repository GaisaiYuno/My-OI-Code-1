var
        n,m,i,j,k,x,y,z:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);
        readln(x,y,z);
        writeln(x div 10*2+y div 10*3+z div 10 *5);
        close(input);close(output);
end.