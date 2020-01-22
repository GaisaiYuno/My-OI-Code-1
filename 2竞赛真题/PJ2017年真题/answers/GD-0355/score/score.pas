program score;
var a,b,c,d:real;
begin
assign(input,'score.in');rewrite(input);
assign(output,'score.out');reset(output);
read(a);
read(b);
read(c);
d:=a*0.2+b*0.3+c*0.5;
write(d:0:0);
close(input);
close(output);
end.
