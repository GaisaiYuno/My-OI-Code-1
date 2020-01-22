var
a,s:array[1..100,1..100] of longint;
i,j,k,l,m,n,warn,ss:longint;
begin

  readln(m,n);
  for i:=1 to m do
    for j:=1 to m do
      begin
        a[i,j]:=0-2;
        s[i,j]:=5;
      end;
  for i:=1 to n do
    begin
      readln(j,k,l);
      a[j,k]:=l;
    end;
  s[1,1]:=1;
  for i:=1 to m do
    for j:=1 to m do
      if warn=2 then

        ss:=0-1


        else
         begin
         warn:=0;
           if s[i,j]=1 then
             if a[i,j]=a[i+1,j] then
               begin
                 s[i,j]:=5;
                 s[i+1,j]:=1
               end;
           if s[i,j]=1 then
             if a[i,j]=a[i,j+1] then
                 begin
                   s[i,j]:=5;
                   s[i,j+1]:=1
                 end;
           if s[i,j]=1 then
             if (a[i,j]=a[i+1,j]+1) or (a[i,j]=a[i+1,j]-1) then
                 begin
                   s[i,j]:=5;
                   s[i+1,j]:=1;
                   ss:=ss+1;
                 end;
           if s[i,j]=1 then
             if (a[i,j]=a[i,j+1]+1) or (a[i,j]=a[i,j+1]-1) then
                 begin
                   s[i,j]:=5;
                   s[i+1,j]:=1;
                   ss:=ss+1;
                 end;
           if s[i,j]=1 then
               begin
                 warn:=warn+1;
                 s[i,j+1]:=1;
                 a[i,j+1]:=a[i,j];
                 ss:=ss+2;
                 s[i,j]:=5;
               end;

        end;
   write(ss);

end.
