var a,b,c,s:real;
begin
assign(input,'score.in');
assign(output,'score.out');
reset(input);
rewrite(output);
        readln(a,b,c);
        a:=a*0.2;
        b:=b*0.3;
        c:=c*0.5;
        writeln(a+b+c:0:0);
close(input);
close(output);
end.