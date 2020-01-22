Var
        a,b,c:longint;
        d:real;
Begin
assign(input,'score.in');reset(input);
assign(output,'score.out');rewrite(output);

        readln(a,b,c);
        d:=a*0.2+b*0.3+c*0.5;
        writeln(d:0:0);
        readln;

close(input);close(output);
End.