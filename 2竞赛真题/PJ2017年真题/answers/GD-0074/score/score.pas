var a,b,c:longint;
    d,e,f,s:real;
begin
assign(input,'score.in');
assign(output,'score.out');
reset(input);
rewrite(output);
read(a,b,c);
d:=a*0.2;
e:=b*0.3;
f:=c*0.5;
s:=d+e+f;
write(s:0:0);
close(input);
close(output);
end.