var
    a,b,c,d,o,p:longint;
begin
    assign(input,'jump.in');reset(input);
    assign(output,'jump.out');rewrite(output);
     readln(a,b,c);
     for d:=1 to a do
     begin
         readln(o,p);
     end;
     write('-1');
    close(input);
    close(output);
end.