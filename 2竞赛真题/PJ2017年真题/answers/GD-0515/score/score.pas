var a,b,c,d:longint;
begin
 assign(input,'score.in');
 assign(output,'score.out');
 reset(input);
 rewrite(output);
 readln(a,b,c);
 d:=d+(a div 5)+(b*3 div 10)+(c div 2);
 writeln(d);
 close(input);
 close(output);
end.