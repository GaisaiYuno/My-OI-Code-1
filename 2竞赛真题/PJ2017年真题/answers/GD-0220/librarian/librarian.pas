var
   a,b:array[1..10000] of longint;
   c:array[1..10000] of string;
   n,q,i,j,k,len,t:longint;
   x,s:string;
      begin
         assign(input,'librarian.in'); reset(input);
         assign(output,'librarian.out'); rewrite(output);

         readln(n,q);
         for i:=1 to n do
            readln(a[i]);
         for i:=1 to n do
            readln(b[i],c[i]);
         for i:=1 to n-1 do
         for j:=i+1 to n do
         if a[i]>a[j] then
            begin
               t:=a[i];
               a[i]:=a[j];
               a[j]:=t;
            end;
         for i:=1 to q do
            begin
               t:=0;
               for j:=1 to n do
                  begin
                     s:=' ';
                     str(a[j],x) ;
                     len:=length(x);
                     for k:=len-b[i]+1 to len do
                        s:=s+x[k];
                     if s=c[i] then
                        begin
                           writeln(a[j]);
                           t:=1;
                           break;
                        end;
                  end;
               if t=0 then
                  writeln('-1');
            end;

         close(input);
         close(output);
      end.





