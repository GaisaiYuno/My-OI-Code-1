var
   a,b,c,n:longint;
      begin
         assign(input,'score.in'); reset(input);
         assign(output,'score.out'); rewrite(output);

         readln(a,b,c);
         n:=(a*2) div 10+(b*3) div 10+(c*5) div 10;
         writeln(n);

         close(input);
         close(output);
      end.
