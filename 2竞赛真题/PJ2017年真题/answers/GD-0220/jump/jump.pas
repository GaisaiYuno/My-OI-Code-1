var
   x,s:array[1..100000] of longint;
   n,d,k,i,j,c:longint;

      begin
         assign(input,'jump.in'); reset(input);
         assign(output,'jump.out'); rewrite(output);

         readln(n,d,k);
         for i:=1 to n do
            begin
               readln(x[i],s[i]);
               if s[i]>=0 then
                  c:=c+s[i];
            end;
         if c<k then
            begin
               writeln('-1');
               exit;
            end;
         c:=0;
         for i:=1 to n do
            begin
               inc(d);
               for j:=1 to d do
                  if s[j]>0 then
                     c:=c+s[j];
                  if c>k then
                     begin
                        writeln(i);
                        exit;
                     end;
               c:=0;
            end;

         close(input);
         close(output);
      end.
