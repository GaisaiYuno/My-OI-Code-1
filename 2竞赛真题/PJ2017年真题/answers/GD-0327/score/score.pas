var     n,m,i,j,k:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);
        read(i,j,k);
        write(i div 10 *2+j div 10 *3+k div 2);
        close(input);close(output);
end.