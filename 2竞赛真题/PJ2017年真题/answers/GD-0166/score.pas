var
   a,b,c:longint;
begin
   assign(input,'score.in'); reset(input);
   assign(output,'score.out'); rewrite(output);
     readln(a,b,c);
     writeln(0.2*a+0.3*b+0.5*c:0:0);
   close(input); close(output);
end.
