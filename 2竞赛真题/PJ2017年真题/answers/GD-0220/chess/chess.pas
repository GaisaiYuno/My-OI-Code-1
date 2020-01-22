var
   a,b,s:array[1..1000,1..1000] of longint;
   m,n,i,j,x,y,z,c,t,cl:longint;
      begin
         assign(input,'chess.in'); reset(input);
         assign(output,'chess.out'); rewrite(output);

         readln(m,n);
         for i:=1 to n do
            begin
               readln(x,y,z);
               a[x,y]:=1;
               b[x,y]:=z;
            end;
         c:=0;
         t:=5;
         for i:=m-2 to m do
            begin
               for j:=t to m do
               if a[i,j]=1 then c:=1;
               if c=0 then
                  begin
                     writeln('-1');
                     exit;
                  end;
               dec(t);
            end;
         c:=0;
         t:=0;
         for i:=1 to m do
         for j:=1 to m do
            begin
               t:=0;
               if (a[i+1,j]=1) and (s[i+1,j]=0) and (t=0) then
                  if b[i,j]<>b[i+1,j] then
                     begin
                        c:=c+1;
                        t:=1;
                        s[i+1,j]:=1;
                     end;
               if (a[i,j-1]=1) and (s[i,j-1]=0) and (t=0) then
                  if b[i,j]<>b[i,j-1] then
                     begin
                        c:=c+1;
                        t:=1;
                        s[i,j-1]:=1;
                     end;
               if (a[i-1,j]=1) and (s[i-1,j]=0) and (t=0) then
                  if b[i,j]<>b[i-1,j] then
                     begin
                        c:=1;
                        t:=1;
                        s[i-1,j]:=1;
                     end;
               if (a[i,j+1]=1) and (s[i,j+1]=0) and (t=0) then
                  if b[i,j]<>b[i,j+1] then
                     begin
                        c:=c+1;
                        t:=1;
                        s[i,j+1]:=1;
                     end;
               if t=0 then
                  begin
                     if (a[i+1,j+1]=1) and (s[i+1,j+1]=0) and (t=0) then
                        begin
                           c:=c+2;
                           t:=1;
                           s[i+1,j+1]:=1;
                        end;
                     if (a[i+2,j]=1) and (s[i+2,j]=0) and (t=0) then
                        begin
                           c:=c+2;
                           t:=1;
                           s[i+2,j]:=1;
                        end;
                     if (a[i,j+2]=1) and (s[i,j+2]=0) and (t=0) then
                        begin
                           c:=c+2;
                           t:=1;
                           s[i,j+2]:=1;
                        end;
                  end;
            end;
         writeln(c);

         close(input);
         close(output);
      end.





