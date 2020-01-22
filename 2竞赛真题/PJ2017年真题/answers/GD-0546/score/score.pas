var
a,b,c : longint;
ans : double;
begin
assign(input,'score.in');reset(input);
assign(output,'score.out');rewrite(output);
read(a,b,c);
ans := a*0.2+b*0.3+c*0.5;
write(trunc(ans));
close(input);close(output);
end.
