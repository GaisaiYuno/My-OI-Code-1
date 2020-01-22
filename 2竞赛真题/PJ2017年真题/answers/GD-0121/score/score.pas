var a,b,c:longint;
begin
        assign(input,'score.in');reset(input);
        assign(output,'score.out');rewrite(output);
        readln(a,b,c);
        writeln((a/5+(b/10*3)+c/2):0:0);
        close(input);
        close(output);
end.
